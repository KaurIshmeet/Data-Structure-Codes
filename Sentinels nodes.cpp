#include <iostream>

using namespace std;

typedef int Elem;
class CNode{
	private:
		Elem elem;
		CNode *next;
		friend class Clist;
};
class Clist{
	public:
		Clist();
		~Clist();
		bool empty() const;
		const Elem& Front() const;
		const Elem& Back() const;
		void advance();
		void add(const Elem& e);
		void remove();
		void display();
		
	private:
		CNode* cursor;
};

Clist :: Clist(){
	cursor = NULL;
}

Clist :: ~Clist()
{
	while(!empty())
	{
		remove();
	}
}

bool Clist :: empty() const
{
	return (cursor == NULL);
}

const Elem& Clist :: Front() const
{
	return (cursor -> next -> elem);
}

const Elem& Clist :: Back() const
{
	return (cursor -> elem);
}

void Clist :: advance()
{
	cursor = cursor -> next;
}

void Clist :: add(const Elem& e)
{
	CNode* v = new CNode;
	v -> elem = e;
	if(cursor == NULL){
		v -> next = v;
		cursor = v;
	}
	else{
		v -> next = cursor -> next;
		cursor -> next = v;
	}
}

void Clist :: remove()
{
	CNode* old = cursor -> next;
	if(old == cursor){
		cursor = NULL;
	}
	else{
		cursor -> next = old -> next;
	}
	delete old;
}

void Clist::display()
{
    //cout << "Circular Linked List is: " << endl;

    CNode *temp = cursor;
    cout<<"[ ";
    for (temp = cursor -> next; temp != cursor; temp = temp->next)
    {
        cout << temp->elem << " , ";
    }
    cout << temp->elem;
    cout <<" ]";
    cout << endl;
}

//int main(){
//	
//	cout<<"* --------------------------------- MENU --------------------------------- *"<<endl;
//	cout<<"*   01) Insert value in the circular linked list.                          *"<<endl;
//	cout<<"*   02) Return the front element from the linked list.                     *"<<endl;
//	cout<<"*   03) Return the last element from the linked list.                      *"<<endl;
//	cout<<"*   04) Increase the value of cursor to it's next node.                    *"<<endl;
//	cout<<"*   05) Check that the list is empty or not.                               *"<<endl;
//	cout<<"*   06) Display the linked list.                                           *"<<endl;    
//	cout<<"*   07) Remove an element from the linked list.                            *"<<endl;
//	cout<<"* ------------------------------------------------------------------------ *"<<endl;
//	cout<<endl;
//	
//	Clist obj,obj2;
//	int k;
//	string val;
//	
//	obj2.add("Hello");
//	obj2.add("my");
//	obj2.add("dream.");
//	
//	do{
//		cout<<"Enter choice: "<<endl;
//		cin>>k;
//		switch(k){
//			case 0:{cout<<"Program terminated.";
//				    break;
//			}
//			case 1:{cout<<"Enter an element to add on head: ";
//			        cin>>val;
//			        obj.add(val);
//			        cout<<endl;
//				    break;
//			}
//			case 2:{cout<<obj.Front();
//			        cout<<endl;
//				    break;
//			}
//			case 3:{cout<<obj.Back();
//			        cout<<endl;
//				    break;
//			}
//			case 4:{obj.advance();
//			        cout<<endl;
//				    break;
//			}
//			case 5:{bool result = obj.empty();
//			        if(result == true){
//			        	cout<<"Empty."<<endl;
//					}
//					else{
//						cout<<"Not Eempty."<<endl;
//					}
//				    break;
//			}
//			case 6:{obj.display();
//				break;
//			}
//			case 7:{obj.remove();
//			        cout<<endl;
//				    break;
//			}
//			default:{cout<<"Invalid value.";
//				    break;
//			}
//		}
//	}while(k!=0);
//	return 0;
//}
