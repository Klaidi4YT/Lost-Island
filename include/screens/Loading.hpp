#ifndef LOST_ISLAND_LOADING_HPP
#define LOST_ISLAND_LOADING_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
class Loading {
private:
    Texture texture;
    Sprite sprite;

public:
    Loading(int windowWidth, int windowHeight);
    void setLogo(RenderWindow &window);
    void run(RenderWindow &window);
};
#endif