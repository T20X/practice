#ifndef _NUMERIC_UTIL_HPP_
#define _NUMERIC_UTIL_HPP_
/*
A lot of people gave the basic answer but nobody pointed out that in C++ const defaults to static
at namespace level (and some gave wrong information). See the C++98 standard section 3.5.3

static const int sci = 0; // sci is explicitly static
const int ci = 1;         // ci is implicitly static
extern const int eci = 2; // eci is explicitly extern
extern int ei = 3;        // ei is explicitly extern
int i = 4;                // i is implicitly extern
static int si = 5;        // si is explicitly static


*/

const static int _NULL_ = -999999999;

#endif //_NUMERIC_UTIL_HPP_