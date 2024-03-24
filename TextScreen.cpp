#include "TextScreen.h"
void TextScreen::InitBulletText(sf::Font* font, sf::Text* textBullet){
    font->loadFromFile("BigSpace-rPKx.ttf");
    textBullet->setFont(*font);
    textBullet->setFillColor(sf::Color::White);
    textBullet->setCharacterSize(40);
    textBullet->setOutlineColor(sf::Color::Black);
    textBullet->setOutlineThickness(5);
    textBullet->setOrigin(textBullet->getGlobalBounds().width / 2, textBullet->getGlobalBounds().height / 2);
}
void TextScreen::PrintBullet(int* bulletCount, sf::View* viewWindow, sf::Text* textBullet){
    textBullet->setString("Ammo : " + std::to_string(*bulletCount) + "/INF");
    textBullet->setOrigin(textBullet->getGlobalBounds().width / 2, textBullet->getGlobalBounds().height / 2);
    textBullet->setPosition(viewWindow->getCenter().x - viewWindow->getSize().x / 2 + textBullet->getGlobalBounds().width / 2 + 10, viewWindow->getCenter().y -viewWindow->getSize().y / 2 + 15);
}
void TextScreen::InitKillText(sf::Font* font, sf::Text* textKill){
    font->loadFromFile("BigSpace-rPKx.ttf");
    textKill->setFont(*font);
    textKill->setFillColor(sf::Color::White);
    textKill->setCharacterSize(40);
    textKill->setOutlineColor(sf::Color::Black);
    textKill->setOutlineThickness(5);
    textKill->setOrigin(textKill->getGlobalBounds().width / 2, textKill->getGlobalBounds().height / 2);
}
void TextScreen::PrintKill(int* killCount, sf::View* viewWindow, sf::Text* textKill){
    textKill->setString("Kills : " + std::to_string(*killCount));
    textKill->setOrigin(textKill->getGlobalBounds().width / 2, textKill->getGlobalBounds().height / 2);
    textKill->setPosition(viewWindow->getCenter().x - viewWindow->getSize().x / 2 + textKill->getGlobalBounds().width / 2 + 10, viewWindow->getCenter().y - viewWindow->getSize().y / 2 + 55);
}
void TextScreen::InitHealth(sf::Font* font, sf::Text* textHealth){
    font->loadFromFile("BigSpace-rPKx.ttf");
    textHealth->setFont(*font);
    textHealth->setFillColor(sf::Color::Red);
    textHealth->setCharacterSize(40);
    textHealth->setOutlineColor(sf::Color::Black);
    textHealth->setOutlineThickness(5);
    textHealth->setOrigin(textHealth->getGlobalBounds().width / 2, textHealth->getGlobalBounds().height / 2);
}
void TextScreen::PrintHealth(int* health, sf::View* viewWindow, sf::Text* textHealth, sf::RectangleShape* player,
    vector<sf::RectangleShape>* enemys, float* timeHealth, float* timeMaxHealth){
    for (auto &i : *enemys)
    {
        if ((*timeHealth) >= (*timeMaxHealth))
        {
            (*timeHealth) = 0;
            if (player->getGlobalBounds().intersects(i.getGlobalBounds()))
            {
                (*health) -= 5;
            }
            if ((*health) <= 0)
            {
                exit(0);
            }
        }
        else
            (*timeHealth)++;
    }
    textHealth->setString("Health : %" + std::to_string(*health));
    textHealth->setOrigin(textHealth->getGlobalBounds().width / 2, textHealth->getGlobalBounds().height / 2);
    textHealth->setPosition(viewWindow->getCenter().x - viewWindow->getSize().x / 2 + textHealth->getGlobalBounds().width / 2 + 10, viewWindow->getCenter().y - viewWindow->getSize().y / 2 + 95);
}