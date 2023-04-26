#include <string>
#include <ctype.h>
using namespace std;

struct Customer
{
	string Name;
	string Surname;
};
void create_array(Customer**& passengers, const int size);

void initialize_array(Customer* const* const passengers, const int size);

void print_array_elements(Customer** passengers, const int size);

void add_array_element(Customer**& passengers, int& size);

void delete_array_element(Customer**& passengers, int& size, int index);

void edit_customer(Customer** passenger, const int size, int index);
