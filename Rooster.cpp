#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/Rooster.h"
#include <iostream>
#include <algorithm>

int Rooster::nextRoosterId = 1;
int Rooster::nextAge = 1;

Rooster::Rooster() : Bird(generateUniqueName(), generateUniqueAge(), 0){
    roosterId = ++nextRoosterId;
}

Rooster::Rooster(const std::string &name) : Bird(name, generateUniqueAge(), 0) {
    roosterId = ++nextRoosterId;
}



Rooster::Rooster(const std::string &name, int id) : Bird(name, generateUniqueAge(), 0) {
    roosterId = ++nextRoosterId;
    nextRoosterId = std::max(nextRoosterId, id + 1);
}

void Rooster::crow() const {
    std::cout << name << " unreasonably crowing KUKAREKUU.." << '\n';
    
}

int Rooster::getRoosterId() const {
    return roosterId;
}

std::string Rooster::generateUniqueName() {
    return "Rooster" + std::to_string(nextRoosterId);
}

int Rooster::generateUniqueAge(){
    //std::srand(static_cast<unsigned int>(std::time(NULL)));
    return rand() % 10 + 1;
}