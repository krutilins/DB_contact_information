#include "Header.h"

/* ������������� ������ */
void initialize(doubly_linked_list* L) {
	// ��������� ��� ����� ��������� �������
	L->start = (Contact*)malloc(sizeof(Contact));
	// ���� ������ �� �������
	if (!L->start) {
		cout << "�� ������� ������ ��� ������������� ����������� ������.";
		cout << "\a";
		cout << endl;
		system("pause");
		return;
	}
	// ��������� ������ ��� ������� ���������� ��������
	L->end = (Contact*)malloc(sizeof(Contact));
	// ���� ������ �� �������
	if (!L->end) {
		cout << "�� ������� ������ ��� ������������� ����������� ������.";
		cout << "\a";
		cout << endl;
		free((void*)L->start); // �������� ������ ���������� ��������
		L->start = NULL;
		system("pause");
		return;
	}
	// �������, ��������� �� ����� ��������� - ������ ��������� �������
	L->start->next_link = L->end;
	// ��������, ��������������� ������ ���������� �������� ���
	L->start->prev_link = NULL;
	// ��������, ���������� �� ������ ��������� ��������� ���
	L->end->next_link = NULL;
	// �������, �������������� ������� ���������� - ����� ��������� �������
	L->end->prev_link = L->start;
	L->ptr = L->start;
}

/* ��������� �������� �� �������� ��������� */
void prevPut(doubly_linked_list* L, Contact* elem) {
	// ���� ������� ��������� ���������� �� ������
	if (L->ptr == L->start) {
		cout << "������. ���������� ������� �� �������� ���������." << endl;
		cout << "������� ��������� �� ��������� ������." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ��������� ������ ��� ����� �������
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	// ���� ������ �� ����������
	if (!pntr) {
		cout << "���������� �������� �������. �� ���������� ������." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ������ ���������� � ����� �������
	strcpy(pntr->FIO, elem->FIO);
	strcpy(pntr->phone, elem->phone);
	strcpy(pntr->city, elem->city);
	strcpy(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	// ����� ������� ��������� ����� �� ����������
	pntr->prev_link = L->ptr->prev_link;
	// ����� ������� ��������� ������ �� ��������
	pntr->next_link = L->ptr;
	// ���������� ������� ��������� ������ �� �����
	L->ptr->prev_link->next_link = pntr;
	// ������� ������� ��������� ����� �� �����
	L->ptr->prev_link = pntr;
}

/* ��������� �������� ����� �������� ��������� */
void postPut(doubly_linked_list* L, Contact* elem) {
	// ���� ������� ��������� ���������� �� ������
	if (L->ptr == L->end) {
		cout << "������. ���������� ������� ����� �������� ���������." << endl;
		cout << "������� ��������� �� ��������� �����." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ��������� ������ ��� ����� �������
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	// ���� ������ �� ����������
	if (!pntr) {
		cout << "���������� �������� �������. �� ���������� ������." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ������ ���������� � ����� �������
	strcpy(pntr->FIO, elem->FIO);
	strcpy(pntr->phone, elem->phone);
	strcpy(pntr->city, elem->city);
	strcpy(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	// ����� ������� ��������� ������ �� ���������
	pntr->next_link = L->ptr->next_link;
	// ����� ������� ��������� ����� �� �������
	pntr->prev_link = L->ptr;
	// ��������� ������� ��������� ����� �� �����
	L->ptr->next_link->prev_link = pntr;
	// �������� ������� ��������� ������ �� �����
	L->ptr->next_link = pntr;
}

/* ���������� �������� �� �������� ��������� */
void prevGet(doubly_linked_list* L, Contact* elem) {
	// ���� ������ ����
	if (isEmptyList(L)) return;
	// ���� ������� ��������� ��������� �� ������ (����� ��������� �������)
	if (L->ptr == L->start) {
		cout << "������. ���������� �������� �� �������� ���������." << endl;
		cout << "������� ��������� �� ��������� ������." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ������ ���������� � ���������� 
	strcpy(elem->FIO, L->ptr->prev_link->FIO);
	strcpy(elem->phone, L->ptr->prev_link->phone);
	strcpy(elem->city, L->ptr->prev_link->city);
	strcpy(elem->street, L->ptr->prev_link->street);
	elem->house = L->ptr->prev_link->house;
	elem->flat = L->ptr->prev_link->flat;
	// ��������� �������, ����������� �� ���������
	Contact* pntr = L->ptr->prev_link;
	// ������� ������� ��������� �� �������������� ����������
	L->ptr->prev_link = pntr->prev_link;
	// �������������� ���������� ������� ��������� �� �������
	pntr->prev_link->next_link = L->ptr;
	// �������� ���������� ��������
	free((void*)pntr);
}

/* ���������� �������� ����� �������� ��������� */
void postGet(doubly_linked_list* L, Contact* elem) {
	// ���� ������ ����
	if (isEmptyList(L)) return;
	// ���� ������� ��������� ��������� �� ����� (������ ��������� �������)
	if (L->ptr == L->end) {
		cout << "������. ���������� �������� ����� �������� ���������." << endl;
		cout << "������� ��������� �� ��������� �����." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// ������ ���������� � ���������� 
	strcpy(elem->FIO, L->ptr->next_link->FIO);
	strcpy(elem->phone, L->ptr->next_link->phone);
	strcpy(elem->city, L->ptr->next_link->city);
	strcpy(elem->street, L->ptr->next_link->street);
	elem->house = L->ptr->next_link->house;
	elem->flat = L->ptr->next_link->flat;
	// ��������� �������, ����������� �� ���������
	Contact* pntr = L->ptr->next_link;
	// ������� ������� ��������� �� �������������� ����������
	L->ptr->next_link = pntr->next_link;
	// �������������� ���������� ������� ��������� �� �������
	pntr->next_link->prev_link = L->ptr;
	// �������� ���������� ��������
	free((void*)pntr);
}

/* ��������� �������� ��������� � ������ ������ */
void beginPtr(doubly_linked_list* L) {
	while (L->ptr != L->start) movePtrLeft(L);
}

/* ��������� �������� ��������� � ����� ������ */
void endPtr(doubly_linked_list* L) {
	while (L->ptr != L->end) movePtrRight(L);
}

/* ����� �������� ��������� ����� */
void movePtrLeft(doubly_linked_list* L) {
	// ���� ������� ��������� ��������� �� ������
	if (L->ptr == L->start) {
		return;
	}
	L->ptr = L->ptr->prev_link; // ����� �������� ���������
}

/* ����� �������� ��������� ������ */
void movePtrRight(doubly_linked_list* L) {
	// ���� ������� ��������� ��������� �� �����
	if (L->ptr == L->end) {
		return;
	}
	L->ptr = L->ptr->next_link; // ����� �������� ���������
}

/* �������� ������ */
void clearList(doubly_linked_list* L) {
	beginPtr(L); // ��������� �������� ��������� � ������
	Contact temp; // �������� ��������� ����������
	while (!isEmptyList(L)) {	// ���� ������ �� ����
		postGet(L, &temp);						// ������� �������
	}
	free((void*)L->end);  // ������� ��������� �������
	// L->ptr ��������� �� L->start, ������� ����������� ��� �������� NULL
	L->ptr = NULL;
	free((void*)L->start);
}

/* ��������: �������� �� ������ ������ */
int isEmptyList(doubly_linked_list* L) {
	if (L->start->next_link == L->end) {
		return 1;
	}
	return 0;
}

/* ������ ��� ��������� ������ � ������ �� ����� */
void printList(doubly_linked_list* L) {
	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;

	tmp = L->start->next_link; // ������ �� ������ �������

	// ���� �� ����� ������
	while (tmp != L->end) {
		cout << tmp->FIO << endl;
		cout << tmp->phone << endl;
		cout << tmp->city << endl;
		cout << tmp->street << endl;
		cout << tmp->house << endl;
		cout << tmp->flat << endl;
		cout << endl;
		tmp = tmp->next_link;
	}
}

/* ������� ������ ������ */
int numElements(doubly_linked_list* L) {
	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������
	int itr = 0;
	// ���� �� ����� ������
	while (tmp != L->end) {
		itr++;
		tmp = tmp->next_link;
	}
	return itr;
}