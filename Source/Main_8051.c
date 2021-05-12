#include <REGX52.H>

void main(){

	
	unsigned char temp = 0, result;
	volatile unsigned char inA, inB, inC;
	while(1){

		inA = P1_2;
		inB = P1_3;
		inC = P1_4;
	

                temp  = ((!inA)&(!inB)&(!inC)) << 0;

                temp |= ((!inA)&(!inB)&(inC)) << 1;
         
                temp |= ((!inA)&(inB)&(!inC)) << 2; 
         
                temp |= ((!inA)&(inB)&(inC)) << 3;           
         
                temp |= ((inA)&(!inB)&(!inC)) << 4;          
         
                temp |= ((inA)&(!inB)&(inC)) << 5;        
         
                temp |= ((inA)&(inB)&(!inC)) << 6;  
         
                temp |= ((inA)&(inB)&(inC)) << 7;   	

                result = temp & P0;

                P2 = (result >> 7)|(result >> 6)|(result >> 5)|(result >> 4)|(result >> 3)|(result >> 2)|(result >> 1)|(result >> 0);


 	}
}