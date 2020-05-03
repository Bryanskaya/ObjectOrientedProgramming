#ifndef VECTOR_H
#define VECTOR_H

#include "basevector.h"


class Vector : public BaseVector
{
public:
    Vector();
    ~Vector();

    /*Vector(int length);
    Vector(const Vector<type>& vector);
    explicit Vector(initializer_list<type> list);

    Vector<type>& operator =(const Vector<type>& list);
    template<typename _type>friend osteam& operator <<(osteam& os, const Vector<_type>& list); // разобраться с этим
    Vector<type>& operator +=(const Vector<type>& vector);
    Vector<type>& operator -=(const Vector<type>& vector);
    Vector<type>& operator *=(const Vector<type>& num);
    Vector<type>& operator /=(const Vector<type>& num);
    template<typename _type>friend Vector<_type> operator +(const Vector<_type>& vector1,
                                                            const Vector<_type>& vector2);
    template<typename _type>friend Vector<_type> operator -(const Vector<_type>& vector1,
                                                            const Vector<_type>& vector2);
    template<typename _type>friend Vector<_type> operator *(const Vector<_type>& vector,
                                                            const type& num);  // понять разницу с другой перегрузкой *=
    template<typename _type>friend Vector<_type> operator /(const Vector<_type>& vector,
                                                            const type& num);

    int get_length(); // есть в базовом: где лучше???
    void clear(); // аналог есть в базовом, но там только обнуление числа

    void set_elem(int ind, const type& elem);
    void set_same_elems(int num, const type &num); // const type &num не уверена, это из книги - проверить. Заполняет вектор одинаковыми числами
    type& get_elem(int ind);
    type& get_first_elem();
    type& get_last_elem();
    type& operator[](int ind); // доступ к элементу аналогично массиву - не нравится


    type[] replace_vector(); // можно наверное назвать copy*/
};

#endif // VECTOR_H
