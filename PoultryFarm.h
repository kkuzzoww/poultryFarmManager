#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Bird.h"
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Chicken.h"
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Rooster.h"


class PoultryFarm 
{
public:
    PoultryFarm() {}

    virtual void addChicken() = 0;
    virtual void addChicken(const Chicken &chicken) = 0;
    virtual void addChicken(const std::string &name) = 0;
    virtual void addChicken(const std::string &name, int id) = 0;

    virtual void addRooster() = 0;
    virtual void addRooster(const Rooster &rooster) = 0;
    virtual void addRooster(const std::string &name) = 0;
    virtual void addRooster(const std::string &name, int id) = 0;

    virtual void printFarmInfo() const = 0;

    virtual ~PoultryFarm() {}

    template <typename T>
    void feedPoultry(const std::vector<T> &poultry);

};

template <typename T>
void PoultryFarm::feedPoultry(const std::vector<T> &poultry) {

    std::vector<std::thread> feedingThreads;

    for(auto &bird : poultry) {
        feedingThreads.push_back(std::thread(&T::eat, bird));
    }
    for(auto &thread : feedingThreads) {
        thread.join();
    }
}