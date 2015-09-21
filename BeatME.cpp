/*
Rajendra Baviskar
Why computer wins all the time.
(Who ever left with last matchstick to pick loses the game) 
*/
#include<iostream>
using namespace std;
int win(int n)
{
	int i;
	if(n==6)	return 0;
	if(n<=5)	return n-1;
	for(i=1;i<=4;i++)
		if(win(n-i-1)&&win(n-i-2)&&win(n-i-3)&&win(n-i-4))
			return i;
}
int main()
{
	int iRemainingSticks=21,iUserPicked,iComputerPicked;
	cout<<"MATCHSTICK GAME.\n"
		"Who ever left with last matchstick to pick loses the game.\n"
		"On each turn enter a value between 1 and 4.\n";
	while(1)
	{
		cout<<"Number of matchsticks remaining="<<iRemainingSticks<<"\nEnter value:";
		cin>>iUserPicked;
		if(iUserPicked<1||iUserPicked>4)
		{
			cout<<"Value entered is not valid ( Valid range: 1 =< Value >=4 )\n";
			continue;
		}
		iRemainingSticks-=iUserPicked;
		iRemainingSticks-=(iComputerPicked=win(iRemainingSticks));
		cout<<"Computer takes "<<iComputerPicked<<" matchsticks\n";
		if(iRemainingSticks==1)
		{
			cout<<"You are left with " << iRemainingSticks <<" matchstick to pick Computer wins\n";
			break;
		}
	}
	return 0;
}
