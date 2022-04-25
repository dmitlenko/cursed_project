#include "system_block.h"

void system_block::setCPUType(string c) { cpu_type = c; }
void system_block::setCPUFreq(float f) { cpu_freq = f; }
void system_block::setHDDCap(float f) { hdd_cap = f; }
void system_block::setCD(bool b) { sb_cd = b; }
void system_block::setPrice(float f) { price = f; }

string system_block::getCPUType() { return cpu_type; }
float system_block::getCPUFreq() { return cpu_freq; }
float system_block::getHDDCap() { return hdd_cap; }
bool system_block::getCD() { return sb_cd; }
float system_block::getPrice() { return price; }

ostream& operator<< (ostream& os, system_block& ss) {
    os << "│ Системный блок:\n│  " << ss.cpu_type << " " << ss.cpu_freq << "ГГц, " << ss.hdd_cap << "ГБ, " << (ss.sb_cd ? "с" : "без") << " CD," << ss.price << "$" << endl;
    return os;
}

istream& operator>> (istream& is, system_block& ss) {
    is >> ss.cpu_type >> ss.cpu_freq >> ss.hdd_cap >> ss.sb_cd >> ss.price;
    return is;
}

ofstream& operator<< (ofstream& os, system_block& ss) {
    os << ss.cpu_type << ' ' << ss.cpu_freq << " " << ss.hdd_cap << " " << (ss.sb_cd ? 1 : 0) << " " << ss.price << " ";
    return os;
}

ifstream& operator>> (ifstream& is, system_block& ss) {
    is >> ss.cpu_type >> ss.cpu_freq >> ss.hdd_cap >> ss.sb_cd >> ss.price;
    return is;
}