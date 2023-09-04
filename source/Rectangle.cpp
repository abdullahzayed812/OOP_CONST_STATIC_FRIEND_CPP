#include "../header/Rectangle.h"

// const function -> Didn't change members in it's class.
double Rectangle::computeArea() const
{
  return this->width * this->height;
}
double Rectangle::getWidth() const
{
  return this->width;
}

// const function -> can only access object data.
double Rectangle::getHeight() const
{
  return this->width;
}

void Rectangle::setWidth(double width)
{
  this->width = width;
}

void Rectangle::setHeight(double height)
{
  this->height = height;
}