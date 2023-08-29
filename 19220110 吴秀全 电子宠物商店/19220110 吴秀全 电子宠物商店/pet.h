#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Pet 
{
protected:
    string name;
    int age;
    string color;

public:
    Pet(const string& name, const string& color) : name(name), age(0), color(color) {}

    virtual ~Pet() {}

    virtual void showStatus() const {
        cout << "Pet: " << name << ", Age: " << age << " years, Color: " << color << endl;
    }

    virtual void interact() {}

    void grow() {
        age++;
    }

    string getName() const {
        return name;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name, const string& color) : Pet(name, color), mood("neutral") {}

    void showStatus() const override {
        cout << "Cat: " << name << ", Age: " << age << " years, Mood: " << mood << ", Color: " << color << endl;
    }

    void interact() override {
        cout << "You played with the cat. Mood improved!" << endl;
        mood = "happy";
    }

private:
    string mood;
};

class Dog : public Pet {
public:
    Dog(const string& name, const string& color) : Pet(name, color), hungerLevel(0) {}

    void showStatus() const override {
        cout << "Dog: " << name << ", Age: " << age << " years, Hunger: " << hungerLevel << ", Color: " << color << endl;
    }

    void interact() override {
        cout << "You fed the dog. Hunger reduced!" << endl;
        hungerLevel--;
    }

private:
    int hungerLevel;
};

class Rabbit : public Pet {
public:
    Rabbit(const string& name, const string& color) : Pet(name, color), happiness(50) {}

    void showStatus() const override {
        cout << "Rabbit: " << name << ", Age: " << age << " years, Happiness: " << happiness << ", Color: " << color << endl;
    }

    void interact() override {
        cout << "You played with the rabbit. Happiness improved!" << endl;
        happiness += 10;
    }

private:
    int happiness;
};

class Fish : public Pet {
public:
    Fish(const string& name, const string& color) : Pet(name, color), waterQuality(80) {}

    void showStatus() const override {
        cout << "Fish: " << name << ", Age: " << age << " years, Water Quality: " << waterQuality << ", Color: " << color << endl;
    }

    void interact() override {
        cout << "You cleaned the fish tank. Water quality improved!" << endl;
        waterQuality += 10;
    }

private:
    int waterQuality;
};

class Turtle : public Pet {
public:
    Turtle(const string& name, const string& color) : Pet(name, color), energy(100), shellHardness(75) {}

    void showStatus() const override {
        cout << "Turtle: " << name << ", Age: " << age << " years, Energy: " << energy << ", Shell Hardness: " << shellHardness << ", Color: " << color << endl;
    }

    void interact() override {
        cout << "You took the turtle for a walk. Energy reduced!" << endl;
        energy -= 20;
    }

private:
    int energy;
    int shellHardness;
};