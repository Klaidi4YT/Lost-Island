#include <SFML/Graphics.hpp>
#include "world/Ocean.hpp"
#include "world/Island.hpp"
#include "screens/Loading.hpp"
#include "utils/Utils.hpp"
#include "utils/Camera.hpp"

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;
const int FRAME_COUNT = 19;
const int FRAME_IDLE_COUNT = 16;
const int FRAME_RUN_COUNT = 11;

int main() {
    RenderWindow window(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Lost Island");
    window.setFramerateLimit(144);

    Image logo;
    logo.loadFromFile("../assets/utils/logo.png");
    window.setIcon(logo.getSize(), logo.getPixelsPtr());

    Loading loading(WINDOW_WIDTH, WINDOW_HEIGHT);
    loading.run(window);
    Ocean ocean(WINDOW_WIDTH, WINDOW_HEIGHT);
    Island island(WINDOW_WIDTH, WINDOW_HEIGHT);
    Utils utils;
    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT);
    vector<Texture> front(FRAME_COUNT), back(FRAME_COUNT), left(FRAME_COUNT), right(FRAME_COUNT);
    vector<Texture> idle_front(FRAME_IDLE_COUNT), idle_back(FRAME_IDLE_COUNT), idle_left(FRAME_IDLE_COUNT), idle_right(FRAME_IDLE_COUNT);
    vector<Texture> run_front(FRAME_RUN_COUNT), run_back(FRAME_RUN_COUNT), run_left(FRAME_RUN_COUNT), run_right(FRAME_RUN_COUNT);
    utils.loadTextures(front, "../assets/entities/Player/FrontWalking/", FRAME_COUNT);
    utils.loadTextures(back, "../assets/entities/Player/BackWalking/", FRAME_COUNT);
    utils.loadTextures(left, "../assets/entities/Player/LeftWalking/", FRAME_COUNT);
    utils.loadTextures(right, "../assets/entities/Player/RightWalking/", FRAME_COUNT);
    utils.loadTextures(idle_front, "../assets/entities/Player/FrontIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_back, "../assets/entities/Player/BackIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_left, "../assets/entities/Player/LeftIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_right, "../assets/entities/Player/RightIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(run_front, "../assets/entities/Player/FrontRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_back, "../assets/entities/Player/BackRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_left, "../assets/entities/Player/LeftRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_right, "../assets/entities/Player/RightRunning/", FRAME_RUN_COUNT);

    Sprite playerSprite(front[0]);
    playerSprite.setOrigin(playerSprite.getLocalBounds().getCenter());
    playerSprite.setPosition(island.getSprite().getGlobalBounds().getCenter());
    playerSprite.setScale({0.5f, 0.5f});
    float CurrentFrameTime = 0;
    Clock clock;
    enum Direction {FRONT, BACK, LEFT, RIGHT};
    Direction direction = FRONT;

    while (window.isOpen()) {
        bool moving = false;
        bool running = Keyboard::isKeyPressed(Keyboard::Key::LControl) &&
               (Keyboard::isKeyPressed(Keyboard::Key::W) ||
                Keyboard::isKeyPressed(Keyboard::Key::A) ||
                Keyboard::isKeyPressed(Keyboard::Key::S) ||
                Keyboard::isKeyPressed(Keyboard::Key::D));
        float walkspeed = 0.15f;
        float runspeed = 0.20f;
        float currentspeed = running ? runspeed : walkspeed;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        while (const auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::LAlt) && Keyboard::isKeyPressed(Keyboard::Key::F4)) {
                window.close();
            }
        }
        Vector2f oldPos = playerSprite.getPosition();
        if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
            running ? utils.currentFrame(CurrentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(CurrentFrameTime, time, FRAME_COUNT);
            direction = BACK;
            Vector2f delta(0, -currentspeed * time);
            playerSprite.move(delta);
            moving = true;
            camera.update(playerSprite.getPosition().x, playerSprite.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
            running ? utils.currentFrame(CurrentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(CurrentFrameTime, time, FRAME_COUNT);
            direction = LEFT;
            Vector2f delta(-currentspeed * time, 0);
            playerSprite.move(delta);
            moving = true;
            camera.update(playerSprite.getPosition().x, playerSprite.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
            running ? utils.currentFrame(CurrentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(CurrentFrameTime, time, FRAME_COUNT);
            direction = FRONT;
            Vector2f delta(0, currentspeed * time);
            playerSprite.move(delta);
            moving = true;
            camera.update(playerSprite.getPosition().x, playerSprite.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
            running ? utils.currentFrame(CurrentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(CurrentFrameTime, time, FRAME_COUNT);
            direction = RIGHT;
            Vector2f delta(currentspeed * time, 0);
            playerSprite.move(delta);
            moving = true;
            camera.update(playerSprite.getPosition().x, playerSprite.getPosition().y);
        }

        if (moving) {
            if (running) {
                switch (direction) {
                    case FRONT: playerSprite.setTexture(run_front[int(CurrentFrameTime)]); break;
                    case BACK:  playerSprite.setTexture(run_back[int(CurrentFrameTime)]); break;
                    case LEFT:  playerSprite.setTexture(run_left[int(CurrentFrameTime)]); break;
                    case RIGHT: playerSprite.setTexture(run_right[int(CurrentFrameTime)]); break;
                }
            } else  {
                switch (direction) {
                    case FRONT: playerSprite.setTexture(front[int(CurrentFrameTime)]); break;
                    case BACK:  playerSprite.setTexture(back[int(CurrentFrameTime)]); break;
                    case LEFT:  playerSprite.setTexture(left[int(CurrentFrameTime)]); break;
                    case RIGHT: playerSprite.setTexture(right[int(CurrentFrameTime)]); break;
                }
            }
        } else {
            utils.currentFrame(CurrentFrameTime, time, FRAME_IDLE_COUNT);
            switch (direction) {
                case FRONT: playerSprite.setTexture(idle_front[int(CurrentFrameTime)], true); break;
                case BACK: playerSprite.setTexture(idle_back[int(CurrentFrameTime)], true); break;
                case RIGHT: playerSprite.setTexture(idle_right[int(CurrentFrameTime)], true); break;
                case LEFT: playerSprite.setTexture(idle_left[int(CurrentFrameTime)], true); break;
            }
        }
        island.collision(playerSprite, oldPos);
        camera.update(playerSprite.getPosition().x, playerSprite.getPosition().y);
        window.setView(window.getDefaultView());
        ocean.draw(window);
        camera.draw(window);
        island.draw(window);
        window.draw(playerSprite);
        window.display();
    }
}
