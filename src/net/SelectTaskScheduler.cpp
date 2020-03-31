//
// Created by admin on 2020-03-31.
//

#include "SelectTaskScheduler.h"

using namespace xop;
SelectTaskScheduler::SelectTaskScheduler(int id) : TaskScheduler(id)
{
    FD_ZERO(&_fdReadBackup);
    FD_ZERO(&_fdWriteBackup);
    FD_ZERO(&_fdExpBackup);

    this->updateChannel(_wakeupChannel);
}

void SelectTaskScheduler::updateChannel(ChannelPtr channel)
{
    // TODO: implementation
    std::lock_guard<std::mutex> lock(_mutex);

}
