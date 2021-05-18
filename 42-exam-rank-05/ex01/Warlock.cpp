#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock( ) { }

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title),
	_spell(NULL)
{
	std::cout << this->_name << ": This looks like another boring day."
		<< std::endl;
}

Warlock::Warlock(Warlock const &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

Warlock				&Warlock::operator=(Warlock const &rhs)
{
    this->_name = rhs.getName();
    this->_title = rhs.getTitle();
    return (*this);
}

void				Warlock::setTitle(std::string const &title)
{
    this->_title = title;
}

std::string	const	&Warlock::getTitle() const
{
	return (this->_title);
}

std::string	const	&Warlock::getName() const
{
	return (this->_name);
}

void				Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name 
		<< ", " << this->_title << '!' << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!"
		<< std::endl;
}

void				Warlock::learnSpell(ASpell *spell)
{
	this->_spell = spell;
}

void				Warlock::forgetSpell(std::string name)
{
	if (!this->_spell || this->_spell->getName().compare(name))
		return ;
	this->_spell = NULL;
}

void				Warlock::launchSpell(std::string name, ATarget &target)
{
	if (!this->_spell || this->_spell->getName().compare(name))
		return ;
	std::cout << target.getType() << " has been " << this->_spell->getEffects()
		<< '!' << std::endl;
}