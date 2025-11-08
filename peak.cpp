#include <iostream>
#include <vector>

using namespace std;

int peak(vector<int>& a, int inf, int sup){
    
    int mid = (inf + sup) / 2;

    if (mid == 0 || mid == a.size() - 1 || (a[mid - 1] < a[mid] && a[mid] > a[mid + 1]))
        return a[mid];
    else if(a[mid - 1] > a[mid]) return peak(a, inf, mid -1);
    else return peak(a, mid + 1, sup);
}

int main(int argc, char const *argv[])
{
    vector <int> a = {5,30,50,20,65};
    int res = peak(a, 0, a.size() - 1);
    cout << "El número pico es: " << res << endl;
    return 0; 
}
