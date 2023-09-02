#include "Fish.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Fish::Fish(const string& petName) : ElectronicPet(petName, 60, 5) 
{}

void Fish::interact() 
{
    cout << "You interacted with " << name << "." << endl;
    setEmotion("content");
    health += 3;
}

void Fish::performRandomAction() 
{
    int action = rand() % 3;
    if (action == 0) {
        interact();
    }
    else 
    {
        setEmotion("neutral");
    }
}
