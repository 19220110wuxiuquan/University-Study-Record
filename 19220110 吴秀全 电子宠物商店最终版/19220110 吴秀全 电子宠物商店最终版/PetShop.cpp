#include "PetShop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

PetShop::PetShop() {
    srand(time(NULL));
}

PetShop::~PetShop() {
    for (auto& pet : pets) {
        delete pet;
    }
}

void PetShop::addPet(Pet* pet) {
    pets.push_back(pet);
}

void PetShop::removePet(const string& petName) {
    auto it = pets.begin();
    while (it != pets.end()) {
        if ((*it)->getName() == petName) {
            delete* it;
            it = pets.erase(it);
            cout << "Pet " << petName << " removed from the shop." << endl;
            return;
        }
        ++it;
    }
    cout << "Pet not found." << endl;
}

Pet* PetShop::findPet(const string& petName) const {
    for (const auto& pet : pets) {
        if (pet->getName() == petName) {
            return pet;
        }
    }
    return nullptr;
}

void PetShop::listPets() const {
    cout << "Available Pets:" << endl;
    for (const auto& pet : pets) {
        pet->showStatus();
    }
}

void PetShop::interactWithPet(const string& petName) {
    Pet* pet = findPet(petName);
    if (pet) {
        pet->interact();
        showPetEmotion(petName);
    }
    else {
        cout << "Pet not found." << endl;
    }
}

void PetShop::simulateTimePassing() {
    for (auto& pet : pets) {
        pet->performRandomAction();
        pet->ageOneYear();
    }
}

void PetShop::showPetEmotion(const string& petName) {
    Pet* pet = findPet(petName);
    if (pet) {
        pet->showEmotion();
    }
    else {
        cout << "Pet not found." << endl;
    }
}

int PetShop::countPets() const {
    return pets.size();
}

void PetShop::updatePetName(const string& oldName, const string& newName) {
    for (auto& pet : pets) {
        if (pet->getName() == oldName) {
            pet->setName(newName);
            cout << "Pet name updated." << endl;
            return;
        }
    }
    cout << "Pet not found." << endl;
}

void PetShop::saveDataToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& pet : pets) {
        file << pet->getName() << " " << pet->getAge() << " " << pet->getColor() << " " << pet->getPrice() << endl;
    }

    file.close();
    cout << "Pet data saved to '" << filename << "'." << endl;
}

void PetShop::loadDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    pets.clear();

    string name, color;
    int age, price;
    while (file >> name >> age >> color >> price) {
        Pet* pet = new Pet(name, color, age, price);
        pets.push_back(pet);
    }
    file.close();
    cout << "Pet data loaded from '" << filename << "'." << endl;
}
