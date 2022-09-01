#include <apue/apue.h>

int main(void)
{
    char *arr;
    int len = 0;
    int i = 0;
    printf("Enter the length os your array: ");
    scanf("%d", &len);
    arr = (char *)malloc(sizeof(char) * len + 1);
    printf("Enter the content: ");
    scanf("%s", arr);
    arr[len] = '\0';

    printf("%s", arr);

    int *arr2 = NULL;
    int len2 = 0;
    printf("Enter the length of arr2: ");
    scanf("%d", &len2);
    arr2 = (int *)calloc(len2, sizeof(int));
    for (i = 0; i < len2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int len3;
    printf("Enter addition length: ");
    scanf("%d", &len3);
    arr2 = (int *)realloc((void *)arr2, len2+len3);
    for (i = 0; i < len2+len3; i++) {
        printf("%d ", arr2[i]);
    }
    return 0;
}