#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <assert.h>
int main()
 
{
    int n;
    char ch = '\0';
    mpz_t fib_value;  
    mpz_t fib_prev;
    mpz_t fib_next;
    mpz_t rem_three;
    mpz_t three;
    mpz_t rem_five;
    mpz_t five;
    mpz_t sqrt;
    mpz_t index;
    mpz_t zero;
    mpz_t one;
    mpz_t prm_temp;
    while(1)
    {
        printf("Enter value of n \n\t-->");
        scanf("%d",&n);
	int i;
        //fflush(stdin);    	

    	mpz_init(fib_value);
    	mpz_set_ui(fib_value,0);
        
    	mpz_init(fib_prev);
    	mpz_set_ui(fib_prev,0);

    	mpz_init(fib_next);
    	mpz_set_ui(fib_next,1);
	
    	if(n < 0)
        {
            while(n < 0)
            {
                printf("you have entered negative/out of range number, please enter proper Number\n\t-->");
                scanf("%d", &n);
            }
        }
        else if(n == 0)
        {
            mpz_set(fib_value,fib_prev);
        }
        else if(n == 1)
        {
            mpz_set(fib_value,fib_next);
        }
        else
        {
            for(i = 2; i <= n; i++)
            {
                mpz_add(fib_value,fib_prev,fib_next);
                mpz_set(fib_prev,fib_next);
                mpz_set(fib_next,fib_value);
	    }
        }

        //mpz_out_str(stdout,10,fib_value);

    	mpz_init(rem_three);
    	mpz_set_ui(rem_three,0);

    	mpz_init(three);
    	mpz_set_ui(three,3);

	mpz_mod(rem_three,fib_value,three);
	
    	mpz_init(rem_five);
    	mpz_set_ui(rem_five,0);

    	mpz_init(five);
    	mpz_set_ui(five,5);

	mpz_mod(rem_five,fib_value,five);
	
    	mpz_init(sqrt);
    	mpz_set_ui(sqrt,0);

	mpz_sqrt(sqrt,fib_value);

    	mpz_init(index);
    	mpz_set_ui(index,2);

    	mpz_init(zero);
    	mpz_set_ui(zero,0);

    	mpz_init(one);
    	mpz_set_ui(one,1);
       	

    	mpz_init(prm_temp);
    	mpz_set_ui(prm_temp,0);

	int flag = 0;
	int check1,check2;
	
	//mpz_out_str(stdout,10,sqrt);
	check1 = mpz_cmp(index,sqrt);
			
	while(check1 <= 0)	
	{
		check1 = mpz_cmp(index,sqrt);
		mpz_mod(prm_temp,fib_value,index);
		check2 = mpz_cmp(prm_temp,zero);		
		if(check2  == 0 )
        	{
        	    flag = 1;
        	}
		mpz_add_ui(index,index,1);
	}	
	//printf("\n");
	if(mpz_cmp(fib_value,zero) == 0 || mpz_cmp(fib_value,one) == 0)
	{
	    mpz_out_str(stdout,10,fib_value);
	}
	else if(mpz_cmp(rem_five,zero) == 0 && mpz_cmp(rem_three,zero) == 0)
        {
            printf("FizzBuzz");
        }
        else if(mpz_cmp(rem_three,zero) == 0)
        {
	    printf("Buzz");
        }
        else if(mpz_cmp(rem_five,zero) == 0)
        {
	    printf("Fizz");
        }
        else if(flag == 0)
        {
            printf("BuzzFizz");
        }
        else
        {
	    mpz_out_str(stdout,10,fib_value);
        }

	printf("\nPlease Press any key to continue with Next Number \n\t\tor \npress\"E/e\" followed by ENTER to exit :");
        
        fflush(stdin);

        scanf("%c",&ch);
       
        if(ch == 'e' || ch == 'E')
            break;
     }
	mpz_clear(fib_value);
	mpz_clear(fib_prev);
	mpz_clear(fib_next);
	mpz_clear(three);
	mpz_clear(rem_five);
	mpz_clear(five);
	mpz_clear(sqrt);
	mpz_clear(index);
	mpz_clear(zero);
	mpz_clear(one);
	mpz_clear(prm_temp);
        return 0;
}
