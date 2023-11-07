#include "Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Vector2f velocity, int radius) {
	_position = position;
	_velocity = velocity;
	_radius = radius;
	_sgn_x = -1;
	_sgn_y = -1;
	_image = sf::CircleShape(radius);
	_image.setFillColor(sf::Color::Red);
	_image.setPosition(position);
}

void Ball::SetPosition(sf::Vector2f new_position) {
	_position = new_position;
	_image.setPosition(new_position);
}

void Ball::SetVelocity(sf::Vector2f new_velocity) {
	_velocity = new_velocity;
}

void Ball::SetSgnX(float new_sgn_x) {
	_sgn_x = new_sgn_x;
}

void Ball::SetSgnY(float new_sgn_y) {
	_sgn_y = new_sgn_y;
}

void Ball::SetRadius(int new_radius) {
	_radius = new_radius;
	_image.setRadius(new_radius);
}

void Ball::SetImage(sf::CircleShape new_image) {
	_image = new_image;
}

void Ball::SetIsMoving(bool new_is_moving) {
	_is_moving = new_is_moving;
}

void Ball::SetIsSticky(bool new_is_sticky) {
	_is_sticky = new_is_sticky;
}

void Ball::SetIsSecondChance(bool new_second_chance) {
	_is_second_chance = new_second_chance;
}

sf::Vector2f const Ball::GetPosition() {
	return _position;
}

sf::Vector2f const Ball::GetVelocity() {
	return _velocity;
}

float const Ball::GetSgnX() {
	return _sgn_x;
}

float const Ball::GetSgnY() {
	return _sgn_y;
}

int const Ball::GetRadius() {
	return _radius;
}

sf::CircleShape const Ball::GetImage() {
	return _image;
}

bool const Ball::isMoving() {
	return _is_moving;
}

bool const Ball::isSticky() {
	return _is_sticky;
}

bool const Ball::isSecondChance() {
	return _is_second_chance;
}

void Ball::StartPosition(int width, int height) {
	_is_moving = false;
	this->SetPosition(sf::Vector2f(width / 2 - _radius, height * 0.8 - 2 * _radius));
	this->SetVelocity(STANDART_VELOCITY_BALL);
	this->SetSgnX(-1);
	this->SetSgnY(-1);
}

void Ball::Move() {
	_image.move(_velocity);
	_position = _position + _velocity;
}