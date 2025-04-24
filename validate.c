#include <stdio.h>
#include <string.h>
#include "inverted_search.h"
#include <stdlib.h>

Status read_and_validate_args(int argc,char *argv[],Slist **head,Hash *table)
{
	FILE *file;
	long size;
	if(argc==1)
	{
		printf("INFO: NOT ENOUGH ARGUMENTS\n");
		return e_failure;
	}
	for(int i=0;i<27;i++)
	{
		table[i].index=i;
		table[i].link=NULL;
	}

	for(int i=1;i<argc;i++)
	{
		if(strcmp(strstr(argv[i],"."),".txt")==0)
		{
			file=fopen(argv[i],"r");
			if(file)
			{
				fseek(file,0,SEEK_END);
				size=ftell(file);
				if(size==0)
				{
					printf("WARNING: %s FILE EMPTY\n",argv[i]);
				}
				else
				{
					Slist *new=malloc(sizeof(Slist));
					if(new==NULL)
					{
						printf("WARNING:FAILED TO ALLOCATE MEMORY\n");
						return e_failure;
					}
					new->filename=argv[i];
					new->link=NULL;
					if(*head==NULL)
					{
						*head=new;
						printf("%s->",new->filename);
					}
					else
					{
						Slist *temp=*head;
						Slist *prev=NULL;
						while(temp!=NULL)
						{
							if(strcmp(temp->filename,argv[i])==0)
							{
								printf("WARNING:DUPLICATE FILE FOUND\n");
								break;
							}
							prev=temp;
							temp=temp->link;
						}
						if(temp==NULL)
						{
							prev->link=new;
							printf("%s->",new->filename);
						}
					}
				}
			}
		}
		else
		{
			printf("WARNING: ENTER FILENAME %s WITH PROPER FILE EXTENSION\n",argv[i]);
		}
	}
	printf("NULL\n");
	if(*head!=NULL)
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
}





