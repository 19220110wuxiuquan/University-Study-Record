#include "Turtle.h"

Turtle::Turtle(const string& name, const string& color, int price)
    : Pet(name, color, 30, price) {}

void Turtle::interact() {
    int action = rand() % 2;
    switch (action) {
    case 0:
        takeToBathroom();
        break;
    case 1:
        setEmotion("angry");
        break;
    default:
        break;
    }
}
