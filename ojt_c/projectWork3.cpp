//2021-02학기 객체지향언어과제2 cStudent 
//2021531034 이서현

#include <iostream>
#include <cstring>
using namespace std;

class CPerson {
	private:
		char m_name[16] = {0};
		int m_age = 0;
		int m_gender = 0;
		int m_id = 0;
		char m_majored[40] = {0};
	public:
		void Set(char* name, int age, int gender, int id, char* majored) {
			strcat(m_name, name);
			m_age = age;
			m_gender = gender;
			m_id = id;
			strcat(m_majored, majored);
		}
		char* GetName() {
			return m_name;
		}
		int GetAge() {
			return m_age;
		}
		int GetGender() {
			return m_gender;
		}	
		int GetId() {
			return m_id;
		}	 
		char* GetMajored() {
			return m_majored;
		}
}; 

class CStudent : public CPerson {
	public:
		void Print() {
			cout << GetName() << "  " << GetAge() << "     " << GetGender() << "      " << GetId() << "  " << GetMajored() << endl;
		}
};

int main() {
	cout << "   이름     나이     성별     ID      전공" << endl;
	cout << "-------------------------------------------" << endl;
	
	CStudent ss;
	ss.Set("김아름", 22, 2, 1000, "정보통신기술공학과");
	ss.Print();
	
	CStudent ss1;
	ss1.Set("김홍도", 25, 1, 1001, "컴퓨터공학과");
	ss1.Print(); 
	
	return 0;
}
