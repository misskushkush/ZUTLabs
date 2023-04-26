#include "Customer.h"
#include <time.h>
#include <iostream>


void create_array(Customer**& passengers, const size_t size) {
	passengers = new Customer * [size];
	for (size_t i = 0; i < size; i++)
		passengers[i] = new Customer;
}

void initialize_array(Customer* const* const passengers, const size_t size) {
	srand(time(nullptr));
	string Names[10] = { "Cade", "Caden", "Cadon", "Cadyn", "Caedan", "Caedyn", "Cael", "Caelan", "Caelen", "Caethan" };
	string Surnames[10] = { "David-Jay", "David-Lee", "Davie", "Davis", "Davy", "Dawid", "Dawson", "Dawud", "Dayem", "Daymian" };

	for (size_t i = 0; i < size; i++) {
		int rand_index = rand() % 9 + 0;
		passengers[i]->Name = Names[rand_index];
		passengers[i]->Surname = Surnames[rand_index];
	}
}

void print_array_elements(Customer** passengers, const size_t size) {
	cout << "\n Name | Surname " << endl;
	for (size_t i = 0; i < size; i++) {
		cout << passengers[i]->Name <<"|" << passengers[i]->Surname<< endl;
	}
}

void add_array_element(Customer**& passengers, size_t& size) {
	Customer** temp = new Customer * [size + 1];
	for (size_t i = 0; i < size; ++i)
			temp[i] = passengers[i];

	srand(time(nullptr));
	string Names[10] = { "Cade", "Caden", "Cadon", "Cadyn", "Caedan", "Caedyn", "Cael", "Caelan", "Caelen", "Caethan" };
	string Surnames[10] = { "David-Jay", "David-Lee", "Davie", "Davis", "Davy", "Dawid", "Dawson", "Dawud", "Dayem", "Daymian" };
    int rand_index = rand() % 9 + 0;
	temp[size] = new Customer;
	temp[size]->Name = Names[rand_index];
    temp[size]->Surname = Surnames[rand_index];
	
		
	delete[] passengers;
	passengers = temp;
	++size;
}

void delete_array_element(Customer**& passengers, size_t& size, size_t index) {
	
	
	if (index >= 0 && index < size) {
		// Create a new array with one fewer element
		Customer** temp = new Customer * [size - 1];

		// Copy the existing elements to the new array, skipping the one to be deleted
		size_t j = 0;
		for (size_t i = 0; i < size; i++) {
			if (i != index) {
				temp[j] = passengers[i];
				j++;
			}
		}

		// Delete the old array and replace it with the new one
		delete[] passengers;
		passengers = temp;
		size--;
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void edit_customer(Customer** passenger, const size_t size, size_t index) {
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
