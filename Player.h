#ifndef PLAYER_H
#define PLAYER_H
#include"WindowScreen.cpp"
#pragma once
class Player : public WindowScreen
{
public:
    void InitPlayer(sf::RectangleShape*);
    void MovePlayer(sf::RectangleShape*);
protected:
    float playerSpeed = 10.f;
};

#endif