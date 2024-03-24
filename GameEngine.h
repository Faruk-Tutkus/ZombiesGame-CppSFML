#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include"Player.cpp"
#include"Bullet.cpp"
#include"BackGround.cpp"
#include"TextScreen.cpp"
#include"Animation.cpp"
#include"Enemy.cpp"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
#pragma once
class GameEngine : public Player, public Bullet, public BackGround, public TextScreen, public Enemy, public Animation
{
public:
    GameEngine();
    //window_S
    void InitWindow();
    void WindowUpdate();
    void UpdateEvent();
    void RenderWindow();
    ~GameEngine();
private:
    //window
    int screenWidht = 1024;
    int screenHeight = 720;
    sf::RenderWindow *window;
    sf::Event *event;
    //player
    sf::RectangleShape player;
    //bullet
    sf::CircleShape bullet;
    vector<sf::CircleShape> bullets;

    float timeSpawnBullet = 0.f;
    float timeMaxSpawnBullet = 15.f;

    vector<float> bulletSpeedX;
    vector<float> bulletSpeedY;
    float timeDeleteBullet = 0.f;
    float timeMaxDeleteBullet = 250.f;

    sf::View viewWindow;
    sf::Texture textureBackGround;
    sf::Sprite spriteBackGround;
    vector<sf::Sprite> spriteBackGrounds;

    float posBackX = 0.f;
    float posBackY = 0.f;

    int bulletCount = 20;

    float timeLoadBullet = 0.f;
    float timeMaxLoadBullet = 75.f;

    sf::Font font;
    sf::Text textBullet;

    sf::RectangleShape enemy;
    vector<sf::RectangleShape> enemys;
    float timeSpawnEnemy = 0.f;
    float timeMaxSpawnEnemy = 100.f;

    vector<float> speedEnemyX;
    vector<float> speedEnemyY;

    sf::Sprite spriteEdgeOut;
    vector<sf::Sprite> spriteEdgeOuts;
    sf::Texture textureEdgeOut;

    sf::Texture texturePlayer;
    sf::Sprite spritePlayer;

    sf::Texture textureEnemy;
    sf::Sprite spriteEnemy;
    vector<sf::Sprite> enemysAnimations;

    int killCount = 0;
    sf::Text textKill;

    sf::Text textHealth;
    int health = 100;
    float timeHealth = 0.f;
    float timeMaxHealth = 10.f;

    float timeGameSpeed = 0.f;
    float timeMaxGameSpeed = 250.f;
};

#endif