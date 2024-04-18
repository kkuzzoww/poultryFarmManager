#pragma once
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Chicken.h"
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Rooster.h"
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/PoultryFarm.h"
#include <functional>

class ConcretePoultryFarm : public PoultryFarm
{
public:

    virtual void addChicken() override;
    virtual void addChicken(const Chicken &chicken) override;
    virtual void addChicken(const std::string &name) override;
    virtual void addChicken(const std::string &name, int id) override;


    virtual void addRooster() override;
    virtual void addRooster(const Rooster &rooster) override;
    virtual void addRooster(const std::string &name) override;
    virtual void addRooster(const std::string &name, int id) override;

    template<typename T>
    void feedPoultry(const std::vector<T> &poultry) {

        std::vector<std::thread> feedingThreads;

        for(auto &bird : poultry) {
            feedingThreads.push_back(std::thread([&bird]() { return bird } )); 
        }
        for(auto &thread : feedingThreads) {
            thread.join();
        }
    }

    virtual void printFarmInfo() const;

    const std::vector<Chicken>& getChickens() const;

    const std::vector<Rooster>& getRoosters() const;

private:
    std::vector<Chicken> chickens;
    std::vector<Rooster> roosters; 
};