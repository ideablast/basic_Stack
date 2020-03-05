#include"ALL.h"

extern Stack *top;

Stack* Add_new_stack()
{
	Stack *temp = (Stack*)malloc(sizeof(Stack));
	temp->nData = 0;
	temp->Link = NULL;

	return temp;
}

void Push_stack(int item)
{
	Stack *temp = Add_new_stack();
	temp->nData = item;
	temp->Link = top->Link;
	top->Link = temp;
}

int Pop_stack()
{
	Stack *Pop_mem = top->Link;
	int Pop_nData = top->Link->nData;

	top->Link = Pop_mem->Link;
	free(Pop_mem);

	return Pop_nData;
}
int IsEmpty()
{
	return top->Link == NULL;
}
int Count_stack()
{
	int cnt = 0;
	Stack *Count = top->Link;

	while (Count->Link != NULL)
	{
		cnt++;
		Count = Count->Link;
	}
	cnt++;

	return cnt;

}
/*괄호 체크 알고리즘
*왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야한다.
*같은 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야한다.
*괄호 사이에는 포함 관계만 존재한다.
*/
int Bracket_check_getchar_stack(int ch)
{
	int result = TRUE;
	int pop;

	if (ch == '(' || ch == '{' || ch == '[')
		Push_stack(ch);

	if (ch == ')' || ch == '}' || ch == ']')//pop의 신호
	{
		
		if (IsEmpty() == TRUE)
			pop = -1;

		else
			pop = Pop_stack();

		switch (pop)
		{
		case '(':
			if (ch != ')')
				puts("Pair_Error");
			else
				puts("Success");
			break;
		case '{':
			if (ch != '}')
				puts("Pair_Error");
			else
				puts("Success");
			break;
		case '[':
			if (ch != ']')
				puts("Pair_Error");
			else
				puts("Success");
			break;
		case -1:
			puts("Open_Fail");
			break;
		}
	}

	return result;
}

Bracket_check_gets_stack(char *string)
{
	int idx_end = strlen(string);
	int pop;
	int idx = 0;

	for (idx = 0; idx < idx_end; idx++)
	{
		if (string[idx] == '(' || string[idx] == '{' || string[idx] == '[')
			Push_stack((int)string[idx]);

		if (string[idx] == ')' || string[idx] == '}' || string[idx] == ']')//pop의 신호
		{
			if (IsEmpty() == TRUE)
				pop = -1;

			else
				pop = Pop_stack();

			switch (pop)
			{
			case '(':
				if (string[idx] != ')')
					puts("Pair_Error");
				else
					puts("Success");
				break;
			case '{':
				if (string[idx] != '}')
					puts("Pair_Error");
				else
					puts("Success");
				break;
			case '[':
				if (string[idx] != ']')
					puts("Pair_Error");
				else
					puts("Success");
				break;
			case -1:
				puts("Open_Fail");
				break;
			}
		}
	}
		

}

/*중위표기->후위표기
 *피연산자가 들어오면 바로 출력
 *연산자가 들어오면 자기보다 우선 순위가 높거나 같은 것들을 빼고 자신을 스택에 담습니다.
 *여는 괄호 '('를 만나면 무조건 스택에 담습니다.
 *닫는 괄호 ')'를 만날때 까지 스택에서 출력합니다.
*/
int Level_tester(int op)
{
	int level = 0;

	if(op == '(')
		level = 1;
	else if (op == '+' || op == '-')
		level = 2;
	else if (op == '*' || op == '/')
		level = 3;
	else
		level = FAIL;

	return level;
}

char* Notation_changer(const char *string)
{
	int idx_end = strlen(string);
	int pop = -1;
	int idx = 0;
	int level = 0;
	char *print;
	int print_idx = 0;
	print = (char*)malloc((idx_end + 1) * sizeof(char));
	memset(print, '\0', (idx_end + 1) * sizeof(char));

	for (idx = 0; idx < idx_end; idx++)
	{
		if (string[idx] == '(')
			Push_stack((int)string[idx]);
		else if (string[idx] == '+' || string[idx] == '-' || string[idx] == '*' || string[idx] == '/')
		{
			//Level_tester(string[idx]) 스택에 넣을지 그대로 출력할지를 결정해야할 연산자
			//Level_tester(pop) 이미 스택에 들어가있는 연산자
			if (IsEmpty() == TRUE)
				Push_stack(string[idx]);
			else
			{
				pop = Pop_stack();
				if (Level_tester(pop) >= Level_tester(string[idx]))
				{
					print[print_idx] = (char)pop;
					print[print_idx + 1] = '\0';
					print_idx++;
					Push_stack(string[idx]);
					pop = -1;//쓰고 초기화
				}
				else
				{
					Push_stack(pop);
					Push_stack(string[idx]);
				}
					
			}
			
		}
		else if (string[idx] == ')')
		{
			pop = Pop_stack();
			while ( pop != '(')
			{
				print[print_idx] = (char)pop;
				print[print_idx + 1] = '\0';
				print_idx++;
				pop = Pop_stack();
			}
			pop = -1;
		}
		else//숫자나 공백 문자의 경우
		{
			print[print_idx] = string[idx];
			print[print_idx + 1] = '\0';
			print_idx++;
		}
	}

	//스택에 남은 연산자를 끝에 붙여줌
	idx_end = Count_stack();
	for (idx = 0; idx < idx_end; idx++)//이 안에 함수가 들어가면 계속 실행하면서 값이 바뀌는가?
	{
		print[print_idx] = Pop_stack();
		print[print_idx + 1] = '\0';
		print_idx++;
	}
	return print;
}
void clear_buf()//버퍼 비우기
{
	while (getchar() != '\n');
}

char* get_string_return_ptr()//문자열의 길이에 따라서 능동적으로 배열의 할당 메모리를 조절하여 입력받는 함수
{
	//이 방식이 좀더 안정적일것 같은 느낌적인 느낌?
	//받아서 쓰는 방식이 좋을까 
	//내부에서 입력 받은 것을 리턴하는 방식이 좋을까?

	char *temp;
	unsigned int str_len = 2;//문자열의 길이 정보를 저장하고 있는 배열
	char ch = 0;
	unsigned int cnt = 0;


	temp = (char*)malloc(str_len * sizeof(char));

	while (ch != '\n')//입력 받은 문자가 엔터이면 바로 루프 탈출
	{
		if (str_len > cnt)
		{
			ch = getchar();
			temp[cnt] = ch;
			cnt++;
		}

		else
		{
			str_len += 5;
			temp = (char*)realloc(temp, (str_len) * sizeof(char));
		}
	}

	temp[cnt - 1] = '\0';
	str_len = strlen(temp);
	temp = (char*)realloc(temp, (str_len + 1) * sizeof(char));//엔터를 입력받은 경우에는 1바이트 메모리 할당

	cnt = 0;
	ch = 0;
	//정확하게 문자열의 형태로 저장
	//예를 들어 [123456\0]을 입력했으면 메모리 7바이트가 리턴
	//strlen시 6리턴
	//malloc는 7바이트 해줘야함
	return temp;
}