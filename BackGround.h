#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
#pragma once
class BackGround
{
public:
    void InitBackGround(sf::Texture*, sf::Sprite*);
    void AddBackGround(sf::Sprite*, vector<sf::Sprite>*);
    void RenderBackGround(sf::Sprite*, vector<sf::Sprite>*, float*, float*);
    void InitEdgeOut(sf::Texture*, sf::Sprite*);
    void AddEdgeOut(sf::Sprite*, vector<sf::Sprite>*);
    void RenderEdgeOut(sf::Sprite*, vector<sf::Sprite>*, float*, float*);
    
protected:
};

#endif