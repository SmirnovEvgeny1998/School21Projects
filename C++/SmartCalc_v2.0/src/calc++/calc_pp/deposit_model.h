#ifndef DEPOSIT_MODEL_H
#define DEPOSIT_MODEL_H

namespace s21 {

class deposit_controller {
 public:
  /**
          @brief Базовая инициализация
       */
  deposit_controller();

  /**
   @brief Структура для счета дат в депозитах
   */
  typedef struct {
    int day = 1;
    int month = 1;
    int year = 0;
    int month_days[12] = {0};
  } s21_date;

  /**
   @brief Структура для дополнительных пополнений в депозитах
   */
  typedef struct {
    double summ = 0;
    int day = 1;
    int month = 1;
    int year = 0;
    int last = 0;
  } s21_repelishments;

  /**
   @brief Структура для частичных снятий в депозитах
   */
  typedef struct {
    double summ = 0;
    int day = 1;
    int month = 1;
    int year = 0;
    int last = 0;
  } s21_widrawls;

  /**
      @brief Коплексный метод вычисления депозитов, высчитывающий несколько
     значений.
      @details Принимает код возврата int what_to_return 1 - полученные с вклада
     деньги, 2 - сумма налога. Вложенная сумма double, продолжительность
     депозита int, процентная ставка вклада double, налоговая ставка double, код
     периодичности выплат 0 - ежемесячные, 1 - раз в 3 месяца, 2 - раз в пол
     года, 3 - раз в год, 4 - по окончании периода. Код капитализации 0 - без
     капитализации, 1 - с капитализацией. Массив структур содержащий пополнения
     вклада, массив структур содержащий изъятия с вклада, ключевая ставка ЦБ
     double
      @return Возвращает полученные с вклада деньги или вычтенные налогом деньги
     в зависимости от поданного кода.
      @param what_to_return Код возврата 1 - полученные с вклада деньги, 2 -
     сумма налога.
      @param deposit_amount Вложенная сумма.
      @param deposit_term Продолжительность депозита.
      @param interst Процентная ставка.
      @param tax Налоговая ставка.
      @param periodicity Код периодичности выплат 0 - ежемесячные, 1 - раз в 3
     месяца, 2 - раз в пол года, 3 - раз в год, 4 - по окончании периода.
      @param capitalization Код капитализации 0 - без капитализации, 1 - с
     капитализацией.
      @param repelishments Массив структур содержащий пополнения вклада.
      @param partial_widrawal Массив структур содержащий изъятия с вклада.
      @param bank_key_deposit Ключевая ставка ЦБ.
   */
  static double s21_deposit_profitability_complex(
      int what_to_return, double deposit_amount, int deposit_term,
      double interst, double tax, int periodicity, int capitalization,
      s21_repelishments *repelishments, s21_widrawls *partial_widrawal,
      double bank_key_deposit);

  /**
      @brief Ветвь коплексного метода вычисления депозитов
     s21_deposit_profitability_complex.
      @details Принимает код периодичности выплат 0 - ежемесячные, 1 - раз в 3
     месяца, 2 - раз в пол года, 3 - раз в год, 4 - по окончании периода.
     Указатель double на число полученных процентов в этом месяце, Указатель
     double на число полученных процентов в этом году, ссылка на итоговый
     результат из метода s21_deposit_profitability_complex, указатель на счетчик
     прошедших месяцев int, указатель на сумму депозита double, процентная
     ставка вклада double, "нынешняя" дата в вычислениях использующаяся для
     рассчета времени, продолжительность депозита int, код капитализации 0 - без
     капитализации, 1 - с капитализацией
      @return Возвращает сумму ежемесячной выплаты кредита аннуитентной формы.
      @param periodicity Код периодичности выплат 0 - ежемесячные, 1 - раз в 3
     месяца, 2 - раз в пол года, 3 - раз в год, 4 - по окончании периода.
      @param month_percents Указатель double на число полученных процентов в
     этом месяце.
      @param percents_this_year Указатель double на число полученных процентов в
     этом году.
      @param result Ссылка на итоговый результат из метода
     s21_deposit_profitability_complex.
      @param month_counter Указатель на счетчик прошедших месяцев.
      @param deposit_amount Вложенная сумма.
      @param interst Процентная ставка.
      @param current_date "Нынешняя" дата в вычислениях использующаяся для
     рассчета времени.
      @param deposit_term Продолжительность депозита.
      @param capitalization Код капитализации 0 - без капитализации, 1 - с
     капитализацией.
   */
  static void s21_deposit_profitability_complex_branch_1(
      int periodicity, double *month_percents, double *percents_this_year,
      double *result, int *month_counter, double *deposit_amount,
      double interst, s21_date current_date, double deposit_term,
      int capitalization);

  /**
      @brief Ветвь коплексного метода вычисления депозитов
     s21_deposit_profitability_complex.
      @return Возвращает сумму ежемесячной выплаты кредита аннуитентной формы.
      @param periodicity Код периодичности выплат 0 - ежемесячные, 1 - раз в 3
     месяца, 2 - раз в пол года, 3 - раз в год, 4 - по окончании периода.
      @param month_counter Указатель на счетчик прошедших месяцев.
      @param deposit_term Продолжительность депозита.
      @param nalog_result Ссылка на налоговый результат из метода
     s21_deposit_profitability_complex.
      @param tax Налоговая ставка.
      @param result Итоговый результат вычтенных налогов.
      @param bank_key_deposit Ключевая ставка ЦБ.
      @param current_date "Нынешняя" дата в вычислениях использующаяся для
     рассчета времени.
      @param end_date Дата окончания депозита.
      @param last_year Проценты полученные за прошлый год.
      @param percents_this_year Проценты полученные в этом году.
   */
  static void s21_deposit_profitability_complex_branch_2(
      int periodicity, int month_counter, int deposit_term,
      double *nalog_result, double tax, double result, double bank_key_deposit,
      s21_date current_date, s21_date end_date, double *last_year,
      double *percents_this_year);
  /**
      @brief Заполняет тип данных s21_date.
      @param months Структура месяцев для заполнения.
   */
  static void s21_fullfiil_monts(s21_date *months);
};

};  // namespace s21

#endif  // DEPOSIT_MODEL_H
