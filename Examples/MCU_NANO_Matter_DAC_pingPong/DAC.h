#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_iadc.h"
#include "em_ldma.h"
#include "em_gpio.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

// How many samples to capture
#define NUM_SAMPLES         1024

/*
 * Specify the IADC input using the IADC_PosInput_t typedef.  This
 * must be paired with a corresponding macro definition that allocates
 * the corresponding ABUS to the IADC.  These are...
 *
 * GPIO->ABUSALLOC |= GPIO_ABUSALLOC_AEVEN0_ADC0
 * GPIO->ABUSALLOC |= GPIO_ABUSALLOC_AODD0_ADC0
 * GPIO->BBUSALLOC |= GPIO_BBUSALLOC_BEVEN0_ADC0
 * GPIO->BBUSALLOC |= GPIO_BBUSALLOC_BODD0_ADC0
 * GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDEVEN0_ADC0
 * GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDODD0_ADC0
 *
 * ...for port A, port B, and port C/D pins, even and odd, respectively.
 */
#define IADC_INPUT_0_PORT_PIN     iadcPosInputPortBPin0;
#define IADC_INPUT_1_PORT_PIN     iadcPosInputPortBPin1;

#define IADC_INPUT_0_BUS          BBUSALLOC
#define IADC_INPUT_0_BUSALLOC     GPIO_BBUSALLOC_BEVEN0_ADC0
#define IADC_INPUT_1_BUS          BBUSALLOC
#define IADC_INPUT_1_BUSALLOC     GPIO_BBUSALLOC_BODD0_ADC0


// Set CLK_ADC to 10 MHz
#define CLK_SRC_ADC_FREQ    20000000  // CLK_SRC_ADC
#define CLK_ADC_FREQ        10000000  // CLK_ADC - 10 MHz max in normal mode


// Use specified LDMA channel
#define IADC_LDMA_CH              0

// GPIO output toggle to notify LDMA transfer complete
#define GPIO_OUTPUT_0_PORT        gpioPortC
#define GPIO_OUTPUT_0_PIN         5

/**************************************************************************//**
 * @brief  LDMA Handler
 *****************************************************************************/
void LDMA_IRQHandler1(void);


/**************************************************************************//**
 * @brief  IADC initialization
 *****************************************************************************/
void initIADC(void);

