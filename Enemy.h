#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
#pragma once
class Enemy
{
public:
    void InitEnemy(sf::RectangleShape*);
    void SpawnEnemy(sf::RectangleShape*, vector<sf::RectangleShape>*, float*, float*);
    void MoveEnemy(vector<sf::RectangleShape>*, sf::RectangleShape*, vector<float>*, vector<float>*);
    void DeleteEnemy(vector<sf::RectangleShape>*, vector<sf::CircleShape>*, vector<float>*, vector<float>*,
        vector<float>*, vector<float>*, vector<sf::Sprite>*, int*);
private:
    float edgeX;
    float edgeY;
    float hypotenuse;
    float angle;
    float dirX = 1;
    float dirY = 1;
    float speedEnemy = 5.f;
};
#endif