#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* saved_memory;
unsigned int memory_length = 0;
int* work_memory;

void set_work_memory(int noun, int verb)
{
	unsigned int index = 0;
	for(index = 0; index<memory_length; index++)
	{
		work_memory[index] = saved_memory[index];
	}

	work_memory[1] = noun;
	work_memory[2] = verb;
}

void compute(int* memory)
{
	unsigned int instruction_pointer = 0;
	while(instruction_pointer<memory_length)
	{
		switch (memory[instruction_pointer])
		{
			case 1:
				memory[memory[instruction_pointer+3]] = memory[memory[instruction_pointer+1]] + memory[memory[instruction_pointer+2]];
				instruction_pointer+=4;
				break;
			case 2:
				memory[memory[instruction_pointer+3]] = memory[memory[instruction_pointer+1]] * memory[memory[instruction_pointer+2]];
				instruction_pointer+=4;
				break;
			case 99:
				//printf("index 0 = %d\n", memory[0]);
				return;
			default:
				instruction_pointer+=4;
		}
	}
}

void find_noun_verb()
{
	int noun, verb = 0;
	work_memory = (int*) malloc(memory_length * sizeof(int*));

	for(noun = 0; noun < 100; noun++)
	{
		for(verb = 0; verb < 100; verb++)
		{
			set_work_memory(noun, verb);

			compute(work_memory);

			if(work_memory[0] == 19690720)
			{
				printf("noun is %d, verb is %d, result is %d\n", noun, verb, noun*100+verb);
				return;
			}
		}
	}
}



int main(void)
{
	saved_memory = (int*) malloc(sizeof(int*));
	int next = getchar();
	int last;

	while(next!=EOF)
	{
		//init array
		while(isdigit(next))
		{
			if(isdigit(last))
			{
				            saved_memory[memory_length-1] = saved_memory[memory_length-1] * 10 + (next - '0');
			} else {
				            saved_memory[memory_length++] = (next - '0');
				            saved_memory = (int*) realloc(saved_memory, memory_length * sizeof(int*));
				if(saved_memory == NULL)
				{
					printf("error when realloc array");
					free(saved_memory);
					exit(0);
				}
			}
			last = next;
			next = getchar();
		}
		last = next;
		next = getchar();
	}

	find_noun_verb();
	//compute(saved_memory);

	free(work_memory);
	free(saved_memory);

}
