#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
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

	void ShowRecipeItem()const {
		cout << "amount : " << amount << " gr" << endl;
		ingredient.ShowIngredient();

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


};

class Restaurant {
	string name;
	string adress;
	string city;
	double budget = 0;
	vector<Admin> admins;
public:
	Restaurant(const string& name, const string& adress, const string& city) {
		SetName(name);
		SetAdress(adress);
		SetCity(city);
		budget = 0;
	}

	Restaurant(const string& name, const string& adress, const string& city, vector<Admin> admins):Restaurant(name,adress,city) {
		SetAdmins(admins);
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