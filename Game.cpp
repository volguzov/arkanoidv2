#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include <iostream>

Game::Game(int width, int height) {
    _width = width;
    _height = height;
}

std::shared_ptr<sf::RenderWindow> Game::CreateWindow() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(_width, _height), "Arcanoid");
    window->setFramerateLimit(100);
    window->setVerticalSyncEnabled(true);
    window->setKeyRepeatEnabled(false);
    return std::shared_ptr<sf::RenderWindow>(window);
}

std::shared_ptr<Ball> Game::CreateBall() {
    sf::Vector2f position_ball = sf::Vector2f(_width / 2 - RADIUS_BALL, _height * 0.8 - 2 * RADIUS_BALL);
    sf::Vector2f velocity_ball = sf::Vector2f(5.f, 5.f);
    Ball* ball = new Ball(position_ball, velocity_ball, RADIUS_BALL);
    return std::shared_ptr<Ball>(ball);
}

std::shared_ptr<Paddle> Game::CreatePaddle() {
    sf::Vector2f position_paddle = sf::Vector2f(_width / 2 - 0.5 * SIZE_PADDLE.x, _height * 0.8);
    sf::Vector2f velocity_paddle = sf::Vector2f(0, 0);
    Paddle* paddle = new Paddle(position_paddle, velocity_paddle, SIZE_PADDLE);
    return std::shared_ptr<Paddle>(paddle);
}

std::shared_ptr<std::vector<Brick>> Game::CreateGridBricks() {
    std::shared_ptr<std::vector<Brick>> bricks = std::make_shared<std::vector<Brick>>();

    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 8; i++) {
            switch (j) {
            case 0: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 1);
                brick.SetColor(sf::Color::Green);
                bricks->push_back(brick);

                break;
            }
            case 1: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 3);
                brick.SetColor(sf::Color::Red);
                bricks->push_back(brick);

                break;
            }
            case 2: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, -1);
                brick.SetColor(sf::Color::Black);
                bricks->push_back(brick);

                break;
            }
            case 3: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 1);
                brick.SetColor(sf::Color::Green);
                bricks->push_back(brick);

                break;
            }
            case 4: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 3);
                brick.SetColor(sf::Color::Red);
                bricks->push_back(brick);

                break;
            }
            case 5: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 1);
                brick.SetColor(sf::Color::Green);
                bricks->push_back(brick);

                break;
            }
            case 6: {
                float start_pos_X = _width / 2.0f - (SIZE_BRICK.x * 8 + 20 * 7) / 2.0f;
                float start_pos_Y = _height / 2.0f - (SIZE_BRICK.y * 7 + 20 * 6 + 20 + SIZE_BRICK.y) / 2.0f - 150;
                sf::Vector2f current_pos = sf::Vector2f(SIZE_BRICK.x * i + 20 * i + start_pos_X, SIZE_BRICK.y * j + 20 * j + start_pos_Y);

                Brick brick(current_pos, SIZE_BRICK, 2);
                brick.SetColor(sf::Color::Yellow);
                bricks->push_back(brick);

                break;
            }
            }
        }
    }

    return std::shared_ptr<std::vector<Brick>>(bricks);
}

std::shared_ptr<BonusObserver> Game::CreateBonusObserver() {
    std::shared_ptr<BonusObserver> bonus_observer = std::make_shared<BonusObserver>();
    return bonus_observer;
}

sf::RectangleShape Game::CreateFloor() {
    sf::RectangleShape floor(sf::Vector2f(_width, 2));
    floor.setFillColor(sf::Color(200, 200, 200));
    floor.setPosition(0, _position_floor);
    return floor;
}

void Game::Start() {
    std::shared_ptr<sf::RenderWindow> window = CreateWindow();
    std::shared_ptr<std::vector<Brick>> bricks = CreateGridBricks();
    std::shared_ptr<Paddle> paddle = CreatePaddle();
    std::shared_ptr<Ball> ball = CreateBall();
    std::shared_ptr<BonusObserver> bonus_observer = CreateBonusObserver();
    sf::RectangleShape floor = CreateFloor();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (paddle->GetPosition().x < _width - paddle->GetSize().x) {
                paddle->SetVelocity(STANDART_VELOCITY_PADDLE);
                paddle->Move();
                if (!ball->isMoving()) {
                    ball->SetVelocity(STANDART_VELOCITY_PADDLE);
                    ball->Move();
                    ball->SetVelocity(STANDART_VELOCITY_BALL);
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (paddle->GetPosition().x > 0) {
                paddle->SetVelocity(-STANDART_VELOCITY_PADDLE);
                paddle->Move();
                if (!ball->isMoving()) {
                    ball->SetVelocity(-STANDART_VELOCITY_PADDLE);
                    ball->Move();
                    ball->SetVelocity(STANDART_VELOCITY_BALL);
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            ball->SetIsMoving(true);
            ball->SetIsSticky(false);
        }

        if (ball->isMoving()) {
            Move(ball, paddle, bricks, bonus_observer);
        }

        if (!bonus_observer->GetBonuses().empty()) {
            bonus_observer->MovementBonuses();
        }

        if (IsEndBricks(bricks)) {
            Win(window);
            ClearMemory(ball, paddle, bricks, window, bonus_observer);
            break;
        }

        if (IsEndLifes()) {
            Defeat(window);
            ClearMemory(ball, paddle, bricks, window, bonus_observer);
            break;
        }

        GraphicsRendererSystem::Rendering(ball, paddle, bricks, window, bonus_observer);
    }
}

void Game::Move(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle,
    std::shared_ptr<std::vector<Brick>> bricks, std::shared_ptr<BonusObserver> bonus_observer) {

    ball->SetVelocity(sf::Vector2f(ball->GetSgnX() * abs(ball->GetVelocity().x), ball->GetSgnY() * abs(ball->GetVelocity().y)));
    ball->Move();

    CollisionSystem::CollisionBallWalls(ball, paddle, &_life, _width, _height);
    CollisionSystem::CollisionBallPaddle(ball, paddle);
    CollisionSystem::CollisionBallBricks(ball, bricks, &_score, bonus_observer);
    CollisionSystem::CollisionPaddleBonuses(ball, paddle, bonus_observer);
}

void const Game::Win(std::shared_ptr<sf::RenderWindow> window) {
    sf::Text winText;
    sf::Font font;
    font.loadFromFile("resources\\fonts\\ArialRegular.ttf");
    winText.setFont(font);
    winText.setCharacterSize(58);
    winText.setFillColor(sf::Color::White);
    winText.setString("WIN! SCORE: " + std::to_string(_score));
    winText.setPosition(window->getSize().x / 3, window->getSize().y / 4);
    winText.setOutlineThickness(2);
    winText.setOutlineColor(sf::Color::Black);

    sf::Texture back_tex;
    sf::Sprite back_sprite;
    back_tex.loadFromFile("resources\\textures\\background.png");
    back_sprite.setTexture(back_tex);
    back_sprite.setScale(
        float(window->getSize().x) / back_sprite.getLocalBounds().width,
        float(window->getSize().y) / back_sprite.getLocalBounds().height);

    window->clear();
    window->draw(back_sprite);
    window->draw(winText);
    window->display();
    sf::sleep(sf::seconds(3.f));
}

void const Game::Defeat(std::shared_ptr<sf::RenderWindow> window) {
    sf::Text loseText;
    sf::Font font;
    font.loadFromFile("resources\\fonts\\ArialRegular.ttf");
    loseText.setFont(font);
    loseText.setCharacterSize(58);
    loseText.setFillColor(sf::Color::White);
    loseText.setString("GAME OVER! SCORE: " + std::to_string(_score));
    loseText.setPosition(window->getSize().x / 4, window->getSize().y / 4);
    loseText.setOutlineThickness(2);
    loseText.setOutlineColor(sf::Color::Black);

    sf::Texture back_tex;
    sf::Sprite back_sprite;
    back_tex.loadFromFile("resources\\textures\\background.png");
    back_sprite.setTexture(back_tex);
    back_sprite.setScale(
        float(window->getSize().x) / back_sprite.getLocalBounds().width,
        float(window->getSize().y) / back_sprite.getLocalBounds().height);

    window->clear();
    window->draw(back_sprite);
    window->draw(loseText);
    window->display();
    sf::sleep(sf::seconds(3.f));
}

bool const Game::IsEndBricks(std::shared_ptr<std::vector<Brick>> bricks) {
    int quantity_bricks = 0;
    int quantity_destroyed_bricks = 0;
    for (auto& brick : *bricks) {
        if (brick.GetColor() != sf::Color::Black) quantity_bricks += 1;
    }

    for (auto& brick : *bricks) {
        if ((brick.GetColor() != sf::Color::Black) && (brick.GetPosition() == sf::Vector2f(-200, -200))) {
            quantity_destroyed_bricks += 1;
        }
    }

    if (quantity_bricks == quantity_destroyed_bricks) return true;
    return false;
}

bool const Game::IsEndLifes() {
    if (_life == 0) return true;
    return false;
}

void Game::ClearMemory(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle,
    std::shared_ptr<std::vector<Brick>> bricks, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<BonusObserver> bonus_observer) {

    ball = nullptr;
    paddle = nullptr;
    bricks = nullptr;
    bonus_observer = nullptr;
    window = nullptr;
}