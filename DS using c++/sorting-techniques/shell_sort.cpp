#include <iostream>
#include <algorithm>
using namespace std;
const char line='\n';
int i,j,k;
void intialization(string a[],int n){
    cout<<"Enter student roll numbers separated by space : ";
    for (i=0;i<n;i++) cin>>a[i];
    cout<<line;
}
void shell_sort(string a[],int n){
    string temp;
    for(i=0;i<n;i++) transform(a[i].begin(),a[i].end(),a[i].begin(),::toupper);
    for(i=n/2;i>0;i/=2){
        for(j=i;j<n;j++){
            temp=a[j];
            for(k=j;k>=i && temp.compare(a[k-i])<0;k-=i) a[k]=a[k-i];
            a[k]=temp;
        }
    }
}
int main(){
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    string a[n];
    intialization(a,n);
    shell_sort(a,n);
    for(string i:a){
        cout<<i<<" ";
    }
    return 0;
}
