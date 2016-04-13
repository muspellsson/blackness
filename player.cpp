#include "player.hpp"

Player::Player()
{
	this->x = 0;
	this->y = 0;
	this->hp = 0;
	this->sp = 0;
}

void Player::PutAt(uint32_t x, uint32_t y)
{
	this->x = x;
	this->y = y;
}