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
#include "text/_text.h"

void move_cursore (text txt,int ind,int pos)
{
    struct _node *current = txt->begin;
    int index = 0;
    txt->cursor->position=pos;
    /* К каждой строке текста применяем обработчик */
    while (current) {
	if(index==ind)
	    txt->cursor->line=current;
        current = current->next;
        index++;
    }
}
