//
// Created by admin on 2020-03-31.
//

#pragma once

#include <vector>
#include <atomic>

namespace xop
{
    template <typename T>
    class RingBuffer
    {
    public:
        RingBuffer(unsigned capacity=60) :
        _buffer(capacity),
        _capacity(capacity),
        _numDatas(0)
        {}

    private:
        int _capacity = 0;

        std::atomic_int _numDatas;
        std::vector<T> _buffer;
    };
}