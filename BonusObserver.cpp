#include "BonusObserver.hpp"

BonusObserver::BonusObserver() {}

BonusObserver::~BonusObserver() {
	if (!_bonuses.empty()) {
		for (std::shared_ptr<Bonus> bonus : _bonuses) {
			bonus = nullptr;
		}
	}
}

void const BonusObserver::PushBonus(std::shared_ptr<Bonus> bonus) {
	_bonuses.push_back(bonus);
}

void BonusObserver::RemoveBonus(std::shared_ptr<Bonus> bonus) {
	_bonuses.erase(std::remove(_bonuses.begin(), _bonuses.end(), bonus), _bonuses.end());
	bonus = nullptr;
}

std::vector<std::shared_ptr<Bonus>> const BonusObserver::GetBonuses() {
	return _bonuses;
}

void BonusObserver::MovementBonuses() {
	for (std::shared_ptr<Bonus> bonus : _bonuses) {
		bonus->Move();
	}
}

void BonusObserver::AccelerationBallFromBricks(std::shared_ptr<Ball> ball) {
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distrib(1, 5);

	if (distrib(rnd) == 5) {
		ball->SetVelocity(sf::Vector2f(ball->GetSgnX() * (abs(ball->GetVelocity().x) + 1), ball->GetSgnY() * (abs(ball->GetVelocity().y) + 1)));
		if (abs(ball->GetVelocity().x) > MAX_VELOCITY_BALL.x) {
			ball->SetVelocity(sf::Vector2f(ball->GetSgnX() * MAX_VELOCITY_BALL.x, ball->GetSgnY() * MAX_VELOCITY_BALL.y));
		}
	}
}

void BonusObserver::DistributionBonuses(std::shared_ptr<Brick> brick) {
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distrib(1, 18);

	if (brick->IsDestroyable()) {
		switch (distrib(rnd)) {
		case 1: {
			std::shared_ptr<Bonus> bonus = std::make_shared<SpeedBallBonus>(brick->GetPosition());
			this->PushBonus(bonus);
			break;
		}
		case 2: {
			std::shared_ptr<Bonus> bonus = std::make_shared<WidthPaddleBonus>(brick->GetPosition());
			this->PushBonus(bonus);
			break;
		}
		case 3: {
			std::shared_ptr<Bonus> bonus = std::make_shared<StickBallBonus>(brick->GetPosition());
			this->PushBonus(bonus);
			break;
		}
		case 4: {
			std::shared_ptr<Bonus> bonus = std::make_shared<SecondChanceBonus>(brick->GetPosition());
			this->PushBonus(bonus);
			break;
		}
		case 5: {
			std::shared_ptr<Bonus> bonus = std::make_shared<RandomOrientationBonus>(brick->GetPosition());
			this->PushBonus(bonus);
			break;
		}
		}
	}
}