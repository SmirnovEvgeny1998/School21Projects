#include "deposit_model.h"

#include <iostream>

s21::deposit_controller::deposit_controller() {}

double s21::deposit_controller::s21_deposit_profitability_complex(
    int what_to_return, double deposit_amount, int deposit_term, double interst,
    double tax, int periodicity, int capitalization,
    s21::deposit_controller::s21_repelishments *repelishments,
    s21::deposit_controller::s21_widrawls *partial_widrawal,
    double bank_key_deposit) {
  s21_date current_date, end_date;
  current_date.day = 1, current_date.month = 1, current_date.year = 0;
  end_date.day = 0, end_date.month = 0, end_date.year = 0;
  double result = 0, percents_this_year = 0, month_percents = 0,
         nalog_result = 0, last_year = 0;
  int repelishments_size = 0, widrawl_size = 0, month_counter = 0, error = 0;
  if (sizeof(repelishments) == 0) {
    repelishments_size = 0;
  } else {
    while (repelishments[repelishments_size].last != 1) {
      repelishments_size += 1;
    }
    repelishments_size += 1;
  }
  if (sizeof(partial_widrawal) == 0) {
    widrawl_size = 0;
  } else {
    while (partial_widrawal[widrawl_size].last != 1) {
      widrawl_size += 1;
    }
    widrawl_size += 1;
  }
  s21_fullfiil_monts(&current_date);
  s21_fullfiil_monts(&end_date);
  end_date.day = 1;
  end_date.month += deposit_term;
  end_date.year += end_date.month / 12;
  end_date.month = end_date.month % 12 + 1;
  while (current_date.month != end_date.month ||
         current_date.year != end_date.year) {
    for (int i = 0; i < repelishments_size; i++) {
      if (repelishments[i].month == current_date.month &&
          repelishments[i].year == current_date.year) {
        deposit_amount += repelishments[i].summ;
      }
    }
    for (int i = 0; i < widrawl_size; i++) {
      if (partial_widrawal[i].month == current_date.month &&
          partial_widrawal[i].year == current_date.year) {
        deposit_amount -= partial_widrawal[i].summ;
      }
      if (deposit_amount < 0) {
        error = -1;
      }
    }
    s21_deposit_profitability_complex_branch_1(
        periodicity, &month_percents, &percents_this_year, &result,
        &month_counter, &deposit_amount, interst, current_date, deposit_term,
        capitalization);
    s21_deposit_profitability_complex_branch_2(
        periodicity, month_counter, deposit_term, &nalog_result, tax, result,
        bank_key_deposit, current_date, end_date, &last_year,
        &percents_this_year);
    current_date.month += 1;
    if (current_date.month > 12) {
      current_date.month -= 12;
      current_date.year += 1;
    }
  }
  if (what_to_return == 1) {
    result = nalog_result;
  } else if (what_to_return == 2) {
    result = deposit_amount;
  }
  if (error == -1) {
    result = error;
  }
  return result;
}

void s21::deposit_controller::s21_deposit_profitability_complex_branch_1(
    int periodicity, double *month_percents, double *percents_this_year,
    double *result, int *month_counter, double *deposit_amount, double interst,
    s21::deposit_controller::s21_date current_date, double deposit_term,
    int capitalization) {
  if (periodicity == 0) {
    *month_percents = (*deposit_amount * interst *
                       current_date.month_days[current_date.month - 1] / 365) /
                      100;
    *percents_this_year += *month_percents;
    *result += *month_percents;
    *month_counter += 1;
  } else if (periodicity == 1) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 3 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year += *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 2) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 6 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year += *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 3) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 12 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year = *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 4) {
    *result += (*deposit_amount * interst *
                current_date.month_days[current_date.month - 1] / 365) /
               100;
    *month_counter += 1;
  }
  if (capitalization == 1 && periodicity == 0) {
    *deposit_amount += *month_percents;
  } else if (capitalization == 1 && periodicity == 1 &&
             (*month_counter % 3 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 2 &&
             (*month_counter % 6 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 3 &&
             (*month_counter % 12 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 4 &&
             *month_counter == deposit_term) {
    *deposit_amount += *result;
  }
}

void s21::deposit_controller::s21_deposit_profitability_complex_branch_2(
    int periodicity, int month_counter, int deposit_term, double *nalog_result,
    double tax, double result, double bank_key_deposit,
    s21::deposit_controller::s21_date current_date,
    s21::deposit_controller::s21_date end_date, double *last_year,
    double *percents_this_year) {
  if (periodicity == 4 && month_counter == deposit_term) {
    *nalog_result = tax * (result - bank_key_deposit * 10000) / 100;
    if (*nalog_result < 0) {
      *nalog_result = 0;
    }
  } else if ((periodicity == 3 && current_date.month == 1) ||
             (periodicity == 3 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 2 && current_date.month == 11) ||
             (periodicity == 2 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 1 && current_date.month == 11) ||
             (periodicity == 1 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 0 && current_date.month == 11) ||
             (periodicity == 0 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  }
}

void s21::deposit_controller::s21_fullfiil_monts(
    s21::deposit_controller::s21_date *months) {
  months->month_days[0] = 31;
  months->month_days[1] = 28;
  months->month_days[2] = 31;
  months->month_days[3] = 30;
  months->month_days[4] = 31;
  months->month_days[5] = 30;
  months->month_days[6] = 31;
  months->month_days[7] = 31;
  months->month_days[8] = 30;
  months->month_days[9] = 31;
  months->month_days[10] = 30;
  months->month_days[11] = 31;
}
