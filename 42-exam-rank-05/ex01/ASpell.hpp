#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <string>
class ATarget;
# include "ATarget.hpp"

class ASpell
{
    protected:
        std::string	_name;
        std::string	_effects;
    public:
		ASpell();
		ASpell(ASpell const &rhs);
        ASpell(std::string name, std::string effects);
		virtual ~ASpell();

        ASpell				&operator=(ASpell const &rhs);
		std::string	const	&getName() const;
		std::string	const	&getEffects() const;
		virtual ASpell		*clone() const = 0;
		void				launch(ATarget const &rhs);
};

#endif