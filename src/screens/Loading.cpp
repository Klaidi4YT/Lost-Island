#include "screens/Loading.hpp"

Loading::Loading(int windowWidth, int windowHeight) : texture("../assets/utils/loading.png"), sprite(texture)  {
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.getCenter());
    float width = (float)windowWidth / 2;
    float height = (float)windowHeight / 2;
    sprite.setPosition({width, height});
    sprite.setScale({1.5, 1.5});
}
void Loading::setLogo(RenderWindow &window) {
    Image logo("../assets/utils/logo.png");
    window.setIcon(logo.getSize(), logo.getPixelsPtr());
}
void Loading::run(RenderWindow &window) {
    Clock clock;

    float fadeInTime = 2.0f;
    float holdTime = 1.0f;
    float fadeOutTime = 2.0f;

    while (window.isOpen()) {

        float t = clock.getElapsedTime().asSeconds();

        if (t > fadeInTime + holdTime + fadeOutTime)
            break;

        while (const auto event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        float alpha = 255.0f;

        if (t < fadeInTime) {
            alpha = (t / fadeInTime) * 255.0f;
        }
        else if (t < fadeInTime + holdTime) {
            alpha = 255.0f;
        }
        else {
            float outT = t - (fadeInTime + holdTime);
            alpha = 255.0f * (1.0f - (outT / fadeOutTime));
        }

        if (alpha < 0) alpha = 0;
        if (alpha > 255) alpha = 255;

        Color color = sprite.getColor();
        color.a = (uint8_t)alpha;
        sprite.setColor(color);

        window.clear(Color::Black);
        window.draw(sprite);
        window.display();
    }
}