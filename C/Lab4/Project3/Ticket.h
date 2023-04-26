#include "DateTime.h"
#define STRINGBUFFER 100
#define TICKET 10
typedef struct
{
	char name[STRINGBUFFER];
	depart_date date;
	depart_time time;

}Ticket;

void Init_Ticket(char[STRINGBUFFER], Ticket*);

void display(char name[STRINGBUFFER], Ticket list[TICKET], int s);

void bsortDesc(Ticket list[TICKET], int s);

void Init_TicketList(int, char[STRINGBUFFER], Ticket[TICKET]);

void TicketWork(Ticket[TICKET], int);