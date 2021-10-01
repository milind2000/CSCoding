#include <iostream>

using namespace std;

void bubbleSort(int a[]){

        for(int i=0;i<5;i++){
            bool flag= false;  //optimized algorithim

            for(int j=0;j<(5-i-1);j++){

                if(a[j]>a[j+1]){
                    flag=true;
                    int temp= a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }

            if(flag==false){
                break;
            }
        }
}

int main()
{
    int arr[5],i;
    cout<<"Enter the 5 elements:"<<endl;

    for(i=0;i<5;i++){
        cin>>arr[i];
    }

    bubbleSort(arr);

    cout<<"Sorted 5 elements:"<<endl;

    for(i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
