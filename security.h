#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void S_logo()
{
	cout << "				*******************************************************" << endl;
	cout << "			   			HAPPY GROUP RESTURANT" << endl;
	cout << "				*******************************************************" << endl;
}
class SECURITY {
	//Variables Declared...
	string first_name, last_name;
	int age;
	string email, admin_phno, password, final_pass;
public:
	//Constructor to 'NONE' The Email and password Containers...
	SECURITY()
	{
		email = "none", password = "none";
	}
	//Function to Login To existing account
	void log_in()
	{
		//First it will check if any previous account exist...
		ifstream Check;
		Check.open("password.txt");
		Check >> password;
		Check.close();
		if (password == "none")
		{
			point_choice:
			char choice;
			cout << "				<<< No existing account. Create one >>>";
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				create();
				break;
			case 'N':
			case 'n':
				cout << "				))) As you wish (((" << endl;
				system("pause");
				system("cls");
				break;
			default:
				system("color 0c");
				cout << "				<<<< INVALID ENTRY. TRY AGAIN >>>>" << endl;
				goto point_choice;
			}

		}
		//This Section contains Login Account Algorithm...
		else
		{
			string mail, pass;
			ifstream check_mail;
			check_mail.open("mail.txt");
			ifstream check_pass;
			check_pass.open("password.txt");
			check_mail >> mail;
			check_pass >> pass;
			check_mail.close();
			check_pass.close();
		try_again:
			//If Email OR Password does not match, The Program will re-run from this point...
			cout << "				>>>> Enter Your E-mail address (Lower Case Only): ";
			cin >> email;
			cout << "				>>>> Enter Password: ";
			cin >> password;
			if (email != mail || password != pass)
			{
				cout << "			>>>> Your E-mail or Password is Invalid. Try again <<<<" << endl;
				goto try_again;
			}
			else
			{
				//This include The feature which shows Admin Name After Successful Login...
				string admin_name;
				ifstream get_name;
				get_name.open("Admin_details.txt");
				for (int i = 0; i < 2; i++)
				{
					get_name >> admin_name;
				}
				cout << "						<<<< ACCESS GRANTED >>>>" << endl;
				getline(get_name, admin_name);
				cout << "					>>>> Welcome Back Mr. " << admin_name << " <<<<" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	//This Function Creates An Admin Account and save it into files using file-handling
	//Condition is in the main body if account is already existing, then login function will be called.
	void create()
	{
		cout << "--->Enter First Name: ";
		cin >> first_name;
		cout << "--->Enter Last Name: ";
		cin >> last_name;
		cout << "--->Enter Age: ";
		cin >> age;
		cout << "--->Enter Your E-Mail Address (Lower_case only): ";
		cin >> email;
	Re_pass:
		// If Password and confirm password does not match then this point will be re-called.
		cout << "--->Enter Password: ";
		cin >> password;
		cout << "--->Confirm Password: ";
		cin >> final_pass;
		if (password != final_pass)
		{
			cout << "Password Does Not Match. Try again..." << endl;
			goto Re_pass;
		}
		cout << "--->Enter Phone Number: ";
		cin >> admin_phno;
		//This will Save Email and password in two seprate files. SECURITY REASONS :)
		ofstream inpass;
		ofstream inmail;
		inpass.open("password.txt");
		inpass << final_pass;
		inpass.close();
		inmail.open("mail.txt");
		inmail << email;
		inmail.close();
		// This will save data into 'Admin_details.txt' file...
		ofstream in_admin;
		in_admin.open("Admin_details.txt");
		in_admin << "Admin Name: " << first_name << " " << last_name << endl;
		in_admin << "Age: " << age << endl;
		in_admin << "E-mail Address: " << email << endl;
		in_admin << "Password: ";
		int len = password.length();
		for (int i = 1; i <= len; i++)
		{
			in_admin << "* ";
		}
		in_admin << endl;
		in_admin << "Phone Number: " << admin_phno << endl;
		in_admin.close();
		cout << "===>Account Created Successfully<===" << endl;
		system("pause");
		system("cls");
	}
};
