#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Egg.h"

Egg::Egg() : isFertilized(false) {}

void Egg::setFertilized(bool fertilized) {
    isFertilized = fertilized;
}

bool Egg::getFertilized() const {
    return isFertilized;
}