#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number as a string
 * @n2: The second number as a string
 * @r: The buffer to store the result
 * @size_r: The buffer size
 *
 * Return: Pointer to the result or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, len1, len2, carry, sum;

	len1 = 0;
	len2 = 0;
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (size_r <= len1 || size_r <= len2)
		return (0);

	r[size_r - 1] = '\0';
	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 2;
	carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		carry = sum / 10;
		r[k--] = sum % 10 + '0';
	}

	if (k == -1 && carry)
		return (0);

	return (&r[k + 1]);
}

