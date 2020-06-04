#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>

#include "iterator.h"
#include "constiterator.h"
#include "basearray.h"

template <typename Type>
class Array : public BaseArray
{
public:
    Array();
    explicit Array(size_t num);
    Array(initializer_list<Type> args);
    explicit Array(const Array<Type>& other);
    Array(Array<Type>&& other);

    virtual ~Array() = default;

    Iterator<Type> begin() { return Iterator<Type>(_arr, _count); }
    Iterator<Type> end() { return Iterator<Type>(_arr, _count, *_count); }

    ConstIterator<Type> begin() const { return ConstIterator<Type>(_arr, _count); }
    ConstIterator<Type> end() const { return ConstIterator<Type>(_arr, _count, *_count); }

    ConstIterator<Type> const_begin() const { return ConstIterator<Type>(_arr, _count); }
    ConstIterator<Type> const_end() const { return ConstIterator<Type>(_arr, _count, *_count); }

    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;
    Type* get_arr();

    Array<Type>& operator=(const Array<Type>& other);
    Array<Type>& operator=(initializer_list<Type> args);
    Array<Type>& operator=(Array<Type>&& other);

    void append(const Type& elem);

    void clear();

private:
    shared_ptr<Type[]> _arr { nullptr };

    void _copy_array(const Array<Type>& other);
    void _clone_array(Array<Type>&& other);

    void _realloc(size_t new_size);
    Type& _get_elem(size_t index);
    const Type& _get_elem(size_t index) const;
    void _set_elem(size_t index, const Type& elem);
};

#ifndef ARRAY_HPP_ADVANCED
#include "array.hpp"
#endif // ARRAY_HPP_ADVANCED

#endif // ARRAY_H
