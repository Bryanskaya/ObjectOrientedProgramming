#include <iostream>

#include "my_errors.h"

using namespace std;

int main()
{
    try
    {
        cout << "Testing" << endl;
    }
    catch (BaseError& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << 10;
    }

    return 0;
}
