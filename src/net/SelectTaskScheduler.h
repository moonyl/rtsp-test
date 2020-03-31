//
// Created by admin on 2020-03-31.
//

#pragma once
#include "TaskScheduler.h"
#include "Socket.h"
#include <mutex>

namespace xop {
    class SelectTaskScheduler : public TaskScheduler
    {
    public:
        SelectTaskScheduler(int id = 0);

        void updateChannel(ChannelPtr channel);

    private:
        fd_set _fdReadBackup;
        fd_set _fdWriteBackup;
        fd_set _fdExpBackup;


        std::mutex _mutex;
    };
}


