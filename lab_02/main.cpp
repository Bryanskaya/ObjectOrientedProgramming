#include <iostream>

#include "my_errors.h"
//#include "vector.h"

using namespace std;

int main()
{
    try
    {
        cout << "Testing" << endl;

        int *p = new int[0];
        cout << p;
        /*Vector<int> v1;
        Vector<float> v2(-2.0, 1.2, 3.56, -5.5);

        cout << ""*/
    }
    catch (BaseError& error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
