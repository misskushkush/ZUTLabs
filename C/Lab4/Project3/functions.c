#include<stdio.h>
#include<string.h>
#include "Ticket.h"

void Init_Ticket(char name[STRINGBUFFER], Ticket* ticket)
{
	strcpy(ticket->name, name);
	Init_Depart_Date(&ticket->date);
	Init_Depart_Time(&ticket->time);
}

void Init_Depart_Time(depart_time* time)
{
	time->hour = rand() % 23 + 0;
	time->minute = rand() % 59 + 0;
}

void Init_Depart_Date(depart_date* date)
{
	date->day = rand() % 30 + 1;
	date->month = rand() % 12 + 1;
	date->year = 2023;
}

void display(char name[STRINGBUFFER], Ticket list[TICKET], int s)
{
	int i;

	for (i = 0; i < s; i++)
	{
		printf("Name %s\n", name);
		printf("Date %d-%d-%d\nTime %d:%d\n", list[i].date.day, list[i].date.month, list[i].date.year, list[i].time.hour, list[i].time.minute);
	}
}

void bsortDesc(Ticket list[TICKET], int s)
{
	int i, j;
	Ticket temp;

	for (i = 0; i < s - 1; i++)
	{
		for (j = 0; j < (s - 1 - i); j++)
		{
			if (list[j].date.month > list[j + 1].date.month)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			if (list[j].date.month == list[j + 1].date.month && list[j].date.day > list[j + 1].date.day)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			if (list[j].date.month == list[j + 1].date.month && list[j].date.day == list[j + 1].date.day && list[j].time.hour > list[j + 1].time.hour)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			if (list[j].date.month == list[j + 1].date.month && list[j].date.day == list[j + 1].date.day && list[j].time.hour == list[j + 1].time.hour && list[j].time.minute > list[j + 1].time.minute)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void Init_TicketList(int quant, char name[STRINGBUFFER], Ticket tickets[TICKET])
{
	for (int i = 0; i < quant; i++)
	{
		Init_Ticket(name, &tickets[i]);
	}
}

void TicketWork(Ticket list[TICKET], int n)
{
	char name[STRINGBUFFER];
	puts("Enter name of a traveller\n");
	scanf("%s", name);
	Init_TicketList(n, name, list);
	printf("\nBefore sorting\n");
	display(name, list, n);
	bsortDesc(list, n);
	printf("\nAfter sorting\n");
	display(name, list, n);
}
