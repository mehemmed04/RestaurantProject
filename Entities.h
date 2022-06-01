#pragma once
#include<iostream>
#include"Start.h"
#include<vector>
#include<string>
#include"Functions.h"
using namespace std;

class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	double kcal;
	double price;
public:
	Ingredient() {

	}
	Ingredient(const string& name, const double& fats, const double& protein, const double& carbohydrates, const double& kcal, const double& price) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetPrice(price);
	}
	void SetPrice(const double& price) {
		this->price = price;
	}

	void SetName(const string& name) {
		this->name = name;
	}
	void SetFats(const double& fats) {
		this->fats = fats;
	}
	void SetProtein(const double& protein) {
		this->protein = protein;
	}
	void SetCarbohydrates(const double& carbohydrates) {
		this->carbohydrates = carbohydrates;
	}
	void SetKcal(const double& kcal) {
		this->kcal = kcal;
	}

	string GetName()const { return name; }
	double GetFats()const { return fats; }
	double GetProtein()const { return protein; }
	double GetCarbohydrates()const { return carbohydrates; }
	double GetKcal()const { return kcal; }


	void ShowIngredient()const {
		cout << "Name : " << name << endl;
		cout << "Kcal : " << kcal << endl;
		cout << "Fats : " << fats << endl;
		cout << "Protein : " << protein << endl;
		cout << "Carbohydrates : " << carbohydrates << endl;
	}

};



struct RecipeItem {
	Ingredient ingredient;
	int amount = 0;// neche dene
public:
	RecipeItem(Ingredient ingredient, int amount) {
		this->ingredient = ingredient;
		this->amount = amount;
	}
	int GetAmount()const { return amount; }

	void ShowRecipeItemWithMicro()const {
		cout << "amount : " << amount << " gr" << endl;
		ingredient.ShowIngredient();
	}
	void ShowRecipeItem() {
		cout << "amount : " << amount << " gr" << endl;
		cout << "Name : " << ingredient.GetName()<<endl;
	}

};

class Meal {
protected:
	vector<RecipeItem> items;
	string name;
	double rating;
public:
	Meal() {}
	Meal(const string& name,const double& rating) {
		this->name = name;
		this->rating = rating;
	}
	virtual void AddIngredient(RecipeItem item) {
		items.push_back(item);
	}
	string GetName()const { return name; }

	virtual void Taste() {
		cout << "I do not know what is this ? " << endl;
	}

	virtual void PrintRecipeWithMicro() {
		cout << "Meal name : " << GetName() << endl;
		cout << "Meal Rating : " << rating << endl;
		cout << "Meal Ingredients : " << endl;
		for (auto i : items) {
			i.ShowRecipeItemWithMicro();
		}
		cout << "-----------------" << endl;


	}

	virtual void PrintRecipe() {
		cout << "Meal name : " << GetName() << endl;
		cout << "Meal Rating : " << rating << endl;
		cout << "Meal Ingredients : " << endl;
		for (auto i : items) {
			i.ShowRecipeItem();
		}
		cout << "-----------------" << endl;
	}
};



class Admin {
	string username;
	string password;
public:
	Admin() {

	}
	Admin(const string& username,const string& password){
		SetUsername(username);
		SetPassword(password);
	}

	void SetUsername(const string& username) {
		this->username = username;
	}
	void SetPassword(const string& password) {
		this->password = password;
	}

	string GetUsername() {
		return username;
	}
	string GetPassword() {
		return password;
	}

};


class Order {
	string Table_no;
	vector<Meal> meals;
public:
	Order(string Table_no,vector<Meal> meals) {
		this->Table_no = Table_no;
		SetMeals(meals);
	}
	void SetMeals(vector<Meal> meals) {
		this->meals = meals;
	}

	string GetTableNoByOrder() { return Table_no; }
	void ShowOrder() {
		for (auto meal : meals) {
			meal.PrintRecipe();
		}
	}
};

class Table {
	string table_no;
	vector<Order> orders;
	string MessageFromKitchen;
public:
	Table() = default;
	Table(const string& table_no) {
		SetTableNo(table_no);
	}
	void SetTableNo(const string& table_no) {
		this->table_no = table_no;
	}
	string GetTableNo()const {
		return table_no;
	}
	void AddOrder(const Order& order) {
		orders.push_back(order);
	}

	void SetMessageFromKitchen(const string& message) {
		this->MessageFromKitchen = message;
	}

};


class Restaurant {
	string name;
	string adress;
	string city;
	double budget = 0;
	vector<Admin> admins;
	vector<Table> tables;
public:
	Restaurant() = default;
	Restaurant(const string& name, const string& adress, const string& city) {
		SetName(name);
		SetAdress(adress);
		SetCity(city);
		budget = 0;
	}


	Table* GetTableByNoPtr(const string& table_no) {
		for (auto table : tables) {
			if (table.GetTableNo() == table_no) return &table;
		}
		return nullptr;
	}

	Table GetTableByNo(const string& table_no) {
		for (auto table : tables) {
			if (table.GetTableNo() == table_no) return table;
		}
	}

	Restaurant(const string& name, const string& adress, const string& city, vector<Admin> admins):Restaurant(name,adress,city) {
		SetAdmins(admins);
	}

	void AddTable(const Table& table) {
		tables.push_back(table);
	}

	vector<Admin>GetAdmins() {
		return admins;
	}

	void SetName(const string& name) { this->name = name; }

	void SetAdress(const string& adress) {
		this->adress = adress;
	}
	void SetCity(const string& city) {
		this->city = city;
	}

	void SetAdmins(vector<Admin> admins) {
		this->admins = admins;
	}

	void AddAdmin(const Admin& admin) {
		admins.push_back(admin);
	}

	void IncreaseBudget(double b) {
		budget += b;
	}

};



class Stock {
	vector<Ingredient> ingredients;
public:
	Ingredient GetIngredient() {
		string name; double fats; double protein; double carbohydrates; double price;
		double kcal;
		system("cls");
		SetCordinates(50, 10);
		cout << "Enter Ingredient Name : "; getline(cin, name);
		SetCordinates(50, 11);
		cout << "Enter Ingredient Fats : "; cin >> fats;
		SetCordinates(50, 12);
		cout << "Enter Ingredient Protein : "; cin >> protein;
		SetCordinates(50, 13);
		cout << "Enter Ingredient Carbohydrates : "; cin >> carbohydrates;
		SetCordinates(50, 14);
		cout << "Enter Ingredient kcal : "; cin >> kcal;
		SetCordinates(50, 15);
		cout << "Enter Ingredient Price : "; cin >> price;

		return Ingredient(name, fats, protein, carbohydrates, kcal, price);

	}

	void AddIngredient(const Ingredient& ingredient) {
		ingredients.push_back(ingredient);
	}
	void DeleteIngredient() {

	}
	void ShowAllIngredients() {
		cout << "STOCK : " << endl;
		for (auto i : ingredients) {
			i.ShowIngredient();
			cout << endl;
		}
		
	}
	Ingredient GetIngredientByName(const string& name) {
		for (auto i : ingredients) {
			if (i.GetName() == name) {
				return i;
			}
		}
		return Ingredient();
	}

	void DecraseIngredientCount() {

	}
	void IncreaseIngredientCount() {

	}
};

class Kitchen {
	vector<Order> orders;
	vector<Meal> meals;
public:
	void ShowAllOrders() {
		system("cls");
		for (auto order : orders) {
			cout << "Table : " << order.GetTableNoByOrder() << endl;
			order.ShowOrder();
			cout << "=====================" << endl;
		}
	}
	void AddOrder(const Order& order) {
		orders.push_back(order);
	}
	void AddMeal(const Meal& meal) {
		meals.push_back(meal);
	}
	void DeleteMeal() {

	}

	Meal* GetMealPtrByName(const string& meal_name) {
		for (auto meal : meals) {
			if (meal.GetName() == meal_name) return &meal;
		}
		return nullptr;
	}

	Meal GetMealByName(const string& meal_name) {
		for (auto meal : meals) {
			if (meal.GetName() == meal_name) return meal;
		}
	}

	void UpdateMeal(){

	}

	void ShowStock() {
		
	}

	void ShowAllMeals() {
		for (auto meal : meals) {
			meal.PrintRecipe();
		}
	}

};