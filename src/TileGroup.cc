#include "TileGroup.hh"

TileGroup::TileGroup(sf::RenderWindow*& window, int cols, int rows, const char* texture, const char* tgFile, int tileWidth, int tileHeight, float tileScale)
{
  this->window = window;
  tiles = new std::vector<Tile*>();
  reader = new std::ifstream();
  this->cols = cols;
  this->rows = rows;
  this->texture = texture;
  this->tgFile = tgFile;
  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight; 
  this->tileScale = tileScale;
  GenerateGroup();
}

TileGroup::~TileGroup()
{

}

void TileGroup::GenerateGroup()
{
  /*tiles->push_back(new Tile("assets/tile.png", 0, 2, 16.f, 16.f, 4.f, new sf::Vector2f(16*0, 0)));
  tiles->push_back(new Tile("assets/tile.png", 1, 2, 16.f, 16.f, 4.f, new sf::Vector2f(16*1, 0)));
  tiles->push_back(new Tile("assets/tile.png", 2, 2, 16.f, 16.f, 4.f, new sf::Vector2f(16*2, 0)));*/

  reader->open(tgFile);
  for(int y{}; y < rows; y++)
  {
    for(int x{}; x < cols; x++)
    {
      int coordX{};
      int coordY{};

      *reader >> coordX;
      *reader >> coordY;

      tiles->push_back(new Tile(texture, coordX, coordY, tileWidth, tileHeight, tileScale,
      new sf::Vector2f(tileWidth * tileScale * x, tileHeight * tileScale * y)));
    }
  }
  reader->close();
}

void TileGroup::Draw()
{
  for(auto& tile : *tiles)
  {
    window->draw(*tile->GetSprite());
  }
}