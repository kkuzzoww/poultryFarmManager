#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/ConcretePoultryFarm.h"

void ConcretePoultryFarm::addChicken() {
    Chicken chicken;
    chickens.push_back(chicken);
}

void ConcretePoultryFarm::addChicken(const Chicken &chicken) {
    chickens.push_back(chicken);
}

void ConcretePoultryFarm::addChicken(const std::string &name) {
    Chicken chicken(name);
    chickens.push_back(chicken);
}

void ConcretePoultryFarm::addChicken(const std::string &name, int id) {
    Chicken chicken(name, id);
    chickens.push_back(chicken);
}

void ConcretePoultryFarm::addRooster() {
    Rooster rooster;
    roosters.push_back(rooster);
}

void ConcretePoultryFarm::addRooster(const Rooster &rooster) {
    roosters.push_back(rooster);
}

void ConcretePoultryFarm::addRooster(const std::string &name) {
    Rooster rooster(name);
    roosters.push_back(rooster);
}

void ConcretePoultryFarm::addRooster(const std::string &name, int id) {
    Rooster rooster(name, id);
    roosters.push_back(rooster);
}

void ConcretePoultryFarm::printFarmInfo() const {
    std::cout << "Chickens on the farm: " << std::endl;
    for(const auto &chicken : chickens) {
        chicken.printBirdInfo();
    }

    std::cout << "\nRoosters on the farm: " << std::endl;
    for(const auto &rooster : roosters) {
        rooster.printBirdInfo();
    }
}

const std::vector<Chicken>& ConcretePoultryFarm::getChickens() const {
    return chickens;
}

const std::vector<Rooster>& ConcretePoultryFarm::getRoosters() const {
    return roosters;
}