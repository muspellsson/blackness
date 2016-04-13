#include "player.hpp"

Player::Player() :
	x(0), y(0), hp(0), sp(0)
{
}

void Player::PutAt(uint32_t nx, uint32_t ny)
{
	this->x = nx;
	this->y = ny;
}