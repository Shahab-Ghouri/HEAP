  
// 		© Copyright 2021 , OBAID ULLAH SHAHAB GHOURI 

#include <iostream>
#include <vector>
using namespace std;


void Heapify(vector <int>& vect , int size, int i){
	int left = 2*i+1;
	int right = 2*i+2;
	int max_num = i;		// suppose that the max_num is on the index i;
	
	// here 'i' is the parent node
	if(left < size &&  vect[left] > vect[max_num]){
		max_num = left;
	}
	if(right < size &&  vect[right] > vect[max_num]){
		max_num = right;
	}
	
	if(max_num != i){		// it means that the number at index i is not the maxium number
		
		swap(vect[i],vect[max_num]);
		Heapify(vect,size,max_num);
	}
	
	
}


void heapsort(vector<int>& a){
	int size = a.size();
	for(int i=size/2-1;i>=0;i--){
		Heapify(a,size,i);
	}
	
	for(int i = size-1 ; i>0 ;i--){
		swap(a[0],a[i]);
		Heapify(a,i,0);
	}
	
}


main(){
	vector<int> vect;
	int n,x;
	
	cout<<" Enter the size of array : ";cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		vect.push_back(x);
	}
	
	heapsort(vect);
	
	for(int i=0;i<vect.size();i++){
		cout<<" "<<vect[i];
	}
}
