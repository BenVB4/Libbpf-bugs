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
	bool b1;
	bool b2;
	bool b3;
	bool b4;
	__u32 nlmsg_len;    /* Length of message including header */
    __u16 nlmsg_type;   /* Type of message content */
    __u16 nlmsg_flags;  /* Additional flags */
    __u32 nlmsg_seq;    /* Sequence number */
    __u32 nlmsg_pid;    /* Sender port ID */


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




struct nlmsghdr {
    __u32 nlmsg_len;    /* Length of message including header */
    __u16 nlmsg_type;   /* Type of message content */
    __u16 nlmsg_flags;  /* Additional flags */
    __u32 nlmsg_seq;    /* Sequence number */
    __u32 nlmsg_pid;    /* Sender port ID */
};


struct nlmsghdr nlh;
    nlh.nlmsg_len = pta.nlmsg_len;    /* Length of message including header */
    nlh.nlmsg_type = pta.nlmsg_type;   /* Type of message content */
    nlh.nlmsg_flags = pta.nlmsg_flags;  /* Additional flags */
    nlh.nlmsg_seq = pta.nlmsg_seq;    /* Sequence number */
    nlh.nlmsg_pid = pta.nlmsg_pid;    /* Sender port ID */

printf("Calling libbpf_nla_dump_errormsg\n");
libbpf_nla_dump_errormsg(&nlh);



printf("Test complete.\n");


return 0;
}
