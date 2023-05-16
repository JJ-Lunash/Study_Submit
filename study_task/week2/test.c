#include <stdio.h>

int main(){
    int arr1[5] = {1, 2, 3, 4, 5};
    // int *arr2 = {1, 2, 3, 4, 5};

    char arr3[] = "abc";
    // char *arr4 = "abc";

    int size1_arr = sizeof(arr1);
    int size1_p = sizeof(arr1[0]);
    int size1_div = sizeof(arr1)/sizeof(arr1[0]);
    // int size2_arr = sizeof(arr2);
    // int size2_p = sizeof(arr2[0]);
    int size3_arr = sizeof(arr3);
    int size3_p = sizeof(arr3[0]);
    int size3_div = sizeof(arr3)/sizeof(arr3[0]);
    // int size4_arr = sizeof(arr4);
    // int size4_p = sizeof(arr4[0]);
    // int size4_div = sizeof(arr4)/sizeof(arr4[0]);

    printf("%d\n", size1_arr);
    printf("%d\n", size1_p);
    printf("%d\n", size1_div);
    printf("---------------------------------\n");
    // printf("%d\n", size2_arr);
    // printf("%d\n", size2_p);
    printf("---------------------------------\n");
    printf("%d\n", size3_arr);
    printf("%d\n", size3_p);
    printf("%d\n", size3_div);
    printf("---------------------------------\n");
    // printf("%d\n", size4_arr);
    // printf("%d\n", size4_p);
    // printf("%d\n", size4_div);

    return 0;
}

// str1과str2의 차이명확히
//두개가 저장되는공간
//수정가능불가능