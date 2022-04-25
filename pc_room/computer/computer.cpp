#include "computer.h"

float computer::getPCPrice() { return price; }

ostream& operator<< (ostream& os, const computer& ss) {
    os << (system_block&)ss << (monitor&)ss << (keyboard&)ss << (mouse&)ss << "│ Цена сборки: " << ss.price << "$\n";
    return os;
}

istream& operator>> (istream& is, computer& ss) {
    is >> (system_block&)ss >> (monitor&)ss >> (keyboard&)ss >> (mouse&)ss >> ss.price;
    return is;
}

ofstream& operator<< (ofstream& os, const computer& ss) {
    os << (system_block&)ss << (monitor&)ss << (keyboard&)ss << (mouse&)ss << ss.price << endl;
    return os;
}

ifstream& operator>> (ifstream& is, computer& ss) {
    is >> (system_block&)ss >> (monitor&)ss >> (keyboard&)ss >> (mouse&)ss;
    if(!(is>>ss.price)) ss.price = time(NULL);
    return is;
}

bool operator<(const computer& pc1, const computer& pc2) {
    return pc1.price < pc2.price;
}