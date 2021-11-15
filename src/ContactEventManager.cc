#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>
#include<string>

ContactEventManager::ContactEventManager()
{
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  std::string a = actorA->GetTagName();
  std::string b = actorB->GetTagName();

  if(actorA && actorB )
  {
    if(!(a == "Player" && b == "Bullet")){
      std::cout << "c " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
      std::cout << "collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    }
    
  }
}
void ContactEventManager::EndContact(b2Contact *contact)
{
  std::cout << "mmm patas" << std::endl;
}