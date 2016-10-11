#include <stdio.h>
#include <stdlib.h>



void odczyt_pliku(int **);
int main()
{

	int **tab=NULL;

	odczyt_pliku(tab);
	return 0;
}

void odczyt_pliku(int **tablica)
{
	FILE *plik;
	int rozmiar=0,i,j,suma=0;
	int *trasa;

	char nazwa[] = "exp0.txt";
	if ((plik = fopen(&nazwa, "r")) == NULL)
	{
		printf("Blad\n");
	}
	else 
	{
		plik = fopen(&nazwa, "r");
		fscanf(plik, "%d", &rozmiar);
		printf("Rozmiar macierzy:%d\n", rozmiar);
		tablica = (int**)malloc(rozmiar * sizeof(int*));
		trasa = (int*)malloc(rozmiar * sizeof(int));
		for (i = 0; i < rozmiar; i++)
		{
			tablica[i] = (int*)malloc(rozmiar * sizeof(int));
		}

		for (i = 0; i < rozmiar; i++)
		{
			for (j = 0; j < rozmiar; j++)
			{
				fscanf(plik, "%d", &tablica[i][j]);
				printf("%d ", tablica[i][j]);
			}
			printf("\n");

		}
		for (i = 0; i < rozmiar; i++)
		{
			fscanf(plik, "%d", &trasa[i]);
			printf("%d ", trasa[i]);
		}
	}
	fclose(plik);
	for (i = 0; i < rozmiar-1; i++)
	{
		suma = suma + tablica[trasa[i]][trasa[i+1]];
		

	}
	suma += tablica[rozmiar-1][0];
	printf("\nsuma:%d", suma);
}