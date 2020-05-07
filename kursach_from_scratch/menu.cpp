#include "menu.h"

int choiceMenu(int currentMenu) {
	int functionKey;
	int position = 1;

	void (*fcnPtrShowCurrentMenu)(int);
	int lastMenuItem;
	if (currentMenu == 1) {
		fcnPtrShowCurrentMenu = showMainMenu;
		lastMenuItem = 9;
	}
	else if (currentMenu == 2) {
		fcnPtrShowCurrentMenu = showSortMenu;
		lastMenuItem = 7;
	}
	else if (currentMenu == 3) {
		fcnPtrShowCurrentMenu = showOderMenu;
		lastMenuItem = 3;
	}
	else if (currentMenu == 4) {
		fcnPtrShowCurrentMenu = showSearchMenu;
		lastMenuItem = 8;
	}
	else if (currentMenu == 5) {
		fcnPtrShowCurrentMenu = showPartFIOMenu;
		lastMenuItem = 4;
	}
	else if (currentMenu == 6) {
		fcnPtrShowCurrentMenu = showFiltrationMenu;
		lastMenuItem = 8;
	}
	else {
		exit(0);
	}

	
	do {
		(*fcnPtrShowCurrentMenu)(position);
	
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // ââåğõ
				if (position != 1) {
					position--;
				}
			}
			else if (functionKey == 80) { // Âíèç
				if (position != lastMenuItem) {
					position++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return position;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return lastMenuItem;
		}
		
		system("cls");
	} while (true);
}

void mainMenu(doubly_linked_list* database) {
	const int mainMenu = 1;

	while (true) {
		switch (choiceMenu(mainMenu))
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
		case 8: // ôèëüòğàöèÿ
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}
void showMainMenu(int position) {
	int i = 1;
	cout << "ÌÅÍŞ:" << endl;

	if (position == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÇÀÃĞÓÇÈÒÜ ÄÀÍÍÛÅ ÈÇ ÔÀÉËÀ" << endl;

	if (position == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ĞÀÁÎÒÀ Ñ ÒÀÁËÈÖÅÉ" << endl;

	if (position == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÄÎÁÀÂÈÒÜ ÂĞÓ×ÍÓŞ" << endl;

	if (position == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÃĞÓÇÈÒÜ ÄÀÍÍÛÅ Â ÔÀÉË" << endl;

	if (position == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "Î×ÈÑÒÊÀ ÑÏÈÑÊÀ" << endl;

	if (position == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÑÎĞÒÈĞÎÂÊÀ" << endl;

	if (position == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÏÎÈÑÊ" << endl;

	if (position == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÔÈËÜÒĞÀÖÈß" << endl;

	if (position == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ÂÛÕÎÄ" << endl;
}

void sortMenu(doubly_linked_list* database) {
	const int sortMenu = 2;
	const int oderMenu = 3;

	while (true) {
		switch (choiceMenu(sortMenu))
		{
		case 1: // ÔÈÎ
			switch (choiceMenu(oderMenu))
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
			switch (choiceMenu(oderMenu))
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
			switch (choiceMenu(oderMenu))
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
			switch (choiceMenu(oderMenu))
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
			switch (choiceMenu(oderMenu))
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
			switch (choiceMenu(oderMenu))
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

void searchMenu(doubly_linked_list* database) {
	const int searchMenu = 4;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(searchMenu))
		{
		case 1: // ôèî
			searchFIO(database);
			break;
		case 2: // ÷àñòü ôèî
			switch (choiceMenu(partFIOMenu))
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

void filtrationMenu(doubly_linked_list* database) {
	const int filtrationMenu = 6;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(filtrationMenu))
		{
		case 1: // ôèî
			filtrFIO(database);
			break;
		case 2: // ÷àñòü ôèî
			switch (choiceMenu(partFIOMenu))
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
	cout << "ÌÅÍŞ ÔÈËÜÒĞÀÖÈÈ:" << endl;

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