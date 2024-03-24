#include "Bullet.h"
void Bullet::InitBullet(sf::CircleShape* bullet){
    bullet->setFillColor(sf::Color::White);
    bullet->setRadius(10.f);
    bullet->setOrigin(bullet->getRadius(), bullet->getRadius());
}
void Bullet::SpawnBullet(sf::CircleShape* bullet, vector<sf::CircleShape>* bullets, sf::RectangleShape* player, sf::RenderWindow* window,
    vector<float>* speedX, vector<float>* speedY, int* bulletCount, float* timeSpawnBullet, float* timeMaxSpawnBullet){
    if ((*bulletCount) > 0)
    {
        if (*(timeSpawnBullet) >= (*timeMaxSpawnBullet))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                (*bulletCount)--;
                (*timeSpawnBullet) = 0.f;
                pixelMousePos = sf::Mouse::getPosition(*window);
                worldMousePos = window->mapPixelToCoords(pixelMousePos);
                bullet->setPosition(player->getPosition());
                edgeX = worldMousePos.x - player->getPosition().x;
                edgeY = player->getPosition().y - worldMousePos.y;
                hypotenuse = hypot(edgeX, edgeY);
                angle = asin(edgeY / hypotenuse);
                if (worldMousePos.y < player->getPosition().y)
                {
                    dirY = -1;
                }
                else
                    dirY = -1;
                
                if (worldMousePos.x < player->getPosition().x)
                {
                    dirX = -1;
                }
                else
                    dirX = 1;
                (*speedX).push_back(speedBullet * dirX * cos(angle));
                (*speedY).push_back(speedBullet * dirY * sin(angle));
                bullets->push_back(*bullet);
            }
        }
        else
            (*timeSpawnBullet)++;
    }
}
void Bullet::MoveBullet(vector<sf::CircleShape>* bullets, vector<float>* speedX, vector<float>* speedY){
    for (int i = 0; i < bullets->size(); i++)
    {
        (*bullets)[i].move((*speedX)[i], (*speedY)[i]);
    }
}
void Bullet::DeleteBullet(vector<sf::CircleShape>* bullets, vector<float>* speedX, vector<float>* speedY){
    for (int i = 0; i < bullets->size(); i++)
    {
        if ((*bullets)[i].getPosition().x < - 5000.f)
        {
            (*bullets).erase((*bullets).begin() + i);
            (*speedX).erase((*speedX).begin() + i);
            (*speedY).erase((*speedY).begin() + i);
        }
        if ((*bullets)[i].getPosition().x > 5000.f)
        {
            (*bullets).erase((*bullets).begin() + i);
            (*speedX).erase((*speedX).begin() + i);
            (*speedY).erase((*speedY).begin() + i);
        }
        if ((*bullets)[i].getPosition().y < - 5000.f)
        {
            (*bullets).erase((*bullets).begin() + i);
            (*speedX).erase((*speedX).begin() + i);
            (*speedY).erase((*speedY).begin() + i);
        }
        if ((*bullets)[i].getPosition().y > 5000.f)
        {
            (*bullets).erase((*bullets).begin() + i);
            (*speedX).erase((*speedX).begin() + i);
            (*speedY).erase((*speedY).begin() + i);
        }
        
    }
}
void Bullet::LoadBullet(int* bulletCount, float* timeLoadBullet, float* timeMaxLoadBullet){
    if ((*bulletCount) <= 0)
    {
        if ((*timeLoadBullet) >= (*timeMaxLoadBullet))
        {
            (*timeLoadBullet) = 0;
            (*bulletCount) = 20;
        }
        else
            (*timeLoadBullet)++;
    }
    //cout << (*bulletCount) << endl;
}
