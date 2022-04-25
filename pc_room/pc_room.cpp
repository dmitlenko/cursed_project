#include "pc_room.h"

float str_to_float(string s) {
	// Check string is float
	if (!regex_match(s,regex("/(\d+(?:\.\d+)?)/"))) return -1;
	return atof(s.c_str());
}

void pc_room::print() {
	printTitle("Вывести список", false);
	cout << "╰─────────────────────────────────────╯ \n";

	int i = 0, n = pc_pq.size();
	priority_queue<computer> t = pc_pq;

	while (!t.empty())
	{
		cout << "╭─────────────────────────────────────╮\n";
		printf("│ ПК №%3d                             │ \n", ++i);
		cout << "├─────────────────────────────────────╯ \n";
		cout << t.top();
		t.pop();
		cout << "╰────────────────────────────────────── \n";
	}

	wait();
}

void pc_room::print(string title, priority_queue<computer> v) {
	printTitle(title, false);
	cout << "╰─────────────────────────────────────╯ \n";

	int i = 0, n = v.size();
	priority_queue<computer> t = v;
	string namef;

	while (!t.empty())
	{
		cout << "╭─────────────────────────────────────╮\n";
		printf("│ ПК №%3d                             │ \n", ++i);
		cout << "├─────────────────────────────────────╯ \n";
		cout << t.top();
		t.pop();
		cout << "╰────────────────────────────────────── \n";
	}

	if (acceptQuery("╭─────────────────────────────────────╮ \n│ Сохранить в файл?                   │ \n╰─────────────────────────────────────╯\n")) {
		cout << "╭─────────────────────────────────────╮ \n│ Введите имя файла:                  │ \n╰─────────────────────────────────────╯ \n ";
		cin >> namef;
		ofstream g(namef, ios::out);

		if (g.is_open()) {
			g << pc_pq.size() << "\n";
			priority_queue<computer> t = pc_pq;

			while (!t.empty())
			{
				g << t.top();
				t.pop();
			}
			g.close();
			cout << "╭─────────────────────────────────────╮ \n│ Сохранено                           │ \n╰─────────────────────────────────────╯ \n";
		}
		else {
			cout << "╭─────────────────────────────────────╮ \n│ Файл не найден!                     │ \n╰─────────────────────────────────────╯ \n";
		}
	}

	wait();
}

void pc_room::add(bool silent = false) {
	printTitle("Добавить элемент");
	cout << "╰─────────────────────────────────────╯\n";
	
	system_block sb;
	monitor m;
	keyboard k;
	mouse ms;
	float p;

	cin >> sb >> m >> ms >> k >> p;	

	pc_pq.push(computer(sb, m, k, ms, p));

	if (!silent) wait("╭─────────────────────────────────────╮ \n│ Компьютер добавлен                  │ \n│ Нажмите любую кнопку чтобы продол - │ \n│ жить...                             │ \n╰─────────────────────────────────────╯ \n");
}

void pc_room::load() {
	printTitle("Открыть список", false);
	cout << "╰─────────────────────────────────────╯ \n";

	char sn[5];
	int n = 0;
	computer t;
	string namef = "computers.txt";
	if (acceptQuery("╭─────────────────────────────────────╮ \n│ Загрузить из стороннего файла?      │ \n╰─────────────────────────────────────╯ \n")) {
		printTitle("Открыть список", false);
		cout << "╰─────────────────────────────────────╯ \n";
		cout << "╭─────────────────────────────────────╮ \n│ Введите имя файла:                  │ \n╰─────────────────────────────────────╯ \n ";
		cin >> namef;
	}

	ifstream f(namef, ios::in);
	if (f.is_open()) {
		pc_pq = priority_queue<computer>();
		f.getline(sn, 5);
		n = atoi(sn);
		for (int i = 0; i < n; i++)
		{
			f >> t;
			pc_pq.push(t);
		};
		f.close();
		cout << "╭─────────────────────────────────────╮ \n│ Загружено                           │ \n╰─────────────────────────────────────╯ \n";
	}
	else {
		cout << "╭─────────────────────────────────────╮ \n│ Файл не найден!                     │ \n╰─────────────────────────────────────╯ \n";
	}

	wait();
}

void pc_room::save() {
	printTitle("Сохранить список", false);
	cout << "╰─────────────────────────────────────╯ \n";

	string namef = "computers.txt";
	if (acceptQuery("╭─────────────────────────────────────╮ \n│ Сохранить в новый файл?             │ \n╰─────────────────────────────────────╯ \n")) {

		printTitle("Сохранить список", false);
		cout << "╰─────────────────────────────────────╯ \n";
		cout << "╭─────────────────────────────────────╮ \n│ Введите имя файла:                  │ \n╰─────────────────────────────────────╯ \n ";
		cin >> namef;
	}

	ofstream g(namef, ios::out);

	if (g.is_open()) {
		g << pc_pq.size() << "\n";
		priority_queue<computer> t = pc_pq;

		while (!t.empty())
		{
			g << t.top();
			t.pop();
		}
		g.close();
		cout << "╭─────────────────────────────────────╮ \n│ Сохранено                           │ \n╰─────────────────────────────────────╯ \n";
	}
	else {
		cout << "╭─────────────────────────────────────╮ \n│ Файл не найден!                     │ \n╰─────────────────────────────────────╯ \n";
	}
	wait();
}

void pc_room::newlist() {
	printTitle("Новый список");

	int i = 0;

	if (acceptQuery("│ Очистить существующий список и соз- │\n│ дать новый список?                  │\n╰─────────────────────────────────────╯\n")) {
		pc_pq = priority_queue<computer>();
		while (true) {
			printTitle("Новый список");
			printf("│ ПК №%3d                             │ \n", ++i);
			cout << "├─────────────────────────────────────┤ \n";

			add(true);

			if (!acceptQuery("╭─────────────────────────────────────╮ \n│ Добавить еще ПК?                    │ \n╰─────────────────────────────────────╯ \n")) return;
		}
	}
}

void pc_room::del() {
	printTitle("Удалить элемент");

	int i = 0, n;

	cout << "│ Введите номер элемента:             │ \n╰─────────────────────────────────────╯ \n ";
	cin >> n;

	if (n < 1 || n > pc_pq.size()) {
		cout << "╭─────────────────────────────────────╮ \n│ Элемент не существует!              │ \n╰─────────────────────────────────────╯ \n";
		wait();
	}
	else {
		n--;
		priority_queue<computer> pq;

		while (i < n) {
			pq.push(pc_pq.top());
			pc_pq.pop();
			i++;
		}

		pc_pq.pop();

		while (!pq.empty()) {
			pc_pq.push(pq.top());
			pq.pop();
		}

		cout << "╭─────────────────────────────────────╮ \n│ Элемент удален.                     │ \n╰─────────────────────────────────────╯ \n";
		wait();
	}
}

computer pc_room::edit_helper(computer p) {


	int subMenu = 0, input, int_buff;
	float float_buff;
	string string_buff;

	system_block sb = (system_block&)p;
	monitor mr = (monitor&)p;
	keyboard kb = (keyboard&)p;
	mouse ms = (mouse&)p;
	float pr = p.getPCPrice();


	while (true) {
		printTitle("Редактировать элемент", false);
		cout << "├─────────────────────────────────────╯ \n";

		cout << sb << mr << kb << ms << "│ Цена сборки: " << pr << "$\n";;
		cout << "├─────────────────────────────────────╮\n";
		cout << "│ Нажмите ESC чтобы завершить редак-  │\n";
		cout << "│ тирование                           │\n";
		cout << "├─────────────────────────────────────┤\n";
		cout << "│ Поля для редактирования:            │\n";

		switch (subMenu)
		{
		case 0:
			cout << "├───────────────────┬─────┬─────┬─────┤\n";
			cout << "│ (S) Сис. блок     │ (M) │ (K) │ (O) │\n"
				<< "├───────────────────┴─────┴─────┴─────┤\n"
				<< "│ (1) Тип ЦП                          │\n"
				<< "│ (2) Частота ЦП                      │\n"
				<< "│ (3) Вместимость ЖД                  │\n"
				<< "│ (4) Наличие CD-привода              │\n"
				<< "│ (5) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 1:
			cout << "├─────┬───────────────────┬─────┬─────┤\n";
			cout << "│ (S) │ (M) Монитор       │ (K) │ (O) │\n"
				<< "├─────┴───────────────────┴─────┴─────┤\n"
				<< "│ (1) Диагональ                       │\n"
				<< "│ (2) Частота                         │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 2:
			cout << "├─────┬─────┬───────────────────┬─────┤\n";
			cout << "│ (S) │ (M) │ (K) Клавиатура    │ (O) │\n"
				<< "├─────┴─────┴───────────────────┴─────┤\n"
				<< "│ (1) Тип                             │\n"
				<< "│ (2) Количество кнопок               │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 3:
			cout << "├─────┬─────┬─────┬───────────────────┤\n";
			cout << "│ (S) │ (M) │ (K) │ (O) Мышь          │\n"
				<< "├─────┴─────┴─────┴───────────────────┤\n"
				<< "│ (1) Тип                             │\n"
				<< "│ (2) Количество кнопок               │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		default:
			break;
		}

		input = _getch();

		switch (input)
		{
		case 'S': case 's':
			subMenu = 0;
			break;
		case 'M': case 'm':
			subMenu = 1;
			break;
		case 'K': case 'k':
			subMenu = 2;
			break;
		case 'O': case 'o':
			subMenu = 3;
			break;
		case 27:
			if (acceptQuery("╭─────────────────────────────────────╮ \n│ Завершить редактирование?           │ \n╰─────────────────────────────────────╯ \n")) return computer(sb, mr, kb, ms, pr);
			break;
		case '1':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип ЦП:                     │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				sb.setCPUType(string_buff);
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите диагональ:                  │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				mr.setDiaglonal(str_to_float(string_buff));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип клавиатуры:             │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				kb.setType(string_buff);
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип мыши:                   │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				ms.setType(string_buff);
				break;
			default:
				break;
			}
			break;
		case '2':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите частоту ЦП:                 │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				sb.setCPUFreq(str_to_float(string_buff));
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите частоту:                    │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				mr.setFreq(int(str_to_float(string_buff)));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				kb.setKeys(int(str_to_float(string_buff)));
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				ms.setKeys(int(str_to_float(string_buff)));
				break;
			default:
				break;
			}
			break;
		case '3':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите вместимость ЖД:             │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				sb.setHDDCap(str_to_float(string_buff));
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				mr.setPrice(str_to_float(string_buff));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				kb.setPrice(str_to_float(string_buff));
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				ms.setPrice(str_to_float(string_buff));
				break;
			default:
				break;
			}
			break;
		case '4':
			switch (subMenu)
			{
			case 0:
				sb.setCD(acceptQuery("╭─────────────────────────────────────╮ \n│ Есть наличие CD-привода:            │ \n╰─────────────────────────────────────╯ \n "));
				break;
			default:
				break;
			}
			break;
		case '5':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
				sb.setPrice(str_to_float(string_buff));
				break;
			default:
				break;
			}
			break;
		default:

			break;
		}
	}

	return computer(sb, mr, kb, ms, pr);
}

void pc_room::edit() {
	printTitle("Редактировать элемент");

	int i = 0, n;
	computer b;

	cout << "│ Введите номер элемента:             │ \n╰─────────────────────────────────────╯ \n ";
	cin >> n;

	if (n < 1 || n > pc_pq.size()) {
		cout << "╭─────────────────────────────────────╮ \n│ Элемент не существует!              │ \n╰─────────────────────────────────────╯ \n";
		wait();
	}
	else {
		n--;
		priority_queue<computer> pq;

		while (i < n) {
			pq.push(pc_pq.top());
			pc_pq.pop();
			i++;
		}

		b = pc_pq.top();
		pc_pq.pop();
		pc_pq.push(edit_helper(b));

		while (!pq.empty()) {
			pc_pq.push(pq.top());
			pq.pop();
		}
	}
}

priority_queue<computer> pc_room::find_helper(float valuef, int valuei, string values, int field) {
	priority_queue<computer> v = pc_pq;
	priority_queue<computer> out;
	system_block sb;
	monitor mn;
	keyboard kb;
	mouse ms;

	switch (field)
	{
	case 1:
		while (!v.empty()) {
			sb = (system_block&)v.top();
			if (sb.getCPUType() == values) out.push(v.top());
			v.pop();
		}
		break;
	case 2:
		while (!v.empty()) {
			sb = (system_block&)v.top();
			if (sb.getCPUFreq() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 3:
		while (!v.empty()) {
			sb = (system_block&)v.top();
			if (sb.getHDDCap() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 4:
		while (!v.empty()) {
			sb = (system_block&)v.top();
			if (sb.getCD() == valuei) out.push(v.top());
			v.pop();
		}
		break;
	case 5:
		while (!v.empty()) {
			sb = (system_block&)v.top();
			if (sb.getPrice() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 6:
		while (!v.empty()) {
			mn = (monitor&)v.top();
			if (mn.getDiagonal() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 7:
		while (!v.empty()) {
			mn = (monitor&)v.top();
			if (mn.getFreq() == valuei) out.push(v.top());
			v.pop();
		}
		break;
	case 8:
		while (!v.empty()) {
			mn = (monitor&)v.top();
			if (mn.getPrice() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 9:
		while (!v.empty()) {
			ms = (mouse&)v.top();
			if (ms.getType() == values) out.push(v.top());
			v.pop();
		}
		break;
	case 10:
		while (!v.empty()) {
			ms = (mouse&)v.top();
			if (ms.getKeys() == valuei) out.push(v.top());
			v.pop();
		}
		break;
	case 11:
		while (!v.empty()) {
			ms = (mouse&)v.top();
			if (ms.getPrice() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	case 12:
		while (!v.empty()) {
			kb = (keyboard&)v.top();
			if (kb.getType() == values) out.push(v.top());
			v.pop();
		}
		break;
	case 13:
		while (!v.empty()) {
			kb = (keyboard&)v.top();
			if (kb.getKeys() == valuei) out.push(v.top());
			v.pop();
		}
		break;
	case 14:
		while (!v.empty()) {
			kb = (keyboard&)v.top();
			if (kb.getPrice() == valuef) out.push(v.top());
			v.pop();
		}
		break;
	default:
		break;
	}

	return out;
}

void pc_room::find() {
	int input, subMenu = 0, int_buff = 0;
	float float_buff = 0.0f;
	string string_buff = "";

	while (true) {
		printTitle("Найти элемент");
		cout << "│ Нажмите ESC чтобы завершить поиск.  │\n";
		cout << "├─────────────────────────────────────┤\n";
		cout << "│ Критерии для поиска:                │\n";

		switch (subMenu)
		{
		case 0:
			cout << "├───────────────────┬─────┬─────┬─────┤\n";
			cout << "│ (S) Сис. блок     │ (M) │ (K) │ (O) │\n"
				<< "├───────────────────┴─────┴─────┴─────┤\n"
				<< "│ (1) Тип ЦП                          │\n"
				<< "│ (2) Частота ЦП                      │\n"
				<< "│ (3) Вместимость ЖД                  │\n"
				<< "│ (4) Наличие CD-привода              │\n"
				<< "│ (5) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 1:
			cout << "├─────┬───────────────────┬─────┬─────┤\n";
			cout << "│ (S) │ (M) Монитор       │ (K) │ (O) │\n"
				<< "├─────┴───────────────────┴─────┴─────┤\n"
				<< "│ (1) Диагональ                       │\n"
				<< "│ (2) Частота                         │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 2:
			cout << "├─────┬─────┬───────────────────┬─────┤\n";
			cout << "│ (S) │ (M) │ (K) Клавиатура    │ (O) │\n"
				<< "├─────┴─────┴───────────────────┴─────┤\n"
				<< "│ (1) Тип                             │\n"
				<< "│ (2) Количество кнопок               │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		case 3:
			cout << "├─────┬─────┬─────┬───────────────────┤\n";
			cout << "│ (S) │ (M) │ (K) │ (O) Мышь          │\n"
				<< "├─────┴─────┴─────┴───────────────────┤\n"
				<< "│ (1) Тип                             │\n"
				<< "│ (2) Количество кнопок               │\n"
				<< "│ (3) Цена                            │\n"
				<< "╰─────────────────────────────────────╯\n";
			break;
		default:
			break;
		}

		input = _getch();

		switch (input)
		{
		case 'S': case 's':
			subMenu = 0;
			break;
		case 'M': case 'm':
			subMenu = 1;
			break;
		case 'K': case 'k':
			subMenu = 2;
			break;
		case 'O': case 'o':
			subMenu = 3;
			break;
		case 27:
			if (acceptQuery("╭─────────────────────────────────────╮ \n│ Завершить поиск?                    │ \n╰─────────────────────────────────────╯ \n")) return;
			break;
		case '1':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип ЦП:                     │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(float_buff, int_buff, string_buff, 1));
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите диагональ:                  │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 6));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип клавиатуры:             │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(float_buff, int_buff, string_buff, 12));
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите тип мыши:                   │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(float_buff, int_buff, string_buff, 9));
				break;
			default:
				break;
			}
			break;
		case '2':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите частоту ЦП:                 │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 2));
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите частоту:                    │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 6));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 13));
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 10));
				break;
			default:
				break;
			}
			break;
		case '3':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите вместимость ЖД:             │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 3));
				break;
			case 1:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 8));
				break;
			case 2:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 14));
				break;
			case 3:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 11));
				break;
			default:
				break;
			}
			break;
		case '4':
			switch (subMenu)
			{
			case 0:
				int_buff = acceptQuery("╭─────────────────────────────────────╮ \n│ Есть наличие CD-привода:            │ \n╰─────────────────────────────────────╯ \n");
				print("Результаты поиска", find_helper(float_buff, int_buff, string_buff, 4));
				break;
			default:
				break;
			}
			break;
		case '5':
			switch (subMenu)
			{
			case 0:
				cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
				print("Результаты поиска", find_helper(str_to_float(string_buff), int(str_to_float(string_buff)), string_buff, 5));
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