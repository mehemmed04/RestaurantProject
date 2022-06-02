#pragma once
#include<fstream>
#include<iostream>
#include"Start.h"
#include"Database.h"
using namespace std;


void WriteDatabaseToFile(Database& database) {
	Restaurant r = database.restaurant;
	ofstream fout("Database.txt", ios::out);
	fout << r.GetName() << "   " << r.GetAdress() << "   " << r.GetCity() << "   " << r.GetBudget() << "\n";
	fout << r.GetAdmins().size() << "\n";
	for (auto admin : r.GetAdmins())
	{
		fout << admin.GetUsername() << "   " << admin.GetPassword() << "\n";
	}
	fout << r.GetTables().size() << "\n";
	for (auto table : r.GetTables()) {
		fout << table.GetTableNo() << "  ";
		if (table.IsReady) fout << "ready" << "   ";
		else fout << "not-ready" << "   ";
		fout << "\n";
	}

	//stock

	Stock s = database.stock;

	fout << s.GetIngredients().size() << "\n";
	for (auto i : s.GetIngredients()) {
		fout << i.GetName() << "  " << i.GetKcal() << "   " << i.GetFats() << "   " << i.GetProtein() << "   " << i.GetPrice() << "\n";
	}


	//kitchen
	Kitchen k = database.kitchen;
	vector<Order> orders = k.GetOrders();
	vector<Meal> meals = k.GetMeals();

	fout << meals.size() << "\n";
	for (auto meal : meals) {
		fout << meal.GetName() << "   " << meal.GetRating() << "   " << meal.GetPrice() << "  " << meal.GetItems().size()<<"\n";

		for (auto i : meal.GetItems()) {
			fout << i.GetIngredient().GetName() << "   " << i.GetAmount() << "\n";
		}
	}

	fout << orders.size() << "\n";
	for (auto order : orders) {
		fout << order.GetTableNo() << "  ";
		if (order.GetisReady()) fout << "ready";
		else fout << "not-ready";
		fout << "\n";
		auto mealsinorder = order.GetMeals();

		fout << meals.size() << "\n";
		for (auto meal : meals) {
			fout << meal.GetName() << "   " << meal.GetRating() << "   " << meal.GetPrice() << "  " << meal.GetItems().size() << "\n";

			for (auto i : meal.GetItems()) {
				fout << i.GetIngredient().GetName() << "   " << i.GetAmount() << "\n";
			}
		}

	}
}
