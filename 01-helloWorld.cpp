#include "systemc.h"

SC_MODULE(hello_world) {
        SC_CTOR(hello_world) {
                // Nothing in the constructor
        }
        void say_hello() {
                // Print "Hello World" to the console
                cout << "Hello World\n" ;
        }
};

int sc_main(int argc, char* argv[]) {
        hello_world hello("Hello") ;
        // Print the hello world
        hello.say_hello() ;
        return 0 ;
}