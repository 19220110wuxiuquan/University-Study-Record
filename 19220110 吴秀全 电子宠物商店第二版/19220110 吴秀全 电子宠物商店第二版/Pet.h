#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
using namespace std;

class Pet 
{
protected:
    string name;
    string emotion;

public:
    Pet(const string& petName);
    virtual ~Pet();

    virtual void showStatus() const = 0;
    virtual void interact() = 0;
    virtual void performRandomAction() = 0;
    virtual void ageOneDay() = 0;

    string getName() const;

    void setEmotion(const string& newEmotion);
    void showEmotion();
};

#endif // PET_H

