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
		int labelCounter;
		stack<string> _stack;

	public:
		Code();
		void generateCode(string action);
		void r0();
		void r1();

};