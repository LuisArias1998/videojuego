#include "Character.hh"
#include "InputsSystem.hh"
#include "Animation.hh"
#include <stack>
#include <iostream>
#include "Bullet.hh"

Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

Character::Character(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;
  this->bullets = new std::vector<GameObject*>();
  this->position = position;

  rigidbody->SetRotationFreeze(true);

  idleAnimation = new Animation(0, 5, drawable, 0.05f, 5);
  runAnimation = new Animation(0, 5, drawable, 0.08f, 6);
}

Character::~Character()
{
}

void Character::Draw()
{
  GameObject::Draw();
  for(auto& bullet : *bullets)
  {
    bullet->Draw();
  }
}

void Character::Update(float& deltaTime)
{
  GameObject::Update(deltaTime);

  for(auto& bullet : *bullets)
  {
    bullet->Update(deltaTime);
  }

  FlipSprite();
  Move();

  if(std::abs(InputsSystem::GetAxis().x) || std::abs(InputsSystem::GetAxis().y))
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }
  if(InputsSystem::GetAxis().x != 0.f || InputsSystem::GetAxis().y != 0.f)
  {
    lastAxis = InputsSystem::GetAxis();
  }
  if(InputsSystem::isPressed())
  {
    if(isShooting==false){
      isShooting = true;
      std::cout << "create bullets" << std::endl;
      CreateBullet();
    }
  }
  else
  {
    //std::cout << "not create bullets" << std::endl;
    isShooting = false;
  }

  if(bullets->size()!=0){
    //std::cout << "posaber bullets" << std::endl;
    DeleteBullet();
  }

}

void Character::FlipSprite()
{
    drawable->GetSprite()->setScale(InputsSystem::GetAxis().x > 0 ? scale :
    InputsSystem::GetAxis().x < 0 ? -scale :
    drawable->GetSprite()->getScale().x, drawable->GetSprite()->getScale().y);
}

void Character::Move()
{
  rigidbody->Move(b2Vec2(InputsSystem::GetAxis().x * moveSpeed, InputsSystem::GetAxis().y * moveSpeed));
}


sf::Sprite* Character::GetSprite() const
{
  return drawable->GetSprite();
}

void Character::CreateBullet()
{
  Bullet* b = new Bullet("assets/BulletSprites.png", 0, 12, 8.f, 8.f, 4.f, 500.f, new sf::Vector2f(GetPosition()), 
  window, world, b2Vec2(lastAxis.x, lastAxis.y));
  b->SetTagName("Bullet");
  bullets->push_back(b);
}

void Character::DeleteBullet()
{
  //std::cout << "entra" << std::endl;sdd
  std::vector<GameObject*>* bullet2 = new std::vector<GameObject*>();
  std::stack<int>* aber = new std::stack<int>();
  aber = {};

  int size = bullets->size();

  for( int i = 0; i < size; i++ ){
    if (bullets->at(i)->GetPosition().y <=50 || bullets->at(i)->GetPosition().y >= 550
      ||  bullets->at(i)->GetPosition().x <= 50 || bullets->at(i)->GetPosition().x >= 782 ){
      world->DestroyBody(bullets->at(i)->rigidbody->GetBody());
      //bullets->at(i)->rigidbody->EraseBody();
      bullets->erase(bullets->begin());
      //bullets->pop_back();
      break;
    }
  }
}
 
