#include "pc_room.h"

float str_to_float(string s) {
	// just f*cing translate
	try {
		return stof(s);
	} catch (...) {
		return 0;
	}
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

	if (acceptQuery("Сохранить в файл?")) {
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
	if (acceptQuery("Загрузить из стороннего файла?")) {
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
	if (acceptQuery("Сохранить в новый файл?")) {

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

	if (acceptQuery("│ Очистить существующий список и соз- │\n│ дать новый список?                  │\n╰─────────────────────────────────────╯\n",true)) {
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
	int subMenu = 0;
	string string_buff;

	system_block sb = (system_block&)p;
	monitor mr = (monitor&)p;
	keyboard kb = (keyboard&)p;
	mouse ms = (mouse&)p;
	float pr = p.getPCPrice();


	while (true) {
		printTitle("Редактировать элемент", false);
		cout << "├─────────────────────────────────────╯ \n"
			 << sb << mr << kb << ms << "│ Цена сборки: " << pr << "$\n"
			 << "├─────────────────────────────────────╮\n"
			 << "│ Нажмите ESC чтобы завершить редак-  │\n"
			 << "│ тирование                           │\n"
			 << "├─────────────────────────────────────┤\n"
			 << "│ Поля для редактирования:            │\n";

		switch (subMenu) {
			case 0: cout << "├───────────────────┬─────┬─────┬─────┤\n"
						 << "│ (S) Сис. блок     │ (M) │ (K) │ (O) │\n"
						 << "├───────────────────┴─────┴─────┴─────┤\n"
						 << "│ (1) Тип ЦП                          │\n"
						 << "│ (2) Частота ЦП                      │\n"
						 << "│ (3) Вместимость ЖД                  │\n"
						 << "│ (4) Наличие CD-привода              │\n"
						 << "│ (5) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			case 1: cout << "├─────┬───────────────────┬─────┬─────┤\n"
						 << "│ (S) │ (M) Монитор       │ (K) │ (O) │\n"
						 << "├─────┴───────────────────┴─────┴─────┤\n"
						 << "│ (1) Диагональ                       │\n"
						 << "│ (2) Частота                         │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			case 2: cout << "├─────┬─────┬───────────────────┬─────┤\n"
						 << "│ (S) │ (M) │ (K) Клавиатура    │ (O) │\n"
						 << "├─────┴─────┴───────────────────┴─────┤\n"
						 << "│ (1) Тип                             │\n"
						 << "│ (2) Количество кнопок               │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			case 3: cout << "├─────┬─────┬─────┬───────────────────┤\n"
						 << "│ (S) │ (M) │ (K) │ (O) Мышь          │\n"
						 << "├─────┴─────┴─────┴───────────────────┤\n"
						 << "│ (1) Тип                             │\n"
						 << "│ (2) Количество кнопок               │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			default: break;
		}

		switch (_getch()) {
			case 'S': case 's': subMenu = 0; break;
			case 'M': case 'm': subMenu = 1; break;
			case 'K': case 'k': subMenu = 2; break;
			case 'O': case 'o': subMenu = 3; break;
			case 27: if (acceptQuery("Завершить редактирование?")) return computer(sb, mr, kb, ms, pr);
			case '1': switch (subMenu) {
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
			case '2': switch (subMenu) {
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
					default: break;
				}
				break;
			case '3': switch (subMenu) {
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
					default: break;
				}
				break;
			case '4': switch (subMenu) {
					case 0:
						sb.setCD(acceptQuery("Есть наличие CD-привода:"));
						break;
					default: break;
				}
				break;
			case '5': switch (subMenu) {
					case 0:
						cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; cin >> string_buff;
						sb.setPrice(str_to_float(string_buff));
						break;
					default: break;
				}
				break;
			default: break;
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

template<class T, typename cmp, typename ss>
priority_queue<computer> finder(priority_queue<computer> v, cmp cm, ss test) {
	priority_queue<computer> out;
	while (!v.empty()) {
		T sb = (T&) v.top();
		if (cm(sb,test)) 
			out.push(v.top()); 
		v.pop(); 
	}
	return out;
}

priority_queue<computer> pc_room::find_helper(string values, int field) {
	float valuef = str_to_float(values);
	int valuei = int(valuef);

	priority_queue<computer> v = pc_pq;
	system_block sb;
	monitor mn;
	keyboard kb;
	mouse ms;

	switch (field)
	{
		case 1:		return finder<system_block>	(v, [values](system_block sb, string test) {return sb.getCPUType() == values; }	, values); 
		case 2:		return finder<system_block>	(v, [valuef](system_block sb, float test) {return sb.getCPUFreq() == valuef; }	, valuef); 
		case 3:		return finder<system_block>	(v, [valuef](system_block sb, float test) {return sb.getHDDCap() == valuef; }	, valuef); 
		case 4:		return finder<system_block>	(v, [valuei](system_block sb, int test) {return sb.getCD() == valuei; }			, valuei); 
		case 5:		return finder<system_block>	(v, [valuef](system_block sb, float test) {return sb.getPrice() == valuef; }	, valuef); 
		case 6:		return finder<monitor>		(v, [valuef](monitor mn, float test) {return mn.getDiagonal() == valuef; }		, valuef); 
		case 7:		return finder<monitor>		(v, [valuei](monitor mn, int test) {return mn.getFreq() == valuei; }			, valuei); 
		case 8:		return finder<monitor>		(v, [valuef](monitor mn, float test) {return mn.getPrice() == valuef; }			, valuef); 
		case 9:		return finder<mouse>		(v, [values](mouse kb, string test) {return kb.getType() == values; }			, values); 
		case 10:	return finder<mouse>		(v, [valuei](mouse kb, int test) {return kb.getKeys() == valuei; }				, valuei); 
		case 11:	return finder<mouse>		(v, [valuef](mouse kb, float test) {return kb.getPrice() == valuef; }			, valuef);
		case 12:	return finder<keyboard>		(v, [values](keyboard kb, string test) {return kb.getType() == values; }		, values);
		case 13:	return finder<keyboard>		(v, [valuei](keyboard kb, int test) {return kb.getKeys() == valuei; }			, valuei);
		case 14:	return finder<keyboard>		(v, [valuef](keyboard kb, float test) {return kb.getPrice() == valuef; }		, valuef);
		default:	return priority_queue<computer>();
	}
}

void pc_room::find() {
	int subMenu = 0;
	string string_buff = "";

	while (true) {
		printTitle("Найти элемент");
		cout << "│ Нажмите ESC чтобы завершить поиск.  │\n"
			 << "├─────────────────────────────────────┤\n"
			 << "│ Критерии для поиска:                │\n";

		switch (subMenu) {
			case 0: cout  << "├───────────────────┬─────┬─────┬─────┤\n"
						  << "│ (S) Сис. блок     │ (M) │ (K) │ (O) │\n"
						  << "├───────────────────┴─────┴─────┴─────┤\n"
						  << "│ (1) Тип ЦП                          │\n"
						  << "│ (2) Частота ЦП                      │\n"
						  << "│ (3) Вместимость ЖД                  │\n"
						  << "│ (4) Наличие CD-привода              │\n"
						  << "│ (5) Цена                            │\n"
						  << "╰─────────────────────────────────────╯\n"; break;
			case 1: cout << "├─────┬───────────────────┬─────┬─────┤\n"
						 << "│ (S) │ (M) Монитор       │ (K) │ (O) │\n"
						 << "├─────┴───────────────────┴─────┴─────┤\n"
						 << "│ (1) Диагональ                       │\n"
						 << "│ (2) Частота                         │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			case 2: cout << "├─────┬─────┬───────────────────┬─────┤\n"
						 << "│ (S) │ (M) │ (K) Клавиатура    │ (O) │\n"
						 << "├─────┴─────┴───────────────────┴─────┤\n"
						 << "│ (1) Тип                             │\n"
						 << "│ (2) Количество кнопок               │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			case 3: cout << "├─────┬─────┬─────┬───────────────────┤\n"
						 << "│ (S) │ (M) │ (K) │ (O) Мышь          │\n"
						 << "├─────┴─────┴─────┴───────────────────┤\n"
						 << "│ (1) Тип                             │\n"
						 << "│ (2) Количество кнопок               │\n"
						 << "│ (3) Цена                            │\n"
						 << "╰─────────────────────────────────────╯\n"; break;
			default: break;
		}

		switch (_getch()) {
			case 'S': case 's': subMenu = 0; break;
			case 'M': case 'm': subMenu = 1; break;
			case 'K': case 'k': subMenu = 2; break;
			case 'O': case 'o': subMenu = 3; break;
			case 27: if (acceptQuery("Завершить поиск?")) return; 
			case '1': switch (subMenu) {
					case 0:
						cout << "╭─────────────────────────────────────╮ \n│ Введите тип ЦП:                     │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 1));
						break;
					case 1:
						cout << "╭─────────────────────────────────────╮ \n│ Введите диагональ:                  │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 6));
						break;
					case 2:
						cout << "╭─────────────────────────────────────╮ \n│ Введите тип клавиатуры:             │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 12));
						break;
					case 3:
						cout << "╭─────────────────────────────────────╮ \n│ Введите тип мыши:                   │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 9));
						break;
					default: break;
				}
				break;
			case '2': switch (subMenu) {
					case 0:
						cout << "╭─────────────────────────────────────╮ \n│ Введите частоту ЦП:                 │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 2));
						break;
					case 1:
						cout << "╭─────────────────────────────────────╮ \n│ Введите частоту:                    │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 6));
						break;
					case 2:
						cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 13));
						break;
					case 3:
						cout << "╭─────────────────────────────────────╮ \n│ Введите количество кнопок:          │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 10));
						break;
					default: break;
				}
				break;
			case '3': switch (subMenu) {
					case 0:
						cout << "╭─────────────────────────────────────╮ \n│ Введите вместимость ЖД:             │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 3));
						break;
					case 1:
						cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 8));
						break;
					case 2:
						cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 14));
						break;
					case 3:
						cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 11));
						break;
					default: break;
				}
				break;
			case '4': switch (subMenu) {
					case 0:
						string_buff = acceptQuery("Есть наличие CD-привода:");
						print("Результаты поиска", find_helper(string_buff, 4));
						break;
					default: break;
				}
				break;
			case '5': switch (subMenu) {
					case 0: 
						cout << "╭─────────────────────────────────────╮ \n│ Введите цену:                       │ \n╰─────────────────────────────────────╯ \n "; std::cin >> string_buff;
						print("Результаты поиска", find_helper(string_buff, 5)); break;
					default: break;
				}
				break;
			default: break;
		}
	}
}