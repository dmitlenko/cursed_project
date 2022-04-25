#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "keyboard/keyboard.h"
#include "monitor/monitor.h"
#include "mouse/mouse.h"
#include "system_block/system_block.h"

using namespace std;

class computer : public system_block, public monitor, public keyboard, public mouse {
	float price; // цена всего пк
public:
	computer() : system_block(), monitor(), keyboard(), mouse(), price(100.0) { }
	computer(string cpu_t, float cpu_f, float hdd_c, bool cd, float diag, int freq, string ktype, int kkeys, string mtype, int mkeys, float price) :
		system_block(cpu_t, cpu_f, hdd_c, cd, price), monitor(diag, freq, price), keyboard(ktype, kkeys, price), mouse(mtype, mkeys, price), price(price) {}
	computer(const system_block& sb, const monitor& mn, const keyboard& kb, const mouse& ms, float price) : system_block(sb), monitor(mn), keyboard(kb), mouse(ms), price(price) {}

	float getPCPrice();

	friend ostream& operator<< (ostream& os, const computer& ss);
	friend istream& operator>> (istream& is, computer& ss);

	friend ofstream& operator<< (ofstream& os, const computer& ss);
	friend ifstream& operator>> (ifstream& is, computer& ss);

	friend bool operator<(const computer& pc1, const computer& pc2);
};