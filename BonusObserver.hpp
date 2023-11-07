#pragma once

#include "Bonus.hpp"

#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

class BonusObserver {
private:
	std::vector<std::shared_ptr<Bonus>> _bonuses;
public:
	BonusObserver();
	~BonusObserver();
	void const PushBonus(std::shared_ptr<Bonus> bonus);
	void RemoveBonus(std::shared_ptr<Bonus> bonus);

	std::vector<std::shared_ptr<Bonus>> const GetBonuses();
	void MovementBonuses();

	void AccelerationBallFromBricks(std::shared_ptr<Ball> ball);
	void DistributionBonuses(std::shared_ptr<Brick> brick);
};