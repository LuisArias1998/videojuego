#pragma once
#include<SFML/Graphics.hpp>
#include "GameObject.hh"
#include<box2d/box2d.h>

class Bullet : public GameObject
{
private:
  b2Vec2 direction{};
  float moveSpeed{};

  void Movement();
public:
  Bullet(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
  sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world, b2Vec2 direction);
  ~Bullet();

  void Update(float& deltaTime) override;
  void Draw() override;
};