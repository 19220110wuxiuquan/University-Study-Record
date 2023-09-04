#include "Fish.h"

Fish::Fish(const string& name, const string& color, int price)
    : Pet(name, color, 5, price) {}

void Fish::interact() {
    int action = rand() % 2;
    switch (action) {
    case 0:
        giveWater();
        break;
    case 1:
        setEmotion("angry");
        break;
    default:
        break;
    }
}
