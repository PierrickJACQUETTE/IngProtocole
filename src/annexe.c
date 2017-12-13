#include "annexe.h"

void print(char* chaine, int value){
	if(verbose==1){
		printf(" %s (%d) ", chaine, value);
	}else{
		printf(" %d", value);
	}
}

void printHeader(){
	printf("n°   | Qui     | Information\n");
	printf("--------------------------------------------------------------------------------\n");
}

void read8(unsigned char** message, int* i){
	int8_t t = 0;
	t = (*message)[*i];
	*i = *i +1;
	printf("%d ", (int)(t));
}

void read16(unsigned char** message, int* i){
	int16_t t = 0;
	int j;
	for(j=1; j>=0; j--){
		if(j==0){
			t = (*message)[*i];
		}else{
			t = (*message)[*i]<< 4;
		}
		*i = *i +1;
	}
	printf("%d ", (int)(t));
}

void read32(unsigned char** message, int* i){
	int32_t t = 0;
	int j;
	for(j=3; j>=0; j--){
		if(j==0){
			t = (*message)[*i];
		}else{
			t = (*message)[*i]<< 4;
		}
		*i = *i +1;
	}
	printf("%d ", (int)(t));
}

void read255(unsigned char** message, int* i, int print){
	while((*message)[*i] != 255){
		if(print == 3){
			read8(message, i);
		}else if(print == 0){
			printf("%c", (*message)[*i]);
			*i = *i +1;
		}else if(print == 1){
			printf("%d ", (*message)[*i]);
			*i = *i +1;
		}
	}
}

int checkZeroOne(unsigned char** message, int* i, char* zero, char* one){
	if((*message)[*i] == 1){
		print(one, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 0){
		print(zero, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkZeroUntilTwo(unsigned char** message, int* i, char* zero, char* one, char* two){
	if(checkZeroOne(message, i, zero, one) == 1){
		return 1;
	}
	if((*message)[*i] == 2){
		print(two, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkZeroUntilThree(unsigned char** message, int* i, char* zero, char* one, char* two, char* three){
	if(checkZeroUntilTwo(message, i, zero, one, two)){
		return 1;
	}
	if((*message)[*i] == 3){
		print(three, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkZeroUntilFour(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four){
	if(checkZeroUntilThree(message, i, zero, one, two, three) == 1){
		return 1;
	}
	if((*message)[*i] == 4){
		print(four, (*message)[*i]);
		*i = *i +1;
	}
	return 0;
}


int checkZeroUntilEight(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight){
	if(checkZeroUntilFour(message, i, zero, one, two, three, four) == 1){
		return 1;
	}
	if((*message)[*i] == 5){
		print(five, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 6){
		print(six, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 7){
		print(seven, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 8){
		print(eight, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkEightUntilNine(unsigned char** message, int* i, char* eight, char* nine){
	if((*message)[*i] == 8){
		print(eight, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 9){
		print(nine, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkEightUntilEleven(unsigned char** message, int* i, char* eight, char* nine, char* ten, char* eleven){
	if(checkEightUntilNine(message, i, eight, nine) == 1){
		return 1;
	}
	if((*message)[*i] == 10){
		print(ten, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 11){
		print(eleven, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int check0Until4And8Until11(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* eight, char* nine, char* ten, char* eleven){
	if(checkZeroUntilFour(message, i, zero, one, two, three, four) == 1){
		return 1;
	}
	if(checkEightUntilEleven(message, i, eight, nine, ten, eleven) == 1){
		return 1;
	}
	return 0;
}

int checkOneUntilThree(unsigned char** message, int* i, char* one, char* two, char* three){
	if((*message)[*i] == 1){
		print(one, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 2){
		print(two, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 3){
		print(three, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkOneUntilFour(unsigned char** message, int* i, char* one, char* two, char* three, char* four){
	if(checkOneUntilThree(message, i, one, two, three) == 1){
		return 1;
	}
	if((*message)[*i] == 4){
		print(four, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkOneUntilSeven(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven){
	if(checkOneUntilFour(message, i, one, two, three, four) == 1){
		return 1;
	}
	if((*message)[*i] == 5){
		print(five, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 6){
		print(six, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 7){
		print(seven, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkTwelveUntilTwenty(unsigned char** message, int* i, char* twelve, char* thirteen, char* fourteen, char* fifteen, char* sixteen, char* seventeen, char* eighteen, char* nineteen, char* twenty){
	if((*message)[*i] == 12){
		print(twelve, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 13){
		print(thirteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 14){
		print(fourteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 15){
		print(fifteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 16){
		print(sixteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 17){
		print(seventeen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 18){
		print(eighteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 19){
		print(nineteen, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 20){
		print(twenty, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkTwentyOneUtilThirty(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight, char* nine, char* thirty){
	if((*message)[*i] == 21){
		print(one, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 22){
		print(two, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 23){
		print(three, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 24){
		print(four, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 25){
		print(five, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 26){
		print(six, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 27){
		print(seven, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 28){
		print(eight, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 29){
		print(nine, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 30){
		print(thirty, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}

int checkThirtyOneUtilFortyOne(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight, char* nine, char* forty, char* fortyOne){
	if((*message)[*i] == 31){
		print(one, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 32){
		print(two, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 33){
		print(three, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 34){
		print(four, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 35){
		print(five, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 36){
		print(six, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 37){
		print(seven, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 38){
		print(eight, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 39){
		print(nine, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 40){
		print(forty, (*message)[*i]);
		*i = *i +1;
		return 1;
	}else if((*message)[*i] == 41){
		print(fortyOne, (*message)[*i]);
		*i = *i +1;
		return 1;
	}
	return 0;
}
