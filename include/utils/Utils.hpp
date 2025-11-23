#ifndef LOST_ISLAND_UTILS_HPP
#define LOST_ISLAND_UTILS_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Utils {
    public:
    void currentFrame(float &frame, float &time, const int &count);
    void loadTextures(vector<Texture>& vec, const string& path, int count);
};
#endif