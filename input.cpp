#include<bits/stdc++.h>
using namespace std;
int dx[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
int dy[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
int board[800][4][4]={},cnt=1,ma=0, score[800];

void input();

void copy(int a, int b){	//b 보드에 a보드를 복사함  
	int i, j;
	for(i = 1; i <= 3; i++){
		for(j = 1; j<= 3;j++){
			board[b][i][j] = board[a][i][j]; 
		}
	}
	return 0;
}
void title(){ //타이틀
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
  	else cout << "잘못된 입력입니다. 다시 입력해주세요 : " ;
  }
}

void re(){ //다시하기 입력받는 함수
	char a;
	while(1){
	cin >> a;
	if(a=='Y'||a=='y'){
		system("cls");
		puts("0 1 2 3");    //제일처음 판 출력
		puts("1 - - -");
		puts("2 - - -");
		puts("3 - - -");
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				board[i][j]=0;
			}
		}
		cnt=1;
		return ;
	}
	else if(a=='N'||a=='n'){
		exit(0);
	}
	else cout << "잘못된 입력입니다. 다시 입력해주세요: ";
	}
}

void input(){
	if(ma==0) title();
  system("cls");
	int k=0,t=1,cnt1=0,x,y;
	puts("0 1 2 3");
	puts("1 - - -");
	puts("2 - - -");
	puts("3 - - -");
	while(1){
		if(cnt==10){
			cout << "무승부 입니다. 다시하시겠습니까? Y/N: ";
      			re();
		}
		for(int i=1;i<4;i++){									// 승리 판별;
			if(board[1][i]==1&&board[2][i]==1&&board[3][i]==1){
				cout << "Player 1의 승리! 다시하시겠습니까? Y/N : ";
				re();
			}
			if(board[1][i]==2&&board[2][i]==2&&board[3][i]==2){
				cout << "Player 2의 승리! 다시하시겠습니까? Y/N : ";
				re();
			}
		}
		for(int i=1;i<4;i++){
			if(board[i][1]==1&&board[i][2]==1&&board[i][3]==1){
				cout << "Player 1의 승리! 다시하시겠습니까? Y/N : ";
				re();
			}
			if(board[i][1]==2&&board[i][2]==2&&board[i][3]==2){
				cout << "Player 2의 승리! 다시하시겠습니까? Y/N : ";
				re();
			}
		}
		if(board[1][1]==1&&board[2][2]==1&&board[3][3]==1){
			cout << "Player 1의 승리! 다시하시겠습니까? Y/N : ";
			re();
		}
		if(board[1][1]==2&&board[2][2]==2&&board[3][3]==2){
			cout << "Player 2의 승리! 다시하시겠습니까? Y/N : ";
			re();
		}
		if(board[3][1]==1&&board[2][2]==1&&board[1][3]==1){
			cout << "Player 1의 승리! 다시하시겠습니까? Y/N : ";
			re();
		}
		if(board[3][1]==2&&board[2][2]==2&&board[1][3]==2){
			cout << "Player 2의 승리! 다시하시겠습니까? Y/N : ";
			re();
		}
		cnt1=0;
		if(cnt%2!=0) cout << "Player 1의 착수위치를 입력해주세요: ";
		else cout << "Player 2의 착수위치를 입력해주세요: ";
		while(1){
			cin >> x >> y;
			if(x<0||x>3||y<0||y>3||board[y][x]!=0) cout << "잘못된 입력입니다. 다시 입력해주세요: ";
			else break;
		}
		if(cnt%2!=0){
			board[0][y][x]=1; //player1 착수, board[0]은 루트노드 
			for(int i = 1; i <= 9; i++){		//경우의 수 트리에 저장 
				copy(0, i); 
				if(board[i][dx[i]][dy[i]] != 0){		//이미 돌이 있는 경우 
					score[i] = -1;	//나중에 점수 계산(미니맥스 알고리즘)을 사용할때 논외로 빼놓기 위함	
				}
				else{
					board[i][dx[i]][dy[i]] = 2;
				} 
				for(int j = 1; j <= 9; j++){
					copy(i, i*9+j);
					if(board[i*9+i][dx[j]][dy[j]] != 0){		//이미 돌이 있는 경우 
						score[i*9+j] = -1;	//나중에 점수 계산(미니맥스 알고리즘)을 사용할때 논외로 빼놓기 위함	
					}
					else{
						board[i*9+j][dx[j]][dy[j]] = 1;
					}
				}
			}	
		}
		else board[y][x]=2;         //player2 착수
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(i==0){           //가로줄 번호 출력
					cout << k << " ";
					k++;
					continue;
				}
				if(j==0){           //세로줄 번호 출력
					cout << t << " ";
					t++;
					continue;
				}
				if(board[i][j]==0) cout << "- ";
				else if(board[i][j]==1) cout << "O ";
				else if(board[i][j]==2) cout << "X ";
			}
			puts("");
		}
		t=1,k=0;
	cnt ++;
	}
}
int main(){
  	input();
}
