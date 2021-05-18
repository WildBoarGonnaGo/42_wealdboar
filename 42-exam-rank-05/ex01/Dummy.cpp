#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") { }

Dummy::Dummy(const Dummy &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

Dummy  	&Dummy::operator=(const Dummy &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Dummy::~Dummy( ) { }

ATarget  *Dummy::clone() const
{
    return (new Dummy());
}