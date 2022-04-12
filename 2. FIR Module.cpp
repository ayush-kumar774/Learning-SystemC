#include "systemc.h"

// FIR filter module
SC_MODULE (fir) {
        sc_in <bool> clk;
        sc_in <bool> rst;
        sc_in  < sc_uint <16> > inp ;
        sc_out < sc_uint <16> > outp ;

        void fir_main() ;

        SC_CTOR(fir) {
                SC_CTHREAD (fir_main , clk.pos());
                reset_signal_is (rst, true); // true means reset is asserted to high while false means it is asserted to low
        }

};

const sc_uint<8> coef[5] = {
        18, 77, 107, 87, 78
};

// FIR main thread

void fir::fir_main(void) {
        sc_int <16> taps[5] ;

        outp.write(0) ;
        wait();

        while (true)
        {
                for (int i = 5 - 1; i > 0 ; i--) {
                        taps[i] = taps[i - 1] ;
                }
                taps[0] = inp.read() ;

                sc_int<16> val;
                for (int i = 0 ; i < 5 ; i++) {
                        val += coef[i] * taps[i] ;
                }
                outp.write(val);
                wait();
        }
        
}

int sc_main(int argc, char* argv[])
{
        return 0 ;
}