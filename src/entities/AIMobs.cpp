#include "entities/AIMobs.hpp"

AIMobs::AIMobs() {
    direction = FRONT;
    moving = false;
    currentSpeed = 0.05f;
    aiTimer = 0;
    moveTime = 0;
}

void AIMobs::updateAI(float time, Sprite &sprite, Island &island) {
    aiTimer += time;

    if (aiTimer > moveTime) {
        aiTimer = 0;
        moveTime = (rand() % 2000) + 1000;
        moving = (rand() % 2) == 1;
        if (moving) {
            int dir = rand() % 4;
            direction = static_cast<Direction>(dir);
        }
    }

    if (moving) {
        Vector2f movement(0.f, 0.f);
        switch (direction) {
            case FRONT: movement.y += currentSpeed * time; break;
            case BACK:  movement.y -= currentSpeed * time; break;
            case LEFT:  movement.x -= currentSpeed * time; break;
            case RIGHT: movement.x += currentSpeed * time; break;
        }

        Vector2f nextPos = sprite.getPosition() + movement;
        FloatRect bounds = sprite.getGlobalBounds();

        float footX = nextPos.x;
        float footY = nextPos.y + (bounds.position.y / 2.0f) - 10.0f;

        if (island.isSolid(footX, footY)) {
            sprite.move(movement);
        } else {
            moving = false;
            aiTimer = moveTime;
        }
    }
}