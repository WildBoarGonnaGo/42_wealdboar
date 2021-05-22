#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP
# include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        BrickWall(const BrickWall &rhs);
        virtual ~BrickWall();

        BrickWall           &operator=(const BrickWall &rhs);
        virtual ATarget *clone() const;
};

#endif