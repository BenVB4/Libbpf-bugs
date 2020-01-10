#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <asm/unistd.h>
#include <linux/bpf.h>
#include "bpf.h"
//#include "libbpf2.h"
#include <errno.h>
#include "nlattr.h"
#include <linux/rtnetlink.h>
#include <sys/socket.h>
#include "libbpf.h"
#include <sys/types.h>  // for size_t


int main(int argc, char **argv){


typedef struct args{

int err;
char buf[100];
size_t size;
size_t offset;

int buffer[150];
int flags;

size_t obj_buf_sz;
char name;


char name1;
int rand1;
int rand2;
int rand3;
int rand4;
bool b1;

} args_t;

args_t pta;


/*
printf("Opening the file\n");

FILE *fp;
fp = fopen(argv[1], "rb");
printf("File name is: %s\n", argv[1]);
printf("File was opened\n");

struct bpf_object;
struct bpf_object *bo;

bo = bpf_object__open(argv[1]);

printf("Opening bpf Object with argv[1]\n");
bpf_object__open(argv[1]);

//bpf_object__open(argv[1]);
*/


struct bpf_object;
struct bpf_object *bo;

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


FILE *fp2;
fp2 = fopen(argv[2], "rb");
printf("File name is: %s\n", argv[2]);
printf("Second File was opened\n");
if(fread(&pta, sizeof(pta), 1, fp2) != 1){
        printf("File not big enough\n");
        fclose(fp2);
        return 0;
}


printf("\nOpening bpf object via: bpf_object__open_buffer()\n");
char name5 = "a";
size_t obj_buf_sz = 5;
bo = bpf_object__open_buffer(argv[1], pta.obj_buf_sz, &pta.name);
printf("Opened a bpf file with bpf_object__open_buffer()\n\n");


if (bo == NULL){

	printf("Returned: Invalid BPF_Prog\n");
	return 0;
}

printf("Calling methods that use the bpf objects");

bpf_object__load(&bo);

bpf_object__kversion(&bo);

bpf_object__btf(&bo);

bpf_object__btf_fd(&bo);

bpf_object__unload(&bo);












//enum bpf_prog_type prog_type = BPF_PROG_TYPE_TRACEPOINT;

fclose(fp);
fclose(fp2);

printf("Test complete. Opened a bpf_program.\n");


return 0;
}
