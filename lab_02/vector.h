#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <cmath>
#include <ostream>

#include "base_vector.h"
#include "iterator.h"
#include "const_iterator.h"

#define EPS 1e-5

using namespace std;

template<typename Type>
class Vector : public BaseVector
{
private:
    shared_ptr<Type[]> list_elem;

    void _copy_vector(const Vector<Type>& other);
    bool _is_equal(const Vector<Type>& other) const;
    bool _is_empty(const Vector<Type>& vector) const;
    void _allocate_memory(int num);
    Type _scalar_mult(const Vector<Type>& vector1,
                      const Vector<Type>& vector2) const;
    Vector<Type> _vect_num_mult(const Vector<Type>& vector,
                                const Type& num) const;
    Vector<Type> _vect_num_div(const Vector<Type>& vector,
                                const Type& num) const;

    Vector<Type> _sum_vectors(const Vector<Type>& vector1,
                              const Vector<Type>& vector2) const;
    Vector<Type> _diff_vectors(const Vector<Type>& vector1,
                               const Vector<Type>& vector2) const;

    void _print() const;

public:
    Vector();
    Vector(int num);
    explicit Vector(const Vector<Type>& vector); // у тассова тут не  было explicit
    explicit Vector(initializer_list<Type> args);
    Vector(Vector<Type>&& vector);

    virtual ~Vector() = default;

    Iterator<Type> begin() { return Iterator<Type>(list_elem, num_elem); }
    Iterator<Type> end() { return Iterator<Type>(list_elem, num_elem, *num_elem); }
    ConstIterator<Type> begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    ConstIterator<Type> const_begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> const_end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    // ВАЖНО!!! нужно слежить за аргументами, здесь не все готовые заголовки, кое-что взято из учебника
    // + здесь нет функций для итератора!!!!!! ни из документа, ни из учебника

    Type& operator[](int index);

    friend ostream& operator <<(ostream &os, const Vector<Type>& arr)
    {
        arr._print();
        return os;
    }

    Vector<Type>& operator =(const Vector<Type>& other);

    Vector<Type>& operator +=(const Vector<Type>& vector);
    Vector<Type> operator +(const Vector<Type>& vector) const;

    Vector<Type>& operator -=(const Vector<Type>& vector);
    Vector<Type> operator -(const Vector<Type>& vector) const;

    Vector<Type>& operator *=(const Type& num);
    Vector<Type> operator *(const Type& num) const;

    Vector<Type>& operator /=(const Type& num);
    Vector<Type> operator /(const Type& num) const;

    Type operator *(const Vector<Type>& vector) const;

    bool operator ==(const Vector<Type>&) const;
    bool operator !=(const Vector<Type>&) const;

    double get_length() const;

    void clear();

    /*void set_elem(int ind, const type& elem);
    void set_same_elems(int num, const type &num); // const type &num не уверена, это из книги - проверить. Заполняет вектор одинаковыми числами
*/
    Type& get_elem(size_t index);

    Type& get_first_elem();
    Type& get_last_elem();

    double angle(const Vector<Type>& vector) const;
    Type scalar_mul(const Vector<Type>& vector) const;
    Type vector_mul(const Vector<Type>& vector) const;

    /*type[] replace_vector(); // можно наверное назвать copy - уточнить с документом тассова*/
};

/*template<typename Type>
friend osteam& operator <<(osteam& os, const Vector<Type>& list)
*/

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
Vector<Type>::Vector(Vector<Type>&& vector)
{
    _copy_vector(vector);
    vector.clear();
}

template<typename Type>
Vector<Type>::Vector(initializer_list<Type> args)
{
    if (!args.size())
        Vector();

    *num_elem = int(args.size());
    _allocate_memory(*num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);

    int i = 0;
    for (Type arg : args)
    {
        list_elem[i] = arg;
        i++;
    }
}

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

/*template<typename Type>
void Vector<Type>::my_print()
{
    for (unsigned int i = 0; i < *num_elem; i++)
        cout << list_elem[i] << ' ';
    cout << endl;
}*/

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
Type& Vector<Type>::operator[](int index)
{
    return get_elem(index);
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
void Vector<Type>::_copy_vector(const Vector<Type>& other)
{
    *num_elem = *other.num_elem;
    _allocate_memory(*num_elem);

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
Vector<Type>& Vector<Type>::operator =(const Vector<Type>& other)
{
    _copy_vector(other);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& vector)
{
    *this = _sum_vectors(*this, vector);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& vector)
{
    *this = _diff_vectors(*this, vector);

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type>& vector) const
{
    return _sum_vectors(*this, vector);
    /*Vector<Type> new_vector(_sum_vectors(*this, vector));
    return new_vector;*/
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
double Vector<Type>::get_length() const
{
    if (*num_elem <= 0)
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    double len = 0;

    for (Type val : *this)
        len += val * val;

    return sqrt(len);
}

template<typename Type>
Type& Vector<Type>::get_elem(size_t index)
{
    if (index >= *num_elem)
        throw ErrorIndex(__FILE__, typeid (*this).name(), __LINE__ - 1,
                         index);

    return list_elem[index];
}

template<typename Type>
Type& Vector<Type>::get_first_elem()
{
    //проверка
    return list_elem[0];
}

template<typename Type>
Type& Vector<Type>::get_last_elem()
{
    //проверка
    return list_elem[*num_elem - 1];
}

template<typename Type>
Vector<Type> Vector<Type>::_sum_vectors(const Vector<Type>& vector1,
                                        const Vector<Type>& vector2) const
{
    if (*vector1.num_elem <= 0 || *vector2.num_elem <= 0)
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
double Vector<Type>::angle(const Vector<Type>& vector) const
{
    if (!this->get_length() || vector.get_length())
        throw ErrorDivZero(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (*num_elem != *vector.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *num_elem, *vector.num_elem);

    double angle = scalar_mul(vector) / (this->get_length() * vector.get_length());

    return acos(angle);
}

template<typename Type>
Vector<Type> Vector<Type>::_diff_vectors(const Vector<Type>& vector1,
                                 const Vector<Type>& vector2) const
{
    if (*vector1.num_elem <= 0 || *vector2.num_elem <= 0)
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Vector<Type> result(vector1);
    ConstIterator<Type> iter1 = vector1.begin(), iter2 = vector2.begin();
    Iterator<Type> iter_res = result.begin();

    for (; iter1; iter_res++, iter1++, iter2++)
        *iter_res = *iter1 - *iter2;

    return result;
}

template<typename Type>
Type Vector<Type>::_scalar_mult(const Vector<Type>& vector1,
                                const Vector<Type>& vector2) const
{
    if (*vector1.num_elem != *vector2.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            *vector1.num_elem, *vector2.num_elem);

    Iterator<Type> iter1 = vector1.begin();
    ConstIterator<Type> iter2 = vector2.begin();

    Type mul = 0;
    for (; iter1; iter1++, iter2++)
        mul += *iter1 * *iter2;

    return mul;
}

template<typename Type>
Vector<Type> Vector<Type>::_vect_num_mult(const Vector<Type>& vector,
                                          const Type& num) const
{
    if (*vector.num_elem <= 0)
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
    if (*vector.num_elem <= 0)
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
void Vector<Type>::clear()
{
    if (!*num_elem) return;

    list_elem.reset();
    *num_elem = 0;
}

template<typename Type>
Type Vector<Type>::scalar_mul(const Vector<Type>& vector) const
{
    return _scalar_mult(*this, vector);
}

template<typename Type>
Type Vector<Type>::vector_mul(const Vector<Type>& vector) const
{

    return get_length() * vector.get_length() * sin(angle(vector));
}

#endif // VECTOR_H
