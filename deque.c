#include "deque.h"
typedef struct s_plentyNode //узел последовательности
{
float data;
struct s_plentyNode* next;
} t_plentyNode;

typedef struct DBLLinkedList //узел дека
{
struct DBLLinkedList* Next;
struct DBLLinkedList* Prev;
t_plenty* plenty;
} Deque;

void clearDeque(Deque** deque) // функция очмстка дека
{
	while ((*deque)->Next != NULL) // пока не дошли до конца дека берем элементы
	{
		(*deque) = (*deque)->Next;
		cleanerPlenty(&(*deque)->plenty); // очистка последовательности внутри текущего элемента дека
		free((*deque)->Prev); //очистка предыдущего элемент дека
	}
	cleanerPlenty(&(*deque)->plenty); // очистка последовательности внутри текущего элемента дека
	free((*deque)); //очистка текущего элемента дека
	(*deque) = NULL; // ставим указатель дека на NULL
}
void changeEndDeque(Deque** deque) // функция изменение последнего элемента дека
{
	while ((*deque)->Next != NULL) // пока не дошли до конца дека двигаем указатель
	(*deque) = (*deque)->Next;
	plentyMenu(&(*deque)->plenty); // вызываем меню последовательности и изменяем элемент
}

void changeBeginningDeque(Deque** deque) // функция изменение первого элемента дека
{
	while ((*deque)->Prev != NULL) // пока не дошли до начала дека двигаем указатель
		(*deque) = (*deque)->Prev;
	plentyMenu(&(*deque)->plenty); // вызываем мен последовательности и изменяем элемент
}

void deleteEndDeque(Deque** deque) // функция удаление последнего элемента дека
{
	if ((*deque)->Next == NULL && (*deque)->Prev == NULL) // если один элемент то очищаем его
	{
		clearDeque(deque); // функция очистка дека удалит этот элемент и последовательность внутри
	}
	else
	{
	while ((*deque)->Next != NULL) // пока не дошли до конца дека двигаем указатель
		(*deque) = (*deque)->Next;
	(*deque) = (*deque)->Prev;
	cleanerPlenty(&(*deque)->Next->plenty); // очистка последовательности внутри последнего элемента
	free((*deque)->Next); // очистка последнего элемента дека
	(*deque)->Next = NULL; // присваем в конец дека NULL
	}
}
void deleteBeginningDeque(Deque** deque) // функция удаление первого элемента дека
{
	if ((*deque)->Prev == NULL && (*deque)->Next == NULL) // если в последовательности один элемент удаляем его
	{
	clearDeque(deque); // функция очистка дека удалит этот элемент и последовательность внутри
	}
	else
	{
		while ((*deque)->Prev != NULL) // пока не дошли до начала дека двигаем указатель
			(*deque) = (*deque)->Prev;
		(*deque) = (*deque)->Next;
		cleanerPlenty(&(*deque)->Prev->plenty); // очищаем последовательность внутри первого элемента
		free((*deque)->Prev); // очистка первого элемента
		(*deque)->Prev = NULL; // присваем в начало дека NULL
	}
}

void getElementInTheEndDeque(Deque* deque) // функция получение последнего элемента дека
{
	while (deque->Next != NULL) // пока не дошли до конца дека двигаем указатель
	deque = deque->Next;
	printPlenty(deque->plenty); // печатаем значение элемента внутри последнего элемента дека
	printf("\n\n");
}

void getElementInTheBeginningDeque(Deque* deque) // функция получени первого элемента дека
{
	while (deque->Prev != NULL) // пока не дошли до начала дека двигаем указатель
	deque = deque->Prev;
	printPlenty(deque->plenty); // печатаем значение элемента внутри первого элемента дека
	printf("\n\n");
}

void addNewElementDequeAtTheEnd(Deque** deque) // функция добавления элемента в конец дека
{
	Deque* temp = NULL; // временаня переменная для создания элемента
	if ((*deque) == NULL) // если дек пуст инициализируем его и создаем 1 элемент
	{
		(*deque) = (Deque*)malloc(sizeof(Deque));
		if ((*deque) == NULL) // проверка выделния памяти
		{
			printf("Ошибка выделенмия памяти!\n\n");
			exit(0);
		}
		//установка указатель на соседние элементы в NULL
		(*deque)->Next = (*deque)->Prev = NULL;
		(*deque)->plenty = NULL;
		plentyMenu(&(*deque)->plenty); // заполнение последовательности внутри этого элемента дека
	}
	else
	{
		while ((*deque)->Next != NULL) // пока не в конце дека двигаем указатель
			(*deque) = (*deque)->Next;
		temp = (Deque*)malloc(sizeof(Deque));
		if (temp == NULL) // проверка выделилась ли память
		{
			printf("Ошибка выделения памяти!\n\n");
			exit(0);
		}
		(*deque)->Next = temp; // добавляем элемент в конец
		temp->Prev = (*deque); // ставим указатель предыдущего элемента на последний элемент дека до добавления
		temp->Next = NULL; // указатель на конец ставим NULL
		temp->plenty = NULL; // ставим указатель последовательности внутри этого элемента в NULL
		plentyMenu(&temp->plenty); // работаем с последовательностью внутри данного элемента
	}

}

void printDeque(Deque* deque) // функция печати дека
{
	while (deque->Prev != NULL) // пока не в начале декa двигаем указатель
		deque = deque->Prev;
	printf("====>\n");
	while (deque->Next != NULL) // пока не в конце дека	печатаем элементы дека
	{
		printPlenty(deque->plenty); // печатаем последовательность внутри элемента дека
		printf(" ");
		deque = deque->Next;
	}
	printPlenty(deque->plenty); // печатаем последовательность внутри элемента дека
	printf("\n<====\n");
	while (deque->Prev != NULL) // пока не в начале дека печатаем элементы дека
	{
		printPlenty(deque->plenty); // печатаем последовательность внутри элемента дека
		printf(" ");
		deque = deque->Prev;
	}
	printPlenty(deque->plenty); // печатаем последовательность внутри элемента дека
	printf("\n");
}

void addNewElementDequeAtTheBeginning(Deque** deque) // функция добавления элемента в начало дека
{
	Deque* temp = NULL; // временная переменная для создания элемента
	if ((*deque) == NULL) // если дек пуст инициализируем его и создаем 1 элемент
	{
		(*deque) = (Deque*)malloc(sizeof(Deque));
		if ((*deque) == NULL) // проверка выделения памяти
		{
			printf("Memory error!\n\n");
			exit(0);
		}
		// ставим указатели на соседние элементы в NULL
		(*deque)->Next = (*deque)->Prev = NULL;
		(*deque)->plenty = NULL; // ставим указатель на последовательность в NULL
		plentyMenu(&(*deque)->plenty); // изменяем последовательность внутри элемента дека
	}
	else
	{
		while ((*deque)->Prev != NULL) // пока не в начале дека двигаем указатель
		(*deque) = (*deque)->Prev;
		temp = (Deque*)malloc(sizeof(Deque));
		if (temp == NULL) // проверка выделния памяти
		{
			printf("Ошибка выделенмия памяти!\n\n");
			exit(0);
		}
		(*deque)->Prev = temp; // добавляем элемент в начало дека
		temp->Next = (*deque); // ставим указатель на следующий элемент нового элемента на первый элемент дека до добавления элемента
		temp->Prev = NULL; // ставим указатель нового элемента на предыдущий в NULL
		temp->plenty = NULL; // ставим указатель последовательности в NULL
		plentyMenu(&temp->plenty); // изменяем последовательность внутри элемента дека
	}
}

void DequeMenu(void) // функция меню дека
{
	Deque* deque = NULL, *tDeque = NULL; // указатель на дек и временная переменная для взятия элемента
	int choice, flagwork = 0, countElements = 0; //переменная для выбора в меню, флаг для работы с деком и счетчик элементов дека
	while (1)
	{
		printf("[1] - Начать работу с деком\n");
		printf("[2] - Сделать дек пустым\n");
		printf("[3] - Дек пуст?\n");
		printf("[4] - Показать значение в начале\n");
		printf("[5] - Показать значение в конце\n");
		printf("[6] - Удалить элемент в начале\n");
		printf("[7] - Удалить элемент в конце\n");
		printf("[8] - Взять элемент из начала\n");
		printf("[9] - Взять элемент из конца\n");
		printf("[10] - Изменить значение элемента вs	начале\n");
		printf("[11] - Изменить значение элемента в конце\n");
		printf("[12] - Добавить элемент в начало\n");
		printf("[13] - Добавить элемент в конец\n");
		printf("[14] - Распечатать дек\n");
		printf("[15] - Закончить работу с деком\n");
		printf("[16] - Завершить работу с программой\n");
		printf("\n");
		if (deque != NULL)
			printDeque(deque);
		else
			printf("Дек пуст!\n\n");
		printf("\nВаш выбор: ");
		scanf("%d", &choice);
		//std::cin >> choice;
		if (choice != 1 && choice != 16 && flagwork == 0) //проверка начата ли работа с деком, хочет ли человек начать работу или выйти из программы
		{
			system("cls");
			printf("Работа с деком ещё не начата!\n");
			system("pause");
			system("cls");
			continue;
		}
		system("cls");
		switch (choice) // выбло действия
		{
		case 1:
			flagwork = 1;
			printf("Работа с деком начата\n");
			system("pause");
			system("cls");
			break;
		case 2:
			if (deque == NULL)
			{
				printf("Дек и так пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				printf("Дек очищен!\n");
				system("pause");
				system("cls");
				clearDeque(&deque);
				countElements = 0;
			}
			break;
		case 3:
			if (deque == NULL)
			{
				printf("Дек пуст!\n");
				system("pause");
				system("cls");
			}
			else
			{
				printf("Дек не пуст\n");
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				getElementInTheBeginningDeque(deque);
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				getElementInTheEndDeque(deque);
				system("pause");
				system("cls");
			}
			break;
		case 6:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				deleteBeginningDeque(&deque);
				countElements--;
			}
			break;
		case 7:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				deleteEndDeque(&deque);
				countElements--;
			}
			break;
		case 8:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				while (deque->Prev != NULL)
					deque = deque->Prev;
				tDeque = deque;
				printPlenty(tDeque->plenty);
				deleteBeginningDeque(&deque);
				countElements--;
				printf("\n\n");
			}
			break;
		case 9:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				while (deque->Next != NULL)
					deque = deque->Next;
				tDeque = deque;
				printPlenty(tDeque->plenty);
				deleteEndDeque(&deque);
				countElements--;
				printf("\n\n");
			}
			break;
		case 10:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
				changeBeginningDeque(&deque);
			break;
		case 11:
			if (deque == NULL)
			{
				printf("Дек пуст!\n\n");
				system("pause");
				system("cls");
			}
			else
				changeEndDeque(&deque);
			break;
			case 12:
			if (countElements < 5)
			{
				addNewElementDequeAtTheBeginning(&deque);
				countElements++;
			}
			else
			{
				printf("В деке не может быть больше 5 элементов !\n");
				system("pause");
				system("cls");
			}
			break;
		case 13:
			if (countElements < 5)
			{
				addNewElementDequeAtTheEnd(&deque);
				countElements++;
			}
			else
			{
				printf("В деке не может быть больше 5 элементов !\n");
				system("pause");
				system("cls");
			}
			break;
		case 14:
			system("cls");
			if (deque == NULL)
				printf("Дек пуст!\n\n");
			else
				printDeque(deque);
			system("pause");
			system("cls");
			break;
		case 15:
			flagwork = 0;
			printf("Работа с деком закончена!\n");
			system("pause");
			system("cls");
			if (deque != NULL)
				clearDeque(&deque);
			countElements = 0;
			break;
		case 16:
			if (flagwork != 1)
				exit(0);
			else
			{
				printf("Работа с деком не закончена!\n");
				system("pause");
				system("cls");
			}
			break;
		default: // блок для неккоректного выбора пользователя
			printf("Вы ввели неизвестную команду!\n");
			system("pause");
			system("cls");
			break;
		}
	}
}


// int main()
// {
// 	setlocale(LC_ALL, "Russian"); // включение поддержки русского языка
// 	DequeMenu(); // вызов меню дека
// }