#ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        Fwoosh(const Fwoosh &rhs);
        virtual ~Fwoosh();

        Fwoosh  &operator=(const Fwoosh &rhs);
        virtual ASpell  *clone() const;
};

#endif