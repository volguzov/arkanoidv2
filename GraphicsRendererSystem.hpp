#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Bonus.hpp"
#include "BonusObserver.hpp"

namespace GraphicsRendererSystem {
	static void Rendering(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle,
		std::shared_ptr<std::vector<Brick>> bricks, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<BonusObserver> bonus_observer) {

		window->clear();
		window->draw(ball->GetImage());
		window->draw(paddle->GetImage());
		for (auto& brick : *bricks) {
			window->draw(brick.GetImage());
		}
		for (std::shared_ptr<Bonus> bonus : bonus_observer->GetBonuses()) {
			window->draw(bonus->GetSprite());
		}
		window->display();
	}
}