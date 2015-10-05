// g++ -c -fPIC foo.cpp -o foo.o
// g++ -shared -Wl,libfoo.so -o libfoo.so  foo.o

/* Example to wrap C functions in python using ctypes

   See http://stackoverflow.com/questions/145270/calling-c-c-from-python

   ** C++ example file **
   compile it as a shared lib with
   g++ -c -fPIC foo.cpp -o foo.o
   and
   g++ -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.o

   Use it with Python wrapper at http://pastebin.com/0D700WPb

*/

#include <iostream>

class Foo{
    public:
        void bar(){
            std::cout << "Hello" << std::endl;
        }
        int doubleme (int input){
	   std::cout << "Doubling " << input << std::endl;
	   return 2*input;
	}
	void printfloat (double input){
	   std::cout << "Printing a float " << input << std::endl;
	}

};


extern "C" {
    Foo* Foo_new(){ return new Foo(); }
    void Foo_bar(Foo* foo){ foo->bar(); }
    int  Foo_doubleme (Foo* foo, int input) {return foo->doubleme(input);}
    void Foo_printfloat (Foo* foo, double input) {return foo->printfloat(input);}
}