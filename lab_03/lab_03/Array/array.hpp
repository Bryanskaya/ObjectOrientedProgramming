#ifndef ARRAY_HPP
#define ARRAY_HPP
#define ARRAY_HPP_ADVANCED

#include "array.h"

template<typename Type>
Array<Type>::Array() : BaseArray(0), _arr(nullptr){}

template<typename Type>
Array<Type>::Array(size_t num)
{
    _realloc(num);
}

template<typename Type>
Array<Type>::Array(const Array<Type>& other) :
    BaseArray(other)
{
    _copy_array(other);
}

template<typename Type>
Array<Type>::Array(initializer_list<Type> args)
{
    _realloc(args.size());

    Iterator<Type> iter = this->begin();
    for (Type elem : args)
    {
        *iter = elem;
        iter++;
    }
}

template<typename Type>
Array<Type>::Array(Array<Type>&& other)
{
    _realloc(other.get_size());

    Iterator<Type> iter1 = this->begin();
    ConstIterator<Type> iter2 = other.const_begin();
    for (; iter1; iter1++, iter2++)
        *iter1 = *iter2;
    other.clear();
}

template<typename Type>
Type& Array<Type>::operator[](size_t index)
{
    return _get_elem(index);
}

template<typename Type>
const Type& Array<Type>::operator[](size_t index) const
{
    return _get_elem(index);
}

/*template<typename Type>
Type* Array<Type>::get_arr()
{
    if (!get_size()) return nullptr;

    Type* arr = new Type[*num_elem];
    for (size_t i = 0; i < *num_elem; i++)
        arr[i] = _get_elem(i);

    return arr;
}*/

template<typename Type>
Array<Type>& Array<Type>::operator =(const Array<Type>& other)
{
    _copy_array(other);

    return *this;
}

/*template<typename Type>
Array<Type>& Array<Type>::operator =(initializer_list<Type> args)
{
    _set_init_list(args);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(Vector<Type>&& vector)
{
    Vector<Type> other(vector);

    _copy_vector(other);

    return *this;
}*/

template<typename Type>
void Array<Type>::append(const Type& new_el)
{
    _realloc(get_size()+1);
    this[get_size() - 1] = new_el;
}

template<typename Type>
void Array<Type>::clear()
{
    if (!get_size()) return;

    _arr.reset();
    _realloc(0);
}

template<typename Type>
void Array<Type>::_copy_array(const Array<Type>& other)
{
    _realloc(other.get_size());

    Iterator<Type> iter1 = this->begin();
    ConstIterator<Type> iter2 = other.begin();
    for (; iter1; iter1++, iter2++)
        *iter1 = *iter2;
}

template <typename Type>
void Array<Type>::_clone_array(Array<Type>&& other)
{
    _arr = other._arr;
    _count = other._count;
}

template<typename Type>
Type& Array<Type>::_get_elem(size_t index)
{
    if (index >= get_size())
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, index);
    return _arr[index];
}

template<typename Type>
const Type& Array<Type>::_get_elem(size_t index) const
{
    if (index >= get_size())
        throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, index);
    return _arr[index];
}

template<typename Type>
void Array<Type>::_realloc(size_t new_size)
{
    if (new_size == get_size())
        return;

    if (_arr == nullptr)
    {
        try
        {
            _arr = shared_ptr<Type[]>(new Type[new_size]);
        }
        catch(std::bad_alloc&)
        {
            throw error::AllocProblem(__FILE__, typeid (*this).name(), __LINE__ - 4);
        }
    }
    else if (new_size)
    {
        Array<Type> new_arr(new_size);

        Iterator<Type> iter1 = new_arr.begin();
        ConstIterator<Type> iter2 = this->const_begin();
        for (; bool(iter1) && bool(iter2); iter1++, iter2++)
            *iter1 = *iter2;
        _clone_array(std::move(new_arr));
    }
    else
        _arr.reset();
    *_count = new_size;
}


#endif // ARRAY_HPP
