#include <iostream>

#include "vector.h"

int main()
{
    try
    {
        cout << "Testing" << endl;

        Vector<int> v1(1);
        Vector<int> v2{-5, 1, 2};
        v2.my_print();




    }
    catch (BaseError& error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
