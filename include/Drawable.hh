#pragma once

#include<SFML/Graphics.hpp>

class Drawable
{
protected:
  sf::Texture* texture{};
  sf::Sprite* sprite{};
public:
  Drawable(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position);
  ~Drawable();

  void SetPosition(sf::Vector2f position);
  sf::Sprite* GetSprite() const;
  void SetScale(float scale);
  void SetRect(int col, int row, float width, float height);
  sf::Vector2f GetPosition() const;
};