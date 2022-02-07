#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int fsize;
    char *buf;
    ifstream ifile(".\\Ex11_12.cpp", ios::in|ios::binary|ios::ate);
    if (!ifile.is_open()) // 파일 열기 성공여부 확인
    {
        cout << "파일을 열 수 없습니다." << endl ;
    }
    else {
        ifile.seekg(0, ios::end); // 파일 끝으로 파일 포인터 이동
        fsize = ifile.tellg(); // 파일의 현재(마지막) 위치 읽기
        buf=new char[fsize+1]; //동적메모리공간할당
    }
    ifile.seekg (0, ios::beg);
    ifile.read (buf, fsize);
    buf[fsize] = "\0";
    ifile.close();
    cout << "다음은 읽은 파일의 내용입니다." << endl ;
    cout << buf << endl; // 파일에서 읽은 데이터 화면 출력
    delete[] buf; // 동적 메모리 공간 해제
    return 0;
}