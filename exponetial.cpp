#include <iostream>
#include <vector>

using namespace std;

int exponentialSearch(int a[],int ini, int fini, int x)
{
    // base case
    if (ini >= fini || x < a[ini] || x > a[fini])return -1;
    
    if (a[ini] == x) return ini;
    else if(a[fini] == x) return fini;

    int mid = (ini + fini)/2;
    if (a[mid] == x) return mid;
    else if(a[mid] < x) return exponentialSearch(a, mid, fini, x);
    else return exponentialSearch(a, ini, mid, x);
}

// Exponential search algorithm
int main(void)
{
    int A[] = {2, 5, 6, 8, 9, 10};
    int target = 10;
 
    int n = sizeof(A)/sizeof(A[0]);
    int index = exponentialSearch(A, 0,n-1, target);
 
    if (index != -1) {
        printf("Element found at index %d\n", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}