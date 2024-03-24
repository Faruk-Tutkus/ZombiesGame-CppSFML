#include "Enemy.h"
void Enemy::InitEnemy(sf::RectangleShape* enemy){
    enemy->setFillColor(sf::Color::Red);
    enemy->setSize(sf::Vector2f(50.f,50.f));
    enemy->setOrigin(enemy->getSize().x / 2, enemy->getSize().y / 2);
}
void Enemy::SpawnEnemy(sf::RectangleShape* enemy, vector<sf::RectangleShape>* enemys, float* timeSpawnEnemy, float* timeMaxSpawnEnemy){
        if ((*timeSpawnEnemy) >= (*timeMaxSpawnEnemy))
        {
            (*timeSpawnEnemy) = 0;
            if ((*timeMaxSpawnEnemy) > 30)
            {
                (*timeMaxSpawnEnemy) -= 0.5f;
            }
            //cout << *timeMaxSpawnEnemy << endl;
            enemy->setPosition(static_cast<float>(rand() % 2800) + 50.f, static_cast<float>(rand() % 1825) + 50.f);
            enemys->push_back(*enemy);
        }
        else
            (*timeSpawnEnemy)++;
}
void Enemy::MoveEnemy(vector<sf::RectangleShape>* enemys, sf::RectangleShape* player, vector<float>* speedEnemyX,
    vector<float>* speedEnemyY){
    for (auto &i : *enemys)
    {
        edgeX = i.getPosition().x - player->getPosition().x;
        edgeY = i.getPosition().y - player->getPosition().y;
        hypotenuse = hypot(edgeX, edgeY);
        angle = asin(edgeY / hypotenuse);
        if (i.getPosition().y < player->getPosition().y)
        {
            dirY = -1;
        }
        else
            dirY = -1;
        
        if (i.getPosition().x < player->getPosition().x)
        {
            dirX = 1;
        }
        else
            dirX = -1;
        (*speedEnemyX).push_back(speedEnemy * dirX * cos(angle));
        (*speedEnemyY).push_back(speedEnemy * dirY * sin(angle));
        i.move((*speedEnemyX).back(), (*speedEnemyY).back());
    }
}
void Enemy::DeleteEnemy(vector<sf::RectangleShape>* enemys, vector<sf::CircleShape>* bullets,
    vector<float>* speedEnemyX, vector<float>* speedEnemyY, vector<float>* speedBulletX, vector<float>* speedBulletY,
        vector<sf::Sprite>* enemysAnimations, int* killcount){
    for (int i = 0; i < enemys->size(); i++)
    {
        for (int j = 0; j < bullets->size(); j++)
        {
            if ((*enemys)[i].getGlobalBounds().intersects((*bullets)[j].getGlobalBounds()))
            {
                (*killcount)++;
                //obj
                (*enemys).erase((*enemys).begin() + i);
                (*enemysAnimations).erase((*enemysAnimations).begin() + i);
                (*bullets).erase((*bullets).begin() + j);
                //speed
                (*speedEnemyX).erase((*speedEnemyX).begin() + i);
                (*speedEnemyY).erase((*speedEnemyY).begin() + i);
                (*speedBulletX).erase((*speedBulletX).begin() + j);
                (*speedBulletY).erase((*speedBulletY).begin() + j);
            }   
        }
    }
}