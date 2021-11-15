#include "Rectangle.hh"

Rectangle::Rectangle(int x, int y, int w, int h,  sf::Color color)
{
  rectShape = new sf::RectangleShape(sf::Vector2f(w, h));
  rectShape->setPosition(sf::Vector2f(w, h));
  rectShape->setFillColor(color);

}

Rectangle::Rectangle(int x, int y, int w, int h)
{
  rectShape = new sf::RectangleShape(sf::Vector2f(w, h));
  rectShape->setPosition(sf::Vector2f(w, h));
  //rectShape->setFillColor(sf::Color::Transparent);
  //rectShape->setOutlineThickness(5.f);
}

Rectangle::~Rectangle()
{
}

sf::RectangleShape* Rectangle::GetShape() const
{
  return rectShape;
}