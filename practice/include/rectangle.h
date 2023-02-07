#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape{
public:
    Rectangle();
    Rectangle(Point lt_,  int width_,  int height_, const BWColor& color);
    Rectangle(Point lt_,  int width_,  int height_, const RGBColor& color);

    void fill() override;
private:
    Point lt;
     int width;
     int height;

};

#endif //RECTANGLE_H
