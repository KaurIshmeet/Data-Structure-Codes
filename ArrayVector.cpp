#include <iostream>
using namespace std;

typedef int Elem;
class ArrayVector{
	public:
		ArrayVector();
		~ArrayVector();
		int size() const;
		bool empty() const;
		Elem& operator[] (int i);
		Elem& at(int i);
		void erase(int i);
		void insert(int i, const Elem& e);
		void reserve(int N);
		void display();
	private:
		int capacity;
		int n;
		Elem* A;
};

ArrayVector :: ArrayVector()
	:capacity(0), n(0), A(NULL){ }
	
int ArrayVector :: size() const
{
	return n;
}

bool ArrayVector :: empty() const
{
	return (size() == 0);
}

Elem& ArrayVector :: operator[] (int i)
{
	return A[i];
}

Elem& ArrayVector :: at(int i)
{
	if(i<0 || i>=n){
		cout<<"INDEX OUT OF BOUNDS";
	}
	else{
		return A[i];
	}
}

void ArrayVector :: erase(int i)
{
	for(int j = i+1; j<n; j++){
		A[j-1] = A[j];
	}
	n--;
}

void ArrayVector :: reserve(int N)
{
	if(capacity >= N) return;
	Elem* B = new Elem[N];
	for(int j=0; j<n; j++){
		B[j] = A[j];
	}
	if(A != NULL) delete [] A;
	A = B;
	capacity = N;
}

void ArrayVector :: insert(int i, const Elem& e)
{
	if(n >= capacity){
		reserve(max(1,2*capacity));
	}
	for(int j=n-1; j>=i; j--){
		A[j+1] = A[j];
	}
	A[i] = e;
	n++;
}

void ArrayVector :: display()
{
	cout<<"Vector is : ";
	for(int i=0; i<size(); i++){
		cout<<A[i]<<" ";
	}
}

ArrayVector :: ~ArrayVector()
{
	while (!empty())
        erase(0);
	cout<<"destructor called"<<endl;
}

int main(){
	cout<<"*------------------------------- MENU --------------------------------*"<<endl;
	cout<<"*   01) Insert an element.                                            *"<<endl;
	cout<<"*   02) Return element at specific index using at function.           *"<<endl;
	cout<<"*   03) Return element at specific index using 'operator' function.   *"<<endl;
	cout<<"*   04) Display the vector.                                           *"<<endl;
	cout<<"*   05) Size of the vector.                                           *"<<endl;
	cout<<"*   06) Check that vector is EMPTY or NOT.                            *"<<endl;
	cout<<"*   07) Erase element from the specific index.                        *"<<endl;
	cout<<"*   08) Call to destructor.                                           *"<<endl;
	cout<<"*   09) Call the reverse function.                                    *"<<endl;
	cout<<"*---------------------------------------------------------------------*"<<endl;
	cout<<endl;
	
	ArrayVector obj;
	int k,i;
	int val;
	cout<<endl;
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 1:{cout<<"Enter value to be pushed : ";
			        cin>>val;
			        cout<<"Enter the index : ";
			        cin>>i;
			        obj.insert(i,val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter the index : ";
			        cin>>i;
					cout<<"Element is : "<<obj.at(i);
					cout<<endl;
				    break;
			}
			case 3:{cout<<"Enter the index : ";
			        cin>>i;
					cout<<"Element is : "<<obj.operator[](i);
					cout<<endl;
				    break;
			}
			case 4:{obj.display();
			        cout<<endl;
				    break;
			}
			case 5:{cout<<"Size of the vector is : "<<obj.size();
					cout<<endl;
					break;
			}
			case 6:{bool result = obj.empty();
					if(result == true){
						cout<<"Vector is empty.";
					}
					else{
						cout<<"Vector is not empty.";
					}
			        cout<<endl;
					break;
			}
			case 7:{cout<<"Enter the index : ";
			        cin>>i;
			        obj.erase(i);
			        cout<<"Element erased.";
			        cout<<endl;
					break;
			}
			case 8:{obj.~ArrayVector();
					break;
			}
			case 9:{cout<<"Enter the index : ";
			        cin>>i;
					obj.reserve(i);
					cout<<endl;
					break;
			}
			default:{cout<<"Invalid value.";
				break;
			}
		}
	}while(k!=11);
	
	return 0;
	
}
