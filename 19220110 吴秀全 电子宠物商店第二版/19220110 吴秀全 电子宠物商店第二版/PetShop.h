#ifndef PETSHOP_H
#define PETSHOP_H

#include <map>
#include "Pet.h"

class PetShop 
{
private:
    std::map<std::string, Pet*> pets;

public:
    ~PetShop();

    void addPet(Pet* pet);
    void removePet(const std::string& petName);
    Pet* findPet(const std::string& petName);
    void updatePetName(const std::string& oldName, const std::string& newName);
    void simulateTimePassing();
    void showPetEmotion(const std::string& petName);
    void listPets() const;
};

#endif // PETSHOP_H

