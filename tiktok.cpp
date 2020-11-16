var dx = [0, 1, 1, 1, 2, 2, 2, 3, 3, 3];
var dy = [0, 1, 2, 3, 1, 2, 3, 1, 2, 3];
var board = new Array(),score = [],cnt=1,ma=0;

for(var i=1;i<=4;i++){
    board[i] = new Array();
    for(var j=1;j<=4;j++){
        board[i][j] = new Array();
        for(var k=1;k<=4;k++){
            board[i][j][k] = 0;
        }
    }
    score[i] = 0;
}


function input(){
    if(ma==0) title();
    var k=0,t=1,cnt1=0,x,y;

    console.log("cls");
    console.log("  1 2 3");
    console.log("1 - - -");
    console.log("2 - - -");
    console.log("3 - - -");
    while(1){
        if(cnt==10){
            alert("무승부 입니다.");
            return ;
        }
        var cnt1 = 0,y,x,output = [], v=0;
        while(1){
            if (cnt % 2 != 0) var [y,x] = prompt("Player 1의 착수위치를 입력해주세요").split(" ");
            else var [y,x] = prompt("Player 2의 착수위치를 입력해주세요").split(" ");
            if(x<0||x>3||y<0||y>3||board[0][y][x]!=0){ 
                alert("잘못된 입력입니다. 다시 입력해주세요: ");
                if (cnt % 2 != 0)var [y,x] = prompt("Player 1의 착수위치를 입력해주세요").split(" ");
                else var [y,x] = prompt("Player 2의 착수위치를 입력해주세요").split(" ");
            }
            else break;
        }
        if(cnt%2!=0){
            board[0][y][x]=1; //player1 착수, board[0]은 루트노드
            score[0] = sc(0);
            if(score[0] < -5000){
                console.log("0 1 2 3");    //제일처음 판 출력
                for (var i = 1; i <4; i++) {
    
                    for(var j=1;j<4;j++) {
                        if (board[0][i][j] == 0) output[v++] = '-';
                        else if (board[0][i][j] == 1) output[v++] = 'O';
                        else if (board[0][i][j] == 2) output[v++] = 'X';
                    }
    
                    console.log(i+" "+output[0]+" "+output[1]+" "+output[2]);
                    v=0;
                }
                
                alert("Player 1의 승리! 다시하시겠습니까? Y/N ");
                return ;
            }
            for(var i = 1; i <= 9; i++){		//경우의 수 트리에 저장
                copy(0, i);
                if(board[i][dx[i]][dy[i]] != 0){		//이미 돌이 있는 경우
                    score[i] = -1000000;	//나중에 점수 계산(미니맥스 알고리즘)을 사용할때 논외로 빼놓기 위함
                    for(var j = 1; j <= 9; j++){
                        score[i*9+j] = -1000000;
                        for(var k = 1; k <= 9; k++){
                            score[(i*9+j)*9+k] = -1000000;
                        }
                    }
                }
                else{
                    board[i][dx[i]][dy[i]] = 2;
                    score[i] = sc(i);
                    for(var j = 1; j <= 9; j++){
                        copy(i, i*9+j);
                        if(board[i*9+i][dx[j]][dy[j]] != 0){		//이미 돌이 있는 경우
                            score[i*9+j] = -1;	//나중에 점수 계산(미니맥스 알고리즘)을 사용할때 논외로 빼놓기 위함
                            for(var k = 1; k <= 9; k++){
                                score[(i*9+j)*9+k] = -1000000;
                            }
                        }
                        else{
                            board[i*9+j][dx[j]][dy[j]] = 1;
                            score[i*9+j] = sc(i*9+j);
                            for(var k = 1; k <= 9; k++){
                                copy(i*9+j, (i*9+j)*9+k);
                                if(board[(i*9+j)*9+k][dx[j]][dy[j]] != 0){		//이미 돌이 있는 경우
                                    score[(i*9+j)*9+k] = -1000000;	//나중에 점수 계산(미니맥스 알고리즘)을 사용할때 논외로 빼놓기 위함
                                }
                                else{
                                    board[(i*9+j)*9+k][dx[j]][dy[j]] = 2;
                                    score[(i*9+j)*9+k] = sc((i*9+j)*9+k);
                                }
                            }
                        }
                    }
                }
            }
        }
        var temp = tree();
        board[0][dx[temp]][dy[temp]] = 2;
        score[0] = sc(0);
        cnt++;
        console.log("0 1 2 3");    //제일처음 판 출력
        for (var i = 1; i <4; i++) {

            for(var j=1;j<4;j++) {
                if (board[0][i][j] == 0) output[v++] = '-';
                else if (board[0][i][j] == 1) output[v++] = 'O';
                else if (board[0][i][j] == 2) output[v++] = 'X';
            }

            console.log(i+" "+output[0]+" "+output[1]+" "+output[2]);
            v=0;
        }

        if(score[0] > 5000){
            alert("AI의 승리!");
            return ;
        }
        cnt ++;
    }
}
input();



function tree(){
    var i, temp = -1, s;
    for(i = 1; i <= 9; i++){
        if(score[i] >= 5000){
            return i;
        }
        console.log(score[i]);
    }
    for(i = 91; i <= 819; i++){
        if(score[i/9] == -1000000){
            i += 8;
        }
        if(score[i] != -1000000){
            score[i/9] = Math.max(score[i/9], score[i]);
        }
    }
    for(i = 10; i <= 90; i++){
        if(score[i/9] == -1000000){
            i += 8;
        }
        if(score[i] != -1000000){
            score[i/9] = Math.min(score[i/9], score[i]);
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
        console.log(score[i]);
    }
    return temp;
}


function sc(index){		//평가함수 플레이어 에게 유리할때는 음수, AI에게 유리할때는 양수
    var i, j, s = 0,temp;
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


function copy(a,b){	//b 보드에 a보드를 복사함
    var i, j;
    for(i = 1; i <= 3; i++){
        for(j = 1; j<= 3;j++){
            board[b][i][j] = board[a][i][j];
        }
    }
}

function title(){ //타이틀
    ma++;
    while(1){
        var a = prompt("1.Start 2.Exit : ");
        if(a==1){
            input();
        }
        else if(a==2) exit(0);
        else alert("잘못된 입력입니다. 다시 입력해주세요 " );
    }
}

function re(){ //다시하기 입력받는 함수
    var a;
    while(1){
        var a = prompt('다시할려면 y 그만할려면 n 을 입력해주세요');
        if(a=='Y'||a=='y'){

            console.log("cls");
            console.log("0 1 2 3");    //제일처음 판 출력
            console.log("1 - - -");
            console.log("2 - - -");
            console.log("3 - - -");
            for(var i=0;i<4;i++){
                for(var j=0;j<4;j++){
                    board[0][i][j]=0;
                }
            }
            cnt=1;
            return ;
        }
        else if(a=='N'||a=='n'){
            exit(0);
        }
        else alert("잘못된 입력입니다. 다시 입력해주세요");
    }
}
