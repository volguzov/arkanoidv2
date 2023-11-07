#pragma once

#include <SFML/Graphics.hpp>

#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

const sf::Vector2f STANDART_VELOCITY_BONUS = sf::Vector2f(0.f, 3.f);
const float SCALE_FACTOR_X = 0.075;
const float SCALE_FACTOR_Y = 0.075;

class Bonus {
protected:
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	sf::Vector2f _size;
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Bonus(sf::Vector2f position);
	virtual ~Bonus() = default;
	virtual void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) = 0;
	void Move();

	void SetPosition(sf::Vector2f new_position);
	void SetVelocity(sf::Vector2f new_velocity);
	void SetSize(sf::Vector2f new_size);
	void SetTexture(sf::Texture new_texture);
	void SetSprite(sf::Sprite new_sprite);

	sf::Vector2f const GetPosition();
	sf::Vector2f const GetVelocity();
	sf::Vector2f const GetSize();
	sf::Texture const GetTexture();
	sf::Sprite const GetSprite();
};

class SpeedBallBonus : public Bonus {
private:
	float _speed_coefficient = MAX_VELOCITY_BALL.x + 2; 
public:
	SpeedBallBonus(sf::Vector2f position);
	void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) override;
};

class WidthPaddleBonus : public Bonus {
private:
	float _new_paddle_width;
public:
	WidthPaddleBonus(sf::Vector2f position);
	void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) override;
};

class StickBallBonus : public Bonus {
public:
	StickBallBonus(sf::Vector2f position);
	void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) override;
};

class SecondChanceBonus : public Bonus {
public:
	SecondChanceBonus(sf::Vector2f position);
	void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) override;
};

class RandomOrientationBonus : public Bonus {
public:
	RandomOrientationBonus(sf::Vector2f position);
	void Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) override;
};