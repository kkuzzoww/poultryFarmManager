#pragma once
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Bird.h"
#include <vector>

class Chicken : public Bird
{
public:
    Chicken();

    Chicken(const std::string &name);

    Chicken(const std::string &name, int id);

    void cluck() const;

    void getSick();

    void getRandomEggsQuantity() const;

    int getRandomEggsQuantity_SICK(int min, int max) const;

    void checkFertilized(bool &isFertilized);
    void layEgg();

    void layEgg_SICK();

    void die();
    void oneYear();
    void live();

    int getChickenId() const;

    

private:

    bool isSick;
    bool getSickChance(int chance_SICK) const;

    int chickenId, fertilizedEggCounter, unfertilizedEggCounter;
    static int nextChickenId;
    static int nextAge;

    static std::string generateUniqueName();

    static int generateUniqueAge();

    std::vector<Chicken> chickens;
};
