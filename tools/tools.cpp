#include "tools.h"

string GetTime() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d.%m.%Y", timeinfo);
	string str(buffer);

	strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);
	string str2(buffer);

	return str2 + " " + str;
}

void PrintConsoleBottomRight(string str) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	COORD coord = { csbi.srWindow.Right - str.length(), 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << str;

	coord = { csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void wait(string text) {
	cout << text; _getch();
}

void waitForEsc(string text) {
	cout << text;
	while (_getch() != 27) {}
}

void printTitle(string title, bool seamless) {
	int len = wstring_convert< codecvt_utf8<char32_t>, char32_t >{}.from_bytes(title).size();
	system("cls");
	PrintConsoleBottomRight("Время: " + GetTime());
	cout << "╭─┤ Компьютерный класс ├────────┤esc├─╮ \n";
	cout << "│ " << title << string(35 - len, ' ') << " │\n";
	if (seamless) cout << "├─────────────────────────────────────┤ \n";
}

bool acceptQuery(string query, bool custom) {
	int len = wstring_convert< codecvt_utf8<char32_t>, char32_t >{}.from_bytes(query).size();
	
	if (!custom)
		cout << "╭─────────────────────────────────────╮ \n"
		<< "│ " << query << string(35 - len, ' ') << " │ \n"
		<< "╰─────────────────────────────────────╯ \n"
		<< " (y/n): ";
	else cout << query << " (y/n): ";
	
	while (true) {
		switch (_getch())
		{
		case '1':
		case 'y':
		case 'Y':
			cout << "\33[2K\r";
			return true;
		default:
			cout << "\33[2K\r";
			return false;
			break;
		}
	}
}
