#ifndef LOST_ISLAND_OCEAN_HPP
#define LOST_ISLAND_OCEAN_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Ocean {
private:
    Texture texture;
    Sprite sprite;
public:
    Ocean(int windowWidth, int windowHeight) : texture("../assets/world/ocean.png"), sprite(texture) {
        float scaleX = (float)windowWidth  / texture.getSize().x;
        float scaleY = (float)windowHeight / texture.getSize().y;
        sprite.setScale({scaleX, scaleY});
    }

    void draw(RenderWindow& window) {
        window.draw(sprite);
    }
    void update(float x, float y) {
        sprite.setPosition({x, y});
    }
    Sprite getSprite() {
        return sprite;
    }
};
#endif