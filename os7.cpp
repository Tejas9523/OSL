#include<iostream>
using namespace std;

int mutex = 1;
int full = 0;
int empty = 5, x = 0;
int arr[]={0,0,0,0,0};

void set(){
    cout<<"[";
	for(int i=0;i<5;i++){
    cout<<arr[i]<<",";
    }
    cout<<"]"<<endl;
}

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
    arr[x-1]=1;
	cout<<"Producer produces item "<<x<<endl;
	set();

	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
    arr[x-1]=0;
	cout<<"Consumer consumes item "<<x<<endl;
	set();
	x--;
	++mutex;
}

int main()
{
	int n, i;
	set();
	cout<<"1. Press 1 for Producer\n";
	cout<<"2. Press 2 for Consumer\n";
	cout<<"3. Press 3 for Exit\n";

	for (i = 1; i > 0; i++) {

		cout<<endl<<"Enter your choice - ";
		cin>>n;

		switch (n) {
		case 1:

		
			if ((mutex == 1)
				&& (empty != 0)) {
				producer();
			}

		
			else {
				cout<<"Buffer is full...!!!\n";
			}
			break;

		case 2:

			if ((mutex == 1)
				&& (full != 0)) {
				consumer();
			}

			
			else {
				cout<<"Buffer is empty...!!!\n";
			}
			break;

		case 3:
			exit(0);
			break;
		}
	}
}

