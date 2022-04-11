#include <systemc.h>
SC_MODULE ( and2 ) {
        //sc_in <DT> a ; // DT --> Data Type
        //sc_in <DT> b ; 
        //sc_out <DT> f ;

        sc_in < sc_uint<1> > a, b ;
        sc_out < sc_uint<1> > f ;
        sc_in <bool> clk ;// clock

        void func() {
                f.write( a.read() & b.read() ) ;
        }

        SC_CTOR ( and2 ) {
                // Constructor   
                SC_METHOD ( func );
                //sensitive << a << b ; // in systemC the left shift operator is overloaded to represent a list of sensitive signals or events 
                //sensitive << clk.pos() ; // positive edge sensitive
                sensitive << clk.neg() ; // negative edge sensitive
        }

} 
