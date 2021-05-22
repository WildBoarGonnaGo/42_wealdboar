#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

SpellBook::~SpellBook()
{
	if (this->book.size())
	{
		for (uint64 i = 0; i < this->book.size(); ++i)
			delete *(this->book.begin() + i);
	}
	this->book.clear();
}

SpellBook	&SpellBook::operator=(SpellBook const &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void		SpellBook::learnSpell(ASpell *spell)
{
	std::vector<ASpell *>::const_iterator	cit;
	
	for (cit = this->book.begin(); cit != book.end(); ++cit)
	{
		if ((*cit)->getName() == spell->getName())
			return ;
	}
	this->book.push_back(spell->clone());
}

void		SpellBook::forgetSpell(std::string const &spell)
{
	for (uint64 i = 0; i < this->book.size(); ++i)
	{
		if (!this->book[i]->getName().compare(spell))
		{
			delete *(this->book.begin() + i);
			this->book.erase(this->book.begin() + i);
			return ;
		}
	}
}

ASpell		*SpellBook::createSpell(std::string const &spell)
{
	for (uint64 i = 0; i < this->book.size(); ++i)
	{
		if (!this->book[i]->getName().compare(spell))
			return (*(this->book.begin() + i));
	}
	return (NULL);
}