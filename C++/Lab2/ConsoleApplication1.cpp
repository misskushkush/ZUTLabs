#include <iostream>
#include <ctype.h>
#include "Customer.h"
#include "Ticket.h"
#include <random>
using namespace std;

void gen_data(int& num) {
	
	static random_device rd;
	static default_random_engine dfe(rd());
	static uniform_int_distribution<int> rozmiar(1, 3);
	num = rozmiar(dfe);
}

void exit(Train**& trains, int& size, Customer**& customer)
{
	delete customer;
	customer = nullptr;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < trains[i]->num_tickets; j++)
		{
			delete trains[i]->tickets[j];
		}
		delete[] trains[i]->tickets;
		delete trains[i];
	}
	delete[] trains;
	trains = nullptr;
	size = 0;
}

int main()
{
	string line;
	
	int choice, index;
	int size;
	gen_data(size);
	Train** trains{ nullptr };
	Customer** passengers{ nullptr };

	cout << "\n1 - Create Train System\n";
	cout << "2 - Show Train details\n";
	cout << "3 - Add Train\n";
	cout << "4 - Remove Train\n";
	cout << "5 -  Edit Train \n";
	cout << "6 -  Find Train number\n";
	cout << "-------------------------\n";
	cout << "7 -  Create a Passenger System\n";
	cout << "8 -  Fill Passenger System with passengers\n";
	cout << "9 -  Show passenger details\n";
	cout << "10 -  Add passenger\n";
	cout << "11 - Delete passenger\n";
	cout << "12 - Edit passenger details\n";
	cout << "-------------------------\n";
	cout << "13 -  Exit\n" << endl;

	while (true) {

		cout << "\nSelect: " << endl;
		cin>>choice;

		switch (choice) {
		case 1:
			create_Train(trains, size);
			break;
		case 2:
			print_Train(trains, size);
			break;
		case 3:
			add_Train(trains, size);
			break;
		case 4:
			cout << "Enter index to delete";
			cin >> index;
			delete_Train(trains, size, index);
			break;
		case 5:
			int index_ticket;
			cout << "Enter index of train to edit";
			cin >> index;
			cout << "Enter index of ticket to edit";
			cin >> index_ticket;
			edit_Train(trains, size, index, index_ticket);
			break;
		case 6:
			find_Train(trains, size);
			break;
		case 7:
			create_array(passengers, size);
			break;
		case 8:
			initialize_array(passengers, size);
			break;
		case 9:
			print_array_elements(passengers, size);
			break;
		case 10:
			add_array_element(passengers, size);
			break;
		case 11:
			cout << "Enter index of passenger";
			cin >> index;
			delete_array_element(passengers, size, index);
			break;
		case 12:
			cout << "Enter index of passenger";
			cin >> index;
			edit_customer(passengers, size, index);
			break;
		case 13:
			cout << "Finishing program" << endl;
			
			return 0;
		default:
			break;

			if (passengers == nullptr)
				cout << "Passenger System is empty!" << endl;
			else if (trains == nullptr)
				cout << "Ticket System is empty!" << endl;
		}
	}
	return 0;
}

