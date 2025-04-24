#include "inverted_search.h"


Status update_list(Slist **head,Slist **file,Slist **list)
{
	Slist *h_temp=*head;
	int flag=0;
	while(h_temp!=NULL)
	{
		flag=0;
		Slist *f_temp=*file;
		while(f_temp!=NULL)
		{
			if(strcmp(h_temp->filename,f_temp->filename)==0)
			{
				flag=1;
				break;	
			}
			f_temp=f_temp->link;
		}
		if(flag==0)
		{
			Slist *new=malloc(sizeof(Slist));
			if(new==NULL)
				return e_failure;
			new->filename=malloc(strlen(h_temp->filename)+1);
			strcpy(new->filename,h_temp->filename);
			new->link=NULL;
			if(*list==NULL)
			{
				*list=new;
			}
			else
			{
				Slist *temp=*list;
				while(temp->link!=NULL)
				{
					temp=temp->link;
				}
				temp->link=new;
			}
		}
		h_temp=h_temp->link;
	}
	Slist *l_temp=*list;
	while(l_temp)
	{
		l_temp=l_temp->link;
	}
	return e_success;
}
Status add_to_list(Slist **head,char *filename)
{
	Slist *new=malloc(sizeof(Slist));
	if(new==NULL)
	{
		return e_failure;
	}
	new->filename=malloc(sizeof(strlen(filename)));
	strcpy(new->filename,filename);
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
	}
	else
	{
		Slist *temp=*head;
		Slist *prev=NULL;
		while(temp!=NULL)
		{
			if(strcmp(temp->filename,filename)==0)
			{
				break;
			}
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)
		{
			prev->link=new;
		}
	}
}

