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
    bool running;
    float currentSpeed;
    float aiTimer;
    float moveTime;
public:
    AIMobs();
    virtual void updateAI(float time, Sprite &sprite, Island &island, float walkSpeed, float runSpeed);
    Direction getDirection() const { return direction; }
    bool isMoving() const { return moving; }
};
#endif