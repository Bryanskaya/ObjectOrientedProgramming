#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include "baseiterator.h"


template<typename Type>
class Array;

template<typename Type>
class ConstIterator : public BaseIterator<Type>
{
    friend class Array<Type>;

public:
    ConstIterator(const ConstIterator &other) : BaseIterator<Type>(other){}

    const Type& get_value() const;
    const Type& operator*() const;
    const Type* get_ptr() const;
    const Type* operator->() const;

private:
    ConstIterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
             size_t ind = 0) : BaseIterator<Type>(a, c, ind) {}
    const Type& _get_value() const;
    const Type* _get_ptr() const;
};

#ifndef CONST_ITERATOR_HPP_ADVANCED
#include "constiterator.hpp"
#endif // CONST_ITERATOR_HPP_ADVANCED

#endif // CONSTITERATOR_H
