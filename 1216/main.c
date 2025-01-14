#include <locale.h>
#include <ncurses.h>
#include "game.h"

int Title(void)
{
  erase();
	mvprintw(Y0+ 0, X0, "+-------------------------------+");
	mvprintw(Y0+ 1, X0, "| The Most Simplest TIC-TAC-TOE |");
	mvprintw(Y0+ 2, X0, "+-------------------------------+");

	mvprintw(Y0+ 4, X0, "  line:x row:y");
	mvprintw(Y0+ 5, X0, "  the number start 0");
	mvprintw(Y0+ 6, X0, "  We dont provide judgement system");

	mvprintw(Y0+ 8, X0, "  PL1: %s", sym[1]);
	mvprintw(Y0+ 9, X0, "  PL2: %s", sym[2]);

	mvprintw(Y0+11, X0, "  Quit [Q] or inGame [Enter]");
	mvprintw(Y0+12, X0, "  Start: [Enter]");
	refresh();
	return (getch());
}
int main(void)
{
  setlocale(LC_ALL, "C");	// 日本語を使うよ
	initscr();		// 端末制御を開始

	while (1) {
		if (Title() == 'q') break;
    if (Game()) break;
	}
	endwin();

  return 0;
}


