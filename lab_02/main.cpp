#include <iostream>

#include "vector.h"

int main()
{
    try
    {
        cout << "Testing" << endl;

        Vector<int> v1{1, 2, 3};




    }
    catch (BaseError& error)
    {
        //cout << error.what() << endl;
    }

    return 0;
}
