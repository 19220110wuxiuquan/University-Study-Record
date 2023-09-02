#ifndef DOG_H
#define DOG_H

#include "ElectronicPet.h"

class Dog : public ElectronicPet {
public:
    Dog(const string& petName);

    void interact() override;
    void performRandomAction() override;
};

#endif // DOG_H

