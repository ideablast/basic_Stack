#include"ALL.h"
//#define BASIC_STACK
//#define BRACKET_CHECK_GET_CHAR
//#define BRACKET_CHECK_GETS
#define NOTATION_CHANGER
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
	printf("����:%d\n", Count_stack());

	while (top->Link != NULL)
	{
		printf("�����? %d\n", IsEmpty());
		printf("%d\n", Pop_stack());
	}
	printf("�����? %d\n", IsEmpty());

#endif

#ifdef BRACKET_CHECK_GET_CHAR
	int ch = 0;
	int cnt = 0;
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

#ifdef NOTATION_CHANGER
	char* string = "(2+3)*4+(3-2)/5+7*3";//"((('60'/2)-3)+(2*3))-(2*3)";
	char* print;
	top = Add_new_stack();
	
	//string = get_string_return_ptr();
	print = Notation_changer(string);
	printf("������ ����: %s\n", string);
	printf("������ ����: %s\n", print);
	printf("%d\n",Calculator(print));
	
#endif


#ifdef CALCULATOR
	char* string = "-10*(-4+9)/10-20*-8*20-19*(4+8-10)*-10+20";
	int *arr;
	int idx = 0;
	int arr_size;
	arr = Number_detector(string);
	arr_size = _msize(arr) / sizeof(int);
	printf("%d\n\n\n\n\n\n\n",arr_size);

	for (idx = 0; idx < arr_size; idx++)
	{
		printf("%d\n", arr[idx]);
	}
	system("pause");


#endif
	
#ifdef NOTYET
	int i = -1000;
	int return_cnt;

	return_cnt = printf("%d\n", i);//printf�� ���� ��ȯ�Ѵ� -1000�̸� 5�� ��ȯ
								   //�� ��ȣ�� ������ ������ ������ ���ش�. ���Ͱ� ������ ���� ���� ���� ��ȯ
	printf("%d", return_cnt);

#endif

	system("pause");
}