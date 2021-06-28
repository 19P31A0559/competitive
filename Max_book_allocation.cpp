#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[],int mid,int s,int n){
	int count=1,sum=0;
	for(int i=0;i<n;i++){
		if(sum+a[i]>mid){
			sum=a[i];
			count++;
			if(count>s) return false;
		}
		else{
			sum+=a[i];
		}
	}return true;
}

int MaxPages(int a[],int n,int s){
	int low=*min_element(a,a+n);
	int high=0,res=-1;
	for(int i=0;i<n;i++)high+=a[i];
	while(low<=high){
		int mid=low+((high-low)>>1);
		if(isPossible(a,mid,s,n)){
			res=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}return res;
}

int main(){
	int n,s;
	cin>>n>>s;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<MaxPages(a,n,s);
}
