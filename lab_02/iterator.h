#ifndef ITERATOR_H
#define ITERATOR_H

#include "baseiterator.h"

template<typename Type>
class Iterator : public BaseIterator
{
    // скорее всего тут надо в private/protected указать weak/shared_ptr

    Type& operator*();
    Type* operator->();

    Iterator<Type>& operator+=(int n);
    Iterator<Type>& operator-=(int n);
    Iterator<Type>& operator++();
    Iterator<Type>& operator--();
    Iterator<Type> operator++(int);
    Iterator<Type> operator--(int);

    // еще сюда точно надо bool


};

template<class Type>
Type& Iterator<Type>::operator*()
{
    //
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    //
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    //
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator-=(int n)
{
    //
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    //
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    //
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    //
}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    //
}

#endif // ITERATOR_H
