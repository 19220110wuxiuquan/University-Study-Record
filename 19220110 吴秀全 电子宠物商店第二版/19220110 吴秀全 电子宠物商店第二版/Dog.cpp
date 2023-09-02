#include "Dog.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Dog::Dog(const string& petName) : ElectronicPet(petName, 120, 12) 
{}

void Dog::interact() 
{
    cout << "You interacted with " << name << "." << endl;
    setEmotion("excited");
    health += 8;
}

void Dog::performRandomAction() 
{
    int action = rand() % 3;
    if (action == 0) {
        interact();
    }
    else {
        setEmotion("neutral");
    }
}
