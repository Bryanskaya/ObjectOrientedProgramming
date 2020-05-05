#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <time.h>

#include "basevector.h"
#include "my_errors.h"

template<typename Type>
class Vector : public BaseVector
{
private:
    shared_ptr<Type[]> list_elem;

protected:
    void allocate_memory(int num);
    void my_print();

public:
    Vector();
    Vector(int num);
    explicit Vector(initializer_list<Type> args);

    virtual ~Vector() = default;

    // ВАЖНО!!! нужно слежить за аргументами, здесь не все готовые заголовки, кое-что взято из учебника
    // + здесь нет функций для итератора!!!!!! ни из документа, ни из учебника
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

template<typename Type>
Vector<Type>::Vector(initializer_list<Type> args)
{
    time_t t = time(nullptr);

    if (!args.size())
        Vector();

    num_elem = int(args.size());
    allocate_memory(num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__,
                          ctime(&t));

    int i = 0;
    for (Type arg : args)
    {
        list_elem[i] = arg;
        i++;
    }
}

#endif // VECTOR_H
