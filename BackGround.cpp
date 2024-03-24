#include "BackGround.h"
void BackGround::InitBackGround(sf::Texture* textureBackGround, sf::Sprite* spriteBackGround){
    textureBackGround->loadFromFile("background.png");
    spriteBackGround->setTexture(*textureBackGround);
    spriteBackGround->setScale(10.f,10.f);
    //spriteBackGround->setOrigin(textureBackGround->getSize().x / 2, textureBackGround->getSize().y / 2);
}
void BackGround::AddBackGround(sf::Sprite* spriteBackGround, vector<sf::Sprite>* spriteBackGrounds){
    for (int i = 0; i < 24; i++)
    {
        spriteBackGrounds->push_back(*spriteBackGround);
    }
}
void BackGround::RenderBackGround(sf::Sprite* spriteBackGround, vector<sf::Sprite>* spriteBackGrounds, float* posBackX, float* posBackY){

    //background
    (*spriteBackGrounds)[0].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[1].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[2].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[3].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[4].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[5].setPosition(*posBackX, *posBackY);
    (*posBackX) = 0;
    (*posBackY) += 480;
    (*spriteBackGrounds)[6].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[7].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[8].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[9].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[10].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[11].setPosition(*posBackX, *posBackY);
    (*posBackX) = 0;
    (*posBackY) += 480;
    (*spriteBackGrounds)[12].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[13].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[14].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[15].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[16].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[17].setPosition(*posBackX, *posBackY);
    (*posBackX) = 0;
    (*posBackY) += 480;
    (*spriteBackGrounds)[18].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[19].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[20].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[21].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[22].setPosition(*posBackX, *posBackY);
    (*posBackX) += 480;
    (*spriteBackGrounds)[23].setPosition(*posBackX, *posBackY);
}
void BackGround::InitEdgeOut(sf::Texture* textureEdgeOut, sf::Sprite* spriteEdgeOut){
    textureEdgeOut->loadFromFile("EdgeOut.png");
    spriteEdgeOut->setTexture(*textureEdgeOut);
    spriteEdgeOut->setScale(15.f,15.f);
}
void BackGround::AddEdgeOut(sf::Sprite* spriteEdgeOut, vector<sf::Sprite>* spriteEdgeOuts){
    for (int i = 0; i < 21; i++)
    {
        spriteEdgeOuts->push_back(*spriteEdgeOut);
    }
}
void BackGround::RenderEdgeOut(sf::Sprite* spriteEdgeOut, vector<sf::Sprite>* spriteEdgeOuts, float* posBackX, float* posBackY){
    (*posBackX) = -720;
    (*posBackY) = -715;
    (*spriteEdgeOuts)[0].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[1].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[2].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[3].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[4].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[5].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[6].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[7].setPosition(*posBackX, *posBackY);
    (*posBackX) = -720;
    (*posBackY) = 0;
    (*spriteEdgeOuts)[8].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[9].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[10].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[11].setPosition(*posBackX, *posBackY);
    (*posBackX) = 2879;
    (*posBackY) = 0;
    (*spriteEdgeOuts)[12].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[13].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[14].setPosition(*posBackX, *posBackY);
    (*posBackY) += 720;
    (*spriteEdgeOuts)[15].setPosition(*posBackX, *posBackY);
    (*posBackX) = -720;
    (*posBackY) = 1915;
    (*spriteEdgeOuts)[16].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[17].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[18].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[19].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[20].setPosition(*posBackX, *posBackY);
    (*posBackX) += 720;
    (*spriteEdgeOuts)[21].setPosition(*posBackX, *posBackY);
    //cout << (*spriteEdgeOuts)[11].getPosition().y << endl;
}