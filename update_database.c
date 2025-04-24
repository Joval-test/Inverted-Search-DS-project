#include "inverted_search.h"


Status update_database(Hash *table, char *filename,Slist **head)
{
	if(strcmp(strstr(filename,"."),".txt")==0)
	{
		
		FILE *file=fopen(filename,"r");
		if(file)
		{
			char line[200];
    		while (fgets(line, sizeof(line), file)) 
			{
        		size_t len = strlen(line);
       			// Check for newline character
        		if (len > 0 && line[len - 1] == '\n') 
				{
            		// Line is complete
            		if (line[0] == '#' && line[len - 2] == '#') 
					{
						int index=atoi(strtok(&line[1],";"));
					
						if (table[index].link==NULL)
						{
							Main *temp=malloc(sizeof(Main));
							if(temp==NULL)
							{
								return e_failure;
							}
							temp->word=malloc(50);
							strcpy(temp->word,strtok(NULL,";"));
							temp->filecount=atoi(strtok(NULL,";"));
							temp->mainlink=NULL;
							Sub *s_prev=NULL;
							for(int i=0;i<temp->filecount;i++)
							{
								Sub *s_temp=malloc(sizeof(Sub));
								s_temp->filename=malloc(50);
								strcpy(s_temp->filename,strtok(NULL,";"));
								add_to_list(head,s_temp->filename);
								s_temp->wordcount=atoi(strtok(NULL,";"));
								s_temp->sublink=NULL;
								if(i==0)
								{
									temp->sub_link=s_temp;
								}
								else
								{
									s_prev->sublink=s_temp;
								}
								s_prev=s_temp;
							}
							table[index].link=temp;
						}
						else
						{
							Main *m_temp=table[index].link;
							while(m_temp->mainlink)
							{
								m_temp=m_temp->mainlink;
							}	
							Main *temp=malloc(sizeof(Main));
							if(temp==NULL)
							{
								return e_failure;
							}
							temp->word=malloc(50);
							strcpy(temp->word,strtok(NULL,";"));
							temp->filecount=atoi(strtok(NULL,";"));
							temp->mainlink=NULL;
							Sub *s_prev=NULL;
							for(int i=0;i<temp->filecount;i++)
							{
								Sub *s_temp=malloc(sizeof(Sub));
								s_temp->filename=malloc(50);
								strcpy(s_temp->filename,strtok(NULL,";"));
								s_temp->wordcount=atoi(strtok(NULL,";"));
								add_to_list(head,s_temp->filename);
								s_temp->sublink=NULL;
								if(i==0)
								{
									temp->sub_link=s_temp;
								}
								else
								{
									s_prev->sublink=s_temp;
								}
								s_prev=s_temp;
							}
							m_temp->mainlink=temp;
						}
					}
				}

			}
		}		
		else
		{
			printf("INFO:FAILED TO OPEN FILE\n");
		}
		
	}
	else
	{
		printf("WARNING: ENTER FILENAME WITH PROPER EXTENTION\n");
	}
}




