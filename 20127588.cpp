#include <iostream>

using namespace std;

struct video {
	char* title;
	char category[5];
	int quantity;
};

struct node {
	video data;
	node* next;
};

class list
{
public:
	list(); ~list();
	node* createNode(video x);

	int add(const video&);
	int remove(char title[]);
	int display_all();
	bool isListEmpty(node* lst);
private:
	node* head;
};

list::list()
{
	head = NULL;
}

bool isListEmpty(node* lst)
{
	if (lst == NULL)
		return true;
	else
		return false;
}
		
int GetListLength(node* lst)
{
	int count = 0;
	node* current = lst;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

bool AddItemToList(node* lst, video item)
{
	node* current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	node* temp = new node;
	temp->data = item;
	temp->next = NULL;
	current->next = temp;
	return true;
}

bool InsertToList(node* lst, int newpos, video item)
{
	node* current = lst;
	for (int i = 1; i < newpos; i++)
		current = current->next;
	node* temp = new node;
	temp->data = item;
	temp->next = current->next;
	current->next = temp;
	return true;
}

bool RemoveFromList(node* lst, int pos)
{
	node* current = lst;
	for (int i = 1; i < pos - 1; i++)
		current = current->next;
	current->next = current->next->next;
	return true;
}

void ClearList(node* lst)
{
	node* current = lst;
	while (current != NULL)
	{
		node* temp = current;
		current = current->next;
		delete temp;
	}
}

int list::display_all()
{
	node* current = head;
	while (current != NULL)
	{
		cout << current->data.title << "\t"
			<< current->data.category << endl;
		current = current->next;
	}
	return 1;
}
int main()
{
	node a;
	if (isListEmpty(&a))
		cout << "True";
	else
		cout << "False";
	return 0;
}
