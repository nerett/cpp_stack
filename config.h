#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED


/*--------------------------RECONFIGURATION-PARAMS----------------------------*/
typedef int stk_element_t; //!!! смена типа не протестирована

const size_t START_CAPACITY = 8;
const double START_UP_RESIZE_COEFF = 1; //не будет вызывать ошибок и падений
const double START_DOWN_RESIZE_COEFF = 1;

const double DEFAULT_UP_RESIZE_COEFF = 2;
const double DEFAULT_DOWN_RESIZE_COEFF = 0.5;
const double DEFAULT_SMOOTHING_DOWNSIZE_COEFF = 0.2;

const int INT_POISON = 0; //TODO поменять на нормальный яд (или заставить пользователя создать его)


/*--------------------------DO-NOT-CHANGE------------------------------------*/
const int START_N_ELEMENT = -1;
const int DATA_ALLOCATION_OFFSET = 1;
const int N_TO_AMOUNT_OFFSET = 1;


#endif //CONFIG_H_INCLUDED