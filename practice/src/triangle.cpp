#include "triangle.h"
#include <cmath>
#include <chrono>


Triangle::Triangle(Point p1_, Point p2_, Point p3_, const BWColor &color)
        : Shape(color), p1(p1_), p2(p2_), p3(p3_) {}

Triangle::Triangle(Point p1_, Point p2_, Point p3_, const RGBColor &color)
        : Shape(color), p1(p1_), p2(p2_), p3(p3_) {}

void Triangle::fill() {

    iteratePossiblePoints(p1,p2);
    iteratePossiblePoints(p2,p3);
    iteratePossiblePoints(p1,p3);

}

float Triangle::getArea(Point p1_, Point p2_, Point p3_) const {
    return abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)) / 2.0f);
}

bool Triangle::isInside(Point point_to_check) const {
    /* Calculate area of triangle PBC */
    float subTriangleArea1 = getArea(p1, p2, point_to_check);

    /* Calculate area of triangle PAC */
    float subTriangleArea2 = getArea(p2, p3, point_to_check);

    /* Calculate area of triangle PAB */
    float subTriangleArea3 = getArea(p3, p1, point_to_check);

    /* Check if sum of subTriangleArea1, subTriangleArea2 and subTriangleArea3 is same as fullTriangleArea */
    return (fullTriangleArea == subTriangleArea1 + subTriangleArea2 + subTriangleArea3);
}

void Triangle::iteratePossiblePoints(Point firstPoint, Point secondPoint) {
    int maxX = std::max(firstPoint.x,secondPoint.x);
    int maxY = std::max(firstPoint.y,secondPoint.y);
    int minX = std::min(firstPoint.x,secondPoint.x);
    int minY = std::min(firstPoint.y,secondPoint.y);
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (isInside({x, y})) {
                m_points.push_back({x, y});
            }
        }
    }

}