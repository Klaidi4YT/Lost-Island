#include "utils/Decoration.hpp"
Decoration::Decoration(const string &path, Vector2f position, Vector2f scale) : texture(path), sprite(texture) {
    sprite.setPosition(position);
    sprite.setScale(scale);
}
void Decoration::draw(RenderWindow &window) {
    window.draw(sprite);
}
Sprite &Decoration::getSprite() {
    return sprite;
}