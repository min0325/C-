#include <stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct STATION  //양방향 연결리스트 구조 정의 
{
	char name[20]; //역 이름 
	struct STATION *next;  //다음 데이터를 가리키는 포인터 
	struct STATION *prev;  //이전 데이터를 가리키는 포인터 
	
}station;
station *first;
station *last;


void init()  //초기화 함수 
{
	first = (station*)malloc(sizeof(station));
	last = (station*)malloc(sizeof(station));
	first->next = last;
	last->prev = first;
	first->prev = NULL;
	last->next = NULL;
	strcpy(first->name, "출발역");
	strcpy(last->name, "종착역");	
	
}

void add_station()  //추가 함수 
{
  	station *add; // 역추가 
	add = (station*)malloc(sizeof(station));
	printf("추가할 역 입력 : ");
	scanf("%s", &add->name);
	first->next->prev = add;
	add->next= first->next;
	first->next = add;
	add->prev = first;
	 
	
	
}

void del_station()  //삭제 함수 
{
	station *del;
	char name[20];
	del = first;
	printf("삭제할 역을 입력하세요 : ");
	scanf("%s", &name); 
	while(del != NULL)
	{
		if(strcmp(del->name,name)==0)
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del);  // 메모리 해제  
		}
		del = del->next;

	}
}

void search_station()  //검색 함수 
{
	station *search;
	char name[20];
	search = first;
	printf("검색할  역을 입력하세요 : ");
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

void print()  //전체 출력 함수  
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
	
	printf("메뉴\n");
	printf("1.추가 2. 삭제 3. 검색 4. 전체출력 0.종료");
	printf("메뉴를 입력하세요 : ");
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
	printf("메뉴를 입력하세요 : ");
	scanf("%d", &select);
	
	}
	return 0;
}
