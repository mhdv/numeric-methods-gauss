#include <iostream>
#define n 3
#define m 4
// #define n 4
// #define m 5

// float A[n][m] ={{-1, -5, 0.5, 5.5, 9.5},
// 				{-2, 0, -1, 3, -3},
// 				{-1.5, -1.25, 0.5, -0.75, -1.5},
// 				{0, -1.25, 0.5, 5.5, 9.5}};

float A[n][m] = {{2, 3, -6, 1},
				 {1, -6, 8, 2},
				 {3, -2, 1, 3}};

float max;
int maxw;

void displayA(){
		for(int i=0; i<n; ++i){
		std::cout << "[ ";
		for(int j=0; j<m; ++j){
			std::cout << A[i][j] << "\t";
		}
		std::cout << "]\n";
	}
	std::cout << "\n";
}

int main(){
	displayA();
	// glowna petla programu
	for(int k=0; k<(n-1); ++k){
		// wybor elementu glownego
		max = 0;
		maxw = 0;
		for(int i=0; i<n; ++i){
			if(A[i][k]<0){
				int tmp = A[i][k]*(-1);
				if(tmp>=max){
					max = tmp;
					maxw = i;
				}
			}
			if(A[i][k]>=max){
				max = A[i][k];
				maxw = i;
			}
		}
		// zamiana wierszy
		float B[m];
		for(int i=0; i<m; ++i){
			B[i]=A[maxw][i];
			A[maxw][i]=A[k][i];
			A[k][i]=B[i];
		}
		// zamiana kolumn

		// obliczenie nowych wierszy
		float mnoznik = 0;
		for(int i=(k+1); i<n; ++i){
			mnoznik = A[i][k]/A[k][k];
			for(int j=k; j<m; ++j){
				A[i][j] = A[i][j] - mnoznik*A[k][j];
			}
		}
	}
	displayA();

	return 0;
}