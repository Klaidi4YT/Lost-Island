#ifndef LOST_ISLAND_PERSON_HPP
#define LOST_ISLAND_PERSON_HPP

class Person {
private:
    int health;
    int damage;
public:
    Person(int health, int damage) {
        this->health = health;
        this->damage = damage;
    };
};
#endif