#include "Paddle.hpp"

Paddle::Paddle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f size) {
	_position = position;
	_velocity = velocity;
	_size = size;
	_image = sf::RectangleShape(_size);
	_image.setFillColor(sf::Color::White);
	_image.setPosition(position);
}

void Paddle::SetPosition(sf::Vector2f new_position) {
	_position = new_position;
	_image.setPosition(new_position);
}

void Paddle::SetVelocity(sf::Vector2f new_velocity) {
	_velocity = new_velocity;
}

void Paddle::SetSize(sf::Vector2f new_size) {
	_size = new_size;
	_image.setSize(new_size);
}

void Paddle::SetImage(sf::RectangleShape new_image) {
	_image = new_image;
}

sf::Vector2f const Paddle::GetPosition() {
	return _position;
}

sf::Vector2f const Paddle::GetVelocity() {
	return _velocity;
}

sf::Vector2f const Paddle::GetSize() {
	return _size;
}

sf::RectangleShape const Paddle::GetImage() {
	return _image;
}

void Paddle::StartPosition(int width, int height) {
	this->SetPosition(sf::Vector2f(width / 2 - 0.5 * _size.x, height * 0.8));
	this->SetVelocity(sf::Vector2f(0, 0));
	this->SetSize(SIZE_PADDLE);
}

void Paddle::Move() {
	_image.move(_velocity);
	_position = _position + _velocity;
}