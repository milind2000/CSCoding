#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,c,i;
        cin>>n>>c;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int low=0,high=a[n-1],mid, best =0;

        while(low <= high){
            mid = (low + high +1)/2;
            int cows=1;
            int left=0;

            for(i=1 ; i<n && cows<=c; i++){
                if(a[i]- a[left] >=mid){
                    left = i;
                    cows++;
              }
            }

            if(cows>=c){
                best= mid;
                low =mid +1;
            }
            else {
                high = mid-1;
            }
        }
        cout<<best<<endl;
    }
    return 0;
}
