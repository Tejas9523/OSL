#include<iostream>
using namespace std;
int main(){
int n,r;
cout<<"Enter no of processes - ";
cin>>n;
cout<<"Enter no of resources - ";
cin>>r;
// int all[n][r], max[n][r], avl[n];
int need[n][r], p[n],ans[n],ind=0;

int all[5][3]={{0,1,0},
            {2,0,0},
            {3,0,2},
            {2,1,1},
            {0,0,2}
};
            
int max[5][3]={{7,5,3},
            {3,2,2},
            {9,0,2},
            {2,2,2},
            {4,3,3}
    
};
            
int avl[3]={3,3,2};

// for (int i=0; i<n; i++ ){
//     for (int j=0; j<r; j++){
//         cout<<"Enter allocated time of p"<<i<<" - ";
//         cin>>all[i][j];
//     }
// }

// for (int i=0; i<n; i++ ){
//     for (int j=0; j<r; j++){
//         cout<<"Enter Max time of p"<<i<<" - ";
//         cin>>max[i][j];
//     }
// }

// for (int i=0; i<r; i++){
//     cout<<"Enter Available time - ";
//     cin>>avl[i];
// }

for (int i=0; i<n; i++ ){
    for (int j=0; j<r; j++){
        need[i][j]=max[i][j]-all[i][j];
    }
}

for (int i=0; i<n; i++){
    p[i]=0;
}

	for (int k = 0; k < n; k++) { 
		for (int i = 0; i < n; i++) { 
			if (p[i] == 0) { 

				int flag = 0; 
				for (int j = 0; j < r; j++) { 
					if (need[i][j] > avl[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (int a = 0; a < r; a++) {
						avl[a] += all[i][a]; 
                        }
					p[i] = 1; 
				} 
			} 
		} 
	} 


cout<<"Safer sequence is - ";
for (int i=0; i<n; i++){
    cout<<"p"<<ans[i]<<" -> ";
    }
}