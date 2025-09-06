#ifndef CREDIT_MODEL_H
#define CREDIT_MODEL_H

#include <math.h>

namespace s21 {

class credit_controller {
 public:
  /**
          @brief Базовая инициализация
       */
  credit_controller();

  /**
      @brief Метод вычисления ежемесячной оплаты в случае ануитентного типа
     кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает сумму ежемесячной выплаты кредита аннуитентной формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_annuitent_montly_payment(double credit_summ, int length_month,
                                           double percent);

  /**
      @brief Метод вычисления переплаты в случае ануитентного типа кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает сумму переплаты кредита аннуитентной формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_annuitent_overpayment(double credit_summ, int length_month,
                                        double percent);

  /**
      @brief Метод вычисления итоговой суммы кредита в случае ануитентного типа
     кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает итоговую суммы кредита аннуитентной формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_annuitent_all_payment(double credit_summ, int length_month,
                                        double percent);

  /**
      @brief Метод вычисления первой ежемесячной выплаты в случае
     дифференциального типа кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает первую ежемесячную выплату кредита дифференциальной
     формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_differential_montly_payment_first(double credit_summ,
                                                    int length_month,
                                                    double percent);

  /**
      @brief Метод вычисления последеней ежемесячной выплаты в случае
     дифференциального типа кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает последнюю ежемесячную выплату кредита дифференциальной
     формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_differential_montly_payment_last(double credit_summ,
                                                   int length_month,
                                                   double percent);

  /**
      @brief Метод вычисления переплаты в случае дифференциального типа кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает переплату кредита дифференциальной формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_differential_overpayment(double credit_summ, int length_month,
                                           double percent);

  /**
      @brief Метод вычисления полной суммы кредита в случае дифференциального
     типа кредита.
      @details Принимает сумму кредита double, продолжительность кредита int,
     процентную ставку double.
      @return Возвращает полную сумму кредита дифференциальной формы.
      @param credit_summ Сумма кредита.
      @param length_month Продолжительность кредит.
      @param percent Процентная ставка.
   */
  double s21_bank_differential_all_payment(double credit_summ, int length_month,
                                           double percent);
};

};  // namespace s21

#endif  // CREDIT_MODEL_H
