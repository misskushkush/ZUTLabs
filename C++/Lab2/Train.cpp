#include "Ticket.h"
#include <ctype.h>
#include <iostream>
#include <random>
using namespace std;

void create_Train(Train**& trains, const int size) {
	// Allocate memory for the Train object
	trains = new Train*[size];

	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> number (100000, 500000);
	static uniform_int_distribution<int> num_tickets(1, 3);

	for (int i = 0; i < size; i++)
	{	trains[i] = new Train;
	trains[i]->number = to_string(number(dfe));
	trains[i]->num_tickets = num_tickets(dfe);
	trains[i]->tickets = new Ticket * [trains[i]->num_tickets];
		for (int j = 0; j < trains[i]->num_tickets; j++) 
		{
			trains[i]->tickets[j] = new Ticket;
			initialize_ticket(trains[i]->tickets[j]);
		}
	
	}
		
}


void print_Train(Train** trains, const int size) {
	cout << "Train tickets"<<endl;
	for (int i = 0; i < size; i++) {
		cout << trains[i]->number << endl;
		for (int j = 0; j < trains[i]->num_tickets; j++)
		{
		cout << "\n\t"<<trains[i]->tickets[j]->hour << ":" << trains[i]->tickets[j]->minute << "\tZL"
					<< trains[i]->tickets[j]->price << "\t" << trains[i]->tickets[j]->DepartCity << "\t"
					<< trains[i]->tickets[j]->ArriveCity << "\t" << endl;
		}
		
	}
}

void add_Train(Train**& trains, int& size) {
	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> number(100000, 500000);
	static uniform_int_distribution<int> num_tickets(1, 5);

	Train** temp = new Train * [size + 1];
	for (int i = 0; i < size; ++i)
		temp[i] = trains[i];


	temp[size] = new Train;
	temp[size]->number = to_string(number(dfe));
	temp[size]->num_tickets = num_tickets(dfe);
	temp[size]->tickets = new Ticket * [temp[size]->num_tickets];
	for (int j = 0; j < temp[size]->num_tickets; j++)
	{
		temp[size]->tickets[j] = new Ticket;
		initialize_ticket(temp[size]->tickets[j]);
	}

	delete[] trains;
	trains = temp;
	++size;
}

void delete_Train(Train**& trains, int& size, int index) {

	if (index >= 0 && index < size) {
		--index;
		// Create a new array with one fewer element
		Train** temp = new Train * [size - 1];

		// Copy the existing elements to the new array, skipping the one to be deleted
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				temp[j] = trains[i];
				j++;
			}
		}

		// Delete the old array and replace it with the new one
		delete trains[index];
		delete[] trains;
		trains = temp;
		size--;
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void edit_Train(Train** trains, const int size, int index_train, int index_ticket) {
	if (index_train >= 0 && index_train < size) {
		if (index_ticket >= 0 && index_ticket < trains[index_train]->num_tickets)
		{
			cin.ignore();
			cout << "Enter data"<<endl;
			cin.ignore();
			string line;
			getline(cin, line);


			int hour, minute;
			float price;
			char number[10], DepartCity[30], ArriveCity[30];

			// Parse the line and assign values to the variables
			sscanf(line.c_str(), "%s %d:%d %f %s %s",&number, &hour, &minute, &price, &DepartCity, &ArriveCity);
			cout << "A new train number" << endl;
			trains[index_train]->number = number;
			cout << trains[index_train]->number<<endl;

			cout << "The new ticket departure hour: "<<endl;
			trains[index_train]->tickets[index_ticket]->hour = hour;
			cout<< trains[index_train]->tickets[index_ticket]->hour<<endl;

			cout << "The new ticket departure minute: " << endl;
			trains[index_train]->tickets[index_ticket]->minute = minute;
			cout<< trains[index_train]->tickets[index_ticket]->minute<<endl;

			cout << "The new ticket price: " << endl;
			trains[index_train]->tickets[index_ticket]->price = price;
			cout<< trains[index_train]->tickets[index_ticket]->price<<endl;

			cout << "The new ticket Departure City: " << endl;
			trains[index_train]->tickets[index_ticket]->DepartCity = DepartCity;
			cout<< trains[index_train]->tickets[index_ticket]->DepartCity<<endl;

			cout << "The new ticket City of Arrival: " << endl;
			trains[index_train]->tickets[index_ticket]->ArriveCity = ArriveCity;
			cout<< trains[index_train]->tickets[index_ticket]->ArriveCity<<endl;
			
			
		}
		else {
			cout << "Invalid index." << endl;
		}
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void find_Train(Train** trains, const int size)
{
	int cyfr{};
	cout << "Enter a number" << endl;
	cin >> cyfr;
	string find = to_string(cyfr);
	for (int i = 0; i < size; i++)
	{
		if (!trains[i]->number.find_first_of(find)) 
		{
			cout << trains[i]->number << endl;
				for (int j = 0; j < trains[i]->num_tickets; j++)
				{
					cout << trains[i]->tickets[j]->hour << ":" << trains[i]->tickets[j]->minute << "\tZL"
						<< trains[i]->tickets[j]->price << "\t" << trains[i]->tickets[j]->DepartCity << "\t"
						<< trains[i]->tickets[j]->ArriveCity << "\t" << endl;
				}

			
		};
	}
}