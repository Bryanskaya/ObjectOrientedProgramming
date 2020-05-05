#include "vector.h"

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

/*template<typename Type>
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

    for (int i = 0; i < num_elem; i++)
    {
        list_elem[i] = args[i];
    }
}*/

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
void Vector<Type>::my_print()
{
    cout << endl;
    for (int i = 0; i < num_elem; i++)
    {
        cout << list_elem[i] << ' ';
    }
}
