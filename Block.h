#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block
{
private:
	sf::Sprite shape;

public:
	Block(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~Block();

	const sf::FloatRect getBounds();

	void update();
	void render(sf::RenderTarget* target);
};

#endif