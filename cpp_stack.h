#ifndef CPP_STACK_H_INCLUDED
#define CPP_STACK_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "error_processing.h"


class CStack
{
	private:

		int max_capacity_ = 0; //!TODO size_t
		int N_element_ = -1;

		stk_element_t* data_ = NULL;

		double up_resize_coeff_ = 0;
		double down_resize_coeff_ = 0;

	private:
		//делать ли геттеры и сеттеры дл внутренних нужд?

		void calc_upsize_coeff();
		void calc_downsize_coeff();
		double calc_smoothing_downsize_coeff();

		void resize( err_code* error_variable = NULL );

		void upsize( err_code* error_variable = NULL );
		void downsize( err_code* error_variable = NULL );
		void reallocate( err_code* error_variable = NULL );

		static stk_element_t* realloc( err_code* error_variable ); //замена realloc для стека

	public:

		explicit CStack( err_code* error_variable = NULL );
		~CStack();

		void push( stk_element_t value, err_code* error_variable = NULL );
		stk_element_t pop( err_code* error_variable = NULL );

};


#endif //CPP_STACK_H_INCLUDED