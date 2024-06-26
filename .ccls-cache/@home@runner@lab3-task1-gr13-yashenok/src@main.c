#include <stdio.h>
#include <stdlib.h>

// Функция для проверки високосного года
int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return 1; // Високосный год
  else
    return 0; // Невисокосный год
}

// Функция для определения количества дней между двумя датами
int daysSince1970(int day, int month, int year) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int totalDays = 0;

  // Добавляем дни за полные года
  for (int i = 1970; i < year; i++) {
    if (isLeapYear(i))
      totalDays += 366; // Високосный год
    else
      totalDays += 365; // Невисокосный год
  }

  // Добавляем дни за полные месяцы текущего года
  for (int i = 1; i < month; i++) {
    totalDays += daysInMonth[i - 1];
    if (i == 2 && isLeapYear(year))
      totalDays++; // Високосный год, добавляем еще один день за февраль
  }

  // Добавляем дни текущего месяца
  totalDays += day - 1;

  return totalDays;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Ошибка! Необходимо передать три аргумента командной строки (день, "
           "месяц, год).\n");
    return 1;
  }

  int day = atoi(argv[1]);
  int month = atoi(argv[2]);
  int year = atoi(argv[3]);

  int days = daysSince1970(day, month, year);

  printf("Количество дней с 1 января 1970 года до %i/%i/%i: %i\n", day, month,
         year, days);

  return 0;
}