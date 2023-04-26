typedef struct
{
	int day, month, year;
}depart_date;

typedef struct
{
	int hour, minute;
}depart_time;

void Init_Depart_Time(depart_time*);

void Init_Depart_Date(depart_date*);