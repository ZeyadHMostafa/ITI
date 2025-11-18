#include "fake_str.h"
#include <iostream>
int main(){
    char str1[20] = "nice JOB!";
    char str2[] = "nice...";
    
    std::cout << (int)str_cmp(str2,str1) << std::endl;
    std::cout << str_len(str1) << std::endl;
    std::cout << str_len(str2) << std::endl;

    std::cout << "\n----\n";

    str_tolower(str1);
    str_tocapital(str2);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    std::cout << "\n----\n";

    str_cpy(str2,str1);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    std::cout << "\n----\n";

    str_concat(str1,str2,str1);

    std::cout << str1 << std::endl;
    return 0;
}