#include <PDcurses/curses.h>
#include "functions.h"
#include <string.h>

void printWindows()
{
 char *options[] = {" ", "WATCH", "FROM", "JOIN", "INFO", "EXIT"};
 int xPadding = 0;
 double yMax, xMax;

 getmaxyx(stdscr, yMax, xMax);                       // Getting max values of the terminal
 window = newwin(yMax - 2, xMax - 3, 1, 2);          // TABLE
 box(window, 0, 0);                                  // Margin of TABLE
 border(0, 0, 0, 0, 0, 0, 0, 0);                     // Creating the border
 mvprintw(0, (xMax * 0.50), "MIEL");                 // Printing title
 for (int i = 0; i < (ARRAY_SIZE(options) - 1); i++) // Printing options
 {
  xPadding = xPadding + 1 + strlen(options[i]);
  mvprintw(0, xPadding, "%s", options[i + 1]);
 }
 refresh();
 wrefresh(window);

 char ch;
 int i = 0;
 int limit = 0;
 xPadding = 0;
 while (ch = wgetch(window))
 {
  switch (ch)
  {
  case 'd':
  {
   attroff(A_STANDOUT);
   mvprintw(0, xPadding, "%s", options[i]);

   xPadding = xPadding + 1 + strlen(options[i]);
   i++;
   limit++;
   mvprintw(5, 5, "%d, %d", xPadding, limit);

   if (i == 6)
   {
    i = 5;
   }
   if (limit < 6)
   {
    attron(A_STANDOUT);
    mvprintw(5, 5, "%d, %d", xPadding, limit);
    mvprintw(0, xPadding, "%s", options[i]);
   }

   break;
  }
  case 'a':
  {
   attroff(A_STANDOUT);
   mvprintw(0, xPadding, "%s", options[i]);
   xPadding = xPadding - 1 - strlen(options[i - 1]);
   i--;
   if (i == 0)
   {
    i = 1;
   }
   if (xPadding > 1)
   {
    attron(A_STANDOUT);
    mvprintw(5, 5, "%d", xPadding);
    mvprintw(0, xPadding, "%s", options[i]);
   }
  }
  break;
  default:
  {
   break;
  }
  }
  refresh();
 }
}
