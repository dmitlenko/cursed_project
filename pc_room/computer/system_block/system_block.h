#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class system_block {
	string cpu_type; 
	float cpu_freq; 
	float hdd_cap; 
	bool sb_cd; 
	float price; 
public:
	system_block() : cpu_type("x64"), cpu_freq(3.4), hdd_cap(1024), sb_cd(false), price(399.0) {}
	system_block(string ct, float cf, float hc, bool cd, float p) : cpu_type(ct), cpu_freq(cf), hdd_cap(hc), sb_cd(cd), price(p) {}
	system_block(const system_block& ss) : cpu_type(ss.cpu_type), cpu_freq(ss.cpu_freq), hdd_cap(ss.hdd_cap), sb_cd(ss.sb_cd), price(ss.price) {}

	void setCPUType(string c);
	void setCPUFreq(float f);
	void setHDDCap(float f);
	void setCD(bool b);
	void setPrice(float f);

	string getCPUType();
	float getCPUFreq();
	float getHDDCap();
	bool getCD();
	float getPrice();

	friend ostream& operator<< (ostream& os, system_block& ss);
	friend istream& operator>> (istream& is, system_block& ss);

	friend ofstream& operator<< (ofstream& os, system_block& ss);
	friend ifstream& operator>> (ifstream& is, system_block& ss);
};