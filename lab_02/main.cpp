#include <iostream>

#include "vector.h"

int main()
{
    try
    {
        cout << "Testing" << endl;

        Vector<int> v1;
        Vector<int> v2{-5, 1, 2};
        Vector<float> v3{-2.5};
        //v2.my_print();

        cout << "Length  v1{}, v2{-5, 1, 2}, v3{-2.5}: " << v1.get_length() << ' ' <<
                v2.get_length() << ' ' << v3.get_length();




    }
    catch (BaseError& error)
    {
        cout << error.what() << endl;
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }

    return 0;
}
