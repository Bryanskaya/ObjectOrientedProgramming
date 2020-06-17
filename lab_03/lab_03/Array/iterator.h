#ifndef ITERATOR_H
#define ITERATOR_H

#include "baseiterator.h"


template<typename Type>
class Array;

template<typename Type>
class Iterator : public BaseIterator<Type>
{
    friend class Array<Type>;

public:
    Iterator(const Iterator &other) : BaseIterator<Type>(other){}

    Type& get_value();
    const Type& get_value() const;

    Type& operator*();
    const Type& operator*() const;

    Type* get_ptr();
    const Type* get_ptr() const;

    Type* operator->();
    const Type* operator->() const;

private:
    Iterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
             size_t ind = 0) : BaseIterator<Type>(a, c, ind) {}
    Type& _get_value();
    const Type& _get_value() const;

    Type* _get_ptr();
    const Type* _get_ptr() const;
};

#ifndef ITERATOR_HPP_ADVANCED
#include "iterator.hpp"
#endif // ITERATOR_HPP_ADVANCED

#endif // ITERATOR_H
