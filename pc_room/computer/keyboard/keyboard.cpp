#include "keyboard.h"

void keyboard::setType(string t) { type = t; }
void keyboard::setKeys(int t) { keys = t; }
void keyboard::setPrice(float t) { price = t; }

string keyboard::getType() { return type; }
int keyboard::getKeys() { return keys; }
float keyboard::getPrice() { return price; }

ostream& operator<< (ostream& os, keyboard& ss) {
    os << "│ Клавиатура:\n│  " << ss.type << ", " << ss.keys << " кнопок, " << ss.price << "$\n";
    return os;
}

istream& operator>> (istream& is, keyboard& ss) {
    is >> ss.type;
    if (!(is >> ss.keys)) ss.keys = 0;
    if (!(is >> ss.price)) ss.price = 0.0;
    return is;
}

ofstream& operator<< (ofstream& os, keyboard& ss) {
    os << ss.type << " " << ss.keys << " " << ss.price << " ";
    return os;
}

ifstream& operator>> (ifstream& is, keyboard& ss) {
    is >> ss.type >> ss.keys >> ss.price;
    return is;
}