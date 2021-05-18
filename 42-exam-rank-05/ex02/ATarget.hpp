#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <string>
class ASpell;
#include "ASpell.hpp"

class ATarget
{
    protected:
        std::string	_type;
    public:
		ATarget();
		ATarget(ATarget const &rhs);
        ATarget(std::string type);
		virtual ~ATarget();

        ATarget			    &operator=(ATarget const &rhs);
		std::string	const   &getType() const;
		virtual ATarget	    *clone() const = 0;
        void				getHitBySpell(ASpell const &rhs) const;
};

#endif