//2021-02학기 객체지향언어과제2 리모컨 
//2021531034 이서현

#include <iostream>
#include <cstring>
using namespace std;

class Ctv {
	protected:
		int ch_number;
		int volume;
	public:
		Ctv(int ch, int vol) : ch_number(ch), volume(vol) {}
		virtual void TurnOn(int status) = 0;
		virtual void Change(int ch) = 0;
		virtual void Volume(int vol) = 0;
};

class Controll : public Ctv {
	public:
		Controll() : Ctv(0, 0) {}
		void TurnOn(int status) {
			int chose, ch, vol;
			
			if (status==1) {
				cout << "TV 전원이 켜졌습니다." << endl;
				
				cout << "채널 선택은 0번, 볼륨 조절은 1번을 선택하세요. >> ";
				cin >> chose;
				
				if (chose  ==  0)  {
					cout  <<  "이동할 채널을 선택해 주세요. >> ";
					cin  >>  ch;
					Change(ch);
				}  else  if  (chose  ==  1)  {
					cout  <<  "조절할 볼륨을 입력해 주세요. >> ";
                    cin  >>  vol;
					Volume(vol);  
				}
				
				cout  <<  "계속하시겠습니까? (0 : 아니오 , 1 : 네) >> ";
				cin  >>  status;
				TurnOn(status);
			}  else  {
				cout  <<  "tv의 전원이 꺼졌습니다."  <<  endl;
				return;  
			}
		}
		void  Change(int  ch)  {
			ch_number = ch;
			cout << "채널 " << ch_number << endl;
		}
		void Volume(int vol) {
			volume = volume + vol;
			cout << "볼륨 " << volume << endl;
		}
};

int main() {
	Ctv* p = new Controll();
	int status, chose, ch, vol;
	
	
	cout << "tv를 켜시겠습니까?(아니오 : 0, 네 : 1) >> ";
	cin >> status;
	p->TurnOn(status);
	
	return 0;
}
