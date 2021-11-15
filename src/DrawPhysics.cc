#include "DrawPhysics.hh"

DrawPhysics::DrawPhysics(sf::RenderWindow*& window)
{
    this->window = window;
}

DrawPhysics::~DrawPhysics()
{
}

/// Draw a closed polygon provided in CCW order.
	void DrawPhysics::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
  {

  }

	/// Draw a solid closed polygon provided in CCW order.
	void DrawPhysics::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
  {
    sf::ConvexShape polygon = sf::ConvexShape(vertexCount);

    for(int i = 0; i < vertexCount; i++)
    {
      //polygon.setPoint(i, SFMLDraw::B2VecToSFVec(vertices[i]));
      sf::Vector2f transformedVec = DrawPhysics::B2VecToSFVec(vertices[i]);
      polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y))); // flooring the coords to fix distorted lines on flat surfaces
    }																								   // they still show up though.. but less frequently
    polygon.setOutlineThickness(-1.f);
    polygon.setFillColor(DrawPhysics::GLColorToSFML(color, 60));
    //polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineColor(DrawPhysics::GLColorToSFML(color));

    window->draw(polygon);   
  }

	/// Draw a circle.
	void DrawPhysics::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
  {

  }
	/// DDrawPhysics::raw a solid circle.
	void DrawPhysics::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
  {

  }
	/// DDrawPhysics::raw a line segment.
	void DrawPhysics::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
  {

  }
	/// DDrawPhysics::raw a transform. Choose your own length scale.
	void DrawPhysics::DrawTransform(const b2Transform& xf)
  {

  }
	//DraDrawPhysics::w a point
	void DrawPhysics::DrawPoint (const b2Vec2 &p, float size, const b2Color &color)
  {
    
  }