#ifndef BASEARRAY_H
#define BASEARRAY_H

#include <memory>

using namespace std;

class BaseArray
{
public:
    BaseArray(size_t sz = 0);
    BaseArray(const BaseArray& other);
    virtual ~BaseArray() = 0;

    size_t get_size() const;
    operator bool() const;

protected:
    shared_ptr<size_t> _count;
};

#endif // BASEARRAY_H
