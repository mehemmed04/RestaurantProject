#pragma once
#include<iostream>
#include<Windows.h>
#include"Entities.h"
#include"Database.h"
#include"Functions.h"
#include<string>
#include<conio.h>
using namespace std;

class Controller {
	Admin CurrentAdmin;
	Database database;
	int Set[6] = { 7,7,7,7,7,7 }; //DEFAULT COLORS
	int counter = 1;
	char key;
public:
	void INIT() {
		Table t1("T1");
		Table t2("T2");
		Table t3("T3");

		Restaurant r("Zeytin Bagi", "9-cu mkr", "Baku", vector<Admin>{Admin("admin", "admin")});
		database.restaurant = r;
		database.restaurant.AddTable(t1);
		database.restaurant.AddTable(t2);
		database.restaurant.AddTable(t3);
		Ingredient i1("Cheese", 20.3, 25.2, 3.2, 200.25, 1.5);
		Ingredient i2("Tomato", 5, 1.2, 3.4, 170.25, 0.5);

		RecipeItem r1(i1, 3);
		RecipeItem r2(i2, 2);

		Meal m1("Dolma", 9.8);
		m1.AddIngredient(r1);
		m1.AddIngredient(r2);

		Meal m2("Plov", 9.6);
		m2.AddIngredient(r1);

		database.stock.AddIngredient(i1);
		database.stock.AddIngredient(i2);
		database.kitchen.AddMeal(m1);
		database.kitchen.AddMeal(m2);
	}

	void StartProject() {
		INIT();
		Start();
	}

	void Start() {
		counter = 1;
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;

#pragma region ConsoleFontSizeController
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = 24;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
#pragma endregion


		while (true)
		{
			system("cls");
			
			ShowHomeMenu();
			key = _getch();
			
			if (key == 72 && (counter == 2)) counter--; // 72 up arrow key
			else if (key == 80 && (counter== 1)) counter++; // 80 down arrow key
			
			if (key == '\r') {// carriage return  = Enter
				if (counter == 1) {
					system("cls");
					string username; string password;
					SetCordinates(50, 12);
					cout << "Enter Username : "; getline(cin, username);
					SetCordinates(50, 13);
					cout << "Enter Password : ";
#pragma region EnteringPassword

					char d;
					int i = 0;
					while (true)
					{
						d = _getch();
						if (d == '\r')
							break;
						if (d == 8)
						{
							cout << "\b \b";
							password[i] = '\0';
						}
						else
							cout << "*";
						password.push_back(d);
						i++;
					}
					password[i] = '\0';
#pragma endregion

					if (IsAdmin(username, password)) {
						CurrentAdmin = GetAdmin(username, password);
						AdminPanel(CurrentAdmin);
					}
					else {
						system("cls");
						SetCordinates(60, 12);
						color(12);
						cout << "ACCESS DENIED" << endl;
						color(7);
					}
					system("pause");
				}
				else if (counter == 2) {
					ClientPanel();
				}
			}
			Set[0] = 7;
			Set[1] = 7;
			if (counter == 1) {
				Set[0] = 12; // Color RED
			}
			else if (counter == 2) {
				Set[1] = 12;
			}

		}


	}


	void ShowHomeMenu() {
		 // admin && client select
		SetCordinates(60, 12);
		color(Set[0]);
		cout << "ADMIN" << endl;
		SetCordinates(60, 13);
		color(Set[1]);
		cout << "CLIENT" << endl;

	}
	

	bool IsAdmin(const string& username,const string& password) {
		
		for (auto admin : database.restaurant.GetAdmins()) {
			if (admin.GetUsername() == username &&
				admin.GetPassword() == password) {
				return true;
			}
		}
		return false;
	}

	Admin GetAdmin(const string& username, const string& password) {
		for (auto admin : database.restaurant.GetAdmins()) {
			if (admin.GetUsername() == username &&
				admin.GetPassword() == password) {
				return admin;
			}
		}
		return Admin();
	}

	void AdminPanel(Admin& admin) {
		auto CurrentAdmin = admin;
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		color(Set[0]);
		counter = 2;
		while (true)
		{
			system("cls");
			SetCordinates(60, 12); color(Set[0]); cout << "KITCHEN" << endl;
			SetCordinates(60, 13); color(Set[1]); cout << " STOCK " << endl;
			SetCordinates(60, 14); color(Set[2]); cout << " BACK " << endl;
			key = _getch();

			if (key == 72 && (counter >= 2 && counter <= 3)) counter--; // 72 up arrow key
			if (key == 80 && (counter >= 1 && counter <= 2)) counter++; // 80 down arrow key

			if (key == '\r') {// carriage return  = Enter
				if (counter == 1) {
					database.kitchen.ShowAllOrders();
					system("pause");

				}
				else if (counter == 2) {
					StockPanel();
				}
				else if (counter == 3) {
					Start();
				}
			}
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			if (counter == 1) {
				Set[0] = 12; // Color RED
			}
			else if (counter == 2) {
				Set[1] = 12;
			}
			else if (counter == 3) {
				Set[2] = 12;
			}


		}

	}
	

	void StockPanel() {
		counter = 3;
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;
		Set[5] = 7;
		color(Set[0]);
		
		while (true)
		{

			system("cls");
			SetCordinates(50, 12);
			color(Set[0]);
			cout << "Show All Ingredients" << endl;
			SetCordinates(50, 13);
			color(Set[1]);
			cout << "   Add Igredient    " << endl;
			SetCordinates(50, 14);
			color(Set[2]);
			cout << "  Delete ingredient " << endl;
			SetCordinates(50, 15);
			color(Set[3]);
			cout << " Increase Ingredient" << endl;
			SetCordinates(50, 16);
			color(Set[4]);
			cout << " Decrease Ingredient" << endl;
			color(Set[5]);
			SetCordinates(50, 17);
			cout << "        Back        " << endl;
			key = _getch();

			if (key == 80 && (counter >= 1 && counter <= 2)) counter++; // 80 down arrow key
			
			else if (key == 72 && (counter >= 2 && counter <= 3)) counter--; // 72 up arrow key
			else if (key == 80 && (counter >= 2 && counter <= 3)) counter++; // 80 down arrow key

			else if (key == 72 && (counter >= 3 && counter <= 4)) counter--; // 72 up arrow key
			else if (key == 80 && (counter >= 3 && counter <= 4)) counter++; // 80 down arrow key

			else if (key == 72 && (counter >= 4 && counter <= 5)) counter--; // 72 up arrow key
			else if (key == 80 && (counter >= 4 && counter <= 5)) counter++; // 80 down arrow key

			else if (key == 72 && (counter >= 5 && counter <= 6)) counter--; // 72 up arrow key
			


			if (key == '\r') {// carriage return  = Enter
				if (counter == 1) {
					system("cls");
					database.stock.ShowAllIngredients();
					system("pause");
				}
				else if (counter == 2) {
					auto ingredient = database.stock.GetIngredient();
					database.stock.AddIngredient(ingredient);
					system("cls");
					SetCordinates(50, 13);
					cout << "Ingredient Added Succesfully" << endl;
					system("pause");
				}
				else if (counter == 3) {
					//DeleteIngredient
				}
				else if (counter== 4) {
					//Increase Ingredient
				}
				else if (counter == 5) {
					//Decrase Ingredient
				}
				else if (counter == 6) {
					AdminPanel(CurrentAdmin);
				}
			}
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			Set[4] = 7;
			Set[5] = 7;
			if (counter == 1) {
				Set[0] = 12; // Color RED
			}
			else if (counter == 2) {
				Set[1] = 12;
			}
			else if (counter == 3) {
				Set[2] = 12;
			}
			else if (counter == 4) {
				Set[3] = 12;
			}
			else if (counter == 5) {
				Set[4] = 12;
			}
			else if (counter == 6) {
				Set[5] = 12;
			}
		}

	}

	void ClientPanel() {
		system("cls");
		color(7);
		SetCordinates(55, 12);
		string table_no;
		cout << "Enter Table No : "; getline(cin, table_no);

		Table* CurrentTablePtr = database.restaurant.GetTableByNoPtr(table_no);

		if (CurrentTablePtr != nullptr) {
			Table CurrentTable = database.restaurant.GetTableByNo(table_no);
			system("cls");
			database.kitchen.ShowAllMeals();
			
			order(CurrentTable);
			system("pause");
			

		}
		else {
			system("cls");
			SetCordinates(45, 12);
			color(12);
			cout << "There is not table by this name, Try agin." << endl;
			color(7);
			system("pause");
		}

	}


	void order(Table& table) {
		vector<Meal>meals;
		do
		{
			string meal_name;
			cout << "Enter Meal Name : " << endl;
			getline(cin, meal_name);
			int choose = 0;
			Meal* CurrentMealPtr = database.kitchen.GetMealPtrByName(meal_name);
			if (CurrentMealPtr != nullptr) {
				Meal CurrentMeal = database.kitchen.GetMealByName(meal_name);
				cout << "Do yu want to continue to order Yes(1) : " << endl;
				cin >> choose;
				cin.ignore();
				cin.clear();
				meals.push_back(CurrentMeal);
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}
			else {
				cout << "There is not meal by this name. Try again." << endl;
			}
		} while (true);
		Order ord(table.GetTableNo(), meals);
		table.AddOrder(ord);
		database.kitchen.AddOrder(ord);

	}

};