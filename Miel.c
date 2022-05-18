#include <PDcurses/curses.h>
#include "functions.h"
int main()
{
 initscr();

 noecho();
 cbreak();
 curs_set(0);
 keypad(stdscr, TRUE);

 printWindows();

 int c = getch();

 endwin();

 return 0;
}