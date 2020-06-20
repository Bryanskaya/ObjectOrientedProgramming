#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#define ITERATOR_HPP_ADVANCED

#include "iterator.h"


template<typename Type>
Type& Iterator<Type>::operator*()
{
    return get_value();
}

template<typename Type>
const Type& Iterator<Type>::operator*() const
{
    return get_value();
}

template<typename Type>
Type* Iterator<Type>::operator->()
{
    if (this->arr.expired())
        throw ErrorArrayExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw ErrorCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

template<typename Type>
const Type* Iterator<Type>::operator->() const
{
    if (this->arr.expired())
        throw ErrorArrayExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw ErrorCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

template<typename Type>
Type& Iterator<Type>::value()
{
    return get_value();
}

template<typename Type>
const Type& Iterator<Type>::value() const
{
    return get_value();
}

template<typename Type>
Type& Iterator<Type>::get_value()
{
    if (this->arr.expired())
        throw ErrorArrayExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw ErrorCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

template<typename Type>
const Type& Iterator<Type>::get_value() const
{
    if (this->arr.expired())
        throw ErrorArrayExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw ErrorCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

#endif // ITERATOR_HPP
