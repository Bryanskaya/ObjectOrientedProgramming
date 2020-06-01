#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>

#include "Errors/arrayerrors.h"

using namespace std;

template<typename Type>
class BaseIterator : public iterator<input_iterator_tag, Type>
{
public:
    BaseIterator(const BaseIterator<Type> &other)
    {
        arr = other.arr;
        count = other.count;
        index = other.index;
    }

    BaseIterator<Type>& next();
    bool is_end() const;

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

private:
    BaseIterator<Type>& _next();
    bool _is_end() const;
};

#ifndef BASE_ITERATOR_HPP_ADVANCED
#include "baseiterator.hpp"
#endif // BASE_ITERATOR_HPP_ADVANCED

#endif // BASEITERATOR_H
