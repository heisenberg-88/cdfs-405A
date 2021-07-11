#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int col;
	cin>>col;
	int colu=col;
	vector<int> colarr;
	while(col--){
		int temp;
		cin>>temp;
		colarr.push_back(temp);
	}
	
	
	int row = *max_element(colarr.begin(),colarr.end());
	vector<vector<int>> mat(row,vector<int>(colu,0));
	
	for(int i=0;i<colu;i++){
		for(int j=row-1;j>=0;j--){
			if(colarr[i]>0){
				mat[j][i]=1;
			}
			colarr[i]--;
		}
	}
	
	vector<int> rowarr(row,0);
	for(int i=0;i<row;i++){
		for(int j=0;j<colu;j++){
			if(mat[i][j]==1){
				rowarr[i]++;
			}
		}
	}
	vector<vector<int>> maty(row,vector<int>(colu,0));
	
	for(int i=row-1;i>=0;i--){
		int j=colu-1;
		while(rowarr[i]>0){
			maty[i][j]=1;
			j--;
			rowarr[i]--;
			
		}
	}
	
	vector<int> ans(colu,0);
	for(int i=0;i<colu;i++){
		for(int j=0;j<row;j++){
			if(maty[j][i]==1){
				ans[i]++;
			}
		}
	}
	cout<<endl;
	for(auto i:ans){
		cout<<i<<" ";
	}
	
}	
	
	