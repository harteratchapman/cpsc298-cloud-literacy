#include <stdio.h>
#include <string.h>

int show_usage()
{
    printf("Usage: calc_primes [starting num]\n");
    printf("Calculate prime numbers. If no starting num is\n");
    printf("given, start at 1\n");
}

int main(int argc, char **argv) { 
    int i;
    int cur_number;
    int is_prime;


    if (argc>2)
    {
        printf("Error in usage:\n");
        show_usage();
    }
    else if (argc==2)
    {
        if (strcmp(argv[1],"-h")==0)
        {
            show_usage();
	    return 1;
        }
    }
    else if (argc==1)
    {
        cur_number = 1;
    }

    return -1;

    while (1)
    { 
        // start by assuming it's a prime
        is_prime = 1;

        // loop through all numbers
        for(i = 2; i < cur_number; i++) {
            if((cur_number % i) == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
            printf("%d is prime number.\n", cur_number);
        cur_number++;
    }

    return 0;
}
