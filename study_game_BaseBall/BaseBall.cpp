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

//���� �߱� 9���� ���ڸ� ������ �迭�� ����
void initBaseBall() {
	for (int i = 0; i < 9; i++) {
		BaseBall[i] = i + 1;
	}
}

void Shuffle() {
	int index1, index2;
	srand((unsigned int)time(0));

	//����� �ζǳѹ��� 100�� ����
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
		//����� �Է�
		cout << "1~9 ������ ���ڸ� �Է��ϼ���(0�� �� ����) : ";
		for (int i = 0; i < 3; i++) {
			cin >> User[i];
		}

		//���� ó��
		if (User[0] == 0 || User[1] == 0 || User[2] == 0) {
			cout << "������ ���� �մϴ�." << endl;
			cout << "" << endl;
			break;
		}
		else if (User[0] == User[1] || User[1] == User[2] || User[2] == User[0]) {
			cout << "���� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			cout << "" << endl;
			continue;
		}
		else if (0 > User[0] || User[0] > 9 || 0 > User[1] || User[1] > 9 || 0 > User[2] || User[2] > 9) {
			cout << "���� ���� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			cout << "" << endl;
			continue;
		}
		
		//�� ��
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (BaseBall[i] == User[j]) {//�迭�� �ִ� ��� ���ڸ� Ȯ���ؼ� ���� ���ڰ� �ִ��� Ȯ��(��� �ε��� ��)
					if (i == j)//���ڵ� ���� �ε����� ���ٸ�
						strike++;
					else//���ڴ� ������ �ε����� �ٸ���
						ball++;
					break;
				}		
		}
		

		if (strike == 3) {
			cout << strike << "strike�Դϴ�." << endl;
			cout <<"�����Դϴ�!" << endl;
			break;
		}
		else if (strike == 0 && ball == 0) {
			cout << strike << "out." << endl;
		}
		else {
			cout << strike << " strike�Դϴ�." << endl;
			cout << ball << " ball�Դϴ�." << endl;
		} 

		//�ʱ�ȭ
		strike = 0;
		ball = 0;
		cout << "" << endl;
	}
}