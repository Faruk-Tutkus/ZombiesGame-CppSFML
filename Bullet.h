#ifndef BULLET_H
#define BULLET_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
#pragma once
class Bullet
{
public:
    void InitBullet(sf::CircleShape*);
    void SpawnBullet(sf::CircleShape*, vector<sf::CircleShape>*, sf::RectangleShape*, sf::RenderWindow*,
    vector<float>*, vector<float>*, int*, float*, float*);
    void MoveBullet(vector<sf::CircleShape>*, vector<float>*, vector<float>*);
    void LoadBullet(int*, float*, float*);
    void DeleteBullet(vector<sf::CircleShape>*, vector<float>*, vector<float>*);
protected:
    sf::Vector2i pixelMousePos;
    sf::Vector2f worldMousePos;
    float edgeX;
    float edgeY;
    float hypotenuse;
    float angle;
    float dirX = 1;
    float dirY = 1;
    float speedBullet = 25.f;
};

#endif