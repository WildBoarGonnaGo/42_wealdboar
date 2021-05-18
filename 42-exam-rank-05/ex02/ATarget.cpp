#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget( ) { }

ATarget::ATarget(std::string type) :
	_type(type) { }

ATarget::ATarget(ATarget const &rhs) 
{
	if (this != &rhs)
		*this = rhs;
}

ATarget		&ATarget::operator=(ATarget const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

std::string const	&ATarget::getType() const
{
	return (this->_type);
}

void                ATarget::getHitBySpell(ASpell const &rhs) const
{
	std::cout << this->_type << " has been " << rhs.getEffects()
        << '!' << std::endl;
}

ATarget::~ATarget( ) { }