#include "world/Island.hpp"

#include "world/Ocean.hpp"

Island::Island(int windowWidth, int windowHeight) : image("../assets/world/island.png"), texture(image), sprite(texture) {
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.getCenter());
    float width = (float)windowWidth / 2;
    float height = (float)windowHeight / 2;
    sprite.setPosition({width, height});
    sprite.setScale({2.5f, 2.5f});
}
bool Island::isSolid(float x, float y) {
    Vector2f localPos = sprite.getInverseTransform().transformPoint({x, y});

    if (localPos.x < 0 || localPos.y < 0 ||
        localPos.x >= image.getSize().x || localPos.y >= image.getSize().y) {
        return false;
        }

    return image.getPixel(Vector2u(localPos.x, localPos.y)).a > 20;
}
void Island::collision(Sprite &player, Vector2f oldPos) {
    FloatRect bounds = player.getGlobalBounds();

    float feetY = bounds.position.y + bounds.size.y - 60.0f;
    float offset = bounds.size.x / 6.0f;

    float leftFootX = bounds.position.x + (bounds.size.x / 2.0f) - offset;
    float rightFootX = bounds.position.x + (bounds.size.x / 2.0f) + offset;

    if (!isSolid(leftFootX, feetY) || !isSolid(rightFootX, feetY)) {
        player.setPosition(oldPos);
    }
}
void Island::draw(RenderWindow &window) {
    window.draw(sprite);
}
Image Island::getImage() {
    return image;
}
Sprite &Island::getSprite() {
    return sprite;
}