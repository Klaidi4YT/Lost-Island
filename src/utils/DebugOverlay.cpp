#include "utils/DebugOverlay.hpp"

DebugOverlay::DebugOverlay() : font("../assets/utils/fonts/arial.ttf"), text(font) {
    text.setCharacterSize(18);
    text.setFillColor(Color::White);
    text.setPosition(Vector2f(10, 10));
    text.setScale(Vector2f(1, 1));
}
void DebugOverlay::FPS(Clock &fpsClock) {
    frames++;
    if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
        currentFps = frames;
        frames = 0;
        fpsClock.restart();
    }
}

void DebugOverlay::setInfo(Sprite &player, float speed) {
    stringstream overlay;
    overlay << fixed << setprecision(2)
       << "Player X: " << player.getPosition().x << endl
       << "Player Y: " << player.getPosition().y << endl
       << "Speed: " << speed << endl
       << "FPS: " << currentFps << endl
       << "     " << endl
       << "F1 - Hide mouse cursor" << endl
       << "F2 - Create a screenshot" << endl
       << "F3 - Open DebugOverlay" << endl
       << "F4 - Enable hitboxes" << endl
       << "F5 - Pause background music" << endl
       << "Left Alt + F4 - Close Game";

    text.setString(overlay.str());
}
void DebugOverlay::draw(RenderWindow &window) {
    window.draw(text);
}