#pragma once

/*
					7 6 5 4 3 2 1 0
	
	CPirate			0 0 0 0 0 0 0 1      1 << 0     0x01
	CSailor			0 0 0 0 0 0 1 0		 1 << 1     0x02
	CAlien			0 0 0 0 0 1 0 0		 1 << 2		0x03
	CPolice			0 0 0 0 1 0 0 0		 1 << 3     0x04
	CThief			0 0 0 1 0 0 0 0      1 << 4		0x05
	CZuckerberg		0 0 1 0 0 0 0 0      1 << 5		0x06
	CActor			0 1 0 0 0 0 0 0      1 << 6		0x07

*/

#define CPirate				 0x01	
#define CSailor			     0x02
#define CAlien				 0x03
#define CPolice				 0x04
#define CThief				 0x05
#define CZuckerberg			 0x06
#define CActor				 0x07

