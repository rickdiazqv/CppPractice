#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "external.h"

struct closed_queue : std::exception
{
};
struct abort_exception : std::exception
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
    condition_variable cv_nofull;
    condition_variable cv_noempty;
    bool isClosed = false;
    bool isAborted = false;

public:
    ManifoldQueue(const int cap = capDefault) : cap(cap) {}
    ~ManifoldQueue() {}

public:
    void push(T data)
    {
        unique_lock<mutex> lk(mtx);
        cv_nofull.wait(lk,
                       [&]
                       {
                           return que.size() < cap || isClosed || isAborted;
                       });

        if (isClosed)
        {
        }
    }
    bool pop(T &data) { return true; }
    void close() {}
    void abort() {}
};