#include <stdio.h> 
#include <stdlib.h> 
#define MAX 500

int genFibonacciNum(int n, int *fib_value)
{
	int i, j;
	int carry = 0, add;
	int fib_prev[MAX] = { 0 };
	int fib_next[MAX] = { 0 };
	fib_prev[MAX - 1] = 0;
	fib_next[MAX - 1] = 1;
	if (n < 0)
	{
		while (n < 0)
		{
			printf("you have entered negative number, please enter proper Number\n\t-->");
			scanf("%d", &n);
		}
	}
	else if (n == 0)
	{
		fib_value[MAX - 1] = fib_prev[MAX - 1];
		j = 1;
	}
	else if (n == 1)
	{
		fib_value[MAX - 1] = fib_next[MAX - 1];
		j = 1;
	}
	else
	{
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <= MAX; j++)
			{
				add = fib_prev[MAX - j] + fib_next[MAX - j] + carry;
				fib_value[MAX - j] = (add % 10);
				carry = add / 10;
				fib_prev[MAX - j] = fib_next[MAX - j];
				fib_next[MAX - j] = fib_value[MAX - j];
            }
        }
    }
        for(j = 0; j < MAX; j++)
        if(fib_value[j]!= 0)
            break;
        j = MAX - j;
    return j;
}

int divBy3(int* fib_value, int len)
{
    int i;
    signed int num = 0;
    for (i = len; i >= 1; i--)
        num += fib_value[MAX - i]; 
	return (num % 3 == 0) ? 1 : 0;
}

int divBy5(int* fib_value, int len)
{
    return ((fib_value[MAX - 1] == 0) || (fib_value[MAX - 1] == 5)) ? 1 : 0;
}

int divBy15(int* fib_value, int len)
{
	return (divBy3(fib_value,len) && divBy5(fib_value,len)) ? 1 : 0;
}

int primeNo(int num, int len)
{
	unsigned long i;
	unsigned long check_pnt = 1, sqr_value = 1;
	while (sqr_value <= num)
	{
		check_pnt++;
		sqr_value = check_pnt*check_pnt;
	}
	for (i = 2; i<check_pnt; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int n;
	char ch = '\0';
	int length;
	while (1)
	{
		printf("\n\nEnter value of n \n\t-->");
		scanf("%d", &n);
		int i;
		int fib[MAX] = { 0 };
		length = genFibonacciNum(n, fib);
		if(divBy15(fib,length))
		{
            printf("FizzBuzz");
		}
		else if(divBy5(fib,length))
		{
            printf("Fizz");
		}
		else if(divBy3(fib,length))
		{
            printf("Buzz");
		}
		else
		{
	        for (i = length; i >= 1; i--)
                printf("%d", fib[MAX - i]); 
		
		}
		printf("\n");
        for (i = length; i >= 1; i--)
			printf("%d", fib[MAX - i]); 
		printf("\n\n\n\tPlease Press any key to continue with Next Number \n\t\tor \n\tpress\"E/e\" followed by ENTER to exit :");
		//ch = getchar();
		fflush(stdin);
		scanf("%c", &ch);

		if (ch == 'e' || ch == 'E')
			break;
	}  
	return 0;
}
