//2021-02학기 객체지향언어과제2 성적파일입출력 
//2021531034 이서현
#include <iostream>
#include <cstring>
#include<fstream>
#include<string.h>

using namespace std;

class Person{
	protected:
		char*name;
	public:
		Person(char* na):name(na){};
		void set(char* na) {
			name = na;
		}
		char* GetName(){
			char nameAr[10]={0};
			strcpy(nameAr, name);
			return nameAr;
		}
		virtual void showData() = 0;
};


class Student : public Person {
	protected:
		int kor=0;
		int eng=0;
		int math=0;
		int sum=0;
		int avg=0;
	public:
		Student() : Person(NULL) {};
		void score(int k, int e, int m) {
			kor=k;
			eng=e;
			math=m;
		}
		int GetKor() {
			return kor;
		}
		int GetEng() {
			return eng;
		}
		int GetMath() {
			return math;
		}
		int Results() {
			sum = GetKor()+GetEng()+GetMath();
			return sum;
		}
		int Average() {
			avg = Results()/3;
			return avg;
		}
		void showData() {
		    ofstream writeFile("work2.txt");
			writeFile << "===================================================" << endl;
			writeFile << "   성명  |  국어  |  영어  |  수학  |  총점  |  평균 " << endl;
			writeFile << "------------------------------------------------" << endl;
			writeFile << GetName() << " | " << GetKor() << " | "  << GetEng() << " | "  << GetMath() << " | "  << Results() << " | "  << Average() << endl;
			writeFile << "-------------------------------------------------" << endl;
    		writeFile.close();
			return;
		}
};


int main(void) {
	char name;
	int kor=0, eng=0, math=0, sum=0, avg=0;
	Student s[3];
	
	for (int i=0; i<3; i++) {
		cout << "이름을 입력하세요 : ";
		cin >> name;
		cout << "국어 점수 : ";
		cin >> kor;
		cout << "영어 점수 : ";
        cin >> eng;
		cout << "수학 점수 : ";
		cin >> math;

		s[i].set(&name);
		s[i].score(kor, eng, math);
	}

	for (int i=0; i<3; i++) {
		s[i].showData();
	} 
}
