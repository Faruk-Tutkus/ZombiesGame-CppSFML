#ifndef OBJECT_H
#define OBJECT_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
#pragma once

class WindowScreen
{
public:
    void setWindow(int*, int*);
    void setView(sf::RenderWindow*, sf::View*, sf::RectangleShape*);
protected:
    int screenWidth;
    int screenHeight;
};

#endif