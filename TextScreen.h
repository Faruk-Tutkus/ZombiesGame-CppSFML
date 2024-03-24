#ifndef TEXTSCREEN_H
#define TEXTSCREEN_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
#pragma once
class TextScreen
{
public:
    void InitBulletText(sf::Font*, sf::Text*); 
    void PrintBullet(int*, sf::View*, sf::Text*);
    void InitKillText(sf::Font*, sf::Text*);
    void PrintKill(int*, sf::View*, sf::Text*);
    void InitHealth(sf::Font*, sf::Text*);
    void PrintHealth(int*, sf::View*, sf::Text*, sf::RectangleShape*, vector<sf::RectangleShape>*, float*, float*);
};

#endif