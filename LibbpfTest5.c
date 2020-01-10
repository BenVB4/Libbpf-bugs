#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <asm/unistd.h>
#include <linux/bpf.h>
#include "bpf.h"
#include "libbpf2.h"
#include <errno.h>
#include "nlattr.h"
#include <linux/rtnetlink.h>


int main(int argc, char **argv){


typedef struct args{

    int one;
    int two;
    int maxtype;
    int len;
	bool b1;
	bool b2;
	bool b3;
	bool b4;
    int size;
    struct nlattr nl;

    struct nlattr head;
    struct libbpf_nla_policy policy;


} args_t;

args_t pta;




printf("Driver program for nlattr.c class\n");

printf("Opening the file\n");

FILE *fp;
fp = fopen(argv[1], "rb");
printf("File name is: %s\n", argv[1]);
printf("File was opened\n");
if(fread(&pta, sizeof(pta), 1, fp) != 1){
        printf("File not big enough\n");
        fclose(fp);
        return 0;
}







//printf("Calling libbpf_nla_dump_errormsg\n");
//libbpf_nla_dump_errormsg(&nlh);
//libbpf_nla_parse(struct nlattr *tb[], int maxtype, struct nlattr *head,
//             int len, struct libbpf_nla_policy *policy);



int size = 5;


if(pta.size > 0 && pta. size < 999999){
    size = pta.size;
}

struct nlattr tb[size];


for(int i = 0; i < size; i++){
    tb[i] = pta.nl;
}



struct nlattr head;
struct libbpf_nla_policy policy;

printf("Calling libbpf_nla_parse\n");

libbpf_nla_parse(&tb, pta.maxtype, &pta.head,
pta.len, &pta.policy);



printf("Test complete.\n");


return 0;
}
