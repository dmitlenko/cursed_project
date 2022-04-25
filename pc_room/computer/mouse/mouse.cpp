#include "mouse.h"

void mouse::setType(string t) { type = t; }
void mouse::setKeys(int t) { keys = t; }
void mouse::setPrice(float t) { price = t; }

string mouse::getType() { return type; }
int mouse::getKeys() { return keys; }
float mouse::getPrice() { return price; }

ostream& operator<< (ostream& os, mouse& ss) {
    os << "│ Мышь:\n│  " << ss.type << ", " << ss.keys << " keys, " << ss.price << "$\n";
    return os;
}

istream& operator>> (istream& is, mouse& ss) {
    cout << "╭─────────────────────────────────────╮ \n│ Введите тип мыши:                   │\n╰─────────────────────────────────────╯\n";
    getline(is, ss.type);

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │\n╰─────────────────────────────────────╯\n " && !(is >> ss.keys)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите цену мыши:                  │\n╰─────────────────────────────────────╯\n " && !(is >> ss.price)) {
        is.clear(); //clear bad input flag           
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    return is;
}

ofstream& operator<< (ofstream& os, mouse& ss) {
    os << ss.type << " " << ss.keys << " " << ss.price << " ";
    return os;
}

ifstream& operator>> (ifstream& is, mouse& ss) {
    is >> ss.type >> ss.keys >> ss.price;
    return is;
}