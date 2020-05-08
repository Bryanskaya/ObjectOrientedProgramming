#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>

#include "my_errors.h"

using namespace std;

template<typename Type>
class BaseIterator : public iterator<input_iterator_tag, Type>
{
public:
    BaseIterator(const BaseIterator &other)
    {
        arr = other.arr;
        count = other.count;
        index = other.index;
    }

    BaseIterator<Type>& next();
    bool is_end() const;

    int kate = 10;

    operator bool() const;

    BaseIterator<Type>& operator++();
    BaseIterator<Type> operator++(int);

    BaseIterator<Type>& operator--();
    BaseIterator<Type> operator--(int);

    BaseIterator<Type>& operator=(const BaseIterator<Type>& iter);

    bool operator==(BaseIterator const& other) const;
    bool operator!=(BaseIterator const& other) const;
    bool operator>=(BaseIterator const& other) const;
    bool operator>(BaseIterator const& other) const;
    bool operator<=(BaseIterator const& other) const;
    bool operator<(BaseIterator const& other) const;

protected:
    BaseIterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
             size_t ind = 0) : arr(a), count(c), index(ind) {}

    weak_ptr<Type[]> arr;
    weak_ptr<size_t> count;
    size_t index = 0;

    int help_base = 55;

private:
    BaseIterator<Type>& _next();
    bool _is_end() const;
};

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::operator=(const BaseIterator<Type>& iter)
{
    index = iter.index;
    return *this;
}

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::next()
{
    return _next();
}

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::_next()
{
    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<size_t> n(count);
    if (index < *n)
        index++;

    return *this;
}

template<typename Type>
bool BaseIterator<Type>::is_end() const
{
    return _is_end();
}

template<typename Type>
bool BaseIterator<Type>::_is_end() const
{
    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    return index == *(count.lock());
}

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::operator++()
{
    return _next();
}

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::operator--()
{
    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<size_t> n(count);
    if (index > *n)
        index--;

    return *this;
}

template<typename Type>
BaseIterator<Type> BaseIterator<Type>::operator++(int)
{
    BaseIterator<Type> iter(*this);

    ++(*this);

    return iter;
}

template<typename Type>
BaseIterator<Type> BaseIterator<Type>::operator--(int)
{
    BaseIterator<Type> iter(*this);

    --(*this);

    return iter;
}

template<typename Type>
bool BaseIterator<Type>::operator==(BaseIterator const& other) const
{
    return index == other.index;
}

template<typename Type>
bool BaseIterator<Type>::operator!=(BaseIterator const& other) const
{
    return !(index == other.index);
}

template<typename Type>
bool BaseIterator<Type>::operator>=(BaseIterator const& other) const
{
    return index >= other.index;
}

template<typename Type>
bool BaseIterator<Type>::operator>(BaseIterator const& other) const
{
    return index > other.index;
}

template<typename Type>
bool BaseIterator<Type>::operator<=(BaseIterator const& other) const
{
    return index <= other.index;
}

template<typename Type>
bool BaseIterator<Type>::operator<(BaseIterator const& other) const
{
    return index < other.index;
}

template<typename Type>
BaseIterator<Type>::operator bool() const
{
    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (index >= *(count.lock()))
        return false;
    return true;
}

#endif // BASEITERATOR_H
