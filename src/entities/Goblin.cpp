#include "entities/Goblin.hpp"

Goblin::Goblin(Vector2f position) : texture("../assets/entities/Goblin/FrontIdle/0.png"), sprite(texture) {
    currentFrameTime = 0.0f;

    direction = FRONT;
    moving = false;
    currentSpeed = 0.04f;

    walkSpeed = 0.04f;
    runSpeed = 0.07f;
    attacking = false;
    running = false;

    walking_front.resize(FRAME_WALKING_COUNT);
    walking_back.resize(FRAME_WALKING_COUNT);
    walking_left.resize(FRAME_WALKING_COUNT);
    walking_right.resize(FRAME_WALKING_COUNT);
    idle_front.resize(FRAME_IDLE_COUNT);
    idle_back.resize(FRAME_IDLE_COUNT);
    idle_left.resize(FRAME_IDLE_COUNT);
    idle_right.resize(FRAME_IDLE_COUNT);
    run_front.resize(FRAME_RUN_COUNT);
    run_back.resize(FRAME_RUN_COUNT);
    run_left.resize(FRAME_RUN_COUNT);
    run_right.resize(FRAME_RUN_COUNT);

    loadAllTextures();

    sprite.setTexture(idle_front[0]);
    sprite.setOrigin(sprite.getLocalBounds().getCenter());
    sprite.setPosition(position);
    sprite.setScale({0.5f, 0.5f});
}
void Goblin::loadAllTextures() {
    utils.loadTextures(walking_front, "../assets/entities/Goblin/FrontWalking/", FRAME_WALKING_COUNT);
    utils.loadTextures(walking_back, "../assets/entities/Goblin/BackWalking/", FRAME_WALKING_COUNT);
    utils.loadTextures(walking_left, "../assets/entities/Goblin/LeftWalking/", FRAME_WALKING_COUNT);
    utils.loadTextures(walking_right, "../assets/entities/Goblin/RightWalking/", FRAME_WALKING_COUNT);
    utils.loadTextures(idle_front, "../assets/entities/Goblin/FrontIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_back, "../assets/entities/Goblin/BackIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_left, "../assets/entities/Goblin/LeftIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(idle_right, "../assets/entities/Goblin/RightIdle/", FRAME_IDLE_COUNT);
    utils.loadTextures(run_front, "../assets/entities/Goblin/FrontRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_back, "../assets/entities/Goblin/BackRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_left, "../assets/entities/Goblin/LeftRunning/", FRAME_RUN_COUNT);
    utils.loadTextures(run_right, "../assets/entities/Goblin/RightRunning/", FRAME_RUN_COUNT);
}
void Goblin::update(float time, Island &island) {
    updateAI(time, sprite, island);
    updateAnimations(time);
}
void Goblin::updateAnimations(float time) {
    if (moving) {
        if (running) {
            utils.currentFrame(currentFrameTime, time, FRAME_RUN_COUNT);
            switch (direction) {
                case FRONT: sprite.setTexture(run_front[int(currentFrameTime)]); break;
                case BACK:  sprite.setTexture(run_back[int(currentFrameTime)]); break;
                case LEFT:  sprite.setTexture(run_left[int(currentFrameTime)]); break;
                case RIGHT: sprite.setTexture(run_right[int(currentFrameTime)]); break;
            }
        } else  {
            utils.currentFrame(currentFrameTime, time, FRAME_WALKING_COUNT);
            switch (direction) {
                case FRONT: sprite.setTexture(walking_front[int(currentFrameTime)]); break;
                case BACK:  sprite.setTexture(walking_back[int(currentFrameTime)]); break;
                case LEFT:  sprite.setTexture(walking_left[int(currentFrameTime)]); break;
                case RIGHT: sprite.setTexture(walking_right[int(currentFrameTime)]); break;
            }
        }
    } else {
        utils.currentFrame(currentFrameTime, time, FRAME_IDLE_COUNT);
        switch (direction) {
            case FRONT: sprite.setTexture(idle_front[int(currentFrameTime)], true); break;
            case BACK: sprite.setTexture(idle_back[int(currentFrameTime)], true); break;
            case RIGHT: sprite.setTexture(idle_right[int(currentFrameTime)], true); break;
            case LEFT: sprite.setTexture(idle_left[int(currentFrameTime)], true); break;
        }
    }
}

void Goblin::draw(RenderWindow &window) {
    window.draw(sprite);
}
Sprite &Goblin::getSprite() {
    return sprite;
}
float Goblin::getSpeed() {
    return currentSpeed;
}
