/* 
 *
 *
 *
 *          TEST MAIN FILE FOR CMSIS-DSP X86 PORT
 * 
 * 
 * 
 * 
*/
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "arm_math.h"


#define FFT_SIZE 256

#include "adc_20ms_log.h"
q15_t input[FFT_SIZE * 2] = {0};


    arm_cfft_radix4_instance_q15 fft_inst;
    // arm_cfft_instance_q15 fft_inst;
    int main(void)
    {
        
        for (uint16_t i = 0; i < FFT_SIZE; i++)
        {
            input[i * 2] = (signed)(sample[i] - (q15_t)512);
            input[(i * 2) + 1] = 0;
        }
       
        arm_shift_q15(input, 8, input, FFT_SIZE * 2);
        // Initialize FFT
        arm_cfft_radix4_init_q15(&fft_inst, FFT_SIZE, 0, 1); // forward FFT, bit reverse = 1
        // Perform FFT
        arm_cfft_radix4_q15(&fft_inst, input);
        

// Print real part of ifft output
printf("IFFT Output (real parts):\n");
for (int i = 0; i < FFT_SIZE; i++) {
    printf("(%d,%d)\t", input[2*i], input[2*i +1]);
    if ((i % 16) == 0) printf("\n");
}
fflush(stdout);
   

        return 0;
}
