#include <PDcurses/curses.h>
#include "functions.h"
#include <string.h>

void printWindows()
{
 char *options[] = {" ", "WATCH", "FROM", "JOIN", "INFO", "EXIT"};
 int xPadding = 0;
 double yMax, xMax;

 getmaxyx(stdscr, yMax, xMax);       // Getting max values of the terminal
 border(0, 0, 0, 0, 0, 0, 0, 0);     // Creating the border
 mvprintw(0, (xMax * 0.50), "MIEL"); // Printing title

 for (int i = 0; i < (ARRAY_SIZE(options) - 1); i++) // Printing options
 {
  xPadding = xPadding + 1 + strlen(options[i]);
  mvprintw(0, xPadding, "%s", options[i + 1]);
 }

 window = newwin(yMax - 2, xMax - 3, 1, 2); // TABLE
 refresh();

 box(window, 0, 0);
 wrefresh(window);
 // char ch;
 // while (ch = wgetch(window))
 // {
 //  switch (expression)
 //  {
 //  case /* constant-expression */:
 //   /* code */
 //   break;

 //  default:
 //   break;
 //  }
 // }
}