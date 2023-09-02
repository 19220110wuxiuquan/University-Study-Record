#ifndef ELECTRONICPET_H
#define ELECTRONICPET_H

#include "Pet.h"

class ElectronicPet : public Pet {
protected:
    int health;
    int maxHealth;
    int age;

public:
    ElectronicPet(const string& petName, int initialHealth, int maxAge);

    void ageOneDay() override;

    void showStatus() const override;
};

#endif // ELECTRONICPET_H

