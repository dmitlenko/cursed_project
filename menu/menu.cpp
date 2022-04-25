#include "menu.h"

int menu(){
    pc_room room;
	program_data prg;

	int input, subMenu = -1;

	while (true) {
		printTitle("Меню", false);

		switch (subMenu)
		{
		case 0:
			cout << "├──────────┬────────────┬─────────────┤\n"
				<< "│ (F) Файл │ (E) Правка │ (A) Cправка │\n"
				<< "├──────────┴───────────┬┴─────────────╯\n"
				<< "│ (1) Новый список     │\n"
				<< "│ (2) Открыть список   │\n"
				<< "│ (3) Сохранить список │\n"
				<< "│ (4) Выйти            │\n"
				<< "╰──────────────────────╯\n";

			break;
		case 1:
			cout << "├──────────┬────────────┬─────────────┤\n"
				<< "│ (F) Файл │ (E) Правка │ (A) Cправка │\n"
				<< "╰──────────┼────────────┴─────────────┴╮\n"
				<< "           │ (1) Добавить элемент      │\n"
				<< "           │ (2) Редактировать элемент │\n"
				<< "           │ (3) Удалить элемент       │\n"
				<< "           │ (4) Найти элемент         │\n"
				<< "           │ (5) Вывести список        │\n"
				<< "           ╰───────────────────────────╯\n";
			break;
		case 2:
			cout << "├──────────┬────────────┬─────────────┤\n"
				<< "│ (F) Файл │ (E) Правка │ (A) Cправка │\n"
				<< "╰──────────┴────────────┼─────────────┴───╮\n"
				<< "                        │ (1) Помощь      │\n"
				<< "                        │ (2) О программе │\n"
				<< "                        ╰─────────────────╯\n";
			break;
		default:
			cout << "├──────────┬────────────┬─────────────┤\n"
				<< "│ (F) Файл │ (E) Правка │ (A) Cправка │\n"
				<< "╰──────────┴────────────┴─────────────╯\n";
			break;
		}

		input = _getch();

		switch (input)
		{
		case 'F': case 'f':
			subMenu = 0;
			break;
		case 'E': case 'e':
			subMenu = 1;
			break;
		case 'A': case 'a':
			subMenu = 2;
			break;
		case 27: // esc button
			if (subMenu > -1) subMenu = -1;
			else if (acceptQuery("╭─────────────────────────────────────╮ \n│ Завершить работу?                   │ \n╰─────────────────────────────────────╯ \n")) return 0;
			break;
		case '1':
			switch (subMenu)
			{
			case 0:
				room.newlist(); //Новый список
				subMenu = -1;
				break;
			case 1:
				room.add(false); // Добавить элемент
				subMenu = -1;
				break;
			case 2:
				prg.help(); // Помощь
				subMenu = -1;
				break;
			default:
				break;
			}
			break;
		case '2':
			switch (subMenu)
			{
			case 0:
				room.load(); // Открыть список
				subMenu = -1;
				break;
			case 1:
				room.edit(); // Редактировать элемент
				subMenu = -1;
				break;
			case 2:
				prg.about(); // О программе
				subMenu = -1;
				break;
			default:
				break;
			}
			break;
		case '3':
			switch (subMenu)
			{
			case 0:
				room.save(); // Сохранить список
				subMenu = -1;
				break;
			case 1:
				room.del(); // Удалить элемент
				subMenu = -1;
				break;
			default:
				break;
			}
			break;
		case '4':
			switch (subMenu)
			{
			case 0:
				if (acceptQuery("╭─────────────────────────────────────╮ \n│ Завершить работу?                   │ \n╰─────────────────────────────────────╯ \n")) return 0; //Выйти
				break;
			case 1:
				room.find(); // Найти элемент
				subMenu = -1;
				break;
			default:
				break;
			}
			break;
		case '5':
			switch (subMenu)
			{
			case 1:
				room.print(); // Вывести список
				subMenu = -1;
				break;
			default:
				break;
			}
			break;
		default:

			break;
		}
	}
}