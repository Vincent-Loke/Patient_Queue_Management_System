#include<iostream>
#include"doctorFunctions.hpp"

int main(int argc, char *argv[]) 
{
	autoAddData();

	//Login Function Here
	int num;
	string account, password, type;
	bool flag = false;
	while(true)
	{
	    cout<<"Weclome to Patient Queue Based Management System\n";
		cout<<"\n**********************************\n*              Login             *\n**********************************";
		cout<<"\nLogin as:\n1. Doctor \n2. Nurse \nYour Selection: ";	
		
		cin>>num;
		if(num == 1)
		{
			type = "doctor";
		} 
		else if(num == 2)
		{
			type = "nurse";
		} 
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout<<"Please enter 1 or 2 \n\n";
			system("pause");
		    system("cls");
		    continue;
		}
		else 
		{
			cout<<"Please enter 1 or 2 \n\n";	
			system("pause");
		    system("cls");
			continue;
		}
		
		cin.ignore();
	    cout<<"Account Name: ";
	    getline(cin,account);
	
	    cout<<"Password: ";
	    getline(cin,password);
		
		flag = searchAccount(account, password, type);
		if(!flag)
		{
			cout<<"\nAccout and password is error. Please enter again\n\n";
			system("pause");
		    system("cls");
			continue;
		} 
		else 
		{
			if(num == 1)
			{
				system("cls");
				cout<<"Welcome Doctor "<<account<<", "<<endl;
				doctorMenu();
			} 
			else if(num == 2)
			{
				system("cls");
				cout<<"Welcome Nurse "<<account<<", "<<endl;
				nurseMenu();
			}
		}
	}
	return 0;
}

