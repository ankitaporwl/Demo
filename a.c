#include<stdio.h>

void merge(int x[],int a[],int m1,int  b[],int m2){
	int i,j,k;
	for(i=0,j=0,k=0;i<m1 && j<m2;){
		if(a[i]<b[j])x[k++]=a[i++];
		else x[k++]=b[j++];
	}
	while(i<m1)x[k++]=a[i++];
	while(j<m2)x[k++]=b[j++];
}

System.out.printn();
void mergesort(int x[],int n){
	if(n==1)return;
	int m1=n/2,i;
	int m2=n-m1;
	int a[m1],b[m2];
	for(i=0;i<m1;i++){
		a[i]=x[i];
	}
	for(i=0;i<m2;i++){
		b[i]=x[i+m1];
	}
	mergesort(a,m1);
	mergesort(b,m2);
	merge(x,a,m1,b,m2);
}
void isort(int x[],int n){
	int i,j,value;
	for(i=1;i<n;i++){
		value=x[i];
		for(j=i;j>0;j--){
			if(x[j-1]>value){
				x[j]=x[j-1];
			}else break;
		}
		x[j]=value;
	}
}
void ssort(int x[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(x[min]>x[j])min=j;
		}
		if(min!=i){
			int t=x[i];
			x[i]=x[min];
			x[min]=t;
		}
	}
}
void heapify(int x[],int n,int i){
	int l=2*i+1;
	int r=2*i+2;
	int max=i;
	if(l<n && x[max]<x[l])max=l;
	if(r<n && x[max]<x[r])max=r;
	if(x[max]>x[i]){
		int t=x[max];
		x[max]=x[i];
		x[i]=t;
		heapify(x,n,max);
	}
}
void heapsort(int x[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(x,n,i);
	}
	for(int i=n-1;i>0;i--){
		int t=x[i];
		x[i]=x[0];
		x[0]=t;
		heapify(x,i,0);
	}
}
void reverse(int x[],int n){
	int i,j;
	for(i=0,j=n-1;i<j;i++,j--){
		int t=x[i];
		x[i]=x[j];
		x[j]=t;
	}
}
void csort(int x[],int n){
	int i,min=x[0],max=x[0];
	for(i=0;i<n;i++){
		if(min>x[i])min=x[i];
		if(max<x[i])max=x[i];
	}
	int y[n];
	max++;
	int a[max-min];
	for(i=0;i<max-min;i++)a[i]=0;
	for(i=0;i<n;i++)a[x[i]-min]++;
	for(i=1;i<max-min;i++)a[i]+=a[i-1];
	for(i=0;i<n;i++){
		y[a[x[i]-min]-=1]=x[i];
	}
	for(i=0;i<n;i++){
		x[i]=y[i];
	}
}
void radix(int x[],int n,int max,int div){
	int i;
	int y[n];
	int a[10]={0};
	for(i=0;i<n;i++){
		a[x[i]/div%10]++;
	}
	for(i=1;i<10;i++){
		a[i]+=a[i-1];
	}
	for(i=n-1;i>=0;i--){
		y[a[x[i]/div%10]-=1]=x[i];
	}
	for(i=0;i<n;i++)x[i]=y[i];
}
void rsort(int x[],int n){
	int i,min=x[0];
	for(i=0;i<n;i++){
		if(min>x[i])min=x[i];
	}
	for(i=0;i<n;i++){
		x[i]=x[i]-min;
	}
	int max=x[0];
	for(i=0;i<n;i++){
		if(x[i]>max)max=x[i];
	}
	
	for(i=1;i<=max;i*=10){
		radix(x,n,max,i);
	}
	for(i=0;i<n;i++)x[i]=x[i]+min;
}
void sort(int x[],int n){
	int left=0;
	int right=n-1;
	while(left<right){
		if(x[left]==2){
			int t=x[left];
			x[left]=x[right];
			x[right]=t;
			right--;
		}else if(x[right]==1){
			int t=x[left];
			x[left]=x[right];
			x[right]=t;
			left++;
		}else if(x[left]==1){
			left++;
		}
		else if(x[right]==2){
			right--;
		}
	}
}
void psort(int x[],int n){
	int left=0;
	int right=n-1;
	int c=0;
	while(left<=right){
		if(x[left]==0){
			x[c++]=0;
			left++;
		}
		/*else if(x[right]==1){
			int t=x[left];
			x[left]=x[right];
			x[right]=t;
			right--;
		}
		else if(x[left]==2){
			int t=x[left];
			x[left]=x[right];
			x[right]=t;
			left++;
		}*/
		
		else if(x[left]==2 && x[right]==1){
			int t=x[left];
			x[left]=x[right];
			x[right]=t;
			left++;
			right--;
		}else if(x[left])
	}
}
void main(){
	int x[]={1,0,2,1,2,0,2,2};
	int n=8;
	// mergesort(x,n);
	int i;
	// isort(x,n);
	// ssort(x,n);
	// heapsort(x,n);
	// reverse(x,n);
	// csort(x,n);
	// rsort(x,n);
	// sort(x,n);
	psort(x,n);
	for(i=0;i<n;i++)printf("%d\t",x[i]);
}