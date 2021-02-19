#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream read("testfile.txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;
	cout<<"1.Register \n2.Login \nEnter your choice ";cin>>choice;
	if (choice==1)
		{
		string username,password;
		cout<<"Enter your username "; cin>>username;
		cout<<"Enter your password "; cin>>password;
		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();
		main();
		}
	if (choice==2)
		{
		bool status = IsLoggedIn();
		if (!status)
			{
			cout<<"Username or password is Incorrect"<<endl;
			system("PAUSE");
			return 0;
			}
		else
			{
			cout<<"Logged In"<<endl;
			system("PAUSE");
			return 1;
			}
		}
	

	else 
		{
		cout<<"Wrong choice . Please retry"<<endl;
		main();
		}
}
