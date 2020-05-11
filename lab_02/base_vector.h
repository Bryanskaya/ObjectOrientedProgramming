#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <iostream>
#include <memory>

using namespace std;

class BaseVector
{
public:
    BaseVector();
    explicit BaseVector(const BaseVector& base);
    virtual ~BaseVector() = 0;

    size_t get_size();
    size_t get_size() const;

    bool is_empty();
    bool is_empty() const;

protected:
    shared_ptr<size_t> num_elem;
};

#endif // BASEVECTOR_H
