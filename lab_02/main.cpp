#include <iostream>

#include "vector.h"

int main()
{
    try
    {
        cout << "\tTesting" << endl << endl;

        Vector<int> v1;
        Vector<int> v2{-5, 1, 2};
        Vector<double> v3{-2.5};
        Vector<double> v4{-9, 2.36, 0, 56, -1.02};
        Vector<double> v5{-9, 2.36, 0, 56, -1.02};
        Vector<int> v6{-5, 1, -2};
        Vector<int> v7{-2, 0, 12, 1};
        Vector<double> v8{9.7};
        Vector<int> v9{14, 2, -8};

        cout << "Length v2" << v2 << ", v3" << v3 << ": "
             << v2.get_length() << ' ' << v3.get_length() << endl << endl << endl;
        cout << "v4" << v4 << " v4[0], v4[2], v4[4]: " << ' '
             << v4.get_elem(0) << ' ' << v4.get_elem(2) << ' '
             << v4.get_elem(4) << endl << endl;
        cout << "v4" << v4 << " v4[0], v4[2], v4[4]: " << ' '
             << v4[0] << ' ' << v4[2] << ' ' << v4[4] << endl << endl << endl;

        cout << "First elements in v2" << v2 << ", v3" << v3 << ": "
             << v2.get_first_elem() << ' ' << v3.get_first_elem() << endl << endl;
        cout << "Last elements in v2" << v2 << ", v3" << v3 << ": "
             << v2.get_last_elem() << ' ' << v3.get_last_elem() << endl << endl << endl;

        cout << "Equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 == v5 ? "True" : "False") << endl << endl;
        cout << "Equal v2" << v2 << " and v6" << v6 << ": "
             << (v2 == v6 ? "True" : "False") << endl << endl;
        cout << "Not equal v3" << v3 << " and v8" << v8 << ": "
             << (v3 != v8 ? "True" : "False") << endl << endl;
        cout << "Not equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 != v5 ? "True" : "False") << endl << endl << endl;

        cout << "v9{14, 2, -8} v2{-5, 1, 2} v9 = v2 v9: " << (v9 = v2) << endl << endl << endl;

        cout << v2 << " plus " << v6 << ": " << (v2 += v6) << endl << endl;
        cout << v2 << " plus " << v6 << ": " << (v1 = v2 + v6) << endl << endl << endl;

        cout << v1 << " minus " << v6 << ": " << (v1 -= v6) << endl << endl;
        cout << v8 << " minus " << v3 << ": " << (v8 = v8 - v3) << endl << endl << endl;

        cout << v7 << " * 2: " << (v7 *= 2) << endl << endl;
        cout << v4 << " * -1: " << (v4 *= -1) << endl << endl;
        cout << v6 << " * 6: " << (v6 = v6 * 6) << endl << endl << endl;

        cout << v7 << " / 2: " << (v7 /= 2) << endl << endl;
        cout << v4 << " / -1: " << (v4 /= -1) << endl << endl;
        cout << v6 << " / 6: " << (v6 = v6 / 6) << endl << endl << endl;

        // вставка элемента




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
