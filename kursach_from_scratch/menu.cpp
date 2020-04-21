#include "menu.h"

void menu(doubly_linked_list* database)
{
	// ãëàâíîå ìåíş
	while (true) {
		switch (mainMenu())
		{
		case 1: // çàãğóçèòü èç ôàéëà
			if (load_DB(database)) {
				cout << "Äàííûå óñïåøíî çàãğóæåííû." << endl;
			}
			_getch();
			system("cls");
			break;
		case 2: // âûâåñòè òàáëèöó
			if (!isEmptyList(database)) {
				display_table(database);
			}
			else {
				cout << "Ñïèñîê ïóñò.";
			}
			_getch();
			system("cls");
			break;
		case 3: // äîáàâèòü âğó÷íóş
			add_information(database);
			break;
		case 4: // âûãğóçèòü â ôàéë
			upload_file(database);
			cout << "Ôàéë áûë âûãğóæåí." << endl;
			_getch();
			system("cls");
			break;
		case 5: // î÷èñòèòü ñïèñîê
			clearList(database);
			initialize(database);
			cout << "Ñïèñîê áûë î÷èùåí." << endl;
			_getch();
			system("cls");
			break;
		case 6: // ıêñïåğèìåíò ñ òàáëèöåé
			table(database);
			system("cls");
			break;
		case 7: // ñîğòèğîâêà
			switch (sortMenu())
			{
			case 1: // ÔÈÎ
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					fioAscending(database);
					break;
				case 2: // óáûâàíèå
					fioDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 2: // íîìåğ òåëåôîíà
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					phoneAscending(database);
					break;
				case 2: // óáûâàíèå
					phoneDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 3: // ãîğîä
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					cityAscending(database);
					break;
				case 2: // óáûâàíèå
					cityDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 4: // óëèöà
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					streetAscending(database);
					break;
				case 2: // óáûâàíèå
					streetDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 5: // äîì
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					houseAscending(database);
					break;
				case 2: // óáûâàíèå
					houseDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 6: // êâàğòèğà
				switch (oderMenu())
				{
				case 1: // âîçğàñòàíèå
					flatAscending(database);
					break;
				case 2: // óáûâàíèå
					flatDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 7: // ãëàâíîå ìåíş
				break;
			default:
				break;
			}
			break;
		case 8: // ïîèñê
			switch (searchMenu())
			{
			case 1: // ôèî
				searchFIO(database);
				break;
			case 2: // ÷àñòü ôèî
				switch (partFIOMenu())
				{
				case 1: // èìÿ
					searchFirstName(database);
					break;
				case 2: // ôàìèëèÿ
					searchSecondName(database);
					break;
				case 3: // îò÷åñòâî
					searchMiddleName(database);
					break;
				case 4: // ìåíş ïîèñêà
					break;
				default:
					break;
				}
				break;
			case 3: // òåëåôîí
				searchPhone(database);
				break;
			case 4: // ãîğîä
				searchCity(database);
				break;
			case 5: // óëèöà
				searchStreet(database);
				break;
			case 6: // äîì
				searchHouse(database);
				break;
			case 7: // êâàğòèğà
				searchFlat(database);
				break;
			case 8: // ãëàâíîå ìåíş
				break;
			default:
				break;
			}
			break;
		case 9: // âûõîä c îñâîáîæäåíèåì ïàìÿòè
			clearList(database);
			cout << "Âû âûøëè èç ïğîãğàììû" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
}

void showMainMenu(int pos) {
	int i = 1;
	cout << "ÌÅÍŞ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÇÀÃĞÓÇÈÒÜ ÄÀÍÍÛÅ ÈÇ ÔÀÉËÀ" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÂÎÄ ÒÀÁËÈÖÛ" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÄÎÁÀÂÈÒÜ ÂĞÓ×ÍÓŞ" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÃĞÓÇÈÒÜ ÄÀÍÍÛÅ Â ÔÀÉË" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "Î×ÈÑÒÊÀ ÑÏÈÑÊÀ" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ĞÀÁÎÒÀ Ñ ÒÀÁËÈÖÅÉ" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÑÎĞÒÈĞÎÂÊÀ" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎÈÑÊ" << endl;

	if (pos == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÕÎÄ" << endl;
}
int mainMenu() {
	int functionKey;
	int pos = 1;
	do {
		showMainMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (pos != 9) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 9;
		}
		system("cls");
	} while (true);
}

void showSortMenu(int pos) {
	int i = 1;
	cout << "ÑÎĞÒÈĞÎÂÎ×ÍÎÅ ÌÅÍŞ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÔÈÎ" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÍÎÌÅĞ ÒÅËÅÔÎÍÀ" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÃÎĞÎÄ" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÓËÈÖÀ" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÄÎÌ" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÊÂÀĞÒÈĞÀ" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÅĞÍÓÒÜÑß Â ÃËÀÂÍÎÅ ÌÅÍŞ" << endl;
}
int sortMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSortMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (pos != 7) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 7;
		}
		system("cls");
	} while (true);
}

void showOderMenu(int pos) {
	int i = 1;
	cout << "ÑÎĞÒÈĞÎÂÎ×ÍÎÅ ÌÅÍŞ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎ ÂÎÇĞÀÑÒÀÍÈŞ" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎ ÓÁÛÂÀÍÈŞ" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÅĞÍÓÒÜÑß Â ÃËÀÂÍÎÅ ÌÅÍŞ" << endl;
}
int oderMenu() {
	int functionKey;
	int pos = 1;
	do {
		showOderMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (pos != 3) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 3;
		}
		system("cls");
	} while (true);
}

void showSearchtMenu(int pos) {
	int i = 1;
	cout << "ÌÅÍŞ ÏÎÈÑÊÀ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÔÈÎ" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎ ×ÀÑÒÈ ÔÈÎ" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÍÎÌÅĞ ÒÅËÅÔÎÍÀ" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÃÎĞÎÄ" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÓËÈÖÀ" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÄÎÌ" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÊÂÀĞÒÈĞÀ" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÅĞÍÓÒÜÑß Â ÃËÀÂÍÎÅ ÌÅÍŞ" << endl;
}
int searchMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSortMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (pos != 8) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 8;
		}
		system("cls");
	} while (true);
}

void showPartFIOMenu(int pos) {
	int i = 1;
	cout << "ÌÅÍŞ ÏÎÈÑÊÀ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÔÀÌÈËÈß" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÈÌß" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÎÒ×ÅÑÒÂÎ" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÅĞÍÓÒÜÑß Â ÃËÀÂÍÎÅ ÌÅÍŞ" << endl;
}
int partFIOMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSortMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (pos != 4) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 4;
		}
		system("cls");
	} while (true);
}