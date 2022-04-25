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
    cout << "╭─────────────────────────────────────╮ \n│ Введите тип клавиатуры:             │\n╰─────────────────────────────────────╯\n";
    getline(is, ss.type);

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │\n╰─────────────────────────────────────╯\n " && !(is >> ss.keys)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите цену клавиатуры:            │\n╰─────────────────────────────────────╯\n " && !(is >> ss.price)) {
        is.clear(); //clear bad input flag           
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

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