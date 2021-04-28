#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <syslog.h>

/**
 * @brief send syslog
 * 
 * This is just made send random syslog messages
 * 
 * Written by William Wood Harter
 * Free to use and public domain
 * 
 * @return int 
 */
int show_usage()
{
    printf("Usage: send_syslog_messages num_messages\n");
    printf("Create random number of syslog messages\n");
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

#define MSG_LEN 16
int main(int argc, char **argv) { 
    int i;
    int j;
    int num_msgs;
    time_t t;   // random seed

    char msg_payload[MSG_LEN];

    if ((argc<2) || (argc>2))
    {
        printf("Error in usage:\n");
        show_usage();
        return -1;
    }
    else if (argc==2)
    {
        sscanf(argv[1], "%d", &num_msgs);
    }

    // set the random seed
    srand((unsigned) time(&t));

    //setlogmask (LOG_UPTO (LOG_NOTICE));
    setlogmask (LOG_UPTO (LOG_DEBUG));
    openlog ("cpsc298", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
    syslog (LOG_NOTICE, "send_syslog_messages started");


    for (i=0;i<num_msgs;i++)
    { 
        // get a random file name
        for (j=0;j<MSG_LEN-2;j++)
            msg_payload[j] = get_rand_char();
        msg_payload[MSG_LEN-1] = '\0';  // null termination for string

        syslog(LOG_ERR, "%d %s", i, msg_payload);
    }

    return 0;
}
