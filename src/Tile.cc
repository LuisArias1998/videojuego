#include "Tile.hh"

Tile::Tile(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position) :
Drawable(textureUrl, col, row, width, height, scale, position)
{

}

Tile::~Tile()
{
}

sf::Sprite* Tile::GetSprite() const
{
  return Drawable::GetSprite();
}

void Tile::SetPosition(sf::Vector2f position)
{
  Drawable::SetPosition(position);
}