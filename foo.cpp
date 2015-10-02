// g++ -c -fPIC foo.cpp -o foo.o
// g++ -shared -Wl,libfoo.so -o libfoo.so  foo.o


#include <iostream>

class Foo{
public:
     void bar(){
	  std::cout << "Hello" << std::endl;
     }
};
extern "C" {
     Foo* Foo_new(){ return new Foo(); }
     void Foo_bar(Foo* foo){ foo->bar(); }
}
