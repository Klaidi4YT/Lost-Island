#ifndef LOST_ISLAND_DECORATION_HPP
#define LOST_ISLAND_DECORATION_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Decoration {
    private:
    Texture texture;
    Sprite sprite;
    public:
    Decoration(const string &path, Vector2f position = {0,0}, Vector2f scale = {1,1});
    Sprite &getSprite();
    void draw(RenderWindow &window);
};
#endif