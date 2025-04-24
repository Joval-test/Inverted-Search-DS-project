#include "inverted_search.h"

Status display_database(Hash *table)
{
	int count=0;
	printf("INDEX\tWORD\tFILECOUNT\tFILENAME\tWORDCOUNT\n");
	for(int i=0;i<27;i++)
	{
		Main *m_tmp=table[i].link;
		while(m_tmp)
		{
			printf("%d\t",table[i].index);
			printf("%s\t",m_tmp->word);
			printf("%d\t\t",m_tmp->filecount);
			Sub *s_tmp=m_tmp->sub_link;
			while(s_tmp)
			{
				printf("%s\t\t",s_tmp->filename);
				printf("%d\t\t",s_tmp->wordcount);
				s_tmp=s_tmp->sublink;
			}
			m_tmp=m_tmp->mainlink;
			printf("\n");
			count++;
		}
	}
	printf("\n");
	if(count==0)
	{
		return e_failure;
	}
	return e_success;
}

