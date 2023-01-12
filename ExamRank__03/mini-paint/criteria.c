#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define ARG_ERR "Error: argument\n"
#define FILE_ERR "Error: Operation file corrupted\n"

int bgW;
int bgH;
char bgC;

char type;
float cX;
float cY;
float r;
char color;

FILE *file;
char **paper;

int ft_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
	}
	return (1);
}

int isInCircle(int x, int y)
{
	float distance = sqrtf(powf(cX - x, 2.0) + powf(cY - y, 2.0));
	if (distance < r)
	{
		if (r - distance < 1.000000)
			return (1);
		return (2);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (ft_putstr(ARG_ERR));
	file = (fopen(av[1], "r"));
	if (!file)
		return (ft_putstr(FILE_ERR));
	int ret = fscanf(file, "%d %d %c\n", &bgW, &bgH, &bgC);
	if (ret != 3 || bgW < 1 || bgH < 1 || bgW > 300 || bgH > 300)
		return (ft_putstr(FILE_ERR));
	paper = malloc(bgH * sizeof(char *));
	for (int i = 0; i < bgH; i++)
	{
		paper[i] = malloc(bgW * sizeof(char));
		memset(paper[i], bgC, bgW);
	}
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &type, &cX, &cY, &r, &color)) == 5)
	{
		if (r < 1 || (type != 'c' && type != 'C'))
			return (ft_putstr(FILE_ERR));
		for (int y = 0; y < bgH; y++)
		{
			for (int x = 0; x < bgW; x++)
			{
				int cond = isInCircle(x, y);
				if (cond == 1 || (cond == 2 && type == 'C'))
					paper[y][x] = color;
			}
		}
	}
	if (ret != -1)
		return (ft_putstr(FILE_ERR));
	for (int i = 0; i < bgH; i++)
	{
		ft_putstr(paper[i]);
		ft_putstr("\n");
	}
	return (0);
}