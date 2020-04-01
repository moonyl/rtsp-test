//
// Created by admin on 2020-03-31.
//

#pragma once

#include "Channel.h"
#include "Pipe.h"
#include "RingBuffer.h"

namespace xop {
    typedef std::function<void(void)> TriggerEvent;

    class TaskScheduler
    {
    public:
        TaskScheduler(int id = 1);

        void start();

    protected:
        void handleTriggerEvent();

        int _id = 0;
        std::atomic_bool _shutdown;
        std::shared_ptr<Pipe> _wakeupPipe;
        std::shared_ptr<Channel> _wakeupChannel;

        typedef xop::RingBuffer<TriggerEvent> TriggerEventQueue;
        std::shared_ptr<TriggerEventQueue> _triggerEvents;

        static const int kMaxTriggetEvents = 5000;
    };

}

