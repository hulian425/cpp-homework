#include<conio.h>
int main
{
  char c;
  c = getche() // 不进入缓冲区，直接发送数据
  
  while(1){
      if(kbhit()){ // 当用户按下一次按键时，kbhit()返回是1
          printf("The user presses a key.\n");
          getch();
        }
    }
}
