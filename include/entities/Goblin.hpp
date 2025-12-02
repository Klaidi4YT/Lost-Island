#ifndef LOST_ISLAND_GOBLIN_HPP
#define LOST_ISLAND_GOBLIN_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils/Utils.hpp"
#include <cmath>
#include "AIMobs.hpp"
using namespace sf;
using namespace std;
class Goblin : public AIMobs {
    const int FRAME_WALKING_COUNT = 19;
    const int FRAME_IDLE_COUNT = 16;
    const int FRAME_RUN_COUNT = 11;

private:
    Texture texture;
    Sprite sprite;
    Utils utils;
    float currentFrameTime;
    bool attacking;
    float walkSpeed;
    float runSpeed;
    float currentSpeed;
    vector<Texture> walking_front, walking_back, walking_left, walking_right;
    vector<Texture> idle_front, idle_back, idle_left, idle_right;
    vector<Texture> run_front, run_back, run_left, run_right;
    void loadAllTextures();
    void updateAnimations(float time);
public:
    Goblin(Vector2f position);
    Sprite &getSprite();
    Vector2f getPosition();
    void update(float time, Island &island);
    void draw(RenderWindow &window);
    float getSpeed();
    FloatRect getHitBox();
};
#endif