#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#define ITERATOR_HPP_ADVANCED

#include "iterator.h"


template<typename Type>
Type& Iterator<Type>::operator*()
{
    return _get_value();
}

template<typename Type>
const Type& Iterator<Type>::operator*() const
{
    return _get_value();
}

template<typename Type>
Type* Iterator<Type>::operator->()
{
    return _get_ptr();
}

template<typename Type>
const Type* Iterator<Type>::operator->() const
{
    return _get_ptr();
}

template<typename Type>
Type* Iterator<Type>::get_ptr()
{
    return _get_ptr();
}

template<typename Type>
const Type* Iterator<Type>::get_ptr() const
{
    return _get_ptr();
}

template<typename Type>
Type& Iterator<Type>::get_value()
{
    return _get_value();
}

template<typename Type>
const Type& Iterator<Type>::get_value() const
{
    return get_value();
}

template<typename Type>
Type& Iterator<Type>::_get_value()
{
    if (this->arr.expired())
        throw error::ArrayPtrExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

template<typename Type>
const Type& Iterator<Type>::_get_value() const
{
    if (this->arr.expired())
        throw error::ArrayPtrExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

template<typename Type>
const Type* Iterator<Type>::_get_ptr() const
{
    if (this->arr.expired())
        throw error::ArrayPtrExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return &a[this->index];
}

template<typename Type>
Type* Iterator<Type>::_get_ptr()
{
    if (this->arr.expired())
        throw error::ArrayPtrExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->count.expired())
        throw error::ArrayCountExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return &a[this->index];
}

#endif // ITERATOR_HPP
