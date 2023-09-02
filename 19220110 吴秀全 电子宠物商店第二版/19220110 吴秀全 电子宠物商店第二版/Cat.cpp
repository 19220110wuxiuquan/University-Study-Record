#include "Cat.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Cat::Cat(const string& petName) : ElectronicPet(petName, 100, 10) 
{}

void Cat::interact() 
{
    cout << "You interacted with " << name << "." << endl;
    setEmotion("happy");
    health += 5;
}

void Cat::performRandomAction() 
{
    int action = rand() % 3;
    if (action == 0) {
        interact();
    }
    else {
        setEmotion("neutral");
    }
}
