#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") { }

Fireball::Fireball(const Fireball &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

Fireball  &Fireball::operator=(const Fireball &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Fireball::~Fireball( ) { }

ASpell  *Fireball::clone() const
{
    return (new Fireball());
}