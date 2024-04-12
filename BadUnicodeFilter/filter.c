#include"filter.h"

#define END_OF_TABLE {0xFFFFFF,0xFFFFFF,FilterTag_Controll} // this is not unicode, but I use it to mark the end of the table, simelar on how \0 ends a string
typedef unsigned int uint;


uint LoselySearch(uint uchar);

UNIfilter Ufilter[] = { 
	{0x0 , 0x7, FilterTag_Controll},
	{0x8 , 0x8, FilterTag_Deletion},
	{0x9 , 0x9, FilterTag_Spaces},
	{0xA , 0xB, FilterTag_NewLines},
	{0xC , 0xC, FilterTag_PageBreak},
	{0xD , 0xD, FilterTag_NewLines},
	{0xE , 0x1A, FilterTag_Controll},
	{0x1B , 0x1B, FilterTag_Escape},
	{0x1C , 0x1F, FilterTag_Escape},
	{0x20 , 0x20, FilterTag_Spaces},
	{0x1F , 0x1F, FilterTag_Deletion},

	{0x1F , 0x1F, FilterTag_Deletion},
	{0x1F , 0x1F, FilterTag_Hyphen},
	{0x34F , 0x34F, FilterTag_CharModify},
	{0x378 , 0x379, FilterTag_Unassinged},
	{0x380 , 0x383, FilterTag_Unassinged},
	{0x38B , 0x38B, FilterTag_Unassinged},
	{0x38D , 0x38D, FilterTag_Unassinged},
	{0x3A2 , 0x3A2, FilterTag_Unassinged},
	{0x530 , 0x530, FilterTag_Unassinged},
	{0x557 , 0x558, FilterTag_Unassinged},
	{0x58B , 0x58C, FilterTag_Unassinged},
	{0x590 , 0x590, FilterTag_Unassinged},
	{0x5C8 , 0x5CF, FilterTag_Unassinged},
	{0x5EB , 0x5EE, FilterTag_Unassinged},
	{0x5F5 , 0x5FF, FilterTag_Unassinged},
	
	{0x61C , 0x61C, FilterTag_CharModify},

	{0x70E , 0x70E, FilterTag_Unassinged},
	{0x74B , 0x74C, FilterTag_Unassinged},
	{0x7B2 , 0x7BF, FilterTag_Unassinged},
	{0x7FB , 0x7FC, FilterTag_Unassinged},
	{0x82E , 0x82F, FilterTag_Unassinged},
	{0x83F , 0x83F, FilterTag_Unassinged},
	{0x85C , 0x85D, FilterTag_Unassinged},
	{0x85F , 0x85F, FilterTag_Unassinged},
	{0x86B , 0x86F, FilterTag_Unassinged},
	{0x892 , 0x897, FilterTag_Unassinged},
	{0x984 , 0x984, FilterTag_Unassinged},
	{0x98D , 0x98E, FilterTag_Unassinged},
	{0x991 , 0x992, FilterTag_Unassinged},
	{0x9A9 , 0x9A9, FilterTag_Unassinged},
	{0x9B1 , 0x9B1, FilterTag_Unassinged},
	{0x9B3 , 0x9B5, FilterTag_Unassinged},
	{0x9BA , 0x9BB, FilterTag_Unassinged},
	{0x9C5 , 0x9C6, FilterTag_Unassinged},
	{0x9C9 , 0x9CA, FilterTag_Unassinged},
	{0x9CF , 0x9D6, FilterTag_Unassinged},
	{0x9D8 , 0x9DB, FilterTag_Unassinged},
	{0x9DE , 0x9DE, FilterTag_Unassinged},
	{0x9E4 , 0x9E5, FilterTag_Unassinged},
	{0x9FF , 0xA00, FilterTag_Unassinged},
	{0xA0B , 0xA0B, FilterTag_Unassinged},
	{0xA04 , 0xA04, FilterTag_Unassinged},
	{0xA0B , 0xA0E, FilterTag_Unassinged},

	// more chars here

	END_OF_TABLE
};

UNIfilter end_of_table = END_OF_TABLE;


bool filterUnicode(uint uchar, unsigned short filter) {
	if (uchar > MaximumSupportedUnicodeValue) return false;	// I havent categorized it yes, so I assume its invalid.

	for (unsigned int i = LoselySearch(uchar); true; i++) {	// for every element in the list from the start point
		if (Ufilter[i].start == end_of_table.start)
			return true;

		if (uchar < Ufilter->start)
			return true;

		if (uchar >= Ufilter[i].start && uchar <= Ufilter[i].end) {
			if ((filter & Ufilter[i].tag) != 0)
				return false;
		}
	}
}


uint LoselySearch(uint uchar) {			// gives an index of either 0/1, 1/3, 1/2 or 3/4 of the list

	uint center = sizeof(Ufilter) / sizeof(UNIfilter) / 2;	

	if (uchar < Ufilter[center].start) {
		center /= 2;
		if (uchar < Ufilter[center].start) 
			return 0;
		else return center;
	}
	else {
		center *= 2;
		if (uchar < Ufilter[center].start)
			return center /2;
		else return center;

	}
}