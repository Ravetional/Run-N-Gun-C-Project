#include "Block.h"

Block::Block(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	if (pos_y == 6)
		pos_y = 234;
	else if (pos_y == 5)
		pos_y = 336;
	else if (pos_y == 4)
		pos_y = 438;
	else if (pos_y == 3)
		pos_y = 490;
	else if (pos_y == 2)
		pos_y = 541;
	else if (pos_y == 1)
		pos_y = 643;
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(3.2f, 3.2f);
}

Block::~Block()
{

}

const sf::FloatRect Block::getBounds()
{
	return this->shape.getGlobalBounds();
}

void Block::update()
{
	
}

void Block::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
