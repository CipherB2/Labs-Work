#include <iostream>
using namespace std;
struct tree
{
	int value;
	tree* right;
	tree* left;
	tree()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct list
{
	int val;
	list* point;
	list()
	{
		val = 0;
		point = NULL;
	}
};
void Vvod(tree* t, tree* l)
{
	if (t == NULL || l == NULL) {
		return;
	}
	if (t->left == l) {
		t->left = NULL;
	}
	else if (t->right == l) {
		t->right = NULL;
	}
	{
		Vvod(t->left, l);
		Vvod(t->right, l);
	}
}
void Input(tree*& el, int v)
{
	if (el == NULL)
	{
		el = new tree();
		el->value = v;
	}
	if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(tree* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << ",";
		Output(el->right);
	}
}
void OutputList(list* l)
{
	while (l != NULL)
	{
		cout << l->val;
		l = l->point;
		if (l != NULL)cout << ", ";
	}
	cout << endl;
}
void Remove(tree* t)
{
	if (t != NULL)
	{
		Remove(t->left);
		Remove(t->right);
		delete t;
	}
}
tree* Find(tree* t, int v)
{
	tree* result = NULL;
	if (t == NULL) {
		result = NULL;
	}
	else if (t->value == v) {
		result = t;
	}
	else
	{
		result = Find(t->left, v);
		if (result == NULL) {
			result = Find(t->right, v);
		}
	}
	return result;
}
void spisok(list*& l, tree* t, list*& li)
{
	if (t != NULL)
	{
		spisok(l, t->left, li);
		list* l1 = new list();
		l1->val = t->value;
		if (li == NULL) {
			l = l1;
			li = l1;
		}
		else {
			li->point = l1;
			li = l1;
		}
		spisok(l, t->right, li);
	}
}
void outputlist(list* l) {
	while (l != NULL) {
		cout << l->val << " ";
		l = l->point;
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	tree* root = NULL;
	list* first = NULL;
	int n = 0, v;
	cout << "Введите количество элементов ";
	cin >> n;
	cout << "Введите элементы ";
	for (int i = 0; i < n; i++) {
		cin >> v;
		Input(root, v);
	}
	Output(root);
	cout << endl;
	cout << "Список: ";
	list* l = NULL;
	spisok(first, root, l);
	OutputList(first);
	int N;
	cout << "Введите элемент, для удаления поддерева ";
	cin >> N;
	tree* t = Find(root, N);
	Vvod(root, t);
	Remove(t);
	Output(root);
	cout << endl;
	system("pause");
	return 0;
}