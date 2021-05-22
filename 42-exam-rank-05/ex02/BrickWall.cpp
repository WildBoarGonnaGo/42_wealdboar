#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") { }

BrickWall::BrickWall(const BrickWall &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

BrickWall  	&BrickWall::operator=(const BrickWall &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

BrickWall::~BrickWall( ) { }

ATarget  *BrickWall::clone() const
{
    return (new BrickWall());
}