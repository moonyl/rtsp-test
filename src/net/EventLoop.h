//
// Created by admin on 2020-03-31.
//

#pragma once
#include <memory>
#include <mutex>

#include "SelectTaskScheduler.h"

namespace xop {
    class EventLoop
    {
    public:
        EventLoop(const EventLoop&) = delete;
        EventLoop &operator = (const EventLoop&) = delete;
        EventLoop(uint32_t nThreads=1);

    private:
        void loop();

        std::mutex _mutex;
        uint32_t _nThreads = 1;
        uint32_t _index = 1;
    };

}

