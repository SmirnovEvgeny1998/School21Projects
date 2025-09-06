#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H
/**
 \file
 @author burnerwa
 @version 1.0
 @date 04.08.2025
 */
/**
 @brief Структура для счета дат в депозитах
 */
typedef struct {
  int day;
  int month;
  int year;
  int month_days[12];
} s21_date;

/**
 @brief Структура для дополнительных пополнений в депозитах
 */
typedef struct {
  double summ;
  int day;
  int month;
  int year;
  int last;
} s21_repelishments;

/**
 @brief Структура для частичных снятий в депозитах
 */
typedef struct {
  double summ;
  int day;
  int month;
  int year;
  int last;
} s21_widrawls;

/**
 @class s21_addition
 @brief Сумма
 */
double s21_addition(double i_1, double i_2);

/**
 @class s21_substraction
 @brief Вычитание
 */
double s21_substraction(double i_1, double i_2);

/**
 @class s21_multiplication
 @brief Умножение
 */
double s21_multiplication(double i_1, double i_2);

/**
 @class s21_division
 @brief Деление
 */
double s21_division(double i_1, double i_2);

/**
 @class s21_power
 @brief Степень
 */
double s21_power(double i_1, double i_2);

/**
 @class s21_module
 @brief Деление по модулю
 */
double s21_module(double i_1, double i_2);

/**
 @class s21_sinus
 @brief Синус
 */
double s21_sinus(double i_1);

/**
 @class s21_cosinus
 @brief Косинус
 */
double s21_cosinus(double i_1);

/**
 @class s21_tangience
 @brief Тангиенс
 */
double s21_tangience(double i_1);

/**
 @class s21_arcsinus
 @brief Арксинус
 */
double s21_arcsinus(double i_1);

/**
 @class s21_arccosinus
 @brief Арккосинус
 */
double s21_arccosinus(double i_1);

/**
 @class s21_arctangience
 @brief Арктангиенс
 */
double s21_arctangience(double i_1);

/**
 @class s21_sqrt
 @brief Квадратный корень
 */
double s21_sqrt(double i_1);

/**
 @class s21_nat_log
 @brief Натуральный логарифм
 */
double s21_nat_log(double i_1);

/**
 @class s21_common_log
 @brief Общий логарифм
 */
double s21_common_log(double i_1);

/**
 @class s21_error_in_brackets
 @brief Проверка правильной постановки скобок в инфиксной форме
 */
int s21_error_in_brackets(char *string);
/**
 @class s21_string_to_djicstra
 @brief Перевод инфиксной формы в обратную польскую нотацию
 */
void s21_string_to_djicstra(char *string, char *result);
/**
 @class s21_string_to_djicstra_branch_1
 @brief Ветвь функции s21_string_to_djicstra
 */
void s21_string_to_djicstra_branch_1(char *string, char *temp, char *djicstra,
                                     int i);
/**
 @class s21_string_to_djicstra_branch_2
 @brief Ветвь функции s21_string_to_djicstra
 */
void s21_string_to_djicstra_branch_2(char *string, char *temp, char *djicstra,
                                     int *i, int len_2, char *buffer);
/**
 @class s21_string_to_djicstra_branch_3
 @brief Ветвь функции s21_string_to_djicstra
 */
void s21_string_to_djicstra_branch_3(char *string, char *temp, char *djicstra,
                                     int *i, int len_2, char *buffer);
/**
 @class s21_take_last_sign
 @brief Получает из конца string_2 последний знак и переносит его в конец
 string_1
 */
void s21_take_last_sign(char *string_1, char *string_2);
/**
 @class s21_calculation
 @brief Вычисление в виде обратной польской нотации
 */
double s21_calculation(char *string);
/**
 @class s21_calculation_branch_1
 @brief Ветвь функции s21_calculation
 */
void s21_calculation_branch_1(char *i_copy, char *copy, char *pointer,
                              double *result, int counter);
/**
 @class s21_calculation_branch_2
 @brief Ветвь функции s21_calculation
 */
void s21_calculation_branch_2(char *i_copy, char *copy, char *pointer,
                              double *result, int counter, double *f_one,
                              double *f_two);
/**
 @class s21_three_numbers_in_row
 @brief Проверка на количество чисел идущих подряд в обратной польской нотации
 @details Функция возвращает единицу в случае если подряд идут 3 числа либо 2
 числа и третьим идет функия для одного операнда, возвращает 0 в случае ошибки
 вычисления, возвращет -1 когда впереди одно число, возвращает -2 когда впереди
 два числа
 */
int s21_three_numbers_in_row(char *string);
/**
 @class s21_calculate_x
 @brief Переводит х в поданное число внутри поданой строки
 */
double s21_calculate_x(char *string, char *number);
/**
 @class s21_count_spaces
 @brief Считает количество пробелов в строке
 */
int s21_count_spaces(char *string);
/**
 @class s21_point_number
 @brief Переводит число в виде строки в интовую форму
 */
int s21_point_number(char *string);
/**
 @class s21_correctness
 @brief Проверка на корректный ввод данных в функцию s21_string_to_djicstra
 */
int s21_correctness(char *string);
/**
 @class s21_only_number
 @brief Проверка на то что в строке присутствуют только цифры и точки
 */
int s21_only_number(char *string);
/**
 @class s21_calculation_one_number
 @brief Переводит поданное число в форме строки в форму double
 */
double s21_calculation_one_number(char *string);
/**
 @class s21_check_if_only_znaks_and_not_pm_in_the_beginning
 @brief Проверка правильности в первом символе строки для вычисления
 */
int s21_check_if_only_znaks_and_not_pm_in_the_beginning(char *string);
/**
 @class s21_check_points
 @brief Проверка на корректное использование точек в уравнении
 */
int s21_check_points(char *string);
/**
 @class s21_check_bracket_after_sin
 @brief Проверка на корректное использование скобок в уравнении
 */
int s21_check_bracket_after_sin(char *string);
/**
 @class s21_check_step_width_heigth
 @brief Проверка на корректный ввод данных в показатели системы координат
 */
int s21_check_step_width_heigth(char *string);
/**
 @class s21_bank_annuitent_montly_payment
 @brief Вычисление кредита аннуитентного типа: ежемесячные платежи
 */
double s21_bank_annuitent_montly_payment(double credit_summ, int length_month,
                                         double percent);
/**
 @class s21_bank_annuitent_overpayment
 @brief Вычисление кредита аннуитентного типа: переплата
 */
double s21_bank_annuitent_overpayment(double credit_summ, int length_month,
                                      double percent);
/**
 @class s21_bank_annuitent_all_payment
 @brief Вычисление кредита аннуитентного типа: выплаченные за все время деньги
 */
double s21_bank_annuitent_all_payment(double credit_summ, int length_month,
                                      double percent);
/**
 @class s21_bank_differential_montly_payment_first
 @brief Вычисление кредита дифферентного типа: ежемесячные платежи первый платеж
 */
double s21_bank_differential_montly_payment_first(double credit_summ,
                                                  int length_month,
                                                  double percent);
/**
 @class s21_bank_differential_montly_payment_last
 @brief Вычисление кредита дифферентного типа: ежемесячные платежи последний
 платеж
 */
double s21_bank_differential_montly_payment_last(double credit_summ,
                                                 int length_month,
                                                 double percent);
/**
 @class s21_bank_differential_overpayment
 @brief Вычисление кредита дифферентного типа: переплата
 */
double s21_bank_differential_overpayment(double credit_summ, int length_month,
                                         double percent);
/**
 @class s21_bank_differential_all_payment
 @brief Вычисление кредита дифферентного  типа: выплаченные за все время деньги
 */
double s21_bank_differential_all_payment(double credit_summ, int length_month,
                                         double percent);
/**
 @class s21_fullfiil_monts
 @brief Наполняет структуру типа s21_date значениями дней в соответствующих
 месяцах
 */
void s21_fullfiil_monts(s21_date *months);
/**
 @class s21_deposit_profitability_simple
 @brief Простые проценты с депозита(функция не используется)
 */
double s21_deposit_profitability_simple(double deposit_amount, int deposit_term,
                                        double interst, double tax);
/**
 @class s21_deposit_profitability_complex
 @brief Вычисление возвращемой депозитом суммы, налог с нее и сумму вклада к
 концу срока
 */
double s21_deposit_profitability_complex(
    int what_to_return, double deposit_amount, int deposit_term, double interst,
    double tax, int periodicity, int capitalization,
    s21_repelishments *repelishments, s21_widrawls *partial_widrawal,
    double bank_key_deposit);
/**
 @class s21_deposit_profitability_complex_branch_1
 @brief Ответвление от функции s21_deposit_profitability_complex
 */
void s21_deposit_profitability_complex_branch_1(
    int periodicity, double *month_percents, double *percents_this_year,
    double *result, int *month_counter, double *deposit_amount, double interst,
    s21_date current_date, double deposit_term, int capitalization);
/**
 @class s21_deposit_profitability_complex_branch_2
 @brief Ответвление от функции s21_deposit_profitability_complex
 */
void s21_deposit_profitability_complex_branch_2(
    int periodicity, int month_counter, int deposit_term, double *nalog_result,
    double tax, double result, double bank_key_deposit, s21_date current_date,
    s21_date end_date, double *last_year, double *percents_this_year);
/**
 @class s21_check_if_only_numbers
 @brief Проерка на то, что функция содержит только числа
 */
int s21_check_if_only_numbers(char *string, int mode);

/**
 @class s21_string_to_float
 @brief Преображает число в строковой форме в тип long double
*/
long double s21_string_to_float(char *massive);
/**
 @class s21_int_to_string
 @brief Преображает число int в строковую форму
 */
void s21_int_to_string(long int number, char *massive, int number_length);
/**
 @class s21_number_lenght
 @brief Вычисляет длинну числа
 */
int s21_number_lenght(long int number);

#endif
