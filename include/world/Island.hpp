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
    Island(int windowWidth, int windowHeight) : image("../assets/world/island.png"), texture(image), sprite(texture) {
        FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.getCenter());
        float width = (float)windowWidth / 2;
        float height = (float)windowHeight / 2;
        sprite.setPosition({width, height});
        sprite.setScale({2.5f, 2.5f});
    }
    const Image& getImage() const {
        return image;
    }
    const Sprite& getSprite() const {
        return sprite;
    }


    void draw(RenderWindow &window) {
        window.draw(sprite);
    };
};
#endif