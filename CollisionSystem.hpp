#pragma once

#include <SFML/Graphics.hpp>

#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "BonusObserver.hpp"

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

namespace CollisionSystem {
	static void CollisionBallWalls(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle, short* life, int width, int height) {
		float x = ball->GetPosition().x + ball->GetRadius();
		float y = ball->GetPosition().y + ball->GetRadius();

		if (x < 0 || x > width) {
			ball->SetSgnX(-ball->GetSgnX());
		}
		if (y < 0) {
			ball->SetSgnY(-ball->GetSgnY());
		}
		if (y > height) {
			if (ball->isSecondChance()) {
				ball->SetSgnY(-ball->GetSgnY());
				ball->SetIsSecondChance(false);
			}
			else {
				ball->StartPosition(width, height);
				paddle->StartPosition(width, height);
				*life = *life - 1;
			}
		}
	}

	static void CollisionBallPaddle(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
		sf::FloatRect ball_rect(ball->GetPosition().x, ball->GetPosition().y, ball->GetRadius() * 2, ball->GetRadius() * 2);
		sf::FloatRect paddle_rect(paddle->GetPosition().x, paddle->GetPosition().y, paddle->GetSize().x, paddle->GetSize().y);

		if (ball_rect.intersects(paddle_rect) && !ball->isSticky()) {
			sf::FloatRect intersection;
			if (ball_rect.intersects(paddle_rect, intersection)) {
				float overlap_x = intersection.width;
				float overlap_y = intersection.height;

				if (overlap_x >= overlap_y) {
					ball->SetSgnY(-ball->GetSgnY());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x, ball->GetPosition().y + ball->GetSgnY() * overlap_y));

				}
				else {
					ball->SetSgnX(-ball->GetSgnX());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x + ball->GetSgnX() * overlap_x, ball->GetPosition().y));
				}
			}
		}
		else if (ball_rect.intersects(paddle_rect) && ball->isSticky()) {
			ball->SetIsMoving(false);
			int x = ball->GetPosition().x;
			int y = ball->GetPosition().y;
			ball->SetPosition(sf::Vector2f(x, y));
		}
	}

	static void CollisionBallBricks(std::shared_ptr<Ball> ball, std::shared_ptr<std::vector<Brick>> bricks,
		int* score, std::shared_ptr<BonusObserver> bonus_observer) {
		sf::FloatRect ball_rect(ball->GetPosition().x, ball->GetPosition().y, ball->GetRadius() * 2, ball->GetRadius() * 2);
		for (int i = 0; i < bricks->size(); i++) {
			sf::FloatRect brick_rect(bricks->at(i).GetPosition().x, bricks->at(i).GetPosition().y, bricks->at(i).GetSize().x, bricks->at(i).GetSize().y);

			if (ball_rect.intersects(brick_rect)) {
				sf::Vector2f brick_tr(brick_rect.left + brick_rect.width, brick_rect.top);
				sf::Vector2f brick_tl(brick_rect.left, brick_rect.top);
				sf::Vector2f brick_br(brick_rect.left + brick_rect.width, brick_rect.top + brick_rect.height);
				sf::Vector2f brick_bl(brick_rect.left, brick_rect.top + brick_rect.height);

				float ball_min_x = ball_rect.left;
				float ball_max_x = ball_rect.left + ball_rect.width;
				float ball_min_y = ball_rect.top;
				float ball_max_y = ball_rect.top + ball_rect.height;

				float brick_min_x = std::min(brick_tl.x, brick_bl.x);
				float brick_max_x = std::max(brick_tr.x, brick_br.x);
				float brick_min_y = std::min(brick_tl.y, brick_tr.y);
				float brick_max_y = std::max(brick_bl.y, brick_br.y);

				float left_dist = abs(ball_max_x - brick_min_x);
				float right_dist = abs(ball_min_x - brick_max_x);
				float top_dist = abs(ball_max_y - brick_min_y);
				float bottom_dist = abs(ball_min_y - brick_max_y);

				if (left_dist <= right_dist && left_dist <= top_dist && left_dist <= bottom_dist) {
					ball->SetSgnX(-ball->GetSgnX());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x - ball->GetRadius(), ball->GetPosition().y));
				}
				else if (right_dist <= left_dist && right_dist <= top_dist && right_dist <= bottom_dist) {
					ball->SetSgnX(-ball->GetSgnX());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x + ball->GetRadius(), ball->GetPosition().y));
				}
				else if (top_dist <= left_dist && top_dist <= right_dist && top_dist <= bottom_dist) {
					ball->SetSgnY(-ball->GetSgnY());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x, ball->GetPosition().y - ball->GetRadius()));
				}
				else if (bottom_dist <= left_dist && bottom_dist <= right_dist && bottom_dist <= top_dist) {
					ball->SetSgnY(-ball->GetSgnY());
					ball->SetPosition(sf::Vector2f(ball->GetPosition().x, ball->GetPosition().y + ball->GetRadius()));
				}

				bricks->at(i).UpdateHealth(score);
				bonus_observer->AccelerationBallFromBricks(ball);
				bonus_observer->DistributionBonuses(std::make_shared<Brick>(bricks->at(i)));
			}

		}
	}
	static void CollisionPaddleBonuses(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle, std::shared_ptr<BonusObserver> bonus_observer) {
		sf::FloatRect paddle_rect(paddle->GetPosition().x, paddle->GetPosition().y, paddle->GetSize().x, paddle->GetSize().y);
		std::vector<std::shared_ptr<Bonus>> bonuses = bonus_observer->GetBonuses();
		for (std::shared_ptr<Bonus> bonus : bonuses) {
			sf::FloatRect bonus_rect(bonus->GetPosition().x, bonus->GetPosition().y, bonus->GetSize().x, bonus->GetSize().y);
			if (paddle_rect.intersects(bonus_rect)) {
				bonus->Activate(ball, paddle);
				bonus_observer->RemoveBonus(bonus);
			}
		}
	}
}