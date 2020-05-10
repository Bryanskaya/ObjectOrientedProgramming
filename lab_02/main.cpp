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
        Vector<int> v10{5, 0, 0};
        Vector<int> v11{0, 5, 0};
        Vector<int> v12{-7, 0, 0};



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

        cout << "v9{14, 2, -8} v2{-5, 1, 2} v9 = v2 v9: " << (v9 = v2) << endl << endl;
        cout << (v1 = {1, -5, 3, 4}) << endl << endl << endl;

        cout << v2 << " plus " << v6 << ": " << (v2 += v6) << endl << endl;
        cout << v2 << " plus " << v6 << ": " << (v1 = v2 + v6) << endl << endl;
        cout << v2 << " plus {1, 10, -8}: " << (v2 += {1, 10, -8}) << endl << endl << endl;

        cout << v1 << " minus " << v6 << ": " << (v1 -= v6) << endl << endl;
        cout << v8 << " minus " << v3 << ": " << (v8 = v8 - v3) << endl << endl;
        cout << v2 << " minus {7, 0, -2}: " << (v2 -= {7, 0, -2}) << endl << endl << endl;

        cout << v7 << " * 2: " << (v7 *= 2) << endl << endl;
        cout << v4 << " * -1: " << (v4 *= -1) << endl << endl;
        cout << v6 << " * 6: " << (v6 = v6 * 6) << endl << endl << endl;

        cout << v7 << " / 2: " << (v7 /= 2) << endl << endl;
        cout << v4 << " / -1: " << (v4 /= -1) << endl << endl;
        cout << v6 << " / 6: " << (v6 = v6 / 6) << endl << endl << endl;

        cout << v10 << " * " << v11 << ": " << (v10 * v11) << endl << endl;
        cout << v10 << " * " << v9 << ": " << (v10 * v9) << endl << endl << endl;

        cout << "Scalar mult " << v10 << " and " << v11 << ": " << (v10.scalar_mul(v11)) << endl << endl;
        cout << "Scalar mult " << v10 << " and " << v9 << ": " << (v10.scalar_mul(v9)) << endl << endl;
        cout << "Vect mult " << v10 << " and " << v11 << ": " << (v10.vector_mul(v11)) << endl << endl;
        cout << "Vect mult " << v10 << " and " << v12 << ": " << (v10.vector_mul(v12)) << endl << endl << endl;

        cout << "Angle between " << v10 << " and " << v11 << ": " << v10.angle(v11) << " rad" << endl << endl;
        cout << "Angle between " << v10 << " and " << v12 << ": " << v10.angle(v12) << " rad" << endl << endl;


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
