#ifndef LOST_ISLAND_CAMERA_HPP
#define LOST_ISLAND_CAMERA_HPP
#include "SFML/Graphics.hpp"
using namespace sf;

class Camera {
private:
    View view;
    float normalZoom = 1;
    float maxZoom = 5;
public:
    Camera(int windowWidth, int windowHeight) {
        view.setSize({(float)windowWidth, (float)windowHeight});
        view.setCenter({(float)windowWidth / 2, (float)windowHeight / 2});
    }
    void update(float x, float y) {
        view.setCenter({x, y});
    }

    void draw(RenderWindow &window) {
        window.setView(view);
    }
};
#endif