#ifndef LOST_ISLAND_UTILS_HPP
#define LOST_ISLAND_UTILS_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
class Utils {
    private:
    Music music;
    public:
    void currentFrame(float &frame, float &time, const int &count);
    void loadTextures(vector<Texture>& vec, const string& path, int count);
    void backgroundSound();
    void pauseSound();
    void playSound();
    void drawHitBox(RenderWindow &window, const FloatRect &rect);
};
#endif