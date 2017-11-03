
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define vert 10
#define horiz 7
void main()
{
	int a, b, c, cols2, i, j, x, y;
	int **massive1 = NULL;
	int **massive2 = NULL;
	int **massive3 = NULL;
	massive1 = (int **)malloc(horiz * sizeof(int *));
	for (i = 0; i < horiz; i++)
	{
		massive1[i] = (int *)malloc(vert * sizeof(int));
	}

	c = INT_MAX;				/* for Quest 03 */

	srand(time(NULL));			/* for random */

	printf("\nQuest 01: just make some MASSIVE thing\n\n");

	for (i = 0; i < horiz; i++)
	{
		for (j = 0; j < vert; j++)
		{
			massive1[i][j] = rand() % 10000;
			printf("%d  ", massive1[i][j]);
		}
		printf("\n\n");
	}

	printf
		("\nQuest 02: show first and last rows backwards and make first one last and last one first\n\n");

	for (i = 0, j = vert - 1; i < vert / 2; i++, j--)
	{
		a = massive1[0][j];
		massive1[0][j] = massive1[0][i];
		massive1[0][i] = a;

		b = massive1[horiz - 1][j];
		massive1[horiz - 1][j] = massive1[horiz - 1][i];
		massive1[horiz - 1][i] = b;
	}

	for (i = 0; i < vert; i++)
	{
		a = massive1[0][i];
		massive1[0][i] = massive1[horiz - 1][i];
		massive1[horiz - 1][i] = a;
	}

	for (i = 0; i < horiz; i++)
	{
		for (j = 0; j < vert; j++)
		{
			printf("%d  ", massive1[i][j]);
		}
		printf("\n\n");
	}

	printf("\nQuest 03: be a bulldozer, crash the least\n\n");

	for (i = 0; i < horiz; i++)
	{
		for (j = 0; j < vert; j++)
		{
			if (massive1[i][j] < c)
			{
				c = massive1[i][j];
				x = i;
				y = j;
			}
		}
	}

	for (i = 0; i < horiz; i++)
	{
		for (j = 0; j < vert; j++)
		{
			massive1[x][j] = -1;
			massive1[i][y] = -1;
		}
	}
	for (i = 0; i < horiz; i++)
	{
		for (j = 0; j < vert - 1; j++)
		{
			if (massive1[i][j] == -1 && massive1[i][j + 1] != -1)
			{
				a = massive1[i][j];
				massive1[i][j] = massive1[i][j + 1];
				massive1[i][j + 1] = a;
			}
		}
	}

	for (i = 0; i < horiz - 1; i++)
	{
		for (j = 0; j < vert; j++)
		{
			if (massive1[i][j] == -1 && massive1[i + 1][j] != -1)
			{
				a = massive1[i][j];
				massive1[i][j] = massive1[i + 1][j];
				massive1[i + 1][j] = a;
			}
		}
	}

	for (i = 0; i < horiz - 1; i++)
	{
		for (j = 0; j < vert - 1; j++)
		{
			printf("%d  ", massive1[i][j]);
		}
		printf("\n\n");
	}

	printf
		("\nQuest 04: become a matrix\nSyntax: space is for element's end, comma is for row's end, dot is for end of matrix.\n\n");
	printf("But first, type in amount of columns: ");
	scanf("%d", &cols2);
	printf("\n%d rows, %d columns", vert - 1, cols2);

	massive2 = (int **)malloc((vert - 1) * sizeof(int *));
	for (i = 0; i < (vert - 1); i++)
	{
		massive2[i] = (int *)malloc(cols2 * sizeof(int));
	}

	massive3 = (int **)malloc((horiz - 1) * sizeof(int *));
	for (i = 0; i < (horiz - 1); i++)
	{
		massive3[i] = (int *)malloc(cols2 * sizeof(int));
	}

	printf("\nNow start typing the matrix\n");
	for (i = 0; i < vert - 1; i++)
	{
		for (j = 0; j < cols2; j++)
		{
			scanf("%d", &massive2[i][j]);
		}
		scanf(",");
	}

	for (i = 0; i < vert - 1; i++)
	{
		for (j = 0; j < cols2; j++)
		{
			printf("%d  ", massive2[i][j]);
		}
		printf("\n\n");
	}

	printf("\nQuest 05: improvise, adapt, overcome, or just multiply two matrixes above\n\n");

	for (i = 0; i < (horiz - 1); i++)
	{
		for (j = 0; j < cols2; j++)
		{
			massive3[i][j] = 0;
			for (c = 0; c < vert - 1; c++)
			{
				massive3[i][j] += massive1[i][c] * massive2[c][j];
			}
		}
	}

	for (i = 0; i < horiz - 1; i++)
	{
		for (j = 0; j < cols2; j++)
		{
			printf("%d  ", massive3[i][j]);
		}
		printf("\n\n");
	}
}
