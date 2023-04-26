﻿#include "Ticket.h"
#include <iostream>
#include <iomanip>
#include <random>


void sort_tickets_by_time(Ticket* const ticket, const int size) {
	int i, j;
	Ticket* temp = new Ticket[size];

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
		{
			if (ticket[j].hour > ticket[j + 1].hour)
			{
				*temp = ticket[j];
				ticket[j] = ticket[j + 1];
				ticket[j + 1] = *temp;
			}
			if (ticket[j].hour == ticket[j + 1].hour && ticket[j].minute > ticket[j + 1].minute)
			{
				*temp = ticket[j];
				ticket[j] = ticket[j + 1];
				ticket[j + 1] = *temp;
			}
		}
	}
}

void initialize_ticket(Ticket* ticket) {
	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> cityDist(0, 9);
	static uniform_int_distribution<int> hourDist(0, 23);
	static uniform_int_distribution<int> minuteDist(0, 59);
	static uniform_int_distribution<int> priceDist(100, 500);

	string ArriveCities[10] = { "Kalisz", "Legnica", "Grudziądz", "Jaworzno", "Słupsk", "Jastrzębie", "Nowy Sącz", "Jelenia Góra", "Siedlce", "Mysłowice" };
	string DepartCities[10] = { "Konin", "Piła", "Piotrków", "Trybunalski", "Inowrocław", "Lubin", "Ostrów Wielkopolski", "Suwałki", "Stargard", "Gniezno" };
	int randcity_index = cityDist(dfe);
	ticket->hour = hourDist(dfe);
	ticket->minute = minuteDist(dfe);
	ticket->price = priceDist(dfe);
	ticket->DepartCity = DepartCities[randcity_index];
	ticket->ArriveCity = ArriveCities[randcity_index];
	
}

void create_array(Ticket*& ticket, const int size) {
	ticket = new Ticket[size];
}

void initialize_array(Ticket* const ticket, const int size) {
	
	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> cityDist(0, 9);
	static uniform_int_distribution<int> hourDist(0, 23);
	static uniform_int_distribution<int> minuteDist(0, 59);
	static uniform_int_distribution<int> priceDist(100, 500);

	string ArriveCities[10] = { "Kalisz", "Legnica", "Grudziądz", "Jaworzno", "Słupsk", "Jastrzębie", "Nowy Sącz", "Jelenia Góra", "Siedlce", "Mysłowice" };
	string DepartCities[10] = { "Konin", "Piła", "Piotrków", "Trybunalski", "Inowrocław", "Lubin", "Wielkopolski", "Suwałki", "Stargard", "Gniezno" };

	for (int i = 0; i < size; i++) {
		int randcity_index = cityDist(dfe);
		ticket[i].hour = hourDist(dfe);
		ticket[i].minute = minuteDist(dfe);
		ticket[i].price = priceDist(dfe);
		ticket[i].DepartCity = DepartCities[randcity_index];
		ticket[i].ArriveCity = ArriveCities[randcity_index];
	}
}

void print_array_elements(Ticket* ticket, const int size) {
	cout << "\n Hour | Minute | Price | Departure City | City of Arrival" << endl;
	for (int i = 0; i < size; i++) {
	     cout << ticket[i].hour<< "   " << "|" << ticket[i].minute << "      " << "|" 
			 << ticket[i].price << "    " << "|" << ticket[i].DepartCity << "   " << "|" 
			 << ticket[i].ArriveCity << "   " << "|" << endl;
	}
}

void add_array_element(Ticket*& tickets, int& size) {
	Ticket* temp = new Ticket[size + 1];
	
	for (int i = 0; i < size; ++i)
			temp[i] = tickets[i];

	initialize_ticket(&temp[size]);

    delete[] tickets;
	tickets = temp;
	size++;
}


void delete_array_element(Ticket*& tickets, int& size, int index) {
	
	if (index >= 0 && index < size) {
		// Create a new array with one fewer element
		Ticket* temp = new Ticket[size - 1];

		// Copy the existing elements to the new array, skipping the one to be deleted
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				temp[j] = tickets[i];
				j++;
			}
		}

		// Delete the old array and replace it with the new one
		delete[] tickets;
		tickets = temp;
		size--;
	}
	else {
		cout << "Invalid index." << endl;
	}
}