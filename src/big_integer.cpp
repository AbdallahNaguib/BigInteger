#include "big_integer.h"
#include <algorithm>

bool isBigger(string number1,string number2){//this will return true only if number1 is bigger than 2
    int diff=number1.size()-number2.size();
    if(diff>0){
        return true;
    }else if(diff<0){
        return false;
    }
    for(int i=0 ; i<number1.size() ; i++){
        if(number1[i]>number2[i]){
            return true;
        }else if(number2[i]>number1[i]){
            return false;
        }
    }
    return false;//the two numbers are equal
}//this function is not a part of the class




big_integer::big_integer()
{
    num="";
}


big_integer::big_integer(string num){

    if(num[0]=='-'){
        isNeg=true;
        num=num.substr(1);//ignoring the negative sign
    }
    check(num);
    this->num=num;
}

string big_integer::getNum(){
    return num;
}

void big_integer::setNum(string num){
    if(num[0]=='-'){
        isNeg=true;
        num=num.substr(1);//ignoring the negative sign
    }
    check(num);
    this->num=num;
}

big_integer big_integer::operator-(big_integer b2){
    string number1=this->num;
    string number2=b2.getNum();


    if(this->isNeg && b2.isNeg){
        string temp=number1;
        number1=number2;
        number2=temp;
    }else if(this->isNeg){
        big_integer new_b1(this->num);
        big_integer new_b2(b2.getNum());
        big_integer res=new_b1+new_b2;//this returns their sum with their absolute values
        res.isNeg=true;
        return res;
    }else if(b2.isNeg){
         big_integer new_b1(this->num);
         big_integer new_b2(b2.getNum());
         cout<<"hello"<<endl;
         big_integer res=new_b1+new_b2;
         return res;
    }


    bool neg=false;
    if(isBigger(number2,number1)){//this condition is to make sure that number1 is bigger than number2
        neg=true;
        string temp=number1;
        number1=number2;
        number2=temp;
    }
    int diff=number1.size()-number2.size();
    if(diff>0){
        for(int i=0 ; i<diff ; i++){
            number2='0'+number2;
        }
    }
    int taken=0;
    string res="";
    for(int i=number1.size()-1 ; i>=0 ; --i){
        int char1=number1[i]-'0';
        int char2=number2[i]-'0';
        if(char1-taken<char2){
            res+=((char1-taken+10)-char2)+'0';
            taken=1;
        }else{
            res+=(char1-taken)-char2+'0';
            taken=0;
        }
    }
    reverse(res.begin(),res.end());
    big_integer res_num(res);
    if(neg){
        res_num.isNeg=true;
    }
    return res_num;
}



big_integer big_integer::operator+(big_integer b2){
    string number1=this->num;
    string number2=b2.getNum();
    bool resNeg=false;
    if(this->isNeg && b2.isNeg){
        resNeg=true;
    }else if(this->isNeg){
        big_integer new_b1(number1);
        big_integer new_b2(number2);
        big_integer res=new_b2-new_b1;
        return res;
    }else if(b2.isNeg){
         big_integer new_b1(number1);
         big_integer new_b2(number2);
         big_integer res=new_b1-new_b2;
         return res;
    }


    if(number1.size()>number2.size()){
        int diff=number1.size()-number2.size();
        for(int i=0 ; i<diff ; i++){
            number2='0'+number2;
        }
    }else{
        int diff=number2.size()-number1.size();
        for(int i=0 ; i<diff ; i++){
            number1='0'+number1;
        }
    }
    int carry=0;
    string res="";
    for(int i=number1.size()-1 ; i>=0 ; i--){
        int dig1=number1[i]-'0';
        int dig2=number2[i]-'0';
        if(dig1+dig2+carry>9){
            res+=(dig1+dig2+carry-10)+'0';
            carry=1;
        }else{
            res+=(dig1+dig2+carry)+'0';
            carry=0;
        }
    }
    if(carry==1){
        res+="1";
    }
    reverse(res.begin(),res.end());
    big_integer res_b(res);
    if(resNeg){
        res_b.isNeg=true;
    }
    return res_b;
}
void big_integer::check(string number){
    for(int i=0 ; i<number.size() ; i++){
        if(number[i]-'0' > 9 || number[i]-'0'<0 ){//this character is not a digit
            throw 0;
        }
    }
}
