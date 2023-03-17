//Copyright 2022 UNN_IASR

#include <iostream>
#include <string>
#include "Automata.h"

int main()
{
    std::string menu[] = {"Latte", "Espresso", "Americano"};
    int prices[] = {100, 110, 80};
    Automata automat(menu, prices, 3);
    automat.on();
    std::cout << automat.getState() << std::endl;
    automat.coin(100);
    std::cout << automat.getState() << std::endl;
    automat.cancel();
    std::cout << automat.getState() << std::endl;
    automat.coin(100);
    std::cout << automat.getState() << std::endl;
    automat.getMenu();
    automat.choice(1);
    std::cout << automat.getState() << std::endl;
    automat.check();
    std::cout << automat.getState() << std::endl;
    automat.coin(100);
    std::cout << automat.getState() << std::endl;
    automat.choice(1);
    std::cout << automat.getState() << std::endl;
    automat.check();
    std::cout << automat.getState() << std::endl;
    automat.cook();
    std::cout << automat.getState() << std::endl;
    automat.finish();
    std::cout << automat.getState() << std::endl;
}
