#include "Brick.hpp"

Brick::Brick(sf::Vector2f position, sf::Vector2f size, short health) {
	_position = position;
	_size = size;
	_health = health;
	_image = sf::RectangleShape(_size);
	_image.setOutlineColor(sf::Color::White);
	_image.setOutlineThickness(2);
	_image.setPosition(position);
}

void Brick::SetPosition(sf::Vector2f new_position) {
	_position = new_position;
	_image.setPosition(new_position);
}

void Brick::SetSize(sf::Vector2f new_size) {
	_size = new_size;
}

void Brick::SetColor(sf::Color new_color) {
	_color = new_color;
	_image.setFillColor(new_color);
}

void Brick::SetHealth(short new_health) {
	_health = new_health;
}

void Brick::SetImage(sf::RectangleShape new_image) {
	_image = new_image;
}

sf::Vector2f const Brick::GetPosition() {
	return _position;
}

sf::Vector2f const Brick::GetSize() {
	return _size;
}

sf::Color const Brick::GetColor() {
	return _color;
}

short const Brick::GetHealth() {
	return _health;
}

sf::RectangleShape const Brick::GetImage() {
	return _image;
}

bool const Brick::IsDestroyable() {
	if (this->GetColor() == sf::Color::Black) return false;
	else return true;
}

void Brick::UpdateHealth(int* score) {
	int health = this->GetHealth() - 1;
	this->SetHealth(health);
	switch (this->GetHealth()) {
	case 0:
		this->SetPosition(sf::Vector2f(-200, -200));
		*score = *score + 1;
		break;
	case 1:
		this->SetColor(sf::Color::Green);
		*score = *score + 1;
		break;
	case 2:
		this->SetColor(sf::Color::Yellow);
		*score = *score + 1;
		break;
	case 3:
		this->SetColor(sf::Color::Red);
		*score = *score + 1;
		break;
	}
}