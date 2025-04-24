#include "inverted_search.h"

Status search_database(Hash *table,char *word)
{
	int index = toupper(word[0])%65;
	if(index<0 || index>25)
	{
		index=26;
	}
	Main *temp=table[index].link;
	while(temp)
	{
		if(!(strcmp(temp->word,word)))
		{
			printf("INFO: DATA FOUND\n");
			printf("INDEX = %d\n",index);
			printf("WORD = %s\n",temp->word);
			printf("NUMBER OF FILES = %d\n",temp->filecount);
			Sub *tmp=temp->sub_link;
			int count=1;
			while(tmp)
			{
				printf("FILE NAME =%s\n",tmp->filename);
				printf("WORD COUNT = %d\n",tmp->wordcount);
				count++;
				tmp=tmp->sublink;
			}
			return e_success;
		}
		temp=temp->mainlink;
	}
	return e_failure;
}

