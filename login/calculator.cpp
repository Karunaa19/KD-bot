#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;
void showCalculator(){
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"-                                            SCIENTIFIC                               -"<<endl;
    cout<<"---                                          CALCULATOR                            --- "<<endl;
    cout<<"-                                                                                     -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        +               |             -             |           *                      -"<<endl;
    cout<<"-       Add              |          Subtract         |         Multiply                 -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        /               |             m             |           L                     -"<<endl;
    cout<<"-     Diviide            |            Mod            |          Log                    -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        S               |             C             |           T                     -"<<endl;
    cout<<"-       sin              |            cos            |          tan                    -"<<endl;
     cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        S               |              C            |           P                      -"<<endl;
    cout<<"-      Square            |             Cube          |         Power                     -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        r               |             k             |           .                      -"<<endl;
    cout<<"-     sq root            |          clear            |         close                    -"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;



}
void displayOutput(int answer){
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"------                                                                ----------------"<<endl;
    cout<<"---                                           current                 |        "<<endl;
    cout<<"-                                             output is:              |"<<answer<<endl;
    cout<<"---                                                                    -----------------"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        +               |             -             |           *                      -"<<endl;
    cout<<"-       Add              |          Subtract         |         Multiply                 -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        /               |             m             |           L                     -"<<endl;
    cout<<"-     Diviide            |            Mod            |          Log                    -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        s               |             c             |           T                     -"<<endl;
    cout<<"-       sin              |            cos            |          tan                    -"<<endl;
     cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        S               |              C            |           P                      -"<<endl;
    cout<<"-      Square            |             Cube          |         Power                     -"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"-        r               |             k             |           .                      -"<<endl;
    cout<<"-     sq root            |          clear            |         close                    -"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;


}
int main(){

    double num1=0.0;
    double num2=0.0;
    double answer=0.0;
    bool converter=0;
    char inp='\n';
    showCalculator();
    while(inp!='.'){
        if (converter==1){

            

        }
        else{

        }
        cout<<"Enter: ";
        cin>>inp;
        if(inp=='+'||inp=='-'||inp=='*'||inp=='/'||inp=='m'||inp=='p'){
            cout<<"Enter num1: ";
            cin>>num1;
            cout<<"Enter num2: ";
            cin>>num2;

        }
        else if(inp=='k'||inp=='.'){

        }
        else{
            cout<<"Enter num1: ";
            cin>>num1;

        }
        switch(inp){
            case '+':
            answer=num1+num2;
            break;
            case '-':
            answer=num1-num2;
            break;
            case '*':
            answer=num1*num2;
            break;
            case '/':
            answer=num1/num2;
            break;
            case 'm':
            answer=int(num1)%int(num2);
            break;
            case 'L':
            answer=log(num1);
            break;
            case 'S':
            answer=num1*num1;
            case 'C':
            answer=num1*num1*num1;
            break;
            case 'p':
            answer=pow(num1,num2);
            break;
            case 's':
            answer=sin(num1);
            break;
            case 'c':
            answer=cos(num1);
            break;
            case 't':
            answer=tan(num1);
            break;
            case 'r':
            answer=sqrt(num1);
            case '.':
            break;
            default:
            cout<<"please! enter valid number"<<endl;

        }
        system("cls");
        displayOutput(answer);
    }
    return 0;
}