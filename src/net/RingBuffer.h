//
// Created by admin on 2020-03-31.
//

#pragma once

#include <vector>
#include <atomic>

namespace xop
{
    // TODO : implementation
    template <typename T>
    class RingBuffer
    {
    public:
        RingBuffer(unsigned capacity=60) :
        _buffer(capacity),
        _capacity(capacity),
        _numDatas(0)
        {}

        bool pop(T& data)   {
            if (_numDatas > 0)  {
                data = std::move(_buffer[_getPos]);
                add(_getPos);
                _numDatas--;
                return true;
            }
            return false;
        }

        int size() const { return _numDatas;}

    private:
        void add(int& pos)  {
            pos = (((pos+1)==_capacity) ? 0 : (pos+1));
        }

        int _capacity = 0;
        int _getPos = 0;

        std::atomic_int _numDatas;
        std::vector<T> _buffer;
    };
}