#pragma once
#include<SFML/Graphics.hpp>
#include "Drawable.hh"

class Animation
{
private:
  float delay{};
  int startFrame{};
  int endFrame{};
  Drawable* drawable;
  float timer{};
  int currentFrame{};
  int currentAnimation{};
public:
  Animation();
  Animation(int startFrame, int endFrame, Drawable*& drawable, float delay, int currentAnimation);
  ~Animation();

  void Play(float& deltaTime);
};