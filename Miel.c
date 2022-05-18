#include <PDcurses/curses.h>
#include "functions.h"

int main()
{

 initscr();

 cbreak();
 noecho();
 keypad(stdscr, TRUE);
 curs_set(0);

 printWindows();

 int c = getch();

 endwin();

 return 0;
}