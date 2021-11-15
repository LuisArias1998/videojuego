#pragma once

#include "Drawable.hh"

class Tile : public Drawable
{
private:
  
public:
  Tile(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position);
  ~Tile();
  sf::Sprite* GetSprite() const;
  void SetPosition(sf::Vector2f);
};