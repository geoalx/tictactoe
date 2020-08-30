#include<iostream>
using namespace std;

int max(int k[]){
    int ma = k[0];
    for(int o = 1; o<8;o++){
        if(k[o] > ma) ma = k[o];
    }
    return ma;
}

int min(int y[]){
    int mi = y[0];
    for(int r = 1; r <8; r++){
        if(y[r] < mi) mi = y[r];
    }
    return mi;
}

class tictactoe{
private:
    int a[3][3];
public:
    tictactoe() {
        cout << "THE GAME BEGINS"<<endl;
        for (int i = 0; i < 3; i++) {
            for (int u = 0; u < 3; u++) {
                a[i][u] = 0;
            }
        }
    }
    ~tictactoe(){
        cout <<"nice game"<<endl;
    }
    bool empty(){
        int sum = 0;
        for(int i = 0;i<3;i++){
            for(int u = 0; u<3;u++){
                sum += a[i][u];
            }
        }
        if(sum == 0) return true;
        return false;
    }
    int win(){
        int ho = 0;
        int ka = 0;
        int i = 0;
        int b[8];
        for(int u = 0; u < 8; u++){
            b[u] = 0;
        }
        while(ho < 3){
            for(int y = 0; y < 3; y++){
                b[i] += a[ho][y];
            }
            ho++;
            i++;
        }
        while(ka < 3){
            for(int t = 0; t < 3; t++){
                b[i] += a[t][ka];
            }
            ka++;
            i++;
        }
        b[6] = a[0][0] + a[1][1] + a[2][2];
        b[7] = a[0][2] + a[1][1] + a[2][0];
        if(max(b) == 3) return 1;
        else if(min(b) == -3) return -1;
        else return 0;
    }
    void moveX(int p1,int p2){
        a[p1][p2] = 1;
    }
    void moveO(int r1,int r2){
        a[r1][r2] = -1;
    }
    void playX()throw(logic_error){
        int x1,x2;
        cout << "Set X position"<<endl;
        cin>> x1 >>x2;
        if(a[x1][x2] == 0){moveX(x1,x2);}
        else if(abs(a[x1][x2]) == 1){logic_error("INVALID VALUE"); playX();}
        else if(x1<0 or x1>=3 or x2 < 0 or x2 >= 3 ){logic_error("INVALID VALUE"); playX();}
    }
    void playO()throw(logic_error){
        int o1,o2;
        cout << "Set O position"<<endl;
        cin>> o1 >>o2;
        if(a[o1][o2] == 0){moveO(o1,o2);}
        else if(abs(a[o1][o2]) == 1){logic_error("INVALID VALUE"); playO();}
        else if(o1<0 or o1>=3 or o2 < 0 or o2 >= 3 ){logic_error("INVALID VALUE"); playO();}
    }
    void print(){
        char c[3][3];
        for(int i = 0; i < 3;i++){
            for(int y = 0; y < 3; y++){
                if(a[i][y] == 0) c[i][y] = ' ';
                else if(a[i][y] == 1) c[i][y] = 'X';
                else c[i][y] = 'O';
            }
        }
        cout << c[0][0] << " | " << c[0][1] << " | " <<c[0][2]<<endl;
        cout << "--+---+--" <<endl;
        cout << c[1][0] << " | " << c[1][1] << " | " <<c[1][2]<<endl;
        cout << "--+---+--" <<endl;
        cout << c[2][0] << " | " << c[2][1] << " | " <<c[2][2]<<endl;
    }
    void play(){
        print();
        int t = 0;
        for(int i = 0; i < 2; i++){
            playX();
            print();
            playO();
            print();
        }
        while(true){
            playX();
            print();
            if(t == 2){cout <<"DRAW"<<endl; break;}
            else if(win() == 1){cout<<"X WINS" <<endl; break;}
            else if(win() == -1){cout << "O WINS"<<endl; break;}
            playO();
            print();
            if(win() == 1){cout<<"X WINS" <<endl; break;}
            else if(win() == -1){cout << "O WINS"<<endl; break;}
            t++;
        }
    }
};


int main(){
    tictactoe s;
    s.play();

}