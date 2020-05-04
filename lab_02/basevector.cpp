#include "basevector.h"

BaseVector::BaseVector()
{
    num_elem = 0;
}

// зачем оно
BaseVector::BaseVector(const BaseVector& base)
{
    num_elem = base.num_elem;
}

BaseVector::~BaseVector()
{
    num_elem = 0;
}

int BaseVector::get_size()
{
    return num_elem;
}

bool BaseVector::is_empty()
{
    return !num_elem;
}
