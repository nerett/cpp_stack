#include "cpp_stack.h"


/*--------------------------FUNCTION----------------------------------------- */
CStack::CStack( err_code* error_variable ):

		max_capacity_ ( START_CAPACITY ), //!TODO size_t
		N_element_ ( -1 ),

		data_ ( new stk_element_t[max_capacity_ + DATA_ALLOCATION_OFFSET] {} ),

		up_resize_coeff_ ( 1 ), //не будет вызывать ошибок и падений
		down_resize_coeff_ ( 1 )
{
	//some_stack->data = ( stk_element_t* )calloc( some_stack->max_capacity + 1 + N_CANARIES, sizeof( stk_element_t ) ); //я не знаю, почему, но все ошибки valgrind исчезли после +1

/*
	if( some_stack->data == NULL )
	{
		error_output( error_variable, CALLOC_ERROR );
		return;
	}
*/
}


/*--------------------------FUNCTION----------------------------------------- */
CStack::~CStack()
{
/*
	if( some_stack->data == NULL )
	{
		error_output( error_variable, INVALID_DATA_PTR );
		return;
	}
	free( some_stack->data - DATA_PTR_OFFSET );

	some_stack->is_initialized = false;
	some_stack->N_element = 0;
	some_stack->max_capacity = 0;
	some_stack->up_resize_coeff = 0;
	some_stack->down_resize_coeff = 0;
*/

	delete[] data_;

}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::resize( err_code* error_variable )
{
	calc_upsize_coeff();
	calc_downsize_coeff();

    if( N_element_ == max_capacity_ )
    {
        upsize( error_variable );
    }
    else if( N_element_ < max_capacity_ * calc_smoothing_downsize_coeff() && max_capacity_ > START_CAPACITY ) //! КОСТЫЛЬ!
    {
		downsize( error_variable );
    }

	//void_check_errors( error_variable );
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::calc_upsize_coeff()
{
	up_resize_coeff_ = 2; //! HARDCODE
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::calc_downsize_coeff()
{
	down_resize_coeff_ = 0.5; //! HARDCODE
}


/*--------------------------FUNCTION----------------------------------------- */
double CStack::calc_smoothing_downsize_coeff()
{
	return 0.2; //! HARDCODE
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::upsize( err_code* error_variable )
{
	max_capacity_ *= up_resize_coeff_;

	reallocate( error_variable );
	//void_check_errors( error_variable );
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::downsize( err_code* error_variable )
{
	max_capacity_ *= down_resize_coeff_;

	reallocate( error_variable );
	//void_check_errors( error_variable );
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::reallocate( err_code* error_variable ) //!TODO переписать в стиле C++
{
	//void* realloc_buffer = ( stk_element_t* )realloc( data_, sizeof( stk_element_t ) * ( max_capacity_ + 1 ) );
	stk_element_t* realloc_buffer = new stk_element_t[max_capacity_+1] {0};

	if( !realloc_buffer )
	{
		return;
	}
	
	memcpy( realloc_buffer, data_, sizeof( stk_element_t ) * N_element_ );

	/*
	for( int i = 0; i < N_element_; i++ ) //!TODO копирование нормальным методом
	{
		realloc_buffer[i] = data_[i];
	}
	*/

	delete[] data_;

	data_ = ( stk_element_t* )realloc_buffer;
}


/*--------------------------FUNCTION----------------------------------------- */
void CStack::push( stk_element_t value, err_code* error_variable ) //есть какая-то ошибка памяти
{
    resize( error_variable );
	//void_check_errors( error_variable );

	N_element_++;

	//не знаю, нужна ли проверка N_element < max_capacity
	data_[N_element_] = value;
}


/*--------------------------FUNCTION----------------------------------------- */
stk_element_t CStack::pop( err_code* error_variable ) //!TODO ошибка запроса нулевого элемента стека
{

	if( N_element_ < 0 )
	{
		return {};
	}

	if( max_capacity_ < N_element_ )
	{
		//error_output( error_variable, NO_ELEMENTS_TO_POP );
		return {};
	}

	stk_element_t return_value = data_[N_element_]; //!TODO добавить сеттеры/геттеры и проверки на обращение к невыделенной памяти
	data_[N_element_] = INT_POISON;
	N_element_--;

	resize( error_variable );
	//int_check_errors( error_variable );

	return return_value;
}


/*
static bool validate_stack( Stack* some_stack, err_code* error_variable )
{
	if( some_stack->is_initialized == false )
	{
		error_output( error_variable, STACK_IS_NOT_CONSTRUCTED );
		return false;
	}
	if( some_stack->N_element > some_stack->max_capacity )
	{
		error_output( error_variable, N_ELEMENT_MORE_CAPACITY );
		return false;
	}
	if( some_stack->data == NULL )
	{
		error_output( error_variable, INVALID_DATA_PTR );
		return false;
	}
	if( some_stack->up_resize_coeff <= 0 )
	{
		error_output( error_variable, INVALID_UP_RESIZE_COEFF );
		return false;
	}
	if( some_stack->down_resize_coeff <= 0 )
	{
		error_output( error_variable, INVALID_DOWN_RESIZE_COEFF );
		return false;
	}


	#ifndef NDEBUG
		if( !check_struct_canary( &some_stack->left_struct_canary ) )
		{
			error_output( error_variable, LEFT_STRUCT_CANARY_DIED );
			return false;
		}
		if( !check_struct_canary( &some_stack->right_struct_canary ) )
		{
			error_output( error_variable, RIGHT_STRUCT_CANARY_DIED );
			return false;
		}
		if( !check_data_canary( some_stack->data, - DATA_PTR_OFFSET ) )
		{
			error_output( error_variable, LEFT_DATA_CANARY_DIED );
			return false;
		}
		if( !check_data_canary( some_stack->data, some_stack->max_capacity + DATA_PTR_OFFSET ) )
		{
			error_output( error_variable, RIGHT_DATA_CANARY_DIED );
			return false;
		}
		if( xor_hash( some_stack->data, some_stack->N_element ) != some_stack->data_hash )
		{
			error_output( error_variable, INVALID_DATA_HASH );
			return false;
		}
	#endif


	return true;
}
*/
