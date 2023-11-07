#pragma once

#include <SFML/Graphics.hpp>

const int RADIUS_BALL = 10;
const sf::Vector2f STANDART_VELOCITY_BALL = sf::Vector2f(5.f, 5.f);
const sf::Vector2f MAX_VELOCITY_BALL = sf::Vector2f(7.f, 7.f);

class Ball {
private:
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	float _sgn_x = -1;
	float _sgn_y = -1;
	int _radius;
	sf::CircleShape _image;

	bool _is_moving = false;
	bool _is_sticky = false;
	bool _is_second_chance = false;

public:
	Ball(sf::Vector2f position, sf::Vector2f velocity, int radius);

	void SetPosition(sf::Vector2f new_position);
	void SetVelocity(sf::Vector2f new_velocity);
	void SetSgnX(float new_sgn_x);
	void SetSgnY(float new_sgn_y);
	void SetRadius(int new_radius);
	void SetImage(sf::CircleShape new_image);
	void SetIsMoving(bool new_is_moving);
	void SetIsSticky(bool new_is_sticky);
	void SetIsSecondChance(bool new_second_chance);

	sf::Vector2f const GetPosition();
	sf::Vector2f const GetVelocity();
	float const GetSgnX();
	float const GetSgnY();
	int const GetRadius();
	sf::CircleShape const GetImage();
	bool const isMoving();
	bool const isSticky();
	bool const isSecondChance();

	void StartPosition(int width, int height);

	void Move();
};