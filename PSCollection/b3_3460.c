#include <stdio.h>

int main(){
    int T = 0, n = 0;
    int idx = 0;

    scanf("%d", &T);
    if (T > 10)
        return 0;

    while (T != 0)
    {
        scanf("%d", &n);
        if (n < 1 || n > 100000)
            return 0;

        while (n > 0)
        {
			if (n % 2 == 1 && n != 1)
				printf("%d ", idx);
            else if (n == 1)
                printf("%d", idx);
			n = n / 2;
			idx++;
		}
		printf("\n");
        idx = 0; // idx초기화를 깜빡!! 가장 마지막까지 놓쳤던 에러
        T--;
    }

    return 0;
}

/*
<아이디어>

배열뒤집기함수(*배열)
{
    뒤집어서배열return
}
n을 이진수롤 나타내주는 함수(n)
{
    배열에 %이용해서 0,1입력받기
    배열리턴
}

main(){
    테스트케이스 개수인 T 입력받기
    양의 정수 n 입력 받기


}
*/
// 13 -> 1101 (처음뒤집힌건 1011)