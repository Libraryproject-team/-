#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#pragma warning(disable:4996)
/*************��Ľṹ��***********/
typedef struct book {
	char number[4];     //���
	char space = 32;    //�ո��
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
	int mon;							//
	int day;							//
}information;
book* find_former(book*p,int find_key)//ͷ���Ϊ�գ�Ѱ��ǰ��
{
	book *f;
	f = p;
	p = p->next;
	while (p)
	{
		if (atoi(p->number) == find_key)
		{
			return f;
			break;
		}
		p = p->next;
		f = f->next;
	}
	if (!p)
		return 0;
}
book* book_borrow(int find_key, book*p)//������find_former����
{
	 book*q;
	 book*left;
	 if (find_former(p, find_key))
	{
		 q = find_former(p, find_key);
		 left = q->next;
		 if (left->includer > 0)			//���ִ��������㣬���
		 {
			 left->borrow++;
			 left->includer--;
		 }
		 else
		 {
			 printf(" �ִ���Ϊ�㣬���ܽ��");
		 }
		 return left;
	}
}
void information_insert_file(struct information new_reader)
{
	FILE*fp = NULL;
	fp = fopen("reader.txt", "a");
	fputs(new_reader.number, fp);
	fputs(" ", fp);
	fputs(new_reader.SID, fp);
	fputs("\n", fp);
	fclose(fp);
}
void record(book*left)//��¼��������Ϣ�Լ�����ʱ�䣨�����ʱ���Ƿ����ʱ�亯���仯��
{									//��ͨ����������

	information* m;
	int year, mon, day;
	time_t t=time(0);
	struct tm p;
	localtime_s(&p,&t);
	year = p.tm_year+1900;
	mon = p.tm_mon+3;
	day = p.tm_mday;
	m = (information*)malloc(sizeof(information));
	m->day = day;
	m->mon = mon;
	m->year = year;
	printf("��������Ľ���֤�ţ�");
	scanf("%s", &m->SID);
	printf("��ɵǼǣ����պ�ͼ��");
	printf("����%d��%d��%d��ǰ�黹ͼ��!!",p.tm_year + 1900, p.tm_mon + 3, p.tm_mon + 3);
	strcpy_s(m->number, left->number);
	information_insert_file(*m);
}
int main()
{
	unsigned int find_key;
	book*p;//�Ѵ��ڵ�����
	book*f;//�������
	printf("��������Ҫ����ͼ�����ţ�");
	scanf_s("%d", &find_key);
	f = book_borrow(find_key, p);
	if (f->includer > 0)
	{
		record(f);
	}
	return 0;
}