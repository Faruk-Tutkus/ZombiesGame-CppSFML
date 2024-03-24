#include "GameEngine.h"
GameEngine::GameEngine()
{
    srand(time(NULL));
    this->InitWindow();
    WindowScreen::setWindow(&screenWidht,&screenHeight);
    Player::InitPlayer(&player);
    Bullet::InitBullet(&bullet);
    BackGround::InitBackGround(&textureBackGround, &spriteBackGround);
    BackGround::AddBackGround(&spriteBackGround, &spriteBackGrounds);
    BackGround::RenderBackGround(&spriteBackGround,&spriteBackGrounds, &posBackX, &posBackY);
    TextScreen::InitBulletText(&font, &textBullet);
    BackGround::InitEdgeOut(&textureEdgeOut, &spriteEdgeOut);
    BackGround::AddEdgeOut(&spriteEdgeOut, &spriteEdgeOuts);
    BackGround::RenderEdgeOut(&spriteEdgeOut, &spriteEdgeOuts, &posBackX, &posBackY);
    Animation::InitPlayerAnimation(&texturePlayer, &spritePlayer);
    Enemy::InitEnemy(&enemy);
    Animation::InitEnemyAnimation(&textureEnemy, &spriteEnemy);
    TextScreen::InitKillText(&font, &textKill);
    TextScreen::InitHealth(&font,&textHealth);
    WindowUpdate();
}
void GameEngine::InitWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "SFML", sf::Style::Fullscreen);
    this->event = new sf::Event;
    this->screenWidht = this->window->getSize().x;
    this->screenHeight = this->window->getSize().y;
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(true);
}
void GameEngine::WindowUpdate(){
    while (this->window->isOpen())
    {   
        UpdateEvent();
        
        Player::MovePlayer(&player);
        Bullet::MoveBullet(&bullets, &bulletSpeedX, &bulletSpeedY);
        Bullet::SpawnBullet(&bullet, &bullets, &player, window, &bulletSpeedX, &bulletSpeedY, &bulletCount, &timeSpawnBullet, &timeMaxSpawnBullet);
        Bullet::DeleteBullet(&bullets, &bulletSpeedX, &bulletSpeedY);
        Bullet::LoadBullet(&bulletCount, &timeLoadBullet, &timeMaxLoadBullet);
        WindowScreen::setView(window, &viewWindow, &player);
        TextScreen::PrintBullet(&bulletCount, &viewWindow, &textBullet);
        Enemy::SpawnEnemy(&enemy, &enemys, &timeSpawnEnemy, &timeMaxSpawnEnemy);
        Enemy::MoveEnemy(&enemys, &player, &speedEnemyX, &speedEnemyY);
        Enemy::DeleteEnemy(&enemys,&bullets,&speedEnemyX,&speedEnemyY,&bulletSpeedX,&bulletSpeedY, &enemysAnimations,&killCount);
        Animation::AnimationPlayer(&player,&spritePlayer,window);
        Animation::SpawnEnemyAnimation(&enemysAnimations, &spriteEnemy, &timeSpawnEnemy, &timeMaxSpawnEnemy);
        Animation::AnimationEnemy(&enemys, &enemysAnimations, &player);
        TextScreen::PrintKill(&killCount,&viewWindow,&textKill);
        TextScreen::PrintHealth(&health,&viewWindow,&textHealth,&player,&enemys,&timeHealth,&timeMaxHealth);
        //cout << bullets.size() << endl;
        RenderWindow();
    }
}
void GameEngine::UpdateEvent(){
    while (this->window->pollEvent(*(this->event)))
    {       
        switch (this->event->type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->window->close();
            }
        }
    }
}
void GameEngine::RenderWindow(){
    this->window->clear();
    
    this->window->setView(viewWindow);
    
    for (auto &i : this->spriteBackGrounds)
    {
        this->window->draw(i);
    }
    for (auto &i : spriteEdgeOuts)
    {
        this->window->draw(i);
    }
    /*
    for (auto &i : this->enemys)
    {
        this->window->draw(i);
    }
    */
    for (auto &i : this->bullets)
    {
        this->window->draw(i);
    }
    for (auto &i : this->enemysAnimations)
    {
        this->window->draw(i);
    }
    this->window->draw(textBullet);
    this->window->draw(textKill);
    this->window->draw(textHealth);
    //this->window->draw(player);
    this->window->draw(spritePlayer);
    this->window->display();
}
GameEngine::~GameEngine()
{    
    delete window;
    delete event;
}