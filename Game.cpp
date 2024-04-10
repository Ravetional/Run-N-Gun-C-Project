#include "Game.h"
#include "Player.h"
#include <fstream>

int mapa[6][104] = {
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					 {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,0,0,0,5,5,5,5,5,7,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,5,5,0,0,5,5,0,0,0,0,0,5,5,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0},
					 {0,0,0,0,4,4,4,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,4,4,0,0,4,4,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,4,4,0,0,0,0,4,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0},
					 {0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,0},
					 {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1}
};

int mapEnemies[6][104] = {
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Run'n'gun", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	this->textures["ENEMY"] = new sf::Texture();
	this->textures["ENEMY"]->loadFromFile("Textures/player_sheet.png");
	this->textures["BLOCK"] = new sf::Texture();
	this->textures["BLOCK"]->loadFromFile("Textures/block_transparent.png");
	this->textures["BRIDGE"] = new sf::Texture();
	this->textures["BRIDGE"]->loadFromFile("Textures/bridge.png");
}

void Game::initGUI()
{
	
}

void Game::initWorld()
{
	if (!this->worldBackgroundTexture.loadFromFile("Textures/level1.png"))
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
	
	this->worldBackground.setTexture(this->worldBackgroundTexture);
	this->worldBackground.scale(3.2f, 3.2f);

	//Blocks
	for (int i = 0; i < 104; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (mapa[k][i] != 0)
			{
				if (mapa[k][i] == 7)
				{
					this->blocks.push_back(new Block(this->textures["BRIDGE"], 95 + i * 102.5, 6 - k));
				}
				else
				this->blocks.push_back(new Block(this->textures["BLOCK"], 95 + i*102.5, 6-k));
			}
		}
	}
}
void Game::initView()
{
	this->view.setCenter(sf::Vector2f((this->window->getSize().x)/2, (this->window->getSize().y)/2));
	this->view.setSize(sf::Vector2f(1280.f, 720.f));
}

void Game::initPlayer()
{
	this->player = new Player();
	this->intersectBlock = false;
}

void Game::initEnemies()
{
	//Spawning
	for (int i = 0; i < 104; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (mapEnemies[k][i] != 0)
			{
				this->enemies.push_back(new Enemy(this->textures["ENEMY"], 95 + i * 102.5, 6 - k));
			}
		}
	}
}

Game::Game()
{
	this->restartPressed = false;
	this->loadState = false;
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initView();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	//Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}
	//Delete blocks
	for (auto* i : this->blocks)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::P)
		{
			std::ofstream gameState("gameState.txt");
			gameState << this->player->getAmmo() << std::endl;
			gameState << this->player->getPoints() << std::endl;
			gameState << this->player->getLifes() << std::endl;
			gameState << this->player->getPos().x << std::endl;
			gameState << this->player->getPos().y << std::endl;
			gameState.close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::O)
		{
			std::ifstream gameState("gameState.txt");
			if (gameState.peek() == std::ifstream::traits_type::eof())
			{
				loadState = false;
			}
			else
				loadState = true;
		}
		if ((e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::R) || restartPressed == true || this->player->getLifes() == 0)
		{
			this->player->setAmmo(30);
			this->player->setPoints(0);
			this->player->setLifes(10);
			sf::Vector2f coords(200.f,200.f);
			this->player->setPos(coords);
			this->view.setCenter(sf::Vector2f((this->window->getSize().x)/2, (this->window->getSize().y)/2));
			std::ofstream gameState;
			gameState.close();
			this->enemies.clear();
			this->initEnemies();
			restartPressed = false;
		}
		if(loadState == true)
		{
			std::fstream gameState;
			gameState.open("gameState.txt", std::ios::in);
			std::string line;
			int lineNumber = 1;
			while(getline(gameState,line))
			{
				switch(lineNumber)
				{
					case 1: this->player->setAmmo(std::stoi(line)); break;
					case 2: this->player->setPoints(std::stoi(line)); break;
					case 3: this->player->setLifes(std::stoi(line)); break;
					case 4: this->posX = std::stof(line); break;
					case 5: this->posY = std::stof(line); break;
				}
				lineNumber++;
			}
			gameState.close();
			sf::Vector2f coords(posX,posY);
			this->player->setPos(coords);
			this->view.setCenter(posX, this->window->getSize().y/2);
			loadState = false;
		}
	}
}
void Game::updateInput()
{
	//Move player
	this->player->update(this->intersectBlock, this->view.getCenter().x - this->window->getSize().x/2);

	//Bullet
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->player->canAttack())
	{
		if (this->player->getSpriteScale().x == 3.f) //Right
		{
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x+100, this->player->getPos().y+65, 1.f, 0.f, 5.f));
		}
		else //Left
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x-10, this->player->getPos().y+65, -1.f, 0.f, 5.f));
	}
}

void Game::updateGUI()
{
	if (this->player->getPos().x == 10500)
	{
		font.loadFromFile("Textures/SuperMario256.ttf");
		score = this->player->getLifes() * this->player->getPoints() * 10 + this->player->getAmmo();
		sf::Text overallScore;
		sf::Text yourScore;
		sf::Text scoreCommunicate;
		overallScore.setFont(font);
		overallScore.setCharacterSize(100);
		overallScore.setFillColor(sf::Color::White);
		overallScore.setString(std::to_string(score));
		yourScore.setFont(font);
		yourScore.setCharacterSize(100);
		yourScore.setFillColor(sf::Color::White);
		yourScore.setString("Your score: ");
		scoreCommunicate.setString(yourScore.getString() + overallScore.getString());
		scoreCommunicate.setFont(font);
		scoreCommunicate.setCharacterSize(100);
		scoreCommunicate.setFillColor(sf::Color::White);
		scoreCommunicate.setPosition(0.f, 0.f);
		std::fstream bestScore;
		bestScore.open("bestScore.txt", std::ios::in);
		std::string line;
		int best;
		while(getline(bestScore,line))
		{
			best = std::stoi(line);
		}
		bestScore.close();
		if (score > best)
		{
			std::fstream bestScore;
			bestScore.open("bestScore.txt", std::ios::out);
			bestScore << score << std::endl;
			bestScore.close();
		}
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling(top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		//Bullet culling(right of screen)
		if (bullet->getBounds().left > this->view.getCenter().x + this->window->getSize().x/2)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		//Bullet culling(left of screen)
		if (bullet->getBounds().left < this->view.getCenter().x - this->window->getSize().x / 2)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateBulletsEnemy()
{
	//Shot
	for (auto* enemy : this->enemies)
	{
		if (enemy->getBounds().left - this->player->getGlobalBounds().left < this->window->getSize().x / 2 && enemy->canAttack())
		{
			this->bulletsEnemy.push_back(new Bullet(this->textures["BULLET"], enemy->getBounds().left - 10, enemy->getBounds().top + 65, -1.f, 0.f, 5.f));
		}
	}

	unsigned counter = 0;

	for (auto* bullet : this->bulletsEnemy)
	{
		bullet->update();

		//Bullet culling(top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bulletsEnemy.at(counter);
			this->bulletsEnemy.erase(this->bulletsEnemy.begin() + counter);
			--counter;
		}

		//Bullet culling(right of screen)
		if (bullet->getBounds().left > this->view.getCenter().x + this->window->getSize().x / 2)
		{
			//Delete bullet
			delete this->bulletsEnemy.at(counter);
			this->bulletsEnemy.erase(this->bulletsEnemy.begin() + counter);
			--counter;
		}

		//Bullet culling(left of screen)
		if (bullet->getBounds().left < this->view.getCenter().x - this->window->getSize().x / 2)
		{
			//Delete bullet
			delete this->bulletsEnemy.at(counter);
			this->bulletsEnemy.erase(this->bulletsEnemy.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateEnemies()
{
	//Update
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update();

		//Enemy culling(bottom of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}

	//Intersect Player
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		if (this->player->getGlobalBounds().intersects(this->enemies[i]->getBounds()))
		{
			this->player->move(-40.f, -20.f);
		}
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted==false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				if (this->enemies[i]->getHp() > 0)
				{
					this->enemies[i]->hit();
				}
				else
				{
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);
					player->addAmmo(15);
					player->addPoints(10);
				}

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}

	for (size_t k = 0; k < this->bulletsEnemy.size(); k++)
	{
		if (this->player->getGlobalBounds().intersects(this->bulletsEnemy[k]->getBounds()))
		{
			if (this->player->getLifes() > 0)
			{
				this->player->subtractLife();
			}

			delete this->bulletsEnemy[k];
			this->bulletsEnemy.erase(this->bulletsEnemy.begin() + k);
		}
	}
}

void Game::updateView()
{
	if (this->player->getPos().x >= (this->view.getCenter().x)+100)
	{
		this->view.setCenter(sf::Vector2f(view.getCenter().x + 2, view.getCenter().y));
	}
	else if ((this->player->getPos().x <= (this->view.getCenter().x)-200) && (this->view.getCenter().x > (this->window->getSize().x) /2))
	{
		this->view.setCenter(sf::Vector2f(view.getCenter().x - 2, view.getCenter().y));
	}
	if (this->player->getPos().y > 750)
		restartPressed = true;
}

void Game::updateBlocksColission()
{
	this->intersectBlock = false;

	for (int i =0; i < this->blocks.size(); ++i)
	{
		if (this->player->getGlobalBounds().intersects(this->blocks[i]->getBounds()))
		{
			if(this->player->getGlobalBounds().top + 100 <= this->blocks[i]->getBounds().top)
				this->intersectBlock = true;
		}
	}
	if(this->intersectBlock == false)
		this->player->move(0.f, 1.2f);
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->updateBullets();
	this->updateBulletsEnemy();
	this->updateEnemies();
	this->updateCombat();
	this->updateGUI();
	this->updateView();
	this->updateBlocksColission();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//Draw world
	this->renderWorld();

	//Draw view
	this->window->setView(this->view);

	//Draw blocks
	for (auto* block : this->blocks)
	{
		block->render(this->window);
	}

	//Draw all the stuffs
	if(loadState == true)
	{
		sf::Vector2f coords(posX,posY);
		this->player->setPos(coords);
		loadState = false;
	}
	this->player->render(*this->window);

	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* bulletEnemy : this->bulletsEnemy)
	{
		bulletEnemy->render(this->window);
	}

	this->renderGUI();

	this->window->display();
}