#include "basevector.h"

BaseVector::BaseVector()
{
    num_elem = shared_ptr<size_t>(new size_t(0));
}

// зачем оно
BaseVector::BaseVector(const BaseVector& base)
{
    num_elem = base.num_elem;
}

BaseVector::~BaseVector()
{
}

size_t BaseVector::get_size()
{
    return *num_elem;
}

bool BaseVector::is_empty()
{
    return !num_elem;
}
