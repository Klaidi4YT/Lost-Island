#include <SFML/Graphics.hpp>
#include "world/Ocean.hpp"
#include "world/Island.hpp"
#include "screens/Loading.hpp"
#include "utils/Camera.hpp"
#include "utils/DebugOverlay.hpp"
#include "entities/Player.hpp"
using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

int main() {
    RenderWindow window(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Lost Island");
    window.setFramerateLimit(144);
    Loading loading(WINDOW_WIDTH, WINDOW_HEIGHT);
    loading.setLogo(window);
    loading.run(window);
    Ocean ocean(WINDOW_WIDTH, WINDOW_HEIGHT);
    Island island(WINDOW_WIDTH, WINDOW_HEIGHT);
    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT);
    DebugOverlay debugOverlay;
    Player player(island.getSprite().getGlobalBounds().getCenter());


    Clock clock;
    bool showDebug = false;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        while (const optional event = window.pollEvent()){
            if (event->is<Event::Closed>()) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::LAlt) && Keyboard::isKeyPressed(Keyboard::Key::F4)) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::F3)) {
                showDebug = !showDebug;
            }
        }
        Vector2f oldPos = player.getPosition();
        player.update(time);
        island.collision(player.getSprite(), oldPos);
        camera.update(player.getPosition().x, player.getPosition().y);
        window.clear();
        debugOverlay.setInfo(player.getSprite(), player.getCurrentSpeed());
        ocean.draw(window);
        camera.draw(window);
        island.draw(window);
        player.draw(window);
        window.setView(window.getDefaultView());
        if (showDebug) {
            debugOverlay.draw(window);
        }
        window.display();
    }
}
