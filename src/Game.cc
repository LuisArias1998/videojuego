#include "Game.hh"
#include "constance.hh"
#include "Collider.hh"
#include "Character.hh"
#include<iostream>
#include "TileGroup.hh"
#include "InputsSystem.hh"
#include "Enemy.hh"

Collider* collider{new Collider(100, 100, 100, 100, sf::Color::Green, 5.f)};

sf::Clock* timer{new sf::Clock()};
float deltaTime{};
const float playerSpeed{200.f};
const float playerScale{4.f};
const float boxScale{2.f};

Character* character1{};
GameObject* chest1{};
GameObject* chest2{};
Enemy* enemy1{};
DrawMap* walls{};
DrawMap* floorT{};
sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f)); 

TileGroup* tileGroup{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), G_NAME);
  event = new sf::Event();


  //gravity = new b2Vec2(0.f, 9.8f);
  
  //view->reset(sf::FloatRect(0.f,0.f, (float)WINDOW_WIDTH);
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  contactEventManager = new ContactEventManager();
  gameObjects = new std::vector<GameObject*>;

  character1 = new Character("assets/sprites.png", 0, 5, 16.f, 16.f, 
  playerScale, playerSpeed, new sf::Vector2f(100, 100), window, world);

  character1->SetTagName("Player");


  
  chest1 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(350, 350), b2BodyType::b2_staticBody, window, world);
  chest1->SetTagName("chest");

  chest2 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(448, 448), b2BodyType::b2_dynamicBody, window, world);
  chest2->SetTagName("dynamic chest");

  enemy1 = new Enemy( "assets/sprites.png", 0, 1, 16, 16, playerScale,
  new sf::Vector2f(600, 500), b2BodyType::b2_dynamicBody, window, world, playerSpeed);
  enemy1->SetTagName("Enemy");

  //tileGroup = new TileGroup(window, 10, 10, "assets/tile.png", "assets/maps/map1.tg", 16, 16, 4.f);

  walls = new DrawMap("assets/tilemap.png", window, 39, 27, sf::Vector2u(16, 16), wallsTiles);
  floorT = new DrawMap("assets/tilemap.png", window, 39, 27, sf::Vector2u(16, 16), floorTiles);

  gameObjects->push_back(character1);
  gameObjects->push_back(chest1);
  gameObjects->push_back(chest2);
  gameObjects->push_back(enemy1);

}

Game::~Game()
{
}

void Game::Inputs()
{

}

void Game::Draw()
{
   //tileGroup->Draw();
   window->draw(*floorT);
   window->draw(*walls);

  for(auto& gameObject : *gameObjects)
  {
    gameObject->Draw();
  }
  world->DebugDraw();
}

void Game::Render()
{
  window->clear(sf::Color(0, 0, 0, 255));
  Draw();
  window->display();
}
void Game::Init()
{
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(b2Draw::e_shapeBit);
  world->SetContactListener(contactEventManager);

  Update();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

void Game::Update()
{
  while (window->isOpen())
  {
    while (window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }
    deltaTime = timer->getElapsedTime().asSeconds();
    timer->restart();

    UpdatePhysics();

    for(auto& gameObject : *gameObjects)
    {
      gameObject->Update(deltaTime);
    }
  window->setView(view);
  view.setCenter(character1->GetPosition());
  Render();
  }

  delete window;
  delete event;
}




