#include "function.h"

void func::sorted(std::string& str){
    std::sort(str.begin(), str.end(), [](const char& x, const char& y){
        return (x < y);
    });
    for(int i = 0; i < str.size(); i++){
        if(int(str[i]) % 2 == 0){
            str.replace(i, 1, "KB");
            i++;
        }
    }
}

int func::calculat(const std::string& str){
    int sum = 0;
    for(auto x : str){
        if(std::isdigit(x)){
            sum += (x - '0'); //если нужно брать по ASCII а не само значение то нужно убрать (- '0')
        }
    }
    return sum;
}

bool func::analys(const std::string& check){
    if(check.size() > 2 && std::stoi(check)%32 == 0){
        return true;
    }
    else{
        return false;
    }
}