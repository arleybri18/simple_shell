#include "holberton.h"

/**
 * free_grid - create a two dimensional array
 *
 * @grid: grid to free
 * @height: heigth of the array
 *
 * Return: Nothing
 */
void free_grid(char **grid, int height)
{
	int i = 0;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
