#pragma once

#include <SFML/Graphics.hpp>

const sf::Vector2f SIZE_PADDLE = sf::Vector2f(500, 15);
const sf::Vector2f STANDART_VELOCITY_PADDLE = sf::Vector2f(8.f, 0.f);

class Paddle {
private:
	sf::Vector2f _position;
	sf::Vector2f _velocity = sf::Vector2f(8.f, 0.f);
	sf::Vector2f _size;
	sf::RectangleShape _image;

public:
	Paddle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f size);

	void SetPosition(sf::Vector2f new_position);
	void SetVelocity(sf::Vector2f new_velocity);
	void SetSize(sf::Vector2f new_size);
	void SetImage(sf::RectangleShape new_image);

	sf::Vector2f const GetPosition();
	sf::Vector2f const GetVelocity();
	sf::Vector2f const GetSize();
	sf::RectangleShape const GetImage();

	void StartPosition(int width, int height);

	void Move();
};