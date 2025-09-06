#include <stdarg.h>
#ifndef S21_STRING_H
#define S21_STRING_H
#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;
typedef struct specifier_parameters {
  int minus;
  int plus;
  int space;
  int hashtag;
  int zero;
  int number;
  int asterisk;
  int point;
  long int point_number;
  int h;
  int l;
  int L;
  char type;
} specifier_parameters;

void s21_clear_string(char *massive);
s21_size_t s21_strlen(const char *massive);
void s21_strcpy(char *massive_1, char *massive_2);
void s21_strcat(char *massive_1, char *massive_2);
char *s21_strchr(const char *massive_1, int char_1);
char *s21_strstr(const char *massive_1, const char *massive_2);
char *s21_strtok(char *massive_1, const char *massive_2);
void *s21_memchr(const void *massive_1, int char_1, s21_size_t number_of_bytes);
int s21_memcmp(const void *massive_1, const void *massive_2,
               s21_size_t number_of_bytes);
void *s21_memcpy(void *massive_1, const void *massive_2,
                 s21_size_t number_of_bytes);
void *s21_memset(void *massive_1, int char_1, s21_size_t number_of_bytes);
char *s21_strpbrk(const char *massive_1, const char *massive_2);
char *s21_strrchr(const char *massive_1, int char_1);
char *s21_strerror(int number);
char *s21_strncat(char *massive_1, char *massive_2, int number);
int s21_strncmp(char *massive_1, char *massive_2, int number);
char *s21_strncpy(char *massive_1, char *massive_2, int number);
s21_size_t s21_strcspn(char *massive_1, char *massive_2);

int s21_sprintf(char *buffer, char *format, ...);
void s21_reset_parameters(specifier_parameters *parameters);
int s21_search_length(char *format, int *i);
void s21_out_parameters(specifier_parameters parameters);
void s21_search_parameters(specifier_parameters *parameters, char *format,
                           int *i);
int s21_search_specifier_type(char specifier, specifier_parameters *parameters);
void s21_sprintf_int(char *massive, specifier_parameters flags,
                     long int number);
void s21_sprintf_int_before_after(specifier_parameters flags, char *massive,
                                  long int number, int before_after);
int s21_number_lenght(long int number);
void s21_int_to_string(long int number, char *massive, int number_length,
                       int decimal);
int s21_before_number(int spase, int plus_minus, char *pointer,
                      long int number);
void s21_sprintf_string(char *massive, specifier_parameters flags,
                        char *string);
int s21_equalizer(specifier_parameters flags, int number_length, char *pointer);
void s21_sprintf_str_before_after(specifier_parameters flags, char *massive,
                                  char *string, int before_after);
void s21_sprintf_float(char *massive, specifier_parameters flags,
                       double number);
void s21_sprintf_flo_before_after(specifier_parameters flags, char *massive,
                                  double number, int before_after);
void s21_if_previous_more_than_4(char *pointer, int number);
void s21_format_float_to_e(double decimal, specifier_parameters parametr,
                           char *result);
long int s21_float_to_int(double number);
void s21_int_to_sixteen(long int number, char *massive,
                        specifier_parameters parametr);
void s21_ten_to_A(char *massive, char type);
void s21_int_to_eight(long int number, char *massive,
                      specifier_parameters parameters);
void s21_pointer_to_string(char *massive, void *pointer);
int s21_hashtag(specifier_parameters parameters, char *massive);
int s21_check_next_n(char *massive, int number);
void s21_trim_string(char *massive, specifier_parameters parameters);

int s21_sscanf(char *buffer, char *format, ...);
int s21_get_buffer_string(specifier_parameters parameters, char *pointer,
                          char *massive);
int s21_string_to_int(char *massive);
long double s21_string_to_float(char *massive);
long unsigned int s21_sixteen_to_int(char *massive);
long unsigned int s21_eight_to_int(char *massive);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

char *s21_sprintf_c_branch(specifier_parameters parameters, char *long_char,
                           char *buffer_pointer, ...);
char *s21_sprintf_d_branch(specifier_parameters parameters,
                           long int chosen_number, char *buffer_pointer, ...);
char *s21_sprintf_f_branch(specifier_parameters parameters,
                           long double chosen_float, char *buffer_pointer);
char *s21_sprintf_s_branch(specifier_parameters parameters, void *string,
                           char *buffer_pointer);
char *s21_sprintf_u_branch(specifier_parameters parameters,
                           long int chosen_number, char *buffer_pointer, ...);
char *s21_sprintf_eE_branch(specifier_parameters parameters,
                            long double e_param, char *buffer_pointer);
char *s21_sprintf_xX_branch(specifier_parameters parameters,
                            char *buffer_pointer, ...);
char *s21_sprintf_o_branch(specifier_parameters parameters,
                           char *buffer_pointer, ...);
char *s21_sprintf_p_branch(specifier_parameters parameters,
                           char *buffer_pointer, ...);
char *s21_sprintf_gG_branch(specifier_parameters parameters,
                            long double chosen_float, char *buffer_pointer);
char *s21_all_branches(char *buffer_pointer, long int chosen_number,
                       specifier_parameters parameters, ...);
void s21_sprintf_flo_before_after_branch_1(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length);
void s21_sprintf_flo_before_after_branch_2(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length);
void s21_sprintf_flo_before_after_branch_3(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length);
void s21_format_float_to_e_branch_1(double abs_decimal, int shift_number,
                                    specifier_parameters parametr,
                                    char *pointer, char *string_decimal,
                                    char *string_shift, long int copy_decimal);
int s21_get_buffer_string_branch_1(specifier_parameters parameters,
                                   char *pointer, char *massive, int result);
int s21_get_buffer_string_branch_2(specifier_parameters parameters,
                                   char *pointer, char *massive, int result);
void s21_sscanf_branch_sc(char *temp_string, int *d_adress,
                          specifier_parameters parameters, ...);
void s21_sprintf_branch_top(specifier_parameters *parameters, char *format,
                            int *i, long int *unexpected_type);
void s21_shorten_string(char *massive, specifier_parameters parameters);
void s21_null_adder(char *massive, specifier_parameters parameters,
                    int decimals);
long double s21_check_L_parametr(specifier_parameters parameters,
                                 va_list specifier_arg);
void s21_sscanf_get_p_adress(void **p_adress, va_list specifier_arg,
                             char temp_string[10000]);

#if defined(__APPLE__)
#define MAX_ERRNUM 107
#define MIN_ERRNUM -1
#define BASIC_ERROR "Unknown error: "

static char *maserror[] = {"Undefined error: 0",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "Device not configured",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource deadlock avoided",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Resource busy",
                           "File exists",
                           "Cross-device link",
                           "Operation not supported by device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Result too large",
                           "Resource temporarily unavailable",
                           "Operation now in progress",
                           "Operation already in progress",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol family",
                           "Address already in use",
                           "Can't assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Socket is already connected",
                           "Socket is not connected",
                           "Can't send after socket shutdown",
                           "Too many references: can't splice",
                           "Operation timed out",
                           "Connection refused",
                           "Too many levels of symbolic links",
                           "File name too long",
                           "Host is down",
                           "No route to host",
                           "Directory not empty",
                           "Too many processes",
                           "Too many users",
                           "Disc quota exceeded",
                           "Stale NFS file handle",
                           "Too many levels of remote in path",
                           "RPC struct is bad",
                           "RPC version wrong",
                           "RPC prog. not avail",
                           "Program version wrong",
                           "Bad procedure for program",
                           "No locks available",
                           "Function not implemented",
                           "Inappropriate file type or format",
                           "Authentication error",
                           "Need authenticator",
                           "Device power is off",
                           "Device error",
                           "Value too large to be stored in data type",
                           "Bad executable (or shared library)",
                           "Bad CPU type in executable",
                           "Shared library version mismatch",
                           "Malformed Mach-o file",
                           "Operation canceled",
                           "Identifier removed",
                           "No message of desired type",
                           "Illegal byte sequence",
                           "Attribute not found",
                           "Bad message",
                           "EMULTIHOP (Reserved)",
                           "No message available on STREAM",
                           "ENOLINK (Reserved)",
                           "No STREAM resources",
                           "Not a STREAM",
                           "Protocol error",
                           "STREAM ioctl timeout",
                           "Operation not supported on socket",
                           "Policy not found",
                           "State not recoverable",
                           "Previous owner died",
                           "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_ERRNUM 134
#define MIN_ERRNUM -1
#define BASIC_ERROR "Unknown error "

static char *maserror[] = {"Success",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "No such device or address",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource temporarily unavailable",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Device or resource busy",
                           "File exists",
                           "Invalid cross-device link",
                           "No such device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Numerical result out of range",
                           "Resource deadlock avoided",
                           "File name too long",
                           "No locks available",
                           "Function not implemented",
                           "Directory not empty",
                           "Too many levels of symbolic links",
                           "Unknown error 41",
                           "No message of desired type",
                           "Identifier removed",
                           "Channel number out of range",
                           "Level 2 not synchronized",
                           "Level 3 halted",
                           "Level 3 reset",
                           "Link number out of range",
                           "Protocol driver not attached",
                           "No CSI structure available",
                           "Level 2 halted",
                           "Invalid exchange",
                           "Invalid request descriptor",
                           "Exchange full",
                           "No anode",
                           "Invalid request code",
                           "Invalid slot",
                           "Unknown error 58",
                           "Bad font file format",
                           "Device not a stream",
                           "No data available",
                           "Timer expired",
                           "Out of streams resources",
                           "Machine is not on the network",
                           "Package not installed",
                           "Object is remote",
                           "Link has been severed",
                           "Advertise error",
                           "Srmount error",
                           "Communication error on send",
                           "Protocol error",
                           "Multihop attempted",
                           "RFS specific error",
                           "Bad message",
                           "Value too large for defined data type",
                           "Name not unique on network",
                           "File descriptor in bad state",
                           "Remote address changed",
                           "Can not access a needed shared library",
                           "Accessing a corrupted shared library",
                           ".lib section in a.out corrupted",
                           "Attempting to link in too many shared libraries",
                           "Cannot exec a shared library directly",
                           "Invalid or incomplete multibyte or wide character",
                           "Interrupted system call should be restarted",
                           "Streams pipe error",
                           "Too many users",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol",
                           "Address already in use",
                           "Cannot assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Transport endpoint is already connected",
                           "Transport endpoint is not connected",
                           "Cannot send after transport endpoint shutdown",
                           "Too many references: cannot splice",
                           "Connection timed out",
                           "Connection refused",
                           "Host is down",
                           "No route to host",
                           "Operation already in progress",
                           "Operation now in progress",
                           "Stale file handle",
                           "Structure needs cleaning",
                           "Not a XENIX named type file",
                           "No XENIX semaphores available",
                           "Is a named type file",
                           "Remote I/O error",
                           "Disk quota exceeded",
                           "No medium found",
                           "Wrong medium type",
                           "Operation canceled",
                           "Required key not available",
                           "Key has expired",
                           "Key has been revoked",
                           "Key was rejected by service",
                           "Owner died",
                           "State not recoverable",
                           "Operation not possible due to RF-kill",
                           "Memory page has hardware error"};
#endif

#endif
