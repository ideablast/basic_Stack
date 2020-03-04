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
/*��ȣ üũ �˰���
*���� ��ȣ�� ������ ������ ��ȣ�� ������ ���ƾ��Ѵ�.
*���� ��ȣ���� ���� ��ȣ�� ������ ��ȣ���� ���� ���;��Ѵ�.
*��ȣ ���̿��� ���� ���踸 �����Ѵ�.
*/
int Bracket_check_getchar_stack(int ch)
{
	int result = TRUE;
	int pop;

	if (ch == '(' || ch == '{' || ch == '[')
		Push_stack(ch);

	if (ch == ')' || ch == '}' || ch == ']')//pop�� ��ȣ
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

int Bracket_check_gets_stack(char *string)
{
	int idx_end = strlen(string);
	int pop;
	int idx = 0;

	for (idx = 0; idx < idx_end; idx++)
	{
		string[idx];

		if (string[idx] == '(' || string[idx] == '{' || string[idx] == '[')
			Push_stack((int)string[idx]);

		if (string[idx] == ')' || string[idx] == '}' || string[idx] == ']')//pop�� ��ȣ
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

/*����ǥ��->����ǥ��

*/
void Notation_changer()
{


}
void clear_buf()//���� ����
{
	while (getchar() != '\n');
}

char* get_string_return_ptr()//���ڿ��� ���̿� ���� �ɵ������� �迭�� �Ҵ� �޸𸮸� �����Ͽ� �Է¹޴� �Լ�
{
	//�� ����� ���� �������ϰ� ���� �������� ����?
	//�޾Ƽ� ���� ����� ������ 
	//���ο��� �Է� ���� ���� �����ϴ� ����� ������?

	char *temp;
	unsigned int str_len = 2;//���ڿ��� ���� ������ �����ϰ� �ִ� �迭
	char ch = 0;
	unsigned int cnt = 0;


	temp = (char*)malloc(str_len * sizeof(char));

	while (ch != '\n')//�Է� ���� ���ڰ� �����̸� �ٷ� ���� Ż��
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
	temp = (char*)realloc(temp, (str_len + 1) * sizeof(char));//���͸� �Է¹��� ��쿡�� 1����Ʈ �޸� �Ҵ�

	cnt = 0;
	ch = 0;
	//��Ȯ�ϰ� ���ڿ��� ���·� ����
	//���� ��� [123456\0]�� �Է������� �޸� 7����Ʈ�� ����
	//strlen�� 6����
	//malloc�� 7����Ʈ �������
	return temp;
}