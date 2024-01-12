#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

FILE *fp = NULL;
/**
 * main - monty
 * @argc: argument count
 * @argv: arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parser(fp);
	fclose(fp);

	return (0);
}
