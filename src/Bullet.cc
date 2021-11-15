#include "Bullet.hh"
#include "Animation.hh"

Animation* bulletAnimation{new Animation()};

Bullet::Bullet(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world, b2Vec2 direction) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;
  this->direction = direction;
  rigidbody->SetSensor();

  bulletAnimation = new Animation(0, 7, drawable, 0.08f, 12);
}

Bullet::~Bullet()
{
}

void Bullet::Movement()
{
  rigidbody->Move(b2Vec2(direction.x* moveSpeed, direction.y * moveSpeed));
}

void Bullet::Update(float& deltaTime)
{
  bulletAnimation->Play(deltaTime);
  GameObject::Update(deltaTime);
  Movement();
}
void Bullet::Draw()
{
  GameObject::Draw();
}
