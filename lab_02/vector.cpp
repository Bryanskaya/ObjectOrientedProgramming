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
    if (num_elem <= 0)
        throw ErrorSize(__FILE__, typeid (*this).name(), __LINE__,
                        ctime(&time), num);
    num_elem = num;


}

template<typename Type>
Vector<Type>::allocate_memory(int num)
{
    shared_ptr<Type> ptr_temp(new Type[num], default_delete<Type[]>());
    if (!ptr_temp)
        throw ErrorMemory(__FILE__, typeid (*this).name(), __LINE__,
                          ctime(&time));
    list_elem.reset();
    list_elem = ptr_temp;
}

template<typename Type>
Vector<Type>::~Vector<Type>()
{
    if (list_elem)
        list_elem.reset();
}
