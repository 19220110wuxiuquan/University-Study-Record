#include "ElectronicPet.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int maxAge = 100;
ElectronicPet::ElectronicPet(const string& petName, int initialHealth, int maxAge)
    : Pet(petName), health(initialHealth), maxHealth(initialHealth), age(0) {}

void ElectronicPet::ageOneDay() 
{
    age++;
    health--;
    if (age >= maxAge || health <= 0) 
    {
        cout << name << " passed away." << endl;
        delete this;
    }
}

void ElectronicPet::showStatus() const 
{
    cout << "Pet: " << name << ", Age: " << age << " days, Health: " << health << "/" << maxHealth << ", Emotion: " << emotion << endl;
}
