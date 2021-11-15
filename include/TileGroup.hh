#pragma once
#include<iostream>
#include<fstream>
#include "Tile.hh"

class TileGroup
{
private:
  std::ifstream* reader{};
  int cols{}, rows{};
  const char* texture{};
  const char* tgFile{};
  std::vector<Tile*>* tiles;
  sf::RenderWindow* window{};

  int tileWidth{}, tileHeight{};
  float tileScale{};
public:
  TileGroup(sf::RenderWindow*& window, int cols, int rows, const char* texture, const char* tgFile, int tileWidth, int tileHeight, float tileScale);
  ~TileGroup();
  void Draw();
  void GenerateGroup();
};