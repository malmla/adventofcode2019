#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	int next = getchar();
	int module;
	int module_total_fuel = 0;
	int total_fuel = 0;
	int fuel = 0;

	while(next!=EOF)
	{
		module = 0;
		while(isdigit(next))
		{
			module = module * 10 + (next - '0');
			next = getchar();
		}
		fuel = (module/3) - 2;
		module_total_fuel += fuel;
		int rest = (fuel/3) - 2;
		while(rest > 0)
		{
			total_fuel += rest;
			rest = (rest/3) - 2;
		}
		next = getchar();
	}
	printf("module fuel is %d\n", module_total_fuel);
	printf("total fuel is %d\n", total_fuel + module_total_fuel);

}
