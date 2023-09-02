#ifndef CAT_H
#define CAT_H

#include "ElectronicPet.h"

class Cat : public ElectronicPet {
public:
    Cat(const string& petName);

    void interact() override;
    void performRandomAction() override;
};

#endif // CAT_H

