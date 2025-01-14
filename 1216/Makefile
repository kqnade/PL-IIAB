CC = cc                  # 使用するコンパイラ
CFLAGS = -Wall            # コンパイラのフラグ（警告を全て表示）
LDFLAGS = -lncursesw      # リンク時に必要なライブラリ（ここではncurses）

# ソースファイルとオブジェクトファイル
SRC = board.c game.c main.c
OBJ = board.o game.o main.o
EXEC = ttt                # 最終的な実行可能ファイル名

# デフォルトターゲット：実行可能ファイルを作成
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

# オブジェクトファイルを作成
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# クリーンターゲット：生成したファイルを削除
.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)

