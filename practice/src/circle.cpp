#include "circle.h"




Circle::Circle(Point center_, int radius_, const BWColor &color)
        : Shape(color), center(center_), radius(radius_) {}

Circle::Circle(Point center_,  int radius_, const RGBColor &color)
        : Shape(color), center(center_), radius(radius_) {}

void Circle::fill() {

     int x;
     int y;
    for (x = center.x - radius; x <= center.x; x++) {
        for (y = center.y - radius; y <= center.y; y++) {
            if ((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) <= radius * radius) {
                 int xSym = center.x - (x - center.x);
                 int ySym = center.y - (y - center.y);
                m_points.push_back({x, y});
                m_points.push_back({x, ySym});
                m_points.push_back({xSym, y});
                m_points.push_back({xSym, ySym});
            }
        }
    }

}