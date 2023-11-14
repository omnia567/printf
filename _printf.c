#include <stdarg.h>
#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            _putchar(*format);
            printed_chars++;
        } else {
            format++;
            if (*format == '\0') break;

            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    _putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        _putchar(*str);
                        str++;
                        printed_chars++;
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    printed_chars += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

