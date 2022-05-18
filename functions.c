#include <PDcurses/curses.h>
#include "functions.h"

void printWindows()
{
 double yMax, xMax;
 getmaxyx(stdscr, yMax, xMax);

 border(0, 0, 0, 0, 0, 0, 0, 0);                                          // Creating the border
 windows[0] = newwin(yMax / 6, xMax - 6, 2, 3);                           // TITLE -->[0]
 windows[1] = newwin(yMax * 0.70, xMax / 4, yMax * 0.25, 3);              // MENU  -->[1]
 windows[2] = newwin(yMax * 0.70, xMax * 0.68, yMax * 0.25, xMax * 0.30); // TABLE -->[2]
 refresh();
 for (int i = 0; i < WINDOWS_SIZE; i++)
 {
  box(windows[i], 0, 0);
  wrefresh(windows[i]);
 }
}