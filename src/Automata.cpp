#include "Automat.h"

Automat::Automat(string menu1[], int prices1[], int count1) {
    cash = 0;
    state = Off;
    menu = menu1;
    prices = prices1;
    count = count1;
    chosen = -1;
}
void Automat::on() {
    if(state==Off)
    state = Wait;
}
void Automat::off() {
    if(state==Wait)
    state = Off;
}
void Automat::coin(int summa) {
    if ((state == Wait) || (state == Accept)) {
        state = Accept;
        cash = cash + summa;
    }  
}
void Automat::getMenu() {
   
    cout << "Menu:" << endl;
    for (int i = 0; i < count; i++) {
        cout << to_string(i) + ":" + menu[i] + "   cost   " + to_string(prices[i])+"rub." << endl;
        
    }
}
string Automat::getState() {
    if (state == Off) return "Off";
    if (state == Wait) return "Wait";
    if (state == Accept) return "Accept";
    if (state == Check) return "Check";
    if (state == Cook) return "Cook";
}
void Automat::choice(int id_chosen) {
    if (state == Accept) {
        chosen = id_chosen;
        cout << "Your choice" << to_string(chosen) << endl;
        state = Check;
    }
   
}
void Automat::check() {
    if (state == Check) {
        if (cash >= prices[chosen]) {
            cash = cash - prices[chosen];
            cout << "There is enough money in the account" << endl;
            cout << "Your change " + to_string(cash) << endl;
            state = Cook;
            chosen = -1;
        } else {
            state = Accept;
            cout << "There is not enough money in the account" << endl;
        }
    }
       
}
void Automat::cancel() {
    if ((state == Accept) || (state == Check)) {
        state = Wait;
        cash = 0;
        chosen = -1;
    }
   
}
void Automat::cook() {
    if (state == Cook)
        cout << "the drink is being prepared" << endl;

}
void Automat::finish() {
    if (state == Cook) {
        state = Wait;
        chosen = -1;
    }
    
}
