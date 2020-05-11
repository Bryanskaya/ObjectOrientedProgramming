#ifndef VECTOR_HPP
#define VECTOR_HPP
#define VECTOR_HPP_ADVANCED

#include "vector.h"

template<typename Type>
void Vector<Type>::_allocate_memory(int num)
{
    try
    {
        shared_ptr<Type[]> ptr_temp(new Type[num], default_delete<Type[]>());

        list_elem.reset();
        list_elem = ptr_temp;
    }
    catch (bad_alloc&)
    {
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);
    }
}

template<typename Type>
void Vector<Type>::_set_init_list(initializer_list<Type> args)
{
    if (!args.size())
        Vector();

    *num_elem = int(args.size());
    _allocate_memory(*num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<Type> iter = this->begin();
    for (Type arg : args)
    {
        *iter = arg;
        iter++;
    }
}

template<typename Type>
void Vector<Type>::_copy_vector(const Vector<Type>& other)
{
    *num_elem = *other.num_elem;
    _allocate_memory(*num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<Type> iter_new = this->begin();
    ConstIterator<Type> iter = other.begin();
    for (; iter; iter++, iter_new++)
        *iter_new = *iter;
}

template<typename Type>
bool Vector<Type>::_is_equal(const Vector<Type>& other) const
{
    if (*num_elem != *other.num_elem)
        return false;

    ConstIterator<Type> iter1 = this->begin(), iter2 = other.begin();
    for (; iter1; iter1++, iter2++)
        if (fabs(*iter1 - *iter2) > EPS)
            return false;

    return true;
}

template<typename Type>
bool Vector<Type>::_is_empty(const Vector<Type>& vector) const
{
    if (!*vector.num_elem)
        return true;

    return false;
}

template<typename Type>
Type& Vector<Type>::_get_elem(size_t index)
{
    if (index >= *num_elem)
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1,
                         index);

    return list_elem[index];
}

template<typename Type>
const Type& Vector<Type>::_get_elem(size_t index) const
{
    if (index >= *num_elem)
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1,
                         index);

    return list_elem[index];
}

template<typename Type>
Type Vector<Type>::_scalar_mult(const Vector<Type>& vector1,
                                const Vector<Type>& vector2) const
{
    if (*vector1.num_elem != *vector2.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, *vector2.num_elem);

    ConstIterator<Type> iter1 = vector1.begin(),
                        iter2 = vector2.begin();

    Type mul = 0;
    for (; iter1; iter1++, iter2++)
        mul += *iter1 * *iter2;

    return mul;
}

template<typename Type>
Type Vector<Type>::_scalar_mult(const Vector<Type>& vector,
                                initializer_list<Type> args) const
{
    if (!args.size())
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (*vector.num_elem != args.size())
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector.num_elem, args.size());

    ConstIterator<Type> iter = vector.begin();

    Type mul = 0;
    for (Type arg : args)
    {
        mul += *iter * arg;
        iter++;
    }

    return mul;
}

template<typename Type>
Vector<Type> Vector<Type>::_vector_mult(const Vector<Type>& vector1,
                                        const Vector<Type>& vector2) const
{
    if (*vector1.num_elem != *vector2.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, *vector2.num_elem);

    if (*vector1.num_elem != SIZE_3D)
        throw ErrorNotAllowedSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, SIZE_3D);

    Vector<Type> result(vector1);

    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::_vector_mult(const Vector<Type>& vector1,
                                        initializer_list<Type> args) const
{
    if (*vector1.num_elem != args.size())
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, args.size());

    if (*vector1.num_elem != SIZE_3D)
        throw ErrorNotAllowedSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, SIZE_3D);

    Vector<Type> result(vector1);
    Vector<Type> vector2(args);

    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::_vect_num_mult(const Vector<Type>& vector,
                                          const Type& num) const
{
    if (_is_empty(vector))
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Vector<Type> result(vector);

    Iterator<Type> iter_res = result.begin();
    ConstIterator<Type> iter = vector.begin();
    for (; iter; iter++, iter_res++)
        *iter_res = (*iter) * num;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::_vect_num_div(const Vector<Type>& vector,
                                          const Type& num) const
{
    if (_is_empty(vector))
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (!num)
        throw ErrorDivZero(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Vector<Type> result(vector);

    Iterator<Type> iter_res = result.begin();
    ConstIterator<Type> iter = vector.begin();
    for (; iter; iter++, iter_res++)
        *iter_res = (*iter) / num;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::_sum_vectors(const Vector<Type>& vector1,
                                        const Vector<Type>& vector2) const
{
    if (_is_empty(vector1) || _is_empty(vector2))
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (*vector1.num_elem != *vector2.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, *vector2.num_elem);

    Vector<Type> result(vector1);
    ConstIterator<Type> iter1 = vector1.begin(), iter2 = vector2.begin();
    Iterator<Type> iter_res = result.begin();

    for (; iter1; iter_res++, iter1++, iter2++)
        *iter_res = *iter1 + *iter2;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::_diff_vectors(const Vector<Type>& vector1,
                                 const Vector<Type>& vector2) const
{
    if (_is_empty(vector1) || _is_empty(vector2))
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Vector<Type> result(vector1);
    ConstIterator<Type> iter1 = vector1.begin(), iter2 = vector2.begin();
    Iterator<Type> iter_res = result.begin();

    for (; iter1; iter_res++, iter1++, iter2++)
        *iter_res = *iter1 - *iter2;

    return result;
}

template<typename Type>
void Vector<Type>::_print() const
{
    if (_is_empty(*this))
        return;

    cout << "( ";
    for (Type val : *this)
        cout << val << " ";
    cout << ")";
}



template<typename Type>
Vector<Type>::Vector()
{
    num_elem = shared_ptr<size_t>(new size_t(0));
    list_elem = nullptr;
}

template<typename Type>
Vector<Type>::Vector(int num)
{
    if (num <= 0)
        throw ErrorSize(__FILE__, typeid (*this).name(), __LINE__ - 1, num);

    num_elem = shared_ptr<size_t>(new size_t(num));
    _allocate_memory(*num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type>& vector) :
    BaseVector(vector)
{
    _copy_vector(vector);
}

template<typename Type>
Vector<Type>::Vector(initializer_list<Type> args)
{
    _set_init_list(args);
}

template<typename Type>
Vector<Type>::Vector(Vector<Type>&& vector)
{
    _copy_vector(vector);
    vector.clear();
}



template<typename Type>
bool Vector<Type>::operator ==(const Vector<Type>& vector) const
{
    return _is_equal(vector);
}

template<typename Type>
bool Vector<Type>::operator !=(const Vector<Type>& vector) const
{
    return !_is_equal(vector);
}

template<typename Type>
Type& Vector<Type>::operator[](int index)
{
    return _get_elem(index);
}

template<typename Type>
const Type& Vector<Type>::operator[](int index) const
{
    return _get_elem(index);
}

template<typename Type>
Type* Vector<Type>::get_arr()
{
    if (_is_empty(*this)) return nullptr;

    Type* arr = new Type[*num_elem];
    for (size_t i = 0; i < *num_elem; i++)
        arr[i] = _get_elem(i);

    return arr;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(const Vector<Type>& other)
{
    _copy_vector(other);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(initializer_list<Type> args)
{
    if (!_is_empty(*this)) clear();

    _set_init_list(args);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& vector)
{
    *this = _sum_vectors(*this, vector);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator +=(initializer_list<Type> args)
{
    if (!args.size())
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (args.size() != *num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1, args.size(), *num_elem);

    Iterator<Type> iter = this->begin();
    for (Type arg : args)
    {
        *iter += arg;
        iter++;
    }

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type>& vector) const
{
    return _sum_vectors(*this, vector);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& vector)
{
    *this = _diff_vectors(*this, vector);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator -=(initializer_list<Type> args)
{
    if (!args.size())
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (args.size() != *num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1, args.size(), *num_elem);

    Iterator<Type> iter = this->begin();
    for (Type arg : args)
    {
        *iter -= arg;
        iter++;
    }

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type>& vector) const
{
    return _diff_vectors(*this, vector);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator *=(const Type& num)
{
    *this = _vect_num_mult(*this, num);

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator *(const Type& num) const
{
    return _vect_num_mult(*this, num);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator /=(const Type& num)
{
    *this = _vect_num_div(*this, num);

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator /(const Type& num) const
{
    return _vect_num_div(*this, num);
}

template<typename Type>
Type Vector<Type>::operator *(const Vector<Type>& vector) const
{
    return _scalar_mult(*this, vector);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator *=(const Vector<Type>& vector)
{
    *this = _vector_mult(*this, vector);

    return *this;
}

template<typename Type>
void Vector<Type>::add(const Vector<Type>& vector)
{
    *this = _sum_vectors(*this, vector);
}

template<typename Type>
void Vector<Type>::add(initializer_list<Type> args)
{
    Vector<Type> vector(args);
    *this = _sum_vectors(*this, vector);
}

template<typename Type>
void Vector<Type>::sub(const Vector<Type>& vector)
{
    *this = _diff_vectors(*this, vector);
}

template<typename Type>
void Vector<Type>::sub(initializer_list<Type> args)
{
    Vector<Type> vector(args);
    *this = _diff_vectors(*this, vector);
}

template<typename Type>
double Vector<Type>::get_length() const
{
    if (_is_empty(*this))
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    double len = 0;

    for (Type val : *this)
        len += val * val;

    return sqrt(len);
}

template<typename Type>
void Vector<Type>::set_elem(size_t index, const Type& elem)
{
    if (index < 0 || index >= *num_elem)
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1, index);

    list_elem[index] = elem;
}

template<typename Type>
void Vector<Type>::invert()
{
    *this = _vect_num_mult(*this, -1);
}

template<typename Type>
double Vector<Type>::angle(const Vector<Type>& vector) const
{
    if (!this->get_length() || !vector.get_length())
        throw ErrorDivZero(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (*num_elem != *vector.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *num_elem, *vector.num_elem);

    double angle = scalar_mult(vector) / (this->get_length() * vector.get_length());

    return acos(angle);
}

template<typename Type>
Type Vector<Type>::scalar_mult(const Vector<Type>& vector) const
{
    return _scalar_mult(*this, vector);
}

template<typename Type>
Type Vector<Type>::scalar_mult(initializer_list<Type> args) const
{
    return _scalar_mult(*this, args);
}

template<typename Type>
Vector<Type> Vector<Type>::vector_mult(const Vector<Type>& vector) const
{
    return _vector_mult(*this, vector);
}

template<typename Type>
Vector<Type> Vector<Type>::vector_mult(initializer_list<Type> args) const
{
    return _vector_mult(*this, args);
}







template<typename Type>
void Vector<Type>::clear()
{
    if (!*num_elem) return;

    list_elem.reset();
    *num_elem = 0;
}

#endif // VECTOR_HPP
