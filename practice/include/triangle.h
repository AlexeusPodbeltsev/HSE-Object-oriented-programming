#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle();

    Triangle(Point p1_, Point p2_, Point p3_, const BWColor &color);

    Triangle(Point p1_, Point p2_, Point p3_, const RGBColor &color);

    void fill() override;

private:
    Point p1;
    Point p2;
    Point p3;
    float fullTriangleArea = getArea(p1, p2, p3);
    float getArea(Point p1_, Point p2_, Point p3_) const;
    bool isInside(Point point_to_check)const;
    void iteratePossiblePoints(Point firstPoint, Point secondPoint);
};


#endif //TRIANGLE_H
