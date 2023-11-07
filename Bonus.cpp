#include "Bonus.hpp"

Bonus::Bonus(sf::Vector2f position) {
	_position = position;
	_velocity = STANDART_VELOCITY_BONUS;
}

void Bonus::Move() {
	_sprite.move(_velocity);
	_position = _position + _velocity;
}

void Bonus::SetPosition(sf::Vector2f new_position) {
	_position = new_position;
	_sprite.setPosition(new_position);
}

void Bonus::SetVelocity(sf::Vector2f new_velocity) {
	_velocity = new_velocity;
}

void Bonus::SetSize(sf::Vector2f new_size) {
	_size = new_size;

}

void Bonus::SetTexture(sf::Texture new_texture) {
	_texture = new_texture;
}

void Bonus::SetSprite(sf::Sprite new_sprite) {
	_sprite = new_sprite;
}

sf::Vector2f const Bonus::GetPosition() {
	return _position;
}

sf::Vector2f const Bonus::GetVelocity() {
	return _velocity;
}

sf::Vector2f const Bonus::GetSize() {
	return _size;
}

sf::Texture const Bonus::GetTexture() {
	return _texture;
}

sf::Sprite const Bonus::GetSprite() {
	return _sprite;
}

SpeedBallBonus::SpeedBallBonus(sf::Vector2f position) : Bonus(position) {
	if (!_texture.loadFromFile("resources\\textures\\SpeedBall.png")) {
		std::cout << "Error loading bonus texture" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(SCALE_FACTOR_X, SCALE_FACTOR_Y);
	_sprite.setPosition(_position);
	_size = sf::Vector2f(_sprite.getTextureRect().width * SCALE_FACTOR_X, _sprite.getTextureRect().height * SCALE_FACTOR_Y);
}

void SpeedBallBonus::Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
	ball->SetVelocity(sf::Vector2f(ball->GetSgnX() * _speed_coefficient, ball->GetSgnY() * _speed_coefficient));
}

WidthPaddleBonus::WidthPaddleBonus(sf::Vector2f position) : Bonus(position) {
	if (!_texture.loadFromFile("resources\\textures\\WidthPaddle.png")) {
		std::cout << "Error loading bonus texture" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(SCALE_FACTOR_X, SCALE_FACTOR_Y);
	_sprite.setPosition(_position);
	_size = sf::Vector2f(_sprite.getTextureRect().width * SCALE_FACTOR_X, _sprite.getTextureRect().height * SCALE_FACTOR_Y);

	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distrib(1, 2);
	if (distrib(rnd) == 1) _new_paddle_width = SIZE_PADDLE.x * 1.5;
	else _new_paddle_width = SIZE_PADDLE.x * 0.5;
}

void WidthPaddleBonus::Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
	paddle->SetSize(sf::Vector2f(_new_paddle_width, paddle->GetSize().y));
}

StickBallBonus::StickBallBonus(sf::Vector2f position) : Bonus(position) {
	if (!_texture.loadFromFile("resources\\textures\\StickBall.png")) {
		std::cout << "Error loading bonus texture" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(SCALE_FACTOR_X, SCALE_FACTOR_Y);
	_sprite.setPosition(_position);
	_size = sf::Vector2f(_sprite.getTextureRect().width * SCALE_FACTOR_X, _sprite.getTextureRect().height * SCALE_FACTOR_Y);
}

void StickBallBonus::Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
	ball->SetIsSticky(true);
}

SecondChanceBonus::SecondChanceBonus(sf::Vector2f position) : Bonus(position) {
	if (!_texture.loadFromFile("resources\\textures\\SecondChance.png")) {
		std::cout << "Error loading bonus texture" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(SCALE_FACTOR_X, SCALE_FACTOR_Y);
	_sprite.setPosition(_position);
	_size = sf::Vector2f(_sprite.getTextureRect().width * SCALE_FACTOR_X, _sprite.getTextureRect().height * SCALE_FACTOR_Y);
}

void SecondChanceBonus::Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
	ball->SetIsSecondChance(true);
}

RandomOrientationBonus::RandomOrientationBonus(sf::Vector2f position) : Bonus(position) {
	if (!_texture.loadFromFile("resources\\textures\\RandomOrientation.png")) {
		std::cout << "Error loading bonus texture" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(SCALE_FACTOR_X, SCALE_FACTOR_Y);
	_sprite.setPosition(_position);
	_size = sf::Vector2f(_sprite.getTextureRect().width * SCALE_FACTOR_X, _sprite.getTextureRect().height * SCALE_FACTOR_Y);
}

void RandomOrientationBonus::Activate(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distrib(150, 210);
	int alpha = distrib(rnd);
	float x = ball->GetVelocity().x;
	float y = ball->GetVelocity().y;
	float new_x = x * cos(alpha) - y * sin(alpha);
	float new_y = x * sin(alpha) + y * cos(alpha);
	ball->SetVelocity(sf::Vector2f(new_x, new_y));
	new_x > 0 ? ball->SetSgnX(1) : ball->SetSgnX(-1);
	new_y > 0 ? ball->SetSgnY(1) : ball->SetSgnY(-1);

}