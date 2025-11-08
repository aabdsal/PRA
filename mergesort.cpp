#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(const vector<int>& left, const vector<int>& right){
    vector<int> arr;
    arr.reserve(left.size() + right.size());

    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()){
        if (left[i] < right[j]){
            arr.push_back(left[i]);
            i += 1;
        }
        else{
            arr.push_back(right[j]);
            j += 1;
        }
    }
    while (i < left.size()){
        arr.push_back(left[i]);
        i += 1;
    }
    while (j < right.size()){
        arr.push_back(right[j]);
        j += 1;
    }
    return arr;
}

vector<int> mergeSort(const vector<int>& a, int inf, int sup){
    if (inf > sup) return {};
    if (inf == sup) return vector<int>{ a[inf] };

    int mid = (inf + sup) / 2;
    vector<int> left = mergeSort(a, inf, mid);
    vector<int> right = mergeSort(a, mid + 1, sup);
    return Merge(left, right);
}

int main(){
    vector<int> a = {38,27,43,3,9,82,10};
    vector<int> res = mergeSort(a, 0, static_cast<int>(a.size()) - 1);
    for (int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}