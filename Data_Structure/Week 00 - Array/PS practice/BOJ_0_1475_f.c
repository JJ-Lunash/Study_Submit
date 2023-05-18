#include <stdio.h>

int main() {
    char room_num[9];
    int count[10] = {0};
    int max_num = -1;
    int i = 0;

    scanf("%s\n", room_num);
    while (room_num[i])
    {
        count[room_num[i] - '0']++;
        i++;
    }
    count[6] = (count[6] + count[9] + 1) / 2;
    i = 0;
    while (i < 9)
    {
        max_num = count[i] > max_num ? count[i] : max_num;
        i++;
    }
    printf("%d\n", max_num);

    return 0;
}