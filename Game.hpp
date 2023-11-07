#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "GraphicsRendererSystem.hpp"
#include "CollisionSystem.hpp"

#include <vector>

class Game {
private:
	int _width;
	int _height;
	float _position_floor = 0.9 * _width;
	int _score = 0;
	short _life = 3;

	std::shared_ptr<sf::RenderWindow> CreateWindow();
	std::shared_ptr<Ball> CreateBall();
	std::shared_ptr<Paddle> CreatePaddle();
	std::shared_ptr<std::vector<Brick>> CreateGridBricks();
	std::shared_ptr<BonusObserver> CreateBonusObserver();
	sf::RectangleShape CreateFloor();

	void Move(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle,
		std::shared_ptr<std::vector<Brick>> bricks, std::shared_ptr<BonusObserver> bonus_observer);

public:
	Game(int width, int height);

	void Start();
	void const Win(std::shared_ptr<sf::RenderWindow> window);
	void const Defeat(std::shared_ptr<sf::RenderWindow> window);
	bool const IsEndBricks(std::shared_ptr<std::vector<Brick>> bricks);
	bool const IsEndLifes();
	void ClearMemory(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle,
		std::shared_ptr<std::vector<Brick>> bricks, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<BonusObserver> bonus_observer);

};