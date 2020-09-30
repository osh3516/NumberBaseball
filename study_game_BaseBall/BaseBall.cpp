# include<iostream>
# include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));
	int BaseBall[9];
	int User[3];
	int Temp, Index1, Index2;
	int strike = 0, ball = 0;

	//BaseBall�迭�� 1~9������ ���ڸ� ����
	for (int i = 0; i < 9; i++)
		BaseBall[i] = i + 1;

	//����� �迭�� 100�� ������ �Ϻ��ϰ� ������ ���ڸ� ����
	for (int i = 0; i < 100; i++) {
		Index1 = rand() % 9;
		Index2 = rand() % 9;

		Temp = BaseBall[Index1];
		BaseBall[Index1] = BaseBall[Index2];
		BaseBall[Index2] = Temp;
	}

	/*
	//����� ���� Ȯ��
	for (int i = 0; i < 3; i++)
		cout << BaseBall[i] << "\t";
	cout <<""<< endl;
	*/
	
	
	


	while (1) {
		cout << "1~9 ������ ���ڸ� �Է��ϼ���(0�� �� ����) : ";
		for (int i = 0; i < 3; i++) {
			cin >> User[i];
		}

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
		
		/*
		//�Է��� ���� Ȯ��
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
			cout <<"������.... ���� �¹�¯...." << endl;
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