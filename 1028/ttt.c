#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define PLAYER 1
#define COMPUTER 2

/* タイトルを表示する関数 */
void Title() {
    printf("+-----------------------------+\n");
    printf("| The Most Simple TIC-TAC-TOE |\n");
    printf("+-----------------------------+\n");
    printf("\n");
    printf("  位置の指定は行番号y，列番号x の順ね．\n");
    printf("    （番号は 0 から数えるよ．）\n");
    printf("  終了するには [Ctrl]+[D]．\n");
    printf("\n");
}

/* ゲーム盤の初期化 */
void Clear(int *bd, int n) {
    int i;
    for (i = 0; i < n * n; i++) {
        bd[i] = EMPTY;
    }
}

/* ゲーム盤を表示する関数 */
void Draw(int *bd, int n) {
    int y, x;
    printf("\n");
    for (y = 0; y < n; y++) {
        for (x = 0; x < n; x++) {
            printf("%2d", bd[y * n + x]);
        }
        printf("\n");
    }
    printf("\n");
}

/* プレイヤーの手を取得する関数 */
int Get(int *bd, int n, int y, int x) {
    if (x < 0 || x >= n || y < 0 || y >= n) return -1; /* ハミ出し禁止 */
    return bd[y * n + x];
}

/* ゲーム盤に手を置く関数 */
void Set(int *bd, int n, int y, int x, int v) {
    if (x < 0 || x >= n || y < 0 || y >= n) return; /* ハミ出し禁止 */
    bd[y * n + x] = v;
}

/* 勝利判定 */
int CheckWin(int *bd, int n, int player) {
    int y, x;

    /* 行と列をチェック */
    for (y = 0; y < n; y++) {
        int row = 1, col = 1;
        for (x = 0; x < n; x++) {
            if (Get(bd, n, y, x) != player) row = 0;
            if (Get(bd, n, x, y) != player) col = 0;
        }
        if (row || col) return 1;
    }

    /* 対角線をチェック */
    int diag1 = 1, diag2 = 1;
    for (y = 0; y < n; y++) {
        if (Get(bd, n, y, y) != player) diag1 = 0;
        if (Get(bd, n, y, n - 1 - y) != player) diag2 = 0;
    }
    return diag1 || diag2;
}

/* コンピュータの手を決定する関数 */
void ComputerMove(int *bd, int n) {
    int moveY = -1, moveX = -1;
    int y, x;

    /* 簡単なAI: 勝利可能な手を探す */
    for (y = 0; y < n; y++) {
        for (x = 0; x < n; x++) {
            if (Get(bd, n, y, x) == EMPTY) {
                Set(bd, n, y, x, COMPUTER);
                if (CheckWin(bd, n, COMPUTER)) {
                    moveY = y;
                    moveX = x;
                    break;
                }
                Set(bd, n, y, x, EMPTY);
            }
        }
        if (moveY != -1) break;
    }

    /* 勝利手が見つからなければランダムに手を選ぶ */
    if (moveY == -1) {
        while (1) {
            moveY = rand() % n;
            moveX = rand() % n;
            if (Get(bd, n, moveY, moveX) == EMPTY) break;
        }
    }

    Set(bd, n, moveY, moveX, COMPUTER);
}

int main(void) {
    int n;
    int *bd;

    Title();
    printf("ゲーム盤のサイズ (3以上) > ");
    scanf("%d", &n);
    if (n < 2) {
        printf("無効なサイズです。\n");
        return 1;
    }

    bd = (int *)malloc(n * n * sizeof(int));
    if (bd == NULL) {
        printf("メモリの確保に失敗しました。\n");
        return 1;
    }

    Clear(bd, n);
    int player = PLAYER;

    while (1) {
        Draw(bd, n);

        if (player == PLAYER) {

            int y, x;
            while (1) {
                printf("%dP の番 > ", player);
                if (scanf("%d %d", &y, &x) == EOF) goto END;

                if (Get(bd, n, y, x) == EMPTY) break;
                printf("そこには置けません!!\nもう一度 ");
            }
            Set(bd, n, y, x, player);
        } else {
            ComputerMove(bd, n);
            printf("コンピュータが手を打ちました。\n");
        }

        if (CheckWin(bd, n, player)) {
            Draw(bd, n);
            printf("プレイヤー %d の勝ち!\n", player);
            break;
        }

        /* 引き分け判定 */
        int full = 1;
        int i;
        for (i = 0; i < n * n; i++) {
            if (bd[i] == EMPTY) {
                full = 0;
                break;
            }
        }
        if (full) {
            Draw(bd, n);
            printf("引き分けです。\n");
            break;
        }

        /* プレイヤーを切り替え */
        player = (player == PLAYER) ? COMPUTER : PLAYER;
    }

END:
    free(bd); /* メモリを解放 */
    return 0;
}

