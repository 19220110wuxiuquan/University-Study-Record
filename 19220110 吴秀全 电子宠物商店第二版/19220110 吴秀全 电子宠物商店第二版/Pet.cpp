#include "Pet.h"
Pet::Pet(const string& petName) : name(petName), emotion("neutral") {}

Pet::~Pet() {}

string Pet::getName() const {
    return name;
}

void Pet::setEmotion(const string& newEmotion) {
    emotion = newEmotion;
}

void Pet::showEmotion() {
    cout << name << " is feeling " << emotion << "." << endl;
}
