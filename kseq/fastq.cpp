#include "fastq.h"
#include <stdio.h>
#include <string.h>
void count_cycle_base_num(char *s)
{
    int cnt=strlen(s);
    int base_num[4]={0};
    for(int i=0;i<cnt;i++)
		{
			switch (s[i])
			{
			case 'A':
				base_num[0]++;
				break;
			case 'T':
				base_num[1]++;
				break;
			case 'C':
				base_num[2]++;
				break;
			case 'G':
				base_num[3]++;
				break;
			default:
				break;
			}
		}
		printf("-----%d %d %d %d\n",base_num[0],base_num[1],base_num[2],base_num[3]);
}