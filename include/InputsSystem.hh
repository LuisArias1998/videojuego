#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

struct InputsSystem
{


    static sf::Vector2f GetAxis()
    {

        sf::Vector2f axis{};

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) |
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            axis.x=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) |
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            axis.x=-1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) |
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            axis.y=-1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) |
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            axis.y=1;
        }

        return axis;
    }

    static bool isPressed()
    {
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    }

    static sf::Vector2f GetAxisJoystick()
    {
         sf::Vector2f axis{};

        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

        if(x>=50){
            axis.x=1;
        }
        if(x<=-50){
            axis.x=-1;
        }
        if(y>=50){
            axis.y=1;
        }
        if(y<=-50){
            axis.y=-1;
        }

        //std::cout << "ENTRA AQUI";
        //std::cout << "AXIS EN X: " << x <<std:: endl;
        //std::cout << "AXIS EN Y: " << y;
        //if(sf::Joystick::

        return axis;
    }
};
