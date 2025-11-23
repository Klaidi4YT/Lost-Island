#include "utils/Utils.hpp"

void Utils::currentFrame(float &frame, float &time, const int &count) {
    frame += 0.01f * time;
    if (frame >= count) {
        frame = 0;
    }
}
void Utils::loadTextures(vector<Texture>& vec, const string& path, int count) {
    for (int i = 0; i < count; i++) {
        if (!vec[i].loadFromFile(path + to_string(i) + ".png")) {
            cout << "Error loading: " << path << i << ".png\n";
        }
    }
}
