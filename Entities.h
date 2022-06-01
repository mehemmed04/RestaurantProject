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


//Yemek DISH

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
		cout << "INGREDIENTS : " << endl;
		for (auto i : items) {
			i.ShowRecipeItemWithMicro();
		}
	}

	virtual void PrintRecipe() {
		cout << "INGREDIENTS : " << endl;
		for (auto i : items) {
			i.ShowRecipeItem();
		}
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
	vector<Meal> meals;
};

class Table {
	string table_no;
	vector<Order> orders;
	string MessageFromKitchen;
};


class Restaurant {
	string name;
	string adress;
	string city;
	double budget = 0;
	vector<Admin> admins;
public:
	Restaurant() = default;
	Restaurant(const string& name, const string& adress, const string& city) {
		SetName(name);
		SetAdress(adress);
		SetCity(city);
		budget = 0;
	}

	Restaurant(const string& name, const string& adress, const string& city, vector<Admin> admins):Restaurant(name,adress,city) {
		SetAdmins(admins);
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

		return Ingredient();
	}

	void DecraseIngredientCount() {

	}
	void IncreaseIngredientCount() {

	}
};

class Kitchen {
	vector<Order> orders;

public:
	void ShowAllMeals() {

	}
	
	void AddMeal() {

	}
	void DeleteMeal() {

	}
	void UpdateMeal(){

	}

	void ShowStock() {

	}

};