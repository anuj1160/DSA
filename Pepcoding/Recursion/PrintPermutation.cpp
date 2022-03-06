#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.size()==0)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        string lpart=str.substr(0,i);
        string rpart=str.substr(i+1);
        string ros=lpart+rpart;
        printPermutations(ros,asf+ch);
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}