#include <stack>
#include <string>
#include <map>
#include <functional>

using namespace std;

/**
 * The Code Generator class
 */
class Code {
	private:
		int ifCounter;
		int whileCounter;
		int forCounter;
		int blockCounter;
		string aux1;
		string aux2;
		stack<string> _stack;

	public:
		Code();
		void generateCode(string action, string lex);
		void r0();
		void r1();
		void r2(string lex);
		void r3();
		void r4();
		void r5(string lex);
		void r6();
		void r7();
		void r8();
		void r9();
		void r10();
		void r11();
		void r12();
		void r13();
		void r14();
		void r15();
		void r16();
		void r17();
		void r18();
		void r19();
		void r20(string lex);
		void r21();
		void r22();
		void r23();
		void r24();
		void r25();
		void r26();
		void r27();
};