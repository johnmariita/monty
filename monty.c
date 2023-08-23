#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stdin, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fp);
	fclose(fp);
}
