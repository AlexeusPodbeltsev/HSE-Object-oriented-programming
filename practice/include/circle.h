#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class Circle : public Shape{
public:
    Circle();
    Circle(Point center_,  int radius_, const BWColor& color);
    Circle(Point center_,  int radius_, const RGBColor& color);

    void fill() override;
private:
    Point center;
    int radius;
};

#endif //CIRCLE_H
