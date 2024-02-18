// The problem is from https://www.acmicpc.net/problem/5373
#include <iostream>

using namespace std;

void init(char upFace[9], char downFace[9], char frontFace[9], char backFace[9], char leftFace[9], char rightFace[9]){
	char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
	for(int i = 0; i < 9; i++){
		upFace[i] = color[0];
		downFace[i] = color[1];
		frontFace[i] = color[2];
		backFace[i] = color[3];
		leftFace[i] = color[4];
		rightFace[i] = color[5];
	}
}

void solution(char plane, char dir, char upFace[9], char downFace[9], char frontFace[9], char backFace[9], char leftFace[9], char rightFace[9]){
	char tmp[12];	
	if(plane == 'U'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = frontFace[i];
				tmp[i+3] = leftFace[i];
				tmp[i+6] = backFace[i];
				tmp[i+9] = rightFace[i];
			}
			for(int i = 0; i < 3; i++){
				leftFace[i] = tmp[i];
				backFace[i] = tmp[i+3];
				rightFace[i] = tmp[i+6];
				frontFace[i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = upFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					upFace[3*j+i] = tmp[6-i*3+j];		
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = frontFace[i];
				tmp[i+3] = rightFace[i];
				tmp[i+6] = backFace[i];
				tmp[i+9] = leftFace[i];
			}
			for(int i = 0; i < 3; i++){
				rightFace[i] = tmp[i];
				backFace[i] = tmp[i+3];
				leftFace[i] = tmp[i+6];
				frontFace[i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = upFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					upFace[3*j+i] = tmp[3*i+(2-j)];		
		}
	}
	else if(plane == 'D'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = frontFace[i+6];
				tmp[i+3] = rightFace[i+6];
				tmp[i+6] = backFace[i+6];
				tmp[i+9] = leftFace[i+6];
			}
			for(int i = 0; i < 3; i++){
				rightFace[i+6] = tmp[i];
				backFace[i+6] = tmp[i+3];
				leftFace[i+6] = tmp[i+6];
				frontFace[i+6] = tmp[i+9];
			}	
			for(int i = 0; i < 9; i++)
				tmp[i] = downFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					downFace[3*j+i] = tmp[3*i+(2-j)];	
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = frontFace[i+6];
				tmp[i+3] = leftFace[i+6];
				tmp[i+6] = backFace[i+6];
				tmp[i+9] = rightFace[i+6];
			}
			for(int i = 0; i < 3; i++){
				leftFace[i+6] = tmp[i];
				backFace[i+6] = tmp[i+3];
				rightFace[i+6] = tmp[i+6];
				frontFace[i+6] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = downFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					downFace[3*j+i] = tmp[6-i*3+j];		
		}
	}
	else if(plane == 'F'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[i+6];
				tmp[i+3] = rightFace[3*i];
				tmp[i+6] = downFace[8-i];
				tmp[i+9] = leftFace[8-i*3];
			}
			for(int i = 0; i < 3; i++){
				rightFace[3*i] = tmp[i];
				downFace[8-i] = tmp[i+3];
				leftFace[8-i*3] = tmp[i+6];
				upFace[i+6] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = frontFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					frontFace[3*j+i] = tmp[6-i*3+j];		
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[i+6];
				tmp[i+3] = leftFace[8-i*3];
				tmp[i+6] = downFace[8-i];
				tmp[i+9] = rightFace[3*i];
			}
			for(int i = 0; i < 3; i++){
				leftFace[8-i*3] = tmp[i];
				downFace[8-i] = tmp[i+3];
				rightFace[3*i] = tmp[i+6];
				upFace[i+6] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = frontFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					frontFace[3*j+i] = tmp[3*i+(2-j)];		
		}
	}
	else if(plane == 'B'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[i];
				tmp[i+3] = leftFace[6-3*i];
				tmp[i+6] = downFace[2-i];
				tmp[i+9] = rightFace[3*(i+1)-1];
			}
			for(int i = 0; i < 3; i++){
				leftFace[6-3*i] = tmp[i];
				downFace[2-i] = tmp[i+3];
				rightFace[3*(i+1)-1] = tmp[i+6];
				upFace[i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = backFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					backFace[3*j+i] = tmp[6-i*3+j];		
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[i];
				tmp[i+3] = rightFace[3*(i+1)-1];
				tmp[i+6] = downFace[2-i];
				tmp[i+9] = leftFace[6-3*i];
			}
			for(int i = 0; i < 3; i++){
				rightFace[3*(i+1)-1] = tmp[i];
				downFace[2-i] = tmp[i+3];
				leftFace[6-3*i] = tmp[i+6];
				upFace[i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = backFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					backFace[3*j+i] = tmp[3*i+(2-j)];		
		}
	}
	else if(plane == 'R'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[8-i*3];
				tmp[i+3] = backFace[3*i];
				tmp[i+6] = downFace[3*i+2];
				tmp[i+9] = frontFace[8-i*3];
			}
			for(int i = 0; i < 3; i++){
				backFace[3*i] = tmp[i];
				downFace[3*i+2] = tmp[i+3];
				frontFace[8-i*3] = tmp[i+6];
				upFace[8-i*3] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = rightFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					rightFace[3*j+i] = tmp[6-i*3+j];		
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[8-i*3];
				tmp[i+3] = frontFace[8-i*3];
				tmp[i+6] = downFace[3*i+2];
				tmp[i+9] = backFace[3*i];
			}
			for(int i = 0; i < 3; i++){
				frontFace[8-i*3] = tmp[i];
				downFace[3*i+2] = tmp[i+3];
				backFace[3*i] = tmp[i+6];
				upFace[8-i*3] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = rightFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					rightFace[3*j+i] = tmp[3*i+(2-j)];		
		}
	}
	else if(plane == 'L'){
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[3*i];
				tmp[i+3] = frontFace[3*i];
				tmp[i+6] = downFace[6-3*i];
				tmp[i+9] = backFace[8-i*3];
			}
			for(int i = 0; i < 3; i++){
				frontFace[3*i] = tmp[i];
				downFace[6-3*i] = tmp[i+3];
				backFace[8-i*3] = tmp[i+6];
				upFace[3*i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = leftFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					leftFace[3*j+i] = tmp[6-i*3+j];		
		}
		else if(dir == '-'){
			for(int i = 0; i < 3; i++){
				tmp[i] = upFace[3*i];
				tmp[i+3] = backFace[8-i*3];
				tmp[i+6] = downFace[6-3*i];
				tmp[i+9] = frontFace[3*i];
			}
			for(int i = 0; i < 3; i++){
				backFace[8-i*3] = tmp[i];
				downFace[6-3*i] = tmp[i+3];
				frontFace[3*i] = tmp[i+6];
				upFace[3*i] = tmp[i+9];
			}
			for(int i = 0; i < 9; i++)
				tmp[i] = leftFace[i];
			
			for(int j = 0; j < 3; j++)
				for(int i = 0; i < 3; i++)
					leftFace[3*j+i] = tmp[3*i+(2-j)];		
		}
	}
}

void input(char upFace[9], char downFace[9], char frontFace[9], char backFace[9], char leftFace[9], char rightFace[9]){
	int N;
	int n;	
	
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> n;
		init(upFace, downFace, frontFace, backFace, leftFace, rightFace);
		for(int j = 0; j < n; j++){
			string rot;
			cin >> rot;
			solution(rot[0], rot[1], upFace, downFace, frontFace, backFace, leftFace, rightFace);
		}
		for(int p = 0; p < 3; p++){
			for(int q = 0; q < 3; q++)
				cout << upFace[q+3*p];
			cout << "\n";
		}
	}
}

int main(){
	char upFace[9];
	char downFace[9];
	char frontFace[9];
	char backFace[9];
	char leftFace[9];
	char rightFace[9];

	input(upFace, downFace, frontFace, backFace, leftFace, rightFace);
}