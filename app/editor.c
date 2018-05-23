/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
	//функция сохраенения текста
	if(strcmp(cmd,"save") == 0){
	    if((arg = strtok(NULL, " \n")) == NULL)
		fprintf(stderr,"No file to save!!!\n");
	    else
                save(txt,arg);
            continue;
        }
	//функция переноса курсора в заданную позицию
	if(strcmp(cmd,"m") == 0){
	    char *arg1 = strtok(NULL, " \n");
	    char *arg2 = strtok(NULL, " \n") ;
	    int len = strtol(arg1,NULL, 10);
	    int pos = strtol(arg2,NULL, 10);
	    move_cursore( txt, len, pos);
	    continue;
	}
	
	//функция вставки строки
	
	if(strcmp(cmd,"p") == 0){
	    char *arg1 = strtok(NULL, " \n");
	    char *arg2 = strtok(NULL, " \n") ;
	    int num = strtol(arg1,NULL, 10);
	    paste(txt, num, arg2);
	    continue;
	}
	//функция вывода строк с нечетными номерами в обратном порядке
	if (strcmp(cmd, "showreveven") == 0) {
            showreveven(txt);
            continue;
        }
	
	//функция переноса курсора в следующую строку
	if (strcmp(cmd, "mnlb") == 0) {
            move_cursor(txt);
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
