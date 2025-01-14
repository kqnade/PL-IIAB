#include <ncurses.h>
#include "board.h"
#include "game.h"

char	*sym[3] = {"-", "O", "X"};
void Draw(Board *bd)
{
	int	y, x;

	for (y = 0; y < bd->size; y++) {
		for (x = 0; x < bd->size; x++) {
      mvprintw(y + Y0, 2*x + X0, "%s", sym[Get(bd, y, x)]);
		}
	}
	printf("\n\n");
}

int Game(void){
  Board	*bd;
	int	n;
	int	y, x, player;

	erase();
	mvprintw(Y0, X0, "Board Size? > ");
	refresh();
	if (scanw("%d", &n) == ERR) return (0);
			// 数値入力無しだと ERR になるよ

	bd = New(n);
	if (bd == NULL) goto ERROR;

	Clear(bd);

	player = 1;
	while (1) {
	CONTINUE:
		erase();
		Draw(bd);
		refresh();

		while (1) {
			printw("%s 's turn > ", sym[player]);
			refresh();
			if (scanw("%d %d", &y, &x) == ERR) goto END;

			if (Get(bd, y, x) == 0) break;
			printw("Cant place!!\nAgain ");
		}
		Set(bd, y, x, player);

		player = player%2 + 1;
	}
END:
	printw("Stop game? (y/n)");
	if (getch() != 'y') goto CONTINUE;

	Free(bd);
	return (0);

ERROR:
	printw("メモリ確保失敗\n");
	getch();
	return (1);
};

