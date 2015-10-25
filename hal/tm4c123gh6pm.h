/*
 * m4c123gh6pm.h
 *
 *  Created on: Oct 19, 2015
 *      Author: lukas
 */

#ifndef HAL_TM4C123GH6PM_H_
#define HAL_TM4C123GH6PM_H_

#include <stdint.h>

#define HWREG32(x)   (*((volatile uint32_t *)(x)))
#define HWREG16(x)  (*((volatile uint16_t *)(x)))
#define HWREG8(x)  (*((volatile uint8_t *)(x)))

// System Control base address of 0x400F.E000 , page 231
#define SYSCTL_BASE 0x400FE000

//*********************************************************************************
// General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
#define RCGCGPIO_OFFSET 0x608
#define SYSCTL_RCGCGPIO_R       HWREG32(SYSCTL_BASE+RCGCGPIO_OFFSET)

// The following are defines for the bit fields in the SYSCTL_RCGCGPIO register.
#define SYSCTL_RCGCGPIO_PORTF      0x00000020  // GPIO Port F Run Mode Clock
#define SYSCTL_RCGCGPIO_PORTE      0x00000010  // GPIO Port E Run Mode Clock
#define SYSCTL_RCGCGPIO_PORTD      0x00000008  // GPIO Port D Run Mode Clock
#define SYSCTL_RCGCGPIO_PORTC      0x00000004  // GPIO Port C Run Mode Clock
#define SYSCTL_RCGCGPIO_PORTB      0x00000002  // GPIO Port B Run Mode Clock
#define SYSCTL_RCGCGPIO_PORTA      0x00000001  // GPIO Port A Run Mode Clockl


//*********************************************************************************
//Register 9: GPIO High-Performance Bus Control (GPIOHBCTL), offset 0x06C
#define GPIOHBCTL_OFFSET 0x06C
#define SYSCTL_GPIOHBCTL_R      HWREG32(SYSCTL_BASE+GPIOHBCTL_OFFSET)

// The following are defines for the bit fields in the SYSCTL_GPIOHBCTL register.
#define SYSCTL_GPIOHBCTL_PORTF  0x00000020  // Port F Advanced High-Performance Bus
#define SYSCTL_GPIOHBCTL_PORTE  0x00000010  // Port E Advanced High-Performance Bus
#define SYSCTL_GPIOHBCTL_PORTD  0x00000008  // Port D Advanced High-Performance Bus
#define SYSCTL_GPIOHBCTL_PORTC  0x00000004  // Port C Advanced High-Performance Bus
#define SYSCTL_GPIOHBCTL_PORTB  0x00000002  // Port B Advanced High-Performance Bus
#define SYSCTL_GPIOHBCTL_PORTA  0x00000001  // Port A Advanced High-Performance Bus

/*
 * ************************************************GPIO**************************************************
 */


#define GPIO_PORTA_APB 0x40004000
#define GPIO_PORTA_AHB 0x40058000
#define GPIO_PORTB_APB 0x40005000
#define GPIO_PORTB_AHB 0x40059000
#define GPIO_PORTC_APB 0x40006000
#define GPIO_PORTC_AHB 0x4005A000
#define GPIO_PORTD_APB 0x40007000
#define GPIO_PORTD_AHB 0x4005B000
#define GPIO_PORTE_APB 0x40024000
#define GPIO_PORTE_AHB 0x4005C000
#define GPIO_PORTF_APB 0x40025000
#define GPIO_PORTF_AHB 0x4005D000

// The following are defines for the GPIO register offsets.
#define GPIO_DATA             0x000003FC  // GPIO Data, 3FC for mask all on, no mask
#define GPIO_DIR              0x00000400  // GPIO Direction
#define GPIO_IS               0x00000404  // GPIO Interrupt Sense
#define GPIO_IBE              0x00000408  // GPIO Interrupt Both Edges
#define GPIO_IEV              0x0000040C  // GPIO Interrupt Event
#define GPIO_IM               0x00000410  // GPIO Interrupt Mask
#define GPIO_RIS              0x00000414  // GPIO Raw Interrupt Status
#define GPIO_MIS              0x00000418  // GPIO Masked Interrupt Status
#define GPIO_ICR              0x0000041C  // GPIO Interrupt Clear
#define GPIO_AFSEL            0x00000420  // GPIO Alternate Function Select
#define GPIO_DR2R             0x00000500  // GPIO 2-mA Drive Select
#define GPIO_DR4R             0x00000504  // GPIO 4-mA Drive Select
#define GPIO_DR8R             0x00000508  // GPIO 8-mA Drive Select
#define GPIO_ODR              0x0000050C  // GPIO Open Drain Select
#define GPIO_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_PDR              0x00000514  // GPIO Pull-Down Select
#define GPIO_SLR              0x00000518  // GPIO Slew Rate Control Select
#define GPIO_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_LOCK             0x00000520  // GPIO Lock
#define GPIO_CR               0x00000524  // GPIO Commit
#define GPIO_AMSEL            0x00000528  // GPIO Analog Mode Select
#define GPIO_PCTL             0x0000052C  // GPIO Port Control
#define GPIO_ADCCTL           0x00000530  // GPIO ADC Control
#define GPIO_DMACTL           0x00000534  // GPIO DMA Control
#define GPIO_SI               0x00000538  // GPIO Select Interrupt
#define GPIO_DR12R            0x0000053C  // GPIO 12-mA Drive Select
#define GPIO_WAKEPEN          0x00000540  // GPIO Wake Pin Enable
#define GPIO_WAKELVL          0x00000544  // GPIO Wake Level
#define GPIO_WAKESTAT         0x00000548  // GPIO Wake Status
#define GPIO_PP               0x00000FC0  // GPIO Peripheral Property
#define GPIO_PC               0x00000FC4  // GPIO Peripheral Configuration

/*
 * ***********************************GPIO Registers*****************************************
 */

/*
 * **********************************PORTA Registers define Start****************************************
 */

// High BUS
#define GPIO_PORTA_AHB_DATA_BITS_R   HWREG32(GPIO_PORTA_AHB)
#define GPIO_PORTA_AHB_DATA_R  HWREG32(GPIO_PORTA_AHB+GPIO_DATA)
#define GPIO_PORTA_AHB_DIR_R		HWREG32( GPIO_PORTA_AHB+GPIO_DIR )
#define GPIO_PORTA_AHB_IS_R			HWREG32( GPIO_PORTA_AHB+GPIO_IS )
#define GPIO_PORTA_AHB_IBE_R		HWREG32( GPIO_PORTA_AHB+GPIO_IBE )
#define GPIO_PORTA_AHB_IEV_R		HWREG32( GPIO_PORTA_AHB+GPIO_IEV )
#define GPIO_PORTA_AHB_IM_R			HWREG32( GPIO_PORTA_AHB+GPIO_IM )
#define GPIO_PORTA_AHB_RIS_R		HWREG32( GPIO_PORTA_AHB+GPIO_RIS )
#define GPIO_PORTA_AHB_MIS_R		HWREG32( GPIO_PORTA_AHB+GPIO_MIS )
#define GPIO_PORTA_AHB_ICR_R		HWREG32( GPIO_PORTA_AHB+GPIO_ICR  )
#define GPIO_PORTA_AHB_AFSEL_R		HWREG32( GPIO_PORTA_AHB+GPIO_AFSEL )
#define GPIO_PORTA_AHB_DR2R_R		HWREG32( GPIO_PORTA_AHB+GPIO_DR2R )
#define GPIO_PORTA_AHB_DR4R_R		HWREG32( GPIO_PORTA_AHB+GPIO_DR4R )
#define GPIO_PORTA_AHB_DR8R_R		HWREG32( GPIO_PORTA_AHB+GPIO_DR8R )
#define GPIO_PORTA_AHB_ODR_R		HWREG32( GPIO_PORTA_AHB+GPIO_ODR )
#define GPIO_PORTA_AHB_PUR_R		HWREG32( GPIO_PORTA_AHB+GPIO_PUR )
#define GPIO_PORTA_AHB_PDR_R		HWREG32( GPIO_PORTA_AHB+GPIO_PDR )
#define GPIO_PORTA_AHB_SLR_R		HWREG32( GPIO_PORTA_AHB+GPIO_SLR )
#define GPIO_PORTA_AHB_DEN_R		HWREG32( GPIO_PORTA_AHB+GPIO_DEN )
#define GPIO_PORTA_AHB_LOCK_R		HWREG32( GPIO_PORTA_AHB+GPIO_LOCK )
#define GPIO_PORTA_AHB_CR_R			HWREG32( GPIO_PORTA_AHB+GPIO_CR )
#define GPIO_PORTA_AHB_AMSEL_R		HWREG32( GPIO_PORTA_AHB+GPIO_AMSEL )
#define GPIO_PORTA_AHB_PCTL_R		HWREG32( GPIO_PORTA_AHB+GPIO_PCTL )
#define GPIO_PORTA_AHB_ADCCTL_R		HWREG32( GPIO_PORTA_AHB+GPIO_ADCCTL )
#define GPIO_PORTA_AHB_DMACTL_R		HWREG32( GPIO_PORTA_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTA_APB_DATA_BITS_R   HWREG32(GPIO_PORTA_APB)
#define GPIO_PORTA_APB_DATA_R  HWREG32(GPIO_PORTA_APB+GPIO_DATA)
#define GPIO_PORTA_APB_DIR_R	HWREG32( GPIO_PORTA_APB+GPIO_DIR )
#define GPIO_PORTA_APB_IS_R		HWREG32( GPIO_PORTA_APB+GPIO_IS )
#define GPIO_PORTA_APB_IBE_R	HWREG32( GPIO_PORTA_APB+GPIO_IBE )
#define GPIO_PORTA_APB_IEV_R	HWREG32( GPIO_PORTA_APB+GPIO_IEV )
#define GPIO_PORTA_APB_IM_R		HWREG32( GPIO_PORTA_APB+GPIO_IM )
#define GPIO_PORTA_APB_RIS_R	HWREG32( GPIO_PORTA_APB+GPIO_RIS )
#define GPIO_PORTA_APB_MIS_R	HWREG32( GPIO_PORTA_APB+GPIO_MIS )
#define GPIO_PORTA_APB_ICR_R	HWREG32( GPIO_PORTA_APB+GPIO_ICR  )
#define GPIO_PORTA_APB_AFSEL_R	HWREG32( GPIO_PORTA_APB+GPIO_AFSEL )
#define GPIO_PORTA_APB_DR2R_R	HWREG32( GPIO_PORTA_APB+GPIO_DR2R )
#define GPIO_PORTA_APB_DR4R_R	HWREG32( GPIO_PORTA_APB+GPIO_DR4R )
#define GPIO_PORTA_APB_DR8R_R	HWREG32( GPIO_PORTA_APB+GPIO_DR8R )
#define GPIO_PORTA_APB_ODR_R	HWREG32( GPIO_PORTA_APB+GPIO_ODR )
#define GPIO_PORTA_APB_PUR_R	HWREG32( GPIO_PORTA_APB+GPIO_PUR )
#define GPIO_PORTA_APB_PDR_R	HWREG32( GPIO_PORTA_APB+GPIO_PDR )
#define GPIO_PORTA_APB_SLR_R	HWREG32( GPIO_PORTA_APB+GPIO_SLR )
#define GPIO_PORTA_APB_DEN_R	HWREG32( GPIO_PORTA_APB+GPIO_DEN )
#define GPIO_PORTA_APB_LOCK_R	HWREG32( GPIO_PORTA_APB+GPIO_LOCK )
#define GPIO_PORTA_APB_CR_R		HWREG32( GPIO_PORTA_APB+GPIO_CR )
#define GPIO_PORTA_APB_AMSEL_R	HWREG32( GPIO_PORTA_APB+GPIO_AMSEL )
#define GPIO_PORTA_APB_PCTL_R	HWREG32( GPIO_PORTA_APB+GPIO_PCTL )
#define GPIO_PORTA_APB_ADCCTL_R	HWREG32( GPIO_PORTA_APB+GPIO_ADCCTL )
#define GPIO_PORTA_APB_DMACTL_R	HWREG32( GPIO_PORTA_APB+GPIO_DMACTL )

//------------------------------PORTA END---------------------------------------------------

/*
 * **********************************PORTB Registers****************************************
 */

// High BUS
#define GPIO_PORTB_AHB_DATA_BITS_R   HWREG32(GPIO_PORTB_AHB)
#define GPIO_PORTB_AHB_DATA_R  HWREG32(GPIO_PORTB_AHB+GPIO_DATA)
#define GPIO_PORTB_AHB_DIR_R		HWREG32( GPIO_PORTB_AHB+GPIO_DIR )
#define GPIO_PORTB_AHB_IS_R			HWREG32( GPIO_PORTB_AHB+GPIO_IS )
#define GPIO_PORTB_AHB_IBE_R		HWREG32( GPIO_PORTB_AHB+GPIO_IBE )
#define GPIO_PORTB_AHB_IEV_R		HWREG32( GPIO_PORTB_AHB+GPIO_IEV )
#define GPIO_PORTB_AHB_IM_R			HWREG32( GPIO_PORTB_AHB+GPIO_IM )
#define GPIO_PORTB_AHB_RIS_R		HWREG32( GPIO_PORTB_AHB+GPIO_RIS )
#define GPIO_PORTB_AHB_MIS_R		HWREG32( GPIO_PORTB_AHB+GPIO_MIS )
#define GPIO_PORTB_AHB_ICR_R		HWREG32( GPIO_PORTB_AHB+GPIO_ICR  )
#define GPIO_PORTB_AHB_AFSEL_R		HWREG32( GPIO_PORTB_AHB+GPIO_AFSEL )
#define GPIO_PORTB_AHB_DR2R_R		HWREG32( GPIO_PORTB_AHB+GPIO_DR2R )
#define GPIO_PORTB_AHB_DR4R_R		HWREG32( GPIO_PORTB_AHB+GPIO_DR4R )
#define GPIO_PORTB_AHB_DR8R_R		HWREG32( GPIO_PORTB_AHB+GPIO_DR8R )
#define GPIO_PORTB_AHB_ODR_R		HWREG32( GPIO_PORTB_AHB+GPIO_ODR )
#define GPIO_PORTB_AHB_PUR_R		HWREG32( GPIO_PORTB_AHB+GPIO_PUR )
#define GPIO_PORTB_AHB_PDR_R		HWREG32( GPIO_PORTB_AHB+GPIO_PDR )
#define GPIO_PORTB_AHB_SLR_R		HWREG32( GPIO_PORTB_AHB+GPIO_SLR )
#define GPIO_PORTB_AHB_DEN_R		HWREG32( GPIO_PORTB_AHB+GPIO_DEN )
#define GPIO_PORTB_AHB_LOCK_R		HWREG32( GPIO_PORTB_AHB+GPIO_LOCK )
#define GPIO_PORTB_AHB_CR_R			HWREG32( GPIO_PORTB_AHB+GPIO_CR )
#define GPIO_PORTB_AHB_AMSEL_R		HWREG32( GPIO_PORTB_AHB+GPIO_AMSEL )
#define GPIO_PORTB_AHB_PCTL_R		HWREG32( GPIO_PORTB_AHB+GPIO_PCTL )
#define GPIO_PORTB_AHB_ADCCTL_R		HWREG32( GPIO_PORTB_AHB+GPIO_ADCCTL )
#define GPIO_PORTB_AHB_DMACTL_R		HWREG32( GPIO_PORTB_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTB_APB_DATA_BITS_R   HWREG32(GPIO_PORTB_APB)
#define GPIO_PORTB_APB_DATA_R  HWREG32(GPIO_PORTB_APB+GPIO_DATA)
#define GPIO_PORTB_APB_DIR_R	HWREG32( GPIO_PORTB_APB+GPIO_DIR )
#define GPIO_PORTB_APB_IS_R		HWREG32( GPIO_PORTB_APB+GPIO_IS )
#define GPIO_PORTB_APB_IBE_R	HWREG32( GPIO_PORTB_APB+GPIO_IBE )
#define GPIO_PORTB_APB_IEV_R	HWREG32( GPIO_PORTB_APB+GPIO_IEV )
#define GPIO_PORTB_APB_IM_R		HWREG32( GPIO_PORTB_APB+GPIO_IM )
#define GPIO_PORTB_APB_RIS_R	HWREG32( GPIO_PORTB_APB+GPIO_RIS )
#define GPIO_PORTB_APB_MIS_R	HWREG32( GPIO_PORTB_APB+GPIO_MIS )
#define GPIO_PORTB_APB_ICR_R	HWREG32( GPIO_PORTB_APB+GPIO_ICR  )
#define GPIO_PORTB_APB_AFSEL_R	HWREG32( GPIO_PORTB_APB+GPIO_AFSEL )
#define GPIO_PORTB_APB_DR2R_R	HWREG32( GPIO_PORTB_APB+GPIO_DR2R )
#define GPIO_PORTB_APB_DR4R_R	HWREG32( GPIO_PORTB_APB+GPIO_DR4R )
#define GPIO_PORTB_APB_DR8R_R	HWREG32( GPIO_PORTB_APB+GPIO_DR8R )
#define GPIO_PORTB_APB_ODR_R	HWREG32( GPIO_PORTB_APB+GPIO_ODR )
#define GPIO_PORTB_APB_PUR_R	HWREG32( GPIO_PORTB_APB+GPIO_PUR )
#define GPIO_PORTB_APB_PDR_R	HWREG32( GPIO_PORTB_APB+GPIO_PDR )
#define GPIO_PORTB_APB_SLR_R	HWREG32( GPIO_PORTB_APB+GPIO_SLR )
#define GPIO_PORTB_APB_DEN_R	HWREG32( GPIO_PORTB_APB+GPIO_DEN )
#define GPIO_PORTB_APB_LOCK_R	HWREG32( GPIO_PORTB_APB+GPIO_LOCK )
#define GPIO_PORTB_APB_CR_R		HWREG32( GPIO_PORTB_APB+GPIO_CR )
#define GPIO_PORTB_APB_AMSEL_R	HWREG32( GPIO_PORTB_APB+GPIO_AMSEL )
#define GPIO_PORTB_APB_PCTL_R	HWREG32( GPIO_PORTB_APB+GPIO_PCTL )
#define GPIO_PORTB_APB_ADCCTL_R	HWREG32( GPIO_PORTB_APB+GPIO_ADCCTL )
#define GPIO_PORTB_APB_DMACTL_R	HWREG32( GPIO_PORTB_APB+GPIO_DMACTL )

//------------------------------PORTB END---------------------------------------------------

/*
 * **********************************PORTC Registers define Start****************************************
 */

// High BUS
#define GPIO_PORTC_AHB_DATA_BITS_R   HWREG32(GPIO_PORTC_AHB)
#define GPIO_PORTC_AHB_DATA_R  HWREG32(GPIO_PORTC_AHB+GPIO_DATA)
#define GPIO_PORTC_AHB_DIR_R		HWREG32( GPIO_PORTC_AHB+GPIO_DIR )
#define GPIO_PORTC_AHB_IS_R			HWREG32( GPIO_PORTC_AHB+GPIO_IS )
#define GPIO_PORTC_AHB_IBE_R		HWREG32( GPIO_PORTC_AHB+GPIO_IBE )
#define GPIO_PORTC_AHB_IEV_R		HWREG32( GPIO_PORTC_AHB+GPIO_IEV )
#define GPIO_PORTC_AHB_IM_R			HWREG32( GPIO_PORTC_AHB+GPIO_IM )
#define GPIO_PORTC_AHB_RIS_R		HWREG32( GPIO_PORTC_AHB+GPIO_RIS )
#define GPIO_PORTC_AHB_MIS_R		HWREG32( GPIO_PORTC_AHB+GPIO_MIS )
#define GPIO_PORTC_AHB_ICR_R		HWREG32( GPIO_PORTC_AHB+GPIO_ICR  )
#define GPIO_PORTC_AHB_AFSEL_R		HWREG32( GPIO_PORTC_AHB+GPIO_AFSEL )
#define GPIO_PORTC_AHB_DR2R_R		HWREG32( GPIO_PORTC_AHB+GPIO_DR2R )
#define GPIO_PORTC_AHB_DR4R_R		HWREG32( GPIO_PORTC_AHB+GPIO_DR4R )
#define GPIO_PORTC_AHB_DR8R_R		HWREG32( GPIO_PORTC_AHB+GPIO_DR8R )
#define GPIO_PORTC_AHB_ODR_R		HWREG32( GPIO_PORTC_AHB+GPIO_ODR )
#define GPIO_PORTC_AHB_PUR_R		HWREG32( GPIO_PORTC_AHB+GPIO_PUR )
#define GPIO_PORTC_AHB_PDR_R		HWREG32( GPIO_PORTC_AHB+GPIO_PDR )
#define GPIO_PORTC_AHB_SLR_R		HWREG32( GPIO_PORTC_AHB+GPIO_SLR )
#define GPIO_PORTC_AHB_DEN_R		HWREG32( GPIO_PORTC_AHB+GPIO_DEN )
#define GPIO_PORTC_AHB_LOCK_R		HWREG32( GPIO_PORTC_AHB+GPIO_LOCK )
#define GPIO_PORTC_AHB_CR_R			HWREG32( GPIO_PORTC_AHB+GPIO_CR )
#define GPIO_PORTC_AHB_AMSEL_R		HWREG32( GPIO_PORTC_AHB+GPIO_AMSEL )
#define GPIO_PORTC_AHB_PCTL_R		HWREG32( GPIO_PORTC_AHB+GPIO_PCTL )
#define GPIO_PORTC_AHB_ADCCTL_R		HWREG32( GPIO_PORTC_AHB+GPIO_ADCCTL )
#define GPIO_PORTC_AHB_DMACTL_R		HWREG32( GPIO_PORTC_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTC_APB_DATA_BITS_R   HWREG32(GPIO_PORTC_APB)
#define GPIO_PORTC_APB_DATA_R  HWREG32(GPIO_PORTC_APB+GPIO_DATA)
#define GPIO_PORTC_APB_DIR_R	HWREG32( GPIO_PORTC_APB+GPIO_DIR )
#define GPIO_PORTC_APB_IS_R		HWREG32( GPIO_PORTC_APB+GPIO_IS )
#define GPIO_PORTC_APB_IBE_R	HWREG32( GPIO_PORTC_APB+GPIO_IBE )
#define GPIO_PORTC_APB_IEV_R	HWREG32( GPIO_PORTC_APB+GPIO_IEV )
#define GPIO_PORTC_APB_IM_R		HWREG32( GPIO_PORTC_APB+GPIO_IM )
#define GPIO_PORTC_APB_RIS_R	HWREG32( GPIO_PORTC_APB+GPIO_RIS )
#define GPIO_PORTC_APB_MIS_R	HWREG32( GPIO_PORTC_APB+GPIO_MIS )
#define GPIO_PORTC_APB_ICR_R	HWREG32( GPIO_PORTC_APB+GPIO_ICR  )
#define GPIO_PORTC_APB_AFSEL_R	HWREG32( GPIO_PORTC_APB+GPIO_AFSEL )
#define GPIO_PORTC_APB_DR2R_R	HWREG32( GPIO_PORTC_APB+GPIO_DR2R )
#define GPIO_PORTC_APB_DR4R_R	HWREG32( GPIO_PORTC_APB+GPIO_DR4R )
#define GPIO_PORTC_APB_DR8R_R	HWREG32( GPIO_PORTC_APB+GPIO_DR8R )
#define GPIO_PORTC_APB_ODR_R	HWREG32( GPIO_PORTC_APB+GPIO_ODR )
#define GPIO_PORTC_APB_PUR_R	HWREG32( GPIO_PORTC_APB+GPIO_PUR )
#define GPIO_PORTC_APB_PDR_R	HWREG32( GPIO_PORTC_APB+GPIO_PDR )
#define GPIO_PORTC_APB_SLR_R	HWREG32( GPIO_PORTC_APB+GPIO_SLR )
#define GPIO_PORTC_APB_DEN_R	HWREG32( GPIO_PORTC_APB+GPIO_DEN )
#define GPIO_PORTC_APB_LOCK_R	HWREG32( GPIO_PORTC_APB+GPIO_LOCK )
#define GPIO_PORTC_APB_CR_R		HWREG32( GPIO_PORTC_APB+GPIO_CR )
#define GPIO_PORTC_APB_AMSEL_R	HWREG32( GPIO_PORTC_APB+GPIO_AMSEL )
#define GPIO_PORTC_APB_PCTL_R	HWREG32( GPIO_PORTC_APB+GPIO_PCTL )
#define GPIO_PORTC_APB_ADCCTL_R	HWREG32( GPIO_PORTC_APB+GPIO_ADCCTL )
#define GPIO_PORTC_APB_DMACTL_R	HWREG32( GPIO_PORTC_APB+GPIO_DMACTL )

//------------------------------PORTC END---------------------------------------------------

/*
 * **********************************PORTD Registers define Start****************************************
 */

// High BUS
#define GPIO_PORTD_AHB_DATA_BITS_R   HWREG32(GPIO_PORTD_AHB)
#define GPIO_PORTD_AHB_DATA_R  HWREG32(GPIO_PORTD_AHB+GPIO_DATA)
#define GPIO_PORTD_AHB_DIR_R		HWREG32( GPIO_PORTD_AHB+GPIO_DIR )
#define GPIO_PORTD_AHB_IS_R			HWREG32( GPIO_PORTD_AHB+GPIO_IS )
#define GPIO_PORTD_AHB_IBE_R		HWREG32( GPIO_PORTD_AHB+GPIO_IBE )
#define GPIO_PORTD_AHB_IEV_R		HWREG32( GPIO_PORTD_AHB+GPIO_IEV )
#define GPIO_PORTD_AHB_IM_R			HWREG32( GPIO_PORTD_AHB+GPIO_IM )
#define GPIO_PORTD_AHB_RIS_R		HWREG32( GPIO_PORTD_AHB+GPIO_RIS )
#define GPIO_PORTD_AHB_MIS_R		HWREG32( GPIO_PORTD_AHB+GPIO_MIS )
#define GPIO_PORTD_AHB_ICR_R		HWREG32( GPIO_PORTD_AHB+GPIO_ICR  )
#define GPIO_PORTD_AHB_AFSEL_R		HWREG32( GPIO_PORTD_AHB+GPIO_AFSEL )
#define GPIO_PORTD_AHB_DR2R_R		HWREG32( GPIO_PORTD_AHB+GPIO_DR2R )
#define GPIO_PORTD_AHB_DR4R_R		HWREG32( GPIO_PORTD_AHB+GPIO_DR4R )
#define GPIO_PORTD_AHB_DR8R_R		HWREG32( GPIO_PORTD_AHB+GPIO_DR8R )
#define GPIO_PORTD_AHB_ODR_R		HWREG32( GPIO_PORTD_AHB+GPIO_ODR )
#define GPIO_PORTD_AHB_PUR_R		HWREG32( GPIO_PORTD_AHB+GPIO_PUR )
#define GPIO_PORTD_AHB_PDR_R		HWREG32( GPIO_PORTD_AHB+GPIO_PDR )
#define GPIO_PORTD_AHB_SLR_R		HWREG32( GPIO_PORTD_AHB+GPIO_SLR )
#define GPIO_PORTD_AHB_DEN_R		HWREG32( GPIO_PORTD_AHB+GPIO_DEN )
#define GPIO_PORTD_AHB_LOCK_R		HWREG32( GPIO_PORTD_AHB+GPIO_LOCK )
#define GPIO_PORTD_AHB_CR_R			HWREG32( GPIO_PORTD_AHB+GPIO_CR )
#define GPIO_PORTD_AHB_AMSEL_R		HWREG32( GPIO_PORTD_AHB+GPIO_AMSEL )
#define GPIO_PORTD_AHB_PCTL_R		HWREG32( GPIO_PORTD_AHB+GPIO_PCTL )
#define GPIO_PORTD_AHB_ADCCTL_R		HWREG32( GPIO_PORTD_AHB+GPIO_ADCCTL )
#define GPIO_PORTD_AHB_DMACTL_R		HWREG32( GPIO_PORTD_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTD_APB_DATA_BITS_R   HWREG32(GPIO_PORTD_APB)
#define GPIO_PORTD_APB_DATA_R  HWREG32(GPIO_PORTD_APB+GPIO_DATA)
#define GPIO_PORTD_APB_DIR_R	HWREG32( GPIO_PORTD_APB+GPIO_DIR )
#define GPIO_PORTD_APB_IS_R		HWREG32( GPIO_PORTD_APB+GPIO_IS )
#define GPIO_PORTD_APB_IBE_R	HWREG32( GPIO_PORTD_APB+GPIO_IBE )
#define GPIO_PORTD_APB_IEV_R	HWREG32( GPIO_PORTD_APB+GPIO_IEV )
#define GPIO_PORTD_APB_IM_R		HWREG32( GPIO_PORTD_APB+GPIO_IM )
#define GPIO_PORTD_APB_RIS_R	HWREG32( GPIO_PORTD_APB+GPIO_RIS )
#define GPIO_PORTD_APB_MIS_R	HWREG32( GPIO_PORTD_APB+GPIO_MIS )
#define GPIO_PORTD_APB_ICR_R	HWREG32( GPIO_PORTD_APB+GPIO_ICR  )
#define GPIO_PORTD_APB_AFSEL_R	HWREG32( GPIO_PORTD_APB+GPIO_AFSEL )
#define GPIO_PORTD_APB_DR2R_R	HWREG32( GPIO_PORTD_APB+GPIO_DR2R )
#define GPIO_PORTD_APB_DR4R_R	HWREG32( GPIO_PORTD_APB+GPIO_DR4R )
#define GPIO_PORTD_APB_DR8R_R	HWREG32( GPIO_PORTD_APB+GPIO_DR8R )
#define GPIO_PORTD_APB_ODR_R	HWREG32( GPIO_PORTD_APB+GPIO_ODR )
#define GPIO_PORTD_APB_PUR_R	HWREG32( GPIO_PORTD_APB+GPIO_PUR )
#define GPIO_PORTD_APB_PDR_R	HWREG32( GPIO_PORTD_APB+GPIO_PDR )
#define GPIO_PORTD_APB_SLR_R	HWREG32( GPIO_PORTD_APB+GPIO_SLR )
#define GPIO_PORTD_APB_DEN_R	HWREG32( GPIO_PORTD_APB+GPIO_DEN )
#define GPIO_PORTD_APB_LOCK_R	HWREG32( GPIO_PORTD_APB+GPIO_LOCK )
#define GPIO_PORTD_APB_CR_R		HWREG32( GPIO_PORTD_APB+GPIO_CR )
#define GPIO_PORTD_APB_AMSEL_R	HWREG32( GPIO_PORTD_APB+GPIO_AMSEL )
#define GPIO_PORTD_APB_PCTL_R	HWREG32( GPIO_PORTD_APB+GPIO_PCTL )
#define GPIO_PORTD_APB_ADCCTL_R	HWREG32( GPIO_PORTD_APB+GPIO_ADCCTL )
#define GPIO_PORTD_APB_DMACTL_R	HWREG32( GPIO_PORTD_APB+GPIO_DMACTL )

//------------------------------PORTD END---------------------------------------------------

/*
 * **********************************PORTE Registers define Start****************************************
 */

// High BUS
#define GPIO_PORTE_AHB_DATA_BITS_R   HWREG32(GPIO_PORTE_AHB)
#define GPIO_PORTE_AHB_DATA_R  HWREG32(GPIO_PORTE_AHB+GPIO_DATA)
#define GPIO_PORTE_AHB_DIR_R		HWREG32( GPIO_PORTE_AHB+GPIO_DIR )
#define GPIO_PORTE_AHB_IS_R			HWREG32( GPIO_PORTE_AHB+GPIO_IS )
#define GPIO_PORTE_AHB_IBE_R		HWREG32( GPIO_PORTE_AHB+GPIO_IBE )
#define GPIO_PORTE_AHB_IEV_R		HWREG32( GPIO_PORTE_AHB+GPIO_IEV )
#define GPIO_PORTE_AHB_IM_R			HWREG32( GPIO_PORTE_AHB+GPIO_IM )
#define GPIO_PORTE_AHB_RIS_R		HWREG32( GPIO_PORTE_AHB+GPIO_RIS )
#define GPIO_PORTE_AHB_MIS_R		HWREG32( GPIO_PORTE_AHB+GPIO_MIS )
#define GPIO_PORTE_AHB_ICR_R		HWREG32( GPIO_PORTE_AHB+GPIO_ICR  )
#define GPIO_PORTE_AHB_AFSEL_R		HWREG32( GPIO_PORTE_AHB+GPIO_AFSEL )
#define GPIO_PORTE_AHB_DR2R_R		HWREG32( GPIO_PORTE_AHB+GPIO_DR2R )
#define GPIO_PORTE_AHB_DR4R_R		HWREG32( GPIO_PORTE_AHB+GPIO_DR4R )
#define GPIO_PORTE_AHB_DR8R_R		HWREG32( GPIO_PORTE_AHB+GPIO_DR8R )
#define GPIO_PORTE_AHB_ODR_R		HWREG32( GPIO_PORTE_AHB+GPIO_ODR )
#define GPIO_PORTE_AHB_PUR_R		HWREG32( GPIO_PORTE_AHB+GPIO_PUR )
#define GPIO_PORTE_AHB_PDR_R		HWREG32( GPIO_PORTE_AHB+GPIO_PDR )
#define GPIO_PORTE_AHB_SLR_R		HWREG32( GPIO_PORTE_AHB+GPIO_SLR )
#define GPIO_PORTE_AHB_DEN_R		HWREG32( GPIO_PORTE_AHB+GPIO_DEN )
#define GPIO_PORTE_AHB_LOCK_R		HWREG32( GPIO_PORTE_AHB+GPIO_LOCK )
#define GPIO_PORTE_AHB_CR_R			HWREG32( GPIO_PORTE_AHB+GPIO_CR )
#define GPIO_PORTE_AHB_AMSEL_R		HWREG32( GPIO_PORTE_AHB+GPIO_AMSEL )
#define GPIO_PORTE_AHB_PCTL_R		HWREG32( GPIO_PORTE_AHB+GPIO_PCTL )
#define GPIO_PORTE_AHB_ADCCTL_R		HWREG32( GPIO_PORTE_AHB+GPIO_ADCCTL )
#define GPIO_PORTE_AHB_DMACTL_R		HWREG32( GPIO_PORTE_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTE_APB_DATA_BITS_R   HWREG32(GPIO_PORTE_APB)
#define GPIO_PORTE_APB_DATA_R  HWREG32(GPIO_PORTE_APB+GPIO_DATA)
#define GPIO_PORTE_APB_DIR_R	HWREG32( GPIO_PORTE_APB+GPIO_DIR )
#define GPIO_PORTE_APB_IS_R		HWREG32( GPIO_PORTE_APB+GPIO_IS )
#define GPIO_PORTE_APB_IBE_R	HWREG32( GPIO_PORTE_APB+GPIO_IBE )
#define GPIO_PORTE_APB_IEV_R	HWREG32( GPIO_PORTE_APB+GPIO_IEV )
#define GPIO_PORTE_APB_IM_R		HWREG32( GPIO_PORTE_APB+GPIO_IM )
#define GPIO_PORTE_APB_RIS_R	HWREG32( GPIO_PORTE_APB+GPIO_RIS )
#define GPIO_PORTE_APB_MIS_R	HWREG32( GPIO_PORTE_APB+GPIO_MIS )
#define GPIO_PORTE_APB_ICR_R	HWREG32( GPIO_PORTE_APB+GPIO_ICR  )
#define GPIO_PORTE_APB_AFSEL_R	HWREG32( GPIO_PORTE_APB+GPIO_AFSEL )
#define GPIO_PORTE_APB_DR2R_R	HWREG32( GPIO_PORTE_APB+GPIO_DR2R )
#define GPIO_PORTE_APB_DR4R_R	HWREG32( GPIO_PORTE_APB+GPIO_DR4R )
#define GPIO_PORTE_APB_DR8R_R	HWREG32( GPIO_PORTE_APB+GPIO_DR8R )
#define GPIO_PORTE_APB_ODR_R	HWREG32( GPIO_PORTE_APB+GPIO_ODR )
#define GPIO_PORTE_APB_PUR_R	HWREG32( GPIO_PORTE_APB+GPIO_PUR )
#define GPIO_PORTE_APB_PDR_R	HWREG32( GPIO_PORTE_APB+GPIO_PDR )
#define GPIO_PORTE_APB_SLR_R	HWREG32( GPIO_PORTE_APB+GPIO_SLR )
#define GPIO_PORTE_APB_DEN_R	HWREG32( GPIO_PORTE_APB+GPIO_DEN )
#define GPIO_PORTE_APB_LOCK_R	HWREG32( GPIO_PORTE_APB+GPIO_LOCK )
#define GPIO_PORTE_APB_CR_R		HWREG32( GPIO_PORTE_APB+GPIO_CR )
#define GPIO_PORTE_APB_AMSEL_R	HWREG32( GPIO_PORTE_APB+GPIO_AMSEL )
#define GPIO_PORTE_APB_PCTL_R	HWREG32( GPIO_PORTE_APB+GPIO_PCTL )
#define GPIO_PORTE_APB_ADCCTL_R	HWREG32( GPIO_PORTE_APB+GPIO_ADCCTL )
#define GPIO_PORTE_APB_DMACTL_R	HWREG32( GPIO_PORTE_APB+GPIO_DMACTL )

//------------------------------PORTE END---------------------------------------------------

/*
 * **********************************PORTF Registers define Start****************************************
 */

// High BUS
#define GPIO_PORTF_AHB_DATA_BITS_R   HWREG32(GPIO_PORTF_AHB)
#define GPIO_PORTF_AHB_DATA_R  HWREG32(GPIO_PORTF_AHB+GPIO_DATA)
#define GPIO_PORTF_AHB_DIR_R		HWREG32( GPIO_PORTF_AHB+GPIO_DIR )
#define GPIO_PORTF_AHB_IS_R			HWREG32( GPIO_PORTF_AHB+GPIO_IS )
#define GPIO_PORTF_AHB_IBE_R		HWREG32( GPIO_PORTF_AHB+GPIO_IBE )
#define GPIO_PORTF_AHB_IEV_R		HWREG32( GPIO_PORTF_AHB+GPIO_IEV )
#define GPIO_PORTF_AHB_IM_R			HWREG32( GPIO_PORTF_AHB+GPIO_IM )
#define GPIO_PORTF_AHB_RIS_R		HWREG32( GPIO_PORTF_AHB+GPIO_RIS )
#define GPIO_PORTF_AHB_MIS_R		HWREG32( GPIO_PORTF_AHB+GPIO_MIS )
#define GPIO_PORTF_AHB_ICR_R		HWREG32( GPIO_PORTF_AHB+GPIO_ICR  )
#define GPIO_PORTF_AHB_AFSEL_R		HWREG32( GPIO_PORTF_AHB+GPIO_AFSEL )
#define GPIO_PORTF_AHB_DR2R_R		HWREG32( GPIO_PORTF_AHB+GPIO_DR2R )
#define GPIO_PORTF_AHB_DR4R_R		HWREG32( GPIO_PORTF_AHB+GPIO_DR4R )
#define GPIO_PORTF_AHB_DR8R_R		HWREG32( GPIO_PORTF_AHB+GPIO_DR8R )
#define GPIO_PORTF_AHB_ODR_R		HWREG32( GPIO_PORTF_AHB+GPIO_ODR )
#define GPIO_PORTF_AHB_PUR_R		HWREG32( GPIO_PORTF_AHB+GPIO_PUR )
#define GPIO_PORTF_AHB_PDR_R		HWREG32( GPIO_PORTF_AHB+GPIO_PDR )
#define GPIO_PORTF_AHB_SLR_R		HWREG32( GPIO_PORTF_AHB+GPIO_SLR )
#define GPIO_PORTF_AHB_DEN_R		HWREG32( GPIO_PORTF_AHB+GPIO_DEN )
#define GPIO_PORTF_AHB_LOCK_R		HWREG32( GPIO_PORTF_AHB+GPIO_LOCK )
#define GPIO_PORTF_AHB_CR_R			HWREG32( GPIO_PORTF_AHB+GPIO_CR )
#define GPIO_PORTF_AHB_AMSEL_R		HWREG32( GPIO_PORTF_AHB+GPIO_AMSEL )
#define GPIO_PORTF_AHB_PCTL_R		HWREG32( GPIO_PORTF_AHB+GPIO_PCTL )
#define GPIO_PORTF_AHB_ADCCTL_R		HWREG32( GPIO_PORTF_AHB+GPIO_ADCCTL )
#define GPIO_PORTF_AHB_DMACTL_R		HWREG32( GPIO_PORTF_AHB+GPIO_DMACTL )


// Peripherie BUS
#define GPIO_PORTF_APB_DATA_BITS_R   HWREG32(GPIO_PORTF_APB)
#define GPIO_PORTF_APB_DATA_R  HWREG32(GPIO_PORTF_APB+GPIO_DATA)
#define GPIO_PORTF_APB_DIR_R	HWREG32( GPIO_PORTF_APB+GPIO_DIR )
#define GPIO_PORTF_APB_IS_R		HWREG32( GPIO_PORTF_APB+GPIO_IS )
#define GPIO_PORTF_APB_IBE_R	HWREG32( GPIO_PORTF_APB+GPIO_IBE )
#define GPIO_PORTF_APB_IEV_R	HWREG32( GPIO_PORTF_APB+GPIO_IEV )
#define GPIO_PORTF_APB_IM_R		HWREG32( GPIO_PORTF_APB+GPIO_IM )
#define GPIO_PORTF_APB_RIS_R	HWREG32( GPIO_PORTF_APB+GPIO_RIS )
#define GPIO_PORTF_APB_MIS_R	HWREG32( GPIO_PORTF_APB+GPIO_MIS )
#define GPIO_PORTF_APB_ICR_R	HWREG32( GPIO_PORTF_APB+GPIO_ICR  )
#define GPIO_PORTF_APB_AFSEL_R	HWREG32( GPIO_PORTF_APB+GPIO_AFSEL )
#define GPIO_PORTF_APB_DR2R_R	HWREG32( GPIO_PORTF_APB+GPIO_DR2R )
#define GPIO_PORTF_APB_DR4R_R	HWREG32( GPIO_PORTF_APB+GPIO_DR4R )
#define GPIO_PORTF_APB_DR8R_R	HWREG32( GPIO_PORTF_APB+GPIO_DR8R )
#define GPIO_PORTF_APB_ODR_R	HWREG32( GPIO_PORTF_APB+GPIO_ODR )
#define GPIO_PORTF_APB_PUR_R	HWREG32( GPIO_PORTF_APB+GPIO_PUR )
#define GPIO_PORTF_APB_PDR_R	HWREG32( GPIO_PORTF_APB+GPIO_PDR )
#define GPIO_PORTF_APB_SLR_R	HWREG32( GPIO_PORTF_APB+GPIO_SLR )
#define GPIO_PORTF_APB_DEN_R	HWREG32( GPIO_PORTF_APB+GPIO_DEN )
#define GPIO_PORTF_APB_LOCK_R	HWREG32( GPIO_PORTF_APB+GPIO_LOCK )
#define GPIO_PORTF_APB_CR_R		HWREG32( GPIO_PORTF_APB+GPIO_CR )
#define GPIO_PORTF_APB_AMSEL_R	HWREG32( GPIO_PORTF_APB+GPIO_AMSEL )
#define GPIO_PORTF_APB_PCTL_R	HWREG32( GPIO_PORTF_APB+GPIO_PCTL )
#define GPIO_PORTF_APB_ADCCTL_R	HWREG32( GPIO_PORTF_APB+GPIO_ADCCTL )
#define GPIO_PORTF_APB_DMACTL_R	HWREG32( GPIO_PORTF_APB+GPIO_DMACTL )

//------------------------------PORTF END---------------------------------------------------


// The following values define the bit field for the ui8Pins argument to several of the APIs.
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
#define GPIO_PIN_7              0x00000080  // GPIO pin 7

//-----------------------------GPIO Register defination ENDS-------------------------------------



#endif /* HAL_TM4C123GH6PM_H_ */