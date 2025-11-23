#include "utils/DebugOverlay.hpp"

DebugOverlay::DebugOverlay() : font("../assets/utils/fonts/arial.ttf"), text(font) {
    text.setCharacterSize(18);
    text.setFillColor(Color::White);
    text.setPosition(Vector2f(10, 10));
    text.setScale(Vector2f(1, 1));
}
void DebugOverlay::setInfo(Sprite &player, float speed) {
    stringstream overlay;
    overlay << fixed << setprecision(2)
       << "Player X: " << player.getPosition().x << endl
       << "Player Y: " << player.getPosition().y << endl
       << "Speed: " << speed << endl;

    text.setString(overlay.str());
}
void DebugOverlay::draw(RenderWindow &window) {
    window.draw(text);
}