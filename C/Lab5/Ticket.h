#include "DateTime.h"
#define STRINGBUFFER 100
#define TICKET 10
typedef struct
{
	char name[STRINGBUFFER];
	depart_date date;
	depart_time time;

}Ticket;

struct Name {
	size_t len;
	char* name;
};
struct Data {
	int name_size;
	struct Name** namePtr;
};

struct Person {
	char RandName[STRINGBUFFER];
};


void Init_Ticket(char[STRINGBUFFER], Ticket*);

void display(char[STRINGBUFFER], Ticket[TICKET], int);

void bsortDesc(Ticket[TICKET], int);

void Init_TicketList(int, char[STRINGBUFFER], Ticket[TICKET]);

void TicketWork(Ticket[TICKET], int);

void SaveName(char[STRINGBUFFER]);

void AllDataOpen();

struct Name** Get_Names(char*, int*);

size_t Get_Lines(char*);

void Create_Names(struct Name***, size_t);

void Make_File_Data(struct Person*, struct Data*);

void Show_File_Data(struct Person*, int);

void Write_File_Data(struct Person*, int);

//void SaveTicket(int arr[5]);