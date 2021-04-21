int main()
{
	int MAX = 10;
	int top = -1;
	int stack_string[MAX];
	char string[MAX] = ‘algorithm’;
	int i;
	printf(“String = %s”, string);
	for (i = 0; i <= strlen(string); i++)
	{
		if (top == MAX – 1)
		{
			printf(“Stack Overflow”);
		}
		else
		{
			top = top+1;
			stack_string[top] = str[i];
		}
	}
	for(i = 0; i <= strlen(string); i++)
	{
		if(top == -1)
		{
			printf(“Stack Underflow”);
		}
		else
		{
			string[i] = stack_string[top];
			top = top – 1;
		}
	}
	printf(“Reversed string is = %s”, string);
}
