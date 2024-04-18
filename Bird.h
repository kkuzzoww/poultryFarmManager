#pragma once

#include <string>
#include <vector>
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Egg.h"

class Bird 
{
public:
    Bird();

    Bird(const std::string &name);

    Bird(const std::string &name, int id);

    Bird(const std::string &name, int age, int birdId);

    void eat();

    void printBirdInfo() const;

    int getBirdId() const;

    virtual void updateBirdInfo();

protected:
    std::string name;
    int age, birdId, eggCounter;
    std::vector<Egg> eggs;
};
