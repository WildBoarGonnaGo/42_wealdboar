#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP
class ASpell;
#include "ASpell.hpp"
#include <vector>

typedef unsigned long	uint64;

class SpellBook 
{
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell);
		ASpell	*createSpell(std::string const &spell);
	private:
		SpellBook(SpellBook const &rhs);
		SpellBook	&operator=(SpellBook const &rhs);
		std::vector<ASpell *>	book;

};

#endif