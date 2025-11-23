#ifndef LOST_ISLAND_OCEAN_HPP
#define LOST_ISLAND_OCEAN_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Ocean {
private:
    Texture texture;
    Sprite sprite;
public:
    Ocean(int windowWidth, int windowHeight);
    void update(float x, float y);
    void draw(RenderWindow &window);
    Sprite &getSprite();
};
#endif