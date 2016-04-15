#include "player.hpp"

Player::Player() :
	x(0), y(0), hp(0), sp(0)
{
}

void Player::PutAt(int32_t nx, int32_t ny)
{
	this->x = nx;
	this->y = ny;
}