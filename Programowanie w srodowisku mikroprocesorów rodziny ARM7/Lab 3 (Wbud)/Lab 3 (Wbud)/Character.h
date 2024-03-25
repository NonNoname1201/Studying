#ifndef INCFILE1_H_
#define INCFILE1_H_


char* character() {
	char* data = (char*)malloc(8 * sizeof(char));
	data[0] = 0b00010;
	data[1] = 0b00101;
	data[2] = 0b00100;
	data[3] = 0b00100;
	data[4] = 0b00100;
	data[5] = 0b00100;
	data[6] = 0b10100;
	data[7] = 0b01000;
	return data;
}



#endif /* INCFILE1_H_ */