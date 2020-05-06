#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <time.h>

#include "my_errors.h"

template<typename Type>
class Vector;

using namespace std;

template<typename Type>
class Iterator : public iterator<input_iterator_tag, Type>
{
    friend class Vector<Type>;
    Iterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c, size_t ind = 0) :
        arr(a), count(c), index(ind) {}

private:
    weak_ptr<Type[]> arr;
    weak_ptr<size_t> count;
    size_t index = 0;

public:
    /*Iterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c, size_t ind = 0) :
        arr(a), count(c), index(ind) {}*/

    Iterator(const Iterator &iter) = default;

    Type& operator*();
    const Type& operator*() const; //

    Type* operator->();
    const Type* operator->() const; //

    operator bool() const;

    Iterator<Type>& operator+(int n) const; // разобраться с ней
    Iterator<Type>& operator-(int n) const; // разобраться с ней

    Iterator<Type>& operator+=(int n); //
    Iterator<Type>& operator-=(int n); //

    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);

    Iterator<Type>& operator--();
    Iterator<Type> operator--(int);

    Iterator<Type>& operator=(const Iterator<Type>& iter); //

    bool operator==(Iterator const& other) const;
    bool operator!=(Iterator const& other) const;
    bool operator>=(Iterator const& other) const;
    bool operator>(Iterator const& other) const;
    bool operator<=(Iterator const& other) const;
    bool operator<(Iterator const& other) const;
};

template<typename Type>
Type& Iterator<Type>::operator*()
{
    time_t t = time(nullptr);

    if (arr.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1, ctime(&t));
    shared_ptr<Type[]> a(arr);

    return a[index];
}

template<typename Type>
Type* Iterator<Type>::operator->()
{
    //
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    //
}

template<typename Type> // узнать
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    Iterator<Type> iter(*this);
    shared_ptr<size_t> n_t(count);

    for (int i = 0; i < n; i++)
        ++iter;

    if (iter < *n_t)
        *this = iter;

    return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator-=(int n)
{
    //
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    time_t t = time(nullptr);

    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1, ctime(&t));
    shared_ptr<size_t> n(count);
    if (index < *n)
        index++;

    return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    time_t t = time(nullptr);

    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1, ctime(&t));
    shared_ptr<size_t> n(count);
    if (index > *n)
        index--;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    // проверка this
    Iterator<Type> iter(*this);

    ++(*this);

    return iter;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    // проверка this
    Iterator<Type> iter(*this);

    --(*this);

    return iter;
}

template<typename Type>
bool Iterator<Type>::operator==(Iterator const& other) const
{
    return index == other.index;
}

template<typename Type>
bool Iterator<Type>::operator!=(Iterator const& other) const
{
    return !(index == other.index);
}

template<typename Type>
bool Iterator<Type>::operator>=(Iterator const& other) const
{
    return index >= other.index;
}

template<typename Type>
bool Iterator<Type>::operator>(Iterator const& other) const
{
    return index > other.index;
}

template<typename Type>
bool Iterator<Type>::operator<=(Iterator const& other) const
{
    return index <= other.index;
}

template<typename Type>
bool Iterator<Type>::operator<(Iterator const& other) const
{
    return index < other.index;
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    time_t t = time(nullptr);

    if (count.expired())
        throw ErrorNotExist(__FILE__, typeid (*this).name(), __LINE__ - 1, ctime(&t));

    if (index >= *(count.lock()))
        return false;
    return true;
}

#endif // ITERATOR_H
