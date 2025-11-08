#include <iostream>
using namespace std;

int count(int nums[], int ini, int fini)
{
    if (nums[fini] == 0) return 0;
    if (nums[ini]==1) return fini - ini + 1;
    
    int mid = (ini + fini)/2;

    if (nums[mid]==0) return count(nums,mid + 1, fini);
    else if(nums[mid]== 1) return count(nums,ini,mid) + count(nums,mid+1,fini);
}
 
int main()
{
    int nums[] = {0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("El numero total de 1's presentes es %d\n", count(nums, 0,n-1));
 
    return 0;
}