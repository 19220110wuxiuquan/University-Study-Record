#ifndef TURTLE_H
#define TURTLE_H

#include "ElectronicPet.h"

class Turtle : public ElectronicPet {
public:
    Turtle(const string& petName);

    void interact() override;
    void performRandomAction() override;
};

#endif // TURTLE_H

