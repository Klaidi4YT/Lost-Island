#include "utils/Screen.hpp"
Screen::Screen() : buffer("../assets/utils/sounds/screen.mp3"), sound(buffer) {
}
void Screen::createScreen(RenderWindow &window) {
    sound.play();
    texture.resize(window.getSize());
    texture.update(window);

    image = texture.copyToImage();
    time_t now = time(nullptr);
    image.saveToFile("../screens/screenshot_" + to_string(now) + ".png");
}