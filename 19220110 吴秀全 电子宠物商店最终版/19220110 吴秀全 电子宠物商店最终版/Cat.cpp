#include "Cat.h"

Cat::Cat(const string& name, const string& color, int price)
    : Pet(name, color, 15, price) {}

void Cat::interact() {
    int action = rand() % 3;
    switch (action) {
    case 0:
        feed();
        break;
    case 1:
        play();
        break;
    case 2:
        setEmotion("angry");
        break;
    default:
        break;
    }
}
