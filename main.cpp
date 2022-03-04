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

	test_stack.push( 1 );
	test_stack.push( 2 );
	test_stack.push( 3 );
	test_stack.push( 4 );
	test_stack.push( 5 );
	test_stack.push( 6 );
	test_stack.push( 7 );
	test_stack.push( 8 );
	test_stack.push( 9 );

	for( int i = 0; i < 15; i++ )
	{
		value = test_stack.pop();
		printf( "value = %d\n", value );
	}
	
	return 0;
}