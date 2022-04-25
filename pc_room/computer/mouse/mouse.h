#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class mouse {
	string type; // optical/mechanical
	int keys; // кількість кнопок
	float price; // ціна
public:
	mouse() : type("optical"), keys(3), price(29.0) {}
	mouse(const mouse& m) : type(m.type), keys(m.keys), price(m.price) {}
	mouse(string type, int keys, float price) : type(type), keys(keys), price(price) {}

	void setType(string t);
	void setKeys(int t);
	void setPrice(float t);

	string getType();
	int getKeys();
	float getPrice();

	friend ostream& operator<< (ostream& os, mouse& ss);
	friend istream& operator>> (istream& is, mouse& ss);

	friend ofstream& operator<< (ofstream& os, mouse& ss);
	friend ifstream& operator>> (ifstream& is, mouse& ss);
};