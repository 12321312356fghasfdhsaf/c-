//
//  main.cpp
//  classwork 21.02.2024
//
//  Created by Rodion Lovyannikov on 21.02.2024.
//

#include <iostream>
using namespace std;

int Rand(int a)
{
    return rand()%a;
}

void massOut(int a,int arr[])
{
    for(int i=0;i<a;++i)
    {
        cout<<arr[i]<<" ";
    }
}

void fillMassive(int a,int arr[])
{
    for(int i=0;i<a;++i)
    {
        arr[i]=rand()%a;
        
    }
}

int minarr(int a,int arr[])
{
    int min=INT32_MAX;
    for(int i=1;i<a;++i)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}

int maxarr(int a,int arr[])
{
    int max=0;
    for(int i=0;i<a;++i)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

void massSwap(int a,int arr[])
{
    int temp;
    for(int i = 0, j = a-1; i<j ; ++i, --j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

int simpleNumbers(int a,int arr[])
{
    int counter=a;
    for(int i=0;i<a;++i)
    {
        for(int j=2;j<arr[i];++j)
        {
            if(arr[i]%j==0||arr[i]==0||arr[i]==1)
            {
                --counter;
                break;
            }
        }
    }
    return counter;
}

void sortirovka(int a, int arr[],bool k)
{
    int temp;
    for(int i = 0;i<a;++i)
    {
        for(int j = a-1;j>i;--j)
        {
            if(k==true)
            {
                if(arr[i]<arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
            if(k==false)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    const int size=30;
    int arr[size]{};
    fillMassive(size,arr);
    massOut(size,arr);
    cout<<"\nTotal = "<<size<<" random elements"<<endl;
    cout<<"Max = "<<maxarr(size,arr)<<endl;
    cout<<"Min = "<<minarr(size,arr)<<endl;
    massSwap(size, arr);
    massOut(size, arr);
    cout<<"\nIn this array we have "<<simpleNumbers(size, arr)<<" simple numbers."<<endl;
    cout<<"Po vozrastaniy - 0, Po ubivaniu-1, input: ";
    bool k=true;
    cin>>k;
    sortirovka(size, arr, k);
    massOut(size, arr);
}
