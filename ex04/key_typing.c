#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	time_t start_time, end_time;
	float result;
	char round[3][30] = {{"Show me The Money"},
			   {"123456789"},
			   {"Korea"}
	};
	char input[3][30];
	system("clear");
	int i, j, msg_len, input_len, longer_len, total, chk=0;
        char c;
       
       	start_time = time(NULL);
        for(i=0; i<3; i++) {
                puts(round[i]);
                scanf("%[^\n]s", input[i]);     
                msg_len = strlen(round[i]);
                input_len = strlen(input[i]);
                printf("origin words : %d, typing words : %d\n", msg_len, input_len);
                total += input_len;

                if(msg_len > input_len) longer_len = msg_len;
                else if(msg_len <= input_len) longer_len = input_len;

                for(j=0; j<longer_len; j++) {
                        if(round[i][j] != input[i][j]) chk++;
                }
                printf("오타수 : %d\n", chk);
                chk=0;
                printf("press enter...\n\n\n");
                getchar();
        }
        end_time = time(NULL);
        result = (float)(end_time - start_time);
        printf("avg %.2fmin.\n", result/3);
        printf("typing speed %.2fta\n", ((60/result)*total)/60);
}
