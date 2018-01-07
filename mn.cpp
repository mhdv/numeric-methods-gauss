#include <iostream>

int main(){
	float A[3][3]={2, 3, -6,
				1, -6, 8,
				3, -2, 1 };
	float B[3][3]={1, 0, 0,
				0, 1, 0,
				0, 0, 1 };

	for(int j=0;j<3;j++){

		float tmp = A[j][j];
		for(int k=0; k<3; k++){
			A[j][k]=A[j][k]*(1/tmp);
			B[j][k]=B[j][k]*(1/tmp);
			std::cout << A[j][k] << "<-MNOZENIE\n";
		}
		for(int i=0;i<3;i++){
			if(i==j && i==3) break;
			if(i==j) i++;
			for(int k=0; k<3; k++){
				A[i][k]=A[i][k]-A[j][j]*A[i][j];
				B[i][k]=B[i][k]-A[j][j]*A[i][j];
				std::cout << A[i][k] << " <-ODEJMOWANIE\n";
			}
		}
	}
for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		std::cout << A[i][j] << " ";
	}
	std::cout << "\n";
}

for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		std::cout << B[i][j] << " ";
	}
	std::cout << "\n";
}

}

