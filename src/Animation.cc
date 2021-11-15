#include "Animation.hh"

Animation::Animation()
{
}

Animation::Animation(int startFrame, int endFrame, Drawable*& drawable, float delay, int currentAnimation)
{
  this->startFrame = startFrame;
  this->endFrame = endFrame;
  this->drawable = drawable;
  this->delay = delay;
  this->currentAnimation = currentAnimation;
  currentFrame = this->startFrame;
}

Animation::~Animation()
{
}

void Animation::Play(float& deltaTime)
{
  timer += deltaTime;
  if(timer >= delay)
  {
    drawable->SetRect(currentFrame * drawable->GetSprite()->getTextureRect().width,
    currentAnimation * drawable->GetSprite()->getTextureRect().height,
    drawable->GetSprite()->getTextureRect().width,
    drawable->GetSprite()->getTextureRect().height);

    timer = 0;
    if(currentFrame == endFrame)
    {
      currentFrame = startFrame;
    }
    else
    {
      currentFrame++;
    }
  }
}