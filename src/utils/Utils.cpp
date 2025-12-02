#include "utils/Utils.hpp"

void Utils::currentFrame(float &frame, float &time, const int &count) {
    frame += 0.01f * time;
    if (frame >= count) {
        frame = 0;
    }
}
void Utils::loadTextures(vector<Texture>& vec, const string& path, int count) {
    for (int i = 0; i < count; i++) {
        if (!vec[i].loadFromFile(path + to_string(i) + ".png")) {
            cout << "Error loading: " << path << i << ".png\n";
        }
    }
}
void Utils::backgroundSound() {
    music.openFromFile("../assets/utils/sounds/background.mp3");
    music.setLooping(true);
    music.setVolume(30);
}
void Utils::pauseSound() {
    music.pause();
}
void Utils::playSound() {
    music.play();
}
void Utils::drawHitBox(RenderWindow &window, const FloatRect &rect) {
    RectangleShape box;

    box.setSize(rect.size);
    box.setPosition(rect.position);
    box.setFillColor(Color::Transparent);
    box.setOutlineColor(Color::White);
    box.setOutlineThickness(1.0f);
    window.draw(box);
}