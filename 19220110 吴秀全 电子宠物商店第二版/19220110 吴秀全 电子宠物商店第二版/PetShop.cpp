#include "PetShop.h"
#include <iostream>

PetShop::~PetShop() 
{
    for (auto& pair : pets)
    {
        delete pair.second;
    }
}

void PetShop::addPet(Pet* pet) 
{
    pets[pet->getName()] = pet;
}

void PetShop::removePet(const std::string& petName) 
{
    auto it = pets.find(petName);
    if (it != pets.end()) 
    {
        delete it->second;
        pets.erase(it);
    }
    else 
    {
        std::cout << "Pet with name '" << petName << "' not found." << std::endl;
    }
}

Pet* PetShop::findPet(const std::string& petName) 
{
    auto it = pets.find(petName);
    if (it != pets.end()) 
    {
        return it->second;
    }
    else 
    {
        std::cout << "Pet with name '" << petName << "' not found." << std::endl;
        return nullptr;
    }
}

void PetShop::updatePetName(const std::string& oldName, const std::string& newName) 
{
    auto it = pets.find(oldName);
    if (it != pets.end()) 
    {
        Pet* pet = it->second;
        pets.erase(it);
        pet->setEmotion("renamed");
        pets[newName] = pet;
    }
    else 
    {
        std::cout << "Pet with name '" << oldName << "' not found." << std::endl;
    }
}

void PetShop::simulateTimePassing() 
{
    for (auto& pair : pets) 
    {
        Pet* pet = pair.second;
        pet->performRandomAction();
        pet->ageOneDay();
    }
}

void PetShop::showPetEmotion(const std::string& petName) 
{
    Pet* pet = findPet(petName);
    if (pet) 
    {
        pet->showEmotion();
    }
}

void PetShop::listPets() const 
{
    std::cout << "Available Pets:" << std::endl;
    for (const auto& pair : pets) 
    {
        pair.second->showStatus();
    }
}
