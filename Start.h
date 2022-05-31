#pragma once
#include<iostream>
#include<Windows.h>
#include"Entities.h"
#include"Database.h"
#include<string>
#include<conio.h>
using namespace std;

class Controller {
	Database database;
	int Set[3] = { 7,7,7 }; //DEFAULT COLORS
	int counter = 1;
	char key;
public:
	void INIT() {
		Restaurant r("Zeytin Bagi", "9-cu mkr", "Baku", vector<Admin>{Admin("admin", "admin")});
		database.restaurant = r;
		//Admin("admin", "admin");
		//database.restaurant.AddAdmin(admin1);

	}
	void StartProject() {

		INIT();
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
					AdminPanel();
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

	void AdminPanel() {
		system("cls");
		string username; string password;
		SetCordinates(55, 12);
		cout << "Enter Username : "; getline(cin, username);
		SetCordinates(55, 13);
		cout << "Enter Password : "; getline(cin, password);

		if (IsAdmin(username, password)) {
			auto CurrentAdmin = GetAdmin(username, password);
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
						//KITCHEN

					}
					else if (counter == 2) {
						//STOCK
					}
					else if (counter == 3) {
						StartProject();
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
		else {
			SetCordinates(60, 12);
			system("cls");
			cout << "ACCESS DENIED" << endl;
		}
		system("pause");
	}
	void ClientPanel() {
		color(7);
		system("cls");
		cout << "Enter Tabel number : ";

	}

	void color(int color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void SetCordinates(int x, int y) {
		COORD c;
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}



};