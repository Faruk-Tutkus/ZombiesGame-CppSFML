#include "Animation.h"

void Animation::InitPlayerAnimation(sf::Texture* texturePlayer, sf::Sprite* spritePlayer){
    texturePlayer->loadFromFile("player.png");
    spritePlayer->setTexture(*texturePlayer);
    spritePlayer->setOrigin(spritePlayer->getGlobalBounds().width / 2, spritePlayer->getGlobalBounds().height / 2);
    spritePlayer->setScale(1.5f, 1.5f);
}
void Animation::AnimationPlayer(sf::RectangleShape* player, sf::Sprite* spritePlayer, sf::RenderWindow* window){
    
    pixelMousePos = sf::Mouse::getPosition(*window);
    worldMousePos = window->mapPixelToCoords(pixelMousePos);
    spritePlayer->setPosition(player->getPosition());
    edgeX = worldMousePos.x - spritePlayer->getPosition().x;
    edgeY = spritePlayer->getPosition().y - worldMousePos.y;
    hypotenuse = hypot(edgeX, edgeY);
    angle = acos(edgeX / hypotenuse);
    if (worldMousePos.y < spritePlayer->getPosition().y)
    {
        dirY = -1;
    }
    else
        dirY = 1;
    spritePlayer->setRotation(angle * 180.f / 3.14f * dirY);
}
void Animation::InitEnemyAnimation(sf::Texture* textureEnemy, sf::Sprite* spriteEnemy){
    textureEnemy->loadFromFile("enemy.png");
    spriteEnemy->setTexture(*textureEnemy);
    spriteEnemy->setOrigin(spriteEnemy->getGlobalBounds().width / 2, spriteEnemy->getGlobalBounds().height / 2);
    spriteEnemy->setScale(-1.5f, 1.5f);
}
void Animation::SpawnEnemyAnimation(vector<sf::Sprite>* enemysAnimations, sf::Sprite* spriteEnemy, float* timeSpawnEnemy, float* timeMaxSpawnEnemy){
    if ((*timeSpawnEnemy) >= (*timeMaxSpawnEnemy))
    {
        enemysAnimations->push_back(*spriteEnemy);
        enemysAnimations->back().setPosition(-1000,1000);
    }
}
void Animation::AnimationEnemy(vector<sf::RectangleShape>* enemys, vector<sf::Sprite>* enemysAnimations, sf::RectangleShape* player){
    for (int i = 0; i < enemys->size(); i++)
    {
        edgeXEnemy = (*enemys)[i].getPosition().x - player->getPosition().x;
        edgeYEnemy = (*enemys)[i].getPosition().y - player->getPosition().y;
        hypotenuseEnemy = hypot(edgeXEnemy, edgeYEnemy);
        angleEnemy = acos(edgeXEnemy / hypotenuseEnemy);
        if ((*enemys)[i].getPosition().y < player->getPosition().y)
        {
            dirEnemyY = -1;
        }
        else
            dirEnemyY = 1;
        (*enemysAnimations)[i].setPosition((*enemys)[i].getPosition());
        (*enemysAnimations)[i].setRotation(angleEnemy * 180.f / 3.14f * dirEnemyY);
    }
}
