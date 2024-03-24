#include "WindowScreen.h"
void WindowScreen::setWindow(int* width, int* height){
    screenWidth = *width;
    screenHeight = *height;
}
void WindowScreen::setView(sf::RenderWindow* window, sf::View* viewWindow, sf::RectangleShape* player){
    
    viewWindow->setCenter(player->getPosition());
    viewWindow->setSize(sf::Vector2f(window->getSize()));
}