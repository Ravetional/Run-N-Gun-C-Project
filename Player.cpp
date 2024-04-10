#include "Player.h"
#include "Game.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->movementSpeed = 2.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->jumpSpeed = 5.f;
	this->jumpState = false;
	this->jumpPhaseOne = false;
	this->jumpPhaseTwo = false;
	this->initialYSpeed = 1.f;
	this->ammo = 40;
	this->points = 0;
	this->lifes = 10;
	this->fallState = false;
}

void Player::initStats()
{
	ammoString = "Ammo: ";
	pointsString = "Points: ";
	lifesString = "Lifes: ";
	textFont.loadFromFile("Fonts/SuperMario256.ttf");
	ammoState.setCharacterSize(25);
	ammoState.setFillColor(sf::Color::White);
	ammoState.setFont(textFont);
	ammoState.setPosition(0, 0);
	pointsState.setCharacterSize(25);
	pointsState.setFillColor(sf::Color::White);
	pointsState.setFont(textFont);
	pointsState.setPosition(0, 30);
	lifesState.setCharacterSize(25);
	lifesState.setFillColor(sf::Color::White);
	lifesState.setFont(textFont);
	lifesState.setPosition(0, 60);
}

void Player::initTexture()
{
	// Load a texture from file.
	if (!this->texture.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite.
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 40, 50);
	this->sprite.setPosition(200.f, 200.f);

	//Resize the sprite.
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(3.f, 3.f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initStats();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{

}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::Vector2f Player::getSpriteScale() const
{
	return this->sprite.getScale();
}

void Player::addAmmo(int addBullets)
{
	ammo += addBullets;
}

int Player::getAmmo()
{
	return ammo;
}

int Player::getLifes()
{
	return lifes;
}

int Player::getPoints()
{
	return points;
}

void Player::addPoints(int pointsToAdd)
{
	points += pointsToAdd;
}

void Player::subtractLife()
{
	lifes--;
}


void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::updateMovement(bool intersectBlock)
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (this->getGlobalBounds().left > 50))
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (this->getGlobalBounds().left + this->getGlobalBounds().width < 10620))
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (this->jumpState == false) && (this->jumpPhaseOne == false)  && intersectBlock)
	{
		this->jumpState = true;
		this->jumpPhaseOne = true;
	}
	if ((this->jumpSpeed >= 0) && (this->jumpPhaseOne == true) && (this->jumpState == true))
	{
		this->move(0.f, -this->jumpSpeed);
		this->jumpSpeed -= 0.125f;
		if (this->jumpSpeed == 0)
		{
			this->jumpPhaseOne = false;
			this->jumpState = false;
			this->jumpSpeed = 5.f;
		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (this->fallState == false) && intersectBlock)
	{
		this->fallState = true;
		jumpSpeed = 0;
	}
	if (this->fallState == true)
	{
		if (intersectBlock)
		{	
			this->move(0.f, this->jumpSpeed);
			this->jumpSpeed +=0.125f;
		}
		else
		{
			fallState = false;
			jumpSpeed = 5.f;
		}
	}
}

void Player::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 160.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(3.f, 3.f);
		this->sprite.setOrigin(0.f, 0.f);

	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else
		this->animationTimer.restart();
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax && this->ammo > 0)
	{
		this->attackCooldown = 0.f;
		this->ammo--;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

void Player::updateStats(float pos_x)
{
	ammoRemained = std::to_string(ammo);
	pointsEarned = std::to_string(points);
	lifesReamined = std::to_string(lifes);
	overallAmmo = ammoString + ammoRemained;
	overallLifes = lifesString + lifesReamined;
	overallPoints = pointsString + pointsEarned;
	ammoState.setString(overallAmmo);
	lifesState.setString(overallLifes);
	pointsState.setString(overallPoints);
	ammoState.setPosition(sf::Vector2f(pos_x, this->ammoState.getPosition().y));
	lifesState.setPosition(sf::Vector2f(pos_x, this->lifesState.getPosition().y));
	pointsState.setPosition(sf::Vector2f(pos_x, this->pointsState.getPosition().y));
}

void Player::update(bool intersectBlock, float pos_x)
{
	this->updateMovement(intersectBlock);
	this->updateAnimations();
	this->updateAttack();
	this->updateStats(pos_x);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->ammoState);
	target.draw(this->pointsState);
	target.draw(this->lifesState);
}

void Player::setAmmo(int newAmmo)
{
	ammo = newAmmo;
}

void Player::setPoints(int newPoints)
{
	points = newPoints;
}

void Player::setLifes(int newLifes)
{
	lifes = newLifes;
}

void Player::setPos(sf::Vector2f coords)
{
	this->sprite.setPosition(coords);
}

