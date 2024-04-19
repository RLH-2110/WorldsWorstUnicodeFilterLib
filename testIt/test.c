#include<wchar.h>
#include"filter.h"
#include"workaround.h"

int main() {
	int ret = 0;


	// check if filtered ones are seen as valid

	if (filterUnicode(0x0, FilterTag_Controll)) aPuts("test 1 failed! 0x0 'NULL' is not filtered in FilterTag_Controll!",&ret);
	if (filterUnicode(0x80, FilterTag_Controll)) aPuts("test 2 failed! 0x80 '<controll>' is not filtered in FilterTag_Controll!", &ret);

	if (filterUnicode(0x8, FilterTag_Deletion)) aPuts("test 3 failed! 0x8 'Backspace' is not filtered in FilterTag_Deletion!", &ret);
	if (filterUnicode(0x7F, FilterTag_Deletion)) aPuts("test 4 failed! 0x7F 'Delete' is not filtered in FilterTag_Deletion!", &ret);

	if (filterUnicode(0x20, FilterTag_Spaces)) aPuts("test 5 failed! 0x20 'Space' is not filtered in FilterTag_Spaces!", &ret);
	if (filterUnicode(0x3000, FilterTag_Spaces)) aPuts("test 6 failed! 0x3000 'IDEOGRAPHIC SPACE' is not filtered in FilterTag_Spaces!", &ret);
	
	
	if (filterUnicode(0xA, FilterTag_NewLines)) aPuts("test 7 failed! 0xA 'LINE FEED' is not filtered in FilterTag_NewLines!", &ret);
	if (filterUnicode(0xD, FilterTag_NewLines)) aPuts("test 8 failed! 0xD 'CARRIAGE RETURN' is not filtered in FilterTag_NewLines!", &ret);
	if (filterUnicode(0x2028, FilterTag_NewLines)) aPuts("test 9 failed! 0x2028 'LINE SEPARATOR' is not filtered in FilterTag_NewLines!", &ret);

	if (filterUnicode(0xC, FilterTag_PageBreak)) aPuts("test 10 failed! 0xC 'FORM FEED' is not filtered in FilterTag_PageBreak!", &ret);

	if (filterUnicode(0x1B, FilterTag_Escape)) aPuts("test 11 failed! 0x1B 'ESCAPE' is not filtered in FilterTag_Escape!", &ret);

	if (filterUnicode(0x2060, FilterTag_NonSpaceInvis)) aPuts("test 12 failed! 0x2060 'WORD JOINER' is not filtered in FilterTag_NonSpaceInvis!", &ret);

	if (filterUnicode(0x378, FilterTag_Unassigned)) aPuts("test 13 failed! 0x378 'UNASSINGED' is not filtered in FilterTag_Unassigned!", &ret);
	if (filterUnicode(0x1257, FilterTag_Unassigned)) aPuts("test 14 failed! 0x1257 'UNASSINGED' is not filtered in FilterTag_Unassigned!", &ret);
	if (filterUnicode(0xfb3f, FilterTag_Unassigned)) aPuts("test 15 failed! 0xfb3f 'UNASSINGED' is not filtered in FilterTag_Unassigned!", &ret);
	if (filterUnicode(0x16b90, FilterTag_Unassigned)) aPuts("test 16 failed! 0x16b90 'UNASSINGED' is not filtered in FilterTag_Unassigned!", &ret);
	if (filterUnicode(0xdffff, FilterTag_Unassigned)) aPuts("test 17 failed! 0xdffff 'UNASSINGED' is not filtered in FilterTag_Unassigned!", &ret);

	if (filterUnicode(0x82, FilterTag_PossibleNL)) aPuts("test 18 failed! 0x82 'BREAK PERMITTED HERE' is not filtered in FilterTag_PossibleNL!", &ret);

	if (filterUnicode(0x61c, FilterTag_Modify)) aPuts("test 19 failed! 0x61c 'ARABIC LETTER MARK' is not filtered in FilterTag_Modify!", &ret);
	if (filterUnicode(0x200e, FilterTag_Modify)) aPuts("test 20 failed! 0x200e 'LEFT-TO-RIGHT MARK' is not filtered in FilterTag_Modify!", &ret);
	if (filterUnicode(0xfff9, FilterTag_Modify)) aPuts("test 21 failed! 0xfff9 'INTERLINEAR ANNOTATION ANCHOR' is not filtered in FilterTag_Modify!", &ret);
	if (filterUnicode(0x1bca2, FilterTag_Modify)) aPuts("test 22 failed! 0x1bca2 'SHORTHAND FORMAT DOWN STEP' is not filtered in FilterTag_Modify!", &ret);

	if (filterUnicode(0x2061, FilterTag_IDontKnow)) aPuts("test 23 failed! 0x2061 'FUNCTION APPLICATION' is not filtered in FilterTag_IDontKnow!", &ret);

	if (filterUnicode(0xd800, FilterTag_Surrogate)) aPuts("test 24 failed! 0xd800 '<Non Private Use High Surrogate, First>' is not filtered in FilterTag_Surrogate!", &ret);
	if (filterUnicode(0xdfff, FilterTag_Surrogate)) aPuts("test 25 failed! 0xdfff '<Low Surrogate, Last>' is not filtered in FilterTag_Surrogate!", &ret);

	// see if valid ones get filtered

	if (!filterUnicode(0x50, 0xffffffff)) aPuts("test 26 failed! 0x50 'LATIN CAPITAL LETTER P' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x500, 0xffffffff)) aPuts("test 27 failed! 0x500 'CYRILLIC CAPITAL LETTER KOMI DE' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x5000, 0xffffffff)) aPuts("test 28 failed! 0x5000 'CJK Unified Ideo­graph-​5000' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x10140, 0xffffffff)) aPuts("test 29 failed! 0x10140 'Greek Acrophonic Attic One Quarter' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x1F781, 0xffffffff)) aPuts("test 30 failed! 0x1F781 'Black Up-Pointing Isosceles Right Triangle' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x20049, 0xffffffff)) aPuts("test 31 failed! 0x20049 'Ideograph chu' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x606, 0xffffffff)) aPuts("test 32 failed! 0x606 'Arabic-Indic Cube Root' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x800, 0xffffffff)) aPuts("test 33 failed! 0x800 'Samaritan Letter Alaf' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x1000, 0xffffffff)) aPuts("test 34 failed! 0x1000 'Myanmar Letter Ka' is filtered, but it should not be!", &ret);
	if (!filterUnicode(0x1A9, 0xffffffff)) aPuts("test 35 failed! 0x1A9 'Latin Capital Letter Esh' is filtered, but it should not be!", &ret);

	puts("test complete!");
	return ret;
}

int aPuts(char* str, int* ret) {	// set the ret value to -1 and execute the puts
	*ret = -1;
	return puts(str);
}