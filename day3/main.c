#include <stdio.h>
#include <stdlib.h>



int main()
{
	_Bool is_first_line = 1;
	unsigned int next = getchar();
	while(next!=EOF)
	{
		if(next=='\n')
		{
			is_first_line = 0;
			next=getchar();
		}
	}


}
