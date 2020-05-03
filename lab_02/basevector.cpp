#include "basevector.h"

BaseVector::BaseVector()
{
    num_elem = 0;
}

BaseVector::~BaseVector()
{
    num_elem = 0;
    // а как насчет освобождения памяти?
}

int BaseVector::get_size()
{
    return num_elem;
}

bool BaseVector::is_empty()
{
    return !num_elem;
}
