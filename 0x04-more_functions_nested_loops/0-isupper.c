#include "main.h"
/**
 *_isupper - checks characters is uppercase
 *@c:number to be checked
 *
 *Return:1 if is upper 0 if its not
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}

	return (0);

}
