#ifndef REVERSE_H
#define REVERSE_H

#include "types.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *filename;
	struct node *link;
}Slist;

typedef struct hashtable
{
	int index;
	struct main_node *link;
}Hash;

typedef struct main_node
{
	int filecount;
	char *word;
	struct subnode *sub_link;
	struct main_node *mainlink;
}Main;

typedef struct subnode
{
	int wordcount;
	char *filename;
	struct subnode *sublink;
}Sub;

Status read_and_validate_args(int argc,char *argv[],Slist **head,Hash *table);
Status create_database(Slist **head,Hash *table);
Status create_main_node(Hash *table,int index,char *word,char *filename);
Status create_sub_node(Main *node,char *filename);
Status display_database(Hash *table);
Status search_database(Hash *table,char *word);
Status save_database(Hash *table,char *filename);
Status update_database(Hash *table,char *filename,Slist **head);
Status update_list(Slist **head,Slist **file,Slist **lsit);
Status add_to_list(Slist **head,char *filename);
#endif
