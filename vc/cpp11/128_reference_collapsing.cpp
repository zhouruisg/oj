// 2019/03/21
//
#include <codech/codech_def.h>
using namespace std;
namespace {
	void noref2ref() {
		int x;
		//auto& &rx = x; //error C2529: 'rx': reference to reference is illegal
	}

	

	template<typename T>
	T&& myforward(typename remove_reference<T>::type& param) {
		return static_cast<T&&>(param); 
	}

	template<typename T>
	void f(T&& fparam) {
		string s(myforward<T>(fparam));  // forward ,convert to rvalue only it is rvalue.
		cout << s << endl;
	}

	string makeString() {
		string s = "localstring";
		return s;
	}
	
	template<typename T>
	void f1(const T& param) {
		cout << typeid(T).name() << endl;
	}

	void testDeduce1() {
		//f1(27); // it is not rvalue?  cannot convert argument 1 from 'int' to 'T &'
		f1(makeString());
	}

	void testMyForward() {
		f(makeString());		
	}

}

DEFINE_CODE_TEST(127_ref_collapsing)
{
	//noref2ref();
	testDeduce1();
	testMyForward();

}