#include <string>
using namespace std;

struct Customer
{
	string Name;
	string Surname;
};
void create_array(Customer**& passengers, const size_t size);

void initialize_array(Customer* const* const passengers, const size_t size);

void print_array_elements(Customer** passengers, const size_t size);

void add_array_element(Customer**& passengers, size_t& size);

void delete_array_element(Customer**& passengers, size_t& size, size_t index);

void edit_customer(Customer** passenger, const size_t size, size_t index);
