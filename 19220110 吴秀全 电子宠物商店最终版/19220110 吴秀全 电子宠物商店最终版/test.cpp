#include <iostream>
#include <string>
#include "Pet.h"
#include "PetShop.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"
#include "Fish.h"
#include "Turtle.h"
using namespace std;
int main() 
{
    srand(time(NULL));
    PetShop shop;
    shop.addPet(new Cat("Whiskers", "gray", 50));
    shop.addPet(new Dog("Buddy", "brown", 60));
    shop.addPet(new Rabbit("Fluffy", "white", 40));
    shop.addPet(new Turtle("Shelly", "green", 70));
    shop.addPet(new Fish("Nemo", "orange", 30));
    int choice;
    do {
        cout << "\nPet Shop Menu" << endl;
        cout << "1. List Pets" << endl;
        cout << "2. Interact with Pet" << endl;
        cout << "3. Simulate Time Passing" << endl;
        cout << "4. Show Pet Emotion" << endl;
        cout << "5. Add Pet" << endl;
        cout << "6. Remove Pet" << endl;
        cout << "7. Find Pet" << endl;
        cout << "8. Count Pets" << endl;
        cout << "9. Update Pet Name" << endl;
        cout << "10. Save Pet Data" << endl;
        cout << "11. Load Pet Data" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            shop.listPets();
            break;
        case 2: {
            string petName;
            cout << "Enter the name of the pet you want to interact with: ";
            cin >> petName;
            shop.interactWithPet(petName);
            break;
        }
        case 3:
            shop.simulateTimePassing();
            break;
        case 4: {
            string petName;
            cout << "Enter the name of the pet you want to check: ";
            cin >> petName;
            shop.showPetEmotion(petName);
            break;
        }
        case 5: {
            int type;
            cout << "Select Pet Type:" << endl;
            cout << "1. Cat" << endl;
            cout << "2. Dog" << endl;
            cout << "3. Rabbit" << endl;
            cout << "4. Fish" << endl;
            cout << "5. Turtle" << endl;
            cout << "Enter the type of pet: ";
            cin >> type;

            string name, color;
            cout << "Enter the name of the pet: ";
            cin >> name;
            cout << "Enter the color of the pet: ";
            cin >> color;

            int price;
            cout << "Enter the price of the pet: ";
            cin >> price;

            Pet* pet = nullptr;
            switch (type) {
            case 1:
                pet = new Cat(name, color, price);
                break;
            case 2:
                pet = new Dog(name, color, price);
                break;
            case 3:
                pet = new Rabbit(name, color, price);
                break;
            case 4:
                pet = new Fish(name, color, price);
                break;
            case 5:
                pet = new Turtle(name, color, price);
                break;
            default:
                cout << "Invalid pet type." << endl;
                break;
            }

            if (pet) {
                shop.addPet(pet);
                cout << "Pet added." << endl;
            }
            break;
        }
        case 6: {
            string petName;
            cout << "Enter the name of the pet to remove: ";
            cin >> petName;
            shop.removePet(petName);
            break;
        }
        case 7: {
            string petName;
            cout << "Enter the name of the pet to find: ";
            cin >> petName;
            Pet* foundPet = shop.findPet(petName);
            if (foundPet) {
                cout << "Pet found: " << foundPet->getName() << endl;
            }
            else {
                cout << "Pet not found." << endl;
            }
            break;
        }
        case 8:
            cout << "Number of pets: " << shop.countPets() << endl;
            break;
        case 9: {
            string oldName, newName;
            cout << "Enter the name of the pet to update: ";
            cin >> oldName;
            cout << "Enter the new name: ";
            cin >> newName;
            shop.updatePetName(oldName, newName);
            break;
        }
        case 10: {
            string filename;
            cout << "Enter the filename to save pet data: ";
            cin >> filename;
            shop.saveDataToFile(filename);
            cout << "Pet data saved to '" << filename << "'." << endl;
            break;
        }
        case 11: {
            string filename;
            cout << "Enter the filename to load pet data: ";
            cin >> filename;
            shop.loadDataFromFile(filename);
            cout << "Pet data loaded from '" << filename << "'." << endl;
            break;
        }
        case 0:
            cout << "Exiting the Pet Shop. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
