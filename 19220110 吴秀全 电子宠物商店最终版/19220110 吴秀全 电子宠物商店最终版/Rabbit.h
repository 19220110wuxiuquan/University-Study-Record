#ifndef RABBIT_H
#define RABBIT_H

#include "Pet.h"

class Rabbit : public Pet {
public:
    Rabbit(const string& name, const string& color, int price);
    void interact() override;
};

#endif

