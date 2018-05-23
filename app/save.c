/**
 * save.c -- функция сохранения
 * 
 * Copyright (c) 2017, Masaeva Olga <masaeva@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"
//сохраняем содержимое в файл
void save(text txt, char *filename)
{
    FILE *f;
    if((f=fopen(filename,"w"))==NULL)
    {
	printf("file can't be opened");
	return;
    }
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    //каждую строку теста сохраняем в файле
    while (current) {
	fprintf(f,"%s",current->contents);
	current = current->next;
    }
	fclose(f);
}
