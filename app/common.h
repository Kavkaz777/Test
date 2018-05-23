/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

//переносит курсор в заданную строку с заданной позицией 
void move_cursore( text txt,int ind, int pos);

// вставляет заданную строку в заданную позицию
void paste( text txt, int num, char *t);

//выводит нечетные строки в обратном порядке
void showreveven( text txt);

//перенос курсора в первую позицию следующей строки
void move_cursor(text txt);

void reversed_process_forward(text txt, void (*process)(int index, char *contents));

		  
// сохраняет содержимое файла
void save( text txt, char*filename);
/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

#endif
