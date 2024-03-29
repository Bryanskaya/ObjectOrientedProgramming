#include "base_vector.h"

BaseVector::BaseVector()
{
    num_elem = shared_ptr<size_t>(new size_t(0));
}

BaseVector::BaseVector(const BaseVector& base)
{
    num_elem = base.num_elem;
}

BaseVector::~BaseVector()
{
}

size_t BaseVector::get_size() const
{
    return *num_elem;
}

bool BaseVector::is_empty() const
{
    if (!*num_elem)
        return true;

    return false;
}
