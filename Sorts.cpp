#include<bits/stdc++.h>
using namespace std;
bool asc(int r, int l){
    return r < l;
}

bool desc(int r, int l){
    return r > l;
}

void insertion_sort(vector<int> &a, bool cmp(int, int)=asc){
    for(int i = 1; i < a.size(); ++ i)
        for(int j = i; j > 0 && cmp(a[j], a[j-1]); -- j)
            swap(a[j], a[j-1]);
}

void selection_sort(vector<int> &a, bool cmp(int, int)=asc){
    int n = (int)a.size(), id;
    while(n > 1){
        id = 0;
        for(int i = 1; i < n; ++ i)
            if(cmp(a[id], a[i])) id = i;
        swap(a[id], a[n-1]);
        -- n;
    }
}

void def_sort(vector<int> &a, bool cmp(int, int)=asc){
    for(int i = 0; i < a.size(); ++ i)
        for(int j = i + 1; j < a.size(); ++ j)
            if(cmp(a[j], a[i]))
                swap(a[j], a[i]);
}

void bubble_sort(vector<int> &a, bool cmp(int, int) = asc){
    int n = (int)a.size();
    while(n > 1){
        for(int i = 1; i < n; ++ i)
            if(cmp(a[i], a[i-1])) swap(a[i-1], a[i]);
        -- n;
    }
}
int main(){
    
}