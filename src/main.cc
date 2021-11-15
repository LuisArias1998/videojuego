#include<iostream>
#include"Game.hh"

int main(){
    
    //sf::RectangleShape* rectangle{new sf::RectangleShape(sf::Vector2f(120, 50))};
    //rectangle->setSize(sf::Vector2f(100,100));
    //rectangle->setFillColor(sf::Color(255,0,0,255));
    //window->draw(*rectangle);
    
    Game *game {new Game};
    game->Init();

    delete game;
    return EXIT_SUCCESS;
}