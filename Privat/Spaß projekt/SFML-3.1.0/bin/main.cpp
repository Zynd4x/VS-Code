#include <iostream>
#include <string>
using namespace std;


int main() {
    string name = "HP";
    int hp = 100;

    cout << name << " " << hp << endl;
    

    return 0;
}

g++ "C:\Users\IT-User\Desktop\VS Code\Spaß projekt\SFML-3.1.0\bin\main.cpp" -I"C:\Users\IT-User\Desktop\VS Code\Spaß projekt\SFML-3.1.0\include" -L"C:\Users\IT-User\Desktop\VS Code\Spaß projekt\SFML-3.1.0\lib" -lsfml-graphics -lsfml-window -lsfml-system -o app.exe
