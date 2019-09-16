//
//  main.cpp
//  guapMaimProject
//
//  Created by кирилл корнющенков on 05/09/2019.
//  Copyright © 2019 кирилл корнющенков. All rights reserved.
//

//что надо
//вводить информацию, хранить её в файле, осуществлять поиск, модификацию, сортировку и удаление данных

/*
 Предметная область – «Информация о сотрудниках».
 Данные о человеке хранятся в структуре с именем ZNAK, содержащей следующие поля:
  фамилия, имя;
  знак зодиака;
  дата рождения (массив из трёх чисел).
 Задание на поиск: найти информацию о людях, родившихся в месяц, значение которого введено с клавиатуры.
*/



//removePeople и dataChange большой общий кусок кода, который надо вынести в функцию !!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;


struct ZNAK {
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

//ввод данных в int
int coutCinInt(string text){
    int var;
    cout << text;
    cin >> var;
    return var;
}

//проверка корректности ввода даты рождения
bool checkDate(string date,ZNAK &timeData){
    
    if (date.length() != 10) {
        return 0;
    }
    
    int day = atoi(date.substr(0,2).c_str());
    int month = atoi(date.substr(3,2).c_str());
    int year = atoi(date.substr(6,4).c_str());
    
    if ((day > 0 && day < 32) && (month > 0 && month < 13) && (year > 0 && year < 2019) && (date.substr(2,1) == "." && date.substr(5,1) == ".")){
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
    cout << "| любая другая цифра, буква выход из программы  |" << endl;
    cout << "\\-----------------------------------------------/" << endl << endl;
    
}


//добавление данных
ZNAK add(){
    ZNAK timeData;
    timeData.soname = coutCin("Введите фамилию: ");
    timeData.name = coutCin("Введите имя: ");
    string date = coutCin("Дата рождения в фортате ДД.ММ.ГГГГ: ");
    
    if (!checkDate(date,timeData)){
        cout << "Вы ввели некоректную дату рождения" << endl;
    }else{
        timeData.badassSign = badass(timeData.day,timeData.month);
    }
    
    cout << endl << endl << "Данные успешно добавлены " << endl << endl;
    return timeData;
}


//поиск: найти информацию о людях, родившихся в месяц, значение которого введено с клавиатуры.
void findPeople(vector<ZNAK> &timeData){
    vector<ZNAK> infoFindPeople;
    
     int month = coutCinInt("Введите месяц, в котором родились люди: ");
    
    for (int i=0; i<timeData.size();i++){
        if (timeData[i].month == month){
            infoFindPeople.push_back(timeData[i]);
        }
    }
    
    if (infoFindPeople.size() == 0){
        cout << "В базе данных нету людей родившихся в этом месяце" << endl;
    }else {
        for(int i=0;i<infoFindPeople.size();i++){
            cout << "Имя, фамилия : " << infoFindPeople[i].name << " " << infoFindPeople[i].soname << ". Дата рождения: " << infoFindPeople[i].day << "." << infoFindPeople[i].month << "." << infoFindPeople[i].year << ". Знак задиака: " << infoFindPeople[i].badassSign << "." << endl;
        }
    }
}




// изменение имени
void changeName(vector<ZNAK> &data,int &index){
    string newName = coutCin("Введите новое имя: ");
    data[index].name = newName;
}

//изменение фамилии
void changeSoname(vector<ZNAK> &data,int &index){
    string newSoname = coutCin("Введите новую фамилию: ");
    data[index].soname = newSoname;
}
//изменение даты рожедения и гороскопа автоматически
void changeDate(vector<ZNAK> &data,int &index){
    ZNAK timeData;
    string date = coutCin("Дата рождения в фортате ДД.ММ.ГГГГ: ");
    
    if (!checkDate(date,timeData)){
        cout << "Вы ввели некоректную дату рождения" << endl;
    }else{
        data[index].badassSign = badass(timeData.day,timeData.month);
        data[index].day = timeData.day;
        data[index].month = timeData.month;
        data[index].year = timeData.year;
    }
}

//поиск людей по имени и фамилии    возвращает массив индексов
vector<int> findPeopleForNameAndSoname(vector<ZNAK> &data){
    string soname = coutCin("Введите фамилию пользователя: ");
    string name = coutCin("Введите текущее имя: ");
    
    vector<int> index;
    
    for (auto i=0;i<data.size();i++){
        if (data[i].name == name && data[i].soname == soname){
            index.push_back(i);
        }
    }
    return index;
}



//изменения данных
void dataChange(vector<ZNAK> &data){
    
    //ищем совпадения
    vector<int> timeData = findPeopleForNameAndSoname(data);
   
    //что хотил поменять
    if (timeData.size() > 0){
        cout << endl;
        for (auto i=0;i<timeData.size();i++){
            cout << i+1 << " : " << data[i].name << " " << data[i].soname <<  " " << data[i].day << "." << data[i].month << "." << data[i].year << " " << data[i].badassSign << endl << endl << endl;
        }
        
        int personIndex = coutCinInt("Выберите нужного пользователя: ");
        
        if (personIndex > 0 && personIndex < timeData.size()+1){
            personIndex--;
            cout << "Что вы хотите изменить ? Введите последовательность цифр." << endl;
            cout << "1 - Имя" << endl;
            cout << "2 - Фамилия" << endl;
            cout << "3 - дата рождения" << endl;
            
            int digite = coutCinInt("");
            
            switch (digite) {
                case 1:
                    changeName(data,personIndex);
                    break;
                case 2:
                    changeSoname(data,personIndex);
                    break;
                case 3:
                    changeDate(data,personIndex);
                    break;
                default:
                    break;
            }
        }else{
            cout << endl <<  "Таких пользователей не найдено " << endl;
        }
    }else {
        cout << endl <<  "Таких пользователей не найдено " << endl;
    }
    
}


//удаление пользователя
void removePeople(vector<ZNAK> &data){
   
    vector<int> index = findPeopleForNameAndSoname(data);
    
    //что хотил поменять
    if (index.size() > 0){
        cout << endl;
        for (auto i=0;i<index.size();i++){
            cout << i+1 << " : " << data[i].name << " " << data[i].soname <<  " " << data[i].day << "." << data[i].month << "." << data[i].year << " " << data[i].badassSign << endl;
        }
        
        int personIndex = coutCinInt("Выберите нужного пользователя: ");
        
        if (personIndex > 0 && personIndex < index.size()+1){
            personIndex--;
            
            data.erase(data.begin() + personIndex);
            
        }else{
            cout << endl <<  "Таких пользователей не найдено " << endl;
        }
    }else {
        cout << endl <<  "Таких пользователей не найдено " << endl;
    }
}

//сортировка массива по фамилии
void sortPeople(vector<ZNAK> &data){
    
}
//сортировка по гороскопу
void sortBadassSign(vector<ZNAK> &data){
    
}
//сортировка по дате рождения
void sortDate(vector<ZNAK> &data){
    
}

//сохранение данных
void saveData(vector<ZNAK> &data){
    ofstream file("/Users/kirillkornusenkov/Desktop/guapMaimProject/guapMaimProject/file.txt");
    
    if (file.is_open()){
        for (int i=0;i<data.size();i++){
            file << data[i].name << " " << data[i].soname << " " << data[i].day << " "  << data[i].month << " " << data[i].year << endl;
        }
    }
    else {
        cout << "Файл не создан";
    }
}


//обработка строки и добавление в вектор структуру
void workWithFileLine(vector<ZNAK> &data,string line){
    
    ZNAK timeStruct;
    string timeString;
    int count = 0;
    for (int i=0;i<line.length();i++){
        if (line[i] != ' '){
            timeString += line[i];
        }
        else{
            switch (count) {
                case 0:
                    count++;
                    timeStruct.name = timeString;
                    timeString = "";
                    break;
                case 1:
                    count++;
                    timeStruct.soname = timeString;
                    timeString = "";
                    break;
                case 2:
                    count++;
                    timeStruct.day = atoi(timeString.c_str());;
                    timeString = "";
                    break;
                case 3:
                    count++;
                    timeStruct.month = atoi(timeString.c_str());
                    timeString = "";
                    break;
                default:
                    break;
            }
        }
    }
    if (count == 4) {
        timeStruct.year = atoi(timeString.c_str());
        timeStruct.badassSign = badass(timeStruct.day, timeStruct.month);
    }
    data.push_back(timeStruct);
}
//считывание данных
void readData(vector<ZNAK> &data){
    
    ifstream file("/Users/kirillkornusenkov/Desktop/guapMaimProject/guapMaimProject/file.txt");
    
    if (!file){
        //файл не открыл ну и ок
    }else{
        string line;
        while (getline(file,line)) {
            workWithFileLine(data,line);
        }
        
        file.close();
    }
    
    
}

int main() {
    
    setlocale(LC_ALL, "ru");
    
    vector<ZNAK> mainData;
    readData(mainData);
    
    bool check = true;
    
    while (check) {
        menu();
        
        int digite = coutCinInt("Введите число соответстующее нужной надписи ( русский моя сильная сторона ):  ");
     
        switch (digite) {
            case 1:
                mainData.push_back(add());
                break;
            case 2:
                findPeople(mainData);
                break;
            case 3:
                dataChange(mainData);
                break;
            case 4:
                sortPeople(mainData);
                break;
            case 5:
                sortBadassSign(mainData);
                break;
            case 6:
                sortDate(mainData);
                break;
            case 7:
                removePeople(mainData);
                break;
            default:
                saveData(mainData);
                check = false;
        }
    }
    return 0;
}
