#include "Pet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
Pet::Pet(const string& name, const string& color, int maxAge, int price)
    : name(name), age(0), color(color), emotion("neutral"), maxAge(maxAge), price(price) {}

void Pet::showStatus() const 
{
    cout << "Pet: " << name << ", Age: " << age << " years, Color: " << color << ", Emotion: " << emotion << endl;
}

void Pet::grow() 
{
    age++;
}

string Pet::getName() const 
{
    return name;
}

void Pet::setName(const string& newName) 
{
    name = newName;
}

int Pet::getAge() const 
{
    return age;
}

string Pet::getColor() const 
{
    return color;
}

void Pet::setEmotion(const string& newEmotion) 
{
    emotion = newEmotion;
}

void Pet::showEmotion() 
{
    cout << name << " is feeling " << emotion << "." << endl;
}

int Pet::getPrice() const 
{
    return price;
}

void Pet::feed() 
{
    cout << "You fed " << name << "." << endl;
    setEmotion("happy");
}

void Pet::giveWater() 
{
    cout << "You gave water to " << name << "." << endl;
    setEmotion("happy");
}

void Pet::takeToBathroom() 
{
    cout << "You took " << name << " to the bathroom." << endl;
    setEmotion("neutral");
}

void Pet::play() 
{
    cout << "You played with " << name << "." << endl;
    setEmotion("happy");
}

void Pet::putToSleep() 
{
    cout << "You put " << name << " to sleep." << endl;
    setEmotion("neutral");
}

void Pet::seeDoctor() 
{
    cout << "You took " << name << " to the doctor." << endl;
    setEmotion("neutral");
}

void Pet::ageOneYear() 
{
    age++;
    if (age >= maxAge) 
    {
        cout << name << " passed away of old age." << endl;
        delete this; // Pet has reached its maximum age, delete it
    }
}

void Pet::performRandomAction() 
{
    int action = rand() % 6; 
    switch (action) 
    {
    case 0:
        feed();
        break;
    case 1:
        giveWater();
        break;
    case 2:
        takeToBathroom();
        break;
    case 3:
        play();
        break;
    case 4:
        putToSleep();
        break;
    case 5:
        seeDoctor();
        break;
    default:
        break;
    }
}
