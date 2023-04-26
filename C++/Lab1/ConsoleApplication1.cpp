#include <iostream>
#include "Customer.h"
#include "Ticket.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	size_t choice, index;
	size_t size = rand() % 15 + 1;
	Ticket* tickets{ nullptr };
	Customer** passengers{ nullptr };

	cout << "\n1 - Create Ticket System\n";
	cout << "2 - Fill Ticket System with tickets\n";
	cout << "3 - Show ticket details\n";
	cout << "4 - Add ticket\n";
	cout << "5 - Remove ticket\n";
	cout << "-------------------------\n";
	cout << "6 -  Create a Passenger System\n";
	cout << "7 -  Fill Passenger System with passengers\n";
	cout << "8 -  Show passenger details\n";
	cout << "9 -  Add passenger\n";
	cout << "10 - Delete passenger\n";
	cout << "11 - Edit passenger details\n";
	cout << "-------------------------\n";
	cout << "12 -  Sort tickets by time\n";
	cout << "13 -  Exit\n" << endl;

	while (true) {

		cout << "\nSelect: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			create_array(tickets, size);
			break;
		case 2:
			initialize_array(tickets, size);
			break;
		case 3:
			print_array_elements(tickets, size);
			break;
		case 4:
			add_array_element(tickets, size);
			break;
		case 5:
			cout << "Enter index of ticket";
			cin >> index;
			delete_array_element(tickets, size, index);
			break;
		case 6:
			create_array(passengers, size);
			break;
		case 7:
			initialize_array(passengers, size);
			break;
		case 8:
			print_array_elements(passengers, size);
			break;
		case 9:
			add_array_element(passengers, size);
			break;
		case 10:
			cout << "Enter index of passenger";
			cin >> index;
			delete_array_element(passengers, size, index);
			break;
		case 11:
			cout << "Enter index of passenger";
			cin >> index;
			edit_customer(passengers, size, index);
			break;
		case 12:
			sort_tickets_by_time(tickets, size);
			break;
		case 13:
			cout << "Finishing program" << endl;
			delete tickets;
			delete passengers;
			tickets = NULL;
			passengers = NULL;
			return 0;
		default:
			break;

			if (passengers == nullptr)
				cout << "Passenger System is empty!" << endl;
			else if (tickets == nullptr)
				cout << "Ticket System is empty!" << endl;
		}
	}
	return 0;
}

