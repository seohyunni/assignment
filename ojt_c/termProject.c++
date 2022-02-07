//헬스장 회원 관리 시스템
//회원의 나이, 키, 몸무게를 입력받아 BMI를 측정하고, 순위를 매겨 txt 파일로 출력한다.

#include<iostream>
#include<string.h>
#include<algorithm>
#include<fstream>
#include<thread>
#include<chrono>

using namespace std;
using std::this_thread::sleep_for;

struct Member{ //멤버 구조체 생성 - 키, 몸무게, 이름
    double height;
    double weight;
    char name[10];
};

int main(){

    int memberLength;

    cout << "안녕하세요, ㅇㅇ헬스장입니다." << endl;
    sleep_for(std::chrono::milliseconds(1000)); //1초가량 delay
    cout << "관리할 회원 수를 입력해 주세요. (숫자만 입력) >> ";

    while(!(cin >> memberLength)){  //회원 수 입력란에 정확한 값 입력할 때까지 
        cout << "숫자만 입력해 주세요!";  // 회원 수 입력란에 잘못된 값을 입력했을 경우 
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n'); //입력 지우기, 없을 경우 루프 끝나지 않음
    }
    
    struct Member member[memberLength]; //구조체 member의 크기 == 입력한 값
    struct Member member_temp;
    int temp = 0;
    double bmi[memberLength];

    for(int i=0; i<memberLength; i++){

        cout << i+1 << "번째 회원의 이름을 입력해 주세요. >> ";
        cin >> member[i].name;

        sleep_for(std::chrono::milliseconds(1000));

        cout << member[i].name << " 회원님의 키를 입력해 주세요. (소수점 아래 1자리까지) >> ";
        cin >> member[i].height;

        sleep_for(std::chrono::milliseconds(1000));

        cout << member[i].name << " 회원님의 몸무게를 입력해 주세요. (소수점 아래 1자리까지) >> ";
        cin >> member[i].weight;

        sleep_for(std::chrono::milliseconds(1000));


        bmi[i] = member[i].weight/(member[i].height/100*member[i].height/100);  //bmi 계산 -> 체중을 키의 제곱으로 나눈 값

        cout.precision(3);
        cout << member[i].name << " 회원님의 BMI는 " << bmi[i] << "% 입니다.\n";

        sleep_for(std::chrono::milliseconds(1000));
    }

    ofstream writeFile("finessMember.txt");

    cout << "----------회원님들의 BMI를 모두 저장할게요!-------------\n";

    for(int i=0; i<memberLength; i++){
        for(int j=0; j<(memberLength-i); j++){
            if(bmi[j] > bmi[j+1]){
                temp = bmi[j];
                member_temp = member[j];
                bmi[j] = bmi[j+1];
                member[j] = member[j+1];
                bmi[j+1] = temp;
                member[j+1] = member_temp;
            }
        }
    }
    for(int i=0; i<memberLength; i++){
        cout << "BMI 순위 " << i+1 << "위 : " << member[i].name << " 회원님" << endl;
        writeFile << member[i].name << "회원님이 키 "<< member[i].height << ", 몸무게 "<< member[i].weight<< "로 BMI 수치 "<<bmi[i]<<"를 기록했습니다. \n\n\n";
    }
    writeFile.close();
}       