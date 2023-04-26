#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Kushneryk Yelyzaveta

int main(int argc, char* argv[])
{
	int choice, choice1;
	float money = 0;
	float distance;
	int age;
	float total = 0;
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
				case 1: case 3: case 5:
					money = distance * 0.15 - 5; // one km costs 0.15 zl - 5zl discount because it is monday/wednesday/friday
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

				case 2: case 4:
					money = distance * 0.15 - 10;
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
				case 1: case 3: case 5:
					money = distance * 0.15 - 5;
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

				case 2: case 4:
					money = distance * 0.15 - 10;
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
				case 1: case 3: case 5:
					money = distance * 0.15 - 5;
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

				case 2: case 4:
					money = distance * 0.15 - 10;
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
				case 1: case 3: case 5:
					money = distance * 0.15 - 5;
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

				case 2: case 4:
					money = distance * 0.15 - 10;
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
				case 1: case 3: case 5:
					money = distance * 0.15 - 5;
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

				case 2: case 4:
					money = distance * 0.15 - 10;
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

	printf("\n");
	printf("Your total is %.2f", total); puts(" zl");

}