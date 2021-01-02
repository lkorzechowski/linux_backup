#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void filename(char * array){
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        char czas[6][2];
        tm.tm_year -= 100;
        czas[0][0] = tm.tm_year/10 +'0';
        czas[0][1] = tm.tm_year%10 +'0';
        if(tm.tm_mon < 10){
                czas[1][0] = '0';
        } else {
                czas[1][0] = '1';
        }
        czas[1][1] = tm.tm_mon%10 +'1';
        if(tm.tm_mday < 10){
                czas[2][0] = '0';
        } else {
                czas[2][0] = tm.tm_mday/10 +'0';
        }
        czas[2][1] = tm.tm_mday%10 +'0';
        if(tm.tm_hour < 10){
                czas[3][0] = '0';
        } else {
                czas[3][0] = tm.tm_hour/10 +'0';
        }
        czas[3][1] = tm.tm_hour%10 +'0';
        if(tm.tm_min < 10){
                czas[4][0] = '0';
        } else {
                czas[4][0] = tm.tm_min/10 +'0';
        }
        czas[4][1] = tm.tm_min%10 +'0';
        if(tm.tm_sec < 10){
                czas[5][0] = '0';
        } else {
                czas[5][0] = tm.tm_sec/10 +'0';
        }
        czas[5][1] = tm.tm_sec%10 +'0';

        array[39] = czas[0][0]; array[40] = czas[0][1]; array[41] = '_';
        array[42] = czas[1][0]; array[43] = czas[1][1]; array[44] = '_';
        array[45] = czas[2][0]; array[46] = czas[2][1]; array[47] = '_';
        array[48] = czas[3][0]; array[49] = czas[3][1]; array[50] = '_';
        array[51] = czas[4][0]; array[52] = czas[4][1]; array[53] = '_';
        array[54] = czas[5][0]; array[55] = czas[5][1];
}

void print_str(const char * str){
        while(*str != '\0'){
                printf("%c", *str);
                str++;
        }
}

int main(int argc, char **argv){
        char command[512] = "dest=\"/mnt/archiwum_lokalne/archiwum_20";
        filename(command);
        strcat(command, ".tgz\"; \
                        sudo tar czf $dest /home/student/dane; \
                        echo \"Backup finished\"; \
                        arr=$(df /dev/sdb1); \
                        space=$(echo $arr | cut -d \" \" -f11;); \
                        cd /mnt/archiwum_lokalne; \
                        while [ $space -lt 30000 ]; \
                                do rm \"$(ls -t | tail -1)\"; \
                                echo \"freeing up space\"; \
                        done;");
        //print_str(command);
        system(command);

}
