#ifndef ERROR_PROCESSING_H_INCLUDED
#define ERROR_PROCESSING_H_INCLUDED


enum err_code
{
	OK = 0,
	NO_ELEMENTS_TO_POP = 1,
	CALLOC_ERROR = 2,
	INVALID_DATA_PTR = 3,
	REALLOCATION_ERROR = 4,
	FOPEN_ERROR = 5,
	N_ELEMENT_MORE_CAPACITY = 6,
	INVALID_UP_RESIZE_COEFF = 7,
	INVALID_DOWN_RESIZE_COEFF = 8,
	STACK_IS_NOT_CONSTRUCTED = 9,
	INVALID__USER_TYPE_DUMP_STRING_PTR = 10,
};


#define error_output( error_variable, possible_error_type ) do { \
    if( error_variable != NULL )                                 \
	{                                                            \
		*error_variable = possible_error_type;                   \
	}                                                            \
} while(0)

#define void_check_errors( error_variable ) do {                       \
    if( error_variable != NULL )                                       \
  	{                                                                  \
  		if( *error_variable != OK )                                    \
		{                                                              \
			return;                                                    \
		}                                                              \
  	}                                                                  \
} while(0)

#define int_check_errors( error_variable ) do {                      \
   if( error_variable != NULL )                                      \
   {                                                                 \
	   if( *error_variable != OK )                                   \
	   {                                                             \
		   return {};                                                \
	   }                                                             \
   }                                                                 \
} while(0)

#define validate_dump( some_stack, error_variable ) do {                                                  \
		err_code stack_error = OK;                                                                        \
		validate_stack( some_stack, &stack_error );                                                       \
		stack_dump( some_stack, stack_error, __FILE__, __PRETTY_FUNCTION__, __LINE__, error_variable );   \
	} while(0)


#endif //ERROR_PROCESSING_H_INCLUDED