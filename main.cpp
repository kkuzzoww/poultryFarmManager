#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <exception>
#include <list>
#include <vector>
#include <thread>
#include <chrono>
#include <queue>
#include <algorithm>
#include <mutex>
#include <time.h>
#include "/Users/dmytrokuzan/Desktop/projects/c++/poultryfarm (IMPORTANT)/headers/ConcretePoultryFarm.h"

int main()
{

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    ConcretePoultryFarm cpf;
    std::vector<std::thread> lifeThreads;

    std::cout << "ya v ahue" << '\n' << '\n';

    Chicken chickendenis("kha",16);
        // chickendenis.layEgg();
        // chickendenis.layEgg();
        // chickendenis.layEgg();
        // chickendenis.cluck();
        // chickendenis.getBirdId(); // !! фикс
        // chickendenis.printBirdInfo();

    Chicken chickenn("pohuy;", 1123);
        // chickenn.layEgg();
        // chickenn.layEgg();
        // chickenn.layEgg();
        // chickenn.cluck();
        // chickenn.getBirdId(); // !! фикс
        // chickenn.printBirdInfo();

    std::vector<Chicken> chickens;
    chickens.push_back(chickendenis);
    chickens.push_back(chickenn);

    for(auto chicken : chickens) {
        chicken.layEgg();
        chicken.layEgg();
        chicken.cluck();
        chicken.getChickenId();
        chicken.printBirdInfo();
        chicken.live();
    }


    // Rooster roosterden("denis", 18);
    //     roosterden.printBirdInfo();
    //     roosterden.crow();
    //     roosterden.getBirdId();
    //     roosterden.getRoosterId();

    // Rooster roosterya("dima", 18);
    //     roosterya.printBirdInfo();
    //     roosterya.crow();
    //     roosterya.getBirdId(); // !! фикс
    //     roosterya.getRoosterId();
    
    // Rooster roostertoha("anton", 214);
    //     roostertoha.printBirdInfo();
    //     roostertoha.crow();
    //     roostertoha.getBirdId();
    //     roostertoha.getRoosterId();

    // Rooster roostermike("misha)", 18);
    //     roostermike.printBirdInfo();
    //     roostermike.crow();
    //     roostermike.getBirdId();
    //     roostermike.getRoosterId();
    
    // Rooster roostertechfleece("ilya", 20);
    //     roostertechfleece.printBirdInfo();
    //     roostertechfleece.crow();
    //     roostertechfleece.getBirdId();
    //     roostertechfleece.getRoosterId();

    // cpf.addChicken();
    // cpf.addChicken();
    // cpf.addChicken("nastya");
    // cpf.addChicken("daa", 16);

    // cpf.addRooster();
    // cpf.addRooster();
    // cpf.addRooster("timur");
    // cpf.addRooster("dima", 18);

    // cpf.addRooster(roostermike);
    // cpf.addRooster(roosterya);
    // cpf.addRooster(roostertechfleece);
    // cpf.addRooster(roosterden);

    cpf.addChicken(chickenn);

    cpf.printFarmInfo();
    std::cout << std::endl << "/t====== FEEDING IN PROCESS   ======/t" << std::endl;

    cpf.feedPoultry(cpf.getChickens());



    

}