#pragma once

#include "Rigidbody.hh"
#include "SFML/Graphics.hpp"
#include "Drawable.hh"

class GameObject
{
protected:
  Drawable* drawable{};
  
  sf::CircleShape* pivotPoint{};
  sf::RenderWindow* window{};
  b2World* world{};
  float scale{};
  const char* tagName{};
public:
  Rigidbody* rigidbody{};
  GameObject(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world);
  ~GameObject();

  const char* GetTagName() const;
  void SetTagName(const char* tagName);

  virtual void Update(float& deltaTime);
  virtual void Draw();

  sf::Vector2f GetPosition();
  void Kill();
};