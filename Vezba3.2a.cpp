// Vezba3.2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
// KORISNIK UNOSI BROJ UCENIKA, BROJ PREDEMTA I OCENE
// 1. PROSEK UCENIKA
#include <stdio.h>
#define MAXUCENIKA 35
#define MAXPREDEMETA 20
int main()
{
	int ocene[MAXUCENIKA][MAXPREDEMETA];
	int bru, brp, i, j;
	printf("Unesite broj ucenika (max 35): ");
	scanf_s("%d", &bru);
	printf("Unesite broj predmeta (max 20): ");
	scanf_s("%d", &brp);
	for (i = 0; i < bru; i++) // 0 1 ...
	{
		printf("Unesite ocene za ucenika %d: ", i + 1);
		for (j = 0; j < brp; j++) // 0,1,2  0,1,2 ...
			scanf_s("%d", &ocene[i][j]);
	}
	// prikaz ocena
	for (i = 0; i < bru; i++)
	{
		printf("Ocene za ucenika %d: ", i + 1);
		for (j = 0; j < brp; j++)
			printf("%d ", ocene[i][j]);
		printf("\n");
	}
	// racunanje proseka
	float suma;
	float prosek[MAXUCENIKA];
	for (i = 0; i < bru; i++)
	{
		suma = 0;
		for (j = 0; j < brp; j++)
			suma+= ocene[i][j];
		printf("Prosek za ucenika %d: %.2f\n", 
			i + 1, suma / brp);
		prosek[i] = suma / brp;
	}
	// pronalazenje najboljeg ucenika
	int poz = 0;//
	for (i = 1; i < bru; i++)
		if (prosek[i] > prosek[poz])
			poz = i;
	printf("Najbolji je %d sa prosekom %.2f\n",
		poz + 1, prosek[poz]);
	// broj ucenika sa bar jednom opomenom
	int brUcSa1 = 0;
	for (i = 0; i < bru; i++)
	{
		for (j = 0; j < brp; j++)
		{
			if (ocene[i][j] == 1)
			{
				brUcSa1++;
				break;
			}
		}
		// skok
	}
	
}
