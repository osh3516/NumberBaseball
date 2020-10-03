# include<iostream>
# include<time.h>
using namespace std;

int BaseBall[9];

void Swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//숫자 야구 9개의 숫자를 각각의 배열에 저장
void initBaseBall() {
	for (int i = 0; i < 9; i++) {
		BaseBall[i] = i + 1;
	}
}

void Shuffle() {
	int index1, index2;
	srand((unsigned int)time(0));

	//저장된 로또넘버를 100번 셔플
	for (int i = 0; i < 100; i++) {
		index1 = rand() % 45;
		index2 = rand() % 45;

		Swap(&BaseBall[index1], &BaseBall[index2]);
	}
}

int main() {
	int User[3];
	int strike = 0, ball = 0;

	Shuffle();

	while (1) {
		//사용자 입력
		cout << "1~9 사이의 숫자를 입력하세요(0일 때 종료) : ";
		for (int i = 0; i < 3; i++) {
			cin >> User[i];
		}

		//예외 처리
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
		
		//값 비교
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
			cout <<"정답입니다!" << endl;
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