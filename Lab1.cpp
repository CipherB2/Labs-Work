#include "stdafx.h" 
#include<iostream> 
using namespace std;
struct list
{
	int value;
	list* next;
	list()
	{
		value = 0;
		next = NULL;
	}
};

void DeleteFromList(list*& first)
{
	list* l = first;
	list* p = NULL;
	while (l != NULL)
	{
		if (l->value < 0)
		{
			p = l;
			l = l->next;
		}
		else
		{
			p->next = l->next;
			delete l;
			l = p->next;
		}
	}
}
void OutputList(list* l)
{
	while (l != NULL)
	{
		cout << l->value;
		l = l->next;
		if (l != NULL)cout << ", ";
	}
	cout << endl;
}
int main()
{
	int n;
	float z;
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов списка: " << endl;
	cin >> n;
	cout << "Введите элементы списка: " << endl;
	list* first = new list();
	list* p = first;
	int i = 0;
	while (i < n)
	{
		cin >> z;
		p->value = z;
		if (i != n)
		{
			p->next = new list();
			p = p->next;
		}
		i++;
	}
	DeleteFromList(first);
	OutputList(first);
	system("pause");
	return 0;
}
