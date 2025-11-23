#include "world/Ocean.hpp"

Ocean::Ocean(int windowWidth, int windowHeight) : texture("../assets/world/ocean.png"), sprite(texture) {
    float scaleX = (float)windowWidth  / texture.getSize().x;
    float scaleY = (float)windowHeight / texture.getSize().y;
    sprite.setScale({scaleX, scaleY});
}
void Ocean::update(float x, float y) {
    sprite.setPosition({x,y});
}
void Ocean::draw(RenderWindow &window) {
    window.draw(sprite);
}

Sprite &Ocean::getSprite() {
    return sprite;
}
