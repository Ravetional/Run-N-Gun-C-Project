#include "Enemy.h"

void Enemy::initVariables()
{
	this->type = 0;
	this->speed = 2.f;
	this->hpMax = 10;
	this->hp = hpMax;
	this->damage = 1;
	this->points = 5;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Enemy::initAnimations()
{
	this->animationTimer.restart();
}

Enemy::Enemy(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	this->currentFrame = sf::IntRect(0, 0, 40, 50);
	if (pos_y == 6)
		pos_y = 210;
	this->shape.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initAnimations();

	//Resize the sprite.
	this->shape.setTextureRect(this->currentFrame);
	this->shape.scale(-3.f, 3.f);
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int Enemy::getHp() const
{
	return this->hp;
}

void Enemy::hit()
{
	this->hp -= this->damage;
}

void Enemy::updateAnimations()
{

	/*
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
	{
		this->currentFrame.top = 50.f;
		this->currentFrame.left += 40.f;
		if (this->currentFrame.left >= 360.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->shape.setTextureRect(this->currentFrame);
	}
	this->shape.setScale(-3.f, 3.f);
	this->shape.setOrigin(this->getBounds().width / 3.f, 0.f);
	*/
}

const bool Enemy::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Enemy::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.05f;
}

void Enemy::update()
{
	//this->shape.move(-(this->speed), 0);
	//this->updateAnimations();
	this->updateAttack();
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}