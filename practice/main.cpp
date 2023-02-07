#include "matrix.h"
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <rectangle.h>
#include <circle.h>
#include "triangle.h"
#include <chrono>

using Time = std::chrono::high_resolution_clock;

using ns = std::chrono::nanoseconds;

void GenMatrix(Matrix &mat, int min = 0, int max = 255) {
    for (size_t r = 0; r < mat.getRows(); ++r) {
        for (size_t c = 0; c < mat.getCols(); ++c) {
            for (size_t ch = 0; ch < mat.getChannels(); ++ch) {
                mat.at(r, c, ch) = min + std::rand() % (max - min + 1);
            }
        }
    }
}

void draw_mushroom_teacher_test() {
    Time::time_point start = Time::now();

    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(2000, 2000, 255);
    BWColor bwColor(capColor);
    Circle cap({1000, 1000}, 700, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 700}, 2000, 1000, bwColor);
    Rectangle background2({800, 1300}, 400, 200, bwColor);
    bwColor.changeColor(stipeColor);
    Triangle stipe({1000, 350}, {1200, 1500}, {800, 1500}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({800, 350}, 400, 350, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({1000, 1500}, 200, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;

    std::cout << "Execution time: " << duration << " ms" << std::endl;
    bw.display();
}

void draw_mushroom_test() {
    Time::time_point start = Time::now();
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(200, 200, 255);
    BWColor bwColor(capColor);
    Circle cap({100, 100}, 70, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 70}, 200, 100, bwColor);
    Rectangle background2({80, 130}, 40, 20, bwColor);
    bwColor.changeColor(stipeColor);
    Triangle stipe({100, 35}, {120, 150}, {80, 150}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({80, 35}, 40, 35, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({100, 150}, 20, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;

    std::cout << "Execution time: " << duration << " ms" << std::endl;
    bw.display();
}

void draw_house_teacher_test() {
    Time::time_point start = Time::now();
    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 1500}, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({50, 50}, 300, rgbColor);
    Triangle ray1({360, 50}, {550, 30}, {550, 70}, rgbColor);
    Triangle ray2({270, 270}, {420, 360}, {390, 400}, rgbColor);
    Triangle ray3({50, 360}, {30, 550}, {70, 550}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({600, 900}, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({1300, 550}, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({560, 900}, {1100, 500}, {1640, 900}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({1400, 1350}, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({1535, 1500}, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({700, 950}, 300, 350, rgbColor);
    Rectangle window2({1200, 950}, 300, 350, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.display();
    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;

    std::cout << "Execution time: " << duration << " ms" << std::endl;
}

void draw_house_test() {
    Time::time_point start = Time::now();
    RGBMatrix rgb(200, 200, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 200, 150, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 150}, 200, 200, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({5, 5}, 30, rgbColor);
    Triangle ray1({36, 5}, {55, 3}, {55, 7}, rgbColor);
    Triangle ray2({27, 27}, {42, 36}, {39, 40}, rgbColor);
    Triangle ray3({5, 36}, {3, 55}, {7, 55}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({60, 90}, 100, 80, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({130, 55}, 10, 20, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({56, 90}, {110, 50}, {164, 90}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({140, 135}, 15, 30, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({153, 150}, 2, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({70, 95}, 30, 35, rgbColor);
    Rectangle window2({120, 95}, 30, 35, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.display();
    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;

    std::cout << "Execution time: " << duration << " ms" << std::endl;
}

void draw_plane() {
    Time::time_point start = Time::now();
    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 2000, 2000, rgbColor);
    rgbColor.changeColor(112, 112, 112);
    Triangle front({100, 1500}, {500, 1500}, {500, 1100}, rgbColor);
    Rectangle body({500, 1100}, 1200, 400, rgbColor);
    rgbColor.changeColor(199, 189, 189);
    Triangle wing1({800, 1100}, {1200, 1100}, {1200, 700}, rgbColor);
    Triangle wing2({800, 1500}, {1200, 1500}, {1200, 2000}, rgbColor);
    Triangle tail({1300, 1100}, {1700, 1100}, {1700, 700}, rgbColor);
    rgbColor.changeColor(7, 24, 173);
    Circle window1({700, 1300}, 100, rgbColor);
    Circle window2({1000, 1300}, 100, rgbColor);
    Circle window3({1300, 1300}, 100, rgbColor);


    rgb.draw(sky);
    rgb.draw(front);
    rgb.draw(body);
    rgb.draw(wing1);
    rgb.draw(wing2);
    rgb.draw(tail);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.draw(window3);

//    rgb.display();

    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;


}

int main() {
    Time::time_point start = Time::now();
    for(int i = 0; i < 10; i++){
        draw_plane();
    }
    Time::time_point end = Time::now();

    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;

    std::cout << "Execution time: " << duration/10 << " ms" << std::endl;

    return 0;
}