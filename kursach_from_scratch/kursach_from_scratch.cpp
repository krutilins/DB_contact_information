///главный файл

//подключение заголовков
#include "Header.h"
#include "menu.h"

int main()
{
	// подключение русской раскладки
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// установка размеров консоли
	system("mode con cols=133 lines=35");
	
	// создание и инициализация списка
	doubly_linked_list* database = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(database);
	
	// главное меню
	menu(database);

	// очистка списка
	clearList(database);
}