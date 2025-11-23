#ifndef LOST_ISLAND_CAMERA_HPP
#define LOST_ISLAND_CAMERA_HPP
#include "SFML/Graphics.hpp"
using namespace sf;

class Camera {
private:
    View view;
public:
    Camera(int windowWidth, int windowHeight);
    void update(float x, float y);
    void draw(RenderWindow &window);
};
#endif