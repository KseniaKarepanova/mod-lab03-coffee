#include<iostream>
#include <string>
using namespace std;

class Automat
{
private:
	enum States { Off, Wait, Accept, Check, Cook }; //перечисляем состояния автомата
	int cash; //хранение текущей суммы
	string* menu; //меню
	int* prices;//цены
	States state;//состояние текущее
	int chosen; //выбранный напиток
	int count; //количество напитков в меню
public:
	Automat(string menu[], int prices[], int count);
	void on();
	void off();
	void coin(int summa);
	void getMenu();
	string getState();
	void choice(int chosen);
	void check();
	void cancel();
	void cook();
	void finish();
};
