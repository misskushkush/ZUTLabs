#include "Customer.h"
#include <iostream>
#include <random>
#include <ctype.h>


void create_array(Customer**& passengers, const int size) {
	passengers = new Customer * [size];
	for (int i = 0; i < size; i++)
		passengers[i] = new Customer;
}

void initialize_array(Customer* const* const trains, const int size) {
	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> nameDist(0, 9);

	string Names[10] = { "Cade", "Caden", "Cadon", "Cadyn", "Caedan", "Caedyn", "Cael", "Caelan", "Caelen", "Caethan" };
	string Surnames[10] = { "David-Jay", "David-Lee", "Davie", "Davis", "Davy", "Dawid", "Dawson", "Dawud", "Dayem", "Daymian" };

	for (int i = 0; i < size; i++) {
		int rand_index = nameDist(dfe);
		trains[i]->Name = Names[rand_index];
		trains[i]->Surname = Surnames[rand_index];
	}
}

void print_array_elements(Customer** trains, const int size) {
	cout << "\n Name | Surname " << endl;
	for (int i = 0; i < size; i++) {
		cout << trains[i]->Name <<"|" << trains[i]->Surname<< endl;
	}
}

void add_array_element(Customer**& trains, int& size) {
	Customer** temp = new Customer * [size + 1];
	for (int i = 0; i < size; ++i)
			temp[i] = trains[i];

	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> nameDist(0, 9);

	string Names[10] = { "Cade", "Caden", "Cadon", "Cadyn", "Caedan", "Caedyn", "Cael", "Caelan", "Caelen", "Caethan" };
	string Surnames[10] = { "David-Jay", "David-Lee", "Davie", "Davis", "Davy", "Dawid", "Dawson", "Dawud", "Dayem", "Daymian" };
    int rand_index = nameDist(dfe);
	temp[size] = new Customer;
	temp[size]->Name = Names[rand_index];
    temp[size]->Surname = Surnames[rand_index];
	
		
	delete[] trains;
	trains = temp;
	++size;
}

void delete_array_element(Customer**& trains, int& size, int index) {
	
	
	if (index >= 0 && index < size) {
		// Create a new array with one fewer element
		Customer** temp = new Customer * [size - 1];

		// Copy the existing elements to the new array, skipping the one to be deleted
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				temp[j] = trains[i];
				j++;
			}
		}

		// Delete the old array and replace it with the new one
		delete[] trains;
		trains = temp;
		size--;
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void edit_customer(Customer** passenger, const int size, int index) {
	if (index >= 0 && index < size) {
		cout << "Enter the new name for person " << index << ": ";
		cin >> passenger[index]->Name;
		cout << "Enter the new surname for person " << index << ": ";
		cin >> passenger[index]->Surname;
	}
	else {
		cout << "Invalid index." << endl;
	}
}
