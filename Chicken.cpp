#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Chicken.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

int Chicken::nextChickenId = 1;
int Chicken::nextAge = 1;

Chicken::Chicken() : Bird(generateUniqueName(), oneYear(), 0){
    chickenId = ++nextChickenId;
}

Chicken::Chicken(const std::string &name) : Bird(name, oneYear(), 0) {
    chickenId = ++nextChickenId;
}

Chicken::Chicken(const std::string &name, int id) : Bird(name, oneYear(), 0) {
    chickenId = ++nextChickenId;
    nextChickenId = std::max(nextChickenId, id + 1);
} // to fix initializind

void Chicken::cluck() const {
    std::cout << name << " unreasonably clucking kudkudah.." << '\n';
}

void Chicken::getSick() { //зробити сьогодні і добавити це в метод live()!!!!!!!!!!!
    if(getSickChance(30)) {
        isSick = true;
        layEgg_SICK();
    }
}

void Chicken::getRandomEggsQuantity() const {
    int eggsLayed = rand() % 9 + 16;
}

int Chicken::getRandomEggsQuantity_SICK(int min, int max) const { //debuff for a sick chicken
    if(min > max)
        std::swap(min, max);
    if(min == max)
        return min;
    int eggslayed = std::rand() & (max - min + 1) + min;
    //int eggsLayed = rand() % 4 + 6;

    return eggslayed;
}

void Chicken::checkFertilized(bool &isFertilized) {
    switch (isFertilized) {
        case true:
            std::cout << "An egg layed by " << 
                 name << " is fertilized! We waiting for some nestlings!\n";
                 ++fertilizedEggCounter;
            break;
        case false:
            std::cout << "An egg layed by " << 
                 name << " is not fertilized! We will eat this one!\n";
                 ++unfertilizedEggCounter;
            break;
    }
}

void Chicken::layEgg() {
    Egg egg;
    getRandomEggsQuantity();
    eggs.push_back(egg);

    bool isFertilized = (rand() % 100) < 35; // random chance by 35%
    checkFertilized(isFertilized);
    eggs.back().setFertilized(isFertilized);

    eggCounter++;
}

void Chicken::layEgg_SICK() { //to fix
    Egg egg;
    getRandomEggsQuantity_SICK(4, 13);
    eggs.push_back(egg);

    bool isFertilized = (rand() % 100) < 35; // random chance by 35%
    checkFertilized(isFertilized);
    eggs.back().setFertilized(isFertilized);

    eggCounter++;
}

void Chicken::die() {
    std::cout << "unfortunately, chicken, named " << name << " reached 10 years and died...\n";
    auto it = std::remove_if(chickens.begin(), chickens.end(), [this](const Chicken &chicken) 
        {
            return chicken.getChickenId() == getChickenId();
        });
    chickens.erase(it, chickens.end());
}

void Chicken::oneYear() { 
    age++;
    std::cout << name << " is now " << age << " years old" << '\n';
}

void Chicken::live() { 
    while (age < 10)  {
        age++;
        updateBirdInfo();
        printBirdInfo();
        if(getSickChance(35) && isSick == true) {
            getSick();
            std::cout << name << " got sick! Quantity of layed eggs is reduced!";
            std::vector<int> poulters = { ; };
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    die(); 
}

int Chicken::getChickenId() const {
    return chickenId; 
}

// !!! private section in the Chicken class

bool Chicken::getSickChance(int chance_SICK) const {
    return (std::rand() % 100) < chance_SICK;
}

std::string Chicken::generateUniqueName(){
    return "Chicken" + std::to_string(nextChickenId);
}

int Chicken::generateUniqueAge(){
    //std::srand(static_cast<unsigned int>(std::time(NULL)));
    return rand() % 10 + 1;
}



