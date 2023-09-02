#ifndef RABBIT_H
#define RABBIT_H

#include "ElectronicPet.h"

class Rabbit : public ElectronicPet 
{
public:
    Rabbit(const string& petName);

    void interact() override;
    void performRandomAction() override;
};

#endif 
