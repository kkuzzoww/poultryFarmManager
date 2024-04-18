#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Bird.h"
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Chicken.h"
#include <iostream>

Bird::Bird(const std::string &name, int age, int birdId) : name(name), age(age), birdId(birdId), eggCounter(0) { };

Bird::Bird() : generateUniqueName(), oneYear() {};

Bird::Bird(const std::string &name) : name(name), oneYear(), 0 {};

Bird::Bird(const std::string &name, int id) {};

void Bird::eat() {
    std::cout << name << " is eating!!" << '\n';
}

void Bird::printBirdInfo() const {
    std::cout << "Bird's name/id: " << name << ", Bird's age: " << age << '\n';
}

int Bird::getBirdId() const {
    return birdId;
}

void Bird::updateBirdInfo() {
    age++;
}