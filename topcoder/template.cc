$BEGINCUT$
$PROBLEMDESC$
$ENDCUT$

#line $NEXTLINENUMBER$ "$FILENAME$"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class $CLASSNAME$ {
	public:
	$RC$ $METHODNAME$($METHODPARMS$) {
	}
	$TESTCODE$
};

$BEGINCUT$
int main() {
	$CLASSNAME$ ___test;
	___test.run_test(-1);
	return 0;
}
$ENDCUT$
