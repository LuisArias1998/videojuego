#include "Collider.hh"

Collider::Collider(int x, int y, int w, int h, sf::Color color, float outlineSize) : Rectangle(x, y, w, h)
{
  rectShape->setFillColor(sf::Color::Transparent);
  rectShape->setOutlineColor(color);
  rectShape->setOutlineThickness(outlineSize);
}

Collider::~Collider()
{
  
}