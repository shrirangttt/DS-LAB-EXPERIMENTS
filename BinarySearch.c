#include <stdio.h>
int main()
{
    int a[100], n, i, key;
    int left, right, mid;
    int flag = 0, pos = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    left = 0;
    right = n - 1;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(a[mid] == key)
        {
            flag = 1;
            pos = mid + 1;
            break;
        }
        else if(key < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    if(flag == 1)
        printf("Element found at position %d", pos);
    else
        printf("Element not found");

    return 0;
}
