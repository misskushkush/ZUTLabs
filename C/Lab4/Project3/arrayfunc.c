#include<stdio.h>
#include<string.h>
#include "Array.h"

static void ShowSchedule(int schedule[row][col])
{
	puts("Days          Tickets Quant");
	puts("      Warszawa Wroclaw Poznan Krakow Gdansk");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0 && j == 0) puts("Mon");
			else if (i == 1 && j == 0) puts("Tue");
			else if (i == 2 && j == 0) puts("Wed");
			else if (i == 3 && j == 0) puts("Thu");
			else if (i == 4 && j == 0) puts("Fri");
			else printf("\t%d", schedule[i][j]);
		}
		puts("\n");
	}
}

static void MakeSchedule(int schedule[row][col], int days[row], int tickets_war[row], int tickets_wroc[row], int tickets_poz[row], int tickets_krak[row], int tickets_gdan[row])
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

