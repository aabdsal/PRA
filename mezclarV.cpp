#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mezclar(vector <int> &a, int inf, int sup){
    if (inf >= sup) return;
    
    int mid = (inf + sup) / 2;
    int i = (inf + mid) / 2;
    int j = mid + 1;
    
    while(i <= mid)
    {
        swap(a[i], a[j]);
        i++;
        j++;
    }
    mezclar(a, inf, mid);
    mezclar(a, mid + 1, sup);
    
}

int main(){
    vector <int> a = {1,3,5,7,2,4,6,8};
    mezclar(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}