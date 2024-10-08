#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<string.h>
#include "common.h"
int main(int argc,char *argv[])
{
    if(argc>=3)
    {
        int op_type=check_operation_type(argv);
        if(op_type==e_encode)
        {
            EncodeInfo encInfo;
            printf("\033[1;32m<--------Encode started-------->\033[0m\n");
            if(read_and_validate_encode_args(argv,&encInfo)==e_success)
            {
                printf("\033[1;34mread and validate done\033[0m\n");
                if(do_encoding(&encInfo)==e_success)
                {
                    printf("\033[1;32m<--------Completed encoding-------->\033[0m\n");
                }
                else
                {
                    printf("Failed to encode\n");
                    return 0;
                }
            }
            else
            {
                printf("\033[1;31mread and validate not done\033[0m\n");
            }
        }
        else if(op_type==e_decode)
        {
            printf("\033[1;32mDecode started\033[0m\n");
        }
        else
        {
            printf("\033[1;31mInvalid option\nKindly pass\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\033[0m\n");
        }
    }
    else
    {
        printf("\033[1;31mError : Kindly pass\nEncoding: 4 arguments\nDecoding: 3 arguments\033[0m\n");
    }
    return 0;
}
OperationType check_operation_type(char *argv[])
{
    if(!(strcmp(argv[1],"-e")))
    return e_encode;
    else if(!(strcmp(argv[1],"-d")))
    return e_decode;
    else
    return e_unsupported;   
}


