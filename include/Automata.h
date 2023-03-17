//Copyright 2022 UNN_IASR
#pragma once

#include<iostream>
#include <string>

class Automata {
private:
    enum States { Off, Wait, Accept, Check, Cook };
    int cash;
    std::string* menu;
    int* prices;
    States state;
    int chosen;
    int count;
public:
    Automata(std::string menu[], int prices[], int count);
    void on();
    void off();
    void coin(int summa);
    void getMenu();
    std::string getState();
    void choice(int chosen);
    void check();
    void cancel();
    void cook();
    void finish();
};
