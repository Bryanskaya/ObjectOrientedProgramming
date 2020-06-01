#ifndef BASEITERATOR_HPP
#define BASEITERATOR_HPP
#define BASE_ITERATOR_HPP_ADVANCED

#include "baseiterator.h"

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
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

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
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

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
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

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
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (index >= *(count.lock()))
        return false;
    return true;
}

#endif // BASEITERATOR_HPP
