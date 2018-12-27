#include <iostream>
#include <cstdlib>
//шаблон функции, которая возвращает различные типы значений
//в зависимости от ТИПОВ входных праметров
/*template <typename MyType>
MyType myFunc(MyType * arr, int size) {
	MyType res = arr[0];
	for (int iter = 0; iter < size; iter++) {
		if (res < arr[iter])
			res = arr[iter];
	}
	return res;
}*/

/*
double myFunc(double * arr, int size) {
double res = arr[0];
for (int iter = 0; iter < size;iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}


int myFunc(int * arr, int size) {
int res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}

char myFunc(char * arr, int size) {
char res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}
*/
/*
template<typename TT>
class myList {
public:
	TT element;
	myList * prev;
	myList * next;
	myList();
	myList(TT el);
	~myList();

	myList<TT> next_elem() {
		return next;
	}
	void print();
	void push_back(TT new_elem);
};
*/
template<class T>
class tree
{
	struct Node
	{
		T item;
		Node *son;
		Node * bro;
		Node(T i, Node*s = NULL, Node *b = NULL)
		{
			item = i;
			son = s;
			bro = b;
		}
		Node() {};
	};
	Node *root;//корень
public: 
	tree() { root = NULL; }
	void add(const T &elem)
	{
		add(root, elem);
	}
	void f()
	{
		Node *temp = new Node;
		*temp = *root;
		std::cout << temp->item;
		while (temp->son != NULL)
		{
			*temp = *temp->son;
			std::cout << temp->item;
			while (temp->bro != NULL)
			{
				*temp = *temp->bro;
				std::cout << temp->item;
			}
			//*temp = *root;
		}
	}
	void print()
	{
		Node *temp = new Node;
		*temp = *root;
		if (temp->son != NULL) 
		{
			*temp = *temp->son;
			while (temp->bro != NULL) 
			{
				std::cout << temp->item;
				*temp = *temp->bro;
			}
			std::cout << temp->item;
		}
	}
private: void add(Node *&node, const T &item)
	{
	int a;
	if (node == NULL) 
	{
		node = new Node(item);
		std::cout << "Elem added. Write 0 for add bro, or 1 for add son" << std::endl;
	}
	else {
		std::cin >> a;
		if (/*item < node->item*/a > 0) {
			add(node->son, item);
		}
	
		else {
			add(node->bro, item);
		}
	}
	}
};

int main() {
	/*	int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char * arrCh;
	double * arrD;

	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];

	std::cout << "Input arrI";
	for (int it = 0; it < sizeI; it++) {
	std::cin >> arrI[it];
	}
	std::cout << "Input arrCh";
	for (int it = 0; it < sizeCh; it++) {
	std::cin >> arrCh[it];
	}
	std::cout << "Input arrD";
	for (int it = 0; it < sizeD; it++) {
	std::cin >> arrD[it];
	}
	std::cout << "Max element int = " << myFunc(arrI, sizeI);
	std::cout << "Max element char = " << myFunc(arrCh, sizeCh);
	std::cout << "Max element double = " << myFunc(arrD, sizeD);
	*/
/*
	myList<int> li(5);
	li.push_back(4);
	//li.push_back(7);
	li.print();*/

	tree<int> t1;
	t1.add(1); //0 брат; 1 сын
	t1.add(2);
	t1.add(3);
	t1.add(4);
	t1.f();
	//t1.print();
	//getchar();
	system("pause"); // Команда задержки экрана
	return 0;
}
/*
template<typename TT>
myList<TT>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TT>
myList<TT>::~myList()
{
	delete prev;
	delete next;
}

template<typename TT>
void myList<TT>::print()
{
	myList<TT> *temp = new myList<TT>;
	*temp = *this;
	while (temp->prev != NULL) {
		*temp = *temp->prev;
	}
	while (temp->next != NULL) {
		std::cout << temp->element << "\t";
		*temp = *temp->next;
	}
	std::cout << temp->element << "\t";
}

template<typename TT>
void myList<TT>::push_back(TT new_elem)
{
	myList<TT> *tmp = new myList<TT>;//указатель на новый элемент
	myList<TT> *tmp1 = new myList<TT>;//указатель на текущий элемент
	this->next = tmp;//изменяем указатель на следующий элемент
	*tmp1 = *this;//копируем указатель
	
	tmp->element = new_elem;
	(tmp->prev) = tmp1;
	tmp->next = NULL;
	
	this->element = tmp->element;
	this->prev = tmp->prev;
	this->next = NULL;
	}
	*/
