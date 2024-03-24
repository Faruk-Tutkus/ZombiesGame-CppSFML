#ifndef ANIMATION_H
#define ANIMATION_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
#pragma once

class Animation
{
public:
    void InitPlayerAnimation(sf::Texture*, sf::Sprite*); 
    void AnimationPlayer(sf::RectangleShape*, sf::Sprite*, sf::RenderWindow*);

    void InitEnemyAnimation(sf::Texture*, sf::Sprite*);
    void SpawnEnemyAnimation(vector<sf::Sprite>*, sf::Sprite*, float*, float*);
    void AnimationEnemy(vector<sf::RectangleShape>*, vector<sf::Sprite>*, sf::RectangleShape*);
private:
    sf::Vector2i pixelMousePos;
    sf::Vector2f worldMousePos;
    float edgeX;
    float edgeY;
    float hypotenuse;
    float angle;
    float dirY = 1;

    float edgeXEnemy;
    float edgeYEnemy;
    float hypotenuseEnemy;
    float angleEnemy;
    float dirEnemyY = 1;
};
#endif