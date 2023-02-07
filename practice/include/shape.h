#ifndef SHAPE_H
#define SHAPE_H
#include "vector"
#include "color.h"
#include "bw_color.h"
#include "rgb_color.h"

struct Point{
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

class Shape{
public:
    virtual ~Shape(){delete m_color;}
    std::vector<Point> getPoints() const{return m_points;}
    const Color* getColor() const {return m_color;}
    virtual void fill() = 0;
protected:
    Shape(const BWColor& color){m_color = new BWColor(color);}
    Shape(const RGBColor& color){m_color = new RGBColor(color);}
protected:
    std::vector<Point> m_points;
    Color* m_color;
};

#endif //SHAPE_H
