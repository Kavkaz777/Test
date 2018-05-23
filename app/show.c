/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    int i;
    /* Применяем функцию show_line к каждой строке текста */
    process_forward_with_cursor( txt,show_line);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемый параметр */
    UNUSED(index);

    /* Выводим строку на экран */
    printf("%s", contents);
}
