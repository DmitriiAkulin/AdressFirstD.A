// AdressFirstD.A

#include <Windows.h>
#include <iostream>
#include <fstream>

using std::cin;

using std::endl;
using std::string;

class Adress {
private:
    string city_name_ ;
    string street_name_ ;
    int num_house_;
    int num_flat_ ;
    //конструктор без параметров для массива
    Adress() :city_name_(), street_name_(), num_house_(), num_flat_() {}
    
public:
   
     //конструктор с параметрами
      Adress(string city_name_, string street_name_, int num_house_, int num_flat_) :
        city_name_(city_name_), street_name_(street_name_), num_house_(num_house_), num_flat_(num_flat_)
       {}
        
     //вывод в файл  
      void Get_Output_Address(Adress *arr, int first) {
            std::ofstream  out("out.txt");            
            out << first << endl;
            for (int i = 0; i < first; i++) {
               
               out << arr[i].city_name_ << ", " << arr[i].street_name_ << ", " << arr[i].num_house_ << ", "
               << arr[i].num_flat_ << endl;
            }

            out.close();
      }

      
     //доступ и запись в массив.
      void AcsessSetData() { 
                 
                 std::ifstream in("in.txt");
                 if (!in.is_open()) std::exit(0);
                 int first; in >> first;
                 
                 Adress* adress_arr = new Adress[first];//создаем массив
                 
                 for (int i = 0; i < first; i++) {  //читаем из файла в массив
                          in >> adress_arr[i].city_name_;
                          in >> adress_arr[i].street_name_;
                          in >> adress_arr[i].num_house_;
                          in >> adress_arr[i].num_flat_;
                 }

                 Get_Output_Address(adress_arr, first);

                 delete [] adress_arr;
                 in.close();
               
               
          
       }
};
int main()
{     
     
    std::ifstream in("in.txt");
    if (!in.is_open()) std::exit(0);
    int f; in >> f;

    string nc, ns; int nh, nf;
    in >> nc >> ns >> nh >> nf;
    Adress adress(nc, ns, nh, nf);
    in.close();

    adress.AcsessSetData();

    return 0;
}
