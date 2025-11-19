#ifndef LOST_ISLAND_UTILS_HPP
#define LOST_ISLAND_UTILS_HPP
#include <iostream>
using namespace std;
class Utils {
    public:
    void currentFrame(float &frame, float &time, const int &count) {
        frame += 0.01f * time;
        if (frame >= count) {
            frame = 0;
        }
    }
    void loadTextures(vector<Texture>& vec, const string& path, int count) {
        for (int i = 0; i < count; i++) {
            if (!vec[i].loadFromFile(path + to_string(i) + ".png")) {
                cout << "Error loading: " << path << i << ".png\n";
            }
        }
    }
};
#endif