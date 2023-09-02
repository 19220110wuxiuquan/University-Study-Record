#ifndef FISH_H
#define FISH_H

#include "ElectronicPet.h"

class Fish : public ElectronicPet 
{

public:
    Fish(const string& petName);

    void interact() override;
    void performRandomAction() override;
};

#endif // FISH_H

