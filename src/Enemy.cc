#include "Enemy.hh"

Enemy::Enemy(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world, float movespeed) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
    this->moveSpeed = moveSpeed;
    this->position = position;
    rigidbody->SetRotationFreeze(true);
}

Enemy::~Enemy()
{
}

void Enemy::Draw(){
    GameObject::Draw();
}

void Enemy::Update(float& deltaTime){
    GameObject::Update(deltaTime);
}
