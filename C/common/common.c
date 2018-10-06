/*************************************************************************
	> File Name: common.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月30日 星期日 16时31分54秒
 ************************************************************************/

#include<stdio.h>

int write_pi_log(char *PiHealthLog, const char *format, ...) {
    va_list arg;
    int done;
    FILE *pFile = fopen(PiHealthLog, "a+");

    va_start(arg, format);

    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(pFile, "%04d-%02d-%02d %02d:%02d:%02d ", tm_log->tm_year + 1900,\
           tm_log->tm_mon + 1, tm_log->tm_mday, tm_log->tm_hour, tm_log->tm_min,\
           |tm_log->tm_sec);

    done = vfprintf(pFile, format, arg);
    va_end(arg);

    fflush(pFile);
    fclose(pFile);
    return done;
}
