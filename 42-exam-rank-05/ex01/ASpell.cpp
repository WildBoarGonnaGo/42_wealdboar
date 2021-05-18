#include "ASpell.hpp"

ASpell::ASpell( ) { }

ASpell::ASpell(std::string name, std::string effects) :
	_name(name), _effects(effects) { }

ASpell::ASpell(ASpell const &rhs) 
{
	if (this != &rhs)
		*this = rhs;
}

ASpell		&ASpell::operator=(ASpell const &rhs)
{
	this->_name = rhs.getName();
	this->_effects = rhs.getEffects();
	return (*this);
}

std::string const	&ASpell::getName() const
{
	return (this->_name);
}

std::string const	&ASpell::getEffects() const
{
	return (this->_effects);
}

void				ASpell::launch(ATarget const &rhs)
{
	rhs.getHitBySpell(*this);
}

ASpell::~ASpell( ) { }