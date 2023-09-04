#ifndef CAT_H
#define CAT_H

#include "Pet.h"

class Cat : public Pet {
public:
    Cat(const string& name, const string& color, int price);
    void interact() override;
};

#endif
