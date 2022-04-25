#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class keyboard {
	string type; 
	int keys; 
	float price; 
public:
	keyboard() : type("full"), keys(101), price(19.0) {}
	keyboard(const keyboard& k) : type(k.type), keys(k.keys), price(k.price) {}
	keyboard(string type, int keys, float price) : type(type), keys(keys), price(price) {}

	void setType(string t);
	void setKeys(int t);
	void setPrice(float t);

	string getType();
	int getKeys();
	float getPrice();

	friend ostream& operator<< (ostream& os, keyboard& ss);
	friend istream& operator>> (istream& is, keyboard& ss);

	friend ofstream& operator<< (ofstream& os, keyboard& ss);
	friend ifstream& operator>> (ifstream& is, keyboard& ss);
};