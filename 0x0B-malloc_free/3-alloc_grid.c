#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * alloc_grid - function that allocates memory to a grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2d array
 */
int **alloc_grid(int width, int height)
{
	int col, row;
	int **doubleptr;

	if (width <= 0 || height <= 0)
		return(NULL);
	doubleptr = malloc(height * sizeof(int *));
	if (doubleptr == NULL)
		return(NULL);
	for (col = 0; col < height; col++)
	{
		doubleptr[col] = malloc(sizeof(int *) * width);
		if (doubleptr[col] == NULL)
		{
			for (; col <= 0; col--)
				free(doubleptr[col]);
			free(doubleptr[col]);
			return(NULL);
		}
		for (row = 0; row < width; row++)
			doubleptr[col][row] = 0;
	}
		return(doubleptr);
}

