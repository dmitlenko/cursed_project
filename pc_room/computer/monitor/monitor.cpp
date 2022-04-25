#include "monitor.h"

void monitor::setDiaglonal(float t) { diagonal = t; }
void monitor::setFreq(int t) { freq = t; }
void monitor::setPrice(float t) { price = t; }

float monitor::getDiagonal() { return diagonal; }
int monitor::getFreq() { return freq; }
float monitor::getPrice() { return price; }

ostream& operator<< (ostream& os, monitor& ss) {
    os << "│ Монитор:\n│  " << ss.diagonal << "\" " << ss.freq << "Hz, " << ss.price << "$\n";
    return os;
}

istream& operator>> (istream& is, monitor& ss) {
    is >> ss.diagonal >> ss.freq >> ss.price;
    return is;
}

ofstream& operator<< (ofstream& os, monitor& ss) {
    os << ss.diagonal << " " << ss.freq << " " << ss.price << " ";
    return os;
}

ifstream& operator>> (ifstream& is, monitor& ss) {
    is >> ss.diagonal >> ss.freq >> ss.price;
    return is;
}