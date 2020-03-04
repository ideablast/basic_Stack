#include"ALL.h"
//#define BASIC_STACK
//#define BRACKET_CHECK_GET_CHAR
//#define BRACKET_CHECK_GETS
//#define CALCULATOR

Stack *top;

int main()
{

#ifdef BASIC_STACK
	top = Add_new_stack();
	Push_stack(10);
	Push_stack(20);
	Push_stack(30);
	Push_stack(40);
	Push_stack(50);
	Push_stack(60);
	printf("갯수:%d\n", Count_stack());

	while (top->Link != NULL)
	{
		printf("비었니? %d\n", IsEmpty());
		printf("%d\n", Pop_stack());
	}
	printf("비었니? %d\n", IsEmpty());

#endif

#ifdef BRACKET_CHECK_GET_CHAR
	int ch = 0;
	int result;
	top = Add_new_stack();

	while (ch != '\n')
	{
		ch = getchar();
		result = Bracket_check_getchar_stack(ch);
	}
	if (IsEmpty() == FALSE)
	{
		for (cnt = 0; cnt < Count_stack(); cnt++)
			puts("Close Fail");
	}

	
#endif

#ifdef BRACKET_CHECK_GETS
	char* string;
	int cnt = 0;

	top = Add_new_stack();

	string = get_string_return_ptr();
	Bracket_check_gets_stack(string);

	if (IsEmpty() == FALSE)
	{
		for(cnt=0;cnt<Count_stack();cnt++)
			puts("Close Fail");
	}
		
#endif



#ifdef CALCULATOR


#endif
	
	system("pause");
}