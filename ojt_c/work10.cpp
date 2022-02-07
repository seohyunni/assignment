#include<iostream>
#include<string.h>
#include<algorithm>
#include<fstream>

using namespace std;

struct Student{
    char name[5];
    int firstScore;
    int secondScore;
    int thirdScore;
};

int main(){
   struct Student student[5];
   struct Student student_temp;
   int temp = 0;
   int total[5] = {0};
  
   
   for(int i=0; i<5; i++){
       cout <<  "\nnumber " << i+1 << " student name : ";
       cin >> student[i].name;
       
       cout << "\n" << student[i].name << "'s first score : ";
       cin >> student[i].firstScore;
       total[i]+=student[i].firstScore;
       
       cout << "\n" << student[i].name << "'s second score : ";
       cin >> student[i].secondScore;
       total[i]+=student[i].secondScore;
       
       cout << "\n" << student[i].name << "'s third score : ";
       cin >> student[i].thirdScore;
       total[i]+=student[i].thirdScore;
       
       cout << "\n" << student[i].name << "'s total score : " << total[i] << "\n";
   }
   
   ofstream writeFile("test.txt"); //create file
   
   
   cout << "\n----------------------------------------------\n";
   
   for(int i = 0 ; i < 4 ; i ++) {
    for(int j = 0 ; j < (4-i) ; j ++) {
        if(total[j] < total[j+1]) {
            temp = total[j];
            student_temp = student[j];
            total[j] = total[j+1];
            student[j] = student[j+1];
            total[j+1] = temp;
            student[j+1] = student_temp;
           }
        }
    }
   
   for(int i=0; i<5; i++){
       writeFile << "rank " << 5-i << " student : " << student[i].name << ", total score : " << total[i] << "\n";
       cout << "rank " << 5-i << " student : " << student[i].name << ", total score : " << total[i] << "\n";
   }
   writeFile.close();
}
        