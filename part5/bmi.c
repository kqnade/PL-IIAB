#include <stdio.h>

int main(void) {
  int HeightCm, WeightKg, n;
  double HeightM, bmi;

  printf("BMi checker\n");

  while (1) {
    printf("Enter your Height(cm)&Weight(Kg) |>");
    if (scanf("%d %d", &HeightCm, &WeightKg) == EOF) {
      printf("Invaild input\n");
      break;
    }

    HeightM = (double)HeightCm / (double)100;
    bmi = WeightKg / (HeightM * HeightM);

    printf("Your BMI is %.1f\n", bmi);

    if (bmi < 18.5) {
      printf("低体重（やせ型）\n");
    } else if (bmi < 25.0) {
      printf("普通体重\n");
    } else {
      n = (int)((bmi - 25.0) / 5.0) + 1;
      if (n > 4)
        n = 4;
      printf("肥満（%d 度）\n", n);
    }
  }
  return 0;
}
