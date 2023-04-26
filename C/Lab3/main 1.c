#include <stdio.h>
#define TICKET 10
#define row 5
#define col 6

struct depart_time
{
    int hour, minute;
};


void accept(struct depart_time list[TICKET], int s);

void display(struct depart_time list[TICKET], int s);

void bsortDesc(struct depart_time list[TICKET], int s);

int ChoiceDay();

void TimeWork(struct depart_time list[TICKET], int n);

float Discount(int n, int distance, int discount);

void MakeSchedule(int schedule[row][col], int days[row], int tickets_war[row], int tickets_wroc[row], int tickets_poz[row], int tickets_krak[row], int tickets_gdan[row]);
void ShowScedule(int schedule[row][col]);


int main()
{


	int choice, choice1, disc_odd = 5, disc_even = 10;
	float money = 0;
	float distance;
	float total = 0;

	struct depart_time data11[TICKET], data12[TICKET], data13[TICKET], data14[TICKET], data15[TICKET];
	struct depart_time data21[TICKET], data22[TICKET], data23[TICKET], data24[TICKET], data25[TICKET];
	struct depart_time data31[TICKET], data32[TICKET], data33[TICKET], data34[TICKET], data35[TICKET];
	struct depart_time data41[TICKET], data42[TICKET], data43[TICKET], data44[TICKET], data45[TICKET];
	struct depart_time data51[TICKET], data52[TICKET], data53[TICKET], data54[TICKET], data55[TICKET];
	int n11=0, n12 = 0, n13 = 0, n14 = 0, n15 = 0,
		n21 = 0, n22 = 0, n23 = 0, n24 = 0, n25 = 0,
		n31 = 0, n32 = 0, n33 = 0, n34 = 0, n35 = 0,
		n41 = 0, n42 = 0, n43 = 0, n44 = 0, n45 = 0,
		n51 = 0, n52 = 0, n53 = 0, n54 = 0, n55 = 0;

	system("cls");
	puts("===================================PKP===================================\n");
	puts("Choose your destination point from Szczecin\n");
	do
	{
		puts("1. Warsaw");
		puts("2. Wroclaw");
		puts("3. Poznan");
		puts("4. Krakow");
		puts("5. Gdansk");
		puts("0. Exit");

		scanf("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");
			do
			{
				system("cls");
				distance = 566;// this is a distance in km
				choice1 = ChoiceDay();

				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n11);

					TimeWork(data11, n11);

					money = Discount(n11, distance, disc_odd);

					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n13);

					TimeWork(data13, n13);

					money = Discount(n13, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n15);

					TimeWork(data15, n15);

					money = Discount(n15, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n12);

					TimeWork(data12, n12);

					money = Discount(n12, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n14);

					TimeWork(data14, n14);

					money = Discount(n14, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				default:
					printf("Incorrect data. Enter again!\n");
					break;
				}
			} while (choice1 != 0);
			break;
		case 2:
			system("cls");
			do
			{
				system("cls");
				distance = 393.7;
				printf("To WROCLAW %.2f", distance); puts(" km\n");
				choice1 = ChoiceDay();


				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n21);

					TimeWork(data21, n21);

					money = Discount(n21, distance, disc_odd);
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n23);

					TimeWork(data23, n23);

					money = Discount(n23, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n25);

					TimeWork(data25, n25);

					money = Discount(n25, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n22);

					TimeWork(data22, n22);

					money = Discount(n22, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n24);

					TimeWork(data24, n24);

					money = Discount(n24, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				default:
					printf("Incorrect data. Enter again!\n");
					break;
				}
			} while (choice1 != 0);
			break;
		case 3:
			system("cls");
			do
			{
				system("cls");
				distance = 265.1;
				printf("To POZNAN %.2f", distance); puts(" km\n");
				choice1 = ChoiceDay();


				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n31);

					TimeWork(data31, n31);

					money = Discount(n31, distance, disc_odd);
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n33);

					TimeWork(data33, n33);

					money = Discount(n33, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n35);

					TimeWork(data35, n35);

					money = Discount(n35, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n32);

					TimeWork(data32, n32);

					money = Discount(n32, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n34);

					TimeWork(data34, n34);

					money = Discount(n34, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				default:
					printf("Incorrect data. Enter again!\n");
					break;
				}
			} while (choice1 != 0);
			break;
		case 4:
			system("cls");
			do
			{
				system("cls");
				distance = 647.3;
				printf("To KRAKOW %.2f", distance); puts(" km\n");
				choice1 = ChoiceDay();


				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n41);

					TimeWork(data41, n41);

					money = Discount(n41, distance, disc_odd);
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n43);

					TimeWork(data43, n43);

					money = Discount(n43, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n45);

					TimeWork(data45, n45);

					money = Discount(n45, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n42);

					TimeWork(data42, n42);

					money = Discount(n42, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n44);

					TimeWork(data44, n44);

					money = Discount(n44, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				default:
					printf("Incorrect data. Enter again!\n");
					break;
				}
			} while (choice1 != 0);
			break;
		case 5:
			system("cls");
			do
			{
				system("cls");
				distance = 358.9;
				printf("To GDANSK %.2f", distance); puts(" km\n");
				choice1 = ChoiceDay();


				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n51);

					TimeWork(data51, n51);

					money = Discount(n51, distance, disc_odd);
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n53);

					TimeWork(data53, n53);

					money = Discount(n53, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n55);

					TimeWork(data55, n55);

					money = Discount(n55, distance, disc_odd);
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n52);

					TimeWork(data52, n52);

					money = Discount(n52, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n54);

					TimeWork(data54, n54);

					money = Discount(n54, distance, disc_even);
					total += money;
					Sleep(5000);
					break;
				default:
					printf("Incorrect data. Enter again!\n");
					break;
				}
			} while (choice1 != 0);
			break;
		case 0:
			printf("Thank you for using our service \n");
			break;
		default:
			printf("Incorrect data. Enter again!\n");
			break;
		}
	} while (choice != 0);


	printf("\n");
	printf("Your total is %.2f", total); puts(" zl");

	//funkcja dwowym.

	int tickets_war[] = { n11, n12, n13, n14, n15 };
	int tickets_wroc[] = { n21, n22, n23, n24, n25 };
	int tickets_poz[] = { n31, n32, n33, n34, n35 };
	int tickets_krak[] = { n41, n42, n43, n44, n45 };
	int tickets_gdan[] = { n51, n52, n53, n54, n55 };
	int days[] = { 1, 2, 3, 4, 5 };

	int schedule[row][col];
    MakeSchedule(schedule,days,tickets_war,tickets_wroc,tickets_poz,tickets_krak,tickets_gdan);
    ShowSchedule(schedule);


return 0;
}




void accept(struct depart_time list[TICKET], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Record #%d", i + 1);

        printf("\nEnter hours : ");
        scanf("%d", &list[i].hour);

        printf("Enter minutes : ");
        scanf("%d", &list[i].minute);
    }
}

void display(struct depart_time list[TICKET], int s)
{
    int i;

    printf("\n\nHours\tMinutes\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%d\n", list[i].hour, list[i].minute);
    }
}

void bsortDesc(struct depart_time list[TICKET], int s)
{
    int i, j;
    struct depart_time temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
            if (list[j].hour > list[j + 1].hour)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
            if (list[j].hour == list[j + 1].hour && list[j].minute > list[j + 1].minute)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int ChoiceDay()
{
	int choice1;
	for (int i = 1; i <= 5; i++)
	{
		printf("%d", i);
		if (i == 1) puts(". Monday, discount 5zl\n");
		else if (i == 2) puts(". Tuesday, discount 10zl\n");
		else if (i == 3) puts(". Wednesday, discount 5zl\n");
		else if (i == 4) puts(". Thursday, discount 10zl\n");
		else if (i == 5) puts(". Friday, discount 5zl\n");

	}

	puts("Choose the day of your departure");
	scanf("%d", &choice1);
	return choice1;
}

void TimeWork(struct depart_time list[TICKET], int n)
{
	accept(list, n);
	printf("\nBefore sorting");
	display(list, n);
	bsortDesc(list, n);
	printf("\nAfter sorting");
	display(list, n);
}

float Discount(int n, int distance, int discount)
{
	int age;
	float money = n * distance * 0.15 - discount; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
	printf("\n The current cost of your ticket is %.2f", money); puts("zl\n");
	puts("Enter your age");
	scanf("%d", &age);
	if (age >= 18 && age <= 26) {
		puts("You are a student, discount 50% -> ");
		money = money * 50 / 100;
		printf("\n The current cost of your ticket is %.2f", money); puts("zl\n");
	}
	else if (age >= 60) {
		puts("You are a pensioner, discount 20%");
		money = money * 50 / 100;
		printf("\n The current cost of your ticket is %.2f", money); puts("zl\n");
	}
	else if (age < 18)
	{
		puts("You are a child, discount 10%");
		money = money * 10 / 100;
		printf("\n The current cost of your ticket is %.2f", money); puts("zl\n");
	}
	else { puts("You are an adult. No changes in cost"); }

	return money;
}

void ShowSchedule(int schedule[row][col])
{
    puts("Days          Tickets Quant");
	puts("      Warszawa Wroclaw Poznan Krakow Gdansk");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j)
        {
            if(i==0 && j==0) puts("Mon");
            else if(i==1 && j==0) puts("Tue");
            else if(i==2 && j==0) puts("Wed");
            else if(i==3 && j==0) puts("Thu");
            else if(i==4 && j==0) puts("Fri");
			else printf("\t%d", schedule[i][j]);
        }
        puts("\n");
	}
}

void MakeSchedule(int schedule[row][col], int days[row], int tickets_war[row], int tickets_wroc[row], int tickets_poz[row], int tickets_krak[row], int tickets_gdan[row])
{
    for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 1; j++) {
			schedule[i][j] = days[i];
			schedule[i][j + 1] = tickets_war[i];
			schedule[i][j + 2] = tickets_wroc[i];
			schedule[i][j + 3] = tickets_poz[i];
			schedule[i][j + 4] = tickets_krak[i];
			schedule[i][j + 5] = tickets_gdan[i];
		}
	}
}
