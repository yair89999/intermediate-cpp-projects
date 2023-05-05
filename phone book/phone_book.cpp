#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printInfoFromFile(){
    ifstream phoneBookInfo("info.txt");
    string text;
    int indent = 10+2; // the 2 that after the |
    cout << "Name     |  Phone Number" << endl;
    while (getline (phoneBookInfo, text)) {
        for (int i =0; i < text.length(); i ++){
            if (text[i] != ':'){
                    cout << text[i];
            } else if (text[i] == ':'){
                if (i < indent){
                    for (int j = i; j < indent; j ++){
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}
bool checkIfNumber(char c){
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
    for (char num:numbers){
        if (c == num){
            return true;
        }
    }
    return false;
}
bool checkValidPhoneNumber(string number){
    /*
    what is a valid number?
    length: 10
    only with numbers or '-'
    first number is 0
    */
   if (number[0] != '0'){
    cout << "0" << endl;
    return false;
   }
    string numberWithoutSymbols = ""; // without the -
    for (int i =0; i < number.length(); i ++){
        if (checkIfNumber(number[i]) == false && number[i] != '-'){ // if the phone number has an illegal symbol(anything but '-')
            return false;
        }
        if (number[i] != '-'){
            numberWithoutSymbols += number[i];
        }
    }
    if (numberWithoutSymbols.length() != 10){
        return false;
    }

    return true; // if didnt get a false this far its a valid number
}
bool checkValidName(string name){ // no symbols
    char c;
    for (int i =0; i < name.length(); i ++){
        c = name[i];
        if (!(c >= 65 && c <= 90 || c >= 97 && c <= 122)){ // if its not a letter
            return false;
        }
    }
    return true;
}
void addANumber(string name, string number){
    if (checkValidPhoneNumber(number) == false){
        cout << "The phone number you game is not valid" << endl;
        cout << "Try checking the length of the number and the characters in it(only numbers or '-')" << endl;
    } else if (checkValidName(name) == false){
        cout << "The name You game is not valid" << endl;
        cout << "Check for symbols and if there are remove them" << endl;
    } else { // everything is good
        vector<string> names;
        vector<string> numbers;

        ifstream phoneBookInfo("info.txt");
        bool added = false;
        string text;
        string fileName,fileNumber;
        while (getline (phoneBookInfo, text)) {
            fileName = "";
            fileNumber = "";
            // set the name and number values
            int addTo = 1;
            char cValue;
            for (int i =0; i < text.length(); i ++){
                cValue = text[i];
                if (cValue == ':'){
                    addTo = 2;
                } else {
                    if (addTo == 1){
                        fileName += cValue;
                    } else {
                        fileNumber += cValue;
                    }
                }
            }
            // check if need to add the name we have
            names.push_back(fileName);
            numbers.push_back(fileNumber);
            if (added == false && name[0] == fileName[0]){
                names.push_back(name);
                numbers.push_back(number);
                added = true;
            }
        }
        if (added == false){
            names.push_back(name);
            numbers.push_back(number);
            added = true;
        }
        // write to the file
        ofstream phoneBookInfoWriteTo("info.txt");
        string nameValue,numberValue;
        for (int i =0; i < names.size(); i ++){
            nameValue = names.at(i);
            numberValue = numbers.at(i);
            phoneBookInfoWriteTo << nameValue + ":" + numberValue + "\n";
        }
        phoneBookInfoWriteTo.close();
        cout << "The name and number you wanted to add, added to the book" << endl;
    }
}

bool checkStringInAnother(string s1, string s2){ // check if s1 is in s2
    for (int i =0; i < s1.length(); i ++){
        if (s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}
void printByName(string namePart){
    ifstream file("info.txt");
    string text;
    string fileName,fileNumber;
    int indent = 10+2;
    cout << "Name      | number" << endl;
    while (getline(file,text)){
        fileName = "";
        fileNumber = "";
        // set the name and number values
        int addTo = 1;
        char cValue;
        for (int i =0; i < text.length(); i ++){
            cValue = text[i];
            if (cValue == ':'){
                addTo = 2;
            } else {
                if (addTo == 1){
                    fileName += cValue;
                } else {
                    fileNumber += cValue;
                }
            }
        }
        // check the text by the name
        if (checkStringInAnother(namePart,fileName)){
            // print its name,number
            for (int i =0; i < text.length(); i ++){
                if (text[i] != ':'){
                        cout << text[i];
                } else if (text[i] == ':'){
                    if (i < indent){
                        for (int j = i; j < indent; j ++){
                            cout << " ";
                        }
                    }
                }
            }
            cout << endl;
        }
    }  
}
void printByNumber(string numberPart){
    ifstream file("info.txt");
    string text;
    string fileName,fileNumber;
    int indent = 10+2;
    cout << "Name      | number" << endl;
    while (getline(file,text)){
        fileName = "";
        fileNumber = "";
        // set the name and number values
        int addTo = 1;
        char cValue;
        for (int i =0; i < text.length(); i ++){
            cValue = text[i];
            if (cValue == ':'){
                addTo = 2;
            } else {
                if (addTo == 1){
                    fileName += cValue;
                } else {
                    fileNumber += cValue;
                }
            }
        }
        // check the text by the name
        if (checkStringInAnother(numberPart,fileNumber)){
            // print its name,number
            for (int i =0; i < text.length(); i ++){
                if (text[i] != ':'){
                        cout << text[i];
                } else if (text[i] == ':'){
                    if (i < indent){
                        for (int j = i; j < indent; j ++){
                            cout << " ";
                        }
                    }
                }
            }
            cout << endl;
        }
    }  
}

int main(){
    /*
    Actions:
    1. Print the whole book
    2. Add a name+phone number(check if its a valid phone number)(need to add it by first letter in first name, example: Ido,Yonatan,Yair)
    3. Get a phone number by name
    4. Get a name by a full/part of a phone number
    */
    /*
    This phone book is not ordered by alphabetic order
    You can see all of the names that start with the same letter but not in the alphabetic order
    */
    cout << "Phone book Actions: " << endl;
    cout << "1. Print the book" << endl;
    cout << "2. Add a name and a phone number" << endl;
    cout << "3. Get a phone number by name" << endl;
    cout << "4. Get a name by full a phone number or a part of it" << endl;
    cout << "Chosen action: " << endl;
    int action;
    cin >> action;
    if (action == 1){
        cout << "Phone book:" << endl;
        printInfoFromFile();
    } else if (action == 2){
        string name,number;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the number(format=000-000-0000): ";
        cin >> number;
        addANumber(name,number);
    } else if (action == 3){
        // using one vector for the names and one for the numbers
        string namePart;
        cout << "Enter the name/name part you want to search by: ";
        cin >> namePart;
        printByName(namePart);
    } else if (action == 4){
        // using one vector for the numbers and one for the names
        string numberPart;
        cout << "Enter the number/number part you want to search by: ";
        cin >> numberPart;
        printByNumber(numberPart);
    }

    char answer;
    cout << "Would you like to use the phone book actions again(y/n)? ";
    cin >> answer;
    if (answer == 'y'){
        main();
    }
}
