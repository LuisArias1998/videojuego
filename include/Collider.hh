#pragma once
#include "Rectangle.hh"

class Collider : public Rectangle
{
private:

public:
  Collider(int x, int y, int w, int h, sf::Color color, float outlineSize);
  ~Collider();
};