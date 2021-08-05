/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Script
 * LICENSE : MIT
 */
/* Include header C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>

/* Include header */
#include "FGTL_System.h"

struct termios FGTL_SYSTEM_OLD, FGTL_SYSTEM_CURRENT;
struct termios FGTL_SYSTEM_ORIG_TERMIOS;

/*
 * @parameter { void }
 * This function for reset terminal
 * mode
 */
void FGTL_reset_terminal_mode(void) \
{
	tcsetattr(0, TCSANOW, \
		&FGTL_SYSTEM_ORIG_TERMIOS);
}

/*
 * @parameter { void }
 * This function for set conio terminal
 * mode
 */
void FGTL_set_conio_terminal_mode(void) \
{
	struct termios new_termios;

    /* take two copies - one 
     * for now, one for later 
     */
    tcgetattr(0, &FGTL_SYSTEM_ORIG_TERMIOS);
    memcpy(&new_termios, &FGTL_SYSTEM_ORIG_TERMIOS, \
    	sizeof(new_termios));

    /* register cleanup handler, 
     * and set the new terminal mode 
     */
    atexit(FGTL_reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

/*
 * @parameter { void }
 * kbhit() is present in conio.h and 
 * used to determine if a key has 
 * been pressed or not.
 */
int FGTL_kbhit(void) \
{
	struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

/*
 * @parameter { int { echo } }
 * Intialize termios
 */
void FGTL_initTermios(int echo) \
{
	/* grab old terminal 
	 * i/o settings 
	 */
	tcgetattr(0, &FGTL_SYSTEM_OLD);

	/* make new settings 
	 * same as old settings 
	 */
    FGTL_SYSTEM_CURRENT = FGTL_SYSTEM_OLD;

    /* disable buffered i/o */
    FGTL_SYSTEM_CURRENT.c_lflag &= ~ICANON;
    if (echo) {
    	/* set echo mode */
        FGTL_SYSTEM_CURRENT.c_lflag |= ECHO;
    } else {
    	/* set no echo mode */
        FGTL_SYSTEM_CURRENT.c_lflag &= ~ECHO;
    }

    /* use these new 
     * terminal i/o settings 
     * now 
     */
    tcsetattr(0, TCSANOW, &FGTL_SYSTEM_CURRENT);
}

/*
 * @parameter { void }
 * reset termios
 */
void FGTL_resetTermios(void) \
{
	/* Restore old terminal 
	 * i/o settings 
	 */
	tcsetattr(0, TCSANOW, &FGTL_SYSTEM_OLD);
}

/*
 * @parameter { void }
 * read 1 character - echo 
 * defines echo mode
 */
char FGTL_getch_(int echo) \
{
	char ch;
    FGTL_initTermios(echo);
    ch = getchar();
    FGTL_resetTermios();
    return ch;
}

/*
 * @parameter { void }
 * Read 1 character without echo
 */
char FGTL_getch(void) \
{
	return FGTL_getch_(0);
}

/*
 * @parameter { void }
 * Read 1 character with echo
 */
char FGTL_getche(void) \
{
	return FGTL_getch_(1);
}

/*
 * @parameter { void }
 * Get input
 */
int FGTL_getInput(char *c) \
{
	if (FGTL_kbhit())
    {
        *c = FGTL_getch();
        
        /* Key Was Hit */ 
        return 1;
    }

    /* No keys were pressed */
    return 0;
}