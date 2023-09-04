// #ifdef RECTANGLE
// #define RECTANGLE

class Rectangle
{
private:
  double width;
  double height;

public:
  Rectangle(double width, double height) : width(width), height(height){};
  ~Rectangle(){};
  double computeArea() const;
  double getWidth() const;
  double getHeight() const;
  void setWidth(double width);
  void setHeight(double height);
};

// #endif