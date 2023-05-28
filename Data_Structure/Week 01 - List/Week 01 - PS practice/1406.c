#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* prev;
    struct node* next;
}Node;

void print(Node* head){
    Node *tmp = head;
    tmp = tmp->next;

    while(tmp){
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int main(void){
    char ch = 0; // getchar() 초기 입력 문자열을 저장
    int M = 0; // 명령어 입력 횟수

    Node *head = (Node *)malloc(sizeof(Node)); // head init
    head->data = '!'; 
    head->prev = NULL; 
    head->next = NULL;

    Node *corsor = head; // corsor 

    while((ch = getchar()) != '\n') {
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = ch;
        n->prev = corsor;
        corsor->next = n;
        n->next = NULL;

        corsor = n;
    }
    
    scanf("%d", &M);

    for(int i=0; i < M; i++)
	{
        char tmp = 0;
        scanf(" %c", &tmp); // scanf 공백

        switch (tmp)
        {
            case 'L':
			{
                if(corsor->prev)
                    corsor = corsor->prev;
                break;
            }
			case 'D':
			{
                if(corsor->next)
                    corsor = corsor->next;
                break;
            }
			case 'B':
			{
                if(corsor->prev == NULL) continue; // head를 가리키는 경우
        
                Node* deln = (Node*)malloc(sizeof(Node)); // 삭제할 노드
                deln = corsor; // 현재 커서가 가리키는 노드 삭제
                corsor = deln->prev;
                // 마지막 노드를 가리키는 경우
                if(deln->next == NULL)
                    (deln->prev)->next = NULL;
                else
				{
                    (deln->prev)->next = deln->next;
                    (deln->next)->prev = deln->prev;
                }
                free (deln);
                break;
            }
			case 'P':
			{
                char temp = 0;
                scanf(" %c", &temp);

                Node* n = (Node*)malloc(sizeof(Node));
                n->data = temp;
                n->prev = corsor;
                
                if(corsor->next == NULL) // 마지막 노드를 가리키는 경우
                    n->next = NULL;
                else
				{
                    n->next = corsor->next;
                    (corsor->next)->prev = n;
                }
                corsor->next = n;
                corsor = corsor->next;
                break;
            }
        }
    }
    print(head); 

    return 0;
}