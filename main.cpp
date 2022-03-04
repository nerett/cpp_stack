#include "cpp_stack.h"
#include <stdio.h>

int main()
{
	CStack test_stack;
	test_stack.push( 15 );
	test_stack.push( 14435 );
	stk_element_t value = test_stack.pop();
	printf( "value = %d\n", value );
	test_stack.push( 999 );

	value = test_stack.pop();
	printf( "value = %d\n", value );
	value = test_stack.pop();
	printf( "value = %d\n", value );
	value = test_stack.pop();
	printf( "value = %d\n", value );
	value = test_stack.pop();
	printf( "value = %d\n", value );
	value = test_stack.pop();
	printf( "value = %d\n", value );
	value = test_stack.pop();
	printf( "value = %d\n", value );
	return 0;
}