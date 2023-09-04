#ifndef PET_H
#define PET_H
#include <string>
using namespace std;
class Pet 
{
protected:
    string name;
    int age;
    string color;
    string emotion;
    int maxAge;
    int price;
public:
    Pet(const string& name, const string& color, int maxAge, int price);
    virtual ~Pet() 
    {}
    virtual void showStatus() const;
    virtual void interact() 
    {}
    void grow();
    string getName() const;
    int getAge() const;  
    string getColor() const;
    void setName(const string& newName);
    void setEmotion(const string& newEmotion);
    void showEmotion();
    int getPrice() const;
    void feed();
    void giveWater();
    void takeToBathroom();
    void play();
    void putToSleep();
    void seeDoctor();
    void ageOneYear();
    void performRandomAction();
};

#endif


