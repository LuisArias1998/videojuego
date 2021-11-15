#include "Rigidbody.hh"

Rigidbody::Rigidbody(){}
Rigidbody::Rigidbody(b2World*& world, b2BodyType bodyType, b2Vec2* position, float width, float height,
float density, float friction, float restitution, b2Vec2 origin, float angle, void* userData)
{
  this->world = world;
  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  bodyDef->position = *position;
  body = world->CreateBody(bodyDef);

  polygonShape = new b2PolygonShape();
  polygonShape->SetAsBox(width, height, origin, angle);

  fixtureDef = new b2FixtureDef();
  fixtureDef->shape = polygonShape;
  fixtureDef->density = density;
  fixtureDef->restitution = restitution;

  fixture = body->CreateFixture(fixtureDef);

  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(userData);
}

Rigidbody::~Rigidbody()
{
}

b2Body* Rigidbody::GetBody() const
{
  return body;
}

sf::Vector2f Rigidbody::GetPositionSFML() const
{
  return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}

void Rigidbody::Move(b2Vec2 direction)
{
    body->SetLinearVelocity(direction);
}

void Rigidbody::SetRotationFreeze(bool freezeRotation)
{
  body->SetFixedRotation(freezeRotation);
}

void Rigidbody::SetSensor()
{
  fixture->SetSensor(true);
}

void Rigidbody::EraseBody(){
  world->DestroyBody(body);
}