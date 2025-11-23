#ifndef LOST_ISLAND_ISLAND_HPP
#define LOST_ISLAND_ISLAND_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
class Island {
private:
    Image image;
    Texture texture;
    Sprite sprite;

public:
    Island(int windowWidth, int windowHeight);

    Image getImage();
    Sprite &getSprite();
    bool isSolid(float x, float y);
    void collision(Sprite &player, Vector2f oldPos);
    void draw(RenderWindow &window);
};
#endif