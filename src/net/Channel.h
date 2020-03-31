//
// Created by admin on 2020-03-31.
//

#pragma once

#include <functional>
#include <memory>
#include "Socket.h"

namespace xop {
class Channel
{
public:
    Channel() = delete;
    Channel(SOCKET fd) : _fd(fd) {};

private:

    SOCKET _fd = 0;
};

typedef std::shared_ptr<Channel> ChannelPtr;
}