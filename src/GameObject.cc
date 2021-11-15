#include "GameObject.hh"

GameObject::GameObject(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world)
{
  this->window = window;
  this->world = world;
  this->scale = scale;

  drawable = new Drawable(textureUrl, col, row, width, height, scale, position);

  rigidbody = new Rigidbody(world, bodyType,
  new b2Vec2(drawable->GetPosition().x, drawable->GetPosition().y),
  width * scale / 2, height * scale / 2, 1, 0, 0,
  b2Vec2(drawable->GetSprite()->getOrigin().x , drawable->GetSprite()->getOrigin().y), 0.f, (void*) this);

  drawable->GetSprite()->setOrigin(width / 2, height / 2);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float& deltaTime)
{
  drawable->SetPosition(rigidbody->GetPositionSFML());
}

void GameObject::Draw()
{
  window->draw(*drawable->GetSprite());
}

const char* GameObject::GetTagName() const
{
  return tagName;
}
void GameObject::SetTagName(const char* tagName)
{
  this->tagName = tagName;
}

sf::Vector2f GameObject::GetPosition()
{
  return rigidbody->GetPositionSFML();
}

void GameObject::Kill(){
  delete this;
}