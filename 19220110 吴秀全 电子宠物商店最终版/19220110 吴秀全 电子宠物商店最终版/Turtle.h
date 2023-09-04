#ifndef TURTLE_H
#define TURTLE_H

#include "Pet.h"

class Turtle : public Pet {
public:
    Turtle(const string& name, const string& color, int price);
    void interact() override;
};

#endif
