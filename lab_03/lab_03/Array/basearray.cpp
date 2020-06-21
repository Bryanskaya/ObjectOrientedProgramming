#include "basearray.h"

BaseArray::BaseArray(size_t size)
{
    _count = shared_ptr<size_t>(new size_t(size));
}

BaseArray::BaseArray(const BaseArray& other)
{
    _count = shared_ptr<size_t>(new size_t(other.get_size()));
}

BaseArray::~BaseArray(){};

size_t BaseArray::get_size() const
{
    return bool(_count) ? *_count : 0;
}

BaseArray::operator bool() const
{
    return get_size();
}
