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
    // �ϳ��� ��ϵ� �Լ����� ȣ��� �� ������ �����Ѵ�. �ƹ����� singleton�� ���� ��.
    static std::once_flag oc_init;
    std::call_once(oc_init, [] {
#if defined(WIN32) || defined(_WIN32)
        // ������ ����ϱ� ���ؼ��� �ݵ�� �ʱ�ȭ�� �ؾ� �Ѵ�.
        WSADATA wsaData;
        // 2.2 �� ����Ѵٴ� �ǹ�.
        if (WSAStartup(MAKEWORD(2, 2), &wsaData))
        {
            // ���ϰ��� 0�� �ƴ϶�� ���� ��Ȳ�̴�.
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
    }
}
