# include<iostream>
# include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));
	int BaseBall[9];
	int User[3];
	int Temp, Index1, Index2;
	int strike = 0, ball = 0;

	//BaseBall배열에 1~9까지의 숫자를 저장
	for (int i = 0; i < 9; i++)
		BaseBall[i] = i + 1;

	//저장된 배열을 100번 섞어줘 완벽하게 랜덤한 숫자를 만듬
	for (int i = 0; i < 100; i++) {
		Index1 = rand() % 9;
		Index2 = rand() % 9;

		Temp = BaseBall[Index1];
		BaseBall[Index1] = BaseBall[Index2];
		BaseBall[Index2] = Temp;
	}

	/*
	//저장된 숫자 확인
	for (int i = 0; i < 3; i++)
		cout << BaseBall[i] << "\t";
	cout <<""<< endl;
	*/
	
	
	


	while (1) {
		cout << "1~9 사이의 숫자를 입력하세요(0일 때 종료) : ";
		for (int i = 0; i < 3; i++) {
			cin >> User[i];
		}

		if (User[0] == 0 || User[1] == 0 || User[2] == 0) {
			cout << "게임을 종료 합니다." << endl;
			cout << "" << endl;
			break;
		}
		else if (User[0] == User[1] || User[1] == User[2] || User[2] == User[0]) {
			cout << "같은 숫자를 입력하셨습니다. 다시 입력해주세요." << endl;
			cout << "" << endl;
			continue;
		}
		else if (0 > User[0] || User[0] > 9 || 0 > User[1] || User[1] > 9 || 0 > User[2] || User[2] > 9) {
			cout << "범위 밖의 숫자를 입력하셨습니다. 다시 입력해주세요." << endl;
			cout << "" << endl;
			continue;
		}
		
		/*
		//입력한 숫자 확인
		for (int i = 0; i < 3; i++) {
			cout << User[i] << endl;
		}
		*/


		/*
		strike
		0 0		1 1		2 2  

		ball
		0 1	+		0 2
		1 0	+		1 2+
		2 0			2 1+
		*/
		
		/*
		for (int i = 0; i < 3; i++) {
			if (BaseBall[i] == User[i])
				strike++;
			else if (BaseBall[i] == User[i + 1])
				ball++;
			else if (BaseBall[i] == User[i - 1])
				ball++;
			else if (BaseBall[2] == User[0])
				ball++;
			else if (BaseBall[0] == User[2])
				ball++;
		}
		*/

		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (BaseBall[i] == User[j]) {//배열에 있는 모든 숫자를 확인해서 같은 숫자가 있는지 확인(모든 인덱스 비교)
					if (i == j)//숫자도 같고 인덱스도 같다면
						strike++;
					else//숫자는 같지만 인덱스가 다르면
						ball++;
					break;
				}		
		}
		

		if (strike == 3) {
			cout << strike << "strike입니다." << endl;
			cout <<"보덜덜.... 역시 태민짱...." << endl;
			break;
		}
		else if (strike == 0 && ball == 0) {
			cout << strike << "out." << endl;
		}
		else {
			cout << strike << " strike입니다." << endl;
			cout << ball << " ball입니다." << endl;
		} 

		//초기화
		strike = 0;
		ball = 0;
		cout << "" << endl;
	}
}