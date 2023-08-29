#include"pet.h"
class PetShop {
public:
    void addPet(Pet* pet) {
        pets.push_back(pet);
    }

    void listPets() const {
        cout << "Available Pets:" << endl;
        for (const auto& pet : pets) {
            pet->showStatus();
        }
    }

    void interactWithPet(const string& petName) {
        for (auto& pet : pets) {
            if (pet->getName() == petName) {
                pet->interact();
                break;
            }
        }
    }

    void simulateTimePassing() {
        for (auto& pet : pets) {
            pet->grow();
        }
    }

    ~PetShop() {
        for (auto& pet : pets) {
            delete pet;
        }
    }

private:
    vector<Pet*> pets;
};
