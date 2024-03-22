#include <iostream>
#include <string>
#include <forward_list>



std::string berechneZeichenkette (int n)
{
    // 
    // return std::string("ABC");

    std::string tmp ("ABC");    // std::forward_list 
    return tmp;
}

void frage_01()
{
    std::string s = berechneZeichenkette(123);
}



void frage()
{
    std::forward_list<int> root;

    std::cout << sizeof(root) << std::endl;   // 16

    root.push_front(123);
    root.push_front(123);
    root.push_front(123);
    root.push_front(123);
    root.push_front(123);
    root.push_front(123);
    root.push_front(123);    
    root.push_front(123);

    std::cout << sizeof(root) << std::endl;   // 

}




void frage_no_go()
{
   // int feld[100000];  //never

    int* feld = new int[100000];  // besser // gut

}

int* frage_no_go_2()
{
    int feld[100000];  //never

    return feld;   // Error
}


//void frage_no_go_Csharp()
//{
//    int[] feld = new int[10000];
//}