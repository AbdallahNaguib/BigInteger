#include <iostream>
#include <big_integer.h>
using namespace std;
ostream& operator<<(ostream& out, big_integer& b){
    if(b.isNeg){
        cout<<'-';
    }
    int frstInd=0;//this variable is made to ignore the first zeros in the number
    bool nonZero=false;
    string number=b.getNum();
    for(int i=0 ; i<number.size() ; i++){
        if(number[i] != '0'){
            frstInd=i;
            nonZero=true;
            break;
        }
    }
    if(!nonZero){//this means that the number consists of zeros only (0000)
        cout<<'0'<<endl;
        return out;
    }
    cout<<number.substr(frstInd)<<endl;
    return out;
}
istream& operator>> (istream& in, big_integer& b){
    string num;
    in>>num;
    b.setNum(num);
    return in;
}

int main(){
    st:
        big_integer b1,b2;
        try{
            cin>>b1>>b2;
            big_integer sub=b1-b2;
            big_integer sum=b1+b2;
            cout<<"sum = "<<sum;
            cout<<"sub = "<<sub;
        }catch(int x){
            cout<<"not valid input"<<endl;
        }
    goto st;
}

