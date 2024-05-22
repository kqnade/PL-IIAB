#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *hands[] = {"グー", NULL, "チョキ", NULL, NULL, "パー"};
    int user_input, computer_hand;
    srand(time(NULL));

    while (1) {
        computer_hand = (rand() % 3) * 2.5;
        printf("ジャンケンポン {0, 2, 5} > ");
        if (scanf("%d", &user_input) != 1 || user_input < 0 || user_input > 5 || hands[user_input] == NULL) {
            printf("何だそれー？ もう一度!!\n");
            while (getchar() != '\n');
            continue;
        }
        printf("あなたは%s 私は%s ", hands[user_input], hands[computer_hand]);
        if (user_input == computer_hand) {
            printf("アイコ\n");
        } else {
            int result = ((user_input - computer_hand + 6) / 2) % 3;
            printf(result == 1 ? "私の勝ち\n" : "あなたの勝ち\n");
        }
    }
    return 0;
}

