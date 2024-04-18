#pragma once
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Bird.h"
#include <algorithm>

class Rooster : public Bird
{
public:
    Rooster();

    Rooster(const std::string &name);

    Rooster(const std::string &name, int id);

    void crow() const;

    int getRoosterId() const;

private:

    int roosterId;
    static int nextRoosterId;
    static int nextAge;

    static std::string generateUniqueName();

    static int generateUniqueAge();

    std::vector<Rooster> roosters;
};
