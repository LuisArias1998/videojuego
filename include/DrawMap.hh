#pragma once
#include<SFML/Graphics.hpp>

class DrawMap : public sf::Drawable, public sf::Transformable
{
protected:
 sf::Texture* texture{};
 sf::RenderWindow* window{};
 sf::VertexArray m_vertices;
 unsigned int width;
 unsigned int height;
    
public:
    DrawMap(const char* textureUrl, sf::RenderWindow*& window, unsigned int width, unsigned int height,
    sf::Vector2u tileSize, const int* tiles);
    ~DrawMap();

     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

