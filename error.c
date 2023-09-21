#include "monty.h"


/**
 * check_args - entry point
 * @argc: the arguments count
 * Return: void
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
