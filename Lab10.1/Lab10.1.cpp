#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	Node* pNext;
	int day, month, year; // Дата вылета
	int hour, minutes; // Время вылета
	int hour1, minutes1; // Время полета
	string airport; // название аэропорта
	bool breakfast; // наличие завтрака, если полет больше 4 часов
	Node(int day = 0, int month = 0, int year = 0, int hour = 0, int minutes = 0,
		int hour1 = 0, int minutes1 = 0, string airport = " ", bool breakfast = 0, Node* pNext = nullptr)
	{
		this->hour = hour;
		this->minutes = minutes;
		this->hour1 = hour1;
		this->minutes1 = minutes1;
		this->day = day;
		this->month = month;
		this->year = year;
		this->airport = airport;
		this->breakfast = breakfast;
		this->pNext = pNext;
	}
};

class List
{
public:
	List();
	~List();

	void push_back(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast);
	void push_front(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast);
	void insert(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast, int index);
	int GetSize() { return Size; }
	void pop_front();
	void pop_back();
	void clear();
	void remove(int index);
	void Get_data(const int number);
	int Get_Day(const int number);
	int Get_Month(const int number);
	int Get_Year(const int number);
	int Get_Hour(const int number);
	int Get_Minutes(const int number);
	int Get_Hour1(const int number);
	int Get_Minutes1(const int number);
	string Get_Airport(const int number);
	bool Get_Breakfast(const int number);
	void vvod_s_klawi();
	Node* create_node();
	void vivod(List& list);
	void OutputToFile();
	List ReadFile(List& L);
	void bsort(void);

private:
	int Size;
	Node* head;

};

List::List()
{
	Size = 0;
	head = nullptr;
};

List::~List()
{
	//clear();
}
void List::push_back(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast)
{
	if (head == nullptr)
	{
		head = new Node(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast);
	}
	Size++;
}
void List::push_front(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast)
{
	head = new Node(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast, head);
	Size++;
}


int List::Get_Day(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->day;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Month(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->month;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Year(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->year;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Hour(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->hour;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Minutes(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->minutes;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Hour1(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->hour1;
		}
		current = current->pNext;
		i++;
	}
}
int List::Get_Minutes1(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->minutes1;
		}
		current =
			current->pNext;
		i++;
	}
}
string List::Get_Airport(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->airport;
		}
		current = current->pNext;
		i++;
	}
}
bool List::Get_Breakfast(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			return current->breakfast;
		}
		current = current->pNext;
		i++;
	}
}
void List::Get_data(const int number)
{
	int i = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (i == number)
		{
			cout << current->day << " " << current->month << " " << current->year << " "
				<< current->hour << " " << current->minutes << " " << current->hour1 << " " << current->minutes1 << " " <<
				current->airport << " " << current->breakfast << endl;
		}
		current = current->pNext;
		i++;
	}
}

void List::pop_front() // удаление с начала
{
	Node* ptr = head;
	head = head->pNext;
	delete ptr;
	Size--;
}
void List::pop_back()
{
	remove(Size - 1);
}
void List::clear()
{
	while (Size)
	{
		pop_front();
	}
	cout << "Выполнена очистка списка." << endl;
}
void List::insert(int day, int month, int year, int hour, int minutes, int hour1, int minutes1, string airport, bool breakfast, int index)
{
	if (index == 0)
	{
		create_node();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index; i++)
		{
			previous = previous->pNext;
		}
		Node* newNode = new Node(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}
void List::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

Node* List::create_node() {
	Node* ptr = new Node();
	ptr->pNext = NULL;//=nullptr
	cout << "Введите дату вылета: " << endl;
	cout << "Введите число: " << endl;
	cin >> ptr->day;
	while (ptr->day > 31) {
		cout << "Введите число до 31." << endl;
		cin >> ptr->day;
	}
	cout << "Введите месяц: " << endl;
	cin >> ptr->month;
	while (ptr->month > 12) {
		cout << "Введите число до 12." << endl;
		cin >> ptr->month;
	}
	cout << "Введите год: " << endl;
	cin >> ptr->year;
	cout << "Введите время вылета: " << endl;
	cout << "Введите час: " << endl;
	cin >> ptr->hour;
	while (ptr->hour > 23) {
		cout << "Введите число до 23." << endl;
		cin >> ptr->hour;
	}
	cout << "Введите минуты: " << endl;
	cin >> ptr->minutes;
	while (ptr->minutes > 59) {
		cout << "Введите число до 59." << endl;
		cin >> ptr->minutes;
	}
	cout << "Введите название Аэропорта: ";
	cin >> ptr->airport;
	cout << "Введите длительность полета: " << endl;
	cout << "Введите час: " << endl;
	cin >> ptr->hour1;
	cout << "Введите минуты: " << endl;
	cin >> ptr->minutes1;
	while (ptr->minutes1 > 59) {
		cout << "Введите число до 59." << endl;
		cin >> ptr->minutes1;
	}
	if (ptr->hour1 > 3) {
		ptr->breakfast = 1;
	}
	else
		ptr->breakfast = 0;
	return ptr;
}

void List::vvod_s_klawi()
{

	if (!head) head = create_node();
	else {
		Node* ptr = head;
		while (ptr->pNext)	ptr = ptr->pNext;
		ptr->pNext = create_node();
	}
	Size++;

}

void List::vivod(List& L)
{
	Node* ptr = head;
	int i = 0;
	while (ptr) {
		i++;
		cout << "Список: " << endl;
		cout << "Запись №" << i << endl
			<< "Дата вылета: " << ptr->day << "." << ptr->month << "." << ptr->year << endl
			<< "Время вылета: " << ptr->hour << ":" << ptr->minutes << endl
			<< "Название аэропорта: " << ptr->airport << endl
			<< "Время полета: " << ptr->hour1 << ":" << ptr->minutes1 << endl
			<< "Есть ли завтрак: " << ptr->breakfast << endl;
		ptr = ptr->pNext;
	}
}

void List::OutputToFile()
{
	ofstream fout("file.txt");
	if (fout)
	{
		Node* ptr = head; //Объявляем указатель и изначально он указывает на начало

		while (ptr != NULL) //Пока по адресу на начало хоть что-то есть
		{
			//Выводим все элементы структуры в файл
			fout << ptr->day << "  "; //Вывод названия
			fout << ptr->month << "  "; //Вывод фамилии автора
			fout << ptr->year << "  "; //Вывод страны
			fout << ptr->hour << "  "; //Вывод года
			fout << ptr->minutes << endl; // Вывод цены
			fout << ptr->hour1 << "  "; //Вывод года
			fout << ptr->minutes1 << endl; // Вывод цены
			fout << ptr->airport << "  "; //Вывод года
			fout << ptr->breakfast << endl; // Вывод цены

			ptr = ptr->pNext; //Указываем на следующий адрес из списка
		}
		fout.close();
	}
	else
		cout << "Ошибка открытия файла!" << endl;
}

List List::ReadFile(List& L)
{
	int day = 0;
	int month = 0; int year = 0;
	int hour = 0;
	int minutes = 0;
	int hour1 = 0;
	int minutes1 = 0;
	string airport = " ";
	bool breakfast = 0;
	string file;
	cout << "Введите название файла: \n(поумолчанию 'file.txt')" << endl;
	cin >> file;
	ifstream read(file);
	if (read)
	{
		while (
			read >> day &&
			read >> month &&
			read >> year &&
			read >> hour &&
			read >> minutes &&
			read >> hour1 &&
			read >> minutes1 &&
			read >> airport &&
			read >> breakfast)
			L.push_back(day, month, year, hour, minutes, hour1, minutes1, airport, breakfast);

		cout << "\nДанные взяты." << endl;
	}
	else
		cout << "\nОшибка открытия файла.Пробуйте вручную." << endl;
	return(L);
}

void List::bsort(void) {
	Node* t, * m, * a, * b;
	if (head == NULL)
		return;

	for (bool go = true; go; ) {
		go = false;
		a = t = head;
		b = head->pNext;

		while (b != NULL) {
			if (a->breakfast > b->breakfast) {
				if (t == a)
					head = b;
				else
					t->pNext = b;

				a->pNext = b->pNext;
				b->pNext = a;

				m = a, a = b, b = m;
				go = true;
			}
			t = a;
			a = a->pNext;
			b = b->pNext;
		}
	}
	cout << "Выполнена сортировка по наличию завтрака!" << endl;
}

int _stateMenu;
int Menu()
{
	cout << endl << "---------------" << endl;
	cout << "Меню:" << endl;
	cout << "1. Добавить новый элемент" << endl;
	cout << "2. Считать список с файла" << endl;
	cout << "3. Подсчёт количества элементов списка" << endl;
	cout << "4. Вывод на экран содержимого списка" << endl;
	cout << "5. Сохранить список в файла" << endl;
	cout << "6. Удаление элемента с конца" << endl;
	cout << "7. Удаление списка" << endl;
	cout << "8. Сортировка" << endl;
	cout << "9. Выход" << endl;
	cout << "Введите номер пункта: " << endl;
	cout << endl << "---------------" << endl;

	cin >> _stateMenu;
	return _stateMenu;
}

void spisokpust() {
	cout << "Список пуст." << endl;
};

int main()
{
	setlocale(LC_ALL, "ru");
	List L;
	Menu();

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{

		case 1:
			L.vvod_s_klawi();
			Menu();
			break;
		case 2:
			L.ReadFile(L);
			Menu();
			break;
		case 3:
			cout << "Элементов в списке: " << L.GetSize() << endl;
			Menu();
			break;
		case 4:
			if (L.GetSize() == 0) {
				spisokpust();
			}
			else L.vivod(L);
			Menu();
			break;
		case 5:
			if (L.GetSize() == 0) {
				spisokpust();
			}
			else L.OutputToFile();
			Menu();
			break;
		case 6:
			if (L.GetSize() == 0) {
				spisokpust();
			}
			else L.pop_back();
			Menu();
			break;
		case 7:
			if (L.GetSize() == 0) {
				spisokpust();
			}
			else L.clear();
			Menu();
			break;
		case 8:
			if (L.GetSize() == 0) {
				spisokpust();
			}
			else L.bsort();
			Menu();
			break;

		default:
			break;
		}

	}

	return 0;
}