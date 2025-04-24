#include "inverted_search.h"


Status create_database(Slist **head,Hash *table)
{
	//create hash table
	Slist *temp=*head;
	int size=0;
	while(temp!=NULL)
	{
		FILE *fptr=fopen(temp->filename,"r");
		if(fptr)
		{
			int flag=0;
			char word[100];
			while(fscanf(fptr,"%s",word)!=EOF)
			{
				int index=toupper(word[0])%65;
				if(index<0||index>25)
				{
					index=26;
				}
				if(table[index].link==NULL)
				{
					if(create_main_node(table,index,word,temp->filename)==e_failure)
						printf("Memory allocation of new node has failed\n");
				}
				else
				{
					Main *mtemp=table[index].link;
					int flag1=0;
					while(mtemp)
					{	
						if(!(strcmp(word,mtemp->word)))
						{
							flag=0;
							Sub *stemp=mtemp->sub_link;
							Sub *sub_pre=NULL;
							while(stemp)
							{
								if(!(strcmp(stemp->filename,temp->filename)))
								{
									stemp->wordcount++;
									flag=1;
									break;
								}
								sub_pre=stemp;
								stemp=stemp->sublink;
							}
							if(flag==0)
							{
								create_sub_node(mtemp,temp->filename);
								mtemp->filecount++;
							}
							flag1=1;
							break;
						}
						mtemp=mtemp->mainlink;
					}
					if(flag1==0)
					{
						create_main_node(table,index,word,temp->filename);
					}
				}
			}
		}
		temp=temp->link;
	}
}



Status create_main_node(Hash *table,int index,char *word,char *filename)
{
	Main *new=malloc(sizeof(Main));
	if(new==NULL)
		return e_failure;
	new->filecount=1;
	new->mainlink=NULL;
	new->word=malloc(sizeof(strlen(word)+1));
	strcpy(new->word,word);
	if(table[index].link==NULL)
	{
		table[index].link=new;
	}
	else
	{
		Main *mtmp=table[index].link;
		Main *pre=NULL;
		while(mtmp)
		{
			pre=mtmp;
			mtmp=mtmp->mainlink;
		}
		pre->mainlink=new;
	}
	if(create_sub_node(new,filename)==e_failure)
		printf("Memory allocation failed in sub node\n");
}
Status create_sub_node(Main *node,char *filename)
{
	Sub *new1=malloc(sizeof(Sub));
	if(new1==NULL)
		return e_failure;
	new1->wordcount=1;
	new1->filename=malloc(sizeof(strlen(filename)+1));
	strcpy(new1->filename,filename);
	new1->sublink=NULL;
	if(node->sub_link==NULL)
	{
		node->sub_link=new1;
	}
	else
	{
		Sub *stmp=node->sub_link;
		Sub *pr=NULL;
		while(stmp)
		{
			pr=stmp;
			stmp=stmp->sublink;
		}
		pr->sublink=new1;
	}
}







