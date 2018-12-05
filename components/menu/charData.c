#include <esp_system.h>

bool characters[70][7][6]=	{
/*A*/			{{0,0,1,1,0,0},
				 {0,1,0,0,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*B*/			{{1,1,1,1,1,0},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,1},
				 {0,1,1,1,1,0},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,1},
				 {1,1,1,1,1,0}},

/*C*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*D*/			{{1,1,1,1,0,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,1,0},
				 {1,1,1,1,0,0}},

/*E*/			{{1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {1,1,1,1,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,1}},

/*F*/			{{1,1,1,1,1,1},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,0},
				 {0,1,1,1,0,0},
				 {0,1,0,0,0,0},
				 {0,1,0,0,0,0},
				 {1,1,1,0,0,0},},

/*G*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {1,0,0,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*H*/			{{1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*I*/			{{0,1,1,1,1,1},
				 {0,1,0,1,0,1},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,1,0,1,0,1},
				 {0,1,1,1,1,1}},

/*J*/			{{1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*K*/			{{0,1,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,1,0,1,0,0},
				 {0,1,1,0,0,0},
				 {0,1,0,1,0,0},
				 {0,1,0,0,1,0},
				 {0,1,0,0,0,1}},

/*L*/			{{1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,1}},

/*M*/			{{0,1,0,0,0,1},
				 {0,1,1,0,1,1},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,1}},

/*N*/			{{1,0,0,0,0,1},
				 {1,1,0,0,0,1},
				 {1,0,1,0,0,1},
				 {1,0,0,1,0,1},
				 {1,0,0,0,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*O*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*P*/			{{1,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,1,0,0,0,0}},

/*Q*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,1,0,1},
				 {1,0,0,0,1,0},
				 {0,1,1,1,0,1}},

/*R*/			{{1,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,0},
				 {1,0,1,0,0,0},
				 {1,0,0,1,0,0},
				 {1,0,0,0,1,1}},

/*S*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {0,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*T*/			{{0,1,1,1,1,1},
				 {0,1,0,1,0,1},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,1,1,1,0}},

/*U*/			{{1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*V*/			{{1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0}},

/*W*/			{{0,1,0,0,0,1},
				 {0,1,0,0,0,1},
				 {0,1,0,0,0,1},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1},
				 {0,0,1,0,1,0},
				 {0,0,1,0,1,0}},

/*X*/			{{1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0},
				 {0,1,0,0,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*Y*/			{{1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0},
				 {0,0,1,0,0,0},
				 {0,1,0,0,0,0},
				 {1,0,0,0,0,0}},

/*Z*/			{{1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {0,0,0,0,1,0},
				 {0,0,1,1,0,0},
				 {0,1,0,0,0,0},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,1}},

/*a*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {0,0,0,0,0,1},
				 {0,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*b*/			{{1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,0}},

/*c*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*d*/			{{0,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {0,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,1}},

/*e*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,0},
				 {1,0,0,0,0,0},
				 {0,1,1,1,1,0}},

/*f*/			{{0,0,0,1,1,1},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,1,1,1,1,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,1,1,1,0,0}},

/*g*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,1},
				 {0,0,0,0,0,1},
				 {1,1,1,1,1,0}},

/*h*/			{{1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,1,1,1,0},
				 {1,1,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*i*/			{{0,0,0,1,0,0},
				 {0,0,0,0,0,0},
				 {0,1,1,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0}},

/*j*/			{{0,0,0,0,0,0},
				 {0,0,1,1,1,0},
				 {0,0,0,0,1,0},
				 {0,0,0,0,1,0},
				 {0,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {0,1,1,1,0,0}},

/*k*/			{{1,0,0,0,0,0},
				 {1,0,0,1,0,0},
				 {1,0,1,0,0,0},
				 {1,1,0,0,0,0},
				 {1,0,1,0,0,0},
				 {1,0,0,1,0,0},
				 {1,0,0,0,1,0}},

/*l*/			{{0,1,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,1,1,1,0,0}},

/*m*/			{{0,0,0,0,0,0},
				 {1,0,1,0,1,0},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1},
				 {0,1,0,1,0,1}},

/*n*/			{{0,0,0,0,0,0},
				 {1,0,1,1,1,0},
				 {1,1,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*o*/			{{0,0,0,0,0,0},
				 {0,1,1,1,0,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {0,1,1,1,0,0}},

/*p*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,1,1,1,1,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0}},

/*q*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,1},
				 {0,0,0,0,0,1},
				 {0,0,0,0,1,1}},

/*r*/			{{0,0,0,0,0,0},
				 {1,1,0,1,1,0},
				 {0,1,1,0,0,1},
				 {0,1,0,0,0,0},
				 {0,1,0,0,0,0},
				 {0,1,0,0,0,0},
				 {0,1,1,0,0,0}},

/*s*/			{{0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {0,1,1,0,0,0},
				 {0,0,0,1,1,0},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*t*/			{{0,1,0,0,0,0},
				 {1,1,1,1,0,0},
				 {0,1,0,0,0,0},
				 {0,1,0,0,0,0},
				 {0,1,0,0,0,0},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0}},

/*u*/			{{0,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,1,1},
				 {0,1,1,1,0,1}},

/*v*/			{{0,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0}},

/*w*/			{{0,0,0,0,0,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {1,0,1,0,1,0},
				 {1,0,1,0,1,0},
				 {0,1,0,1,0,0}},

/*x*/			{{0,0,0,0,0,0},
				 {1,0,0,0,0,1},
				 {0,1,0,0,1,0},
				 {0,0,1,1,0,0},
				 {0,1,0,0,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1}},

/*y*/			{{0,0,0,0,0,0},
				 {1,0,0,0,1,0},
				 {1,0,0,0,1,0},
				 {0,1,0,0,1,0},
				 {0,0,1,1,1,0},
				 {0,0,0,0,1,0},
				 {0,1,1,1,0,0}},

/*z*/			{{0,0,0,0,0,0},
				 {1,1,1,1,1,1},
				 {0,0,0,0,1,0},
				 {0,0,0,1,0,0},
				 {0,0,1,0,0,0},
				 {0,1,0,0,0,0},
				 {1,1,1,1,1,1}},

/*0*/			{{0,0,1,1,1,0},
				 {0,1,0,0,0,1},
				 {0,1,0,0,1,1},
				 {0,1,0,1,0,1},
				 {0,1,1,0,0,1},
				 {0,1,0,0,0,1},
				 {0,0,1,1,1,0}},

/*1*/			{{0,0,0,1,0,0},
				 {0,0,1,1,0,0},
				 {0,1,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,1,1,1,0}},

/*2*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,1,1,1,1,1}},

/*3*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {0,0,1,1,1,0},
				 {0,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*4*/			{{0,0,0,0,1,0},
				 {0,0,0,1,1,0},
				 {0,0,1,0,1,0},
				 {0,1,0,0,1,0},
				 {1,1,1,1,1,1},
				 {0,0,0,0,1,0},
				 {0,0,0,1,1,1}},

/*5*/			{{0,1,1,1,1,1},
				 {0,1,0,0,0,0},
				 {0,1,1,1,1,0},
				 {0,0,0,0,0,1},
				 {0,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*6*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,0},
				 {1,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*7*/			{{1,1,1,1,1,1},
				 {1,0,0,0,0,1},
				 {0,0,0,0,1,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0}},

/*8*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*9*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,1},
				 {0,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,1,1,1,1,0}},

/*?*/			{{0,1,1,1,1,0},
				 {1,0,0,0,0,1},
				 {1,0,0,0,0,1},
				 {0,0,0,0,1,0},
				 {0,0,0,1,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,1,0,0}},

/*!*/			{{1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {1,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {1,0,0,0,0,0}},

/*.*/			{{0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {1,1,0,0,0,0},
				 {1,1,0,0,0,0}},

/*,*/			{{0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {1,1,0,0,0,0},
				 {1,1,0,0,0,0},
				 {1,0,0,0,0,0}},

/*:*/			{{0,0,0,0,0,0},
				 {1,1,0,0,0,0},
				 {1,1,0,0,0,0},
				 {0,0,0,0,0,0},
				 {1,1,0,0,0,0},
				 {1,1,0,0,0,0},
				 {0,0,0,0,0,0}},

/*(*/			{{0,0,0,0,1,1},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,1,0,0},
				 {0,0,0,0,1,1}},

/*)*/			{{1,1,0,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {0,0,1,0,0,0},
				 {1,1,0,0,0,0}},

/*-*/			{{0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0},
				 {0,1,1,1,1,0},
				 {0,0,0,0,0,0},
				 {0,0,0,0,0,0}}

};

bool errNoChar[14][12]={{0,0,1,1,1,1,1,1,1,1,0,0},
						{0,1,1,1,1,1,1,1,1,1,1,0},
						{1,1,1,1,1,1,1,1,1,1,1,1},
						{1,1,0,0,1,1,1,1,0,0,1,1},
						{1,0,0,0,0,1,1,0,0,0,0,1},
						{1,0,0,0,0,1,1,0,0,0,0,1},
						{1,0,0,0,0,1,1,0,0,0,0,1},
						{1,1,0,0,1,1,1,1,0,0,1,1},
						{1,1,1,1,1,0,0,1,1,1,1,1},
						{0,1,1,1,0,0,0,0,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,0},
						{0,0,1,1,1,1,1,1,1,1,0,0},
						{0,0,1,1,1,1,1,1,1,1,0,0},
						{0,0,1,0,1,0,0,1,0,1,0,0}};

bool getPixel(char actChar, int xMod, int yMod){
	if(xMod<2 || xMod>13 || yMod<2 || yMod>15) return 0;
	else{
		if(actChar==' ')return 0;
		else if(actChar>96 && actChar<123){
			return characters[actChar-97+26][(yMod-2)][(xMod-2)];
		}
		else if(actChar>64 && actChar<91){
			return characters[actChar-65][(yMod-2)][(xMod-2)];
		}
		else if(actChar>47 && actChar<58){
			return characters[actChar-48+52][(yMod-2)][(xMod-2)];
		}
		else{
			if(actChar=='-')return characters[69][(yMod-2)][(xMod-2)];
			else if(actChar==')')return characters[68][(yMod-2)][(xMod-2)];
			else if(actChar=='(')return characters[67][(yMod-2)][(xMod-2)];
			else if(actChar==':')return characters[66][(yMod-2)][(xMod-2)];
			else if(actChar==',')return characters[65][(yMod-2)][(xMod-2)];
			else if(actChar=='.')return characters[64][(yMod-2)][(xMod-2)];
			else if(actChar=='!')return characters[63][(yMod-2)][(xMod-2)];
			else if(actChar=='?')return characters[62][(yMod-2)][(xMod-2)];
			else return errNoChar[yMod-2][xMod-2];
		}
	}
};
