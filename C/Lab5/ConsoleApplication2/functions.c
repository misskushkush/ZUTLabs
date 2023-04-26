#include<stdio.h>
#include<string.h>
#include<time.h>
#include<string.h> 
#include "Ticket.h"

#define number 4

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

	int arr[5] = { list[i].date.day, list[i].date.month, list[i].date.year, list[i].time.hour, list[i].time.minute };
	
	//SaveTicket(arr);
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
	SaveName(name);
}

void SaveName(char string[STRINGBUFFER])
{
	char* filename = "name.txt";
	FILE* fp = fopen(filename, "a");
	if (!fp)
	{
		printf("Error occured while opening file\n");
		return 1;
	}
	// записываем строку
	fputs(string, fp);
	fputs("\n", fp);
	fclose(fp);
	printf("File has been written\n");
}


void AllDataOpen()
{
	srand(time(NULL));
	struct Data data;
	char* filenameImion = "name.txt";
	data.namePtr = Get_Names(filenameImion, &data.name_size);
	//int number = rand()%5 + 1;
	struct Person pasangers[number];
	for (int i = 0; i < number; i++)
	Make_File_Data(&pasangers[i], &data);
	Show_File_Data(pasangers, number);
	Write_File_Data(pasangers, number);
}

//void SaveTicket(int arr[5])
//{
//	char* filename = "ticket.txt";
//	FILE* fp = fopen(filename, "wb");
//	if (!fp)
//	{
//		printf("Error occured while opening file\n");
//		return 1;
//	}
//	// записываем строку
//	
//	fwrite(arr, sizeof(int), 5, fp);
//	fputs("\n", fp);
//	fclose(fp);
//	printf("File has been written\n");
//}

size_t Get_Lines(char* filename) {
	FILE* filePointer = NULL;
	filePointer = fopen(filename, "r");
	size_t count_lines = 0;
	if (filePointer != NULL)
	{
		char dataToBeRead[STRINGBUFFER];
		while (fgets(dataToBeRead, STRINGBUFFER, filePointer) != NULL) {
			++count_lines;
		}
	}
	fclose(filePointer);
	return count_lines;
}

void Create_Names(struct Name*** names, size_t count_lines) {
	struct Name** temp = (struct Name**)malloc(count_lines * sizeof(struct Name*));
	for (size_t i = 0; i < count_lines; i++)
		temp[i] = (struct Name*)malloc(sizeof(struct Name));
	*names = temp;
}

struct Name** Get_Names(char* filename, int* size) {
	size_t count_lines = Get_Lines(filename);
	*size = count_lines;
	struct Name** names = NULL;
	if (count_lines > 0) {
		Create_Names(&names, count_lines);
		FILE* filePointer;
		filePointer = fopen(filename, "r");
		size_t i = 0;
		char dataToBeRead[STRINGBUFFER];
		while (fgets(dataToBeRead, STRINGBUFFER, filePointer) != NULL)
		{
			dataToBeRead[strlen(dataToBeRead) - 1] = '\0';
			names[i]->name = (char*)malloc((strlen(dataToBeRead) + 1) * sizeof(char));
			strcpy(names[i]->name, dataToBeRead);
			++i;
		}
		fclose(filePointer);
	}
	else
	{
		puts("Problem z wczytywaniem Imion");
		exit(1);
	}
	return names;
}

void Make_File_Data(struct Person* p, struct Data* data) {
	int ind = rand() % data->name_size + 1;
	--ind;
	strcpy(p->RandName, data->namePtr[ind]->name);
}
void Show_File_Data(struct Person* p, int size) {
	for (int i = 0; i < size; i++)
		puts(p[i].RandName);
}
void Write_File_Data(struct Person* p, int sz) {
	FILE* filePointer;
	filePointer = fopen("pasengers.txt", "w");
	for (int i = 0; i < sz; i++)
		fprintf(filePointer, "%d %s \n", i, p[i].RandName);
	fclose(filePointer);
}
