#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock animationTimer;

	//Animation
	short animState;
	sf::IntRect currentFrame;

	//Movement
	float movementSpeed;
	float jumpSpeed;
	bool jumpState;
	bool jumpPhaseOne;
	bool jumpPhaseTwo;
	bool fallState;
	float initialYSpeed;

	//Stats
	int ammo;
	int points;
	int lifes;
	sf::String ammoString;
	sf::String pointsString;
	sf::String lifesString;
	sf::Font textFont;
	sf::Text ammoState;
	sf::Text pointsState;
	sf::Text lifesState;
	sf::String ammoRemained;
	sf::String overallAmmo;
	sf::String pointsEarned;
	sf::String overallPoints;
	sf::String lifesReamined;
	sf::String overallLifes;
	sf::Font font;
	int score;

	//Attack
	float attackCooldown;
	float attackCooldownMax;

	//Core
	void initVariables();
	void initStats();
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Player();
	virtual ~Player();

	//Accessor
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getPos() const;
	const sf::Vector2f getSpriteScale() const;

	//Stats
	void addAmmo(int addBullets);
	int getAmmo();
	void subtractLife();
	int getLifes();
	int getPoints();
	void addPoints(int pointsToAdd);

	void move(const float dirX, const float dirY);
	void updateMovement(bool intersectBlock);
	void updateAnimations();
	const bool canAttack();
	void updateAttack();
	void updateStats(float pos_x);
	void update(bool intersectBlock, float pos_x);
	void render(sf::RenderTarget& target);
	void setAmmo(int newAmmo);
	void setPoints(int newPoints);
	void setLifes(int newLifes);
	void setPos(sf::Vector2f coords);
};

#endif