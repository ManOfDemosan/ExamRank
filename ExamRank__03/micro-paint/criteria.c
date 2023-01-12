#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ARG_ERR "Error: argument\n"
#define FILE_ERR "Error: Operation file corrupted\n"

int bgW;
int bgH;
char bgC;

char type;
float recX;
float recY;
float recW;
float recH;
char color;

char **paper;

FILE *file;

int ft_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
	}
	return (1);
}

int isInRec(int x, int y)
{
	if (x < recX || y < recY || (recX + recW) < x || (recY + recH) < y)
		return (0);
	else if (x - recX < 1.000000 || y - recY < 1.000000 || (recX + recW) - x < 1.000000 || (recY + recH) - y < 1.000000)
		return (1);
	return (2);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr(ARG_ERR));
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (ft_putstr(FILE_ERR));
	int ret = fscanf(file, "%d %d %c\n", &bgW, &bgH, &bgC);
	if (ret != 3 || bgW < 1 || bgW > 300 || bgH < 1 || bgH > 300)
		return (ft_putstr(FILE_ERR));
	paper = malloc(bgH * sizeof(char *));
	for (int i = 0; i < bgH; i++)
	{
		paper[i] = malloc(bgW * sizeof(char));
		memset(paper[i], bgC, bgW);
	}
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &type, &recX, &recY, &recW, &recH, &color)) == 6)
	{
		if ((type != 'r' && type != 'R') || recW < 1 || recH < 1)
			return (ft_putstr(FILE_ERR));
		for (int y = 0; y < bgH; y++)
		{
			for (int x = 0; x < bgW; x++)
			{
				int cond = isInRec(x, y);
				if ((cond == 2 && type == 'R') || cond == 1)
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
}