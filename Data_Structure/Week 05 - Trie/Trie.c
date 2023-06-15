#include "Trie.h"

typedef struct _node {
    // int isLast; // 문자열의 끝인지를 나타내는 ‘불린 값 변수’
	int rank; //
	struct _node *child[26]; // 자손 노드를 가리키는 ‘포인터 목록’
} Node;

Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));

    for (int i = 0; i < 26; i++)
        newNode->child[i] = NULL;

    return (newNode);
}


void deleteNode(Node *node) {
    for (int i = 0; i < 26; i++) {
        if (node->child[i] != NULL)
            deleteNode(node->child[i]);
    }
    free(node);
}


void insertNode(Node *root, char *str, int rank) {
    Node *tmpNode = root;

    while (*str) {
        int i = *str++ - 'a';
        if (!(tmpNode->child[i]))
            tmpNode->child[i] = createNode();
        tmpNode = tmpNode->child[i];
    }
    tmpNode->rank = rank;
}


int findRank(Node *root, char *str) {
    Node *tmpNode = root;

    while (*str) {
        int i = *str++ - 'a';
        tmpNode = tmpNode->child[i];
    }
    return (tmpNode->rank);
}


void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}


char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    char** answer = (char**)malloc(sizeof(char *) * players_len);
    Node *root = createNode();

    for (int i = 0; i < players_len; i++) {
        answer[i] = (char *)malloc((strlen(players[i]) + 1) * sizeof(char));
        strcpy(answer[i], players[i]);
        insertNode(root, players[i], i);
    }
    for (int i = 0; i < callings_len; i++) {
        int rank = findRank(root, callings[i]);
        insertNode(root, answer[rank], rank - 1);
        insertNode(root, answer[rank - 1], rank);
        swap(&answer[rank], &answer[rank - 1]);
    }
    deleteNode(root);

    return (answer);
}