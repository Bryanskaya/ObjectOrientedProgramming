#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "const_iterator.h"


template<typename Type>
const Type& ConstIterator<Type>::operator*() const
{
    if (this->arr.expired() || this->count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    this->is_end();

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return (*a)[this->index];
}

template<typename Type>
const Type* ConstIterator<Type>::operator->() const
{
    if (this->arr.expired() || this->count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return &(*a)[this->index];
}

template<typename Type>
const Type& ConstIterator<Type>::value() const
{
    return get_value();
}

template<typename Type>
const Type& ConstIterator<Type>::get_value() const
{
    if (this->arr.expired() || this->count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (this->index >= *(this->count.lock()))
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, this->index);

    shared_ptr<Type[]> a(this->arr);

    return a[this->index];
}

#endif // CONST_ITERATOR_HPP
