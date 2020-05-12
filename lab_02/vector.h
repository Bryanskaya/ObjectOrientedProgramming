#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <cmath>
#include <ostream>

#include "base_vector.h"
#include "iterator.h"
#include "const_iterator.h"


using namespace std;

template<typename Type>
class Vector : public BaseVector
{
public:
    Vector();
    Vector(int num);
    explicit Vector(const Vector<Type>& vector);
    explicit Vector(initializer_list<Type> args);
    Vector(Vector<Type>&& vector);

    virtual ~Vector() = default;

    Iterator<Type> begin() { return Iterator<Type>(list_elem, num_elem); }
    Iterator<Type> end() { return Iterator<Type>(list_elem, num_elem, *num_elem); }

    ConstIterator<Type> begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    ConstIterator<Type> const_begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> const_end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    bool operator ==(const Vector<Type>&) const;
    bool operator !=(const Vector<Type>&) const;

    Type& operator[](int index);
    const Type& operator[](int index) const;

    Type* get_arr();

    Vector<Type>& operator =(const Vector<Type>& other);
    Vector<Type>& operator =(initializer_list<Type> args);

    Vector<Type>& operator +=(const Vector<Type>& vector);
    Vector<Type>& operator +=(initializer_list<Type> args);

    Vector<Type> operator +(const Vector<Type>& vector) const;

    Vector<Type>& operator -=(const Vector<Type>& vector);
    Vector<Type>& operator -=(initializer_list<Type> args);

    Vector<Type> operator -(const Vector<Type>& vector) const;

    Vector<Type>& operator *=(const Type& num);
    Vector<Type> operator *(const Type& num) const;

    Vector<Type>& operator /=(const Type& num);
    Vector<Type> operator /(const Type& num) const;

    Type operator *(const Vector<Type>& vector) const;
    Vector<Type>& operator *=(const Vector<Type>& vector);

    void add(const Vector<Type>& vector);
    void add(initializer_list<Type> args);

    void sub(const Vector<Type>& vector);
    void sub(initializer_list<Type> args);

    friend ostream& operator <<(ostream &os, const Vector<Type>& arr)
    {
        arr._print();
        return os;
    }

    double get_length() const;

    void set_elem(size_t index, const Type& elem);

    void invert();

    double angle(const Vector<Type>& vector) const;

    Type scalar_mult(const Vector<Type>& vector) const;
    Type scalar_mult(initializer_list<Type> args) const;

    Vector<Type> vector_mult(const Vector<Type>& vector) const;
    Vector<Type> vector_mult(initializer_list<Type> args) const;

    void clear();

private:
    const double EPS = 1e-5;
    const unsigned int SIZE_3D = 3;

    shared_ptr<Type[]> list_elem;

    void _allocate_memory(int num);
    void _set_init_list(initializer_list<Type> args);

    void _copy_vector(const Vector<Type>& other);

    bool _is_equal(const Vector<Type>& other) const;

    Type& _get_elem(size_t index);
    const Type& _get_elem(size_t index) const;

    Type _scalar_mult(const Vector<Type>& vector1,
                      const Vector<Type>& vector2) const;
    Type _scalar_mult(const Vector<Type>& vector,
                      initializer_list<Type> args) const;

    Vector<Type> _vector_mult(const Vector<Type>& vector1,
                              const Vector<Type>& vector2) const;
    Vector<Type> _vector_mult(const Vector<Type>& vector1,
                              initializer_list<Type> args) const;

    Vector<Type> _vect_num_mult(const Vector<Type>& vector,
                                const Type& num) const;
    Vector<Type> _vect_num_div(const Vector<Type>& vector,
                                const Type& num) const;

    Vector<Type> _sum_vectors(const Vector<Type>& vector1,
                              const Vector<Type>& vector2) const;
    Vector<Type> _diff_vectors(const Vector<Type>& vector1,
                               const Vector<Type>& vector2) const;
    void _print() const;
};


#ifndef VECTOR_HPP_ADVANCED
#include "vector.hpp"
#endif // VECTOR_HPP_ADVANCED

#endif // VECTOR_H
