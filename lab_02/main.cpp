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
        double arr[3] = {-5.5, 10, 8.72};
        Vector<double> v13(3, arr);
        Vector<double> v14{0, 5, 0};
        Vector<int> v15{-1, -2};
        Vector<int> v16{2, 4};
        Vector<double> v17{10, 5, 55, -12.56, -9};


        cout << "Length v2" << v2 << ", v3" << v3 << ": "
             << v2.get_length() << ' ' << v3.get_length() << endl << endl << endl;

        cout << "v4" << v4 << " v4[0], v4[2], v4[4]: " << ' '
             << v4[0] << ' ' << v4[2] << ' ' << v4[4] << endl << endl << endl;

        cout << "Equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 == v5 ? "True" : "False") << endl << endl;
        cout << "Equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 == move(v5) ? "True" : "False") << endl << endl;
        cout << "Equal v2" << v2 << " and v6" << v6 << ": "
             << (v2.is_equal(v6) ? "True" : "False") << endl << endl;
        cout << "Equal v2" << v2 << " and (14, 2, -8): "
             << (v2.is_equal({14, 2, -8}) ? "True" : "False") << endl << endl;
        cout << "Equal v2" << v2 << " and v6" << v6 << ": "
             << (v2.is_equal(move(v6)) ? "True" : "False") << endl << endl << endl;

        cout << "Not equal v3" << v3 << " and v8" << v8 << ": "
             << (v3 != v8 ? "True" : "False") << endl << endl;
        cout << "Not equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 != v5 ? "True" : "False") << endl << endl;
        cout << "Not equal v4" << v4 << " and v5" << v5 << ": "
             << (v4 != move(v5) ? "True" : "False") << endl << endl;
        cout << "Not equal v4" << v4 << " and v17" << v17 << ": "
             << (v4.isnt_equal(v17) ? "True" : "False") << endl << endl;
        cout << "Not equal v4" << v4 << " and {100, 2.36, 0, 56, -1.02}: "
             << (v4.isnt_equal({100, 2.36, 0, 56, -1.02}) ? "True" : "False") << endl << endl;
        cout << "Not equal v8" << v8 << " and v3" << v3 << ": "
             << (v8.isnt_equal(move(v3)) ? "True" : "False") << endl << endl << endl;

        cout << "v9{14, 2, -8} v2{-5, 1, 2} v9 = v2 v9: " << (v9 = v2) << endl << endl;
        cout << "v1 = ()" << v1 << " v1 = {1, -5, 3, 4} v1 = " << (v1 = {1, -5, 3, 4}) << endl << endl;
        cout << "v3 = " << v3 << " v8 = " << v8 << " v3 = v8 v3 = " << (v3 = move(v8)) << endl << endl<< endl;

        cout << v2 << " plus " << v6 << ": " << (v2 += v6) << endl << endl;
        cout << v2 << " plus " << v6 << ": " << (v1 = v2 + v6) << endl << endl;
        cout << v2 << " plus {1, 10, -8}: " << (v2 += {1, 10, -8}) << endl << endl;
        cout << v9 << " plus " << v10 << ": " << (v9 += move(v10)) << endl << endl;
        cout << v13 << " plus " << v14 << ": ";
        v13 = v13 + move(v14);
        cout << v13 << endl << endl;
        cout << v2 << " plus " << v10 << ": ";
        v2.add(v10);
        cout << v2 << endl << endl;
        cout << v2 << " plus {12, -3, 0}: ";
        v2.add({12, -3, 0});
        cout << v2 << endl << endl;
        cout << v2 << " plus " << v12 << ": ";
        v2.add(move(v12));
        cout << v2 << endl << endl;

        cout << v10 << " plus " << v11 << ": " << (v10 + v11) << endl << endl;
        cout << v10 << " plus " << v11 << ": " << (sum_vect(v10, v11)) << endl << endl;
        cout << v10 << " plus {-5 5 -5}: " << (sum_vect(v10, {-5, 5, -5})) << endl << endl << endl;

        cout << v1 << " minus " << v6 << ": " << (v1 -= v6) << endl << endl;
        cout << v8 << " minus " << v3 << ": " << (v8 = v8 - v3) << endl << endl;
        cout << v2 << " minus {7, 0, -2}: " << (v2 -= {7, 0, -2}) << endl << endl;
        cout << v9 << " minus " << v10 << ": " << (v9 -= move(v10)) << endl << endl;
        cout << v13 << " minus " << v14 << ": ";
        v13 = v13 - move(v14);
        cout << v13 << endl << endl;
        cout << v2 << " minus " << v9 << ": ";
        v2.sub(v9);
        cout << v2 << endl << endl;
        cout << v2 << " minus {0, -2, 2}: ";
        v2.sub({0, -2, 2});
        cout << v2 << endl << endl;
        cout << -v5 << endl << endl;
        cout << v2 << " minus " << v6 << ": ";
        v2.sub(move(v6));
        cout << v2 << endl << endl;
        cout << v10 << " minus " << v11 << ": " << (diff_vect(v10, v11)) << endl << endl;
        cout << v10 << " minus {-5 5 -5}: " << (diff_vect(v10, {-5, 5, -5})) << endl << endl << endl;

        cout << v7 << " * 2: " << (v7 *= 2) << endl << endl;
        cout << v4 << " * -1: " << (v4 *= -1) << endl << endl;
        cout << v6 << " * 6: " << (v6 = v6 * 6) << endl << endl << endl;

        cout << v7 << " / 2: " << (v7 /= 2) << endl << endl;
        cout << v4 << " / -1: " << (v4 /= -1) << endl << endl;
        cout << v6 << " / 6: " << (v6 = v6 / 6) << endl << endl << endl;

        cout << v10 << " * " << v11 << ": " << (v10 * v11) << endl << endl;
        cout << v10 << " * " << v9 << ": " << (v10 * v9) << endl << endl << endl;
        cout << v10 << " * " << v9 << ": " << (v10 * move(v9)) << endl << endl << endl;

        cout << "Scalar mult " << v10 << " and " << v11 << ": " << (v10.scalar_mult(v11)) << endl << endl;
        cout << "Scalar mult " << v10 << " and " << v9 << ": " << (v10.scalar_mult(v9)) << endl << endl;
        cout << "Scalar mult " << v10 << " and {9, 1, -2}: " << (v10.scalar_mult({9, 1, -2})) << endl << endl;
        cout << "Scalar mult " << v6 << " and " << v9 << ": " << (v6.scalar_mult(move(v9))) << endl << endl << endl;

        cout << "Vect mult " << v10 << " and " << v11 << ": " << (v10.vector_mult(v11)) << endl << endl;
        cout << "Vect mult " << v10 << " and " << v12 << ": " << (v10.vector_mult(v12)) << endl << endl;
        cout << "Vect mult " << v10 << " and {9, 1, -2}: " << (v10.vector_mult({9, 1, -2})) << endl << endl << endl;
        cout << "Vect mult " << v10 << " and " << v9 << ": " << (v10.vector_mult(move(v9))) << endl << endl << endl;

        cout << "Angle between " << v10 << " and " << v11 << ": " << v10.angle(v11) << " rad" << endl << endl;
        cout << "Angle between " << v10 << " and " << v12 << ": " << v10.angle(v12) << " rad" << endl << endl << endl;

        cout << "Set elem 100 in pos = 2 in " << v7 << ": ";
        v7.set_elem(2, 100);
        cout << v7 << endl << endl;
        cout << "Set elem -5.78 in pos = 0 in " << v4 << ": ";
        v4.set_elem(0, -5.78);
        cout << v4 << endl << endl << endl;

        cout << "v" << v2 << " -v: ";
        v2.make_negative();
        cout << v2 << endl << endl;
        cout << "v" << v3 << " -v: " ;
        v3.make_negative();
        cout << v3 << endl << endl << endl;
        cout << "v" << v5 << " -v: " << -v5 << endl << endl << endl;

        cout << v13 << endl << endl << endl;

        cout << "Normalize vector " << v14 << ": ";
        v14.normalize();
        cout << v14 << endl << endl << endl;

        cout <<"Is collinear " << v15 << " and " << v16 << ": "
            << (v15.is_collinear(v16) ? "True" : "False") << endl << endl;
        cout <<"Is collinear " << v14 << " and " << v13 << ": "
            << (v14.is_collinear(v13) ? "True" : "False") << endl << endl << endl;

        cout <<"Is orthogonal " << v15 << " and " << v16 << ": "
            << (v15.is_orthogonal(v16) ? "True" : "False") << endl << endl;
        cout <<"Is orthogonal " << v10 << " and " << v11 << ": "
            << (v10.is_orthogonal(v11) ? "True" : "False") << endl << endl << endl;
    }
    catch (VectorError& error)
    {
        cout << error.what() << endl;
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }

    return 0;
}
