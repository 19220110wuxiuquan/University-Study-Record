#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet {
public:
    Dog(const string& name, const string& color, int price);
    void interact() override;
};

#endif

