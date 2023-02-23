#include "main.h"
/**
 *_isdigit - checks if character is digit
 *
 *@c: number to be checked
 *Return:1 if its digit else 0
 */
int _isdigit(int c)
{
	for (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


