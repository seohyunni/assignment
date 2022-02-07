#include <iostream>
using namespace std;
class Ctv //추상 클래스
{
 int ch_number;
 int volume;
 
public:
    Ctv(int ch, int vol) : ch_number(ch), volume(vol) {}
    virtual void TurnOn() = 0; // TV 전원 On/Off
    virtual void Volume(int) = 0; // Volume 조절
    virtual void ChangeCh(int) = 0; // Channel 변경
};


int main(void)
{   
    Ctv::TurnOn();
    Ctv::ChangeCh();
    if()
    return 0;
}