#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - function that allocates memory to a grid
 * @width: int arg
 * @height: int arg
 * Return: grid of 0's
 */
int **alloc_grid(int width, int height)
{
	int col, row;
	int **doubleptr;

	if (width < 1 || height < 1)
		return(NULL);
	doubleptr = malloc(height * sizeof(int *));
	if (doubleptr == NULL)
		return(NULL);
	for (col = 0; col < height; col++)
	{
		if (doubleptr[col] == NULL)
		{
			for (row = 0; row < col; row++)
				free(doubleptr[row]);
			free(doubleptr[row]);
			return(NULL);
		}
		for (row = 0; row < width; row++)
			doubleptr[col][row] = 0;
	}
		return(doubleptr);
}

