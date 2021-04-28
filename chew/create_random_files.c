#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief create random files
 * 
 * This is just made to eat disk space for usage statistics
 * 
 * Written by William Wood Harter
 * Free to use and public domain
 * 
 * @return int 
 */
int show_usage()
{
    printf("Usage: create_random_files num_files file_size\n");
    printf("Create random files of specified size.\n");
}

// get a random character
char get_rand_char()
{
    // number between 0 and 25
    int rand_char_num = (rand() % 26) + 97; // ascii a is 97

    // Type cast to character to convert
    // it to a char type.
    return((char) rand_char_num);
}

int main(int argc, char **argv) { 
    int i;
    int j;
    int num_files;
    int file_size;
    time_t t;   // random seed
    
    char file_rand_chars[16];
    char fname[32];
    char rand_char;
    FILE * fPtr;

    if ((argc<3) || (argc>3))
    {
        printf("Error in usage:\n");
        show_usage();
        return -1;
    }
    else if (argc==3)
    {
        sscanf(argv[1], "%d", &num_files);
        sscanf(argv[2], "%d", &file_size);
    }

   // set the random seed
   srand((unsigned) time(&t));

    for (i=0;i<num_files;i++)
    { 
        // get a random file name
        for (j=0;j<8;j++)
            file_rand_chars[j] = get_rand_char();
        file_rand_chars[8] = '\0';  // null termination for string
        sprintf(fname,"%d-%s.txt",i,file_rand_chars);

        // write random characters to the file
        fPtr = fopen(fname, "w");
        for (j=0;j<file_size;j++)
            fputc(get_rand_char(), fPtr);
        fclose(fPtr);

        printf("created file: %s\n",fname);
    }

    return 0;
}
