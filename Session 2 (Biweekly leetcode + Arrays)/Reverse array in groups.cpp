/*
Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines of input. The first line of each test case consists of an integer N(size of array) and an integer K separated by a space. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each test case, print the modified array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018

Example:
Input
2
5 3
1 2 3 4 5
6 2
10 20 30 40 50 60

Output
3 2 1 5 4
20 10 40 30 60 50

Explanation:
Testcase 1: Reversing groups in size 3, first group consists of elements 1, 2, 3. Reversing this group, we have elements in order as 3, 2, 1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    vector<long long int> vec;
	    long long int num;
	    for(int i = 0; i<n; i++){
	        cin>>num; vec.push_back(num);
	    }
	    
	    int num_of_groups = n/k + ((n%k == 0)?0:1);
	    
	    for(int i = 0; i < num_of_groups; i++){
	        int start = i*k; 
	        int end;
	        if(i == num_of_groups-1 && n%k != 0){
	            end = n-1;
	        }
	        else end = (i+1)*k - 1;
	        while(start<end){
	            int temp = vec[start];
	            vec[start] = vec[end];
	            vec[end] = temp;
	            start++; end--;
	        }
	    }
	    
	    for(int i = 0; i<vec.size(); i++){
	        cout<<vec[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}