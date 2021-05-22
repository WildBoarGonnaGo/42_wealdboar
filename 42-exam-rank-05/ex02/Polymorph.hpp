#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP
# include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        Polymorph(const Polymorph &rhs);
        virtual ~Polymorph();

        Polymorph  &operator=(const Polymorph &rhs);
        virtual ASpell  *clone() const;
};

#endif