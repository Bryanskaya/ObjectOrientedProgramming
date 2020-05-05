#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <iostream>

class BaseVector
{
protected:
    int num_elem = 0;

public:
    BaseVector();
    BaseVector(const BaseVector&); // разобраться
    ~BaseVector();

    int get_size();
    bool is_empty();
};

#endif // BASEVECTOR_H
