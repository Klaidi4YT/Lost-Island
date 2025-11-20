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
    Image getImage() {
        return image;
    }
    Sprite getSprite() {
        return sprite;
    }
    bool isSolid(float x, float y) {
        Vector2f localPos = sprite.getInverseTransform().transformPoint({x, y});

        if (localPos.x < 0 || localPos.y < 0 ||
            localPos.x >= image.getSize().x || localPos.y >= image.getSize().y) {
            return false;
            }

        return image.getPixel(Vector2u(localPos.x, localPos.y)).a > 20;
    }

    void collision(Sprite &player, Vector2f oldPos) {
        FloatRect bounds = player.getGlobalBounds();

        float feetY = bounds.position.y + bounds.size.y - 60.0f;
        float offset = bounds.size.x / 6.0f;

        float leftFootX = bounds.position.x + (bounds.size.x / 2.0f) - offset;
        float rightFootX = bounds.position.x + (bounds.size.x / 2.0f) + offset;

        if (!isSolid(leftFootX, feetY) || !isSolid(rightFootX, feetY)) {
            player.setPosition(oldPos);
        }
    }
    void draw(RenderWindow &window) {
        window.draw(sprite);
    };
};
#endif