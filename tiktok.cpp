int sc(int index){		//평가함수 플레이어 에게 유리할때는 양수, AI에게 유리할때는 음수
    int temp=0,s=0,row=3;

    for(int j=1;j<=3;j++){
        for(int i=1;i<=3;i++){
            if(board[index][i][j]==1) temp++;
        }
        if(temp==3)  s -= 1000000;
        else if(temp==2) s -= 100;
        else if(temp==1) s -= 1;
    }
    for(int j=1;j<=3;j++){
        for(int i=1;i<=3;i++){
            if(board[index][j][i]==1) temp++;
        }
        if(temp==3)  s -= 1000000;
        else if(temp==2) s -= 100;
        else if(temp==1) s -= 1;
    }

    for(int i=1;i<=3;i++){
        if(board[index][i][i]==1) temp++;
    }
    if(temp==3)  s -= 1000000;
    else if(temp==2) s -= 100;
    else if(temp==1) s -= 1;

    row=3;
    for(int i=1;i<=3;i++){
        if(board[index][i][row--]==1) temp++;
    }
    if(temp==3)  s -= 1000000;
    else if(temp==2) s -= 100;
    else if(temp==1) s -= 1;



    for(int j=1;j<=3;j++){
        for(int i=1;i<=3;i++){
            if(board[index][i][j]==2) temp++;
        }
        if(temp==3)  s += 1000000;
        else if(temp==2) s += 100;
        else if(temp==1) s += 1;
    }
    for(int j=1;j<=3;j++){
        for(int i=1;i<=3;i++){
            if(board[index][j][i]==2) temp++;
        }

        if(temp==3)  s += 1000000;
        else if(temp==2) s += 100;
        else if(temp==1) s += 1;
    }

    for(int i=1;i<=3;i++){
        if(board[index][i][i]==1) temp++;
    }

    if(temp==3)  s += 1000000;
    else if(temp==2) s += 100;
    else if(temp==1) s += 1;

    row=3;
    for(int i=1;i<=3;i++){
        if(board[index][i][row--]==1) temp++;
    }

    if(temp==3)  s += 1000000;
    else if(temp==2) s += 100;
    else if(temp==1) s += 1;

    return s;
}
