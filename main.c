#include "monty.h"
pro_args pa = {NULL, NULL, NULL, 0};
/**
* main - start of theprogrma
* @argc: number of arguments
* @argv: arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	unsigned int counter = 0;
	char *content;
	FILE *file;
	ssize_t read_line = 1;
	size_t size = 0;
	stack_t *stack = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	pa.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		pa.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
