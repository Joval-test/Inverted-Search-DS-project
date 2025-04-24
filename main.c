#include <stdio.h>
#include <string.h>
#include "inverted_search.h"

int main(int argc,char *argv[])
{
	int flag=0;
	char filename[50];
	Slist *head = NULL;
	Slist *file = NULL;
	Slist *list = NULL;
	Hash table[27];
	if(read_and_validate_args(argc,argv,&head,table)==e_success)
	{
		printf("INFO: VALIDATION SUCCESSFULL\n");
		int option=0;
		int y=1;
		while(y)
		{
			printf("1.Create database\n2.Display database\n3.Search database\n4.Update database\n5.Save database\n6.Exit\nEnter your choice:");
			scanf("%d",&option);
			switch(option)
			{
				case 1:
					if(flag==0)
					{
						if(create_database(&head,table)==e_success)
						{
							flag=1;
							printf("INFO: DATA BASE CREATED SUCCESSFFULL\n");
						}
						else
						{
							printf("INFO: DATA BASE CREATION FAILED\n");
						}
					}
					else
					{
						if(update_list(&head,&file,&list)==e_success)
						{

							if(create_database(&list,table)==e_success)
							{
								printf("INFO: DATA BASE CREATED SUCCESSFFULL\n");
							}
							else
							{
								printf("INFO: DATA BASE CREATION FAILED\n");
							}
						}	
					}
						break;
						case 2:
						if(display_database(table)==e_success)
						{
							printf("INFO: DISPLAY SUCCESSFULL\n");
						}
						else
						{
							printf("INFO: DISPLAY FAILED\n");
						}
						break;
						case 3:
						char word[20];
						printf("Enter the word to be searched: ");
						scanf("%s",word);
						if(search_database(table,word)==e_success)
						{
							printf("INFO: SEARCH SUCCESSFUL\n");
						}
						else
						{
							printf("INFO: DATA NOT FOUND\n");
						}
						break;
						case 4:
						if(flag==0)
						{
							printf("Enter the backup file name : ");
							scanf("%s",filename);
							printf("%s\n",filename);
							if(update_database(table,filename,&file)==e_success)
							{
								flag=1;
								printf("INFO: UPDATE SUCCESSFULL\n");
							}
							else
							{
								printf("INFO: UPDATE FAILED\n");
							}
						}
						else
						{
							printf("INFO : UPDATE DATABASE BEFORE CREATING DATA BASE\n");
						}
						break;
						case 5:
						if(flag==0)
						{
							printf("WARNING: CREATE DATABASE BEFORE PROCEEDING\n");
						}
						else
						{
							printf("Enter the file name to be saved: \n");
							scanf("%s",filename);
							if(save_database(table,filename)==e_success)
							{
								printf("INFO: DATABASE SAVE SUCCESSFUL\n");
							}
							else
							{
								printf("INFO: DATABASE SAVE FAILED\n");
							}
						}break;
						case 6:
						y=0;
						break;

						default:
						{
							printf("INFO: INVALID OPTION\n");
						}
					}
			}
		}
		else
		{
			printf("INFO: VALIDATION FAILED\n");
		}
	}

