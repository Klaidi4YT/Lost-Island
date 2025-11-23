#include "utils/Camera.hpp"
Camera::Camera(int windowWidth, int windowHeight) {
    view.setSize({(float)windowWidth, (float)windowHeight});
    view.setCenter({(float)windowWidth / 2, (float)windowHeight / 2});
}
void Camera::update(float x, float y) {
    view.setCenter({x, y});
}
void Camera::draw(RenderWindow &window) {
    window.setView(view);
}