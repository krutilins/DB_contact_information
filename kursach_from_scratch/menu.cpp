#include "menu.h"

void mainMenu(doubly_linked_list* database)
{
	while (true) {
		switch (choiceMainMenu())
		{
		case 1: // çàãğóçèòü èç ôàéëà
			load_DB(database);
			break;
		case 2: // âûâåñòè òàáëèöó
			table(database);
			break;
		case 3: // äîáàâèòü âğó÷íóş
			add_end(database);
			break;
		case 4: // âûãğóçèòü â ôàéë
			upload_file(database);
			break;
		case 5: // î÷èñòèòü ñïèñîê
			clearList(database);
			initialize(database);
			cout << "Ñïèñîê áûë î÷èùåí." << endl;
			_getch();
			system("cls");
			break;
		case 6: // ñîğòèğîâêà
			sortMenu(database);
			break;
		case 7: // ïîèñê
			searchMenu(database);
			break;
		case 8:
			filtrationMenu(database);
			break;
		case 9:
			return;
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
	cout << "ĞÀÁÎÒÀ Ñ ÒÀÁËÈÖÅÉ" << endl;

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
	cout << "ÑÎĞÒÈĞÎÂÊÀ" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎÈÑÊ" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÑÎĞÒÈĞÎÂÊÀ" << endl;

	if (pos == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÕÎÄ" << endl;
}
int choiceMainMenu() {
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

void sortMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSortMenu())
		{
		case 1: // ÔÈÎ
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			return;
		}
	}
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
int choiceSortMenu() {
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
	cout << "ÂÛÁÅĞÈÒÅ ÌÎÍÎÒÎÍÍÎÑÒÜ ÑÎĞÒÈĞÎÂÊÈ:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎ ÂÎÇĞÀÑÒÀÍÈŞ" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎ ÓÁÛÂÀÍÈŞ" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÅĞÍÓÒÜÑß Â ÌÅÍŞ ÑÎĞÒÈĞÎÂÊÈ" << endl;
}
int choiceOderMenu() {
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

void searchMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSearchMenu())
		{
		case 1: // ôèî
			searchFIO(database);
			break;
		case 2: // ÷àñòü ôèî
			switch (choicePartFIOMenu())
			{
			case 1: // ôàìèëèÿ
				searchSecondName(database);
				break;
			case 2: // èìÿ
				searchFirstName(database);
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
			return;
		}
	}
}
void showSearchMenu(int pos) {
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
int choiceSearchMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSearchMenu(pos);
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
	cout << "ÂÛÁÅĞÈÒÅ ×ÀÑÒÜ ÔÈÎ:" << endl;

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
	cout << "ÂÅĞÍÓÒÜÑß Â ÌÅÍŞ ÏÎÈÑÊÀ" << endl;
}
int choicePartFIOMenu() {
	int functionKey;
	int pos = 1;
	do {
		showPartFIOMenu(pos);
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

void filtrationMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSearchMenu())
		{
		case 1: // ôèî
			filtrFIO(database);
			break;
		case 2: // ÷àñòü ôèî
			switch (choicePartFIOMenu())
			{
			case 1: // ôàìèëèÿ
				filtrSecondName(database);
				break;
			case 2: // èìÿ
				filtrFirstName(database);
				break;
			case 3: // îò÷åñòâî
				filtrMiddleName(database);
				break;
			case 4: // ìåíş ïîèñêà
				break;
			default:
				break;
			}
			break;
		case 3: // òåëåôîí
			filtrPhone(database);
			break;
		case 4: // ãîğîä
			filtrCity(database);
			break;
		case 5: // óëèöà
			filtrStreet(database);
			break;
		case 6: // äîì
			filtrHouse(database);
			break;
		case 7: // êâàğòèğà
			filtrFlat(database);
			break;
		case 8: // ãëàâíîå ìåíş
			return;
		}
	}
}
void showFiltrationMenu(int pos) {
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
int choiceFiltrationMenu() {
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
