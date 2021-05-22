#ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        Fireball(const Fireball &rhs);
        virtual ~Fireball();

        Fireball  &operator=(const Fireball &rhs);
        virtual ASpell  *clone() const;
};

#endif