#include <iostream>

using namespace std;

typedef int Elem;
class node
{
	public:
		Elem elem;
		node *next;
		node *prev;
		node(int el, node *p = NULL, node *n = NULL)
		{
			elem = el;
			next = n;
			prev = p;
		}
		friend class Dlist;
};
class DSlist
{
	private:
		node *head, *tail;
	public:
		DSlist(){
			head = tail = NULL;
		}
		~DSlist();
		bool isempty();
		const Elem& add_head(int el);
		const Elem& add_tail(int el);
		const Elem& Front() const;
		const Elem& Back() const;
		int delete_head();
		int delete_tail();
		void display();
};
bool DSlist :: isempty()
{
	return (head == NULL);
}

DSlist :: ~DSlist()
{
	node *p;
	while(!isempty())
	{
		p = head -> next;
		delete head;
		head = p;
	}
}

const Elem& DSlist :: add_head(int el)
{
	if(head != NULL)
	{
		head = new node (el, NULL, head);
		head -> next -> prev = head;
	}
	else
	{
		head = tail = new node(el);
	}
}

const Elem& DSlist :: add_tail(int el)
{
	if(tail != NULL)
	{
		tail = new node(el,tail,NULL);
		tail -> prev -> next = tail;
	}
	else
	{
		head = tail = new node(el);
	}
}

int DSlist :: delete_head()
{
	int el = head -> elem;
	node  *temp = head;
	if(head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head -> next;
		head -> prev = NULL;
	}
	delete temp;
	return el;
}

int DSlist :: delete_tail()
{
	int el = tail -> elem;
	if(head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		tail = tail -> prev;
		delete tail -> next;
		tail -> next = NULL;
	}
	return el;
}

const Elem& DSlist :: Front() const
{
	Elem el = head -> elem;
	cout<<el;
}

const Elem& DSlist :: Back() const
{
	Elem el = tail -> elem;
	cout<<el;
}

void DSlist :: display()
{
	node *temp;
	for(temp = head; temp != NULL ; temp = temp -> next)
	{
		cout<< temp -> elem<< " ";
	}
}
