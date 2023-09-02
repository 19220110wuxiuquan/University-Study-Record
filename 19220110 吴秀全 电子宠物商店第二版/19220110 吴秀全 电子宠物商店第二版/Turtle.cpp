#include "Turtle.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Turtle::Turtle(const string& petName) : ElectronicPet(petName, 150, 15) {}

void Turtle::interact()
{
    cout << "You interacted with " << name << "." << endl;
    setEmotion("calm");
    health += 2;
}

void Turtle::performRandomAction() 
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
