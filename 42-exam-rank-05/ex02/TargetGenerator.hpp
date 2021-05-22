#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
class ATarget;
#include "ATarget.hpp"
#include <vector>

typedef unsigned long	uint64;

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
	
		void			learnTargetType(ATarget	*target);
		void 			forgetTargetType(std::string const &type);
		ATarget			*createTarget(std::string const &type);
	private:
		TargetGenerator(TargetGenerator const &target);

		TargetGenerator	&operator=(TargetGenerator const &target);
		std::vector<ATarget *>	generator;
};

#endif