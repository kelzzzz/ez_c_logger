#ifndef EZ_LOGGER_H
#define EZ_LOGGER_H

extern int ez_log_is_ansi; 

#define INFO(...) ezlog(LOG_INFO, __func__, __LINE__, __VA_ARGS__)
#define WARN(...) ezlog(LOG_WARN, __func__, __LINE__, __VA_ARGS__)
#define ERR(...) ezlog(LOG_ERR, __func__, __LINE__, __VA_ARGS__)
#define DEBUG(...) ezlog(LOG_DEBUG, __func__, __LINE__, __VA_ARGS__)

#define SET_LOG_COLOR(flag) (ez_log_is_ansi = flag)

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERR,
    LOG_DEBUG,
    LOG_COUNT
} LOG_LEVEL;

void ezlog(LOG_LEVEL level, const char * funct, int line, const char * msg, ...);
void get_time();
void print_time();

#endif