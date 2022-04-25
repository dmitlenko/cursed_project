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
    cout << "╭─────────────────────────────────────╮ \n│ Введите тип ЦП:                     │\n╰─────────────────────────────────────╯\n ";
    getline(is, ss.cpu_type);

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите частоту ЦП в ГГц:           │\n╰─────────────────────────────────────╯\n " && !(is >> ss.cpu_freq)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите вместимость ЖД в ГБ:        │\n╰─────────────────────────────────────╯\n " && !(is >> ss.hdd_cap)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите наличие CD (1/0):           │\n╰─────────────────────────────────────╯\n " && !(is >> ss.sb_cd)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

    while (cout << "╭─────────────────────────────────────╮ \n│ Введите цену ПК:                    │\n╰─────────────────────────────────────╯\n " && !(is >> ss.price)) {
        is.clear(); //clear bad input flag
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "╭─────────────────────────────────────╮ \n│ Введено неверное значение!          │\n╰─────────────────────────────────────╯\n";
    }

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