//
//  main.cpp
//  TFI
//
//  Created by кирилл корнющенков on 25/09/2019.
//  Copyright © 2019 кирилл корнющенков. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool check(string& line,char& time, int& count){
    for (int i=0;i<line.length();i++){
        if ((line[i] == '0' || line[i] == '1') && (line[i] == time)){
            count++;
        }else{
            count = 0;
        }
        time = line[i];
    }
    
    
    if (count >= 3){
        return 1;
    }
    
    return 0;
}

int main() {
    string line;
    
    cin >> line;
    
    int count = 0;
    char time = ' ';
    
    bool answer_chekc_func = check(line,time,count);
    
    if (answer_chekc_func == 1){
        cout << "Введенная последоваткельность правильная" << endl;
    }else{
        cout << "Введенная последовательность не правильная" << endl;
    }
    
    return 0;
}
