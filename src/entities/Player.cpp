#include "entities/Player.hpp"

Player::Player(Vector2f startPosition) : texture("../assets/entities/Player/FrontIdle/0.png"), sprite(texture) {
    currentFrameTime = 0.0f;
    direction = FRONT;
    attacking = false;
    running = false;
    moving = false;

    front.resize(FRAME_COUNT);
    back.resize(FRAME_COUNT);
    left.resize(FRAME_COUNT);
    right.resize(FRAME_COUNT);
    idle_front.resize(FRAME_IDLE_COUNT);
    idle_back.resize(FRAME_IDLE_COUNT);
    idle_left.resize(FRAME_IDLE_COUNT);
    idle_right.resize(FRAME_IDLE_COUNT);
    run_front.resize(FRAME_RUN_COUNT);
    run_back.resize(FRAME_RUN_COUNT);
    run_left.resize(FRAME_RUN_COUNT);
    run_right.resize(FRAME_RUN_COUNT);
    attack_front.resize(FRAME_ATTACKING);
    attack_back.resize(FRAME_ATTACKING);
    attack_left.resize(FRAME_ATTACKING);
    attack_right.resize(FRAME_ATTACKING);

    loadAllTextures();

    sprite.setTexture(front[0]);
    sprite.setOrigin(sprite.getLocalBounds().getCenter());
    sprite.setPosition(startPosition);
    sprite.setScale({0.5f, 0.5f});

}
void Player::loadAllTextures() {
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
    utils.loadTextures(attack_front, "../assets/entities/Player/FrontAttacking/", FRAME_ATTACKING);
    utils.loadTextures(attack_back, "../assets/entities/Player/BackAttacking/", FRAME_ATTACKING);
    utils.loadTextures(attack_left, "../assets/entities/Player/LeftAttacking/", FRAME_ATTACKING);
    utils.loadTextures(attack_right, "../assets/entities/Player/RightAttacking/", FRAME_ATTACKING);
}
void Player::draw(RenderWindow &window) {
    window.draw(sprite);
}
void Player::update(float time) {
    if (Mouse::isButtonPressed(Mouse::Button::Left)) {
        attacking = true;
        currentFrameTime = 0;
    }
    handleInput(time);
    updateAnimations(time);
}

void Player::handleInput(float time) {
    moving = false;
    running = Keyboard::isKeyPressed(Keyboard::Key::LControl) && (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::D));
    walkSpeed = 0.15f;
    runSpeed = 0.20f;
    currentSpeed = running ? runSpeed : walkSpeed;
    Vector2f delta(0,0);
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        running ? utils.currentFrame(currentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame( currentFrameTime, time, FRAME_COUNT);
        direction = BACK;
        delta.y = -currentSpeed * time;
        sprite.move(delta);
        if (attacking) {
            sprite.move(-delta);
        }
        moving = true;

    } else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
        running ? utils.currentFrame(currentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(currentFrameTime, time, FRAME_COUNT);
        direction = LEFT;
        delta.x = -currentSpeed * time;
        sprite.move(delta);
        if (attacking) {
            sprite.move(-delta);
        }
        moving = true;

    } else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        running ? utils.currentFrame(currentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(currentFrameTime, time, FRAME_COUNT);
        direction = FRONT;
        delta.y = currentSpeed * time;
        sprite.move(delta);
        if (attacking) {
            sprite.move(-delta);
        }
        moving = true;
    } else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        running ? utils.currentFrame(currentFrameTime, time, FRAME_RUN_COUNT) : utils.currentFrame(currentFrameTime, time, FRAME_COUNT);
        direction = RIGHT;
        delta.x = currentSpeed * time;
        sprite.move(delta);
        if (attacking) {
            sprite.move(-delta);
        }
        moving = true;
    }
}
void Player::updateAnimations(float time) {
    if (moving) {
        if (running) {
            switch (direction) {
                case FRONT: sprite.setTexture(run_front[int(currentFrameTime)]); break;
                case BACK:  sprite.setTexture(run_back[int(currentFrameTime)]); break;
                case LEFT:  sprite.setTexture(run_left[int(currentFrameTime)]); break;
                case RIGHT: sprite.setTexture(run_right[int(currentFrameTime)]); break;
            }
        } else  {
            switch (direction) {
                case FRONT: sprite.setTexture(front[int(currentFrameTime)]); break;
                case BACK:  sprite.setTexture(back[int(currentFrameTime)]); break;
                case LEFT:  sprite.setTexture(left[int(currentFrameTime)]); break;
                case RIGHT: sprite.setTexture(right[int(currentFrameTime)]); break;
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
    if (attacking) {
        utils.currentFrame(currentFrameTime, time, FRAME_ATTACKING);
        switch (direction) {
            case FRONT: sprite.setTexture(attack_front[int(currentFrameTime)]); break;
            case BACK:  sprite.setTexture(attack_back[int(currentFrameTime)]); break;
            case LEFT:  sprite.setTexture(attack_left[int(currentFrameTime)]); break;
            case RIGHT: sprite.setTexture(attack_right[int(currentFrameTime)]); break;
        }

        if (currentFrameTime >= FRAME_ATTACKING - 1) {
            attacking = false;
        }
    }
}
Sprite &Player::getSprite() {
    return sprite;
}
Vector2f Player::getPosition() {
    return sprite.getPosition();
}
float Player::getCurrentSpeed() {
    return currentSpeed;
}
