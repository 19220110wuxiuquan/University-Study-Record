#ifndef PETSHOP_H
#define PETSHOP_H

#include <vector>
#include <string>
#include "Pet.h"

using namespace std;

class PetShop {
public:
    PetShop();
    ~PetShop();

    void addPet(Pet* pet);
    void removePet(const string& petName);
    Pet* findPet(const string& petName) const;
    void listPets() const;
    void interactWithPet(const string& petName);
    void simulateTimePassing();
    void showPetEmotion(const string& petName);
    int countPets() const;
    void updatePetName(const string& oldName, const string& newName);
    void saveDataToFile(const string& filename) const;
    void loadDataFromFile(const string& filename);

private:
    vector<Pet*> pets;
};

#endif

