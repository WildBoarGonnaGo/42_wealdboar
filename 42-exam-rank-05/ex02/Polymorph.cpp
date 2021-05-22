#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") { }

Polymorph::Polymorph(const Polymorph &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

Polymorph  &Polymorph::operator=(const Polymorph &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Polymorph::~Polymorph( ) { }

ASpell  *Polymorph::clone() const
{
    return (new Polymorph());
}