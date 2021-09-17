#include<iostream>
#include<fstream>		//For File-handling
#include"security.h"	//This header file contain admin "create account" and "login" functions...
/*			NOTE: The Header-File 'security.h' must be with the .cpp file. 
				   Otherwise it will give error and program does not 
					   run. This file contain secuity algorithms.*/
#include"customer.h"	// User Defined Header-File. For Customer Pannel
using namespace std;
void logo()
{
	cout << "				*******************************************************" << endl;
	cout << "			   			HAPPY GROUP RESTURANT" << endl;
	cout << "				*******************************************************" << endl;
}
class ADMIN;
ADMIN* Dish = NULL, * d, * d1, * track;
class ADMIN {
public:
	string items;
	float price;
	ADMIN* Next;
};
	void add_dish()
	{
		Dish = NULL;
		ofstream save;
		save.open("dishes.txt");
		int c;
		cout << "				>>> Enter Number Of Dishes You want to Enter: ";
		cin >> c;
		for (int i = 0; i < c; i++)
		{
			if (Dish == NULL)
			{
				Dish = new ADMIN;
				cout << "				>>> Enter Dish Name (Place '_' underscore between Multiple Words): ";
				cin >> Dish->items;
				cout << "				>>> Price of " << Dish->items << ": ";
				cin >> Dish->price;
				Dish->Next = NULL;
				save << Dish->items << "			" << Dish->price << endl;
			}
			else
			{
				d = Dish;
				while (d->Next != NULL)
				{
					d = d->Next;
				}
				d1 = new ADMIN;
				cout << "				>>> Enter Dish Name (Place '_' underscore between Multiple Words): ";
				cin >> d1->items;
				cout << "				>>>> Price of " << d1->items << ": ";
				cin >> d1->price;
				d1->Next = NULL;
				d->Next = d1;
				save << d1->items << "			" << d1->price << endl;
			}
		}
		save.close();
		cout << "				>>> Dishes Added To List Successfully <<<" << endl;
		system("pause");
		system("cls");
		start = NULL;
	}
	void Add_new()
	{
		Dish = NULL;
		ofstream Update;
		Update.open("dishes.txt", ios::app);
		int UP_c;
		cout << "					<<< No. of Dishes You want to Enter >>> ";
		cin >> UP_c;
		for (int i = 0; i < UP_c; i++)
		{
			d = Dish;
			while (d != NULL)
			{
				d = d->Next;
			}
			d1 = new ADMIN;
			cout << "				>>> Enter Dish Name (Place '_' underscore between Multiple Words): ";
			cin >> d1->items;
			Update << d1->items << "				";
			cout << "				>>> Price of " << d1->items << ": ";
			cin >> d1->price;
			Update << d1->price << endl;
			d1->Next = NULL;
		}
		cout << "					<<< DISHES UPDATED SUCCESSFULLY >>> \a" << endl;
		system("pause");
		system("cls");
		logo();
		Update.close();
	}
void Dish_panel()
{
	logo();
PanelPoint:
	int delC;
	string temp_read="none";
	ifstream temp_ext;
	ofstream del;
	int update_choice;
	cout << "					1. ADD Dishes" << endl;
	cout << "					2. Update Dishes" << endl;
	cout << "					3. Remove Dishes" << endl;
	cout << "					4. Previous Menu" << endl;
	cout << "					<<< Enter Your Choice >>> ";
	char option = '0';
	cin >> option;
	switch (option)
	{
	case '1':
		add_dish();
		goto PanelPoint;
	case '2':
		update_point:
		system("cls");
		logo();
		cout << "					1. ADD New Dishes" << endl;
		cout << "					2. Previous Menu" << endl;
		cout << "					<<< Your Choice >>> ";
		cin >> update_choice;
		switch (update_choice)
		{
		case 1:
			Add_new();
			goto PanelPoint;
		case 2:
			system("cls");
			logo();
			goto PanelPoint;
		default:
			cout << "					<<< INVALID ENTRY >>>" << endl;
			goto update_point;
		}
	case '3':
		system("cls");
		logo();
		cout << "					1. Remove all Dishes" << endl;
		cout << "					2. Previous Menu" << endl;
		cout << "					<<< Enter Your Choice >>> ";
		cin >> delC;
		switch (delC)
		{
		case 1:
			temp_ext.open("dishes.txt");
			temp_ext >> temp_read;
			if (temp_read == "none")
			{
				cout << "					<<< No DATA SAVED YET >>>" << endl;
				system("pause");
				system("cls");
				logo();
				goto PanelPoint;
			}
			else {
				Dish = NULL;
				del.open("dishes.txt");
				del << "none";
				del.close();
				remove("dishes.txt");
				cout << "					))) ALL DISHES DELETED SUCCESSFULLY (((" << endl;
				system("pause");
				system("cls");
				logo();
				start = NULL;
				goto PanelPoint;
			}
		case 2:
			system("cls");
			logo();
			goto PanelPoint;
		default:
			cout << "					<<< INVALID ENTRY >>>" << endl;
			goto PanelPoint;
		}
	case '4':
		system("cls");
		break;
	default:
		cout << "					<<< INVALID ENTRY >>> " << endl;
		goto PanelPoint;
	}
}
			//******************* MAIN BODY********************
int main()
{
	system("color 0b");
START:		//Call Point.
	logo();
	int choice;
	int option;
	int dish_checker=0;
	//This 'check_account' is used to check weather the admin has account or not.
	string check_account = "none";
	ifstream check_file_pass;
	check_file_pass.open("Admin_details.txt");
	getline(check_file_pass, check_account);
	check_file_pass.close();
	SECURITY S;
	//*************Main Pannel***************
	cout << endl << endl;
	cout << "					1. Admin Pannel" << endl;
	cout << "					2. Customer Pannel" << endl;
	cout << "					3. Exit Program" << endl;
	cout << "					===>Enter Your Choice: ";
	cin >> choice;
	//This switch is used to Control Main Panne;
	switch (choice)
	{
	case 1:
		system("cls");
	admin_pannel:		//Call Point
		//*******************Admin Menu***********************
		logo();
		cout << "				--------------------------" << endl;
		cout << "				1. Create Account" << endl;
		cout << "				--------------------------" << endl;
		cout << "				2. Login To Your Account" << endl;
		cout << "				--------------------------" << endl;
		cout << "				3. Previous Menu" << endl;
		cout << "				--------------------------" << endl;
		cout << "				===>Enter Your Choice: ";
		cin >> option;
		//This switch statement is used to Control Admin Pannel.
		switch(option)
		{
		case 1:
			//Creating Account Section
			if (check_account == "none")
			{
				system("cls");
				logo();
				S.create();		//To create Admin Account
				goto admin_pannel;
			}
			else
			{
				//If account already exist, this section will call log_in()
				cout << "				<<<< Already an existing Admin account >>>>" << endl;
				S.log_in();		//To Login to existing account
				Dish_panel();	//After Loging in, Program will execute this function. 
								//This contains admin functions, like dish editing etc...
				goto START;
			}
		case 2:
			S.log_in();
			Dish_panel();
			goto START;
		case 3:
			system("cls");
			goto START;
		default:	// Default Switch Case.
			cout << "					<<<< INVALID ENTRY >>>>" << endl;
			goto admin_pannel;
		}
	case 2:
		system("cls");
		logo();
		dish_checker = display_Menu();
		if (dish_checker == 1)
		{
			goto START;
		}
		else if(dish_checker==-1)
		{
			Get_Input();
			system("cls");
			logo();
			SLIP();
			goto START;
		}
	case 3:
		system("color 0e");
		cout << endl << endl;
		cout << "				>>>>>>>>>>>  Exiting Program  <<<<<<<<<<<" << endl;
		system("pause");
		break;
	default:
		system("color 0c");
		cout << endl;
		cout << "					<<<< INVALID ENTRY >>>>" << endl;
		system("pause");
		system("cls");
		goto START;
	}
}
