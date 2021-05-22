#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

TargetGenerator::~TargetGenerator()
{
	if (this->generator.size())
	{
		for (uint64 i = 0; i < this->generator.size(); ++i)
			delete *(this->generator.begin() + i);
	}
	this->generator.clear();
}

TargetGenerator	&TargetGenerator::operator=(TargetGenerator const &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void		TargetGenerator::learnTargetType(ATarget *target)
{
	std::vector<ATarget *>::const_iterator	cit;
	
	for (cit = this->generator.begin(); cit != generator.end(); ++cit)
	{
		if ((*cit)->getType() == target->getType())
			return ;
	}
	this->generator.push_back(target->clone());
}

void		TargetGenerator::forgetTargetType(std::string const &target)
{
	for (uint64 i = 0; i < this->generator.size(); ++i)
	{
		if (!this->generator[i]->getType().compare(target))
		{
			delete *(this->generator.begin() + i);
			this->generator.erase(this->generator.begin() + i);
			return ;
		}
	}
}

ATarget		*TargetGenerator::createTarget(std::string const &spell)
{
	for (uint64 i = 0; i < this->generator.size(); ++i)
	{
		if (!this->generator[i]->getType().compare(spell))
			return (*(this->generator.begin() + i));
	}
	return (NULL);
}