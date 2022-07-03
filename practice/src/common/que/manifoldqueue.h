#include "external.h"

struct closed_queue : exception
{
};
struct abort_exception : exception
{
};

template <typename T>
class ManifoldQueue
{
private:
    static const int capDefault = 10;
    const int cap = capDefault;
    queue<T> que;
    mutex mtx;
    cvar cv_nofull;
    cvar cv_noempty;
    bool isTermed = false;
    bool isAborted = false;

public:
    ManifoldQueue(const int cap = capDefault) : cap(cap) {}
    ~ManifoldQueue() {}

public:
    void push(T data)
    {
        ulock<mutex> lk(mtx);
        cv_nofull.wait(lk, [&]
                       { return que.size() < cap || isTermed || isAborted; });

        if (isTermed)
        {
            throw closed_queue();
        }
        if (isAborted)
        {
            throw abort_exception();
        }

        bool do_signal = que.empty();
        que.push(data);

        if (do_signal)
        {
            cv_noempty.notify_one();
        }
    }

    bool pop(T &data)
    {
        ulock<mutex> lk(mtx);
        cv_noempty.wait(lk, [&]
                        { return !que.empty() || (que.empty() && isTermed) || isAborted; });

        if (que.empty() && isTermed)
        {
            return false;
        }
        if (isAborted)
        {
            throw abort_exception();
        }

        bool do_signal = que.size() == cap;
        data = que.front();
        que.pop();

        if (do_signal)
        {
            cv_nofull.notify_one();
        }

        return true;
    }
    void term()
    {
        lguard<mutex> lk(mtx);
        isTermed = true;
        cv_nofull.notify_all();
        cv_noempty.notify_all();
    }
    void abort()
    {
        lguard<mutex> lk(mtx);
        isAborted = true;
        cv_nofull.notify_all();
        cv_noempty.notify_all();
    }
};