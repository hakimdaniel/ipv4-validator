// Ipv4 validator by Hakim

#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* args[]){

    if(argc != 2){
        cout << "Use format: " << args[0] << " <ipv4>" << endl;
        return 1;
    }

    string ip = args[1];
    int dot = 0;
    int start = 0;

    if(ip.length() > 15){
        cout << "Invalid: Length more than 15 characters." << endl;
        return 1;
    }

    for(int i = 0;i < ip.length();i++){
        if(ip[i] == '.'){
            if(start == 0){
                cout << "Invalid: Empty octet detected." << endl;
                return 1;
            }
            start = 0;
            dot++;
            if(dot > 3){
                cout << "Invalid: Too many dot." << endl;
                return 1;
            }
        }else{
            start++;
        }

        if(start > 3){
            cout << "Invalid: out of bit." << endl;
            return 1;
        }
    }

    cout << "Ip " << ip << " is valid!";
    cout << endl;
    return 0;
}
