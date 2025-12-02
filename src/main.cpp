#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "world/Ocean.hpp"
#include "world/Island.hpp"
#include "screens/Loading.hpp"
#include "utils/Camera.hpp"
#include "utils/DebugOverlay.hpp"
#include "entities/Player.hpp"
#include "entities/Goblin.hpp"
#include "utils/Decoration.hpp"
#include "utils/Screen.hpp"
#include "utils/Utils.hpp"
using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;
void backgroundSound() {
    Music music;
    music.openFromFile("../assets/utils/sounds/background.mp3");
    music.setLooping(true);
    music.play();
}

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
    Screen screen;
    Utils utils;
    utils.backgroundSound();
    Player player(island.getSprite().getGlobalBounds().getCenter());
    Goblin goblin(player.getSprite().getGlobalBounds().getCenter());
    Decoration tombstone("../assets/decoration/tombstone.png", {-20, -600}, {0.2, 0.2});
    Decoration amagedboat("../assets/decoration/amagedboat.png", {-700, 650}, {0.8, 0.8});
    Decoration skelet("../assets/decoration/skelet.png", {150, -270}, {0.1, 0.1});
    Decoration coffer("../assets/decoration/coffer.png", {2000, 400}, {0.15, 0.15});
    Clock clock;
    Clock fpsClock;
    bool showDebug = false;
    bool mouseCursor = false;
    bool hitBox = false;
    bool sound = false;
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
            if (Keyboard::isKeyPressed(Keyboard::Key::F1)) {
                window.setMouseCursorVisible(mouseCursor);
                mouseCursor = !mouseCursor;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::F2)) {
                screen.createScreen(window);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::F3)) {
                showDebug = !showDebug;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::F4)) {
                hitBox = !hitBox;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::F5)) {
                if (!sound) {
                    utils.playSound();
                } else {
                    utils.pauseSound();
                }
                sound = !sound;
            }
        }
        debugOverlay.FPS(fpsClock);
        Vector2f oldPos = player.getPosition();
        goblin.update(time, island);
        player.update(time);
        island.collision(player.getSprite(), oldPos);
        camera.update(player.getPosition().x, player.getPosition().y);
        window.clear();
        debugOverlay.setInfo(player.getSprite(), player.getCurrentSpeed());
        ocean.draw(window);
        camera.draw(window);
        island.draw(window);
        tombstone.draw(window);
        amagedboat.draw(window);
        skelet.draw(window);
        goblin.draw(window);
        player.draw(window);
        coffer.draw(window);
        if (hitBox) {
            utils.drawHitBox(window, player.getHitBox());
            utils.drawHitBox(window, goblin.getHitBox());
        }
        window.setView(window.getDefaultView());
        if (showDebug) {
            debugOverlay.draw(window);
        }
        window.display();
    }
    return 0;
}
