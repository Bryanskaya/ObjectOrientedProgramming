#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <iostream>
#include <memory>

using namespace std;

class BaseVector
{
protected:
    shared_ptr<size_t> num_elem;

public:
    BaseVector();
    BaseVector(const BaseVector&); // разобраться
    ~BaseVector();

    size_t get_size();
    bool is_empty();
};

#endif // BASEVECTOR_H
