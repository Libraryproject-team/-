#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
/*************��Ľṹ��***********/
typedef struct book {
	char number[4];     //���
	char space [32];    //�ո��
	char author[15];  //����
	char publisher[15];//������
	char name[15];
	int includer;        //����Ĳ�����
	int borrow;        //������
	struct book *next;
}book;
typedef struct information {
	char SID[10];					//����֤��
	char number[4];					//���
	int year;							//����ʱ��
	int moon;							
	int day;	
	struct information *next;						
}information; 
book* find_former(book*p1,int find_key)//ͷ���Ϊ�գ�Ѱ��ǰ��
{
	book *f1;
	f1 = p1;
	p1 = p1->next;
	while (p1)
	{
		if (atoi(p1->number) == find_key)
		{
			return f1;
			break;
		}
		p1 = p1->next;
		f1 = f1->next;
	}
	if (!p1)
		return 0;
}
information* find_former(information*p2,int find_key)//ͷ���Ϊ�գ�Ѱ��ǰ��
{
	information *f2;
	f2 = p2;
	p2 = p2->next;
	while (p2)
	{
		if (atoi(p2->number) == find_key)
		{
			return f2;
			break;
		}
		p2 = p2->next;
		f2 = f2->next;
	}
	if (!p2)
		return 0;
}
book* book_return(int find_key, book*p1)//������find_former����
{
	 book*q;
	 book*left;
	 if (find_former(p1, find_key))
	{
		q = find_former(p1, find_key);
		left = q->next;
		left->borrow++;
		left->includer--;
		return left;
		printf("�黹�ɹ�");
	}
	else
	{
		printf("δ�ҵ�����");
	}
}
void cancel(information*p2,int find_key)
{			
	information*f2;				
	if(find_former(p2,find_key)) 
	{
		f2=find_former(p2,find_key);
		f2=f2->next;
		free(f2);
	}
	else
	{
		printf("δ�ҵ�������");
	}
}
int main()
{
	unsigned int find_key;
	book*p1;//�Ѵ��ڵ�����
	information*p2;
	book*f1;//�������
	information*f2;
	printf("��������Ҫ�黹��ͼ�����ţ�");
	scanf("%d", &find_key);
	book_return(find_key, p1);
	cancel(p2,find_key);
	return 0;
}
