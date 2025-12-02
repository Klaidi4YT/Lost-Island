#ifndef LOST_ISLAND_PLAYER_HPP
#define LOST_ISLAND_PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils/Utils.hpp"
using namespace sf;
using namespace std;
class Player {
    const int FRAME_WALKING_COUNT = 19;
    const int FRAME_IDLE_COUNT = 16;
    const int FRAME_RUN_COUNT = 11;
    const int FRAME_ATTACKING = 9;
private:
    Texture texture;
    Sprite sprite;
    Utils utils;
    enum Direction {FRONT, BACK, LEFT, RIGHT};
    Direction direction;
    bool attacking;
    bool running;
    bool moving;
    float currentFrameTime;
    float walkSpeed;
    float runSpeed;
    float currentSpeed;
    vector<Texture> walking_front, walking_back, walking_left, walking_right;
    vector<Texture> idle_front, idle_back, idle_left, idle_right;
    vector<Texture> run_front, run_back, run_left, run_right;
    vector<Texture> attack_front, attack_back, attack_left, attack_right;
    void loadAllTextures();
    void updateAnimations(float time);
    void handleInput(float time);
public:
    Player(Vector2f startPosition);
    Sprite &getSprite();
    Vector2f getPosition();
    void update(float time);
    float getCurrentSpeed();
    FloatRect getHitBox();
    void draw(RenderWindow &window);
};
#endif