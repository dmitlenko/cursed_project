#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class monitor {
	float diagonal; 
	int freq; 
	float price; 
public:
	monitor() : diagonal(15.6), freq(60), price(79.0) {}
	monitor(const monitor& m) : diagonal(m.diagonal), freq(m.freq), price(m.price) {}
	monitor(float diag, int freq, float price) : diagonal(diag), freq(freq), price(price) {}

	void setDiaglonal(float t);
	void setFreq(int t);
	void setPrice(float t);

	float getDiagonal();
	int getFreq();
	float getPrice();

	friend ostream& operator<< (ostream& os, monitor& ss);
	friend istream& operator>> (istream& is, monitor& ss);

	friend ofstream& operator<< (ofstream& os, monitor& ss);
	friend ifstream& operator>> (ifstream& is, monitor& ss);
};