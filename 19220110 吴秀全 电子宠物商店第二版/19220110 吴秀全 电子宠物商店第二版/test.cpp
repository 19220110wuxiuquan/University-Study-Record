#include <iostream>
#include"ElectronicPet.h"
#include "PetShop.h"
#include "Cat.h"
#include "Dog.h"
#include"Rabbit.h"
#include"Fish.h"
#include"Turtle.h"
int main() {
    srand(time(NULL)); // Seed the random number generator

    PetShop shop;

    shop.addPet(new Cat("Whiskers"));
    shop.addPet(new Dog("Buddy"));
    shop.addPet(new Rabbit("Kitty"));

    int choice;
    do {
        std::cout << "Pet Shop Menu:" << std::endl;
        std::cout << "1. Add Pet" << std::endl;
        std::cout << "2. Remove Pet" << std::endl;
        std::cout << "3. Find Pet" << std::endl;
        std::cout << "4. Update Pet Name" << std::endl;
        std::cout << "5. Simulate Time Passing" << std::endl;
        std::cout << "6. Show Pet Emotion" << std::endl;
        std::cout << "7. List Pets" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string petType, petName;
            std::cout << "Enter the pet type (Cat/Dog): ";
            std::cin >> petType;
            std::cout << "Enter the pet name: ";
            std::cin >> petName;

            if (petType == "Cat") {
                shop.addPet(new Cat(petName));
            }
            else if (petType == "Dog") {
                shop.addPet(new Dog(petName));
            }
            else if (petType == "Rabbit") {
                shop.addPet(new Rabbit(petName));
            }
            else {
                std::cout << "Invalid pet type." << std::endl;
            }
            break;
        }
        case 2: {
            std::string petName;
            std::cout << "Enter the name of the pet to remove: ";
            std::cin >> petName;
            shop.removePet(petName);
            break;
        }
        case 3: {
            std::string petName;
            std::cout << "Enter the name of the pet to find: ";
            std::cin >> petName;
            Pet* pet = shop.findPet(petName);
            if (pet) {
                pet->showStatus();
            }
            break;
        }
        case 4: {
            std::string oldName, newName;
            std::cout << "Enter the current name of the pet: ";
            std::cin >> oldName;
            std::cout << "Enter the new name for the pet: ";
            std::cin >> newName;
            shop.updatePetName(oldName, newName);
            break;
        }
        case 5: {
            int days;
            std::cout << "Enter the number of days to simulate: ";
            std::cin >> days;
            for (int i = 0; i < days; ++i) {
                shop.simulateTimePassing();
            }
            break;
        }
        case 6: {
            std::string petName;
            std::cout << "Enter the name of the pet to check emotion: ";
            std::cin >> petName;
            shop.showPetEmotion(petName);
            break;
        }
        case 7:
            shop.listPets();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
