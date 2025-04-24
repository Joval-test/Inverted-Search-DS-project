#include "inverted_search.h"

Status save_database(Hash *table,char *filename)
{
	if(strcmp(strstr(filename,"."),".txt")==0)
	{
		FILE *fptr=fopen(filename,"w");
		if(fptr)
		{
			for(int i=0;i<27;i++)
			{
				Main *m_tmp=table[i].link;
				while(m_tmp)
				{
					fprintf(fptr,"#%d;%s;%d",i,m_tmp->word,m_tmp->filecount);
					Sub *s_tmp=m_tmp->sub_link;
					while(s_tmp)
					{
						fprintf(fptr,";%s;%d",s_tmp->filename,s_tmp->wordcount);
						s_tmp=s_tmp->sublink;
					}
					m_tmp=m_tmp->mainlink;
					fprintf(fptr,"#\n");
				}
			}
			return e_success;
		}
		else
		{
			printf("WARNING: FILE COULD NOT BE OPEN\n");
		}
	}
	else
	{
		printf("WARNING: NOT A .txt FILE");
		return e_failure;
	}
}

