#include <string>
using namespace std;

struct Ticket
{
	size_t hour;
	size_t minute;
	float price;
	string DepartCity;
	string ArriveCity;
};
void sort_tickets_by_time(Ticket* const ticket, const size_t size);

void initialize_ticket(Ticket& ticket);

void create_array(Ticket*& ticket, const size_t size);

void initialize_array(Ticket* const ticket, const size_t size);

void print_array_elements(Ticket* ticket, const size_t size);

void add_array_element(Ticket*& tickets, size_t& size);

void delete_array_element(Ticket*& tickets, size_t& size, size_t index);