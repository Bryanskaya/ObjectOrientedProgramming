#ifndef BASEVECTOR_H
#define BASEVECTOR_H

class BaseVector
{
protected:
    int num_elem = 0;

public:
    BaseVector();
    ~BaseVector();
    /* как задать с числом? просто num_elem = num?
     */

    int get_size();
    bool is_empty();
};

#endif // BASEVECTOR_H
