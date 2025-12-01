#ifndef LOST_ISLAND_DEBUGOVERLAY_HPP
#define LOST_ISLAND_DEBUGOVERLAY_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class DebugOverlay {
private:
    Font font;
    Text text;
    int frames = 0;
    int currentFps = 0;
    public:
    DebugOverlay ();
    void FPS(Clock &fpsClock);
    void setInfo(Sprite &player, float speed);
    void draw(RenderWindow &window);
};
#endif