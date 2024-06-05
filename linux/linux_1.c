#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 1){
        fprintf(stderr, "Insufficient arguments!\n");   // 인자(argument) 부족으로 인한 에러
        return -1;
    }

    if(unlink(argv[1]) == 0)                                             // 파일 삭제(unlink 이용)
        printf("unlink success!\n");
    else{
        perror("unlink fail!\n");
            
        if(remove(argv[1]) == 0)                                         // 빈 디렉토리 삭제(remove 이용)
            printf("remove success!\n");
        else{
            perror("remove fail!\n");
            return -1;
        }   
    }

    return 0;
}
