#include <PDcurses/curses.h>
#include "functions.h"
int main()
{
 initscr();
 curs_set(0);
 keypad(stdscr, true);
 printWindows();

 int c = getch();

 endwin();

 return 0;
}