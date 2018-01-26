#include "faculty.h"


std::string Faculty::getName() const
{
    return name;
}

std::vector<Department> Faculty::getDeps() const
{
    return deps;
}

