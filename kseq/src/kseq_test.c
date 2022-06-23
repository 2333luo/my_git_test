#include <zlib.h>
#include <stdio.h>
#include "fastq.h"
#include "kseq.h"
KSEQ_INIT(gzFile, gzread)

void seq_rever_h(char *str,int cnt);

int main(int argc, char *argv[])
{
	gzFile fp;
	kseq_t *seq;
	int l;
	if (argc == 1) {
		fprintf(stderr, "Usage: %s <in.seq>\n", argv[0]);
		return 1;
	}
	fp = gzopen(argv[1], "r");
	seq = kseq_init(fp);
	int cnt=0;
	int sum=0;
	int base_num[4]={0}; //A、T、C、G
	while ((l = kseq_read(seq)) >= 0) {
		printf("name: %s\n", seq->name.s);
		printf("seq: %s\n", seq->seq.s);
		cnt=strlen(seq->seq.s);
		seq_rever_h(seq->seq.s,cnt);
		sum+=cnt;
		printf("current_read_bases:%d\n",cnt);
		printf("total_bases:%d\n",sum);
		//count_cycle_base_num(seq->seq.s);
		if (seq->qual.l) printf("qual: %s\n", seq->qual.s);
	}
	printf("return value: %d\n", l);
	kseq_destroy(seq);
	gzclose(fp);
	return 0;
}
//序列的反转互补序列
void seq_rever_h(char *str,int cnt){
	char *dir = (char *)malloc(cnt*(sizeof(char)));
	int i=0;
	cnt--;
	for(i=0;cnt>=0;i++,cnt--)
	{
		switch(str[cnt])
		{
			case 'A':
				dir[i]='T';
				break;
			case 'T':
				dir[i]='A';
				break;
			case 'C':
				dir[i]='G';
				break;
			case 'G':
				dir[i]='C';
				break;
			default:
				break;				
		}
	}
	dir[i]='\0';
	printf("reverse_seq: %s\n", dir);
	free(dir);
}
