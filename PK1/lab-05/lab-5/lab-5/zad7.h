<<<<<<< HEAD
#pragma once

int zad7(int No,char m) {
	if (m=='r')
	{

	}
	else
	{

	}

	return 0;
}
int FibRek(int no,int nm1=0,int nm2=1,int i=3) {
	if (no>2)
	{
		if (i==no)
		{
			return nm1 + nm2;
		}
		else
		{
			return FibRek(no, nm2, nm1 + nm2, i + 1);
		}
	}
	else if (no==1)
	{
		return nm1;
	}
	else if (no == 2) {
		return nm2;
	}
}
int Fib(int No) {
	int nm1 = 0;
	int nm2 = 1;
	int i = 3;
	int result = 0;
	if (No > 2)
	{
		while (i <= No)
		{
			result = nm1 + nm2;
			nm1 = nm2;
			nm2 = result;
			i++;
		}
		return result;
	}
	else if (No == 1)
	{
		return nm1;
	}
	else if (No == 2)
	{
		return nm2;
	}
=======
#pragma once

int zad7(int No,char m) {
	if (m=='r')
	{

	}
	else
	{

	}

	return 0;
}
int FibRek(int no,int nm1=0,int nm2=1,int i=3) {
	if (no>2)
	{
		if (i==no)
		{
			return nm1 + nm2;
		}
		else
		{
			return FibRek(no, nm2, nm1 + nm2, i + 1);
		}
	}
	else if (no==1)
	{
		return nm1;
	}
	else if (no == 2) {
		return nm2;
	}
}
int Fib(int No) {
	int nm1 = 0;
	int nm2 = 1;
	int i = 3;
	int result = 0;
	if (No > 2)
	{
		while (i <= No)
		{
			result = nm1 + nm2;
			nm1 = nm2;
			nm2 = result;
			i++;
		}
		return result;
	}
	else if (No == 1)
	{
		return nm1;
	}
	else if (No == 2)
	{
		return nm2;
	}
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}