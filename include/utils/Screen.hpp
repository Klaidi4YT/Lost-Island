#ifndef LOST_ISLAND_SCREEN_HPP
#define LOST_ISLAND_SCREEN_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <filesystem>
using namespace sf;
using namespace std;
namespace fs = std::filesystem;
class Screen {
private:
    Texture texture;
    Image image;
    SoundBuffer buffer;
    Sound sound;
public:
    Screen();
    void createScreen(RenderWindow &window);
};
#endif