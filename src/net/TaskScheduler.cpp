//
// Created by admin on 2020-03-31.
//

#include "TaskScheduler.h"

using namespace xop;

TaskScheduler::TaskScheduler(int id) :
    _id(id),
    _shutdown(false),
    _wakeupPipe(std::make_shared<Pipe>()),
    _triggerEvents(new TriggerEventQueue(kMaxTriggetEvents))
{
    // TODO : implementation
}

void TaskScheduler::start()
{
#if defined(__linux) || defined(__linux__)
    signal(SIGPIPE, SIG_IGN)
    signal(SIGQUIT, SIG_IGN)
    signal(SIGUSR1, SIG_IGN)
    signal(SIGTERM, SIG_IGN)
    signal(SIGKILL, SIG_IGN)
#endif
    _shutdown = false;
    // TODO: implementation
    while(!_shutdown)   {
        this->handleTriggerEvent();

    }
}

void TaskScheduler::handleTriggerEvent()
{
    do {
        TriggerEvent callback;
        // TODO: implementation
        if (_triggerEvents->pop(callback))  {
            callback();
        }
    } while (_triggerEvents->size() > 0);
}
