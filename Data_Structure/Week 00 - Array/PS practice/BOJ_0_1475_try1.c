#include <stdio.h>
#include <stdlib.h>

size_t ft_int_len(int n);
char *ft_itoa(int n);
int ft_find_max (char *str);

// 숫자를 문자열로 변환하여 반환해주는 함수
// 0에 대한 예외 처리 필요
// 숫자 길이 구하는 함수 필요

size_t ft_int_len(int n)
{
    size_t len;

    if (n == 0)
        return (1);
    if (n < 0 || n > 1000000)
        return (0);
    len = 0;
    while (n) // n != 0 말고 n으로만 써도 되네
    {
        n /= 10;
        len++;
    }

    return (len);
}

char *ft_itoa(int n)
{
    size_t len;
    // size_t i; // len이 size_t로 선언되었기 때문에 처음에 int로 선언했다가 에러를 만났음
    char *rst;

    len = ft_int_len(n);
    rst = (char *)malloc(sizeof(char) * len + 1);
    if (!rst) // rst가 아예 할당되지 않는 경우
        return (NULL);

    rst[len] = '\0';
    while (len > 0)
    {
            rst[len - 1] = n % 10 + '0';
            n /= 10;
            len--;
    }
    return (rst);
}

int ft_find_max (char *str)
{
    int i = 0;
    int zero_to_nine = 0;
    int cnt_each_num[9] = {0};
    int max_num = 0;
    // int temp_six = 0;

    while (str[i])
    {
        while (zero_to_nine < 10)
        {
            
            if (str[i] == zero_to_nine + '0')
            {
                if(zero_to_nine == 9)
                    cnt_each_num[6]++;
                else
                {
                    cnt_each_num[zero_to_nine]++;
                }
                zero_to_nine = 0; // 여기서 zero_to_nine을 초기화시켜주는걸 못찾아서 완성2에서 에러남 제발 마지막 에러여라!
                // 이 문장을 첨 썼을 때 else문 안에 섰던게 문제였었던 것 같음 이번엔 제발제발 맞아라
                break;
            }
            zero_to_nine++;
        }
        i++;
    }

    cnt_each_num[6] = (cnt_each_num[6] + 1) / 2; // 홀수라서 반올림해줄때 + 1먼저해주면 짝수,홀수일때 모두 적용 가능!
// 위의 한줄로 될 거를 밑에처럼 7줄로 썼었음
    // if (cnt_each_num[6] % 2 == 0)
    //     cnt_each_num[6] /= 2;
    // else if (cnt_each_num[6] % 2 == 1)
    // {
    //     cnt_each_num[6] /= 2;
    //     cnt_each_num[6]++;
    // }

    i = 0;
    max_num = cnt_each_num[0];
    while (i < 9) // 처음에 cnt_each_num[i]로 잘못 했었음
    {
        if (cnt_each_num[i] > max_num)
            max_num = cnt_each_num[i];
        i++;
    }
// 아래의 if문을 max_num 찾아낸 후에 하니 cnt[6]과 cnt[6 제외한 다른 수]가 같을 때 문제가 되네! max_num찾기전에 하자. 이게 찐찐 마지막으로 고친 오류 휴,,
    // if (max_num == cnt_each_num[6]) // cnt_each_num[6]이 max_num일 경우를 생각을 못해 9999입력시 4가 나왔었음!
    // {
    //     if (max_num % 2 == 0)
    //         max_num /= 2;
    //     else
    //     {
    //         temp_six = max_num / 2;
    //         max_num = temp_six + 1;
    //     }
    // }
    return (max_num);
}

int main(){

    int room_num = 0;
    char *room_str; // 배열로 선언시 배열명은 포인터 상수이므로 나중에 l-value가 될 수 없음 주의
    int max_num = 0;

    scanf("%d", &room_num);
    room_str = ft_itoa(room_num);
    max_num = ft_find_max(room_str);
    printf("%d", max_num);

    return 0;
}

/* ----------------------------------- PS practice 0 -----------------------------------
< 문제를 처음 읽었을 때 혼자 생각해본 아이디어 >
- 큰 줄기 : 배열로 방 번호를 받아 저장한 후 배열의 각 원소들을 비교하는 방법
- 세부 설명
    step 1) 숫자 입력받기
    step 2) 입력받은 숫자를 문자로 변환하여 배열에 저장
        step 2-1) 숫자의 길이 구하기
        step 2-2) ft_itoa에서 숫자를 문자로 변환해 저장할 배열 만들고 저장
    step 3) 배열의 0번째 요소부터 순서대로 문자'0' ~ '9'와 비교
    step 4) 9개의 변수 지정 (zero, one, two, three, four, five, six_and_nine, seven, eight)
    step 5) 비교하며 일치하는 문자숫자가 나올때마다 각 해당하는 변수에 +1
    step 5) 배열의 마지막 원소까지 비교가 끝나고나면 zero ~ eight을 비교해 max가 몇인지 알아내기
    step 6) 결론 : 플라스틱 숫자 세트는 max개 만큼 필요함!
- 기타 메모 사항
    1) 기본 intlen, itoa 함수의 역할과는 조금 다르게 문제에 맞게 작성됨
-----------------------------------------------------------------------------------------*/
/*
<코드를 완성하기까지의 진행과정 기록>
1) 1차 완성
    : 에러 발생 없이 실행이 되긴 하나 어느 숫자를 입력해도 결과로 0이 출력됨
2) 2차 완성
    : 백준에서 준 테스트케이스를 돌린 경우 정상 출력,
      but 6과9에 대해 처리하는 코드를 추가하였음에도 불구하고 어떠한 경우에는 정상적으로 결과가 나오고
      69696, 69999, 99996 등 몇몇 경우에는 비정상적인 결과가 나옴
3) 3차 완성
    : 
*/

/*
< Question >
1) 함수에서 


< 이번 문제를 통해 새로 공부한 내용>
1) 배열 자체로 배열 선언 vs 포인터 형식으로 배열 선언
    - 포인터 형식으로 선언시, 다른 함수의 매개변수로 넘길 때 내용 변경이 불가능하다는 것은 알고 있었는데
      배열로 선언시, 배열명은 포인터 상수이므로 그 이후에 l-value로 쓸 수 없음을 제대로 모르고 있었는데 알게 됨
2) size_t 타입에 대하여
    - malloc 함수와 strlen 함수가 size_t 타입을 반환하거나 인자로 사용하는 대표적인 함수임
    - size_t 타입은 부호없는 정수(unsigned int)
    - 출력 시 잘못된 형식 지정자를 선택하면 예상치 못한 값이 출력 됨, &zu 사용 할 것
    - 쓰는 이유 : 시스템에서 주소 지정이 가능한 메모리 영역과 일치하는 크기를 선언하는데 음수의 사용은 의미가 없기 때문
*/

