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
