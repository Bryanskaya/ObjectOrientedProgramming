#include <iostream>

#include "vector.h"

int main()
{
    try
    {
        cout << "\tTesting" << endl << endl;

        Vector<int> v1;
        Vector<int> v2{-5, 1, 2};
        Vector<float> v3{-2.5};
        Vector<double> v4{-9, 2.36, 0, 56, -1.02};
        Vector<double> v5{-9, 2.36, 0, 56, -1.02};
        Vector<int> v6{-5, 1, -2};
        //v2.my_print();

        cout << "Length v2{-5, 1, 2}, v3{-2.5}: " << v2.get_length() << ' '
             << v3.get_length() << endl << endl;
        cout << "v4{-9, 2.36, 0, 56, -1.02} v4[0], v4[2], v4[4]: " << ' '
             << v4.get_elem(0) << ' ' << v4.get_elem(2) << ' '
             << v4.get_elem(4) << endl << endl;
        cout << "v4{-9, 2.36, 0, 56, -1.02} v4[0], v4[2], v4[4]: " << ' '
             << v4[0] << ' ' << v4[2] << ' ' << v4[4] << endl << endl;
        cout << "First elements in v2{-5, 1, 2}, v3{-2.5}: " << v2.get_first_elem()
             << ' ' << v3.get_first_elem() << endl << endl;
        cout << "Last elements in v2{-5, 1, 2}, v3{-2.5}: " << v2.get_last_elem()
             << ' ' << v3.get_last_elem() << endl << endl;
        cout << "Equal v4{-9, 2.36, 0, 56, -1.02} and v5{-9, 2.36, 0, 56, -1.02}: "
             << (v4 == v5 ? "Yes" : "No") << endl;
        cout << "Equal v2{-5, 1, 2} and v6{-5, 1, -2}: "
             << (v2 == v6 ? "Yes" : "No") << endl;
        /*cout << "{-5, 1, 2} plus {-5, 1, -2}: " << (v2+=v6) << endl;
        cout << "{-5, 1, 2} plus {-5, 1, -2}: " << (v2+v6) << endl;
        cout << "{-5, 1, 2} minus {-5, 1, -2}: " << (v2-=v6) << endl;
        cout << "{-5, 1, 2} minus {-5, 1, -2}: " << (v2-v6) << endl;
*/







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
