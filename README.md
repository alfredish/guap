//
//  main.cpp
//  guapMaimProject
//
//  Created by кирилл корнющенков on 05/09/2019.
//  Copyright © 2019 кирилл корнющенков. All rights reserved.
//

//что надо
//вводить информацию, хранить её в файле, осуществлять поиск, модификацию, сортировку и удаление данных

/*
 Предметная область – «Информация о сотрудниках».
 Данные о человеке хранятся в структуре с именем ZNAK, содержащей следующие поля:
  фамилия, имя;
  знак зодиака;
  дата рождения (массив из трёх чисел).
 Задание на поиск: найти информацию о людях, родившихся в месяц, значение которого введено с клавиатуры.
*/


//сделать проверку даты и введенных данных вообще 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct data {
    string name;
    string soname;
    int month;
    int day;
    int year;
    string badassSign;
};

//ввод данных
string coutCin(string text){
    string var;
    cout << text;
    cin >> var;
    return var;
}

//проверка корректности ввода даты рождения
bool checkDate(string date,data &timeData){
    int day = atoi(date.substr(0,2).c_str());
    int month = atoi(date.substr(3,2).c_str());
    int year = atoi(date.substr(6,4).c_str());
    
    if ((day > 0 && day < 32) && (month > 0 && month < 13) && (year > 0 && year < 2019) && (date.substr(2,1) == "." && date.substr(5,1) == ".") && date.length() == 10){
        timeData.day = day;
        timeData.month = month;
        timeData.year = year;
        return 1;
    }
    return 0;
}

// определение знака задиака
string badass(int day,int month){
    if ((month == 3 && day > 20) ||(month == 4 && day < 21)) {
        return "Овен";
    }else if ((month == 4 && day > 20) || (month == 5 && day < 21)){
        return "Телец";
    }else if ((month == 5 && day > 20) || (month == 6 && day < 22)){
        return "Близнецы";
    }else if ((month == 6 && day > 21) || (month == 7 && day < 23)){
        return "Рак";
    }else if ((month == 7 && day > 22) || (month == 8 && day < 24)){
        return "Лев";
    }else if ((month == 8 && day > 23) || (month == 9 && day < 24)){
        return "Дева";
    }else if ((month == 9 && day > 23) || (month == 10 && day < 24)){
        return "Весы";
    }else if ((month == 10 && day > 23) || (month == 11 && day < 23)){
        return "Скорпион";
    }else if ((month == 11 && day >22) || (month == 12 && day < 22)){
        return "Стрелец";
    }else if ((month == 12 && day > 21) || (month == 1 && day < 21)){
        return "Козерог";
    }else if ((month == 1 && day > 20) || (month == 2 && day <21)){
        return "Водолей";
    }else if ((month == 2 && day > 20) || (month == 3 && day < 21)){
        return "Рыбы";
    }
    return "error";
}

//меню
void menu(){
    cout << "/-----------------------------------------------\\" << endl;
    cout << "|            Информация о сотрудниках           |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "| 1 - добавление нового пользователя            |" << endl;
    cout << "| 2 - поиск                                     |" << endl;
    cout << "| 3 - изменение данных пользователя             |" << endl;
    cout << "| 4 - сортировка пользователей по алфавиту      |" << endl;
    cout << "| 5 - сортировка пользователей по знаку задиака |" << endl;
    cout << "| 6 - сортировка пользователей по дате рождения |" << endl;
    cout << "| 7 - удалить пользователя                      |" << endl;
    cout << "\\-----------------------------------------------/" << endl << endl;
    
}


//добавление данных
data add(){
    data timeData;
    timeData.soname = coutCin("Введите фамилию: ");
    timeData.name = coutCin("Введите имя: ");
    string date = coutCin("Дата рождения в фортате ДД.ММ.ГГГГ: ");
    
    if (!checkDate(date,timeData)){
        cout << "плохая дата" << endl;
    }
    
    timeData.badassSign = badass(timeData.day,timeData.month);
    
    return timeData;
}




int main() {
    vector<data> mainData;
    int digite;
    fstream file;
    
    bool check = true;
    
    while (check) {
        menu();
        
        cin >> digite;
        
        switch (digite) {
            case 1:
                mainData.push_back(add());
                break;
            default:
                break;
        }
        
        check = false;
    }
    
    return 0;
}
