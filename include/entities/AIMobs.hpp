#ifndef LOST_ISLAND_AIMOBS_HPP
#define LOST_ISLAND_AIMOBS_HPP
#include <SFML/Graphics.hpp>
#include "../world/Island.hpp"
using namespace sf;
enum Direction { FRONT, BACK, LEFT, RIGHT };
class AIMobs {
protected:
    Direction direction;
    bool moving;
    float currentSpeed;
    float aiTimer;
    float moveTime;

public:
    AIMobs();

    void updateAI(float time, Sprite &sprite, Island &island);

    Direction getDirection() const { return direction; }
    bool isMoving() const { return moving; }
};
#endif