#include<bits/stdc++.h>
using namespace std;
int dx[24] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy[24] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
int board[14500][11][11]={},cnt=1,ma=0, score[14500];

void input();

int tree(void){
	int i, temp = -1, s;
	for(i = 1; i <= 9; i++){
		if(score[i] >= 5000){
			return i;
		}
		printf("%d ", score[i]);
	}
	printf("\n");
	for(i = 91; i <= 819; i++){
		if(score[i/9] == -1000000){
			i += 8;
		}
		if(score[i] != -1000000){
			score[i/9] = max(score[i/9], score[i]);
		}
	}
	for(i = 10; i <= 90; i++){
		if(score[i/9] == -1000000){
			i += 8;
		}
		if(score[i] != -1000000){
			score[i/9] = min(score[i/9], score[i]);
		}
	}
	s = -1000001;
	for(i = 1; i <= 9; i++){
		if(score[i] != -1000000){
			if(score[i] >= s){
				temp = i;
				s = score[i];
			}
		}
	}
	for(i = 1; i <= 9; i++){
		printf("%d ", score[i]);
	}
	return temp;
}


int sc(int index){		//���Լ� �÷��̾� ���� �����Ҷ��� ����, AI���� �����Ҷ��� ��� 
	int i, j, s = 0,temp; 
	for(i = 1; i <= 3; i++){
		temp = 0;
		for(j = 1; j <= 3; j++){
			if(board[index][i][j] == 2){
				temp++;
			}
		}
		if(temp == 3){
			s += 10000;
		}
		else if(temp == 2){
			s += 100;
		}
		else if(temp == 1){
			s += 1;
		}
		temp = 0;
		for(j = 1; j <= 3; j++){
			if(board[index][j][i] == 2){
				temp++;
			}
		}
		if(temp == 3){
			s += 10000;
		}
		else if(temp == 2){
			s += 100;
		}
		else if(temp == 1){
			s += 1;
		}
	}
	for(i = 1; i <= 3; i++){
		temp = 0;
		for(j = 1; j <= 3; j++){
			if(board[index][i][j] == 1){
				temp++;
			}
		}
		if(temp == 3){
			s -= 10000;
		}
		else if(temp == 2){
			s -= 100;
		}
		else if(temp == 1){
			s -= 1;
		}
		temp = 0;
		for(j = 1; j <= 3; j++){
			if(board[index][j][i] == 1){
				temp++;
			}
		}
		if(temp == 3){
			s -= 10000;
		}
		else if(temp == 2){
			s -= 100;
		}
		else if(temp == 1){
			s -= 1;
		}
	}
	temp = 0;
	for(i = 1; i <= 3; i++){
		if(board[index][i][i] == 2){
			temp ++;
		}
	}
	if(temp == 3){
		s += 10100;
	}
	else if(temp == 2){
		s += 110;
	}
	else if(temp == 1){
		s += 2;
	}
	temp = 0;
	for(i = 1; i <= 3; i++){
		if(board[index][i][4-i] == 2){
			temp ++;
		}
	}
	if(temp == 3){
		s += 10100;
	}
	else if(temp == 2){
		s += 110;
	}
	else if(temp == 1){
		s += 2;
	}
	temp = 0;
	for(i = 1; i <= 3; i++){
		if(board[index][i][i] == 1){
			temp ++;
		}
	}
	if(temp == 3){
		s -= 10300;
	}
	else if(temp == 2){
		s -= 230;
	}
	else if(temp == 1){
		s -= 2;
	}
	temp = 0;
	for(i = 1; i <= 3; i++){
		if(board[index][i][4-i] == 1){
			temp ++;
		}
	}
	if(temp == 3){
		s -= 10300;
	}
	else if(temp == 2){
		s -= 230;
	}
	else if(temp == 1){
		s -= 2;
	}
	return s;	
}


void copy(int a, int b){	//b ���忡 a���带 ������  
	int i, j;
	for(i = 1; i <= 10; i++){
		for(j = 1; j<= 10;j++){
			board[b][i][j] = board[a][i][j]; 
		}
	}
}

void title(){ //Ÿ��Ʋ
  ma++;
  system("cls");
  puts("Tic-Tac-Toe");
  int a;
  cout << "1.Start 2.Exit : ";
  while(1){
  	cin >> a;
  	if(a==1){
    	input();
  	}
    else if(a==2) exit(0);
  	else cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ��� : " ;
  }
}

void re(){ //�ٽ��ϱ� �Է¹޴� �Լ�
	char a;
	while(1){
	cin >> a;
	if(a=='Y'||a=='y'){
		system("cls");
		puts("0 1 2 3");    //����ó�� �� ���
		puts("1 - - -");
		puts("2 - - -");
		puts("3 - - -");
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				board[0][i][j]=0;
			}
		}
		cnt=1;
		return ;
	}
	else if(a=='N'||a=='n'){
		exit(0);
	}
	else cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
	}
}

void input(){
	if(ma==0) title();
  system("cls");
	int k=0,t=1,cnt1=0,x,y;
	puts("0 1 2 3 4 5 6 7 8 9 X");
	puts("1 - - - - - - - - - -");
	puts("2 - - - - - - - - - -");
	puts("3 - - - - - - - - - -");
	puts("4 - - - - - - - - - -");
	puts("5 - - - - - - - - - -");
	puts("6 - - - - - - - - - -");
	puts("7 - - - - - - - - - -");
	puts("8 - - - - - - - - - -");
	puts("9 - - - - - - - - - -");
	puts("X - - - - - - - - - -");	
	while(1){
		printf("cnt : %d \n", cnt);
		if(cnt==10){
			cout << "���º� �Դϴ�. �ٽ��Ͻðڽ��ϱ�? Y/N: ";
      		return ;
		}
		if(cnt%2!=0) cout << "Player 1�� ������ġ�� �Է����ּ���: ";
		else cout << "Player 2�� ������ġ�� �Է����ּ���: ";
		while(1){
			cin >> y >> x;
			if(x<0||x>10||y<0||y>10||board[0][y][x]!=0) cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
			else break;
		}
		if(cnt%2!=0){
			board[0][y][x]=1; //player1 ����, board[0]�� ��Ʈ���
			score[0] = sc(0);
			for(int i = 1; i <= 24; i++){
				if(board[i][dx[i]][dy[i]] != 0){
					score[i] = -1;
				}
				else{
					board[i][dx[i]][dy[i]] = 2;
				}
			}
		}
		int temp = tree();
		board[0][dx[temp]][dy[temp]] = 2;
		score[0] = sc(0);
		cnt++;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(i==0){           //������ ��ȣ ���
					cout << k << " ";
					k++;
					continue;
				}
				if(j==0){           //������ ��ȣ ���
					cout << t << " ";
					t++;
					continue;
				}
				if(board[0][i][j]==0) cout << "- ";
				else if(board[0][i][j]==1) cout << "O ";
				else if(board[0][i][j]==2) cout << "X ";
			}
			puts("");
		}
		t=1,k=0;
		printf("score : %d \n", score[0]);
		if(score[0] > 5000){
			cout << "AI�� �¸�! �ٽ��Ͻðڽ��ϱ�? Y/N : ";
			return ;
		}
	cnt ++;
	}
}
int main(){
  	input();
}

