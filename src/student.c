/**
 * @file student.c
 * @brief Реализация функций для работы со структурой STUDENT
 * @author Козлов Максим
 */
#include <stdio.h>
#include <string.h>
#include "../include/student.h"

void inputStudents(STUDENT *students, int count) {
    printf("Ввод данных для %d студентов:\n", count);
    for (int i = 0; i < count; i++) {
        printf("\n--- Студент #%d ---\n", i + 1);
        printf("Фамилия и инициалы: ");
        fgets(students[i].Name, NAME_LEN, stdin);
        students[i].Name[strcspn(students[i].Name, "\n")] = 0;

        printf("Курс: ");
        scanf("%d", &students[i].Kurs);
        
        printf("Успеваемость (5 оценок через пробел): ");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].SES[j]);
        }
        getchar();
    }
}

void sortStudentsByName(STUDENT *students, int count) {
    STUDENT temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].Name, students[j].Name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

double calculateAverage(const STUDENT *student) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += student->SES[i];
    }
    return (double)sum / SUBJECTS;
}

double calculateGroupAverage(const STUDENT *students, int count) {
    double totalSum = 0.0;
    for (int i = 0; i < count; i++) {
        totalSum += calculateAverage(&students[i]);
    }
    return totalSum / count;
}

void printAboveAverage(const STUDENT *students, int count, double groupAvg) {
    printf("\n--- Студенты со средним баллом выше %.2f ---\n", groupAvg);
    int found = 0;
    for (int i = 0; i < count; i++) {
        double avg = calculateAverage(&students[i]);
        if (avg > groupAvg) {
            printf("%s, Курс %d, Средний балл: %.2f\n", 
                   students[i].Name, students[i].Kurs, avg);
            found = 1;
        }
    }
    if (!found) {
        printf("Таких студентов нет.\n");
    }
}
