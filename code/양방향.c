#include <stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct STATION  //����� ���Ḯ��Ʈ ���� ���� 
{
	char name[20]; //�� �̸� 
	struct STATION *next;  //���� �����͸� ����Ű�� ������ 
	struct STATION *prev;  //���� �����͸� ����Ű�� ������ 
	
}station;
station *first;
station *last;


void init()  //�ʱ�ȭ �Լ� 
{
	first = (station*)malloc(sizeof(station));
	last = (station*)malloc(sizeof(station));
	first->next = last;
	last->prev = first;
	first->prev = NULL;
	last->next = NULL;
	strcpy(first->name, "��߿�");
	strcpy(last->name, "������");	
	
}

void add_station()  //�߰� �Լ� 
{
  	station *add; // ���߰� 
	add = (station*)malloc(sizeof(station));
	printf("�߰��� �� �Է� : ");
	scanf("%s", &add->name);
	first->next->prev = add;
	add->next= first->next;
	first->next = add;
	add->prev = first;
	 
	
	
}

void del_station()  //���� �Լ� 
{
	station *del;
	char name[20];
	del = first;
	printf("������ ���� �Է��ϼ��� : ");
	scanf("%s", &name); 
	while(del != NULL)
	{
		if(strcmp(del->name,name)==0)
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del);  // �޸� ����  
		}
		del = del->next;

	}
}

void search_station()  //�˻� �Լ� 
{
	station *search;
	char name[20];
	search = first;
	printf("�˻���  ���� �Է��ϼ��� : ");
	scanf("%s", &search);
	while(search != NULL)
	{
		if(strcmp(search->name,name)==0)
		{
			printf("%s", search->name); 
			
		}
		search = search->next;
	}
}

void print()  //��ü ��� �Լ�  
{
	station *prt;
	prt = first;
	while(prt != NULL)
	{
		printf("%s", prt->name);
		if(prt != last)
		{
			printf("->");
		}
		prt = prt->next;
	}
}

int main()
{
	
	init();
	int select;
	
	printf("�޴�\n");
	printf("1.�߰� 2. ���� 3. �˻� 4. ��ü��� 0.����");
	printf("�޴��� �Է��ϼ��� : ");
	scanf("%d", &select);
	while(select != 0)
	{
		switch(select)
		{
			case 1:
				add_station();
				break;
			case 2:
				del_station();
				break;
			case 3:
				search_station();
				break;
			case 4:
				print();
				break;
		}
	printf("�޴��� �Է��ϼ��� : ");
	scanf("%d", &select);
	
	}
	return 0;
}
