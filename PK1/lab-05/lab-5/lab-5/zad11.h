<<<<<<< HEAD
#pragma once

int zad11(int No) {
	return Hanoi(No);
}
int Hanoi(int no){
	if(no==1){
		return 1;
	}
	else{
		return 2*Hanoi(no-1)+1;
	}
=======
#pragma once

int zad11(int No) {
	return Hanoi(No);
}
int Hanoi(int no){
	if(no==1){
		return 1;
	}
	else{
		return 2*Hanoi(no-1)+1;
	}
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}