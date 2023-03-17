#include <iostream>
#include <string>
#include "Automata.h"
using namespace std;

int main()
{
    string menu[] = { "Latte", "Espresso macchiato", "Americano ", "Cappuccino", "Coffee with milk"};
    int prices[] = {100, 110, 80, 110,70};
    
    Automata automat(menu, prices, 5);
    automat.on();
    cout << automat.getState()<<endl;
    automat.coin(100);
    cout << automat.getState() << endl;
    automat.cancel();
    cout << automat.getState() << endl;
    automat.coin(100);
    cout << automat.getState() << endl;

    automat.getMenu();
    automat.choice(1);
    cout << automat.getState() << endl;

    automat.check();
    cout << automat.getState() << endl;
   
    automat.coin(100);
    cout << automat.getState() << endl;
    automat.choice(1);
    cout << automat.getState() << endl;

    automat.check();
    cout << automat.getState() << endl;
    automat.cook();
    cout << automat.getState() << endl;
    automat.finish();
    cout << automat.getState() << endl;
}
