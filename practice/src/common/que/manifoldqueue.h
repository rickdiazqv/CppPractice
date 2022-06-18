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
    std::queue<T> que;
    std::mutex mtx;
    std::condition_variable cv_nofull;
    std::condition_variable cv_noempty;
    bool isClosed = false;
    bool isAborted = false;

public:
    ManifoldQueue(const int cap = capDefault) : cap(cap) {}
    ~ManifoldQueue() {}

public:
    void push(T data)
    {
        std::unique_lock<std::mutex> lk(mtx);
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
    void term() {}
    void abort() {}
};