#include <string>
#include <ctype.h>
using namespace std;

struct Ticket
{
	int hour;
	int minute;
	float price;
	string DepartCity;
	string ArriveCity;
};

void sort_tickets_by_time(Ticket* const ticket, const int size);

void initialize_ticket(Ticket* ticket);

void create_array(Ticket*& ticket, const int size);

void initialize_array(Ticket* const ticket, const int size);

void print_array_elements(Ticket* ticket, const int size);

void add_array_element(Ticket*& tickets, int& size);

void delete_array_element(Ticket*& tickets, int& size, int index);

struct Train
{
	Ticket** tickets;
	string number;
	int num_tickets;
};

void create_Train(Train**& trains, const int size);

void print_Train(Train** trains, const int size);

void add_Train(Train**& trains, int& size);

void delete_Train(Train**& trains, int& size, int index);

void edit_Train(Train** trains, const int size, int index_train, int index_tickets);

void find_Train(Train** trains, const int size);