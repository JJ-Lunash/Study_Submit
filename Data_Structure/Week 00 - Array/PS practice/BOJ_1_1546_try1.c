#include <stdio.h>
#include <stdlib.h>

int ft_len (int *arr)
{
    int len = 0;

    while(arr[len])
    {
        len++;
    }
    return (len);
}

int *ft_split(char *str)
{
    int **tmp_arr = 0;
    int i = 0, num = 0; // 받아온 str 관련
    int word = 0; // 과목 개수
    int j = 0, idx = 0; // tmp_arr 관련
    int each_len = 0;
    int each_num = 0;
    int *num_arr = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            word++;
        i++;
    }
    word++;
    tmp_arr = malloc(sizeof(int) * word);
    i = 0;
    while (str[i])
    {
        while (j < word)
        {
            if (str[num] == ' ')
            {
                idx = 0;
                num = 0;
                j++;
            }
            tmp_arr[j][idx++] = str[num++] - '0'; // 여기서 걸리는데 아직 해결 못함
        }
        i++;
    }

    i = 0;
    num_arr = malloc(sizeof(int) * j);
    while (tmp_arr[j])
    {
        each_len = ft_len(tmp_arr[j]);
        while (i < each_len)
        {
            num_arr[each_num] = tmp_arr[j][idx] + 10 * i;
            idx--;
            i++;
            each_num++;
        }
        j++;
    }

    return (num_arr);
}

int ft_find_max(int *arr)
{
    int i = 0;
    int max_num = -1;
    while (arr[i])
    {
        max_num = arr[i] > max_num ? arr[i] : max_num;
        i++;
    }
    i = 0;
    while (arr[i])
    {
        arr[i] = arr[i] / max_num * 100;
        i++;
    }

    return (max_num);
}

float ft_new_avg(int *arr)
{
    int i = 0;
    float sum = 0;

    while (arr[i])
    {
        sum += arr[i];
        i++;
    }
    sum /= i;

    return (sum);
}

int main(){
    int subject = 0;
    char *str = 0;
    int *scores = 0;
    int max_num = 0;

    // scanf("%d\n", &subject);
    subject = 3; ///////////////////////////////
    if (subject <= 0 || subject > 1000)
        return 0;
    // scanf("%s", str);
    str = "40 80 60"; ///////////////////////////
    scores = ft_split(str);
    max_num = ft_find_max(scores);
    if (max_num == 0)
        return 0;
    printf("%f\n", ft_new_avg(scores));

    return 0;
}


/*
< 실행 결과 기록 >
- 실행 결과 1 : 에러난거 str이 초기화 안된 상태로 사용되었다고 함
    -> 항상 NULL로 초기화하자
- 실행 결과 2 : 'segmentation fault (core dumped)' 라는 에러를 만남
    - segmentaition fault 에 대하여
        - 메모리 보호 기법에 의해 발생한 오류
        - 오류 발생 원인은 보호된 메모리에 접근하려 할 때 / 읽기 권한 없는 process를 읽거나 쓰려 할 때
           / 할당 된 메모리 이외 메모리에 접근할 때
    - segmentaition fault (core dumped)에 대하여
        - 입력받는 부분에서 생기는 오류
           (잘못된 주소를 가져오려고 하거나 잘못된 값 입력으로 넣었을 때)
*/
