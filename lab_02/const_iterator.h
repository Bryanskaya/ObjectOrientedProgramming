#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include "base_iterator.h"


template<typename Type>
class Vector;

template<typename Type>
class ConstIterator : public BaseIterator<Type>
{
    friend class Vector<Type>;

public:
    ConstIterator(const ConstIterator &other) : BaseIterator<Type>(other){}

    const Type& value() const;
    const Type& operator*() const;
    const Type* operator->() const;

private:
    ConstIterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
             size_t ind = 0) : BaseIterator<Type>(a, c, ind) {}
    const Type& get_value() const;
};

#ifndef CONST_ITERATOR_HPP_ADVANCED
#include "const_iterator.hpp"
#endif // CONST_ITERATOR_HPP_ADVANCED

#endif // CONST_ITERATOR_H
