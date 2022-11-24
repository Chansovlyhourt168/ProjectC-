#pragma once
#include <iostream>
#include "Flight.cpp"
using namespace std;
class FirstClass : public Flight{
private:
	string food;
public:
	FirstClass() : Flight(), food("Null") {}
	FirstClass(int ticket_number, string name, double price, string food) : Flight(ticket_number, name, price), food(food) {}
	~FirstClass() {

	}
	void set_food(string food) {
		this->food = food;
	}
	string get_food() {
		return food;
	}
	void input() {
		Flight::input();
		cout << "Enter Food : ";
		cin >> food;
	}
	void output() {
		Flight::output();
		cout << food << endl;
	}
};