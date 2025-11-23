#ifndef LOST_ISLAND_AIMOBS_HPP
#define LOST_ISLAND_AIMOBS_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
enum MobState {
    IDLE,       // Стоїть на місці
    PATROL,     // Ходить туди-сюди
    CHASE,      // Біжить за гравцем
    ATTACK      // Б'є гравця
};
class AIMobs {
public:
};
#endif