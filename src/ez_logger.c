/*MIT License

Copyright (c) 2026 kelzzzz @ github

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include "ez_logger.h"

#define log_ansi_color_info     "\x1b[32m"
#define log_ansi_color_warn     "\x1b[33m"
#define log_ansi_color_err      "\x1b[31m"
#define log_ansi_color_debug    "\x1b[34m"
#define log_ansi_reset          "\x1b[0m"

int ez_log_is_ansi = 1;

static time_t current_time;
static struct tm * local_time; 

const char * const type[LOG_COUNT] = {
    "INFO",
    "WARN",
    "ERR",
    "DEBUG"
}; 

const char * const colors[LOG_COUNT] = {
    log_ansi_color_info,
    log_ansi_color_warn,
    log_ansi_color_err,
    log_ansi_color_debug
};

void get_time() {
    time(&current_time);
    local_time = localtime(&current_time);
}

//format LEVEL:func:line [dd/mm/yyyy : hh:mm:s] msg
void ezlog(LOG_LEVEL level, const char * funct, int line, const char * msg, ...){
    va_list args;
    va_start(args, msg);
        if (level < 0 || level >= LOG_COUNT) return;
        if(ez_log_is_ansi){
            printf("%s", colors[level]);
        }
        printf("%s:", type[level]);
        printf("%s:", funct);
        printf("%d", line);
        print_time();
        vfprintf(stdout, msg, args);
        if(ez_log_is_ansi){
            printf("%s\n", log_ansi_reset);
        }
    va_end(args);
}

void print_time()
{
    get_time();
    printf("[%02d/%02d/%d : %02d:%02d:%02d] ", 
            local_time->tm_mday, 
            local_time->tm_mon + 1,
            local_time->tm_year + 1900, 
            local_time->tm_hour, 
            local_time->tm_min, 
            local_time->tm_sec);
}