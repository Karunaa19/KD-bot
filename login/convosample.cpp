#include <iostream>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
class bot{
    public:
    void getinput();
    void showinput();

};
int main(){
unordered_map<string,string>memory;
string user_input;

transform(user_input.begin(),user_input.end(),user_input.begin(),::tolower);
cout<<"welcome user,i am chatbot"<<endl;

while (true){
    getline(cin,user_input);
    transform(user_input.begin(),user_input.end(),user_input.begin(),::tolower);
    if(user_input=="hi"||user_input=="hello"||user_input=="hey"){
        cout<<"hello user,how can i help you?"<<endl;

    }
    else if(user_input=="how are you"||user_input=="are you ok"){
        cout<<"as a bot ,i have no feelings or emotion"<<endl;

    }
    else if(user_input=="what's my name?"){
        if (memory.find("name")!=memory.end()){
            cout<<"your name is "<<memory["name"]<<endl;
        }
        else{
            cout<<"sorry,YOu didnt tell me your name"<<endl;
        }
        else if(user_input.find("my name is")!=string::npos){
            size_t pos = user_input.find("my name is : ");
            string name =user_input.substr(pos+11);
            memory["name"]=name;
            cout<<"nice to meet you "<<name<<endl;
        }
        else if(user_input=="bye"||user_input=="see you later"||user_input=="later"){
            cout<<"bye";
            break;
        }
        else {
            cout<<"i didnt get that sorry"<<endl;
        }
    }
}
return 0;
}
