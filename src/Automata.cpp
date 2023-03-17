//Copyright 2022 UNN_IASR
#include "Automata.h"

Automata::Automata(std::string menu1[], int prices1[], int count1) {
    cash = 0;
    state = Off;
    menu = menu1;
    prices = prices1;
    count = count1;
    chosen = -1;
}
void Automata::on() {
    if (state == Off)
    state = Wait;
}
void Automata::off() {
    if (state == Wait)
    state = Off;
}
void Automata::coin(int summa) {
    if ((state == Wait) || (state == Accept)) {
        state = Accept;
        cash = cash + summa;
    }
}
void Automata::getMenu() {
    std::cout << "Menu:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << std::to_string(i) + ":" + menu[i];
        std::cout << "   cost   " + std::to_string(prices[i]);
        std::cout << " rub." << std::endl;
    }
}
std::string Automata::getState() {
    switch (state) {
    case Off: return "Off";
    case Wait: return "Wait";
    case Accept: return "Accept";
    case Check: return "Check";
    case Cook: return "Cook";
    }
    return " ";
}
void Automata::choice(int id_chosen) {
    if (state == Accept) {
        chosen = id_chosen;
        std::cout << "Your choice" << std::to_string(chosen) << std::endl;
        state = Check;
    }
}
void Automata::check() {
    if (state == Check) {
        if (cash >= prices[chosen]) {
            cash = cash - prices[chosen];
            std::cout << "There is enough money in the account" << std::endl;
            std::cout << "Your change " + std::to_string(cash) << std::endl;
            state = Cook;
            chosen = -1;
        } else {
            state = Accept;
            std::cout << "There is not enough money" << std::endl;
        }
    }
}
void Automata::cancel() {
    if ((state == Accept) || (state == Check)) {
        state = Wait;
        cash = 0;
        chosen = -1;
    }
}
void Automata::cook() {
    if (state == Cook)
        std::cout << "the drink is being prepared" << std::endl;
}
void Automata::finish() {
    if (state == Cook) {
        state = Wait;
        chosen = -1;
    }
}
