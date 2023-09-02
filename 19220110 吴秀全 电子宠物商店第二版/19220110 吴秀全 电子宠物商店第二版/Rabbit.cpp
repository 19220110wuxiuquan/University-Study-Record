#include "Rabbit.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Rabbit::Rabbit(const string& petName) : ElectronicPet(petName, 90, 8) 
{}

void Rabbit::interact() 
{
    cout << "You interacted with " << name << "." << endl;
    setEmotion("curious");
    health += 4;
}

void Rabbit::performRandomAction() 
{
    int action = rand() % 3;
    if (action == 0) 
    {
        interact();
    }
    else
    {
        setEmotion("neutral");
    }
}