#ifndef FISH_H
#define FISH_H

#include "Pet.h"

class Fish : public Pet {
public:
    Fish(const string& name, const string& color, int price);
    void interact() override;
};

#endif

