// This header-file contanins functions related to customer...
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void C_logo()
{
	cout << "				*******************************************************" << endl;
	cout << "			   			HAPPY GROUP RESTURANT" << endl;
	cout << "				*******************************************************" << endl;
}
struct CUSTOMER {
	string item;
	float price;
	int Sr_no;	//Sr_no gives the serial number to the items.
	CUSTOMER* next;
};
CUSTOMER* start=NULL, * temp, * temp1, * point; // Global Pointers...
int counter=0;	// Counter for total dishes...
float BILL = 0;	// Saves total Bill of Customer...
char cancel;	// For Cancellation of Billing...
int display_Menu()
{
	string identify_dish = "none";
	ifstream Check_dish;
	Check_dish.open("dishes.txt");
	Check_dish >> identify_dish;
	Check_dish.close();
	if (identify_dish == "none")
	{
		cout << "					>>> No Dishes Available <<<" << endl;
		system("pause");
		system("cls");
		return 1;
	}
	else
	{
		ifstream extract;		//File handling variable...
		extract.open("dishes.txt");
		while (!extract.eof())
		{
			if (start == NULL)
			{			//Get details from the file and save it into structure's variables.
				start = new CUSTOMER;
				extract >> start->item;
				extract >> start->price;
				start->next = NULL;
				counter++;
				start->Sr_no = counter;
			}
			else
			{
				temp = start;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp1 = new CUSTOMER;
				extract >> temp1->item;
				extract >> temp1->price;
				counter++;
				temp1->Sr_no = counter;
				temp1->next = NULL;
				temp->next = temp1;
			}
		}
		extract.close();
	}
	point = start;
	// Exceptional IF condition...
	if (start == NULL)
	{
		cout << "					>>> No Dishes Available <<<" << endl;
	}
	else
	{
		cout << "				***********************MENU CHART**********************" << endl;
		int i = 1;
		cout << "				  =================================================" << endl;
		cout << "				     DISHES				 Price" << endl;
		cout << "				  =================================================" << endl;
		while (point->next != NULL)
		{
			cout << "				  " << i << ")-  " << point->item << "\t\t\t\t" << "Rs." << point->price << endl;
			cout << "				  -------------------------------------------------" << endl;
			point = point->next;
			i++;
		}
	}
	return -1;
}
		// This functions gets the input from the user. Selection of dishes...
void Get_Input()
{
	int Selection;
	float qty;
	do
	{
		POINT_SELECTION:
		cout << "				  <<< SELECT YOUR CHOICE ('0' To Proceed) >>> ";
		cin >> Selection;
		if (Selection >= counter)
		{
			cout << "					*** OUT OF RANGE ***" << endl;
			goto POINT_SELECTION;
		}
		if (Selection == 0)
			break;
		temp = start;
		while (temp!=NULL)
		{
			if (temp->Sr_no == Selection)
				break;
			temp = temp->next;
		}
		cout << "				<<<< YOUR CHOICE >>> " << temp->item << endl;
		cout << "				   <<<< Price >>> Rs. " << temp->price << endl;
		cout << "				<<< Enter Quantity >>> ";
		cin >> qty;
		BILL += (temp->price * qty);
	} while (Selection != 0);
	R_point:
	cout << "					0. Proceed Billing" << endl;
	cout << "					#. Cancel Billing" << endl;
	cout << "					<<< Select Your Choice >>> ";
	cin >> cancel;
	if (cancel == '#')
	{
		cout << "					***** Billing Cancelled *****" << endl;
		system("pause");
	}
	else if (cancel == '0')
	{
		cout << "				\a	<<< Proceeding for BILLING >>>" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "					<<< INVALID ENTRY >>>" << endl;
		goto R_point;
	}
	system("cls");
	start = NULL;
	counter = 0;
}
void SLIP()
{
	if (cancel == '#')
	{
		system("cls");
		return;
	}
	if (BILL == 0)
	{
		cout << "					>>> You Hav'nt Selected Any Item <<<" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string c_name, contact, c_ID;
		float amount_payed;
		cout << "						<<< TOTAL BILL >>> Rs. " << BILL << endl;
		cout << "						<<< Enter Your Name >>> ";
		cin >> c_name;
		cout << "						<<< Enter ID Card >>> ";
		cin >> c_ID;
		cout << "						<<<Enter Phone Number >>> ";
		cin >> contact;
	pay_again:
		cout << "						<<< Enter Payable Amount >>> Rs. ";
		cin >> amount_payed;
		if (amount_payed < BILL)
		{
			cout << "				--- Not Enough Amount ---" << endl;
			goto pay_again;
		}
		cout << "						<<< Remaining Amount >>> Rs. " << amount_payed - BILL << endl;
		cout << endl;
		cout << "							>>> Thank You <<<" << endl;
		system("pause");
		system("cls");
		ofstream save_slip;
		save_slip.open("slip.txt", ios::app);
		save_slip << c_ID << endl;
		save_slip << "Name: " << c_name << endl;
		save_slip << "Contact No: " << contact << endl;
		save_slip << "Total Bill: " << BILL << endl;
		save_slip << "Amount Payed By Customer: " << amount_payed << endl;
		save_slip.close();
		BILL = 0;
	}
}