#include "Ticket.h"
#include <time.h>
#include <iostream>
#include <iomanip>


void sort_tickets_by_time(Ticket* const ticket, const size_t size) {
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

void initialize_ticket(Ticket& ticket) {
	srand(time(nullptr));
	string ArriveCities[10] = { "Kalisz", "Legnica", "Grudziądz", "Jaworzno", "Słupsk", "Jastrzębie", "Nowy Sącz", "Jelenia Góra", "Siedlce", "Mysłowice" };
	string DepartCities[10] = { "Konin", "Piła", "Piotrków", "Trybunalski", "Inowrocław", "Lubin", "Ostrów Wielkopolski", "Suwałki", "Stargard", "Gniezno" };
	int randcity_index = rand() % 9 + 0;
		ticket.hour = rand() % 24 + 0;
		ticket.minute = rand() % 60 + 0;
		ticket.price = rand() % 200 + 20;
		ticket.DepartCity = DepartCities[randcity_index];
		ticket.ArriveCity = ArriveCities[randcity_index];
	
}
void create_array(Ticket*& ticket, const size_t size) {
	ticket = new Ticket[size];
}

void initialize_array(Ticket* const ticket, const size_t size) {
	srand(time(nullptr));
	string ArriveCities[10] = { "Kalisz", "Legnica", "Grudziądz", "Jaworzno", "Słupsk", "Jastrzębie", "Nowy Sącz", "Jelenia Góra", "Siedlce", "Mysłowice" };
	string DepartCities[10] = { "Konin", "Piła", "Piotrków", "Trybunalski", "Inowrocław", "Lubin", "Ostrów Wielkopolski", "Suwałki", "Stargard", "Gniezno" };

	for (size_t i = 0; i < size; i++) {
		int randcity_index = rand() % 9 + 0;
		ticket[i].hour = rand() % 24 + 0;
		ticket[i].minute = rand() % 60 + 0;
		ticket[i].price = rand() % 200 + 20;
		ticket[i].DepartCity = DepartCities[randcity_index];
		ticket[i].ArriveCity = ArriveCities[randcity_index];
	}
}

void print_array_elements(Ticket* ticket, const size_t size) {
	cout << "\n Hour | Minute | Price | Departure City | City of Arrival" << endl;
	for (size_t i = 0; i < size; i++) {
	     cout << ticket[i].hour<< "   " << "|" << ticket[i].minute << "      " << "|" 
			 << ticket[i].price << "    " << "|" << ticket[i].DepartCity << "   " << "|" 
			 << ticket[i].ArriveCity << "   " << "|" << endl;
	}
}

void add_array_element(Ticket*& tickets, size_t& size) {
	Ticket* temp = new Ticket[size + 1];
	
	for (size_t i = 0; i < size; ++i)
			temp[i] = tickets[i];

	initialize_ticket(temp[size]);

    delete[] tickets;
	tickets = temp;
	size++;
}


void delete_array_element(Ticket*& tickets, size_t& size, size_t index) {
	
	if (index >= 0 && index < size) {
		// Create a new array with one fewer element
		Ticket* temp = new Ticket[size - 1];

		// Copy the existing elements to the new array, skipping the one to be deleted
		size_t j = 0;
		for (size_t i = 0; i < size; i++) {
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