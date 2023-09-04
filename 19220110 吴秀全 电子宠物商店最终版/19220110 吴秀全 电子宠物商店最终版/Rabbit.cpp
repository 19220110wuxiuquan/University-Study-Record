#include "Rabbit.h"

Rabbit::Rabbit(const string& name, const string& color, int price)
    : Pet(name, color, 10, price) {}

void Rabbit::interact() {
    int action = rand() % 2;
    switch (action) {
    case 0:
        play();
        break;
    case 1:
        setEmotion("angry");
        break;
    default:
        break;
    }
}
