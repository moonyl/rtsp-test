//
// Created by admin on 2020-03-31.
//

#include "EventLoop.h"

#if defined(WIN32) || defined(_WIN32)
#include<windows.h>
#endif

using namespace xop;
EventLoop::EventLoop(uint32_t nThreads) :
    _index(1)
{
    // 하나의 등록된 함수만이 호출될 수 있음을 보장한다. 아무래도 singleton에 사용될 듯.
    static std::once_flag oc_init;
    std::call_once(oc_init, [] {
#if defined(WIN32) || defined(_WIN32)
        // 윈속을 사용하기 위해서는 반드시 초기화를 해야 한다.
        WSADATA wsaData;
        // 2.2 를 사용한다는 의미.
        if (WSAStartup(MAKEWORD(2, 2), &wsaData))
        {
            // 리턴값이 0이 아니라면 에러 상황이다.
            WSACleanup();
        }
#endif
    });

    _nThreads = 1;
    if (nThreads > 0)   {
        _nThreads = nThreads;
    }

    this->loop();
}

void EventLoop::loop()
{
    // TODO : implementation
    std::lock_guard<std::mutex> locker(_mutex);

    for (uint32_t n=0; n < _nThreads; n++)  {
#if defined(__linux) || defined(__linux__)
        std::shared_ptr<TaskScheduler> taskSchedulerPtr(new EpollTaskScheduler(n));
#elif defined(WIN32) || defined(_WIN32)
        std::shared_ptr<TaskScheduler> taskSchedulerPtr(new SelectTaskScheduler(n));
#endif
        _taskSchedulers.push_back(taskSchedulerPtr);
        std::shared_ptr<std::thread> t(new std::thread(&TaskScheduler::start, taskSchedulerPtr.get()));
    }
}
