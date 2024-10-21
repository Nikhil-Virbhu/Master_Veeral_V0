/*
 * Header file for: bandpass filter
 * Generated with : PLECS 4.7.5
 * Generated on   : 31 Jan 2024 14:21:35
 */
#ifndef PLECS_HEADER_bandpass_filter_h_
#define PLECS_HEADER_bandpass_filter_h_

#include <stdbool.h>
#include <stdint.h>
#include "main.h"


//extern float lowpass_out;

/* Model floating point type */
typedef float bandpass_filter_FloatType;

/* Model checksum */
extern const char * const bandpass_filter_checksum;

/* Model error status */
extern const char * bandpass_filter_errorStatus;


/* Model sample time */
extern const float bandpass_filter_sampleTime;


/*
 * Model states */
typedef struct
{
   float TransferFcn2[2];           /* bandpass filter/Transfer Fcn2 */
} bandpass_filter_ModelStates;
extern bandpass_filter_ModelStates bandpass_filter_X;


/* External inputs */
typedef struct
{
   float In1;                       /* bandpass filter/In1 */
} bandpass_filter_ExternalInputs;
extern bandpass_filter_ExternalInputs bandpass_filter_U;


/* External outputs */
typedef struct
{
   float Out1;                      /* bandpass filter/Out1 */
} bandpass_filter_ExternalOutputs;
extern bandpass_filter_ExternalOutputs bandpass_filter_Y;


/* Block parameters */
typedef struct
{
   /* Parameter 'Numerator' of
    *  Transfer Function : 'bandpass filter/Transfer Fcn2'
    * Note:
    *  - Partly or entirely unused due to configuration at code generation time
    */
   float TransferFcn2_Numerator[3];
   /* Parameter 'Denominator' of
    *  Transfer Function : 'bandpass filter/Transfer Fcn2'
    */
   float TransferFcn2_Denominator[2];
} bandpass_filter_Parameters;
extern bandpass_filter_Parameters bandpass_filter_P;

/* Entry point functions */
void bandpass_filter_initialize();
void bandpass_filter_step(void);
void bandpass_filter_terminate(void);

#endif /* PLECS_HEADER_bandpass_filter_h_ */
