#include <stdio.h>
#include <stdlib.h>

#define	andBit(a, b) ((a) ? ((b) ? 1 : 0) : 0)
#define orBit(a,b) ((a) ? 1 : (b ? 1 : 0))
#define notBit(a) ((a) ? 0 : 1)
#define xorBit(a,b) (andBit(orBit((a),(b)),orBit(notBit((a)),notBit((b)))))
#define shiftLeft(reg1) \
			(reg1).bit1 = (reg1).bit2; \
			(reg1).bit2 = (reg1).bit3; \
			(reg1).bit3 = (reg1).bit4; \
			(reg1).bit4 = (reg1).bit5; \
			(reg1).bit5 = (reg1).bit6; \
			(reg1).bit6 = (reg1).bit7; \
			(reg1).bit7 = (reg1).bit8; \
			(reg1).bit8 = 0;

#define shiftRight(reg1) \
			(reg1).bit8 = (reg1).bit7; \
			(reg1).bit7 = (reg1).bit6; \
			(reg1).bit6 = (reg1).bit5; \
			(reg1).bit5 = (reg1).bit4; \
			(reg1).bit4 = (reg1).bit3; \
			(reg1).bit3 = (reg1).bit2; \
			(reg1).bit2 = (reg1).bit1; \
			(reg1).bit1 = 0;

#define convert(c, reg) \
			if (c == '0'){ \
				assign0(reg); \
			} \
			else if (c == '1'){ \
				assign0(reg); \
				increment(reg); \
			} \
			else if (c == '2'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '3'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '4'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '5'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '6'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '7'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '8'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			else if (c == '9'){ \
				assign0(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
				increment(reg); \
			} \
			
#define increment10(reg) \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg); \
			increment(reg);

#define increment100(reg) \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg); \
			increment10(reg);

#define time10(reg4) \
			if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)) { \
				assign0(reg4); \
			} \
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment10(reg4); \
			} \
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment100(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment100(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment100(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){\
				increment100(reg4); \
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){\
				increment100(reg4); \
				increment100(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
				increment10(reg4); \
			}\
			else{\
				assign255(reg4);\
			} \



#define andBitReg(reg1, reg2, regr) \
			(regr).bit1 = andBit((reg1).bit1,(reg2).bit1); \
			(regr).bit2 = andBit((reg1).bit2,(reg2).bit2); \
			(regr).bit3 = andBit((reg1).bit3,(reg2).bit3); \
			(regr).bit4 = andBit((reg1).bit4,(reg2).bit4); \
			(regr).bit5 = andBit((reg1).bit5,(reg2).bit5); \
			(regr).bit6 = andBit((reg1).bit6,(reg2).bit6); \
			(regr).bit7 = andBit((reg1).bit7,(reg2).bit7); \
			(regr).bit8 = andBit((reg1).bit8,(reg2).bit8); 

#define orBitReg(reg1, reg2, regr) \
			(regr).bit1 = orBit((reg1).bit1,(reg2).bit1); \
			(regr).bit2 = orBit((reg1).bit2,(reg2).bit2); \
			(regr).bit3 = orBit((reg1).bit3,(reg2).bit3); \
			(regr).bit4 = orBit((reg1).bit4,(reg2).bit4); \
			(regr).bit5 = orBit((reg1).bit5,(reg2).bit5); \
			(regr).bit6 = orBit((reg1).bit6,(reg2).bit6); \
			(regr).bit7 = orBit((reg1).bit7,(reg2).bit7); \
			(regr).bit8 = orBit((reg1).bit8,(reg2).bit8); 

#define xorBitReg(reg1, reg2, regr) \
			(regr).bit1 = xorBit((reg1).bit1,(reg2).bit1); \
			(regr).bit2 = xorBit((reg1).bit2,(reg2).bit2); \
			(regr).bit3 = xorBit((reg1).bit3,(reg2).bit3); \
			(regr).bit4 = xorBit((reg1).bit4,(reg2).bit4); \
			(regr).bit5 = xorBit((reg1).bit5,(reg2).bit5); \
			(regr).bit6 = xorBit((reg1).bit6,(reg2).bit6); \
			(regr).bit7 = xorBit((reg1).bit7,(reg2).bit7); \
			(regr).bit8 = xorBit((reg1).bit8,(reg2).bit8); 

#define notBitReg(reg1) \
		reg1.bit1 = (reg1.bit1) ? 0 : 1; \
		reg1.bit2 = (reg1.bit2) ? 0 : 1; \
		reg1.bit3 = (reg1.bit3) ? 0 : 1; \
		reg1.bit4 = (reg1.bit4) ? 0 : 1; \
		reg1.bit5 = (reg1.bit5) ? 0 : 1; \
		reg1.bit6 = (reg1.bit6) ? 0 : 1; \
		reg1.bit7 = (reg1.bit7) ? 0 : 1; \
		reg1.bit8 = (reg1.bit8) ? 0 : 1; 

#define isZero(reg) (((reg).bit1 == 0) && ((reg).bit2 == 0) && ((reg).bit3 == 0) && ((reg).bit4 == 0) && ((reg).bit5 == 0) && ((reg).bit6 == 0) && ((reg).bit7 == 0) && ((reg).bit8 == 0))

#define isEqual(reg1,reg2) (((reg1).bit1 == (reg2).bit1) && ((reg1).bit2 == (reg2).bit2) && ((reg1).bit3 == (reg2).bit3) && ((reg1).bit4 == (reg2).bit4) && ((reg1).bit5 == (reg2).bit5) && ((reg1).bit6 == (reg2).bit6) && ((reg1).bit7 == (reg2).bit7) && ((reg1).bit8 == (reg2).bit8))

#define assign(reg2, reg1) \
			(reg1).bit1 = (reg2).bit1; \
			(reg1).bit2 = (reg2).bit2; \
			(reg1).bit3 = (reg2).bit3; \
			(reg1).bit4 = (reg2).bit4; \
			(reg1).bit5 = (reg2).bit5; \
			(reg1).bit6 = (reg2).bit6; \
			(reg1).bit7 = (reg2).bit7; \
			(reg1).bit8 = (reg2).bit8;

#define assign255(reg1) \
			(reg1).bit1 = 1; \
			(reg1).bit2 = 1; \
			(reg1).bit3 = 1; \
			(reg1).bit4 = 1; \
			(reg1).bit5 = 1; \
			(reg1).bit6 = 1; \
			(reg1).bit7 = 1; \
			(reg1).bit8 = 1;

#define assign0(reg1) \
			(reg1).bit1 = 0; \
			(reg1).bit2 = 0; \
			(reg1).bit3 = 0; \
			(reg1).bit4 = 0; \
			(reg1).bit5 = 0; \
			(reg1).bit6 = 0; \
			(reg1).bit7 = 0; \
			(reg1).bit8 = 0; \

#define increment(reg) \
			if ((reg).bit8) {\
				(reg).bit8 = 0; \
				if ((reg).bit7) { \
					(reg).bit7 = 0; \
					if ((reg).bit6) { \
						(reg).bit6 = 0; \
						if ((reg).bit5) { \
							(reg).bit5 = 0; \
							if ((reg).bit4) { \
								(reg).bit4 = 0; \
								if ((reg).bit3) { \
									(reg).bit3 = 0; \
									if ((reg).bit2) { \
										(reg).bit2 = 0; \
										if ((reg).bit1) { \
											assign255(reg); \
										} \
										else { \
											(reg).bit8 = 1; \
										} \
									} \
									else { \
										(reg).bit8 = 1; \
									} \
								} \
								else { \
									(reg).bit3 = 1; \
								} \
							} \
							else { \
								(reg).bit4 = 1; \
							} \
						} \
						else { \
							(reg).bit5 = 1; \
						} \
					} \
					else { \
						(reg).bit6 = 1; \
					} \
				} \
				else { \
					(reg).bit7 = 1; \
				} \
			} \
			else { \
				(reg).bit8 = 1; \
			} 

#define add(reg1, reg2, reg3, regr) \	
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 1) && (reg2.bit1 == 1)){\
				assign255(reg1); \
				assign0(reg2); \
			} \
			andBitReg((reg1), (reg2), (reg3)); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			assign(reg1, regr);

#define substract(reg1, reg2, reg3, regr) \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			if ((reg1.bit1 == 0) && (reg2.bit1 == 1)){\
				assign0(reg1); \
				assign0(reg2); \
			} \
			notBitReg(reg1); \
			andBitReg((reg1), (reg2), (reg3)); \
			notBitReg(reg1); \
			xorBitReg((reg1), (reg2), (regr)); \
			assign((regr),(reg1)); \
			assign((reg3),(reg2)); \ 
			shiftLeft((reg2)); \
			assign(reg1, regr);

#define multiply(reg1, reg2, reg3, regr, reg5, reg6) \
			assign0(regr); \
			if (reg2.bit1){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit2){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit3){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit4){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit5){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit6){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit7){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \
			if (reg2.bit8){ \
				assign(reg1,reg6); \
				add(regr, reg6, reg5, regr); \
			}	 \

#define divide(reg1, reg2, reg3, regr, reg5, reg6) \
			assign0(regr); \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
						assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \
			assign(reg1, reg5); \
			assign(reg2, reg6); \
			substract(reg1, reg2, reg3, reg1); \
			if (isZero(reg1)){ \
				if (isEqual(reg5,reg6)){ \
					increment(regr); \
				}\
				goto akhirbagi; \
			} \
			else { \
				increment(regr); \
				assign(reg5, reg1); \
				assign(reg6, reg2); \
			} \

			




typedef struct {
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
	unsigned int bit8 : 1;
} reg;

reg reg1;
reg reg2;
reg reg3;
reg reg4;
reg reg5;
reg reg6;

int main(int argc, char* argv[]){
	
	FILE *file = fopen("math.txt", "r");
	char c;

	if (file == NULL) {
		printf("File notBit found!\n");

		exit(1);
	}
	assign0(reg1);
	assign0(reg2);
	assign0(reg3);
	assign0(reg4);
	assign0(reg5);
	assign0(reg6);
	if ((c = fgetc(file)) != EOF){
		convert(c, reg1);
	}
	else{
		goto print;
	}
	if ((c = fgetc(file)) != EOF ){
		if (notBit(c == '0' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '8' || c  == '9')){
			goto next;
		}
		else{
			assign0(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			multiply(reg1, reg3, reg2, reg4, reg5, reg6);
			assign(reg4, reg1);
			convert(c, reg2);
			add(reg1, reg2, reg3, reg4);
			assign(reg4, reg1);
		}
	}
	else{
		goto print;
	}
	if ((c = fgetc(file)) != EOF ){
		if (notBit(c == '0' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '8' || c  == '9')){
			goto next;
		}
		else{
			assign0(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			increment(reg3);
			multiply(reg1, reg3, reg2, reg4, reg5, reg6);
			assign(reg4, reg1);
			convert(c, reg2);
			add(reg1, reg2, reg3, reg4);
			assign(reg4, reg1);
		}
	}
	else{
		goto print;
	}
	while ((c = fgetc(file)) != EOF) {	
	next:	
		if (c == '0' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '1' || c  == '8' || c  == '9'){
			time10(reg2);
			convert(c, reg5);
			add(reg2, reg5, reg3, reg4);
			assign(reg4, reg2);
		}
		else if (c == '+'){
			if (reg6.bit1){
				add(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit2){
				substract(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit3){
				multiply(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			else if (reg6.bit4){
				divide(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			assign(reg4, reg1);
			assign0(reg6);
			reg6.bit1 = 1;
		}
		else if (c == '-'){
			if (reg6.bit1){
				add(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit2){
				substract(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit3){
				multiply(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			else if (reg6.bit4){
				divide(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			assign(reg4, reg1);
			assign0(reg6);
			reg6.bit2 = 1;
		}
		else if (c == '*'){
			if (reg6.bit1){
				add(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit2){
				substract(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit3){
				multiply(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			else if (reg6.bit4){
				divide(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			assign(reg4, reg1);
			assign0(reg6);
			reg6.bit3 = 1;
		}
		else if (c == '/'){
			if (reg6.bit1){
				add(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit2){
				substract(reg1, reg2, reg3, reg4);
			}
			else if(reg6.bit3){
				multiply(reg1, reg2, reg3, reg4, reg5, reg6);
			}
			else if (reg6.bit4){
				divide(reg1, reg2, reg3, reg4, reg5, reg6);
			}
		akhirbagi:
			assign(reg4, reg1);
			if (c == EOF){
				goto print; 
			}
			assign0(reg6);
			if (c == '+'){
				reg6.bit1 = 1;
			}
			else if (c == '-'){
				reg6.bit2 = 1;
			}
			else if (c == '*'){
				reg6.bit3 = 1;
			}
			else if(c == '/'){
				reg6.bit4 = 1;
			}
		}
	}
	if (reg6.bit1){
		add(reg1, reg2, reg3, reg4);
	}
	else if(reg6.bit2){
		substract(reg1, reg2, reg3, reg4);
	}
	else if(reg6.bit3){
		multiply(reg1, reg2, reg3, reg4, reg5, reg6);
	}
	else if (reg6.bit4){
		divide(reg1, reg2, reg3, reg4, reg5, reg6);
	}
	assign(reg4, reg1);
print:
	if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("0");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("1");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("2");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("3");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("4");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("5");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("6");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("7");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("8");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("9");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("10");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("11");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("12");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("13");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("14");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("15");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("16");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("17");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("18");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("19");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("20");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("21");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("22");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("23");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("24");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("25");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("26");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("27");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("28");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("29");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("30");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("31");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("32");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("33");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("34");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("35");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("36");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("37");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("38");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("39");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("40");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("41");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("42");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("43");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("44");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("45");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("46");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("47");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("48");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("49");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("50");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("51");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("52");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("53");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("54");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("55");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("56");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("57");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("58");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("59");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("60");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("61");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("62");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("63");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("64");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("65");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("66");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("67");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("68");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("69");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("70");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("71");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("72");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("73");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("74");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("75");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("76");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("77");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("78");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("79");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("80");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("81");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("82");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("83");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("84");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("85");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("86");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("87");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("88");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("89");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("90");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("91");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("92");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("93");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("94");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("95");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("96");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("97");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("98");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("99");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("100");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("101");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("102");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("103");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("104");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("105");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("106");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("107");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("108");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("109");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("110");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("111");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("112");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("113");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("114");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("115");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("116");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("117");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("118");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("119");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("120");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("121");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("122");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("123");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("124");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("125");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("126");
	}

	else if ((reg4.bit1 == 0) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("127");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("128");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("129");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("130");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("131");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("132");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("133");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("134");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("135");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("136");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("137");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("138");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("139");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("140");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("141");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("142");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("143");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("144");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("145");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("146");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("147");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("148");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("149");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("150");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("151");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("152");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("153");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("154");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("155");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("156");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("157");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("158");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("159");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("160");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("161");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("162");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("163");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("164");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("165");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("166");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("167");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("168");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("169");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("170");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("171");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("172");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("173");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("174");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("175");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("176");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("177");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("178");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("179");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("180");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("181");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("182");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("183");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("184");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("185");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("186");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("187");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("188");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("189");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("190");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 0) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("191");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("192");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("193");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("194");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("195");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("196");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("197");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("198");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("199");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("200");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("201");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("202");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("203");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("204");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("205");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("206");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("207");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("208");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("209");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("210");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("211");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("212");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("213");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("214");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("215");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("216");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("217");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("218");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("219");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("220");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("221");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("222");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 0) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("223");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("224");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("225");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("226");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("227");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("228");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("229");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("230");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("231");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("232");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("233");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("234");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("235");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("236");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("237");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("238");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 0) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("239");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("240");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("241");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("242");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("243");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("244");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("245");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("246");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 0) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("247");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("248");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("249");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("250");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 0) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("251");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 0)){
		printf("252");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 0) && (reg4.bit8 == 1)){
		printf("253");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 0)){
		printf("254");
	}

	else if ((reg4.bit1 == 1) && (reg4.bit2 == 1) && (reg4.bit3 == 1) && (reg4.bit4 == 1) && (reg4.bit5 == 1) && (reg4.bit6 == 1) && (reg4.bit7 == 1) && (reg4.bit8 == 1)){
		printf("255");
	}
	printf("\n");
    return 0;
}
