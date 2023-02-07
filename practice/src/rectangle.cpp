#include "rectangle.h"



Rectangle::Rectangle(Point lt_, int width_, int height_, const BWColor &color)
        : Shape(color), lt(lt_), width(width_), height(height_) {}

Rectangle::Rectangle(Point lt_, int width_, int height_, const RGBColor &color)
        : Shape(color), lt(lt_), width(width_), height(height_) {}

void Rectangle::fill() {
    for (int w = lt.x; w < lt.x + width; ++w) {
        for (int h = lt.y; h < lt.y + height; ++h) {
            m_points.push_back({w, h});
        }
    }
}