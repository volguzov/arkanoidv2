#pragma once

#include <SFML/Graphics.hpp>

const sf::Vector2f SIZE_BRICK = sf::Vector2f(100, 30);

class Brick {
private:
	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Color _color;
	short _health;
	sf::RectangleShape _image;

public:
	Brick(sf::Vector2f position, sf::Vector2f size, short health);

	void SetPosition(sf::Vector2f new_position);
	void SetSize(sf::Vector2f new_size);
	void SetColor(sf::Color new_color);
	void SetHealth(short new_health);
	void SetImage(sf::RectangleShape new_image);

	sf::Vector2f const GetPosition();
	sf::Vector2f const GetSize();
	sf::Color const GetColor();
	short const GetHealth();
	sf::RectangleShape const GetImage();
	bool const IsDestroyable();

	void UpdateHealth(int* score);
};