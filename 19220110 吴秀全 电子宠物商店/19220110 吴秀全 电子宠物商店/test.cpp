#include"petshop.h"
int main() {
    PetShop shop;

    shop.addPet(new Cat("Whiskers", "gray"));
    shop.addPet(new Dog("Buddy", "brown"));
    shop.addPet(new Rabbit("Fluffy", "white"));
    shop.addPet(new Turtle("Shelly", "green"));
    shop.addPet(new Fish("Nemo", "orange"));

    int days;
    cout << "Enter the number of days to simulate: ";
    cin >> days;

    for (int i = 0; i < days; ++i) 
    {
        shop.simulateTimePassing();
    }

    cout << "Welcome to the Pet Shop!" << endl;
    shop.listPets();

    string petName;
    cout << "Enter the name of the pet you want to interact with: ";
    cin >> petName;
    shop.interactWithPet(petName);

    return 0;
}