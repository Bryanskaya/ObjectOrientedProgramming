#include "vector.h"
#include "my_errors.h"


using namespace std;

template<typename Type>
Vector<Type>::Vector()
{
    num_elem = 0;
    list_elem = nullptr;
}

template<typename Type>
Vector<Type>::Vector(int num)
{
    time_t t = time(nullptr);

    if (num <= 0)
        throw ErrorSize(__FILE__, typeid (*this).name(), __LINE__,
                        ctime(&t), num);
    num_elem = num;
    allocate_memory(num_elem);

    if (!list_elem)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__,
                          ctime(&t));

    // что-то с итератором, пока не поняла что и зачем
}

template<typename Type>
void Vector<Type>::allocate_memory(int num)
{
    time_t t = time(nullptr);

    shared_ptr<Type> ptr_temp(new Type[num], default_delete<Type[]>());
    if (!ptr_temp)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__,
                          ctime(&t));
    list_elem.reset();
    list_elem = ptr_temp;
}

template<typename Type>
Vector<Type>::~Vector<Type>()
{
    if (list_elem)
        list_elem.reset();
}
