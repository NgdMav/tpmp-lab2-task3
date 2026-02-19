/**
 * @file student.h
 * @brief Заголовочный файл для работы со структурой STUDENT
 * @version 1.0
 * @date 2026-02-19
 * @author Козлов Максим
 */
#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5
#define GROUP_SIZE 10
#define NAME_LEN 50

/**
 * @struct STUDENT
 * @brief Структура для хранения данных о студенте
 * 
 * @var STUDENT::Name - Фамилия и инициалы
 * @var STUDENT::Kurs - Номер курса
 * @var STUDENT::SES - Массив успеваемости по 5 предметам
 */
typedef struct {
    char Name[NAME_LEN];
    int Kurs;
    int SES[SUBJECTS];
} STUDENT;

/**
 * @brief Вводит данные о студентах с клавиатуры
 * @param students Указатель на массив структур STUDENT
 * @param count Количество студентов для ввода
 */
void inputStudents(STUDENT *students, int count);

/**
 * @brief Сортирует массив студентов по алфавиту (фамилии)
 * @param students Указатель на массив структур STUDENT
 * @param count Количество студентов
 */
void sortStudentsByName(STUDENT *students, int count);

/**
 * @brief Вычисляет средний балл для одного студента
 * @param student Указатель на структуру STUDENT
 * @return Средний балл (тип double)
 */
double calculateAverage(const STUDENT *student);

/**
 * @brief Вычисляет общий средний балл всей группы
 * @param students Указатель на массив структур STUDENT
 * @param count Количество студентов
 * @return Общий средний балл группы
 */
double calculateGroupAverage(const STUDENT *students, int count);

/**
 * @brief Выводит студентов, чей средний балл выше общего среднего
 * @param students Указатель на массив структур STUDENT
 * @param count Количество студентов
 * @param groupAvg Общий средний балл группы
 */
void printAboveAverage(const STUDENT *students, int count, double groupAvg);

#endif // STUDENT_H
