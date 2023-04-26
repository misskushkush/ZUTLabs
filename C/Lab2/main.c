#include <stdio.h>

struct depart_time
{
    int hour, minute;
};


void accept(struct depart_time list[10], int s)
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

void display(struct depart_time list[10], int s)
{
    int i;

    printf("\n\nHours\tMinutes\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%d\n", list[i].hour, list[i].minute);
    }
}

void bsortDesc(struct depart_time list[10], int s)
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


int main()
{


	int choice, choice1;
	float money = 0;
	float distance;
	int age;
	float total = 0;

	struct depart_time data11[10], data12[10], data13[10], data14[10], data15[10];
	struct depart_time data21[10], data22[10], data23[10], data24[10], data25[10];
	struct depart_time data31[10], data32[10], data33[10], data34[10], data35[10];
	struct depart_time data41[10], data42[10], data43[10], data44[10], data45[10];
	struct depart_time data51[10], data52[10], data53[10], data54[10], data55[10];
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
				printf("To WARSAW %.2f", distance); puts(" km\n");
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
				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1: 
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n11);

					accept(data11, n11);
					printf("\nBefore sorting");
					display(data11, n11);
					bsortDesc(data11, n11);
					printf("\nAfter sorting");
					display(data11, n11);

					money = n11 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);

					break;
				case 3: 
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n13);

					accept(data13, n13);
					printf("\nBefore sorting");
					display(data13, n13);
					bsortDesc(data13, n13);
					printf("\nAfter sorting");
					display(data13, n13);

					money = n13 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n15);

					accept(data15, n15);
					printf("\nBefore sorting");
					display(data15, n15);
					bsortDesc(data15, n15);
					printf("\nAfter sorting");
					display(data15, n15);

					money = n15 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
					

				case 2: 
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n12);

					accept(data12, n12);
					printf("\nBefore sorting");
					display(data12, n12);
					bsortDesc(data12, n12);
					printf("\nAfter sorting");
					display(data12, n12);

					money = n12*distance * 0.15 - 10;
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
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n14);

					accept(data14, n14);
					printf("\nBefore sorting");
					display(data14, n14);
					bsortDesc(data14, n14);
					printf("\nAfter sorting");
					display(data14, n14);

					money = n14*distance * 0.15 - 10;
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
				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n21);

					accept(data21, n21);
					printf("\nBefore sorting");
					display(data21, n21);
					bsortDesc(data21, n21);
					printf("\nAfter sorting");
					display(data21, n21);

					money = n21 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n23);

					accept(data23, n23);
					printf("\nBefore sorting");
					display(data23, n23);
					bsortDesc(data23, n23);
					printf("\nAfter sorting");
					display(data23, n23);

					money = n23 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n25);

					accept(data25, n25);
					printf("\nBefore sorting");
					display(data25, n25);
					bsortDesc(data25, n25);
					printf("\nAfter sorting");
					display(data25, n25);

					money = n25 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n22);

					accept(data22, n22);
					printf("\nBefore sorting");
					display(data22, n22);
					bsortDesc(data22, n22);
					printf("\nAfter sorting");
					display(data22, n22);

					money = n22 * distance * 0.15 - 10;
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
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n24);

					accept(data24, n24);
					printf("\nBefore sorting");
					display(data24, n24);
					bsortDesc(data24, n24);
					printf("\nAfter sorting");
					display(data24, n24);

					money = n24 * distance * 0.15 - 10;
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
				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n31);

					accept(data31, n31);
					printf("\nBefore sorting");
					display(data31, n31);
					bsortDesc(data31, n31);
					printf("\nAfter sorting");
					display(data31, n31);

					money = n31 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n33);

					accept(data33, n33);
					printf("\nBefore sorting");
					display(data33, n33);
					bsortDesc(data33, n33);
					printf("\nAfter sorting");
					display(data33, n33);

					money = n33 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n35);

					accept(data35, n35);
					printf("\nBefore sorting");
					display(data35, n35);
					bsortDesc(data35, n35);
					printf("\nAfter sorting");
					display(data35, n35);

					money = n35 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n32);

					accept(data32, n32);
					printf("\nBefore sorting");
					display(data32, n32);
					bsortDesc(data32, n32);
					printf("\nAfter sorting");
					display(data32, n32);

					money = n32 * distance * 0.15 - 10;
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
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n34);

					accept(data34, n34);
					printf("\nBefore sorting");
					display(data34, n34);
					bsortDesc(data34, n34);
					printf("\nAfter sorting");
					display(data34, n34);

					money = n34 * distance * 0.15 - 10;
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
				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n41);

					accept(data41, n41);
					printf("\nBefore sorting");
					display(data41, n41);
					bsortDesc(data41, n41);
					printf("\nAfter sorting");
					display(data41, n41);

					money = n41 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n43);

					accept(data43, n43);
					printf("\nBefore sorting");
					display(data43, n43);
					bsortDesc(data43, n43);
					printf("\nAfter sorting");
					display(data43, n43);

					money = n43 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n45);

					accept(data45, n45);
					printf("\nBefore sorting");
					display(data45, n45);
					bsortDesc(data45, n45);
					printf("\nAfter sorting");
					display(data45, n45);

					money = n45 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n42);

					accept(data42, n42);
					printf("\nBefore sorting");
					display(data42, n42);
					bsortDesc(data42, n42);
					printf("\nAfter sorting");
					display(data42, n42);

					money = n42 * distance * 0.15 - 10;
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
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n44);

					accept(data44, n44);
					printf("\nBefore sorting");
					display(data44, n44);
					bsortDesc(data44, n44);
					printf("\nAfter sorting");
					display(data44, n44);

					money = n44 * distance * 0.15 - 10;
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
				switch (choice1) {
				case 0:
					system("cls");
					break;
				case 1:
					printf("Number of tickets you want to buy on Monday? (maximum 10) : ");
					scanf("%d", &n51);

					accept(data51, n51);
					printf("\nBefore sorting");
					display(data51, n51);
					bsortDesc(data51, n51);
					printf("\nAfter sorting");
					display(data51, n51);

					money = n51 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);

					break;
				case 3:
					printf("Number of tickets you want to buy on Wednesday? (maximum 10) : ");
					scanf("%d", &n53);

					accept(data53, n53);
					printf("\nBefore sorting");
					display(data53, n53);
					bsortDesc(data53, n53);
					printf("\nAfter sorting");
					display(data53, n53);

					money = n53 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;
				case 5:
					printf("Number of tickets you want to buy on Friday? (maximum 10) : ");
					scanf("%d", &n55);

					accept(data55, n55);
					printf("\nBefore sorting");
					display(data55, n55);
					bsortDesc(data55, n55);
					printf("\nAfter sorting");
					display(data55, n55);

					money = n55 * distance * 0.15 - 5; // quantity of tickets * one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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
					total += money;
					Sleep(5000);
					break;


				case 2:
					printf("Number of tickets you want to buy on Tuesday? (maximum 10) : ");
					scanf("%d", &n52);

					accept(data52, n52);
					printf("\nBefore sorting");
					display(data52, n52);
					bsortDesc(data52, n52);
					printf("\nAfter sorting");
					display(data52, n52);

					money = n52 * distance * 0.15 - 10;
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
					total += money;
					Sleep(5000);
					break;
				case 4:
					printf("Number of tickets you want to buy on Thursday? (maximum 10) : ");
					scanf("%d", &n54);

					accept(data54, n54);
					printf("\nBefore sorting");
					display(data54, n54);
					bsortDesc(data54, n54);
					printf("\nAfter sorting");
					display(data54, n54);

					money = n54 * distance * 0.15 - 10;
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


	puts("1. Warsaw");
	puts("2. Wroclaw");
	puts("3. Poznan");
	puts("4. Krakow");
	puts("5. Gdansk");
	puts("0. Exit");

	printf("\n");
	printf("Your total is %.2f", total); puts(" zl");
	

	int tickets_war[] = { n11, n12, n13, n14, n15 };
	int tickets_wroc[] = { n21, n22, n23, n24, n25 };
	int tickets_poz[] = { n31, n32, n33, n34, n35 };
	int tickets_krak[] = { n41, n42, n43, n44, n45 };
	int tickets_gdan[] = { n51, n52, n53, n54, n55 };
	int days[] = { 1, 2, 3, 4, 5 };

	int schedule[5][6];

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
	puts("Days          Tickets Quant");
	puts("    Warszawa Wroclaw Poznan Krakow Gdansk");
	for (int i = 0; i < 5; ++i) {  // Выводим на экран строку i
		for (int j = 0; j < 6; ++j)
			printf("%d       ", schedule[i][j]);
		puts("\n");
	}


return 0;
}


