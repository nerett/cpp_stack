#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED


typedef int stk_element_t; //!!! смена типа не протестирована

const size_t START_CAPACITY = 8; //8
const int INT_POISON = 0; //TODO поменять на нормальный яд (или заставить пользователя создать его)
const int DATA_ALLOCATION_OFFSET = 1;

#endif //CONFIG_H_INCLUDED