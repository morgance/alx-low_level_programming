#include "main.h"

/**
 * _abs - Computes the absolute value
 * of an integer.
 *
 * @c: input number as an integer.
 *
 * Return: absolute value
 */
int _abs(int c)
{
	if (c >= 0)
	{
		return (c);
	}
	else
	{
		return (c * -1);
	}
}
