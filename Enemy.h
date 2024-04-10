#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Sprite shape;
	sf::Clock animationTimer;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	//Animation
	sf::IntRect currentFrame;
	
	//Attack
	float attackCooldown;
	float attackCooldownMax;

	void initVariables();
	void initAnimations();

public:
	Enemy(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~Enemy();

	const sf::FloatRect getBounds() const;
	const int getHp() const;


	void hit();
	void updateAnimations();
	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget* target);
};

#endif