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
    explicit Vector(int num);
    Vector(int num, Type vector[]);
    Vector(initializer_list<Type> args);
    explicit Vector(const Vector<Type>& vector);
    Vector(Vector<Type>&& vector);

    virtual ~Vector() = default;

    Iterator<Type> begin() { return Iterator<Type>(list_elem, num_elem); }
    Iterator<Type> end() { return Iterator<Type>(list_elem, num_elem, *num_elem); }

    ConstIterator<Type> begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    ConstIterator<Type> const_begin() const { return ConstIterator<Type>(list_elem, num_elem); }
    ConstIterator<Type> const_end() const { return ConstIterator<Type>(list_elem, num_elem, *num_elem); }

    bool operator ==(const Vector<Type>&) const;
    bool operator ==(Vector<Type>&& vector) const;
    bool is_equal(const Vector<Type>&) const;
    bool is_equal(initializer_list<Type> args) const;
    bool is_equal(Vector<Type>&& vector) const;


    bool operator !=(const Vector<Type>&) const;
    bool operator !=(Vector<Type>&& vector) const;
    bool isnt_equal(const Vector<Type>&) const;
    bool isnt_equal(initializer_list<Type> args) const;
    bool isnt_equal(Vector<Type>&& vector) const;


    Type& operator[](int index);
    const Type& operator[](int index) const;

    Type* get_arr();

    Vector<Type>& operator =(const Vector<Type>& other);
    Vector<Type>& operator =(initializer_list<Type> args);
    Vector<Type>& operator =(Vector<Type>&& vector);

    Vector<Type>& operator +=(const Vector<Type>& vector);
    Vector<Type>& operator +=(initializer_list<Type> args);
    Vector<Type>& operator +=(Vector<Type>&& vector);

    void add(const Vector<Type>& vector);
    void add(initializer_list<Type> args);
    void add(Vector<Type>&& vector);

    Vector<Type> operator +(const Vector<Type>& vector) const;
    Vector<Type> operator +(Vector<Type>&& vector) const;


    Vector<Type>& operator -=(const Vector<Type>& vector);
    Vector<Type>& operator -=(initializer_list<Type> args);
    Vector<Type>& operator -=(Vector<Type>&& vector);

    void sub(const Vector<Type>& vector);
    void sub(initializer_list<Type> args);
    void sub(Vector<Type>&& vector);

    Vector<Type> operator -(const Vector<Type>& vector) const;
    Vector<Type> operator -(Vector<Type>&& vector) const;


    Type operator *(const Vector<Type>& vector) const;
    Type operator *(Vector<Type>&& vector) const;

    Type scalar_mult(const Vector<Type>& vector) const;
    Type scalar_mult(initializer_list<Type> args) const;
    Type scalar_mult(Vector<Type>&& vector) const;


    Vector<Type> operator &(const Vector<Type>& vector) const;
    Vector<Type> operator &(Vector<Type>&& vector) const;

    Vector<Type>& operator &=(const Vector<Type>& vector);
    Vector<Type>& operator &=(initializer_list<Type> args);
    Vector<Type>& operator &=(Vector<Type>&& vector);

    Vector<Type> vector_mult(const Vector<Type>& vector) const;
    Vector<Type> vector_mult(initializer_list<Type> args) const;
    Vector<Type> vector_mult(Vector<Type>&& vector) const;


    Vector<Type>& operator *=(const Type& num);
    void mult_vect_num(const Type& num);

    Vector<Type> operator *(const Type& num) const;


    Vector<Type>& operator /=(const Type& num);
    void div_vect_num(const Type& num);

    Vector<Type> operator /(const Type& num) const;


    Vector<Type> operator -() const;
    Vector<Type> negative() const;


    Type get_length() const;

    void set_elem(size_t index, const Type& elem);

    double angle(const Vector<Type>& vector) const;

    //void normalize();
    Vector<Type> normalize() const;

    bool is_collinear(const Vector<Type>& vector) const;
    bool is_orthogonal(const Vector<Type>& vector) const;

    void clear();

private:
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
