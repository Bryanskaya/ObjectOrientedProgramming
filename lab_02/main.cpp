#include <iostream>

#include "my_errors.h"

using namespace std;

int main()
{
    float a;
    try
    {
        a = 5 / 0;
        //cout << "Hello World!";
    }
    catch (BaseError& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << 10;
    }
    cout << a;

    return 0;
}
