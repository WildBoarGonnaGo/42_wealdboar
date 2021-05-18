#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") { }

Fwoosh::Fwoosh(const Fwoosh &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

Fwoosh  &Fwoosh::operator=(const Fwoosh &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Fwoosh::~Fwoosh( ) { }

ASpell  *Fwoosh::clone() const
{
    return (new Fwoosh());
}

