### ez C logger

A teeny tiny barebones C console logger, because I like having one. It provides a simple macro-based interface to capture timestamps, function names, and line numbers automatically and print them to the console.

#### Log Levels

| Level | Color |
| :--- | :--- |
| **INFO** | Green |
| **WARN** | Yellow |
| **ERR** | Red |
| **DEBUG** | Blue |

## Quick Start

### 1. Get the code
Either copy `ez_logger.c` and `ez_logger.h` into your project, or clone this project, run `make` in your preferred terminal, and link the library (`libezlogger.a`) when you compile with gcc, ex.,: `gcc main.c -L. -libezlogger -o your_app`.

### 2. Include the header
Include `ez_logger.h` in your source files.

### 3. Adjust configuration

Right now, the logger is mostly automatically configured. The adjustments to its behavior can be made directly with function calls. Right now, you may flag it to print in default console colors as opposed to its own color coding with:

`SET_LOG_COLOR(flag)` where it will be b&w when 0, and in color != 0.

### 4. Log messages
Use the provided macros (`INFO`, `WARN`, `ERR`, `DEBUG`) just like you would use `printf`.

```c
#include "ez_logger.h"

int main() {
    INFO("System initialized.");
    DEBUG("Variable x is %d", 42);
    ERR("Connection failed!");
    return 0;
}

Example Output: 

DEBUG:main:41[30/01/2026 : 23:21:56] Variable x is 42 (in blue)
```

### Todo
- [x] Variadic args
- [ ] Output to log file
- [ ] External configuration
- [ ] Customizable color coding
