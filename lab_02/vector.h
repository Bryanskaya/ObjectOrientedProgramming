#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <cmath>

#include "base_vector.h"
#include "iterator.h"

#define EPS 1e-5

using namespace std;

template<typename Type>
class Vector : public BaseVector
{
private:
    shared_ptr<Type[]> list_elem;

protected:
    void allocate_memory(int num);
    void sum_vectors(Vector<Type>& result, Vector<Type>& vector1,
                     Vector<Type>& vector2) const;
    void diff_vectors(Vector<Type>& result, Vector<Type>& vector1,
                      Vector<Type>& vector2) const;


public:
    Vector();
    Vector(int num);
    explicit Vector(initializer_list<Type> args);

    virtual ~Vector() = default;

    Iterator<Type> begin() const { return Iterator<Type>(list_elem, num_elem); }
    Iterator<Type> end() const { return Iterator<Type>(list_elem, num_elem, *num_elem); }

    void my_print();
    void my_print_iter();

    // ВАЖНО!!! нужно слежить за аргументами, здесь не все готовые заголовки, кое-что взято из учебника
    // + здесь нет функций для итератора!!!!!! ни из документа, ни из учебника
    /*
    Vector(const Vector<type>& vector);*/

    Type& operator[](int index);

    /*Vector<type>& operator =(const Vector<type>& list);
    template<typename _type>friend osteam& operator <<(osteam& os, const Vector<_type>& list); // разобраться с этим*/
    Vector<Type>& operator +=(const Vector<Type>& vector);
    Vector<Type>& operator +(const Vector<Type>& vector) const;

    Vector<Type>& operator -=(const Vector<Type>& vector);
    Vector<Type>& operator -(const Vector<Type>& vector) const;
    /*Vector<type>& operator *=(const Vector<type>& num);
    Vector<type>& operator /=(const Vector<type>& num);*/

    bool operator ==(const Vector<Type>&) const;
    bool operator !=(const Vector<Type>&) const;

    /*template<typename _type>friend Vector<_type> operator +(const Vector<_type>& vector1,
                                                            const Vector<_type>& vector2);
    template<typename _type>friend Vector<_type> operator -(const Vector<_type>& vector1,
                                                            const Vector<_type>& vector2);
    template<typename _type>friend Vector<_type> operator *(const Vector<_type>& vector,
                                                            const type& num);  // понять разницу с другой перегрузкой *=
    template<typename _type>friend Vector<_type> operator /(const Vector<_type>& vector,
                                                            const type& num);
    */

    double get_length() const;

    /*void clear(); // аналог есть в базовом, но там только обнуление числа

    void set_elem(int ind, const type& elem);
    void set_same_elems(int num, const type &num); // const type &num не уверена, это из книги - проверить. Заполняет вектор одинаковыми числами
*/
    Type& get_elem(size_t index);

    Type& get_first_elem();
    Type& get_last_elem();

    /*type[] replace_vector(); // можно наверное назвать copy*/
};

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

    *num_elem = shared_ptr<size_t>(new size_t(num));
    allocate_memory(*num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);

    // что-то с итератором, пока не поняла что и зачем
}

template<typename Type>
Vector<Type>::Vector(initializer_list<Type> args)
{
    if (!args.size())
        Vector();

    *num_elem = int(args.size());
    allocate_memory(*num_elem);

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
void Vector<Type>::allocate_memory(int num)
{
    shared_ptr<Type[]> ptr_temp(new Type[num], default_delete<Type[]>());
    if (!ptr_temp)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__ - 1);
    list_elem.reset();
    list_elem = ptr_temp;
}

template<typename Type>
void Vector<Type>::my_print()
{
    for (int i = 0; i < *num_elem; i++)
        cout << list_elem[i] << ' ';
    cout << endl;
}

template<typename Type>
void Vector<Type>::my_print_iter()
{
    Iterator<Type> iter = this->begin();
    for (; iter; iter++)
        cout << *iter << ' ';
    cout << endl;
}

template<typename Type>
Type& Vector<Type>::operator[](int index)
{
    return get_elem(index);
}

template<typename Type>
bool Vector<Type>::operator ==(const Vector<Type>& vector) const
{
    if (num_elem != vector.num_elem)
        return false;

    Iterator<Type> iter1 = this->begin(), iter2 = vector.begin();

    for (; iter1; iter1++, iter2++)
        if (fabs(*iter1 - *iter2) > EPS)
            return false;

    return true;
}

template<typename Type>
bool Vector<Type>::operator !=(const Vector<Type>& vector) const
{
    if (num_elem != vector.num_elem)
        return true;

    Iterator<Type> iter1(*this), iter2(vector); // странно, см.выше
    for (; iter1; iter1++, iter2++)
        if (fabs(*iter1 - *iter2) > EPS)
            return true;
    /*if (*this == vec) // разобраться
        return false;
    else
        return true;*/

    return false;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& vector)
{
    if (num_elem <= 0 || vector.num_elem <= 0)
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (num_elem != vector.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            num_elem, vector.num_elem);

    sum_vectors(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& vector)
{
    if (num_elem <= 0 || vector.num_elem <= 0)
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (num_elem != vector.num_elem)
        throw ErrorDiffSize(__FILE__, typeid (*this).name(), __LINE__ - 1,
                            num_elem, vector.num_elem);

    diff_vectors(*this, *this, vector);

    return *this;
}

template<typename Type>
double Vector<Type>::get_length() const
{
    if (*num_elem <= 0)
        throw ErrorEmpty(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<Type> iter = this->begin();
    double len = 0;

    for (; iter; iter++)
        len += *iter * *iter;

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
void Vector<Type>::sum_vectors(Vector<Type>& result, Vector<Type>& vector1,
                               Vector<Type>& vector2) const
{
    Iterator<Type> iter_res(result), iter1(vector1), iter2(vector2);

    for (; iter1; iter_res++, iter1++, iter2++)
        *iter_res = *iter1 + *iter2;
}

template<typename Type>
void Vector<Type>::diff_vectors(Vector<Type>& result, Vector<Type>& vector1,
                               Vector<Type>& vector2) const
{
    Iterator<Type> iter_res(result), iter1(vector1), iter2(vector2);

    for (; iter1; iter_res++, iter1++, iter2++)
        *iter_res = *iter1 - *iter2;
}


#endif // VECTOR_H
