#include "computer.h"

float computer::getPCPrice() { return price; }

ostream& operator<< (ostream& os, const computer& ss) {
    os << (system_block&)ss << (monitor&)ss << (keyboard&)ss << (mouse&)ss << "│ Цена сборки: " << ss.price << "$\n";
    return os;
}

istream& operator>> (istream& is, computer& ss) {
    is >> (system_block&)ss >> (monitor&)ss >> (keyboard&)ss >> (mouse&)ss ;

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите цену сборк ПК:             │\n╰─────────────────────────────────────╯\n " && !(is >> ss.price)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    return is;
}

ofstream& operator<< (ofstream& os, const computer& ss) {
    os << (system_block&)ss << (monitor&)ss << (keyboard&)ss << (mouse&)ss << ss.price << endl;
    return os;
}

ifstream& operator>> (ifstream& is, computer& ss) {
    is >> (system_block&)ss >> (monitor&)ss >> (keyboard&)ss >> (mouse&)ss >> ss.price;

    
    return is;
}

bool operator<(const computer& pc1, const computer& pc2) {
    return pc1.price < pc2.price;
}