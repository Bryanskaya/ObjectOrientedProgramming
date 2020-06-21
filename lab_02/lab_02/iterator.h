#ifndef ITERATOR_H
#define ITERATOR_H

#include "base_iterator.h"


template<typename Type>
class Vector;

template<typename Type>
class Iterator : public BaseIterator<Type>
{
    friend class Vector<Type>;

public:
    Iterator(const Iterator &other) : BaseIterator<Type>(other){}

    Type& value();
    const Type& value() const;

    Type& operator*();
    const Type& operator*() const;

    Type* operator->();
    const Type* operator->() const;

private:
    Iterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
             size_t ind = 0) : BaseIterator<Type>(a, c, ind) {}
    Type& get_value();
    const Type& get_value() const;
};


#ifndef ITERATOR_HPP_ADVANCED
#include "iterator.hpp"
#endif // ITERATOR_HPP_ADVANCED

#endif // ITERATOR_H
