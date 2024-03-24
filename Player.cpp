#include "Player.h"
void Player::InitPlayer(sf::RectangleShape *player){
    player->setFillColor(sf::Color(0,255,0,0));
    player->setSize(sf::Vector2f(50.f,50.f));
    player->setOrigin(player->getSize().x / 2, player->getSize().y / 2);
    player->setPosition(screenWidth, screenHeight);  
}
void Player::MovePlayer(sf::RectangleShape *player){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (player->getPosition().x < 2400 + 450)
        {
            player->move(playerSpeed,0.f);
        }
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (player->getPosition().x > 25.0f)
        {
            player->move(-playerSpeed, 0.f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (player->getPosition().y > 30.f)
        {
            player->move(0.f, -playerSpeed);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (player->getPosition().y < 960 + 930)
        {
            player->move(0.f, playerSpeed);
        }
    }
}
