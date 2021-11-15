#pragma once
#include<SFML/Graphics.hpp>

class Rectangle
{
protected:
  sf::RectangleShape* rectShape{};
public:
  Rectangle(int x, int y, int w, int h, sf::Color color);
  Rectangle(int x, int y, int w, int h);
  ~Rectangle();
  sf::RectangleShape* GetShape() const;
};