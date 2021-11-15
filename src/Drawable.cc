#include "Drawable.hh"

Drawable::Drawable(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position)
{
  texture = new sf::Texture();
  sprite = new sf::Sprite();

  texture->loadFromFile(textureUrl);
  texture->setSmooth(false);

  sprite->setTexture(*texture);
  sprite->setTextureRect(sf::IntRect(col * width, row * height, width, height));
  sprite->setColor(sf::Color::White);
  sprite->setPosition(*position);
  sprite->setScale(scale, scale);
}

Drawable::~Drawable()
{
}

void Drawable::SetPosition(sf::Vector2f position)
{
  sprite->setPosition(position);
}
sf::Sprite* Drawable::GetSprite() const
{
  return sprite;
}
void Drawable::SetScale(float scale)
{
  sprite->setScale(scale, scale);
}
void Drawable::SetRect(int col, int row, float width, float height)
{
  sprite->setTextureRect(sf::IntRect(col, row, width, height));
}

sf::Vector2f Drawable::GetPosition() const
{
  return sprite->getPosition();
}