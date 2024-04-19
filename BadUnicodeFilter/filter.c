#include"filter.h"
#include"data.c"

typedef unsigned int uint;

uint LoselySearch(uint uchar);


bool filterUnicode(uint uchar, unsigned short filter) {
	if (uchar > MaximumSupportedUnicodeValue) return false;	// I havent categorized it yes, so I assume its invalid.

	for (unsigned int i = LoselySearch(uchar); true; i++) {	// for every element in the list from the start point
		if (Ufilter[i].start == end_of_table.start)	// end of table = did not match a filter
			return true;
		

		if (uchar < Ufilter->start)	// unicode bigger than the unicode we gave it = did not match a filter
			return true;


		if (uchar >= Ufilter[i].start && uchar <= Ufilter[i].end) { // matches a range
			if ((filter & Ufilter[i].tag) != 0)						// matches the filter
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