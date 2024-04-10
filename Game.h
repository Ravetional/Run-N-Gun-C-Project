#ifndef GAME_H
#define GAME_H

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Block.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures; // Map with textures
	std::vector<Bullet*> bullets;

 
	//GUI
	sf::Font font;
	sf::Text pointText;

	//World
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;
	std::vector<Block*> blocks;

	//View
	sf::View view;

	//Player
	Player* player;
	bool intersectBlock;

	//Enemies
	std::vector<Enemy*> enemies;

	//Bullets of enemies
	std::vector<Bullet*> bulletsEnemy;

	//Private functions:
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initView();
	void initPlayer();
	void initEnemies();

	bool loadState;
	float posX;
	float posY;
	bool restartPressed;
	int score;
	std::vector<int> bestScores;

public:
	Game();
	virtual ~Game();

	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateBulletsEnemy();
	void updateEnemies();
	void updateCombat();
	void updateView();
	void updateBlocksColission();
	void update();
	void renderGUI();
	void renderWorld();
	void render();

};

#endif