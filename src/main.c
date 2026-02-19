/**
 * @file main.c
 * @brief Главный модуль программы для работы со студентами
 * @author Козлов Максим
 */
#include <stdio.h>
#include "student.h"

int main() {
    STUDENT group[GROUP_SIZE];
    
    printf("========================================\n");
    printf("РАБОТА СО СТРУКТУРОЙ STUDENT\n");
    printf("Вариант 25 (Задача 3)\n");
    printf("========================================\n");
    
    // Ввод данных
    inputStudents(group, GROUP_SIZE);
    
    // Сортировка по алфавиту
    sortStudentsByName(group, GROUP_SIZE);
    
    // Вывод упорядоченного списка
    printf("\n--- Отсортированный список студентов ---\n");
    for (int i = 0; i < GROUP_SIZE; i++) {
        printf("%d. %s, Курс %d\n", i + 1, group[i].Name, group[i].Kurs);
    }
    
    // Вычисление общего среднего балла
    double groupAvg = calculateGroupAverage(group, GROUP_SIZE);
    printf("\nОбщий средний балл группы: %.2f\n", groupAvg);
    
    // Вывод студентов с баллом выше среднего
    printAboveAverage(group, GROUP_SIZE, groupAvg);

    printf("========================================\n");
    return 0;
}
