#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * add_numbers - Adds two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of two numbers.
 */
int add_numbers(int a, int b)
{
	return (a + b);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int num1 = 20;
	int num2 = 15;
	int result;

	result = add_numbers(num1, num2);

	printf("the sum is:%d\n", result);

	return (0);
}
