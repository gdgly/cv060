//*****************************************************************************
//
// lm3s9790.h - LM3S9790 Register Definitions
//
// Copyright (c) 2009-2010 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 5961 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __LM3S9790_H__
#define __LM3S9790_H__

//*****************************************************************************
//
// Watchdog Timer registers (WATCHDOG0)
//
//*****************************************************************************
#define WATCHDOG0_LOAD_R        (*((volatile unsigned long *)0x40000000))
#define WATCHDOG0_VALUE_R       (*((volatile unsigned long *)0x40000004))
#define WATCHDOG0_CTL_R         (*((volatile unsigned long *)0x40000008))
#define WATCHDOG0_ICR_R         (*((volatile unsigned long *)0x4000000C))
#define WATCHDOG0_RIS_R         (*((volatile unsigned long *)0x40000010))
#define WATCHDOG0_MIS_R         (*((volatile unsigned long *)0x40000014))
#define WATCHDOG0_TEST_R        (*((volatile unsigned long *)0x40000418))
#define WATCHDOG0_LOCK_R        (*((volatile unsigned long *)0x40000C00))

//*****************************************************************************
//
// Watchdog Timer registers (WATCHDOG1)
//
//*****************************************************************************
#define WATCHDOG1_LOAD_R        (*((volatile unsigned long *)0x40001000))
#define WATCHDOG1_VALUE_R       (*((volatile unsigned long *)0x40001004))
#define WATCHDOG1_CTL_R         (*((volatile unsigned long *)0x40001008))
#define WATCHDOG1_ICR_R         (*((volatile unsigned long *)0x4000100C))
#define WATCHDOG1_RIS_R         (*((volatile unsigned long *)0x40001010))
#define WATCHDOG1_MIS_R         (*((volatile unsigned long *)0x40001014))
#define WATCHDOG1_TEST_R        (*((volatile unsigned long *)0x40001418))
#define WATCHDOG1_LOCK_R        (*((volatile unsigned long *)0x40001C00))

//*****************************************************************************
//
// GPIO registers (PORTA)
//
//*****************************************************************************
#define GPIO_PORTA_DATA_BITS_R  ((volatile unsigned long *)0x40004000)
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_IS_R         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_R        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_R        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_R         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_R        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_MIS_R        (*((volatile unsigned long *)0x40004418))
#define GPIO_PORTA_ICR_R        (*((volatile unsigned long *)0x4000441C))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DR2R_R       (*((volatile unsigned long *)0x40004500))
#define GPIO_PORTA_DR4R_R       (*((volatile unsigned long *)0x40004504))
#define GPIO_PORTA_DR8R_R       (*((volatile unsigned long *)0x40004508))
#define GPIO_PORTA_ODR_R        (*((volatile unsigned long *)0x4000450C))
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_R        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_SLR_R        (*((volatile unsigned long *)0x40004518))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))

//*****************************************************************************
//
// GPIO registers (PORTB)
//
//*****************************************************************************
#define GPIO_PORTB_DATA_BITS_R  ((volatile unsigned long *)0x40005000)
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_IS_R         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_R        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_R        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_R         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_R        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_MIS_R        (*((volatile unsigned long *)0x40005418))
#define GPIO_PORTB_ICR_R        (*((volatile unsigned long *)0x4000541C))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_DR2R_R       (*((volatile unsigned long *)0x40005500))
#define GPIO_PORTB_DR4R_R       (*((volatile unsigned long *)0x40005504))
#define GPIO_PORTB_DR8R_R       (*((volatile unsigned long *)0x40005508))
#define GPIO_PORTB_ODR_R        (*((volatile unsigned long *)0x4000550C))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_R        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_SLR_R        (*((volatile unsigned long *)0x40005518))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

//*****************************************************************************
//
// GPIO registers (PORTC)
//
//*****************************************************************************
#define GPIO_PORTC_DATA_BITS_R  ((volatile unsigned long *)0x40006000)
#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_IS_R         (*((volatile unsigned long *)0x40006404))
#define GPIO_PORTC_IBE_R        (*((volatile unsigned long *)0x40006408))
#define GPIO_PORTC_IEV_R        (*((volatile unsigned long *)0x4000640C))
#define GPIO_PORTC_IM_R         (*((volatile unsigned long *)0x40006410))
#define GPIO_PORTC_RIS_R        (*((volatile unsigned long *)0x40006414))
#define GPIO_PORTC_MIS_R        (*((volatile unsigned long *)0x40006418))
#define GPIO_PORTC_ICR_R        (*((volatile unsigned long *)0x4000641C))
#define GPIO_PORTC_AFSEL_R      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_DR2R_R       (*((volatile unsigned long *)0x40006500))
#define GPIO_PORTC_DR4R_R       (*((volatile unsigned long *)0x40006504))
#define GPIO_PORTC_DR8R_R       (*((volatile unsigned long *)0x40006508))
#define GPIO_PORTC_ODR_R        (*((volatile unsigned long *)0x4000650C))
#define GPIO_PORTC_PUR_R        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_R        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_SLR_R        (*((volatile unsigned long *)0x40006518))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_R       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_R      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile unsigned long *)0x4000652C))

//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************
#define GPIO_PORTD_DATA_BITS_R  ((volatile unsigned long *)0x40007000)
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_IS_R         (*((volatile unsigned long *)0x40007404))
#define GPIO_PORTD_IBE_R        (*((volatile unsigned long *)0x40007408))
#define GPIO_PORTD_IEV_R        (*((volatile unsigned long *)0x4000740C))
#define GPIO_PORTD_IM_R         (*((volatile unsigned long *)0x40007410))
#define GPIO_PORTD_RIS_R        (*((volatile unsigned long *)0x40007414))
#define GPIO_PORTD_MIS_R        (*((volatile unsigned long *)0x40007418))
#define GPIO_PORTD_ICR_R        (*((volatile unsigned long *)0x4000741C))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_DR2R_R       (*((volatile unsigned long *)0x40007500))
#define GPIO_PORTD_DR4R_R       (*((volatile unsigned long *)0x40007504))
#define GPIO_PORTD_DR8R_R       (*((volatile unsigned long *)0x40007508))
#define GPIO_PORTD_ODR_R        (*((volatile unsigned long *)0x4000750C))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_SLR_R        (*((volatile unsigned long *)0x40007518))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))

//*****************************************************************************
//
// SSI registers (SSI0)
//
//*****************************************************************************
#define SSI0_CR0_R              (*((volatile unsigned long *)0x40008000))
#define SSI0_CR1_R              (*((volatile unsigned long *)0x40008004))
#define SSI0_DR_R               (*((volatile unsigned long *)0x40008008))
#define SSI0_SR_R               (*((volatile unsigned long *)0x4000800C))
#define SSI0_CPSR_R             (*((volatile unsigned long *)0x40008010))
#define SSI0_IM_R               (*((volatile unsigned long *)0x40008014))
#define SSI0_RIS_R              (*((volatile unsigned long *)0x40008018))
#define SSI0_MIS_R              (*((volatile unsigned long *)0x4000801C))
#define SSI0_ICR_R              (*((volatile unsigned long *)0x40008020))
#define SSI0_DMACTL_R           (*((volatile unsigned long *)0x40008024))

//*****************************************************************************
//
// SSI registers (SSI1)
//
//*****************************************************************************
#define SSI1_CR0_R              (*((volatile unsigned long *)0x40009000))
#define SSI1_CR1_R              (*((volatile unsigned long *)0x40009004))
#define SSI1_DR_R               (*((volatile unsigned long *)0x40009008))
#define SSI1_SR_R               (*((volatile unsigned long *)0x4000900C))
#define SSI1_CPSR_R             (*((volatile unsigned long *)0x40009010))
#define SSI1_IM_R               (*((volatile unsigned long *)0x40009014))
#define SSI1_RIS_R              (*((volatile unsigned long *)0x40009018))
#define SSI1_MIS_R              (*((volatile unsigned long *)0x4000901C))
#define SSI1_ICR_R              (*((volatile unsigned long *)0x40009020))
#define SSI1_DMACTL_R           (*((volatile unsigned long *)0x40009024))

//*****************************************************************************
//
// UART registers (UART0)
//
//*****************************************************************************
#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_RSR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_ECR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_ILPR_R            (*((volatile unsigned long *)0x4000C020))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART0_IFLS_R            (*((volatile unsigned long *)0x4000C034))
#define UART0_IM_R              (*((volatile unsigned long *)0x4000C038))
#define UART0_RIS_R             (*((volatile unsigned long *)0x4000C03C))
#define UART0_MIS_R             (*((volatile unsigned long *)0x4000C040))
#define UART0_ICR_R             (*((volatile unsigned long *)0x4000C044))
#define UART0_DMACTL_R          (*((volatile unsigned long *)0x4000C048))
#define UART0_LCTL_R            (*((volatile unsigned long *)0x4000C090))
#define UART0_LSS_R             (*((volatile unsigned long *)0x4000C094))
#define UART0_LTIM_R            (*((volatile unsigned long *)0x4000C098))

//*****************************************************************************
//
// UART registers (UART1)
//
//*****************************************************************************
#define UART1_DR_R              (*((volatile unsigned long *)0x4000D000))
#define UART1_RSR_R             (*((volatile unsigned long *)0x4000D004))
#define UART1_ECR_R             (*((volatile unsigned long *)0x4000D004))
#define UART1_FR_R              (*((volatile unsigned long *)0x4000D018))
#define UART1_ILPR_R            (*((volatile unsigned long *)0x4000D020))
#define UART1_IBRD_R            (*((volatile unsigned long *)0x4000D024))
#define UART1_FBRD_R            (*((volatile unsigned long *)0x4000D028))
#define UART1_LCRH_R            (*((volatile unsigned long *)0x4000D02C))
#define UART1_CTL_R             (*((volatile unsigned long *)0x4000D030))
#define UART1_IFLS_R            (*((volatile unsigned long *)0x4000D034))
#define UART1_IM_R              (*((volatile unsigned long *)0x4000D038))
#define UART1_RIS_R             (*((volatile unsigned long *)0x4000D03C))
#define UART1_MIS_R             (*((volatile unsigned long *)0x4000D040))
#define UART1_ICR_R             (*((volatile unsigned long *)0x4000D044))
#define UART1_DMACTL_R          (*((volatile unsigned long *)0x4000D048))
#define UART1_LCTL_R            (*((volatile unsigned long *)0x4000D090))
#define UART1_LSS_R             (*((volatile unsigned long *)0x4000D094))
#define UART1_LTIM_R            (*((volatile unsigned long *)0x4000D098))

//*****************************************************************************
//
// UART registers (UART2)
//
//*****************************************************************************
#define UART2_DR_R              (*((volatile unsigned long *)0x4000E000))
#define UART2_RSR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_ECR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_FR_R              (*((volatile unsigned long *)0x4000E018))
#define UART2_ILPR_R            (*((volatile unsigned long *)0x4000E020))
#define UART2_IBRD_R            (*((volatile unsigned long *)0x4000E024))
#define UART2_FBRD_R            (*((volatile unsigned long *)0x4000E028))
#define UART2_LCRH_R            (*((volatile unsigned long *)0x4000E02C))
#define UART2_CTL_R             (*((volatile unsigned long *)0x4000E030))
#define UART2_IFLS_R            (*((volatile unsigned long *)0x4000E034))
#define UART2_IM_R              (*((volatile unsigned long *)0x4000E038))
#define UART2_RIS_R             (*((volatile unsigned long *)0x4000E03C))
#define UART2_MIS_R             (*((volatile unsigned long *)0x4000E040))
#define UART2_ICR_R             (*((volatile unsigned long *)0x4000E044))
#define UART2_DMACTL_R          (*((volatile unsigned long *)0x4000E048))
#define UART2_LCTL_R            (*((volatile unsigned long *)0x4000E090))
#define UART2_LSS_R             (*((volatile unsigned long *)0x4000E094))
#define UART2_LTIM_R            (*((volatile unsigned long *)0x4000E098))

//*****************************************************************************
//
// I2C registers (I2C0 MASTER)
//
//*****************************************************************************
#define I2C0_MASTER_MSA_R       (*((volatile unsigned long *)0x40020000))
#define I2C0_MASTER_SOAR_R      (*((volatile unsigned long *)0x40020000))
#define I2C0_MASTER_SCSR_R      (*((volatile unsigned long *)0x40020004))
#define I2C0_MASTER_MCS_R       (*((volatile unsigned long *)0x40020004))
#define I2C0_MASTER_SDR_R       (*((volatile unsigned long *)0x40020008))
#define I2C0_MASTER_MDR_R       (*((volatile unsigned long *)0x40020008))
#define I2C0_MASTER_MTPR_R      (*((volatile unsigned long *)0x4002000C))
#define I2C0_MASTER_SIMR_R      (*((volatile unsigned long *)0x4002000C))
#define I2C0_MASTER_SRIS_R      (*((volatile unsigned long *)0x40020010))
#define I2C0_MASTER_MIMR_R      (*((volatile unsigned long *)0x40020010))
#define I2C0_MASTER_MRIS_R      (*((volatile unsigned long *)0x40020014))
#define I2C0_MASTER_SMIS_R      (*((volatile unsigned long *)0x40020014))
#define I2C0_MASTER_SICR_R      (*((volatile unsigned long *)0x40020018))
#define I2C0_MASTER_MMIS_R      (*((volatile unsigned long *)0x40020018))
#define I2C0_MASTER_MICR_R      (*((volatile unsigned long *)0x4002001C))
#define I2C0_MASTER_MCR_R       (*((volatile unsigned long *)0x40020020))

//*****************************************************************************
//
// I2C registers (I2C0 SLAVE)
//
//*****************************************************************************
#define I2C0_SLAVE_MSA_R        (*((volatile unsigned long *)0x40020800))
#define I2C0_SLAVE_SOAR_R       (*((volatile unsigned long *)0x40020800))
#define I2C0_SLAVE_SCSR_R       (*((volatile unsigned long *)0x40020804))
#define I2C0_SLAVE_MCS_R        (*((volatile unsigned long *)0x40020804))
#define I2C0_SLAVE_SDR_R        (*((volatile unsigned long *)0x40020808))
#define I2C0_SLAVE_MDR_R        (*((volatile unsigned long *)0x40020808))
#define I2C0_SLAVE_MTPR_R       (*((volatile unsigned long *)0x4002080C))
#define I2C0_SLAVE_SIMR_R       (*((volatile unsigned long *)0x4002080C))
#define I2C0_SLAVE_SRIS_R       (*((volatile unsigned long *)0x40020810))
#define I2C0_SLAVE_MIMR_R       (*((volatile unsigned long *)0x40020810))
#define I2C0_SLAVE_MRIS_R       (*((volatile unsigned long *)0x40020814))
#define I2C0_SLAVE_SMIS_R       (*((volatile unsigned long *)0x40020814))
#define I2C0_SLAVE_SICR_R       (*((volatile unsigned long *)0x40020818))
#define I2C0_SLAVE_MMIS_R       (*((volatile unsigned long *)0x40020818))
#define I2C0_SLAVE_MICR_R       (*((volatile unsigned long *)0x4002081C))
#define I2C0_SLAVE_MCR_R        (*((volatile unsigned long *)0x40020820))

//*****************************************************************************
//
// I2C registers (I2C1 MASTER)
//
//*****************************************************************************
#define I2C1_MASTER_MSA_R       (*((volatile unsigned long *)0x40021000))
#define I2C1_MASTER_SOAR_R      (*((volatile unsigned long *)0x40021000))
#define I2C1_MASTER_SCSR_R      (*((volatile unsigned long *)0x40021004))
#define I2C1_MASTER_MCS_R       (*((volatile unsigned long *)0x40021004))
#define I2C1_MASTER_SDR_R       (*((volatile unsigned long *)0x40021008))
#define I2C1_MASTER_MDR_R       (*((volatile unsigned long *)0x40021008))
#define I2C1_MASTER_MTPR_R      (*((volatile unsigned long *)0x4002100C))
#define I2C1_MASTER_SIMR_R      (*((volatile unsigned long *)0x4002100C))
#define I2C1_MASTER_SRIS_R      (*((volatile unsigned long *)0x40021010))
#define I2C1_MASTER_MIMR_R      (*((volatile unsigned long *)0x40021010))
#define I2C1_MASTER_MRIS_R      (*((volatile unsigned long *)0x40021014))
#define I2C1_MASTER_SMIS_R      (*((volatile unsigned long *)0x40021014))
#define I2C1_MASTER_SICR_R      (*((volatile unsigned long *)0x40021018))
#define I2C1_MASTER_MMIS_R      (*((volatile unsigned long *)0x40021018))
#define I2C1_MASTER_MICR_R      (*((volatile unsigned long *)0x4002101C))
#define I2C1_MASTER_MCR_R       (*((volatile unsigned long *)0x40021020))

//*****************************************************************************
//
// I2C registers (I2C1 SLAVE)
//
//*****************************************************************************
#define I2C1_SLAVE_MSA_R        (*((volatile unsigned long *)0x40021800))
#define I2C1_SLAVE_SOAR_R       (*((volatile unsigned long *)0x40021800))
#define I2C1_SLAVE_SCSR_R       (*((volatile unsigned long *)0x40021804))
#define I2C1_SLAVE_MCS_R        (*((volatile unsigned long *)0x40021804))
#define I2C1_SLAVE_SDR_R        (*((volatile unsigned long *)0x40021808))
#define I2C1_SLAVE_MDR_R        (*((volatile unsigned long *)0x40021808))
#define I2C1_SLAVE_MTPR_R       (*((volatile unsigned long *)0x4002180C))
#define I2C1_SLAVE_SIMR_R       (*((volatile unsigned long *)0x4002180C))
#define I2C1_SLAVE_SRIS_R       (*((volatile unsigned long *)0x40021810))
#define I2C1_SLAVE_MIMR_R       (*((volatile unsigned long *)0x40021810))
#define I2C1_SLAVE_MRIS_R       (*((volatile unsigned long *)0x40021814))
#define I2C1_SLAVE_SMIS_R       (*((volatile unsigned long *)0x40021814))
#define I2C1_SLAVE_SICR_R       (*((volatile unsigned long *)0x40021818))
#define I2C1_SLAVE_MMIS_R       (*((volatile unsigned long *)0x40021818))
#define I2C1_SLAVE_MICR_R       (*((volatile unsigned long *)0x4002181C))
#define I2C1_SLAVE_MCR_R        (*((volatile unsigned long *)0x40021820))

//*****************************************************************************
//
// GPIO registers (PORTE)
//
//*****************************************************************************
#define GPIO_PORTE_DATA_BITS_R  ((volatile unsigned long *)0x40024000)
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_IS_R         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_R        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_R        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_R         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_R        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_MIS_R        (*((volatile unsigned long *)0x40024418))
#define GPIO_PORTE_ICR_R        (*((volatile unsigned long *)0x4002441C))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DR2R_R       (*((volatile unsigned long *)0x40024500))
#define GPIO_PORTE_DR4R_R       (*((volatile unsigned long *)0x40024504))
#define GPIO_PORTE_DR8R_R       (*((volatile unsigned long *)0x40024508))
#define GPIO_PORTE_ODR_R        (*((volatile unsigned long *)0x4002450C))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_R        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_SLR_R        (*((volatile unsigned long *)0x40024518))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

//*****************************************************************************
//
// GPIO registers (PORTF)
//
//*****************************************************************************
#define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x40025000)
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_MIS_R        (*((volatile unsigned long *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DR2R_R       (*((volatile unsigned long *)0x40025500))
#define GPIO_PORTF_DR4R_R       (*((volatile unsigned long *)0x40025504))
#define GPIO_PORTF_DR8R_R       (*((volatile unsigned long *)0x40025508))
#define GPIO_PORTF_ODR_R        (*((volatile unsigned long *)0x4002550C))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_SLR_R        (*((volatile unsigned long *)0x40025518))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))

//*****************************************************************************
//
// GPIO registers (PORTG)
//
//*****************************************************************************
#define GPIO_PORTG_DATA_BITS_R  ((volatile unsigned long *)0x40026000)
#define GPIO_PORTG_DATA_R       (*((volatile unsigned long *)0x400263FC))
#define GPIO_PORTG_DIR_R        (*((volatile unsigned long *)0x40026400))
#define GPIO_PORTG_IS_R         (*((volatile unsigned long *)0x40026404))
#define GPIO_PORTG_IBE_R        (*((volatile unsigned long *)0x40026408))
#define GPIO_PORTG_IEV_R        (*((volatile unsigned long *)0x4002640C))
#define GPIO_PORTG_IM_R         (*((volatile unsigned long *)0x40026410))
#define GPIO_PORTG_RIS_R        (*((volatile unsigned long *)0x40026414))
#define GPIO_PORTG_MIS_R        (*((volatile unsigned long *)0x40026418))
#define GPIO_PORTG_ICR_R        (*((volatile unsigned long *)0x4002641C))
#define GPIO_PORTG_AFSEL_R      (*((volatile unsigned long *)0x40026420))
#define GPIO_PORTG_DR2R_R       (*((volatile unsigned long *)0x40026500))
#define GPIO_PORTG_DR4R_R       (*((volatile unsigned long *)0x40026504))
#define GPIO_PORTG_DR8R_R       (*((volatile unsigned long *)0x40026508))
#define GPIO_PORTG_ODR_R        (*((volatile unsigned long *)0x4002650C))
#define GPIO_PORTG_PUR_R        (*((volatile unsigned long *)0x40026510))
#define GPIO_PORTG_PDR_R        (*((volatile unsigned long *)0x40026514))
#define GPIO_PORTG_SLR_R        (*((volatile unsigned long *)0x40026518))
#define GPIO_PORTG_DEN_R        (*((volatile unsigned long *)0x4002651C))
#define GPIO_PORTG_LOCK_R       (*((volatile unsigned long *)0x40026520))
#define GPIO_PORTG_CR_R         (*((volatile unsigned long *)0x40026524))
#define GPIO_PORTG_AMSEL_R      (*((volatile unsigned long *)0x40026528))
#define GPIO_PORTG_PCTL_R       (*((volatile unsigned long *)0x4002652C))

//*****************************************************************************
//
// GPIO registers (PORTH)
//
//*****************************************************************************
#define GPIO_PORTH_DATA_BITS_R  ((volatile unsigned long *)0x40027000)
#define GPIO_PORTH_DATA_R       (*((volatile unsigned long *)0x400273FC))
#define GPIO_PORTH_DIR_R        (*((volatile unsigned long *)0x40027400))
#define GPIO_PORTH_IS_R         (*((volatile unsigned long *)0x40027404))
#define GPIO_PORTH_IBE_R        (*((volatile unsigned long *)0x40027408))
#define GPIO_PORTH_IEV_R        (*((volatile unsigned long *)0x4002740C))
#define GPIO_PORTH_IM_R         (*((volatile unsigned long *)0x40027410))
#define GPIO_PORTH_RIS_R        (*((volatile unsigned long *)0x40027414))
#define GPIO_PORTH_MIS_R        (*((volatile unsigned long *)0x40027418))
#define GPIO_PORTH_ICR_R        (*((volatile unsigned long *)0x4002741C))
#define GPIO_PORTH_AFSEL_R      (*((volatile unsigned long *)0x40027420))
#define GPIO_PORTH_DR2R_R       (*((volatile unsigned long *)0x40027500))
#define GPIO_PORTH_DR4R_R       (*((volatile unsigned long *)0x40027504))
#define GPIO_PORTH_DR8R_R       (*((volatile unsigned long *)0x40027508))
#define GPIO_PORTH_ODR_R        (*((volatile unsigned long *)0x4002750C))
#define GPIO_PORTH_PUR_R        (*((volatile unsigned long *)0x40027510))
#define GPIO_PORTH_PDR_R        (*((volatile unsigned long *)0x40027514))
#define GPIO_PORTH_SLR_R        (*((volatile unsigned long *)0x40027518))
#define GPIO_PORTH_DEN_R        (*((volatile unsigned long *)0x4002751C))
#define GPIO_PORTH_LOCK_R       (*((volatile unsigned long *)0x40027520))
#define GPIO_PORTH_CR_R         (*((volatile unsigned long *)0x40027524))
#define GPIO_PORTH_AMSEL_R      (*((volatile unsigned long *)0x40027528))
#define GPIO_PORTH_PCTL_R       (*((volatile unsigned long *)0x4002752C))

//*****************************************************************************
//
// Timer registers (TIMER0)
//
//*****************************************************************************
#define TIMER0_CFG_R            (*((volatile unsigned long *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile unsigned long *)0x40030004))
#define TIMER0_TBMR_R           (*((volatile unsigned long *)0x40030008))
#define TIMER0_CTL_R            (*((volatile unsigned long *)0x4003000C))
#define TIMER0_IMR_R            (*((volatile unsigned long *)0x40030018))
#define TIMER0_RIS_R            (*((volatile unsigned long *)0x4003001C))
#define TIMER0_MIS_R            (*((volatile unsigned long *)0x40030020))
#define TIMER0_ICR_R            (*((volatile unsigned long *)0x40030024))
#define TIMER0_TAILR_R          (*((volatile unsigned long *)0x40030028))
#define TIMER0_TBILR_R          (*((volatile unsigned long *)0x4003002C))
#define TIMER0_TAMATCHR_R       (*((volatile unsigned long *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile unsigned long *)0x40030034))
#define TIMER0_TAPR_R           (*((volatile unsigned long *)0x40030038))
#define TIMER0_TBPR_R           (*((volatile unsigned long *)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile unsigned long *)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile unsigned long *)0x40030044))
#define TIMER0_TAR_R            (*((volatile unsigned long *)0x40030048))
#define TIMER0_TBR_R            (*((volatile unsigned long *)0x4003004C))
#define TIMER0_TAV_R            (*((volatile unsigned long *)0x40030050))
#define TIMER0_TBV_R            (*((volatile unsigned long *)0x40030054))

//*****************************************************************************
//
// Timer registers (TIMER1)
//
//*****************************************************************************
#define TIMER1_CFG_R            (*((volatile unsigned long *)0x40031000))
#define TIMER1_TAMR_R           (*((volatile unsigned long *)0x40031004))
#define TIMER1_TBMR_R           (*((volatile unsigned long *)0x40031008))
#define TIMER1_CTL_R            (*((volatile unsigned long *)0x4003100C))
#define TIMER1_IMR_R            (*((volatile unsigned long *)0x40031018))
#define TIMER1_RIS_R            (*((volatile unsigned long *)0x4003101C))
#define TIMER1_MIS_R            (*((volatile unsigned long *)0x40031020))
#define TIMER1_ICR_R            (*((volatile unsigned long *)0x40031024))
#define TIMER1_TAILR_R          (*((volatile unsigned long *)0x40031028))
#define TIMER1_TBILR_R          (*((volatile unsigned long *)0x4003102C))
#define TIMER1_TAMATCHR_R       (*((volatile unsigned long *)0x40031030))
#define TIMER1_TBMATCHR_R       (*((volatile unsigned long *)0x40031034))
#define TIMER1_TAPR_R           (*((volatile unsigned long *)0x40031038))
#define TIMER1_TBPR_R           (*((volatile unsigned long *)0x4003103C))
#define TIMER1_TAPMR_R          (*((volatile unsigned long *)0x40031040))
#define TIMER1_TBPMR_R          (*((volatile unsigned long *)0x40031044))
#define TIMER1_TAR_R            (*((volatile unsigned long *)0x40031048))
#define TIMER1_TBR_R            (*((volatile unsigned long *)0x4003104C))
#define TIMER1_TAV_R            (*((volatile unsigned long *)0x40031050))
#define TIMER1_TBV_R            (*((volatile unsigned long *)0x40031054))

//*****************************************************************************
//
// Timer registers (TIMER2)
//
//*****************************************************************************
#define TIMER2_CFG_R            (*((volatile unsigned long *)0x40032000))
#define TIMER2_TAMR_R           (*((volatile unsigned long *)0x40032004))
#define TIMER2_TBMR_R           (*((volatile unsigned long *)0x40032008))
#define TIMER2_CTL_R            (*((volatile unsigned long *)0x4003200C))
#define TIMER2_IMR_R            (*((volatile unsigned long *)0x40032018))
#define TIMER2_RIS_R            (*((volatile unsigned long *)0x4003201C))
#define TIMER2_MIS_R            (*((volatile unsigned long *)0x40032020))
#define TIMER2_ICR_R            (*((volatile unsigned long *)0x40032024))
#define TIMER2_TAILR_R          (*((volatile unsigned long *)0x40032028))
#define TIMER2_TBILR_R          (*((volatile unsigned long *)0x4003202C))
#define TIMER2_TAMATCHR_R       (*((volatile unsigned long *)0x40032030))
#define TIMER2_TBMATCHR_R       (*((volatile unsigned long *)0x40032034))
#define TIMER2_TAPR_R           (*((volatile unsigned long *)0x40032038))
#define TIMER2_TBPR_R           (*((volatile unsigned long *)0x4003203C))
#define TIMER2_TAPMR_R          (*((volatile unsigned long *)0x40032040))
#define TIMER2_TBPMR_R          (*((volatile unsigned long *)0x40032044))
#define TIMER2_TAR_R            (*((volatile unsigned long *)0x40032048))
#define TIMER2_TBR_R            (*((volatile unsigned long *)0x4003204C))
#define TIMER2_TAV_R            (*((volatile unsigned long *)0x40032050))
#define TIMER2_TBV_R            (*((volatile unsigned long *)0x40032054))

//*****************************************************************************
//
// Timer registers (TIMER3)
//
//*****************************************************************************
#define TIMER3_CFG_R            (*((volatile unsigned long *)0x40033000))
#define TIMER3_TAMR_R           (*((volatile unsigned long *)0x40033004))
#define TIMER3_TBMR_R           (*((volatile unsigned long *)0x40033008))
#define TIMER3_CTL_R            (*((volatile unsigned long *)0x4003300C))
#define TIMER3_IMR_R            (*((volatile unsigned long *)0x40033018))
#define TIMER3_RIS_R            (*((volatile unsigned long *)0x4003301C))
#define TIMER3_MIS_R            (*((volatile unsigned long *)0x40033020))
#define TIMER3_ICR_R            (*((volatile unsigned long *)0x40033024))
#define TIMER3_TAILR_R          (*((volatile unsigned long *)0x40033028))
#define TIMER3_TBILR_R          (*((volatile unsigned long *)0x4003302C))
#define TIMER3_TAMATCHR_R       (*((volatile unsigned long *)0x40033030))
#define TIMER3_TBMATCHR_R       (*((volatile unsigned long *)0x40033034))
#define TIMER3_TAPR_R           (*((volatile unsigned long *)0x40033038))
#define TIMER3_TBPR_R           (*((volatile unsigned long *)0x4003303C))
#define TIMER3_TAPMR_R          (*((volatile unsigned long *)0x40033040))
#define TIMER3_TBPMR_R          (*((volatile unsigned long *)0x40033044))
#define TIMER3_TAR_R            (*((volatile unsigned long *)0x40033048))
#define TIMER3_TBR_R            (*((volatile unsigned long *)0x4003304C))
#define TIMER3_TAV_R            (*((volatile unsigned long *)0x40033050))
#define TIMER3_TBV_R            (*((volatile unsigned long *)0x40033054))

//*****************************************************************************
//
// ADC registers (ADC0)
//
//*****************************************************************************
#define ADC0_ACTSS_R            (*((volatile unsigned long *)0x40038000))
#define ADC0_RIS_R              (*((volatile unsigned long *)0x40038004))
#define ADC0_IM_R               (*((volatile unsigned long *)0x40038008))
#define ADC0_ISC_R              (*((volatile unsigned long *)0x4003800C))
#define ADC0_OSTAT_R            (*((volatile unsigned long *)0x40038010))
#define ADC0_EMUX_R             (*((volatile unsigned long *)0x40038014))
#define ADC0_USTAT_R            (*((volatile unsigned long *)0x40038018))
#define ADC0_SSPRI_R            (*((volatile unsigned long *)0x40038020))
#define ADC0_SPC_R              (*((volatile unsigned long *)0x40038024))
#define ADC0_PSSI_R             (*((volatile unsigned long *)0x40038028))
#define ADC0_SAC_R              (*((volatile unsigned long *)0x40038030))
#define ADC0_DCISC_R            (*((volatile unsigned long *)0x40038034))
#define ADC0_CTL_R              (*((volatile unsigned long *)0x40038038))
#define ADC0_SSMUX0_R           (*((volatile unsigned long *)0x40038040))
#define ADC0_SSCTL0_R           (*((volatile unsigned long *)0x40038044))
#define ADC0_SSFIFO0_R          (*((volatile unsigned long *)0x40038048))
#define ADC0_SSFSTAT0_R         (*((volatile unsigned long *)0x4003804C))
#define ADC0_SSOP0_R            (*((volatile unsigned long *)0x40038050))
#define ADC0_SSDC0_R            (*((volatile unsigned long *)0x40038054))
#define ADC0_SSMUX1_R           (*((volatile unsigned long *)0x40038060))
#define ADC0_SSCTL1_R           (*((volatile unsigned long *)0x40038064))
#define ADC0_SSFIFO1_R          (*((volatile unsigned long *)0x40038068))
#define ADC0_SSFSTAT1_R         (*((volatile unsigned long *)0x4003806C))
#define ADC0_SSOP1_R            (*((volatile unsigned long *)0x40038070))
#define ADC0_SSDC1_R            (*((volatile unsigned long *)0x40038074))
#define ADC0_SSMUX2_R           (*((volatile unsigned long *)0x40038080))
#define ADC0_SSCTL2_R           (*((volatile unsigned long *)0x40038084))
#define ADC0_SSFIFO2_R          (*((volatile unsigned long *)0x40038088))
#define ADC0_SSFSTAT2_R         (*((volatile unsigned long *)0x4003808C))
#define ADC0_SSOP2_R            (*((volatile unsigned long *)0x40038090))
#define ADC0_SSDC2_R            (*((volatile unsigned long *)0x40038094))
#define ADC0_SSMUX3_R           (*((volatile unsigned long *)0x400380A0))
#define ADC0_SSCTL3_R           (*((volatile unsigned long *)0x400380A4))
#define ADC0_SSFIFO3_R          (*((volatile unsigned long *)0x400380A8))
#define ADC0_SSFSTAT3_R         (*((volatile unsigned long *)0x400380AC))
#define ADC0_SSOP3_R            (*((volatile unsigned long *)0x400380B0))
#define ADC0_SSDC3_R            (*((volatile unsigned long *)0x400380B4))
#define ADC0_DCRIC_R            (*((volatile unsigned long *)0x40038D00))
#define ADC0_DCCTL0_R           (*((volatile unsigned long *)0x40038E00))
#define ADC0_DCCTL1_R           (*((volatile unsigned long *)0x40038E04))
#define ADC0_DCCTL2_R           (*((volatile unsigned long *)0x40038E08))
#define ADC0_DCCTL3_R           (*((volatile unsigned long *)0x40038E0C))
#define ADC0_DCCTL4_R           (*((volatile unsigned long *)0x40038E10))
#define ADC0_DCCTL5_R           (*((volatile unsigned long *)0x40038E14))
#define ADC0_DCCTL6_R           (*((volatile unsigned long *)0x40038E18))
#define ADC0_DCCTL7_R           (*((volatile unsigned long *)0x40038E1C))
#define ADC0_DCCMP0_R           (*((volatile unsigned long *)0x40038E40))
#define ADC0_DCCMP1_R           (*((volatile unsigned long *)0x40038E44))
#define ADC0_DCCMP2_R           (*((volatile unsigned long *)0x40038E48))
#define ADC0_DCCMP3_R           (*((volatile unsigned long *)0x40038E4C))
#define ADC0_DCCMP4_R           (*((volatile unsigned long *)0x40038E50))
#define ADC0_DCCMP5_R           (*((volatile unsigned long *)0x40038E54))
#define ADC0_DCCMP6_R           (*((volatile unsigned long *)0x40038E58))
#define ADC0_DCCMP7_R           (*((volatile unsigned long *)0x40038E5C))

//*****************************************************************************
//
// ADC registers (ADC1)
//
//*****************************************************************************
#define ADC1_ACTSS_R            (*((volatile unsigned long *)0x40039000))
#define ADC1_RIS_R              (*((volatile unsigned long *)0x40039004))
#define ADC1_IM_R               (*((volatile unsigned long *)0x40039008))
#define ADC1_ISC_R              (*((volatile unsigned long *)0x4003900C))
#define ADC1_OSTAT_R            (*((volatile unsigned long *)0x40039010))
#define ADC1_EMUX_R             (*((volatile unsigned long *)0x40039014))
#define ADC1_USTAT_R            (*((volatile unsigned long *)0x40039018))
#define ADC1_SSPRI_R            (*((volatile unsigned long *)0x40039020))
#define ADC1_SPC_R              (*((volatile unsigned long *)0x40039024))
#define ADC1_PSSI_R             (*((volatile unsigned long *)0x40039028))
#define ADC1_SAC_R              (*((volatile unsigned long *)0x40039030))
#define ADC1_DCISC_R            (*((volatile unsigned long *)0x40039034))
#define ADC1_CTL_R              (*((volatile unsigned long *)0x40039038))
#define ADC1_SSMUX0_R           (*((volatile unsigned long *)0x40039040))
#define ADC1_SSCTL0_R           (*((volatile unsigned long *)0x40039044))
#define ADC1_SSFIFO0_R          (*((volatile unsigned long *)0x40039048))
#define ADC1_SSFSTAT0_R         (*((volatile unsigned long *)0x4003904C))
#define ADC1_SSOP0_R            (*((volatile unsigned long *)0x40039050))
#define ADC1_SSDC0_R            (*((volatile unsigned long *)0x40039054))
#define ADC1_SSMUX1_R           (*((volatile unsigned long *)0x40039060))
#define ADC1_SSCTL1_R           (*((volatile unsigned long *)0x40039064))
#define ADC1_SSFIFO1_R          (*((volatile unsigned long *)0x40039068))
#define ADC1_SSFSTAT1_R         (*((volatile unsigned long *)0x4003906C))
#define ADC1_SSOP1_R            (*((volatile unsigned long *)0x40039070))
#define ADC1_SSDC1_R            (*((volatile unsigned long *)0x40039074))
#define ADC1_SSMUX2_R           (*((volatile unsigned long *)0x40039080))
#define ADC1_SSCTL2_R           (*((volatile unsigned long *)0x40039084))
#define ADC1_SSFIFO2_R          (*((volatile unsigned long *)0x40039088))
#define ADC1_SSFSTAT2_R         (*((volatile unsigned long *)0x4003908C))
#define ADC1_SSOP2_R            (*((volatile unsigned long *)0x40039090))
#define ADC1_SSDC2_R            (*((volatile unsigned long *)0x40039094))
#define ADC1_SSMUX3_R           (*((volatile unsigned long *)0x400390A0))
#define ADC1_SSCTL3_R           (*((volatile unsigned long *)0x400390A4))
#define ADC1_SSFIFO3_R          (*((volatile unsigned long *)0x400390A8))
#define ADC1_SSFSTAT3_R         (*((volatile unsigned long *)0x400390AC))
#define ADC1_SSOP3_R            (*((volatile unsigned long *)0x400390B0))
#define ADC1_SSDC3_R            (*((volatile unsigned long *)0x400390B4))
#define ADC1_DCRIC_R            (*((volatile unsigned long *)0x40039D00))
#define ADC1_DCCTL0_R           (*((volatile unsigned long *)0x40039E00))
#define ADC1_DCCTL1_R           (*((volatile unsigned long *)0x40039E04))
#define ADC1_DCCTL2_R           (*((volatile unsigned long *)0x40039E08))
#define ADC1_DCCTL3_R           (*((volatile unsigned long *)0x40039E0C))
#define ADC1_DCCTL4_R           (*((volatile unsigned long *)0x40039E10))
#define ADC1_DCCTL5_R           (*((volatile unsigned long *)0x40039E14))
#define ADC1_DCCTL6_R           (*((volatile unsigned long *)0x40039E18))
#define ADC1_DCCTL7_R           (*((volatile unsigned long *)0x40039E1C))
#define ADC1_DCCMP0_R           (*((volatile unsigned long *)0x40039E40))
#define ADC1_DCCMP1_R           (*((volatile unsigned long *)0x40039E44))
#define ADC1_DCCMP2_R           (*((volatile unsigned long *)0x40039E48))
#define ADC1_DCCMP3_R           (*((volatile unsigned long *)0x40039E4C))
#define ADC1_DCCMP4_R           (*((volatile unsigned long *)0x40039E50))
#define ADC1_DCCMP5_R           (*((volatile unsigned long *)0x40039E54))
#define ADC1_DCCMP6_R           (*((volatile unsigned long *)0x40039E58))
#define ADC1_DCCMP7_R           (*((volatile unsigned long *)0x40039E5C))

//*****************************************************************************
//
// Comparator registers (COMP)
//
//*****************************************************************************
#define COMP_ACMIS_R            (*((volatile unsigned long *)0x4003C000))
#define COMP_ACRIS_R            (*((volatile unsigned long *)0x4003C004))
#define COMP_ACINTEN_R          (*((volatile unsigned long *)0x4003C008))
#define COMP_ACREFCTL_R         (*((volatile unsigned long *)0x4003C010))
#define COMP_ACSTAT0_R          (*((volatile unsigned long *)0x4003C020))
#define COMP_ACCTL0_R           (*((volatile unsigned long *)0x4003C024))
#define COMP_ACSTAT1_R          (*((volatile unsigned long *)0x4003C040))
#define COMP_ACCTL1_R           (*((volatile unsigned long *)0x4003C044))
#define COMP_ACSTAT2_R          (*((volatile unsigned long *)0x4003C060))
#define COMP_ACCTL2_R           (*((volatile unsigned long *)0x4003C064))

//*****************************************************************************
//
// GPIO registers (PORTJ)
//
//*****************************************************************************
#define GPIO_PORTJ_DATA_BITS_R  ((volatile unsigned long *)0x4003D000)
#define GPIO_PORTJ_DATA_R       (*((volatile unsigned long *)0x4003D3FC))
#define GPIO_PORTJ_DIR_R        (*((volatile unsigned long *)0x4003D400))
#define GPIO_PORTJ_IS_R         (*((volatile unsigned long *)0x4003D404))
#define GPIO_PORTJ_IBE_R        (*((volatile unsigned long *)0x4003D408))
#define GPIO_PORTJ_IEV_R        (*((volatile unsigned long *)0x4003D40C))
#define GPIO_PORTJ_IM_R         (*((volatile unsigned long *)0x4003D410))
#define GPIO_PORTJ_RIS_R        (*((volatile unsigned long *)0x4003D414))
#define GPIO_PORTJ_MIS_R        (*((volatile unsigned long *)0x4003D418))
#define GPIO_PORTJ_ICR_R        (*((volatile unsigned long *)0x4003D41C))
#define GPIO_PORTJ_AFSEL_R      (*((volatile unsigned long *)0x4003D420))
#define GPIO_PORTJ_DR2R_R       (*((volatile unsigned long *)0x4003D500))
#define GPIO_PORTJ_DR4R_R       (*((volatile unsigned long *)0x4003D504))
#define GPIO_PORTJ_DR8R_R       (*((volatile unsigned long *)0x4003D508))
#define GPIO_PORTJ_ODR_R        (*((volatile unsigned long *)0x4003D50C))
#define GPIO_PORTJ_PUR_R        (*((volatile unsigned long *)0x4003D510))
#define GPIO_PORTJ_PDR_R        (*((volatile unsigned long *)0x4003D514))
#define GPIO_PORTJ_SLR_R        (*((volatile unsigned long *)0x4003D518))
#define GPIO_PORTJ_DEN_R        (*((volatile unsigned long *)0x4003D51C))
#define GPIO_PORTJ_LOCK_R       (*((volatile unsigned long *)0x4003D520))
#define GPIO_PORTJ_CR_R         (*((volatile unsigned long *)0x4003D524))
#define GPIO_PORTJ_AMSEL_R      (*((volatile unsigned long *)0x4003D528))
#define GPIO_PORTJ_PCTL_R       (*((volatile unsigned long *)0x4003D52C))

//*****************************************************************************
//
// CAN registers (CAN0)
//
//*****************************************************************************
#define CAN0_CTL_R              (*((volatile unsigned long *)0x40040000))
#define CAN0_STS_R              (*((volatile unsigned long *)0x40040004))
#define CAN0_ERR_R              (*((volatile unsigned long *)0x40040008))
#define CAN0_BIT_R              (*((volatile unsigned long *)0x4004000C))
#define CAN0_INT_R              (*((volatile unsigned long *)0x40040010))
#define CAN0_TST_R              (*((volatile unsigned long *)0x40040014))
#define CAN0_BRPE_R             (*((volatile unsigned long *)0x40040018))
#define CAN0_IF1CRQ_R           (*((volatile unsigned long *)0x40040020))
#define CAN0_IF1CMSK_R          (*((volatile unsigned long *)0x40040024))
#define CAN0_IF1MSK1_R          (*((volatile unsigned long *)0x40040028))
#define CAN0_IF1MSK2_R          (*((volatile unsigned long *)0x4004002C))
#define CAN0_IF1ARB1_R          (*((volatile unsigned long *)0x40040030))
#define CAN0_IF1ARB2_R          (*((volatile unsigned long *)0x40040034))
#define CAN0_IF1MCTL_R          (*((volatile unsigned long *)0x40040038))
#define CAN0_IF1DA1_R           (*((volatile unsigned long *)0x4004003C))
#define CAN0_IF1DA2_R           (*((volatile unsigned long *)0x40040040))
#define CAN0_IF1DB1_R           (*((volatile unsigned long *)0x40040044))
#define CAN0_IF1DB2_R           (*((volatile unsigned long *)0x40040048))
#define CAN0_IF2CRQ_R           (*((volatile unsigned long *)0x40040080))
#define CAN0_IF2CMSK_R          (*((volatile unsigned long *)0x40040084))
#define CAN0_IF2MSK1_R          (*((volatile unsigned long *)0x40040088))
#define CAN0_IF2MSK2_R          (*((volatile unsigned long *)0x4004008C))
#define CAN0_IF2ARB1_R          (*((volatile unsigned long *)0x40040090))
#define CAN0_IF2ARB2_R          (*((volatile unsigned long *)0x40040094))
#define CAN0_IF2MCTL_R          (*((volatile unsigned long *)0x40040098))
#define CAN0_IF2DA1_R           (*((volatile unsigned long *)0x4004009C))
#define CAN0_IF2DA2_R           (*((volatile unsigned long *)0x400400A0))
#define CAN0_IF2DB1_R           (*((volatile unsigned long *)0x400400A4))
#define CAN0_IF2DB2_R           (*((volatile unsigned long *)0x400400A8))
#define CAN0_TXRQ1_R            (*((volatile unsigned long *)0x40040100))
#define CAN0_TXRQ2_R            (*((volatile unsigned long *)0x40040104))
#define CAN0_NWDA1_R            (*((volatile unsigned long *)0x40040120))
#define CAN0_NWDA2_R            (*((volatile unsigned long *)0x40040124))
#define CAN0_MSG1INT_R          (*((volatile unsigned long *)0x40040140))
#define CAN0_MSG2INT_R          (*((volatile unsigned long *)0x40040144))
#define CAN0_MSG1VAL_R          (*((volatile unsigned long *)0x40040160))
#define CAN0_MSG2VAL_R          (*((volatile unsigned long *)0x40040164))

//*****************************************************************************
//
// CAN registers (CAN1)
//
//*****************************************************************************
#define CAN1_CTL_R              (*((volatile unsigned long *)0x40041000))
#define CAN1_STS_R              (*((volatile unsigned long *)0x40041004))
#define CAN1_ERR_R              (*((volatile unsigned long *)0x40041008))
#define CAN1_BIT_R              (*((volatile unsigned long *)0x4004100C))
#define CAN1_INT_R              (*((volatile unsigned long *)0x40041010))
#define CAN1_TST_R              (*((volatile unsigned long *)0x40041014))
#define CAN1_BRPE_R             (*((volatile unsigned long *)0x40041018))
#define CAN1_IF1CRQ_R           (*((volatile unsigned long *)0x40041020))
#define CAN1_IF1CMSK_R          (*((volatile unsigned long *)0x40041024))
#define CAN1_IF1MSK1_R          (*((volatile unsigned long *)0x40041028))
#define CAN1_IF1MSK2_R          (*((volatile unsigned long *)0x4004102C))
#define CAN1_IF1ARB1_R          (*((volatile unsigned long *)0x40041030))
#define CAN1_IF1ARB2_R          (*((volatile unsigned long *)0x40041034))
#define CAN1_IF1MCTL_R          (*((volatile unsigned long *)0x40041038))
#define CAN1_IF1DA1_R           (*((volatile unsigned long *)0x4004103C))
#define CAN1_IF1DA2_R           (*((volatile unsigned long *)0x40041040))
#define CAN1_IF1DB1_R           (*((volatile unsigned long *)0x40041044))
#define CAN1_IF1DB2_R           (*((volatile unsigned long *)0x40041048))
#define CAN1_IF2CRQ_R           (*((volatile unsigned long *)0x40041080))
#define CAN1_IF2CMSK_R          (*((volatile unsigned long *)0x40041084))
#define CAN1_IF2MSK1_R          (*((volatile unsigned long *)0x40041088))
#define CAN1_IF2MSK2_R          (*((volatile unsigned long *)0x4004108C))
#define CAN1_IF2ARB1_R          (*((volatile unsigned long *)0x40041090))
#define CAN1_IF2ARB2_R          (*((volatile unsigned long *)0x40041094))
#define CAN1_IF2MCTL_R          (*((volatile unsigned long *)0x40041098))
#define CAN1_IF2DA1_R           (*((volatile unsigned long *)0x4004109C))
#define CAN1_IF2DA2_R           (*((volatile unsigned long *)0x400410A0))
#define CAN1_IF2DB1_R           (*((volatile unsigned long *)0x400410A4))
#define CAN1_IF2DB2_R           (*((volatile unsigned long *)0x400410A8))
#define CAN1_TXRQ1_R            (*((volatile unsigned long *)0x40041100))
#define CAN1_TXRQ2_R            (*((volatile unsigned long *)0x40041104))
#define CAN1_NWDA1_R            (*((volatile unsigned long *)0x40041120))
#define CAN1_NWDA2_R            (*((volatile unsigned long *)0x40041124))
#define CAN1_MSG1INT_R          (*((volatile unsigned long *)0x40041140))
#define CAN1_MSG2INT_R          (*((volatile unsigned long *)0x40041144))
#define CAN1_MSG1VAL_R          (*((volatile unsigned long *)0x40041160))
#define CAN1_MSG2VAL_R          (*((volatile unsigned long *)0x40041164))

//*****************************************************************************
//
// Ethernet MAC registers (MAC)
//
//*****************************************************************************
#define MAC_RIS_R               (*((volatile unsigned long *)0x40048000))
#define MAC_IM_R                (*((volatile unsigned long *)0x40048004))
#define MAC_RCTL_R              (*((volatile unsigned long *)0x40048008))
#define MAC_TCTL_R              (*((volatile unsigned long *)0x4004800C))
#define MAC_DATA_R              (*((volatile unsigned long *)0x40048010))
#define MAC_IA0_R               (*((volatile unsigned long *)0x40048014))
#define MAC_IA1_R               (*((volatile unsigned long *)0x40048018))
#define MAC_THR_R               (*((volatile unsigned long *)0x4004801C))
#define MAC_MCTL_R              (*((volatile unsigned long *)0x40048020))
#define MAC_MDV_R               (*((volatile unsigned long *)0x40048024))
#define MAC_MTXD_R              (*((volatile unsigned long *)0x4004802C))
#define MAC_MRXD_R              (*((volatile unsigned long *)0x40048030))
#define MAC_NP_R                (*((volatile unsigned long *)0x40048034))
#define MAC_TR_R                (*((volatile unsigned long *)0x40048038))
#define MAC_LED_R               (*((volatile unsigned long *)0x40048040))
#define MAC_MDIX_R              (*((volatile unsigned long *)0x40048044))

//*****************************************************************************
//
// Ethernet Controller PHY registers (MAC)
//
//*****************************************************************************
#define PHY_MR0                 0x00000000  // Ethernet PHY Management Register
                                            // 0 - Control
#define PHY_MR1                 0x00000001  // Ethernet PHY Management Register
                                            // 1 - Status
#define PHY_MR2                 0x00000002  // Ethernet PHY Management Register
                                            // 2 - PHY Identifier 1
#define PHY_MR3                 0x00000003  // Ethernet PHY Management Register
                                            // 3 - PHY Identifier 2
#define PHY_MR4                 0x00000004  // Ethernet PHY Management Register
                                            // 4 - Auto-Negotiation
                                            // Advertisement
#define PHY_MR5                 0x00000005  // Ethernet PHY Management Register
                                            // 5 - Auto-Negotiation Link
                                            // Partner Base Page Ability
#define PHY_MR6                 0x00000006  // Ethernet PHY Management Register
                                            // 6 - Auto-Negotiation Expansion
#define PHY_MR16                0x00000010  // Ethernet PHY Management Register
                                            // 16 - Vendor-Specific
#define PHY_MR17                0x00000011  // Ethernet PHY Management Register
                                            // 17 - Mode Control/Status
#define PHY_MR27                0x0000001B  // Ethernet PHY Management Register
                                            // 27 - Special Control/Status
#define PHY_MR29                0x0000001D  // Ethernet PHY Management Register
                                            // 29 - Interrupt Status
#define PHY_MR30                0x0000001E  // Ethernet PHY Management Register
                                            // 30 - Interrupt Mask
#define PHY_MR31                0x0000001F  // Ethernet PHY Management Register
                                            // 31 - PHY Special Control/Status

//*****************************************************************************
//
// Univeral Serial Bus registers (USB0)
//
//*****************************************************************************
#define USB0_FADDR_R            (*((volatile unsigned char *)0x40050000))
#define USB0_POWER_R            (*((volatile unsigned char *)0x40050001))
#define USB0_TXIS_R             (*((volatile unsigned short *)0x40050002))
#define USB0_RXIS_R             (*((volatile unsigned short *)0x40050004))
#define USB0_TXIE_R             (*((volatile unsigned short *)0x40050006))
#define USB0_RXIE_R             (*((volatile unsigned short *)0x40050008))
#define USB0_IS_R               (*((volatile unsigned char *)0x4005000A))
#define USB0_IE_R               (*((volatile unsigned char *)0x4005000B))
#define USB0_FRAME_R            (*((volatile unsigned short *)0x4005000C))
#define USB0_EPIDX_R            (*((volatile unsigned char *)0x4005000E))
#define USB0_TEST_R             (*((volatile unsigned char *)0x4005000F))
#define USB0_FIFO0_R            (*((volatile unsigned long *)0x40050020))
#define USB0_FIFO1_R            (*((volatile unsigned long *)0x40050024))
#define USB0_FIFO2_R            (*((volatile unsigned long *)0x40050028))
#define USB0_FIFO3_R            (*((volatile unsigned long *)0x4005002C))
#define USB0_FIFO4_R            (*((volatile unsigned long *)0x40050030))
#define USB0_FIFO5_R            (*((volatile unsigned long *)0x40050034))
#define USB0_FIFO6_R            (*((volatile unsigned long *)0x40050038))
#define USB0_FIFO7_R            (*((volatile unsigned long *)0x4005003C))
#define USB0_FIFO8_R            (*((volatile unsigned long *)0x40050040))
#define USB0_FIFO9_R            (*((volatile unsigned long *)0x40050044))
#define USB0_FIFO10_R           (*((volatile unsigned long *)0x40050048))
#define USB0_FIFO11_R           (*((volatile unsigned long *)0x4005004C))
#define USB0_FIFO12_R           (*((volatile unsigned long *)0x40050050))
#define USB0_FIFO13_R           (*((volatile unsigned long *)0x40050054))
#define USB0_FIFO14_R           (*((volatile unsigned long *)0x40050058))
#define USB0_FIFO15_R           (*((volatile unsigned long *)0x4005005C))
#define USB0_DEVCTL_R           (*((volatile unsigned char *)0x40050060))
#define USB0_TXFIFOSZ_R         (*((volatile unsigned char *)0x40050062))
#define USB0_RXFIFOSZ_R         (*((volatile unsigned char *)0x40050063))
#define USB0_TXFIFOADD_R        (*((volatile unsigned short *)0x40050064))
#define USB0_RXFIFOADD_R        (*((volatile unsigned short *)0x40050066))
#define USB0_CONTIM_R           (*((volatile unsigned char *)0x4005007A))
#define USB0_VPLEN_R            (*((volatile unsigned char *)0x4005007B))
#define USB0_FSEOF_R            (*((volatile unsigned char *)0x4005007D))
#define USB0_LSEOF_R            (*((volatile unsigned char *)0x4005007E))
#define USB0_TXFUNCADDR0_R      (*((volatile unsigned char *)0x40050080))
#define USB0_TXHUBADDR0_R       (*((volatile unsigned char *)0x40050082))
#define USB0_TXHUBPORT0_R       (*((volatile unsigned char *)0x40050083))
#define USB0_TXFUNCADDR1_R      (*((volatile unsigned char *)0x40050088))
#define USB0_TXHUBADDR1_R       (*((volatile unsigned char *)0x4005008A))
#define USB0_TXHUBPORT1_R       (*((volatile unsigned char *)0x4005008B))
#define USB0_RXFUNCADDR1_R      (*((volatile unsigned char *)0x4005008C))
#define USB0_RXHUBADDR1_R       (*((volatile unsigned char *)0x4005008E))
#define USB0_RXHUBPORT1_R       (*((volatile unsigned char *)0x4005008F))
#define USB0_TXFUNCADDR2_R      (*((volatile unsigned char *)0x40050090))
#define USB0_TXHUBADDR2_R       (*((volatile unsigned char *)0x40050092))
#define USB0_TXHUBPORT2_R       (*((volatile unsigned char *)0x40050093))
#define USB0_RXFUNCADDR2_R      (*((volatile unsigned char *)0x40050094))
#define USB0_RXHUBADDR2_R       (*((volatile unsigned char *)0x40050096))
#define USB0_RXHUBPORT2_R       (*((volatile unsigned char *)0x40050097))
#define USB0_TXFUNCADDR3_R      (*((volatile unsigned char *)0x40050098))
#define USB0_TXHUBADDR3_R       (*((volatile unsigned char *)0x4005009A))
#define USB0_TXHUBPORT3_R       (*((volatile unsigned char *)0x4005009B))
#define USB0_RXFUNCADDR3_R      (*((volatile unsigned char *)0x4005009C))
#define USB0_RXHUBADDR3_R       (*((volatile unsigned char *)0x4005009E))
#define USB0_RXHUBPORT3_R       (*((volatile unsigned char *)0x4005009F))
#define USB0_TXFUNCADDR4_R      (*((volatile unsigned char *)0x400500A0))
#define USB0_TXHUBADDR4_R       (*((volatile unsigned char *)0x400500A2))
#define USB0_TXHUBPORT4_R       (*((volatile unsigned char *)0x400500A3))
#define USB0_RXFUNCADDR4_R      (*((volatile unsigned char *)0x400500A4))
#define USB0_RXHUBADDR4_R       (*((volatile unsigned char *)0x400500A6))
#define USB0_RXHUBPORT4_R       (*((volatile unsigned char *)0x400500A7))
#define USB0_TXFUNCADDR5_R      (*((volatile unsigned char *)0x400500A8))
#define USB0_TXHUBADDR5_R       (*((volatile unsigned char *)0x400500AA))
#define USB0_TXHUBPORT5_R       (*((volatile unsigned char *)0x400500AB))
#define USB0_RXFUNCADDR5_R      (*((volatile unsigned char *)0x400500AC))
#define USB0_RXHUBADDR5_R       (*((volatile unsigned char *)0x400500AE))
#define USB0_RXHUBPORT5_R       (*((volatile unsigned char *)0x400500AF))
#define USB0_TXFUNCADDR6_R      (*((volatile unsigned char *)0x400500B0))
#define USB0_TXHUBADDR6_R       (*((volatile unsigned char *)0x400500B2))
#define USB0_TXHUBPORT6_R       (*((volatile unsigned char *)0x400500B3))
#define USB0_RXFUNCADDR6_R      (*((volatile unsigned char *)0x400500B4))
#define USB0_RXHUBADDR6_R       (*((volatile unsigned char *)0x400500B6))
#define USB0_RXHUBPORT6_R       (*((volatile unsigned char *)0x400500B7))
#define USB0_TXFUNCADDR7_R      (*((volatile unsigned char *)0x400500B8))
#define USB0_TXHUBADDR7_R       (*((volatile unsigned char *)0x400500BA))
#define USB0_TXHUBPORT7_R       (*((volatile unsigned char *)0x400500BB))
#define USB0_RXFUNCADDR7_R      (*((volatile unsigned char *)0x400500BC))
#define USB0_RXHUBADDR7_R       (*((volatile unsigned char *)0x400500BE))
#define USB0_RXHUBPORT7_R       (*((volatile unsigned char *)0x400500BF))
#define USB0_TXFUNCADDR8_R      (*((volatile unsigned char *)0x400500C0))
#define USB0_TXHUBADDR8_R       (*((volatile unsigned char *)0x400500C2))
#define USB0_TXHUBPORT8_R       (*((volatile unsigned char *)0x400500C3))
#define USB0_RXFUNCADDR8_R      (*((volatile unsigned char *)0x400500C4))
#define USB0_RXHUBADDR8_R       (*((volatile unsigned char *)0x400500C6))
#define USB0_RXHUBPORT8_R       (*((volatile unsigned char *)0x400500C7))
#define USB0_TXFUNCADDR9_R      (*((volatile unsigned char *)0x400500C8))
#define USB0_TXHUBADDR9_R       (*((volatile unsigned char *)0x400500CA))
#define USB0_TXHUBPORT9_R       (*((volatile unsigned char *)0x400500CB))
#define USB0_RXFUNCADDR9_R      (*((volatile unsigned char *)0x400500CC))
#define USB0_RXHUBADDR9_R       (*((volatile unsigned char *)0x400500CE))
#define USB0_RXHUBPORT9_R       (*((volatile unsigned char *)0x400500CF))
#define USB0_TXFUNCADDR10_R     (*((volatile unsigned char *)0x400500D0))
#define USB0_TXHUBADDR10_R      (*((volatile unsigned char *)0x400500D2))
#define USB0_TXHUBPORT10_R      (*((volatile unsigned char *)0x400500D3))
#define USB0_RXFUNCADDR10_R     (*((volatile unsigned char *)0x400500D4))
#define USB0_RXHUBADDR10_R      (*((volatile unsigned char *)0x400500D6))
#define USB0_RXHUBPORT10_R      (*((volatile unsigned char *)0x400500D7))
#define USB0_TXFUNCADDR11_R     (*((volatile unsigned char *)0x400500D8))
#define USB0_TXHUBADDR11_R      (*((volatile unsigned char *)0x400500DA))
#define USB0_TXHUBPORT11_R      (*((volatile unsigned char *)0x400500DB))
#define USB0_RXFUNCADDR11_R     (*((volatile unsigned char *)0x400500DC))
#define USB0_RXHUBADDR11_R      (*((volatile unsigned char *)0x400500DE))
#define USB0_RXHUBPORT11_R      (*((volatile unsigned char *)0x400500DF))
#define USB0_TXFUNCADDR12_R     (*((volatile unsigned char *)0x400500E0))
#define USB0_TXHUBADDR12_R      (*((volatile unsigned char *)0x400500E2))
#define USB0_TXHUBPORT12_R      (*((volatile unsigned char *)0x400500E3))
#define USB0_RXFUNCADDR12_R     (*((volatile unsigned char *)0x400500E4))
#define USB0_RXHUBADDR12_R      (*((volatile unsigned char *)0x400500E6))
#define USB0_RXHUBPORT12_R      (*((volatile unsigned char *)0x400500E7))
#define USB0_TXFUNCADDR13_R     (*((volatile unsigned char *)0x400500E8))
#define USB0_TXHUBADDR13_R      (*((volatile unsigned char *)0x400500EA))
#define USB0_TXHUBPORT13_R      (*((volatile unsigned char *)0x400500EB))
#define USB0_RXFUNCADDR13_R     (*((volatile unsigned char *)0x400500EC))
#define USB0_RXHUBADDR13_R      (*((volatile unsigned char *)0x400500EE))
#define USB0_RXHUBPORT13_R      (*((volatile unsigned char *)0x400500EF))
#define USB0_TXFUNCADDR14_R     (*((volatile unsigned char *)0x400500F0))
#define USB0_TXHUBADDR14_R      (*((volatile unsigned char *)0x400500F2))
#define USB0_TXHUBPORT14_R      (*((volatile unsigned char *)0x400500F3))
#define USB0_RXFUNCADDR14_R     (*((volatile unsigned char *)0x400500F4))
#define USB0_RXHUBADDR14_R      (*((volatile unsigned char *)0x400500F6))
#define USB0_RXHUBPORT14_R      (*((volatile unsigned char *)0x400500F7))
#define USB0_TXFUNCADDR15_R     (*((volatile unsigned char *)0x400500F8))
#define USB0_TXHUBADDR15_R      (*((volatile unsigned char *)0x400500FA))
#define USB0_TXHUBPORT15_R      (*((volatile unsigned char *)0x400500FB))
#define USB0_RXFUNCADDR15_R     (*((volatile unsigned char *)0x400500FC))
#define USB0_RXHUBADDR15_R      (*((volatile unsigned char *)0x400500FE))
#define USB0_RXHUBPORT15_R      (*((volatile unsigned char *)0x400500FF))
#define USB0_CSRL0_R            (*((volatile unsigned char *)0x40050102))
#define USB0_CSRH0_R            (*((volatile unsigned char *)0x40050103))
#define USB0_COUNT0_R           (*((volatile unsigned char *)0x40050108))
#define USB0_TYPE0_R            (*((volatile unsigned char *)0x4005010A))
#define USB0_NAKLMT_R           (*((volatile unsigned char *)0x4005010B))
#define USB0_TXMAXP1_R          (*((volatile unsigned short *)0x40050110))
#define USB0_TXCSRL1_R          (*((volatile unsigned char *)0x40050112))
#define USB0_TXCSRH1_R          (*((volatile unsigned char *)0x40050113))
#define USB0_RXMAXP1_R          (*((volatile unsigned short *)0x40050114))
#define USB0_RXCSRL1_R          (*((volatile unsigned char *)0x40050116))
#define USB0_RXCSRH1_R          (*((volatile unsigned char *)0x40050117))
#define USB0_RXCOUNT1_R         (*((volatile unsigned short *)0x40050118))
#define USB0_TXTYPE1_R          (*((volatile unsigned char *)0x4005011A))
#define USB0_TXINTERVAL1_R      (*((volatile unsigned char *)0x4005011B))
#define USB0_RXTYPE1_R          (*((volatile unsigned char *)0x4005011C))
#define USB0_RXINTERVAL1_R      (*((volatile unsigned char *)0x4005011D))
#define USB0_TXMAXP2_R          (*((volatile unsigned short *)0x40050120))
#define USB0_TXCSRL2_R          (*((volatile unsigned char *)0x40050122))
#define USB0_TXCSRH2_R          (*((volatile unsigned char *)0x40050123))
#define USB0_RXMAXP2_R          (*((volatile unsigned short *)0x40050124))
#define USB0_RXCSRL2_R          (*((volatile unsigned char *)0x40050126))
#define USB0_RXCSRH2_R          (*((volatile unsigned char *)0x40050127))
#define USB0_RXCOUNT2_R         (*((volatile unsigned short *)0x40050128))
#define USB0_TXTYPE2_R          (*((volatile unsigned char *)0x4005012A))
#define USB0_TXINTERVAL2_R      (*((volatile unsigned char *)0x4005012B))
#define USB0_RXTYPE2_R          (*((volatile unsigned char *)0x4005012C))
#define USB0_RXINTERVAL2_R      (*((volatile unsigned char *)0x4005012D))
#define USB0_TXMAXP3_R          (*((volatile unsigned short *)0x40050130))
#define USB0_TXCSRL3_R          (*((volatile unsigned char *)0x40050132))
#define USB0_TXCSRH3_R          (*((volatile unsigned char *)0x40050133))
#define USB0_RXMAXP3_R          (*((volatile unsigned short *)0x40050134))
#define USB0_RXCSRL3_R          (*((volatile unsigned char *)0x40050136))
#define USB0_RXCSRH3_R          (*((volatile unsigned char *)0x40050137))
#define USB0_RXCOUNT3_R         (*((volatile unsigned short *)0x40050138))
#define USB0_TXTYPE3_R          (*((volatile unsigned char *)0x4005013A))
#define USB0_TXINTERVAL3_R      (*((volatile unsigned char *)0x4005013B))
#define USB0_RXTYPE3_R          (*((volatile unsigned char *)0x4005013C))
#define USB0_RXINTERVAL3_R      (*((volatile unsigned char *)0x4005013D))
#define USB0_TXMAXP4_R          (*((volatile unsigned short *)0x40050140))
#define USB0_TXCSRL4_R          (*((volatile unsigned char *)0x40050142))
#define USB0_TXCSRH4_R          (*((volatile unsigned char *)0x40050143))
#define USB0_RXMAXP4_R          (*((volatile unsigned short *)0x40050144))
#define USB0_RXCSRL4_R          (*((volatile unsigned char *)0x40050146))
#define USB0_RXCSRH4_R          (*((volatile unsigned char *)0x40050147))
#define USB0_RXCOUNT4_R         (*((volatile unsigned short *)0x40050148))
#define USB0_TXTYPE4_R          (*((volatile unsigned char *)0x4005014A))
#define USB0_TXINTERVAL4_R      (*((volatile unsigned char *)0x4005014B))
#define USB0_RXTYPE4_R          (*((volatile unsigned char *)0x4005014C))
#define USB0_RXINTERVAL4_R      (*((volatile unsigned char *)0x4005014D))
#define USB0_TXMAXP5_R          (*((volatile unsigned short *)0x40050150))
#define USB0_TXCSRL5_R          (*((volatile unsigned char *)0x40050152))
#define USB0_TXCSRH5_R          (*((volatile unsigned char *)0x40050153))
#define USB0_RXMAXP5_R          (*((volatile unsigned short *)0x40050154))
#define USB0_RXCSRL5_R          (*((volatile unsigned char *)0x40050156))
#define USB0_RXCSRH5_R          (*((volatile unsigned char *)0x40050157))
#define USB0_RXCOUNT5_R         (*((volatile unsigned short *)0x40050158))
#define USB0_TXTYPE5_R          (*((volatile unsigned char *)0x4005015A))
#define USB0_TXINTERVAL5_R      (*((volatile unsigned char *)0x4005015B))
#define USB0_RXTYPE5_R          (*((volatile unsigned char *)0x4005015C))
#define USB0_RXINTERVAL5_R      (*((volatile unsigned char *)0x4005015D))
#define USB0_TXMAXP6_R          (*((volatile unsigned short *)0x40050160))
#define USB0_TXCSRL6_R          (*((volatile unsigned char *)0x40050162))
#define USB0_TXCSRH6_R          (*((volatile unsigned char *)0x40050163))
#define USB0_RXMAXP6_R          (*((volatile unsigned short *)0x40050164))
#define USB0_RXCSRL6_R          (*((volatile unsigned char *)0x40050166))
#define USB0_RXCSRH6_R          (*((volatile unsigned char *)0x40050167))
#define USB0_RXCOUNT6_R         (*((volatile unsigned short *)0x40050168))
#define USB0_TXTYPE6_R          (*((volatile unsigned char *)0x4005016A))
#define USB0_TXINTERVAL6_R      (*((volatile unsigned char *)0x4005016B))
#define USB0_RXTYPE6_R          (*((volatile unsigned char *)0x4005016C))
#define USB0_RXINTERVAL6_R      (*((volatile unsigned char *)0x4005016D))
#define USB0_TXMAXP7_R          (*((volatile unsigned short *)0x40050170))
#define USB0_TXCSRL7_R          (*((volatile unsigned char *)0x40050172))
#define USB0_TXCSRH7_R          (*((volatile unsigned char *)0x40050173))
#define USB0_RXMAXP7_R          (*((volatile unsigned short *)0x40050174))
#define USB0_RXCSRL7_R          (*((volatile unsigned char *)0x40050176))
#define USB0_RXCSRH7_R          (*((volatile unsigned char *)0x40050177))
#define USB0_RXCOUNT7_R         (*((volatile unsigned short *)0x40050178))
#define USB0_TXTYPE7_R          (*((volatile unsigned char *)0x4005017A))
#define USB0_TXINTERVAL7_R      (*((volatile unsigned char *)0x4005017B))
#define USB0_RXTYPE7_R          (*((volatile unsigned char *)0x4005017C))
#define USB0_RXINTERVAL7_R      (*((volatile unsigned char *)0x4005017D))
#define USB0_TXMAXP8_R          (*((volatile unsigned short *)0x40050180))
#define USB0_TXCSRL8_R          (*((volatile unsigned char *)0x40050182))
#define USB0_TXCSRH8_R          (*((volatile unsigned char *)0x40050183))
#define USB0_RXMAXP8_R          (*((volatile unsigned short *)0x40050184))
#define USB0_RXCSRL8_R          (*((volatile unsigned char *)0x40050186))
#define USB0_RXCSRH8_R          (*((volatile unsigned char *)0x40050187))
#define USB0_RXCOUNT8_R         (*((volatile unsigned short *)0x40050188))
#define USB0_TXTYPE8_R          (*((volatile unsigned char *)0x4005018A))
#define USB0_TXINTERVAL8_R      (*((volatile unsigned char *)0x4005018B))
#define USB0_RXTYPE8_R          (*((volatile unsigned char *)0x4005018C))
#define USB0_RXINTERVAL8_R      (*((volatile unsigned char *)0x4005018D))
#define USB0_TXMAXP9_R          (*((volatile unsigned short *)0x40050190))
#define USB0_TXCSRL9_R          (*((volatile unsigned char *)0x40050192))
#define USB0_TXCSRH9_R          (*((volatile unsigned char *)0x40050193))
#define USB0_RXMAXP9_R          (*((volatile unsigned short *)0x40050194))
#define USB0_RXCSRL9_R          (*((volatile unsigned char *)0x40050196))
#define USB0_RXCSRH9_R          (*((volatile unsigned char *)0x40050197))
#define USB0_RXCOUNT9_R         (*((volatile unsigned short *)0x40050198))
#define USB0_TXTYPE9_R          (*((volatile unsigned char *)0x4005019A))
#define USB0_TXINTERVAL9_R      (*((volatile unsigned char *)0x4005019B))
#define USB0_RXTYPE9_R          (*((volatile unsigned char *)0x4005019C))
#define USB0_RXINTERVAL9_R      (*((volatile unsigned char *)0x4005019D))
#define USB0_TXMAXP10_R         (*((volatile unsigned short *)0x400501A0))
#define USB0_TXCSRL10_R         (*((volatile unsigned char *)0x400501A2))
#define USB0_TXCSRH10_R         (*((volatile unsigned char *)0x400501A3))
#define USB0_RXMAXP10_R         (*((volatile unsigned short *)0x400501A4))
#define USB0_RXCSRL10_R         (*((volatile unsigned char *)0x400501A6))
#define USB0_RXCSRH10_R         (*((volatile unsigned char *)0x400501A7))
#define USB0_RXCOUNT10_R        (*((volatile unsigned short *)0x400501A8))
#define USB0_TXTYPE10_R         (*((volatile unsigned char *)0x400501AA))
#define USB0_TXINTERVAL10_R     (*((volatile unsigned char *)0x400501AB))
#define USB0_RXTYPE10_R         (*((volatile unsigned char *)0x400501AC))
#define USB0_RXINTERVAL10_R     (*((volatile unsigned char *)0x400501AD))
#define USB0_TXMAXP11_R         (*((volatile unsigned short *)0x400501B0))
#define USB0_TXCSRL11_R         (*((volatile unsigned char *)0x400501B2))
#define USB0_TXCSRH11_R         (*((volatile unsigned char *)0x400501B3))
#define USB0_RXMAXP11_R         (*((volatile unsigned short *)0x400501B4))
#define USB0_RXCSRL11_R         (*((volatile unsigned char *)0x400501B6))
#define USB0_RXCSRH11_R         (*((volatile unsigned char *)0x400501B7))
#define USB0_RXCOUNT11_R        (*((volatile unsigned short *)0x400501B8))
#define USB0_TXTYPE11_R         (*((volatile unsigned char *)0x400501BA))
#define USB0_TXINTERVAL11_R     (*((volatile unsigned char *)0x400501BB))
#define USB0_RXTYPE11_R         (*((volatile unsigned char *)0x400501BC))
#define USB0_RXINTERVAL11_R     (*((volatile unsigned char *)0x400501BD))
#define USB0_TXMAXP12_R         (*((volatile unsigned short *)0x400501C0))
#define USB0_TXCSRL12_R         (*((volatile unsigned char *)0x400501C2))
#define USB0_TXCSRH12_R         (*((volatile unsigned char *)0x400501C3))
#define USB0_RXMAXP12_R         (*((volatile unsigned short *)0x400501C4))
#define USB0_RXCSRL12_R         (*((volatile unsigned char *)0x400501C6))
#define USB0_RXCSRH12_R         (*((volatile unsigned char *)0x400501C7))
#define USB0_RXCOUNT12_R        (*((volatile unsigned short *)0x400501C8))
#define USB0_TXTYPE12_R         (*((volatile unsigned char *)0x400501CA))
#define USB0_TXINTERVAL12_R     (*((volatile unsigned char *)0x400501CB))
#define USB0_RXTYPE12_R         (*((volatile unsigned char *)0x400501CC))
#define USB0_RXINTERVAL12_R     (*((volatile unsigned char *)0x400501CD))
#define USB0_TXMAXP13_R         (*((volatile unsigned short *)0x400501D0))
#define USB0_TXCSRL13_R         (*((volatile unsigned char *)0x400501D2))
#define USB0_TXCSRH13_R         (*((volatile unsigned char *)0x400501D3))
#define USB0_RXMAXP13_R         (*((volatile unsigned short *)0x400501D4))
#define USB0_RXCSRL13_R         (*((volatile unsigned char *)0x400501D6))
#define USB0_RXCSRH13_R         (*((volatile unsigned char *)0x400501D7))
#define USB0_RXCOUNT13_R        (*((volatile unsigned short *)0x400501D8))
#define USB0_TXTYPE13_R         (*((volatile unsigned char *)0x400501DA))
#define USB0_TXINTERVAL13_R     (*((volatile unsigned char *)0x400501DB))
#define USB0_RXTYPE13_R         (*((volatile unsigned char *)0x400501DC))
#define USB0_RXINTERVAL13_R     (*((volatile unsigned char *)0x400501DD))
#define USB0_TXMAXP14_R         (*((volatile unsigned short *)0x400501E0))
#define USB0_TXCSRL14_R         (*((volatile unsigned char *)0x400501E2))
#define USB0_TXCSRH14_R         (*((volatile unsigned char *)0x400501E3))
#define USB0_RXMAXP14_R         (*((volatile unsigned short *)0x400501E4))
#define USB0_RXCSRL14_R         (*((volatile unsigned char *)0x400501E6))
#define USB0_RXCSRH14_R         (*((volatile unsigned char *)0x400501E7))
#define USB0_RXCOUNT14_R        (*((volatile unsigned short *)0x400501E8))
#define USB0_TXTYPE14_R         (*((volatile unsigned char *)0x400501EA))
#define USB0_TXINTERVAL14_R     (*((volatile unsigned char *)0x400501EB))
#define USB0_RXTYPE14_R         (*((volatile unsigned char *)0x400501EC))
#define USB0_RXINTERVAL14_R     (*((volatile unsigned char *)0x400501ED))
#define USB0_TXMAXP15_R         (*((volatile unsigned short *)0x400501F0))
#define USB0_TXCSRL15_R         (*((volatile unsigned char *)0x400501F2))
#define USB0_TXCSRH15_R         (*((volatile unsigned char *)0x400501F3))
#define USB0_RXMAXP15_R         (*((volatile unsigned short *)0x400501F4))
#define USB0_RXCSRL15_R         (*((volatile unsigned char *)0x400501F6))
#define USB0_RXCSRH15_R         (*((volatile unsigned char *)0x400501F7))
#define USB0_RXCOUNT15_R        (*((volatile unsigned short *)0x400501F8))
#define USB0_TXTYPE15_R         (*((volatile unsigned char *)0x400501FA))
#define USB0_TXINTERVAL15_R     (*((volatile unsigned char *)0x400501FB))
#define USB0_RXTYPE15_R         (*((volatile unsigned char *)0x400501FC))
#define USB0_RXINTERVAL15_R     (*((volatile unsigned char *)0x400501FD))
#define USB0_RQPKTCOUNT1_R      (*((volatile unsigned short *)0x40050304))
#define USB0_RQPKTCOUNT2_R      (*((volatile unsigned short *)0x40050308))
#define USB0_RQPKTCOUNT3_R      (*((volatile unsigned short *)0x4005030C))
#define USB0_RQPKTCOUNT4_R      (*((volatile unsigned short *)0x40050310))
#define USB0_RQPKTCOUNT5_R      (*((volatile unsigned short *)0x40050314))
#define USB0_RQPKTCOUNT6_R      (*((volatile unsigned short *)0x40050318))
#define USB0_RQPKTCOUNT7_R      (*((volatile unsigned short *)0x4005031C))
#define USB0_RQPKTCOUNT8_R      (*((volatile unsigned short *)0x40050320))
#define USB0_RQPKTCOUNT9_R      (*((volatile unsigned short *)0x40050324))
#define USB0_RQPKTCOUNT10_R     (*((volatile unsigned short *)0x40050328))
#define USB0_RQPKTCOUNT11_R     (*((volatile unsigned short *)0x4005032C))
#define USB0_RQPKTCOUNT12_R     (*((volatile unsigned short *)0x40050330))
#define USB0_RQPKTCOUNT13_R     (*((volatile unsigned short *)0x40050334))
#define USB0_RQPKTCOUNT14_R     (*((volatile unsigned short *)0x40050338))
#define USB0_RQPKTCOUNT15_R     (*((volatile unsigned short *)0x4005033C))
#define USB0_RXDPKTBUFDIS_R     (*((volatile unsigned short *)0x40050340))
#define USB0_TXDPKTBUFDIS_R     (*((volatile unsigned short *)0x40050342))
#define USB0_EPC_R              (*((volatile unsigned long *)0x40050400))
#define USB0_EPCRIS_R           (*((volatile unsigned long *)0x40050404))
#define USB0_EPCIM_R            (*((volatile unsigned long *)0x40050408))
#define USB0_EPCISC_R           (*((volatile unsigned long *)0x4005040C))
#define USB0_DRRIS_R            (*((volatile unsigned long *)0x40050410))
#define USB0_DRIM_R             (*((volatile unsigned long *)0x40050414))
#define USB0_DRISC_R            (*((volatile unsigned long *)0x40050418))
#define USB0_GPCS_R             (*((volatile unsigned long *)0x4005041C))
#define USB0_VDC_R              (*((volatile unsigned long *)0x40050430))
#define USB0_VDCRIS_R           (*((volatile unsigned long *)0x40050434))
#define USB0_VDCIM_R            (*((volatile unsigned long *)0x40050438))
#define USB0_VDCISC_R           (*((volatile unsigned long *)0x4005043C))
#define USB0_IDVRIS_R           (*((volatile unsigned long *)0x40050444))
#define USB0_IDVIM_R            (*((volatile unsigned long *)0x40050448))
#define USB0_IDVISC_R           (*((volatile unsigned long *)0x4005044C))
#define USB0_DMASEL_R           (*((volatile unsigned long *)0x40050450))

//*****************************************************************************
//
// Inter-Integrated Circuit Sound registers (I2S0)
//
//*****************************************************************************
#define I2S0_TXFIFO_R           (*((volatile unsigned long *)0x40054000))
#define I2S0_TXFIFOCFG_R        (*((volatile unsigned long *)0x40054004))
#define I2S0_TXCFG_R            (*((volatile unsigned long *)0x40054008))
#define I2S0_TXLIMIT_R          (*((volatile unsigned long *)0x4005400C))
#define I2S0_TXISM_R            (*((volatile unsigned long *)0x40054010))
#define I2S0_TXLEV_R            (*((volatile unsigned long *)0x40054018))
#define I2S0_RXFIFO_R           (*((volatile unsigned long *)0x40054800))
#define I2S0_RXFIFOCFG_R        (*((volatile unsigned long *)0x40054804))
#define I2S0_RXCFG_R            (*((volatile unsigned long *)0x40054808))
#define I2S0_RXLIMIT_R          (*((volatile unsigned long *)0x4005480C))
#define I2S0_RXISM_R            (*((volatile unsigned long *)0x40054810))
#define I2S0_RXLEV_R            (*((volatile unsigned long *)0x40054818))
#define I2S0_CFG_R              (*((volatile unsigned long *)0x40054C00))
#define I2S0_IM_R               (*((volatile unsigned long *)0x40054C10))
#define I2S0_RIS_R              (*((volatile unsigned long *)0x40054C14))
#define I2S0_MIS_R              (*((volatile unsigned long *)0x40054C18))
#define I2S0_IC_R               (*((volatile unsigned long *)0x40054C1C))

//*****************************************************************************
//
// GPIO registers (PORTA AHB)
//
//*****************************************************************************
#define GPIO_PORTA_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x40058000)
#define GPIO_PORTA_AHB_DATA_R   (*((volatile unsigned long *)0x400583FC))
#define GPIO_PORTA_AHB_DIR_R    (*((volatile unsigned long *)0x40058400))
#define GPIO_PORTA_AHB_IS_R     (*((volatile unsigned long *)0x40058404))
#define GPIO_PORTA_AHB_IBE_R    (*((volatile unsigned long *)0x40058408))
#define GPIO_PORTA_AHB_IEV_R    (*((volatile unsigned long *)0x4005840C))
#define GPIO_PORTA_AHB_IM_R     (*((volatile unsigned long *)0x40058410))
#define GPIO_PORTA_AHB_RIS_R    (*((volatile unsigned long *)0x40058414))
#define GPIO_PORTA_AHB_MIS_R    (*((volatile unsigned long *)0x40058418))
#define GPIO_PORTA_AHB_ICR_R    (*((volatile unsigned long *)0x4005841C))
#define GPIO_PORTA_AHB_AFSEL_R  (*((volatile unsigned long *)0x40058420))
#define GPIO_PORTA_AHB_DR2R_R   (*((volatile unsigned long *)0x40058500))
#define GPIO_PORTA_AHB_DR4R_R   (*((volatile unsigned long *)0x40058504))
#define GPIO_PORTA_AHB_DR8R_R   (*((volatile unsigned long *)0x40058508))
#define GPIO_PORTA_AHB_ODR_R    (*((volatile unsigned long *)0x4005850C))
#define GPIO_PORTA_AHB_PUR_R    (*((volatile unsigned long *)0x40058510))
#define GPIO_PORTA_AHB_PDR_R    (*((volatile unsigned long *)0x40058514))
#define GPIO_PORTA_AHB_SLR_R    (*((volatile unsigned long *)0x40058518))
#define GPIO_PORTA_AHB_DEN_R    (*((volatile unsigned long *)0x4005851C))
#define GPIO_PORTA_AHB_LOCK_R   (*((volatile unsigned long *)0x40058520))
#define GPIO_PORTA_AHB_CR_R     (*((volatile unsigned long *)0x40058524))
#define GPIO_PORTA_AHB_AMSEL_R  (*((volatile unsigned long *)0x40058528))
#define GPIO_PORTA_AHB_PCTL_R   (*((volatile unsigned long *)0x4005852C))

//*****************************************************************************
//
// GPIO registers (PORTB AHB)
//
//*****************************************************************************
#define GPIO_PORTB_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x40059000)
#define GPIO_PORTB_AHB_DATA_R   (*((volatile unsigned long *)0x400593FC))
#define GPIO_PORTB_AHB_DIR_R    (*((volatile unsigned long *)0x40059400))
#define GPIO_PORTB_AHB_IS_R     (*((volatile unsigned long *)0x40059404))
#define GPIO_PORTB_AHB_IBE_R    (*((volatile unsigned long *)0x40059408))
#define GPIO_PORTB_AHB_IEV_R    (*((volatile unsigned long *)0x4005940C))
#define GPIO_PORTB_AHB_IM_R     (*((volatile unsigned long *)0x40059410))
#define GPIO_PORTB_AHB_RIS_R    (*((volatile unsigned long *)0x40059414))
#define GPIO_PORTB_AHB_MIS_R    (*((volatile unsigned long *)0x40059418))
#define GPIO_PORTB_AHB_ICR_R    (*((volatile unsigned long *)0x4005941C))
#define GPIO_PORTB_AHB_AFSEL_R  (*((volatile unsigned long *)0x40059420))
#define GPIO_PORTB_AHB_DR2R_R   (*((volatile unsigned long *)0x40059500))
#define GPIO_PORTB_AHB_DR4R_R   (*((volatile unsigned long *)0x40059504))
#define GPIO_PORTB_AHB_DR8R_R   (*((volatile unsigned long *)0x40059508))
#define GPIO_PORTB_AHB_ODR_R    (*((volatile unsigned long *)0x4005950C))
#define GPIO_PORTB_AHB_PUR_R    (*((volatile unsigned long *)0x40059510))
#define GPIO_PORTB_AHB_PDR_R    (*((volatile unsigned long *)0x40059514))
#define GPIO_PORTB_AHB_SLR_R    (*((volatile unsigned long *)0x40059518))
#define GPIO_PORTB_AHB_DEN_R    (*((volatile unsigned long *)0x4005951C))
#define GPIO_PORTB_AHB_LOCK_R   (*((volatile unsigned long *)0x40059520))
#define GPIO_PORTB_AHB_CR_R     (*((volatile unsigned long *)0x40059524))
#define GPIO_PORTB_AHB_AMSEL_R  (*((volatile unsigned long *)0x40059528))
#define GPIO_PORTB_AHB_PCTL_R   (*((volatile unsigned long *)0x4005952C))

//*****************************************************************************
//
// GPIO registers (PORTC AHB)
//
//*****************************************************************************
#define GPIO_PORTC_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005A000)
#define GPIO_PORTC_AHB_DATA_R   (*((volatile unsigned long *)0x4005A3FC))
#define GPIO_PORTC_AHB_DIR_R    (*((volatile unsigned long *)0x4005A400))
#define GPIO_PORTC_AHB_IS_R     (*((volatile unsigned long *)0x4005A404))
#define GPIO_PORTC_AHB_IBE_R    (*((volatile unsigned long *)0x4005A408))
#define GPIO_PORTC_AHB_IEV_R    (*((volatile unsigned long *)0x4005A40C))
#define GPIO_PORTC_AHB_IM_R     (*((volatile unsigned long *)0x4005A410))
#define GPIO_PORTC_AHB_RIS_R    (*((volatile unsigned long *)0x4005A414))
#define GPIO_PORTC_AHB_MIS_R    (*((volatile unsigned long *)0x4005A418))
#define GPIO_PORTC_AHB_ICR_R    (*((volatile unsigned long *)0x4005A41C))
#define GPIO_PORTC_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005A420))
#define GPIO_PORTC_AHB_DR2R_R   (*((volatile unsigned long *)0x4005A500))
#define GPIO_PORTC_AHB_DR4R_R   (*((volatile unsigned long *)0x4005A504))
#define GPIO_PORTC_AHB_DR8R_R   (*((volatile unsigned long *)0x4005A508))
#define GPIO_PORTC_AHB_ODR_R    (*((volatile unsigned long *)0x4005A50C))
#define GPIO_PORTC_AHB_PUR_R    (*((volatile unsigned long *)0x4005A510))
#define GPIO_PORTC_AHB_PDR_R    (*((volatile unsigned long *)0x4005A514))
#define GPIO_PORTC_AHB_SLR_R    (*((volatile unsigned long *)0x4005A518))
#define GPIO_PORTC_AHB_DEN_R    (*((volatile unsigned long *)0x4005A51C))
#define GPIO_PORTC_AHB_LOCK_R   (*((volatile unsigned long *)0x4005A520))
#define GPIO_PORTC_AHB_CR_R     (*((volatile unsigned long *)0x4005A524))
#define GPIO_PORTC_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005A528))
#define GPIO_PORTC_AHB_PCTL_R   (*((volatile unsigned long *)0x4005A52C))

//*****************************************************************************
//
// GPIO registers (PORTD AHB)
//
//*****************************************************************************
#define GPIO_PORTD_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005B000)
#define GPIO_PORTD_AHB_DATA_R   (*((volatile unsigned long *)0x4005B3FC))
#define GPIO_PORTD_AHB_DIR_R    (*((volatile unsigned long *)0x4005B400))
#define GPIO_PORTD_AHB_IS_R     (*((volatile unsigned long *)0x4005B404))
#define GPIO_PORTD_AHB_IBE_R    (*((volatile unsigned long *)0x4005B408))
#define GPIO_PORTD_AHB_IEV_R    (*((volatile unsigned long *)0x4005B40C))
#define GPIO_PORTD_AHB_IM_R     (*((volatile unsigned long *)0x4005B410))
#define GPIO_PORTD_AHB_RIS_R    (*((volatile unsigned long *)0x4005B414))
#define GPIO_PORTD_AHB_MIS_R    (*((volatile unsigned long *)0x4005B418))
#define GPIO_PORTD_AHB_ICR_R    (*((volatile unsigned long *)0x4005B41C))
#define GPIO_PORTD_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005B420))
#define GPIO_PORTD_AHB_DR2R_R   (*((volatile unsigned long *)0x4005B500))
#define GPIO_PORTD_AHB_DR4R_R   (*((volatile unsigned long *)0x4005B504))
#define GPIO_PORTD_AHB_DR8R_R   (*((volatile unsigned long *)0x4005B508))
#define GPIO_PORTD_AHB_ODR_R    (*((volatile unsigned long *)0x4005B50C))
#define GPIO_PORTD_AHB_PUR_R    (*((volatile unsigned long *)0x4005B510))
#define GPIO_PORTD_AHB_PDR_R    (*((volatile unsigned long *)0x4005B514))
#define GPIO_PORTD_AHB_SLR_R    (*((volatile unsigned long *)0x4005B518))
#define GPIO_PORTD_AHB_DEN_R    (*((volatile unsigned long *)0x4005B51C))
#define GPIO_PORTD_AHB_LOCK_R   (*((volatile unsigned long *)0x4005B520))
#define GPIO_PORTD_AHB_CR_R     (*((volatile unsigned long *)0x4005B524))
#define GPIO_PORTD_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005B528))
#define GPIO_PORTD_AHB_PCTL_R   (*((volatile unsigned long *)0x4005B52C))

//*****************************************************************************
//
// GPIO registers (PORTE AHB)
//
//*****************************************************************************
#define GPIO_PORTE_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005C000)
#define GPIO_PORTE_AHB_DATA_R   (*((volatile unsigned long *)0x4005C3FC))
#define GPIO_PORTE_AHB_DIR_R    (*((volatile unsigned long *)0x4005C400))
#define GPIO_PORTE_AHB_IS_R     (*((volatile unsigned long *)0x4005C404))
#define GPIO_PORTE_AHB_IBE_R    (*((volatile unsigned long *)0x4005C408))
#define GPIO_PORTE_AHB_IEV_R    (*((volatile unsigned long *)0x4005C40C))
#define GPIO_PORTE_AHB_IM_R     (*((volatile unsigned long *)0x4005C410))
#define GPIO_PORTE_AHB_RIS_R    (*((volatile unsigned long *)0x4005C414))
#define GPIO_PORTE_AHB_MIS_R    (*((volatile unsigned long *)0x4005C418))
#define GPIO_PORTE_AHB_ICR_R    (*((volatile unsigned long *)0x4005C41C))
#define GPIO_PORTE_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005C420))
#define GPIO_PORTE_AHB_DR2R_R   (*((volatile unsigned long *)0x4005C500))
#define GPIO_PORTE_AHB_DR4R_R   (*((volatile unsigned long *)0x4005C504))
#define GPIO_PORTE_AHB_DR8R_R   (*((volatile unsigned long *)0x4005C508))
#define GPIO_PORTE_AHB_ODR_R    (*((volatile unsigned long *)0x4005C50C))
#define GPIO_PORTE_AHB_PUR_R    (*((volatile unsigned long *)0x4005C510))
#define GPIO_PORTE_AHB_PDR_R    (*((volatile unsigned long *)0x4005C514))
#define GPIO_PORTE_AHB_SLR_R    (*((volatile unsigned long *)0x4005C518))
#define GPIO_PORTE_AHB_DEN_R    (*((volatile unsigned long *)0x4005C51C))
#define GPIO_PORTE_AHB_LOCK_R   (*((volatile unsigned long *)0x4005C520))
#define GPIO_PORTE_AHB_CR_R     (*((volatile unsigned long *)0x4005C524))
#define GPIO_PORTE_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005C528))
#define GPIO_PORTE_AHB_PCTL_R   (*((volatile unsigned long *)0x4005C52C))

//*****************************************************************************
//
// GPIO registers (PORTF AHB)
//
//*****************************************************************************
#define GPIO_PORTF_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005D000)
#define GPIO_PORTF_AHB_DATA_R   (*((volatile unsigned long *)0x4005D3FC))
#define GPIO_PORTF_AHB_DIR_R    (*((volatile unsigned long *)0x4005D400))
#define GPIO_PORTF_AHB_IS_R     (*((volatile unsigned long *)0x4005D404))
#define GPIO_PORTF_AHB_IBE_R    (*((volatile unsigned long *)0x4005D408))
#define GPIO_PORTF_AHB_IEV_R    (*((volatile unsigned long *)0x4005D40C))
#define GPIO_PORTF_AHB_IM_R     (*((volatile unsigned long *)0x4005D410))
#define GPIO_PORTF_AHB_RIS_R    (*((volatile unsigned long *)0x4005D414))
#define GPIO_PORTF_AHB_MIS_R    (*((volatile unsigned long *)0x4005D418))
#define GPIO_PORTF_AHB_ICR_R    (*((volatile unsigned long *)0x4005D41C))
#define GPIO_PORTF_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005D420))
#define GPIO_PORTF_AHB_DR2R_R   (*((volatile unsigned long *)0x4005D500))
#define GPIO_PORTF_AHB_DR4R_R   (*((volatile unsigned long *)0x4005D504))
#define GPIO_PORTF_AHB_DR8R_R   (*((volatile unsigned long *)0x4005D508))
#define GPIO_PORTF_AHB_ODR_R    (*((volatile unsigned long *)0x4005D50C))
#define GPIO_PORTF_AHB_PUR_R    (*((volatile unsigned long *)0x4005D510))
#define GPIO_PORTF_AHB_PDR_R    (*((volatile unsigned long *)0x4005D514))
#define GPIO_PORTF_AHB_SLR_R    (*((volatile unsigned long *)0x4005D518))
#define GPIO_PORTF_AHB_DEN_R    (*((volatile unsigned long *)0x4005D51C))
#define GPIO_PORTF_AHB_LOCK_R   (*((volatile unsigned long *)0x4005D520))
#define GPIO_PORTF_AHB_CR_R     (*((volatile unsigned long *)0x4005D524))
#define GPIO_PORTF_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005D528))
#define GPIO_PORTF_AHB_PCTL_R   (*((volatile unsigned long *)0x4005D52C))

//*****************************************************************************
//
// GPIO registers (PORTG AHB)
//
//*****************************************************************************
#define GPIO_PORTG_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005E000)
#define GPIO_PORTG_AHB_DATA_R   (*((volatile unsigned long *)0x4005E3FC))
#define GPIO_PORTG_AHB_DIR_R    (*((volatile unsigned long *)0x4005E400))
#define GPIO_PORTG_AHB_IS_R     (*((volatile unsigned long *)0x4005E404))
#define GPIO_PORTG_AHB_IBE_R    (*((volatile unsigned long *)0x4005E408))
#define GPIO_PORTG_AHB_IEV_R    (*((volatile unsigned long *)0x4005E40C))
#define GPIO_PORTG_AHB_IM_R     (*((volatile unsigned long *)0x4005E410))
#define GPIO_PORTG_AHB_RIS_R    (*((volatile unsigned long *)0x4005E414))
#define GPIO_PORTG_AHB_MIS_R    (*((volatile unsigned long *)0x4005E418))
#define GPIO_PORTG_AHB_ICR_R    (*((volatile unsigned long *)0x4005E41C))
#define GPIO_PORTG_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005E420))
#define GPIO_PORTG_AHB_DR2R_R   (*((volatile unsigned long *)0x4005E500))
#define GPIO_PORTG_AHB_DR4R_R   (*((volatile unsigned long *)0x4005E504))
#define GPIO_PORTG_AHB_DR8R_R   (*((volatile unsigned long *)0x4005E508))
#define GPIO_PORTG_AHB_ODR_R    (*((volatile unsigned long *)0x4005E50C))
#define GPIO_PORTG_AHB_PUR_R    (*((volatile unsigned long *)0x4005E510))
#define GPIO_PORTG_AHB_PDR_R    (*((volatile unsigned long *)0x4005E514))
#define GPIO_PORTG_AHB_SLR_R    (*((volatile unsigned long *)0x4005E518))
#define GPIO_PORTG_AHB_DEN_R    (*((volatile unsigned long *)0x4005E51C))
#define GPIO_PORTG_AHB_LOCK_R   (*((volatile unsigned long *)0x4005E520))
#define GPIO_PORTG_AHB_CR_R     (*((volatile unsigned long *)0x4005E524))
#define GPIO_PORTG_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005E528))
#define GPIO_PORTG_AHB_PCTL_R   (*((volatile unsigned long *)0x4005E52C))

//*****************************************************************************
//
// GPIO registers (PORTH AHB)
//
//*****************************************************************************
#define GPIO_PORTH_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x4005F000)
#define GPIO_PORTH_AHB_DATA_R   (*((volatile unsigned long *)0x4005F3FC))
#define GPIO_PORTH_AHB_DIR_R    (*((volatile unsigned long *)0x4005F400))
#define GPIO_PORTH_AHB_IS_R     (*((volatile unsigned long *)0x4005F404))
#define GPIO_PORTH_AHB_IBE_R    (*((volatile unsigned long *)0x4005F408))
#define GPIO_PORTH_AHB_IEV_R    (*((volatile unsigned long *)0x4005F40C))
#define GPIO_PORTH_AHB_IM_R     (*((volatile unsigned long *)0x4005F410))
#define GPIO_PORTH_AHB_RIS_R    (*((volatile unsigned long *)0x4005F414))
#define GPIO_PORTH_AHB_MIS_R    (*((volatile unsigned long *)0x4005F418))
#define GPIO_PORTH_AHB_ICR_R    (*((volatile unsigned long *)0x4005F41C))
#define GPIO_PORTH_AHB_AFSEL_R  (*((volatile unsigned long *)0x4005F420))
#define GPIO_PORTH_AHB_DR2R_R   (*((volatile unsigned long *)0x4005F500))
#define GPIO_PORTH_AHB_DR4R_R   (*((volatile unsigned long *)0x4005F504))
#define GPIO_PORTH_AHB_DR8R_R   (*((volatile unsigned long *)0x4005F508))
#define GPIO_PORTH_AHB_ODR_R    (*((volatile unsigned long *)0x4005F50C))
#define GPIO_PORTH_AHB_PUR_R    (*((volatile unsigned long *)0x4005F510))
#define GPIO_PORTH_AHB_PDR_R    (*((volatile unsigned long *)0x4005F514))
#define GPIO_PORTH_AHB_SLR_R    (*((volatile unsigned long *)0x4005F518))
#define GPIO_PORTH_AHB_DEN_R    (*((volatile unsigned long *)0x4005F51C))
#define GPIO_PORTH_AHB_LOCK_R   (*((volatile unsigned long *)0x4005F520))
#define GPIO_PORTH_AHB_CR_R     (*((volatile unsigned long *)0x4005F524))
#define GPIO_PORTH_AHB_AMSEL_R  (*((volatile unsigned long *)0x4005F528))
#define GPIO_PORTH_AHB_PCTL_R   (*((volatile unsigned long *)0x4005F52C))

//*****************************************************************************
//
// Hibernation module registers (HIB)
//
//*****************************************************************************
#define HIB_RTCC_R              (*((volatile unsigned long *)0x400FC000))
#define HIB_RTCM0_R             (*((volatile unsigned long *)0x400FC004))
#define HIB_RTCM1_R             (*((volatile unsigned long *)0x400FC008))
#define HIB_RTCLD_R             (*((volatile unsigned long *)0x400FC00C))
#define HIB_CTL_R               (*((volatile unsigned long *)0x400FC010))
#define HIB_IM_R                (*((volatile unsigned long *)0x400FC014))
#define HIB_RIS_R               (*((volatile unsigned long *)0x400FC018))
#define HIB_MIS_R               (*((volatile unsigned long *)0x400FC01C))
#define HIB_IC_R                (*((volatile unsigned long *)0x400FC020))
#define HIB_RTCT_R              (*((volatile unsigned long *)0x400FC024))
#define HIB_DATA_R              (*((volatile unsigned long *)0x400FC030))

//*****************************************************************************
//
// GPIO registers (PORTJ AHB)
//
//*****************************************************************************
#define GPIO_PORTJ_AHB_DATA_BITS_R \
                                ((volatile unsigned long *)0x40060000)
#define GPIO_PORTJ_AHB_DATA_R   (*((volatile unsigned long *)0x400603FC))
#define GPIO_PORTJ_AHB_DIR_R    (*((volatile unsigned long *)0x40060400))
#define GPIO_PORTJ_AHB_IS_R     (*((volatile unsigned long *)0x40060404))
#define GPIO_PORTJ_AHB_IBE_R    (*((volatile unsigned long *)0x40060408))
#define GPIO_PORTJ_AHB_IEV_R    (*((volatile unsigned long *)0x4006040C))
#define GPIO_PORTJ_AHB_IM_R     (*((volatile unsigned long *)0x40060410))
#define GPIO_PORTJ_AHB_RIS_R    (*((volatile unsigned long *)0x40060414))
#define GPIO_PORTJ_AHB_MIS_R    (*((volatile unsigned long *)0x40060418))
#define GPIO_PORTJ_AHB_ICR_R    (*((volatile unsigned long *)0x4006041C))
#define GPIO_PORTJ_AHB_AFSEL_R  (*((volatile unsigned long *)0x40060420))
#define GPIO_PORTJ_AHB_DR2R_R   (*((volatile unsigned long *)0x40060500))
#define GPIO_PORTJ_AHB_DR4R_R   (*((volatile unsigned long *)0x40060504))
#define GPIO_PORTJ_AHB_DR8R_R   (*((volatile unsigned long *)0x40060508))
#define GPIO_PORTJ_AHB_ODR_R    (*((volatile unsigned long *)0x4006050C))
#define GPIO_PORTJ_AHB_PUR_R    (*((volatile unsigned long *)0x40060510))
#define GPIO_PORTJ_AHB_PDR_R    (*((volatile unsigned long *)0x40060514))
#define GPIO_PORTJ_AHB_SLR_R    (*((volatile unsigned long *)0x40060518))
#define GPIO_PORTJ_AHB_DEN_R    (*((volatile unsigned long *)0x4006051C))
#define GPIO_PORTJ_AHB_LOCK_R   (*((volatile unsigned long *)0x40060520))
#define GPIO_PORTJ_AHB_CR_R     (*((volatile unsigned long *)0x40060524))
#define GPIO_PORTJ_AHB_AMSEL_R  (*((volatile unsigned long *)0x40060528))
#define GPIO_PORTJ_AHB_PCTL_R   (*((volatile unsigned long *)0x4006052C))

//*****************************************************************************
//
// External Peripheral Interface registers (EPI0)
//
//*****************************************************************************
#define EPI0_CFG_R              (*((volatile unsigned long *)0x400D0000))
#define EPI0_BAUD_R             (*((volatile unsigned long *)0x400D0004))
#define EPI0_HB16CFG_R          (*((volatile unsigned long *)0x400D0010))
#define EPI0_GPCFG_R            (*((volatile unsigned long *)0x400D0010))
#define EPI0_SDRAMCFG_R         (*((volatile unsigned long *)0x400D0010))
#define EPI0_HB8CFG_R           (*((volatile unsigned long *)0x400D0010))
#define EPI0_HB8CFG2_R          (*((volatile unsigned long *)0x400D0014))
#define EPI0_HB16CFG2_R         (*((volatile unsigned long *)0x400D0014))
#define EPI0_GPCFG2_R           (*((volatile unsigned long *)0x400D0014))
#define EPI0_ADDRMAP_R          (*((volatile unsigned long *)0x400D001C))
#define EPI0_RSIZE0_R           (*((volatile unsigned long *)0x400D0020))
#define EPI0_RADDR0_R           (*((volatile unsigned long *)0x400D0024))
#define EPI0_RPSTD0_R           (*((volatile unsigned long *)0x400D0028))
#define EPI0_RSIZE1_R           (*((volatile unsigned long *)0x400D0030))
#define EPI0_RADDR1_R           (*((volatile unsigned long *)0x400D0034))
#define EPI0_RPSTD1_R           (*((volatile unsigned long *)0x400D0038))
#define EPI0_STAT_R             (*((volatile unsigned long *)0x400D0060))
#define EPI0_RFIFOCNT_R         (*((volatile unsigned long *)0x400D006C))
#define EPI0_READFIFO_R         (*((volatile unsigned long *)0x400D0070))
#define EPI0_READFIFO1_R        (*((volatile unsigned long *)0x400D0074))
#define EPI0_READFIFO2_R        (*((volatile unsigned long *)0x400D0078))
#define EPI0_READFIFO3_R        (*((volatile unsigned long *)0x400D007C))
#define EPI0_READFIFO4_R        (*((volatile unsigned long *)0x400D0080))
#define EPI0_READFIFO5_R        (*((volatile unsigned long *)0x400D0084))
#define EPI0_READFIFO6_R        (*((volatile unsigned long *)0x400D0088))
#define EPI0_READFIFO7_R        (*((volatile unsigned long *)0x400D008C))
#define EPI0_FIFOLVL_R          (*((volatile unsigned long *)0x400D0200))
#define EPI0_WFIFOCNT_R         (*((volatile unsigned long *)0x400D0204))
#define EPI0_IM_R               (*((volatile unsigned long *)0x400D0210))
#define EPI0_RIS_R              (*((volatile unsigned long *)0x400D0214))
#define EPI0_MIS_R              (*((volatile unsigned long *)0x400D0218))
#define EPI0_EISC_R             (*((volatile unsigned long *)0x400D021C))

//*****************************************************************************
//
// FLASH registers (FLASH CTRL)
//
//*****************************************************************************
#define FLASH_FMA_R             (*((volatile unsigned long *)0x400FD000))
#define FLASH_FMD_R             (*((volatile unsigned long *)0x400FD004))
#define FLASH_FMC_R             (*((volatile unsigned long *)0x400FD008))
#define FLASH_FCRIS_R           (*((volatile unsigned long *)0x400FD00C))
#define FLASH_FCIM_R            (*((volatile unsigned long *)0x400FD010))
#define FLASH_FCMISC_R          (*((volatile unsigned long *)0x400FD014))
#define FLASH_FMC2_R            (*((volatile unsigned long *)0x400FD020))
#define FLASH_FWBVAL_R          (*((volatile unsigned long *)0x400FD030))
#define FLASH_FCTL_R            (*((volatile unsigned long *)0x400FD0F8))
#define FLASH_FWBN_R            (*((volatile unsigned long *)0x400FD100))
#define FLASH_BOOTCFG_R         (*((volatile unsigned long *)0x400FD1D0))
#define FLASH_RMCTL_R           (*((volatile unsigned long *)0x400FE0F0))
#define FLASH_RMVER_R           (*((volatile unsigned long *)0x400FE0F4))
#define FLASH_USERDBG_R         (*((volatile unsigned long *)0x400FE1D0))
#define FLASH_USERREG0_R        (*((volatile unsigned long *)0x400FE1E0))
#define FLASH_USERREG1_R        (*((volatile unsigned long *)0x400FE1E4))
#define FLASH_USERREG2_R        (*((volatile unsigned long *)0x400FE1E8))
#define FLASH_USERREG3_R        (*((volatile unsigned long *)0x400FE1EC))
#define FLASH_FMPRE0_R          (*((volatile unsigned long *)0x400FE200))
#define FLASH_FMPRE1_R          (*((volatile unsigned long *)0x400FE204))
#define FLASH_FMPRE2_R          (*((volatile unsigned long *)0x400FE208))
#define FLASH_FMPRE3_R          (*((volatile unsigned long *)0x400FE20C))
#define FLASH_FMPPE0_R          (*((volatile unsigned long *)0x400FE400))
#define FLASH_FMPPE1_R          (*((volatile unsigned long *)0x400FE404))
#define FLASH_FMPPE2_R          (*((volatile unsigned long *)0x400FE408))
#define FLASH_FMPPE3_R          (*((volatile unsigned long *)0x400FE40C))

//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_DID0_R           (*((volatile unsigned long *)0x400FE000))
#define SYSCTL_DID1_R           (*((volatile unsigned long *)0x400FE004))
#define SYSCTL_DC0_R            (*((volatile unsigned long *)0x400FE008))
#define SYSCTL_DC1_R            (*((volatile unsigned long *)0x400FE010))
#define SYSCTL_DC2_R            (*((volatile unsigned long *)0x400FE014))
#define SYSCTL_DC3_R            (*((volatile unsigned long *)0x400FE018))
#define SYSCTL_DC4_R            (*((volatile unsigned long *)0x400FE01C))
#define SYSCTL_DC5_R            (*((volatile unsigned long *)0x400FE020))
#define SYSCTL_DC6_R            (*((volatile unsigned long *)0x400FE024))
#define SYSCTL_DC7_R            (*((volatile unsigned long *)0x400FE028))
#define SYSCTL_DC8_R            (*((volatile unsigned long *)0x400FE02C))
#define SYSCTL_PBORCTL_R        (*((volatile unsigned long *)0x400FE030))
#define SYSCTL_SRCR0_R          (*((volatile unsigned long *)0x400FE040))
#define SYSCTL_SRCR1_R          (*((volatile unsigned long *)0x400FE044))
#define SYSCTL_SRCR2_R          (*((volatile unsigned long *)0x400FE048))
#define SYSCTL_RIS_R            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_IMC_R            (*((volatile unsigned long *)0x400FE054))
#define SYSCTL_MISC_R           (*((volatile unsigned long *)0x400FE058))
#define SYSCTL_RESC_R           (*((volatile unsigned long *)0x400FE05C))
#define SYSCTL_RCC_R            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_PLLCFG_R         (*((volatile unsigned long *)0x400FE064))
#define SYSCTL_GPIOHBCTL_R      (*((volatile unsigned long *)0x400FE06C))
#define SYSCTL_RCC2_R           (*((volatile unsigned long *)0x400FE070))
#define SYSCTL_MOSCCTL_R        (*((volatile unsigned long *)0x400FE07C))
#define SYSCTL_RCGC0_R          (*((volatile unsigned long *)0x400FE100))
#define SYSCTL_RCGC1_R          (*((volatile unsigned long *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_SCGC0_R          (*((volatile unsigned long *)0x400FE110))
#define SYSCTL_SCGC1_R          (*((volatile unsigned long *)0x400FE114))
#define SYSCTL_SCGC2_R          (*((volatile unsigned long *)0x400FE118))
#define SYSCTL_DCGC0_R          (*((volatile unsigned long *)0x400FE120))
#define SYSCTL_DCGC1_R          (*((volatile unsigned long *)0x400FE124))
#define SYSCTL_DCGC2_R          (*((volatile unsigned long *)0x400FE128))
#define SYSCTL_DSLPCLKCFG_R     (*((volatile unsigned long *)0x400FE144))
#define SYSCTL_PIOSCCAL_R       (*((volatile unsigned long *)0x400FE150))
#define SYSCTL_PIOSCSTAT_R      (*((volatile unsigned long *)0x400FE154))
#define SYSCTL_I2SMCLKCFG_R     (*((volatile unsigned long *)0x400FE170))
#define SYSCTL_DC9_R            (*((volatile unsigned long *)0x400FE190))
#define SYSCTL_NVMSTAT_R        (*((volatile unsigned long *)0x400FE1A0))

//*****************************************************************************
//
// Micro Direct Memory Access registers (UDMA)
//
//*****************************************************************************
#define UDMA_STAT_R             (*((volatile unsigned long *)0x400FF000))
#define UDMA_CFG_R              (*((volatile unsigned long *)0x400FF004))
#define UDMA_CTLBASE_R          (*((volatile unsigned long *)0x400FF008))
#define UDMA_ALTBASE_R          (*((volatile unsigned long *)0x400FF00C))
#define UDMA_WAITSTAT_R         (*((volatile unsigned long *)0x400FF010))
#define UDMA_SWREQ_R            (*((volatile unsigned long *)0x400FF014))
#define UDMA_USEBURSTSET_R      (*((volatile unsigned long *)0x400FF018))
#define UDMA_USEBURSTCLR_R      (*((volatile unsigned long *)0x400FF01C))
#define UDMA_REQMASKSET_R       (*((volatile unsigned long *)0x400FF020))
#define UDMA_REQMASKCLR_R       (*((volatile unsigned long *)0x400FF024))
#define UDMA_ENASET_R           (*((volatile unsigned long *)0x400FF028))
#define UDMA_ENACLR_R           (*((volatile unsigned long *)0x400FF02C))
#define UDMA_ALTSET_R           (*((volatile unsigned long *)0x400FF030))
#define UDMA_ALTCLR_R           (*((volatile unsigned long *)0x400FF034))
#define UDMA_PRIOSET_R          (*((volatile unsigned long *)0x400FF038))
#define UDMA_PRIOCLR_R          (*((volatile unsigned long *)0x400FF03C))
#define UDMA_ERRCLR_R           (*((volatile unsigned long *)0x400FF04C))
#define UDMA_CHALT_R            (*((volatile unsigned long *)0x400FF500))

//*****************************************************************************
//
// Micro Direct Memory Access (uDMA) offsets (UDMA)
//
//*****************************************************************************
#define UDMA_SRCENDP            0x00000000  // DMA Channel Source Address End
                                            // Pointer
#define UDMA_DSTENDP            0x00000004  // DMA Channel Destination Address
                                            // End Pointer
#define UDMA_CHCTL              0x00000008  // DMA Channel Control Word

//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_INT_TYPE_R         (*((volatile unsigned long *)0xE000E004))
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CAL_R           (*((volatile unsigned long *)0xE000E01C))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_R              (*((volatile unsigned long *)0xE000E104))
#define NVIC_DIS0_R             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_R             (*((volatile unsigned long *)0xE000E184))
#define NVIC_PEND0_R            (*((volatile unsigned long *)0xE000E200))
#define NVIC_PEND1_R            (*((volatile unsigned long *)0xE000E204))
#define NVIC_UNPEND0_R          (*((volatile unsigned long *)0xE000E280))
#define NVIC_UNPEND1_R          (*((volatile unsigned long *)0xE000E284))
#define NVIC_ACTIVE0_R          (*((volatile unsigned long *)0xE000E300))
#define NVIC_ACTIVE1_R          (*((volatile unsigned long *)0xE000E304))
#define NVIC_PRI0_R             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_R             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_R             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_R             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_R             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_R             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_R             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_R             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_R             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_R            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_R            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_R            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_R            (*((volatile unsigned long *)0xE000E434))
#define NVIC_CPUID_R            (*((volatile unsigned long *)0xE000ED00))
#define NVIC_INT_CTRL_R         (*((volatile unsigned long *)0xE000ED04))
#define NVIC_VTABLE_R           (*((volatile unsigned long *)0xE000ED08))
#define NVIC_APINT_R            (*((volatile unsigned long *)0xE000ED0C))
#define NVIC_SYS_CTRL_R         (*((volatile unsigned long *)0xE000ED10))
#define NVIC_CFG_CTRL_R         (*((volatile unsigned long *)0xE000ED14))
#define NVIC_SYS_PRI1_R         (*((volatile unsigned long *)0xE000ED18))
#define NVIC_SYS_PRI2_R         (*((volatile unsigned long *)0xE000ED1C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))
#define NVIC_SYS_HND_CTRL_R     (*((volatile unsigned long *)0xE000ED24))
#define NVIC_FAULT_STAT_R       (*((volatile unsigned long *)0xE000ED28))
#define NVIC_HFAULT_STAT_R      (*((volatile unsigned long *)0xE000ED2C))
#define NVIC_DEBUG_STAT_R       (*((volatile unsigned long *)0xE000ED30))
#define NVIC_MM_ADDR_R          (*((volatile unsigned long *)0xE000ED34))
#define NVIC_FAULT_ADDR_R       (*((volatile unsigned long *)0xE000ED38))
#define NVIC_MPU_TYPE_R         (*((volatile unsigned long *)0xE000ED90))
#define NVIC_MPU_CTRL_R         (*((volatile unsigned long *)0xE000ED94))
#define NVIC_MPU_NUMBER_R       (*((volatile unsigned long *)0xE000ED98))
#define NVIC_MPU_BASE_R         (*((volatile unsigned long *)0xE000ED9C))
#define NVIC_MPU_ATTR_R         (*((volatile unsigned long *)0xE000EDA0))
#define NVIC_DBG_CTRL_R         (*((volatile unsigned long *)0xE000EDF0))
#define NVIC_DBG_XFER_R         (*((volatile unsigned long *)0xE000EDF4))
#define NVIC_DBG_DATA_R         (*((volatile unsigned long *)0xE000EDF8))
#define NVIC_DBG_INT_R          (*((volatile unsigned long *)0xE000EDFC))
#define NVIC_SW_TRIG_R          (*((volatile unsigned long *)0xE000EF00))

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOAD register.
//
//*****************************************************************************
#define WDT_LOAD_M              0xFFFFFFFF  // Watchdog Load Value
#define WDT_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_VALUE register.
//
//*****************************************************************************
#define WDT_VALUE_M             0xFFFFFFFF  // Watchdog Value
#define WDT_VALUE_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_CTL register.
//
//*****************************************************************************
#define WDT_CTL_WRC             0x80000000  // Write Complete
#define WDT_CTL_RESEN           0x00000002  // Watchdog Reset Enable
#define WDT_CTL_INTEN           0x00000001  // Watchdog Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_ICR register.
//
//*****************************************************************************
#define WDT_ICR_M               0xFFFFFFFF  // Watchdog Interrupt Clear
#define WDT_ICR_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_RIS register.
//
//*****************************************************************************
#define WDT_RIS_WDTRIS          0x00000001  // Watchdog Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_MIS register.
//
//*****************************************************************************
#define WDT_MIS_WDTMIS          0x00000001  // Watchdog Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_TEST register.
//
//*****************************************************************************
#define WDT_TEST_STALL          0x00000100  // Watchdog Stall Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOCK register.
//
//*****************************************************************************
#define WDT_LOCK_M              0xFFFFFFFF  // Watchdog Lock
#define WDT_LOCK_UNLOCKED       0x00000000  // Unlocked
#define WDT_LOCK_LOCKED         0x00000001  // Locked
#define WDT_LOCK_UNLOCK         0x1ACCE551  // Unlocks the watchdog timer

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_LOCK register.
//
//*****************************************************************************
#define GPIO_LOCK_M             0xFFFFFFFF  // GPIO Lock
#define GPIO_LOCK_UNLOCKED      0x00000000  // The GPIOCR register is unlocked
                                            // and may be modified
#define GPIO_LOCK_LOCKED        0x00000001  // The GPIOCR register is locked
                                            // and may not be modified
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port A.
//
//*****************************************************************************
#define GPIO_PCTL_PA0_M         0x0000000F  // PA0 mask
#define GPIO_PCTL_PA0_U0RX      0x00000001  // U0RX on PA0
#define GPIO_PCTL_PA0_I2C1SCL   0x00000008  // I2C1SCL on PA0
#define GPIO_PCTL_PA0_U1RX      0x00000009  // U1RX on PA0
#define GPIO_PCTL_PA1_M         0x000000F0  // PA1 mask
#define GPIO_PCTL_PA1_U0TX      0x00000010  // U0TX on PA1
#define GPIO_PCTL_PA1_I2C1SDA   0x00000080  // I2C1SDA on PA1
#define GPIO_PCTL_PA1_U1TX      0x00000090  // U1TX on PA1
#define GPIO_PCTL_PA2_M         0x00000F00  // PA2 mask
#define GPIO_PCTL_PA2_SSI0CLK   0x00000100  // SSI0CLK on PA2
#define GPIO_PCTL_PA2_I2S0RXSD  0x00000900  // I2S0RXSD on PA2
#define GPIO_PCTL_PA3_M         0x0000F000  // PA3 mask
#define GPIO_PCTL_PA3_SSI0FSS   0x00001000  // SSI0FSS on PA3
#define GPIO_PCTL_PA3_I2S0RXMCLK \
                                0x00009000  // I2S0RXMCLK on PA3
#define GPIO_PCTL_PA4_M         0x000F0000  // PA4 mask
#define GPIO_PCTL_PA4_SSI0RX    0x00010000  // SSI0RX on PA4
#define GPIO_PCTL_PA4_CAN0RX    0x00050000  // CAN0RX on PA4
#define GPIO_PCTL_PA4_I2S0TXSCK 0x00090000  // I2S0TXSCK on PA4
#define GPIO_PCTL_PA5_M         0x00F00000  // PA5 mask
#define GPIO_PCTL_PA5_SSI0TX    0x00100000  // SSI0TX on PA5
#define GPIO_PCTL_PA5_CAN0TX    0x00500000  // CAN0TX on PA5
#define GPIO_PCTL_PA5_I2S0TXWS  0x00900000  // I2S0TXWS on PA5
#define GPIO_PCTL_PA6_M         0x0F000000  // PA6 mask
#define GPIO_PCTL_PA6_I2C1SCL   0x01000000  // I2C1SCL on PA6
#define GPIO_PCTL_PA6_CCP1      0x02000000  // CCP1 on PA6
#define GPIO_PCTL_PA6_CAN0RX    0x06000000  // CAN0RX on PA6
#define GPIO_PCTL_PA6_USB0EPEN  0x08000000  // USB0EPEN on PA6
#define GPIO_PCTL_PA6_U1CTS     0x09000000  // U1CTS on PA6
#define GPIO_PCTL_PA7_M         0xF0000000  // PA7 mask
#define GPIO_PCTL_PA7_I2C1SDA   0x10000000  // I2C1SDA on PA7
#define GPIO_PCTL_PA7_CCP4      0x20000000  // CCP4 on PA7
#define GPIO_PCTL_PA7_CAN0TX    0x60000000  // CAN0TX on PA7
#define GPIO_PCTL_PA7_CCP3      0x70000000  // CCP3 on PA7
#define GPIO_PCTL_PA7_USB0PFLT  0x80000000  // USB0PFLT on PA7
#define GPIO_PCTL_PA7_U1DCD     0x90000000  // U1DCD on PA7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port B.
//
//*****************************************************************************
#define GPIO_PCTL_PB0_M         0x0000000F  // PB0 mask
#define GPIO_PCTL_PB0_CCP0      0x00000001  // CCP0 on PB0
#define GPIO_PCTL_PB0_U1RX      0x00000005  // U1RX on PB0
#define GPIO_PCTL_PB1_M         0x000000F0  // PB1 mask
#define GPIO_PCTL_PB1_CCP2      0x00000010  // CCP2 on PB1
#define GPIO_PCTL_PB1_CCP1      0x00000040  // CCP1 on PB1
#define GPIO_PCTL_PB1_U1TX      0x00000050  // U1TX on PB1
#define GPIO_PCTL_PB2_M         0x00000F00  // PB2 mask
#define GPIO_PCTL_PB2_I2C0SCL   0x00000100  // I2C0SCL on PB2
#define GPIO_PCTL_PB2_CCP3      0x00000400  // CCP3 on PB2
#define GPIO_PCTL_PB2_CCP0      0x00000500  // CCP0 on PB2
#define GPIO_PCTL_PB2_USB0EPEN  0x00000800  // USB0EPEN on PB2
#define GPIO_PCTL_PB3_M         0x0000F000  // PB3 mask
#define GPIO_PCTL_PB3_I2C0SDA   0x00001000  // I2C0SDA on PB3
#define GPIO_PCTL_PB3_USB0PFLT  0x00008000  // USB0PFLT on PB3
#define GPIO_PCTL_PB4_M         0x000F0000  // PB4 mask
#define GPIO_PCTL_PB4_U2RX      0x00040000  // U2RX on PB4
#define GPIO_PCTL_PB4_CAN0RX    0x00050000  // CAN0RX on PB4
#define GPIO_PCTL_PB4_U1RX      0x00070000  // U1RX on PB4
#define GPIO_PCTL_PB4_EPI0S23   0x00080000  // EPI0S23 on PB4
#define GPIO_PCTL_PB5_M         0x00F00000  // PB5 mask
#define GPIO_PCTL_PB5_C0O       0x00100000  // C0O on PB5
#define GPIO_PCTL_PB5_CCP5      0x00200000  // CCP5 on PB5
#define GPIO_PCTL_PB5_CCP6      0x00300000  // CCP6 on PB5
#define GPIO_PCTL_PB5_CCP0      0x00400000  // CCP0 on PB5
#define GPIO_PCTL_PB5_CAN0TX    0x00500000  // CAN0TX on PB5
#define GPIO_PCTL_PB5_CCP2      0x00600000  // CCP2 on PB5
#define GPIO_PCTL_PB5_U1TX      0x00700000  // U1TX on PB5
#define GPIO_PCTL_PB5_EPI0S22   0x00800000  // EPI0S22 on PB5
#define GPIO_PCTL_PB6_M         0x0F000000  // PB6 mask
#define GPIO_PCTL_PB6_CCP1      0x01000000  // CCP1 on PB6
#define GPIO_PCTL_PB6_CCP7      0x02000000  // CCP7 on PB6
#define GPIO_PCTL_PB6_C0O       0x03000000  // C0O on PB6
#define GPIO_PCTL_PB6_CCP5      0x06000000  // CCP5 on PB6
#define GPIO_PCTL_PB6_I2S0TXSCK 0x09000000  // I2S0TXSCK on PB6
#define GPIO_PCTL_PB7_M         0xF0000000  // PB7 mask
#define GPIO_PCTL_PB7_NMI       0x40000000  // NMI on PB7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port C.
//
//*****************************************************************************
#define GPIO_PCTL_PC0_M         0x0000000F  // PC0 mask
#define GPIO_PCTL_PC0_TCK       0x00000003  // TCK on PC0
#define GPIO_PCTL_PC1_M         0x000000F0  // PC1 mask
#define GPIO_PCTL_PC1_TMS       0x00000030  // TMS on PC1
#define GPIO_PCTL_PC2_M         0x00000F00  // PC2 mask
#define GPIO_PCTL_PC2_TDI       0x00000300  // TDI on PC2
#define GPIO_PCTL_PC3_M         0x0000F000  // PC3 mask
#define GPIO_PCTL_PC3_TDO       0x00003000  // TDO on PC3
#define GPIO_PCTL_PC4_M         0x000F0000  // PC4 mask
#define GPIO_PCTL_PC4_CCP5      0x00010000  // CCP5 on PC4
#define GPIO_PCTL_PC4_CCP2      0x00050000  // CCP2 on PC4
#define GPIO_PCTL_PC4_CCP4      0x00060000  // CCP4 on PC4
#define GPIO_PCTL_PC4_EPI0S2    0x00080000  // EPI0S2 on PC4
#define GPIO_PCTL_PC4_CCP1      0x00090000  // CCP1 on PC4
#define GPIO_PCTL_PC5_M         0x00F00000  // PC5 mask
#define GPIO_PCTL_PC5_CCP1      0x00100000  // CCP1 on PC5
#define GPIO_PCTL_PC5_C1O       0x00200000  // C1O on PC5
#define GPIO_PCTL_PC5_C0O       0x00300000  // C0O on PC5
#define GPIO_PCTL_PC5_CCP3      0x00500000  // CCP3 on PC5
#define GPIO_PCTL_PC5_USB0EPEN  0x00600000  // USB0EPEN on PC5
#define GPIO_PCTL_PC5_EPI0S3    0x00800000  // EPI0S3 on PC5
#define GPIO_PCTL_PC6_M         0x0F000000  // PC6 mask
#define GPIO_PCTL_PC6_CCP3      0x01000000  // CCP3 on PC6
#define GPIO_PCTL_PC6_C2O       0x03000000  // C2O on PC6
#define GPIO_PCTL_PC6_U1RX      0x05000000  // U1RX on PC6
#define GPIO_PCTL_PC6_CCP0      0x06000000  // CCP0 on PC6
#define GPIO_PCTL_PC6_USB0PFLT  0x07000000  // USB0PFLT on PC6
#define GPIO_PCTL_PC6_EPI0S4    0x08000000  // EPI0S4 on PC6
#define GPIO_PCTL_PC7_M         0xF0000000  // PC7 mask
#define GPIO_PCTL_PC7_CCP4      0x10000000  // CCP4 on PC7
#define GPIO_PCTL_PC7_CCP0      0x40000000  // CCP0 on PC7
#define GPIO_PCTL_PC7_U1TX      0x50000000  // U1TX on PC7
#define GPIO_PCTL_PC7_USB0PFLT  0x60000000  // USB0PFLT on PC7
#define GPIO_PCTL_PC7_C1O       0x70000000  // C1O on PC7
#define GPIO_PCTL_PC7_EPI0S5    0x80000000  // EPI0S5 on PC7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port D.
//
//*****************************************************************************
#define GPIO_PCTL_PD0_M         0x0000000F  // PD0 mask
#define GPIO_PCTL_PD0_CAN0RX    0x00000002  // CAN0RX on PD0
#define GPIO_PCTL_PD0_U2RX      0x00000004  // U2RX on PD0
#define GPIO_PCTL_PD0_U1RX      0x00000005  // U1RX on PD0
#define GPIO_PCTL_PD0_CCP6      0x00000006  // CCP6 on PD0
#define GPIO_PCTL_PD0_I2S0RXSCK 0x00000008  // I2S0RXSCK on PD0
#define GPIO_PCTL_PD0_U1CTS     0x00000009  // U1CTS on PD0
#define GPIO_PCTL_PD1_M         0x000000F0  // PD1 mask
#define GPIO_PCTL_PD1_CAN0TX    0x00000020  // CAN0TX on PD1
#define GPIO_PCTL_PD1_U2TX      0x00000040  // U2TX on PD1
#define GPIO_PCTL_PD1_U1TX      0x00000050  // U1TX on PD1
#define GPIO_PCTL_PD1_CCP7      0x00000060  // CCP7 on PD1
#define GPIO_PCTL_PD1_I2S0RXWS  0x00000080  // I2S0RXWS on PD1
#define GPIO_PCTL_PD1_U1DCD     0x00000090  // U1DCD on PD1
#define GPIO_PCTL_PD1_CCP2      0x000000A0  // CCP2 on PD1
#define GPIO_PCTL_PD2_M         0x00000F00  // PD2 mask
#define GPIO_PCTL_PD2_U1RX      0x00000100  // U1RX on PD2
#define GPIO_PCTL_PD2_CCP6      0x00000200  // CCP6 on PD2
#define GPIO_PCTL_PD2_CCP5      0x00000400  // CCP5 on PD2
#define GPIO_PCTL_PD2_EPI0S20   0x00000800  // EPI0S20 on PD2
#define GPIO_PCTL_PD3_M         0x0000F000  // PD3 mask
#define GPIO_PCTL_PD3_U1TX      0x00001000  // U1TX on PD3
#define GPIO_PCTL_PD3_CCP7      0x00002000  // CCP7 on PD3
#define GPIO_PCTL_PD3_CCP0      0x00004000  // CCP0 on PD3
#define GPIO_PCTL_PD3_EPI0S21   0x00008000  // EPI0S21 on PD3
#define GPIO_PCTL_PD4_M         0x000F0000  // PD4 mask
#define GPIO_PCTL_PD4_CCP0      0x00010000  // CCP0 on PD4
#define GPIO_PCTL_PD4_CCP3      0x00020000  // CCP3 on PD4
#define GPIO_PCTL_PD4_I2S0RXSD  0x00080000  // I2S0RXSD on PD4
#define GPIO_PCTL_PD4_U1RI      0x00090000  // U1RI on PD4
#define GPIO_PCTL_PD4_EPI0S19   0x000A0000  // EPI0S19 on PD4
#define GPIO_PCTL_PD5_M         0x00F00000  // PD5 mask
#define GPIO_PCTL_PD5_CCP2      0x00100000  // CCP2 on PD5
#define GPIO_PCTL_PD5_CCP4      0x00200000  // CCP4 on PD5
#define GPIO_PCTL_PD5_I2S0RXMCLK \
                                0x00800000  // I2S0RXMCLK on PD5
#define GPIO_PCTL_PD5_U2RX      0x00900000  // U2RX on PD5
#define GPIO_PCTL_PD5_EPI0S28   0x00A00000  // EPI0S28 on PD5
#define GPIO_PCTL_PD6_M         0x0F000000  // PD6 mask
#define GPIO_PCTL_PD6_I2S0TXSCK 0x08000000  // I2S0TXSCK on PD6
#define GPIO_PCTL_PD6_U2TX      0x09000000  // U2TX on PD6
#define GPIO_PCTL_PD6_EPI0S29   0x0A000000  // EPI0S29 on PD6
#define GPIO_PCTL_PD7_M         0xF0000000  // PD7 mask
#define GPIO_PCTL_PD7_C0O       0x20000000  // C0O on PD7
#define GPIO_PCTL_PD7_CCP1      0x30000000  // CCP1 on PD7
#define GPIO_PCTL_PD7_I2S0TXWS  0x80000000  // I2S0TXWS on PD7
#define GPIO_PCTL_PD7_U1DTR     0x90000000  // U1DTR on PD7
#define GPIO_PCTL_PD7_EPI0S30   0xA0000000  // EPI0S30 on PD7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port E.
//
//*****************************************************************************
#define GPIO_PCTL_PE0_M         0x0000000F  // PE0 mask
#define GPIO_PCTL_PE0_SSI1CLK   0x00000002  // SSI1CLK on PE0
#define GPIO_PCTL_PE0_CCP3      0x00000003  // CCP3 on PE0
#define GPIO_PCTL_PE0_EPI0S8    0x00000008  // EPI0S8 on PE0
#define GPIO_PCTL_PE0_USB0PFLT  0x00000009  // USB0PFLT on PE0
#define GPIO_PCTL_PE1_M         0x000000F0  // PE1 mask
#define GPIO_PCTL_PE1_SSI1FSS   0x00000020  // SSI1FSS on PE1
#define GPIO_PCTL_PE1_CCP2      0x00000040  // CCP2 on PE1
#define GPIO_PCTL_PE1_CCP6      0x00000050  // CCP6 on PE1
#define GPIO_PCTL_PE1_EPI0S9    0x00000080  // EPI0S9 on PE1
#define GPIO_PCTL_PE2_M         0x00000F00  // PE2 mask
#define GPIO_PCTL_PE2_CCP4      0x00000100  // CCP4 on PE2
#define GPIO_PCTL_PE2_SSI1RX    0x00000200  // SSI1RX on PE2
#define GPIO_PCTL_PE2_CCP2      0x00000500  // CCP2 on PE2
#define GPIO_PCTL_PE2_EPI0S24   0x00000800  // EPI0S24 on PE2
#define GPIO_PCTL_PE3_M         0x0000F000  // PE3 mask
#define GPIO_PCTL_PE3_CCP1      0x00001000  // CCP1 on PE3
#define GPIO_PCTL_PE3_SSI1TX    0x00002000  // SSI1TX on PE3
#define GPIO_PCTL_PE3_CCP7      0x00005000  // CCP7 on PE3
#define GPIO_PCTL_PE3_EPI0S25   0x00008000  // EPI0S25 on PE3
#define GPIO_PCTL_PE4_M         0x000F0000  // PE4 mask
#define GPIO_PCTL_PE4_CCP3      0x00010000  // CCP3 on PE4
#define GPIO_PCTL_PE4_U2TX      0x00050000  // U2TX on PE4
#define GPIO_PCTL_PE4_CCP2      0x00060000  // CCP2 on PE4
#define GPIO_PCTL_PE4_I2S0TXWS  0x00090000  // I2S0TXWS on PE4
#define GPIO_PCTL_PE5_M         0x00F00000  // PE5 mask
#define GPIO_PCTL_PE5_CCP5      0x00100000  // CCP5 on PE5
#define GPIO_PCTL_PE5_I2S0TXSD  0x00900000  // I2S0TXSD on PE5
#define GPIO_PCTL_PE6_M         0x0F000000  // PE6 mask
#define GPIO_PCTL_PE6_C1O       0x02000000  // C1O on PE6
#define GPIO_PCTL_PE6_U1CTS     0x09000000  // U1CTS on PE6
#define GPIO_PCTL_PE7_M         0xF0000000  // PE7 mask
#define GPIO_PCTL_PE7_C2O       0x20000000  // C2O on PE7
#define GPIO_PCTL_PE7_U1DCD     0x90000000  // U1DCD on PE7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port F.
//
//*****************************************************************************
#define GPIO_PCTL_PF0_M         0x0000000F  // PF0 mask
#define GPIO_PCTL_PF0_CAN1RX    0x00000001  // CAN1RX on PF0
#define GPIO_PCTL_PF0_I2S0TXSD  0x00000008  // I2S0TXSD on PF0
#define GPIO_PCTL_PF0_U1DSR     0x00000009  // U1DSR on PF0
#define GPIO_PCTL_PF1_M         0x000000F0  // PF1 mask
#define GPIO_PCTL_PF1_CAN1TX    0x00000010  // CAN1TX on PF1
#define GPIO_PCTL_PF1_I2S0TXMCLK \
                                0x00000080  // I2S0TXMCLK on PF1
#define GPIO_PCTL_PF1_U1RTS     0x00000090  // U1RTS on PF1
#define GPIO_PCTL_PF1_CCP3      0x000000A0  // CCP3 on PF1
#define GPIO_PCTL_PF2_M         0x00000F00  // PF2 mask
#define GPIO_PCTL_PF2_LED1      0x00000100  // LED1 on PF2
#define GPIO_PCTL_PF2_SSI1CLK   0x00000900  // SSI1CLK on PF2
#define GPIO_PCTL_PF3_M         0x0000F000  // PF3 mask
#define GPIO_PCTL_PF3_LED0      0x00001000  // LED0 on PF3
#define GPIO_PCTL_PF3_SSI1FSS   0x00009000  // SSI1FSS on PF3
#define GPIO_PCTL_PF4_M         0x000F0000  // PF4 mask
#define GPIO_PCTL_PF4_CCP0      0x00010000  // CCP0 on PF4
#define GPIO_PCTL_PF4_C0O       0x00020000  // C0O on PF4
#define GPIO_PCTL_PF4_EPI0S12   0x00080000  // EPI0S12 on PF4
#define GPIO_PCTL_PF4_SSI1RX    0x00090000  // SSI1RX on PF4
#define GPIO_PCTL_PF5_M         0x00F00000  // PF5 mask
#define GPIO_PCTL_PF5_CCP2      0x00100000  // CCP2 on PF5
#define GPIO_PCTL_PF5_C1O       0x00200000  // C1O on PF5
#define GPIO_PCTL_PF5_EPI0S15   0x00800000  // EPI0S15 on PF5
#define GPIO_PCTL_PF5_SSI1TX    0x00900000  // SSI1TX on PF5

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port G.
//
//*****************************************************************************
#define GPIO_PCTL_PG0_M         0x0000000F  // PG0 mask
#define GPIO_PCTL_PG0_U2RX      0x00000001  // U2RX on PG0
#define GPIO_PCTL_PG0_I2C1SCL   0x00000003  // I2C1SCL on PG0
#define GPIO_PCTL_PG0_USB0EPEN  0x00000007  // USB0EPEN on PG0
#define GPIO_PCTL_PG0_EPI0S13   0x00000008  // EPI0S13 on PG0
#define GPIO_PCTL_PG1_M         0x000000F0  // PG1 mask
#define GPIO_PCTL_PG1_U2TX      0x00000010  // U2TX on PG1
#define GPIO_PCTL_PG1_I2C1SDA   0x00000030  // I2C1SDA on PG1
#define GPIO_PCTL_PG1_EPI0S14   0x00000080  // EPI0S14 on PG1
#define GPIO_PCTL_PG7_M         0xF0000000  // PG7 mask
#define GPIO_PCTL_PG7_CCP5      0x80000000  // CCP5 on PG7
#define GPIO_PCTL_PG7_EPI0S31   0x90000000  // EPI0S31 on PG7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port H.
//
//*****************************************************************************
#define GPIO_PCTL_PH0_M         0x0000000F  // PH0 mask
#define GPIO_PCTL_PH0_CCP6      0x00000001  // CCP6 on PH0
#define GPIO_PCTL_PH0_EPI0S6    0x00000008  // EPI0S6 on PH0
#define GPIO_PCTL_PH1_M         0x000000F0  // PH1 mask
#define GPIO_PCTL_PH1_CCP7      0x00000010  // CCP7 on PH1
#define GPIO_PCTL_PH1_EPI0S7    0x00000080  // EPI0S7 on PH1
#define GPIO_PCTL_PH2_M         0x00000F00  // PH2 mask
#define GPIO_PCTL_PH2_C1O       0x00000200  // C1O on PH2
#define GPIO_PCTL_PH2_EPI0S1    0x00000800  // EPI0S1 on PH2
#define GPIO_PCTL_PH3_M         0x0000F000  // PH3 mask
#define GPIO_PCTL_PH3_USB0EPEN  0x00004000  // USB0EPEN on PH3
#define GPIO_PCTL_PH3_EPI0S0    0x00008000  // EPI0S0 on PH3
#define GPIO_PCTL_PH4_M         0x000F0000  // PH4 mask
#define GPIO_PCTL_PH4_USB0PFLT  0x00040000  // USB0PFLT on PH4
#define GPIO_PCTL_PH4_EPI0S10   0x00080000  // EPI0S10 on PH4
#define GPIO_PCTL_PH4_SSI1CLK   0x000B0000  // SSI1CLK on PH4
#define GPIO_PCTL_PH5_M         0x00F00000  // PH5 mask
#define GPIO_PCTL_PH5_EPI0S11   0x00800000  // EPI0S11 on PH5
#define GPIO_PCTL_PH5_SSI1FSS   0x00B00000  // SSI1FSS on PH5
#define GPIO_PCTL_PH6_M         0x0F000000  // PH6 mask
#define GPIO_PCTL_PH6_EPI0S26   0x08000000  // EPI0S26 on PH6
#define GPIO_PCTL_PH6_SSI1RX    0x0B000000  // SSI1RX on PH6
#define GPIO_PCTL_PH7_M         0xF0000000  // PH7 mask
#define GPIO_PCTL_PH7_EPI0S27   0x80000000  // EPI0S27 on PH7
#define GPIO_PCTL_PH7_SSI1TX    0xB0000000  // SSI1TX on PH7

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_PCTL register for
// port J.
//
//*****************************************************************************
#define GPIO_PCTL_PJ0_M         0x0000000F  // PJ0 mask
#define GPIO_PCTL_PJ0_EPI0S16   0x00000008  // EPI0S16 on PJ0
#define GPIO_PCTL_PJ0_I2C1SCL   0x0000000B  // I2C1SCL on PJ0
#define GPIO_PCTL_PJ1_M         0x000000F0  // PJ1 mask
#define GPIO_PCTL_PJ1_EPI0S17   0x00000080  // EPI0S17 on PJ1
#define GPIO_PCTL_PJ1_USB0PFLT  0x00000090  // USB0PFLT on PJ1
#define GPIO_PCTL_PJ1_I2C1SDA   0x000000B0  // I2C1SDA on PJ1
#define GPIO_PCTL_PJ2_M         0x00000F00  // PJ2 mask
#define GPIO_PCTL_PJ2_EPI0S18   0x00000800  // EPI0S18 on PJ2
#define GPIO_PCTL_PJ2_CCP0      0x00000900  // CCP0 on PJ2

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CR0 register.
//
//*****************************************************************************
#define SSI_CR0_SCR_M           0x0000FF00  // SSI Serial Clock Rate
#define SSI_CR0_SPH             0x00000080  // SSI Serial Clock Phase
#define SSI_CR0_SPO             0x00000040  // SSI Serial Clock Polarity
#define SSI_CR0_FRF_M           0x00000030  // SSI Frame Format Select
#define SSI_CR0_FRF_MOTO        0x00000000  // Freescale SPI Frame Format
#define SSI_CR0_FRF_TI          0x00000010  // Texas Instruments Synchronous
                                            // Serial Frame Format
#define SSI_CR0_FRF_NMW         0x00000020  // MICROWIRE Frame Format
#define SSI_CR0_DSS_M           0x0000000F  // SSI Data Size Select
#define SSI_CR0_DSS_4           0x00000003  // 4-bit data
#define SSI_CR0_DSS_5           0x00000004  // 5-bit data
#define SSI_CR0_DSS_6           0x00000005  // 6-bit data
#define SSI_CR0_DSS_7           0x00000006  // 7-bit data
#define SSI_CR0_DSS_8           0x00000007  // 8-bit data
#define SSI_CR0_DSS_9           0x00000008  // 9-bit data
#define SSI_CR0_DSS_10          0x00000009  // 10-bit data
#define SSI_CR0_DSS_11          0x0000000A  // 11-bit data
#define SSI_CR0_DSS_12          0x0000000B  // 12-bit data
#define SSI_CR0_DSS_13          0x0000000C  // 13-bit data
#define SSI_CR0_DSS_14          0x0000000D  // 14-bit data
#define SSI_CR0_DSS_15          0x0000000E  // 15-bit data
#define SSI_CR0_DSS_16          0x0000000F  // 16-bit data
#define SSI_CR0_SCR_S           8

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CR1 register.
//
//*****************************************************************************
#define SSI_CR1_EOT             0x00000010  // End of Transmission
#define SSI_CR1_SOD             0x00000008  // SSI Slave Mode Output Disable
#define SSI_CR1_MS              0x00000004  // SSI Master/Slave Select
#define SSI_CR1_SSE             0x00000002  // SSI Synchronous Serial Port
                                            // Enable
#define SSI_CR1_LBM             0x00000001  // SSI Loopback Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_DR register.
//
//*****************************************************************************
#define SSI_DR_DATA_M           0x0000FFFF  // SSI Receive/Transmit Data
#define SSI_DR_DATA_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_SR register.
//
//*****************************************************************************
#define SSI_SR_BSY              0x00000010  // SSI Busy Bit
#define SSI_SR_RFF              0x00000008  // SSI Receive FIFO Full
#define SSI_SR_RNE              0x00000004  // SSI Receive FIFO Not Empty
#define SSI_SR_TNF              0x00000002  // SSI Transmit FIFO Not Full
#define SSI_SR_TFE              0x00000001  // SSI Transmit FIFO Empty

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CPSR register.
//
//*****************************************************************************
#define SSI_CPSR_CPSDVSR_M      0x000000FF  // SSI Clock Prescale Divisor
#define SSI_CPSR_CPSDVSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_IM register.
//
//*****************************************************************************
#define SSI_IM_TXIM             0x00000008  // SSI Transmit FIFO Interrupt Mask
#define SSI_IM_RXIM             0x00000004  // SSI Receive FIFO Interrupt Mask
#define SSI_IM_RTIM             0x00000002  // SSI Receive Time-Out Interrupt
                                            // Mask
#define SSI_IM_RORIM            0x00000001  // SSI Receive Overrun Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_RIS register.
//
//*****************************************************************************
#define SSI_RIS_TXRIS           0x00000008  // SSI Transmit FIFO Raw Interrupt
                                            // Status
#define SSI_RIS_RXRIS           0x00000004  // SSI Receive FIFO Raw Interrupt
                                            // Status
#define SSI_RIS_RTRIS           0x00000002  // SSI Receive Time-Out Raw
                                            // Interrupt Status
#define SSI_RIS_RORRIS          0x00000001  // SSI Receive Overrun Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_MIS register.
//
//*****************************************************************************
#define SSI_MIS_TXMIS           0x00000008  // SSI Transmit FIFO Masked
                                            // Interrupt Status
#define SSI_MIS_RXMIS           0x00000004  // SSI Receive FIFO Masked
                                            // Interrupt Status
#define SSI_MIS_RTMIS           0x00000002  // SSI Receive Time-Out Masked
                                            // Interrupt Status
#define SSI_MIS_RORMIS          0x00000001  // SSI Receive Overrun Masked
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_ICR register.
//
//*****************************************************************************
#define SSI_ICR_RTIC            0x00000002  // SSI Receive Time-Out Interrupt
                                            // Clear
#define SSI_ICR_RORIC           0x00000001  // SSI Receive Overrun Interrupt
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_DMACTL register.
//
//*****************************************************************************
#define SSI_DMACTL_TXDMAE       0x00000002  // Transmit DMA Enable
#define SSI_DMACTL_RXDMAE       0x00000001  // Receive DMA Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_DR register.
//
//*****************************************************************************
#define UART_DR_OE              0x00000800  // UART Overrun Error
#define UART_DR_BE              0x00000400  // UART Break Error
#define UART_DR_PE              0x00000200  // UART Parity Error
#define UART_DR_FE              0x00000100  // UART Framing Error
#define UART_DR_DATA_M          0x000000FF  // Data Transmitted or Received
#define UART_DR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_RSR register.
//
//*****************************************************************************
#define UART_RSR_OE             0x00000008  // UART Overrun Error
#define UART_RSR_BE             0x00000004  // UART Break Error
#define UART_RSR_PE             0x00000002  // UART Parity Error
#define UART_RSR_FE             0x00000001  // UART Framing Error

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ECR register.
//
//*****************************************************************************
#define UART_ECR_DATA_M         0x000000FF  // Error Clear
#define UART_ECR_DATA_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_FR register.
//
//*****************************************************************************
#define UART_FR_RI              0x00000100  // Ring Indicator
#define UART_FR_TXFE            0x00000080  // UART Transmit FIFO Empty
#define UART_FR_RXFF            0x00000040  // UART Receive FIFO Full
#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_FR_BUSY            0x00000008  // UART Busy
#define UART_FR_DCD             0x00000004  // Data Carrier Detect
#define UART_FR_DSR             0x00000002  // Data Set Ready
#define UART_FR_CTS             0x00000001  // Clear To Send

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ILPR register.
//
//*****************************************************************************
#define UART_ILPR_ILPDVSR_M     0x000000FF  // IrDA Low-Power Divisor
#define UART_ILPR_ILPDVSR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IBRD register.
//
//*****************************************************************************
#define UART_IBRD_DIVINT_M      0x0000FFFF  // Integer Baud-Rate Divisor
#define UART_IBRD_DIVINT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_FBRD register.
//
//*****************************************************************************
#define UART_FBRD_DIVFRAC_M     0x0000003F  // Fractional Baud-Rate Divisor
#define UART_FBRD_DIVFRAC_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_LCRH register.
//
//*****************************************************************************
#define UART_LCRH_SPS           0x00000080  // UART Stick Parity Select
#define UART_LCRH_WLEN_M        0x00000060  // UART Word Length
#define UART_LCRH_WLEN_5        0x00000000  // 5 bits (default)
#define UART_LCRH_WLEN_6        0x00000020  // 6 bits
#define UART_LCRH_WLEN_7        0x00000040  // 7 bits
#define UART_LCRH_WLEN_8        0x00000060  // 8 bits
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_LCRH_STP2          0x00000008  // UART Two Stop Bits Select
#define UART_LCRH_EPS           0x00000004  // UART Even Parity Select
#define UART_LCRH_PEN           0x00000002  // UART Parity Enable
#define UART_LCRH_BRK           0x00000001  // UART Send Break

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_CTL register.
//
//*****************************************************************************
#define UART_CTL_CTSEN          0x00008000  // Enable Clear To Send
#define UART_CTL_RTSEN          0x00004000  // Enable Request to Send
#define UART_CTL_RTS            0x00000800  // Request to Send
#define UART_CTL_DTR            0x00000400  // Data Terminal Ready
#define UART_CTL_RXE            0x00000200  // UART Receive Enable
#define UART_CTL_TXE            0x00000100  // UART Transmit Enable
#define UART_CTL_LBE            0x00000080  // UART Loop Back Enable
#define UART_CTL_LIN            0x00000040  // LIN Mode Enable
#define UART_CTL_HSE            0x00000020  // High-Speed Enable
#define UART_CTL_EOT            0x00000010  // End of Transmission
#define UART_CTL_SMART          0x00000008  // ISO 7816 Smart Card Support
#define UART_CTL_SIRLP          0x00000004  // UART SIR Low-Power Mode
#define UART_CTL_SIREN          0x00000002  // UART SIR Enable
#define UART_CTL_UARTEN         0x00000001  // UART Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IFLS register.
//
//*****************************************************************************
#define UART_IFLS_RX_M          0x00000038  // UART Receive Interrupt FIFO
                                            // Level Select
#define UART_IFLS_RX1_8         0x00000000  // RX FIFO >= 1/8 full
#define UART_IFLS_RX2_8         0x00000008  // RX FIFO >= 1/4 full
#define UART_IFLS_RX4_8         0x00000010  // RX FIFO >= 1/2 full (default)
#define UART_IFLS_RX6_8         0x00000018  // RX FIFO >= 3/4 full
#define UART_IFLS_RX7_8         0x00000020  // RX FIFO >= 7/8 full
#define UART_IFLS_TX_M          0x00000007  // UART Transmit Interrupt FIFO
                                            // Level Select
#define UART_IFLS_TX1_8         0x00000000  // TX FIFO <= 1/8 full
#define UART_IFLS_TX2_8         0x00000001  // TX FIFO <= 1/4 full
#define UART_IFLS_TX4_8         0x00000002  // TX FIFO <= 1/2 full (default)
#define UART_IFLS_TX6_8         0x00000003  // TX FIFO <= 3/4 full
#define UART_IFLS_TX7_8         0x00000004  // TX FIFO <= 7/8 full

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IM register.
//
//*****************************************************************************
#define UART_IM_LME5IM          0x00008000  // LIN Mode Edge 5 Interrupt Mask
#define UART_IM_LME1IM          0x00004000  // LIN Mode Edge 1 Interrupt Mask
#define UART_IM_LMSBIM          0x00002000  // LIN Mode Sync Break Interrupt
                                            // Mask
#define UART_IM_OEIM            0x00000400  // UART Overrun Error Interrupt
                                            // Mask
#define UART_IM_BEIM            0x00000200  // UART Break Error Interrupt Mask
#define UART_IM_PEIM            0x00000100  // UART Parity Error Interrupt Mask
#define UART_IM_FEIM            0x00000080  // UART Framing Error Interrupt
                                            // Mask
#define UART_IM_RTIM            0x00000040  // UART Receive Time-Out Interrupt
                                            // Mask
#define UART_IM_TXIM            0x00000020  // UART Transmit Interrupt Mask
#define UART_IM_RXIM            0x00000010  // UART Receive Interrupt Mask
#define UART_IM_DSRMIM          0x00000008  // UART Data Set Ready Modem
                                            // Interrupt Mask
#define UART_IM_DCDMIM          0x00000004  // UART Data Carrier Detect Modem
                                            // Interrupt Mask
#define UART_IM_CTSMIM          0x00000002  // UART Clear to Send Modem
                                            // Interrupt Mask
#define UART_IM_RIMIM           0x00000001  // UART Ring Indicator Modem
                                            // Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_RIS register.
//
//*****************************************************************************
#define UART_RIS_LME5RIS        0x00008000  // LIN Mode Edge 5 Raw Interrupt
                                            // Status
#define UART_RIS_LME1RIS        0x00004000  // LIN Mode Edge 1 Raw Interrupt
                                            // Status
#define UART_RIS_LMSBRIS        0x00002000  // LIN Mode Sync Break Raw
                                            // Interrupt Status
#define UART_RIS_OERIS          0x00000400  // UART Overrun Error Raw Interrupt
                                            // Status
#define UART_RIS_BERIS          0x00000200  // UART Break Error Raw Interrupt
                                            // Status
#define UART_RIS_PERIS          0x00000100  // UART Parity Error Raw Interrupt
                                            // Status
#define UART_RIS_FERIS          0x00000080  // UART Framing Error Raw Interrupt
                                            // Status
#define UART_RIS_RTRIS          0x00000040  // UART Receive Time-Out Raw
                                            // Interrupt Status
#define UART_RIS_TXRIS          0x00000020  // UART Transmit Raw Interrupt
                                            // Status
#define UART_RIS_RXRIS          0x00000010  // UART Receive Raw Interrupt
                                            // Status
#define UART_RIS_DSRRIS         0x00000008  // UART Data Set Ready Modem Raw
                                            // Interrupt Status
#define UART_RIS_DCDRIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Raw Interrupt Status
#define UART_RIS_CTSRIS         0x00000002  // UART Clear to Send Modem Raw
                                            // Interrupt Status
#define UART_RIS_RIRIS          0x00000001  // UART Ring Indicator Modem Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_MIS register.
//
//*****************************************************************************
#define UART_MIS_LME5MIS        0x00008000  // LIN Mode Edge 5 Masked Interrupt
                                            // Status
#define UART_MIS_LME1MIS        0x00004000  // LIN Mode Edge 1 Masked Interrupt
                                            // Status
#define UART_MIS_LMSBMIS        0x00002000  // LIN Mode Sync Break Masked
                                            // Interrupt Status
#define UART_MIS_OEMIS          0x00000400  // UART Overrun Error Masked
                                            // Interrupt Status
#define UART_MIS_BEMIS          0x00000200  // UART Break Error Masked
                                            // Interrupt Status
#define UART_MIS_PEMIS          0x00000100  // UART Parity Error Masked
                                            // Interrupt Status
#define UART_MIS_FEMIS          0x00000080  // UART Framing Error Masked
                                            // Interrupt Status
#define UART_MIS_RTMIS          0x00000040  // UART Receive Time-Out Masked
                                            // Interrupt Status
#define UART_MIS_TXMIS          0x00000020  // UART Transmit Masked Interrupt
                                            // Status
#define UART_MIS_RXMIS          0x00000010  // UART Receive Masked Interrupt
                                            // Status
#define UART_MIS_DSRMIS         0x00000008  // UART Data Set Ready Modem Masked
                                            // Interrupt Status
#define UART_MIS_DCDMIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Masked Interrupt Status
#define UART_MIS_CTSMIS         0x00000002  // UART Clear to Send Modem Masked
                                            // Interrupt Status
#define UART_MIS_RIMIS          0x00000001  // UART Ring Indicator Modem Masked
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ICR register.
//
//*****************************************************************************
#define UART_ICR_LME5MIC        0x00008000  // LIN Mode Edge 5 Interrupt Clear
#define UART_ICR_LME1MIC        0x00004000  // LIN Mode Edge 1 Interrupt Clear
#define UART_ICR_LMSBMIC        0x00002000  // LIN Mode Sync Break Interrupt
                                            // Clear
#define UART_ICR_OEIC           0x00000400  // Overrun Error Interrupt Clear
#define UART_ICR_BEIC           0x00000200  // Break Error Interrupt Clear
#define UART_ICR_PEIC           0x00000100  // Parity Error Interrupt Clear
#define UART_ICR_FEIC           0x00000080  // Framing Error Interrupt Clear
#define UART_ICR_RTIC           0x00000040  // Receive Time-Out Interrupt Clear
#define UART_ICR_TXIC           0x00000020  // Transmit Interrupt Clear
#define UART_ICR_RXIC           0x00000010  // Receive Interrupt Clear
#define UART_ICR_DSRMIC         0x00000008  // UART Data Set Ready Modem
                                            // Interrupt Clear
#define UART_ICR_DCDMIC         0x00000004  // UART Data Carrier Detect Modem
                                            // Interrupt Clear
#define UART_ICR_CTSMIC         0x00000002  // UART Clear to Send Modem
                                            // Interrupt Clear
#define UART_ICR_RIMIC          0x00000001  // UART Ring Indicator Modem
                                            // Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_DMACTL register.
//
//*****************************************************************************
#define UART_DMACTL_DMAERR      0x00000004  // DMA on Error
#define UART_DMACTL_TXDMAE      0x00000002  // Transmit DMA Enable
#define UART_DMACTL_RXDMAE      0x00000001  // Receive DMA Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_LCTL register.
//
//*****************************************************************************
#define UART_LCTL_BLEN_M        0x00000030  // Sync Break Length
#define UART_LCTL_BLEN_13T      0x00000000  // Sync break length is 13T bits
                                            // (default)
#define UART_LCTL_BLEN_14T      0x00000010  // Sync break length is 14T bits
#define UART_LCTL_BLEN_15T      0x00000020  // Sync break length is 15T bits
#define UART_LCTL_BLEN_16T      0x00000030  // Sync break length is 16T bits
#define UART_LCTL_MASTER        0x00000001  // LIN Master Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_LSS register.
//
//*****************************************************************************
#define UART_LSS_TSS_M          0x0000FFFF  // Timer Snap Shot
#define UART_LSS_TSS_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_LTIM register.
//
//*****************************************************************************
#define UART_LTIM_TIMER_M       0x0000FFFF  // Timer Value
#define UART_LTIM_TIMER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MSA register.
//
//*****************************************************************************
#define I2C_MSA_SA_M            0x000000FE  // I2C Slave Address
#define I2C_MSA_RS              0x00000001  // Receive not send
#define I2C_MSA_SA_S            1

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SOAR register.
//
//*****************************************************************************
#define I2C_SOAR_OAR_M          0x0000007F  // I2C Slave Own Address
#define I2C_SOAR_OAR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SCSR register.
//
//*****************************************************************************
#define I2C_SCSR_FBR            0x00000004  // First Byte Received
#define I2C_SCSR_TREQ           0x00000002  // Transmit Request
#define I2C_SCSR_DA             0x00000001  // Device Active
#define I2C_SCSR_RREQ           0x00000001  // Receive Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MCS register.
//
//*****************************************************************************
#define I2C_MCS_BUSBSY          0x00000040  // Bus Busy
#define I2C_MCS_IDLE            0x00000020  // I2C Idle
#define I2C_MCS_ARBLST          0x00000010  // Arbitration Lost
#define I2C_MCS_ACK             0x00000008  // Data Acknowledge Enable
#define I2C_MCS_DATACK          0x00000008  // Acknowledge Data
#define I2C_MCS_ADRACK          0x00000004  // Acknowledge Address
#define I2C_MCS_STOP            0x00000004  // Generate STOP
#define I2C_MCS_START           0x00000002  // Generate START
#define I2C_MCS_ERROR           0x00000002  // Error
#define I2C_MCS_RUN             0x00000001  // I2C Master Enable
#define I2C_MCS_BUSY            0x00000001  // I2C Busy

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SDR register.
//
//*****************************************************************************
#define I2C_SDR_DATA_M          0x000000FF  // Data for Transfer
#define I2C_SDR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MDR register.
//
//*****************************************************************************
#define I2C_MDR_DATA_M          0x000000FF  // Data Transferred
#define I2C_MDR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MTPR register.
//
//*****************************************************************************
#define I2C_MTPR_TPR_M          0x0000007F  // SCL Clock Period
#define I2C_MTPR_TPR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SIMR register.
//
//*****************************************************************************
#define I2C_SIMR_STOPIM         0x00000004  // Stop Condition Interrupt Mask
#define I2C_SIMR_STARTIM        0x00000002  // Start Condition Interrupt Mask
#define I2C_SIMR_DATAIM         0x00000001  // Data Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SRIS register.
//
//*****************************************************************************
#define I2C_SRIS_STOPRIS        0x00000004  // Stop Condition Raw Interrupt
                                            // Status
#define I2C_SRIS_STARTRIS       0x00000002  // Start Condition Raw Interrupt
                                            // Status
#define I2C_SRIS_DATARIS        0x00000001  // Data Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MIMR register.
//
//*****************************************************************************
#define I2C_MIMR_IM             0x00000001  // Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MRIS register.
//
//*****************************************************************************
#define I2C_MRIS_RIS            0x00000001  // Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SMIS register.
//
//*****************************************************************************
#define I2C_SMIS_STOPMIS        0x00000004  // Stop Condition Masked Interrupt
                                            // Status
#define I2C_SMIS_STARTMIS       0x00000002  // Start Condition Masked Interrupt
                                            // Status
#define I2C_SMIS_DATAMIS        0x00000001  // Data Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SICR register.
//
//*****************************************************************************
#define I2C_SICR_STOPIC         0x00000004  // Stop Condition Interrupt Clear
#define I2C_SICR_STARTIC        0x00000002  // Start Condition Interrupt Clear
#define I2C_SICR_DATAIC         0x00000001  // Data Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MMIS register.
//
//*****************************************************************************
#define I2C_MMIS_MIS            0x00000001  // Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MICR register.
//
//*****************************************************************************
#define I2C_MICR_IC             0x00000001  // Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MCR register.
//
//*****************************************************************************
#define I2C_MCR_SFE             0x00000020  // I2C Slave Function Enable
#define I2C_MCR_MFE             0x00000010  // I2C Master Function Enable
#define I2C_MCR_LPBK            0x00000001  // I2C Loopback

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CFG register.
//
//*****************************************************************************
#define TIMER_CFG_M             0x00000007  // GPTM Configuration
#define TIMER_CFG_32_BIT_TIMER  0x00000000  // 32-bit timer configuration
#define TIMER_CFG_32_BIT_RTC    0x00000001  // 32-bit real-time clock (RTC)
                                            // counter configuration
#define TIMER_CFG_16_BIT        0x00000004  // 16-bit timer configuration. The
                                            // function is controlled by bits
                                            // 1:0 of GPTMTAMR and GPTMTBMR

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMR register.
//
//*****************************************************************************
#define TIMER_TAMR_TASNAPS      0x00000080  // GPTM Timer A Snap-Shot Mode
#define TIMER_TAMR_TAWOT        0x00000040  // GPTM Timer A Wait-on-Trigger
#define TIMER_TAMR_TAMIE        0x00000020  // GPTM Timer A Match Interrupt
                                            // Enable
#define TIMER_TAMR_TACDIR       0x00000010  // GPTM Timer A Count Direction
#define TIMER_TAMR_TAAMS        0x00000008  // GPTM Timer A Alternate Mode
                                            // Select
#define TIMER_TAMR_TACMR        0x00000004  // GPTM Timer A Capture Mode
#define TIMER_TAMR_TAMR_M       0x00000003  // GPTM Timer A Mode
#define TIMER_TAMR_TAMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TAMR_TAMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMR register.
//
//*****************************************************************************
#define TIMER_TBMR_TBSNAPS      0x00000080  // GPTM Timer B Snap-Shot Mode
#define TIMER_TBMR_TBWOT        0x00000040  // GPTM Timer B Wait-on-Trigger
#define TIMER_TBMR_TBMIE        0x00000020  // GPTM Timer B Match Interrupt
                                            // Enable
#define TIMER_TBMR_TBCDIR       0x00000010  // GPTM Timer B Count Direction
#define TIMER_TBMR_TBAMS        0x00000008  // GPTM Timer B Alternate Mode
                                            // Select
#define TIMER_TBMR_TBCMR        0x00000004  // GPTM Timer B Capture Mode
#define TIMER_TBMR_TBMR_M       0x00000003  // GPTM Timer B Mode
#define TIMER_TBMR_TBMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TBMR_TBMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TBMR_TBMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_IMR register.
//
//*****************************************************************************
#define TIMER_IMR_TBMIM         0x00000800  // GPTM Timer B Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_CBEIM         0x00000400  // GPTM Capture B Event Interrupt
                                            // Mask
#define TIMER_IMR_CBMIM         0x00000200  // GPTM Capture B Match Interrupt
                                            // Mask
#define TIMER_IMR_TBTOIM        0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Mask
#define TIMER_IMR_TAMIM         0x00000010  // GPTM Timer A Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_RTCIM         0x00000008  // GPTM RTC Interrupt Mask
#define TIMER_IMR_CAEIM         0x00000004  // GPTM Capture A Event Interrupt
                                            // Mask
#define TIMER_IMR_CAMIM         0x00000002  // GPTM Capture A Match Interrupt
                                            // Mask
#define TIMER_IMR_TATOIM        0x00000001  // GPTM Timer A Time-Out Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_RIS register.
//
//*****************************************************************************
#define TIMER_RIS_TBMRIS        0x00000800  // GPTM Timer B Mode Match Raw
                                            // Interrupt
#define TIMER_RIS_CBERIS        0x00000400  // GPTM Capture B Event Raw
                                            // Interrupt
#define TIMER_RIS_CBMRIS        0x00000200  // GPTM Capture B Match Raw
                                            // Interrupt
#define TIMER_RIS_TBTORIS       0x00000100  // GPTM Timer B Time-Out Raw
                                            // Interrupt
#define TIMER_RIS_TAMRIS        0x00000010  // GPTM Timer A Mode Match Raw
                                            // Interrupt
#define TIMER_RIS_RTCRIS        0x00000008  // GPTM RTC Raw Interrupt
#define TIMER_RIS_CAERIS        0x00000004  // GPTM Capture A Event Raw
                                            // Interrupt
#define TIMER_RIS_CAMRIS        0x00000002  // GPTM Capture A Match Raw
                                            // Interrupt
#define TIMER_RIS_TATORIS       0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_MIS register.
//
//*****************************************************************************
#define TIMER_MIS_TBMMIS        0x00000800  // GPTM Timer B Mode Match Masked
                                            // Interrupt
#define TIMER_MIS_CBEMIS        0x00000400  // GPTM Capture B Event Masked
                                            // Interrupt
#define TIMER_MIS_CBMMIS        0x00000200  // GPTM Capture B Match Masked
                                            // Interrupt
#define TIMER_MIS_TBTOMIS       0x00000100  // GPTM Timer B Time-Out Masked
                                            // Interrupt
#define TIMER_MIS_TAMMIS        0x00000010  // GPTM Timer A Mode Match Masked
                                            // Interrupt
#define TIMER_MIS_RTCMIS        0x00000008  // GPTM RTC Masked Interrupt
#define TIMER_MIS_CAEMIS        0x00000004  // GPTM Capture A Event Masked
                                            // Interrupt
#define TIMER_MIS_CAMMIS        0x00000002  // GPTM Capture A Match Masked
                                            // Interrupt
#define TIMER_MIS_TATOMIS       0x00000001  // GPTM Timer A Time-Out Masked
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ICR register.
//
//*****************************************************************************
#define TIMER_ICR_TBMCINT       0x00000800  // GPTM Timer B Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_CBECINT       0x00000400  // GPTM Capture B Event Interrupt
                                            // Clear
#define TIMER_ICR_CBMCINT       0x00000200  // GPTM Capture B Match Interrupt
                                            // Clear
#define TIMER_ICR_TBTOCINT      0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Clear
#define TIMER_ICR_TAMCINT       0x00000010  // GPTM Timer A Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_RTCCINT       0x00000008  // GPTM RTC Interrupt Clear
#define TIMER_ICR_CAECINT       0x00000004  // GPTM Capture A Event Interrupt
                                            // Clear
#define TIMER_ICR_CAMCINT       0x00000002  // GPTM Capture A Match Interrupt
                                            // Clear
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAILR register.
//
//*****************************************************************************
#define TIMER_TAILR_TAILRH_M    0xFFFF0000  // GPTM Timer A Interval Load
                                            // Register High
#define TIMER_TAILR_TAILRL_M    0x0000FFFF  // GPTM Timer A Interval Load
                                            // Register Low
#define TIMER_TAILR_TAILRH_S    16
#define TIMER_TAILR_TAILRL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBILR register.
//
//*****************************************************************************
#define TIMER_TBILR_TBILRL_M    0x0000FFFF  // GPTM Timer B Interval Load
                                            // Register
#define TIMER_TBILR_TBILRL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TAMATCHR_TAMRH_M  0xFFFF0000  // GPTM Timer A Match Register High
#define TIMER_TAMATCHR_TAMRL_M  0x0000FFFF  // GPTM Timer A Match Register Low
#define TIMER_TAMATCHR_TAMRH_S  16
#define TIMER_TAMATCHR_TAMRL_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TBMATCHR_TBMRL_M  0x0000FFFF  // GPTM Timer B Match Register Low
#define TIMER_TBMATCHR_TBMRL_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPR register.
//
//*****************************************************************************
#define TIMER_TAPR_TAPSR_M      0x000000FF  // GPTM Timer A Prescale
#define TIMER_TAPR_TAPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPR register.
//
//*****************************************************************************
#define TIMER_TBPR_TBPSR_M      0x000000FF  // GPTM Timer B Prescale
#define TIMER_TBPR_TBPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPMR register.
//
//*****************************************************************************
#define TIMER_TAPMR_TAPSMR_M    0x000000FF  // GPTM TimerA Prescale Match
#define TIMER_TAPMR_TAPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPMR register.
//
//*****************************************************************************
#define TIMER_TBPMR_TBPSMR_M    0x000000FF  // GPTM TimerB Prescale Match
#define TIMER_TBPMR_TBPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAR register.
//
//*****************************************************************************
#define TIMER_TAR_TARH_M        0xFFFF0000  // GPTM Timer A Register High
#define TIMER_TAR_TARL_M        0x0000FFFF  // GPTM Timer A Register Low
#define TIMER_TAR_TARH_S        16
#define TIMER_TAR_TARL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBR register.
//
//*****************************************************************************
#define TIMER_TBR_TBRL_M        0x00FFFFFF  // GPTM Timer B
#define TIMER_TBR_TBRL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAV register.
//
//*****************************************************************************
#define TIMER_TAV_TAVH_M        0xFFFF0000  // GPTM Timer A Value High
#define TIMER_TAV_TAVL_M        0x0000FFFF  // GPTM Timer A Register Low
#define TIMER_TAV_TAVH_S        16
#define TIMER_TAV_TAVL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBV register.
//
//*****************************************************************************
#define TIMER_TBV_TBVL_M        0x0000FFFF  // GPTM Timer B Register
#define TIMER_TBV_TBVL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_ACTSS register.
//
//*****************************************************************************
#define ADC_ACTSS_ASEN3         0x00000008  // ADC SS3 Enable
#define ADC_ACTSS_ASEN2         0x00000004  // ADC SS2 Enable
#define ADC_ACTSS_ASEN1         0x00000002  // ADC SS1 Enable
#define ADC_ACTSS_ASEN0         0x00000001  // ADC SS0 Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_RIS register.
//
//*****************************************************************************
#define ADC_RIS_INRDC           0x00010000  // Digital Comparator Raw Interrupt
                                            // Status
#define ADC_RIS_INR3            0x00000008  // SS3 Raw Interrupt Status
#define ADC_RIS_INR2            0x00000004  // SS2 Raw Interrupt Status
#define ADC_RIS_INR1            0x00000002  // SS1 Raw Interrupt Status
#define ADC_RIS_INR0            0x00000001  // SS0 Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_IM register.
//
//*****************************************************************************
#define ADC_IM_DCONSS3          0x00080000  // Digital Comparator Interrupt on
                                            // SS3
#define ADC_IM_DCONSS2          0x00040000  // Digital Comparator Interrupt on
                                            // SS2
#define ADC_IM_DCONSS1          0x00020000  // Digital Comparator Interrupt on
                                            // SS1
#define ADC_IM_DCONSS0          0x00010000  // Digital Comparator Interrupt on
                                            // SS0
#define ADC_IM_MASK3            0x00000008  // SS3 Interrupt Mask
#define ADC_IM_MASK2            0x00000004  // SS2 Interrupt Mask
#define ADC_IM_MASK1            0x00000002  // SS1 Interrupt Mask
#define ADC_IM_MASK0            0x00000001  // SS0 Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_ISC register.
//
//*****************************************************************************
#define ADC_ISC_DCINSS3         0x00080000  // Digital Comparator Interrupt
                                            // Status on SS3
#define ADC_ISC_DCINSS2         0x00040000  // Digital Comparator Interrupt
                                            // Status on SS2
#define ADC_ISC_DCINSS1         0x00020000  // Digital Comparator Interrupt
                                            // Status on SS1
#define ADC_ISC_DCINSS0         0x00010000  // Digital Comparator Interrupt
                                            // Status on SS0
#define ADC_ISC_IN3             0x00000008  // SS3 Interrupt Status and Clear
#define ADC_ISC_IN2             0x00000004  // SS2 Interrupt Status and Clear
#define ADC_ISC_IN1             0x00000002  // SS1 Interrupt Status and Clear
#define ADC_ISC_IN0             0x00000001  // SS0 Interrupt Status and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_OSTAT register.
//
//*****************************************************************************
#define ADC_OSTAT_OV3           0x00000008  // SS3 FIFO Overflow
#define ADC_OSTAT_OV2           0x00000004  // SS2 FIFO Overflow
#define ADC_OSTAT_OV1           0x00000002  // SS1 FIFO Overflow
#define ADC_OSTAT_OV0           0x00000001  // SS0 FIFO Overflow

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_EMUX register.
//
//*****************************************************************************
#define ADC_EMUX_EM3_M          0x0000F000  // SS3 Trigger Select
#define ADC_EMUX_EM3_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM3_COMP0      0x00001000  // Analog Comparator 0
#define ADC_EMUX_EM3_COMP1      0x00002000  // Analog Comparator 1
#define ADC_EMUX_EM3_COMP2      0x00003000  // Analog Comparator 2
#define ADC_EMUX_EM3_EXTERNAL   0x00004000  // External (GPIO PB4)
#define ADC_EMUX_EM3_TIMER      0x00005000  // Timer
#define ADC_EMUX_EM3_ALWAYS     0x0000F000  // Always (continuously sample)
#define ADC_EMUX_EM2_M          0x00000F00  // SS2 Trigger Select
#define ADC_EMUX_EM2_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM2_COMP0      0x00000100  // Analog Comparator 0
#define ADC_EMUX_EM2_COMP1      0x00000200  // Analog Comparator 1
#define ADC_EMUX_EM2_COMP2      0x00000300  // Analog Comparator 2
#define ADC_EMUX_EM2_EXTERNAL   0x00000400  // External (GPIO PB4)
#define ADC_EMUX_EM2_TIMER      0x00000500  // Timer
#define ADC_EMUX_EM2_ALWAYS     0x00000F00  // Always (continuously sample)
#define ADC_EMUX_EM1_M          0x000000F0  // SS1 Trigger Select
#define ADC_EMUX_EM1_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM1_COMP0      0x00000010  // Analog Comparator 0
#define ADC_EMUX_EM1_COMP1      0x00000020  // Analog Comparator 1
#define ADC_EMUX_EM1_COMP2      0x00000030  // Analog Comparator 2
#define ADC_EMUX_EM1_EXTERNAL   0x00000040  // External (GPIO PB4)
#define ADC_EMUX_EM1_TIMER      0x00000050  // Timer
#define ADC_EMUX_EM1_ALWAYS     0x000000F0  // Always (continuously sample)
#define ADC_EMUX_EM0_M          0x0000000F  // SS0 Trigger Select
#define ADC_EMUX_EM0_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM0_COMP0      0x00000001  // Analog Comparator 0
#define ADC_EMUX_EM0_COMP1      0x00000002  // Analog Comparator 1
#define ADC_EMUX_EM0_COMP2      0x00000003  // Analog Comparator 2
#define ADC_EMUX_EM0_EXTERNAL   0x00000004  // External (GPIO PB4)
#define ADC_EMUX_EM0_TIMER      0x00000005  // Timer
#define ADC_EMUX_EM0_ALWAYS     0x0000000F  // Always (continuously sample)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_USTAT register.
//
//*****************************************************************************
#define ADC_USTAT_UV3           0x00000008  // SS3 FIFO Underflow
#define ADC_USTAT_UV2           0x00000004  // SS2 FIFO Underflow
#define ADC_USTAT_UV1           0x00000002  // SS1 FIFO Underflow
#define ADC_USTAT_UV0           0x00000001  // SS0 FIFO Underflow

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSPRI register.
//
//*****************************************************************************
#define ADC_SSPRI_SS3_M         0x00003000  // SS3 Priority
#define ADC_SSPRI_SS3_1ST       0x00000000  // First priority
#define ADC_SSPRI_SS3_2ND       0x00001000  // Second priority
#define ADC_SSPRI_SS3_3RD       0x00002000  // Third priority
#define ADC_SSPRI_SS3_4TH       0x00003000  // Fourth priority
#define ADC_SSPRI_SS2_M         0x00000300  // SS2 Priority
#define ADC_SSPRI_SS2_1ST       0x00000000  // First priority
#define ADC_SSPRI_SS2_2ND       0x00000100  // Second priority
#define ADC_SSPRI_SS2_3RD       0x00000200  // Third priority
#define ADC_SSPRI_SS2_4TH       0x00000300  // Fourth priority
#define ADC_SSPRI_SS1_M         0x00000030  // SS1 Priority
#define ADC_SSPRI_SS1_1ST       0x00000000  // First priority
#define ADC_SSPRI_SS1_2ND       0x00000010  // Second priority
#define ADC_SSPRI_SS1_3RD       0x00000020  // Third priority
#define ADC_SSPRI_SS1_4TH       0x00000030  // Fourth priority
#define ADC_SSPRI_SS0_M         0x00000003  // SS0 Priority
#define ADC_SSPRI_SS0_1ST       0x00000000  // First priority
#define ADC_SSPRI_SS0_2ND       0x00000001  // Second priority
#define ADC_SSPRI_SS0_3RD       0x00000002  // Third priority
#define ADC_SSPRI_SS0_4TH       0x00000003  // Fourth priority

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SPC register.
//
//*****************************************************************************
#define ADC_SPC_PHASE_M         0x0000000F  // Phase Difference
#define ADC_SPC_PHASE_0         0x00000000  // ADC sample lags by 0.0
#define ADC_SPC_PHASE_22_5      0x00000001  // ADC sample lags by 22.5
#define ADC_SPC_PHASE_45        0x00000002  // ADC sample lags by 45.0
#define ADC_SPC_PHASE_67_5      0x00000003  // ADC sample lags by 67.5
#define ADC_SPC_PHASE_90        0x00000004  // ADC sample lags by 90.0
#define ADC_SPC_PHASE_112_5     0x00000005  // ADC sample lags by 112.5
#define ADC_SPC_PHASE_135       0x00000006  // ADC sample lags by 135.0
#define ADC_SPC_PHASE_157_5     0x00000007  // ADC sample lags by 157.5
#define ADC_SPC_PHASE_180       0x00000008  // ADC sample lags by 180.0
#define ADC_SPC_PHASE_202_5     0x00000009  // ADC sample lags by 202.5
#define ADC_SPC_PHASE_225       0x0000000A  // ADC sample lags by 225.0
#define ADC_SPC_PHASE_247_5     0x0000000B  // ADC sample lags by 247.5
#define ADC_SPC_PHASE_270       0x0000000C  // ADC sample lags by 270.0
#define ADC_SPC_PHASE_292_5     0x0000000D  // ADC sample lags by 292.5
#define ADC_SPC_PHASE_315       0x0000000E  // ADC sample lags by 315.0
#define ADC_SPC_PHASE_337_5     0x0000000F  // ADC sample lags by 337.5

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_PSSI register.
//
//*****************************************************************************
#define ADC_PSSI_GSYNC          0x80000000  // Global Synchronize
#define ADC_PSSI_SYNCWAIT       0x08000000  // Synchronize Wait
#define ADC_PSSI_SS3            0x00000008  // SS3 Initiate
#define ADC_PSSI_SS2            0x00000004  // SS2 Initiate
#define ADC_PSSI_SS1            0x00000002  // SS1 Initiate
#define ADC_PSSI_SS0            0x00000001  // SS0 Initiate

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SAC register.
//
//*****************************************************************************
#define ADC_SAC_AVG_M           0x00000007  // Hardware Averaging Control
#define ADC_SAC_AVG_OFF         0x00000000  // No hardware oversampling
#define ADC_SAC_AVG_2X          0x00000001  // 2x hardware oversampling
#define ADC_SAC_AVG_4X          0x00000002  // 4x hardware oversampling
#define ADC_SAC_AVG_8X          0x00000003  // 8x hardware oversampling
#define ADC_SAC_AVG_16X         0x00000004  // 16x hardware oversampling
#define ADC_SAC_AVG_32X         0x00000005  // 32x hardware oversampling
#define ADC_SAC_AVG_64X         0x00000006  // 64x hardware oversampling

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCISC register.
//
//*****************************************************************************
#define ADC_DCISC_DCINT7        0x00000080  // Digital Comparator 7 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT6        0x00000040  // Digital Comparator 6 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT5        0x00000020  // Digital Comparator 5 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT4        0x00000010  // Digital Comparator 4 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT3        0x00000008  // Digital Comparator 3 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT2        0x00000004  // Digital Comparator 2 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT1        0x00000002  // Digital Comparator 1 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT0        0x00000001  // Digital Comparator 0 Interrupt
                                            // Status and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_CTL register.
//
//*****************************************************************************
#define ADC_CTL_VREF            0x00000001  // Voltage Reference Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX0 register.
//
//*****************************************************************************
#define ADC_SSMUX0_MUX7_M       0xF0000000  // 8th Sample Input Select
#define ADC_SSMUX0_MUX6_M       0x0F000000  // 7th Sample Input Select
#define ADC_SSMUX0_MUX5_M       0x00F00000  // 6th Sample Input Select
#define ADC_SSMUX0_MUX4_M       0x000F0000  // 5th Sample Input Select
#define ADC_SSMUX0_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX0_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX0_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX0_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX0_MUX7_S       28
#define ADC_SSMUX0_MUX6_S       24
#define ADC_SSMUX0_MUX5_S       20
#define ADC_SSMUX0_MUX4_S       16
#define ADC_SSMUX0_MUX3_S       12
#define ADC_SSMUX0_MUX2_S       8
#define ADC_SSMUX0_MUX1_S       4
#define ADC_SSMUX0_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL0 register.
//
//*****************************************************************************
#define ADC_SSCTL0_TS7          0x80000000  // 8th Sample Temp Sensor Select
#define ADC_SSCTL0_IE7          0x40000000  // 8th Sample Interrupt Enable
#define ADC_SSCTL0_END7         0x20000000  // 8th Sample is End of Sequence
#define ADC_SSCTL0_D7           0x10000000  // 8th Sample Diff Input Select
#define ADC_SSCTL0_TS6          0x08000000  // 7th Sample Temp Sensor Select
#define ADC_SSCTL0_IE6          0x04000000  // 7th Sample Interrupt Enable
#define ADC_SSCTL0_END6         0x02000000  // 7th Sample is End of Sequence
#define ADC_SSCTL0_D6           0x01000000  // 7th Sample Diff Input Select
#define ADC_SSCTL0_TS5          0x00800000  // 6th Sample Temp Sensor Select
#define ADC_SSCTL0_IE5          0x00400000  // 6th Sample Interrupt Enable
#define ADC_SSCTL0_END5         0x00200000  // 6th Sample is End of Sequence
#define ADC_SSCTL0_D5           0x00100000  // 6th Sample Diff Input Select
#define ADC_SSCTL0_TS4          0x00080000  // 5th Sample Temp Sensor Select
#define ADC_SSCTL0_IE4          0x00040000  // 5th Sample Interrupt Enable
#define ADC_SSCTL0_END4         0x00020000  // 5th Sample is End of Sequence
#define ADC_SSCTL0_D4           0x00010000  // 5th Sample Diff Input Select
#define ADC_SSCTL0_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL0_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL0_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL0_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL0_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL0_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL0_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL0_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL0_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL0_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL0_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL0_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL0_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL0_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL0_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL0_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO0 register.
//
//*****************************************************************************
#define ADC_SSFIFO0_DATA_M      0x000003FF  // Conversion Result Data
#define ADC_SSFIFO0_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT0 register.
//
//*****************************************************************************
#define ADC_SSFSTAT0_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT0_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT0_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT0_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT0_HPTR_S     4
#define ADC_SSFSTAT0_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP0 register.
//
//*****************************************************************************
#define ADC_SSOP0_S7DCOP        0x10000000  // Sample 7 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S6DCOP        0x01000000  // Sample 6 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S5DCOP        0x00100000  // Sample 5 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S4DCOP        0x00010000  // Sample 4 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC0 register.
//
//*****************************************************************************
#define ADC_SSDC0_S7DCSEL_M     0xF0000000  // Sample 7 Digital Comparator
                                            // Select
#define ADC_SSDC0_S6DCSEL_M     0x0F000000  // Sample 6 Digital Comparator
                                            // Select
#define ADC_SSDC0_S5DCSEL_M     0x00F00000  // Sample 5 Digital Comparator
                                            // Select
#define ADC_SSDC0_S4DCSEL_M     0x000F0000  // Sample 4 Digital Comparator
                                            // Select
#define ADC_SSDC0_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC0_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC0_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC0_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC0_S6DCSEL_S     24
#define ADC_SSDC0_S5DCSEL_S     20
#define ADC_SSDC0_S4DCSEL_S     16
#define ADC_SSDC0_S3DCSEL_S     12
#define ADC_SSDC0_S2DCSEL_S     8
#define ADC_SSDC0_S1DCSEL_S     4
#define ADC_SSDC0_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX1 register.
//
//*****************************************************************************
#define ADC_SSMUX1_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX1_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX1_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX1_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX1_MUX3_S       12
#define ADC_SSMUX1_MUX2_S       8
#define ADC_SSMUX1_MUX1_S       4
#define ADC_SSMUX1_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL1 register.
//
//*****************************************************************************
#define ADC_SSCTL1_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL1_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL1_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL1_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL1_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL1_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL1_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL1_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL1_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL1_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL1_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL1_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL1_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL1_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL1_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL1_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO1 register.
//
//*****************************************************************************
#define ADC_SSFIFO1_DATA_M      0x000003FF  // Conversion Result Data
#define ADC_SSFIFO1_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT1 register.
//
//*****************************************************************************
#define ADC_SSFSTAT1_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT1_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT1_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT1_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT1_HPTR_S     4
#define ADC_SSFSTAT1_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP1 register.
//
//*****************************************************************************
#define ADC_SSOP1_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC1 register.
//
//*****************************************************************************
#define ADC_SSDC1_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC1_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC1_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC1_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC1_S2DCSEL_S     8
#define ADC_SSDC1_S1DCSEL_S     4
#define ADC_SSDC1_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX2 register.
//
//*****************************************************************************
#define ADC_SSMUX2_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX2_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX2_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX2_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX2_MUX3_S       12
#define ADC_SSMUX2_MUX2_S       8
#define ADC_SSMUX2_MUX1_S       4
#define ADC_SSMUX2_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL2 register.
//
//*****************************************************************************
#define ADC_SSCTL2_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL2_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL2_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL2_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL2_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL2_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL2_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL2_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL2_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL2_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL2_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL2_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL2_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL2_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL2_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL2_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO2 register.
//
//*****************************************************************************
#define ADC_SSFIFO2_DATA_M      0x000003FF  // Conversion Result Data
#define ADC_SSFIFO2_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT2 register.
//
//*****************************************************************************
#define ADC_SSFSTAT2_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT2_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT2_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT2_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT2_HPTR_S     4
#define ADC_SSFSTAT2_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP2 register.
//
//*****************************************************************************
#define ADC_SSOP2_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC2 register.
//
//*****************************************************************************
#define ADC_SSDC2_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC2_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC2_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC2_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC2_S2DCSEL_S     8
#define ADC_SSDC2_S1DCSEL_S     4
#define ADC_SSDC2_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX3 register.
//
//*****************************************************************************
#define ADC_SSMUX3_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX3_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL3 register.
//
//*****************************************************************************
#define ADC_SSCTL3_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL3_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL3_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL3_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO3 register.
//
//*****************************************************************************
#define ADC_SSFIFO3_DATA_M      0x000003FF  // Conversion Result Data
#define ADC_SSFIFO3_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT3 register.
//
//*****************************************************************************
#define ADC_SSFSTAT3_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT3_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT3_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT3_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT3_HPTR_S     4
#define ADC_SSFSTAT3_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP3 register.
//
//*****************************************************************************
#define ADC_SSOP3_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC3 register.
//
//*****************************************************************************
#define ADC_SSDC3_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCRIC register.
//
//*****************************************************************************
#define ADC_DCRIC_DCTRIG7       0x00800000  // Digital Comparator Trigger 7
#define ADC_DCRIC_DCTRIG6       0x00400000  // Digital Comparator Trigger 6
#define ADC_DCRIC_DCTRIG5       0x00200000  // Digital Comparator Trigger 5
#define ADC_DCRIC_DCTRIG4       0x00100000  // Digital Comparator Trigger 4
#define ADC_DCRIC_DCTRIG3       0x00080000  // Digital Comparator Trigger 3
#define ADC_DCRIC_DCTRIG2       0x00040000  // Digital Comparator Trigger 2
#define ADC_DCRIC_DCTRIG1       0x00020000  // Digital Comparator Trigger 1
#define ADC_DCRIC_DCTRIG0       0x00010000  // Digital Comparator Trigger 0
#define ADC_DCRIC_DCINT7        0x00000080  // Digital Comparator Interrupt 7
#define ADC_DCRIC_DCINT6        0x00000040  // Digital Comparator Interrupt 6
#define ADC_DCRIC_DCINT5        0x00000020  // Digital Comparator Interrupt 5
#define ADC_DCRIC_DCINT4        0x00000010  // Digital Comparator Interrupt 4
#define ADC_DCRIC_DCINT3        0x00000008  // Digital Comparator Interrupt 3
#define ADC_DCRIC_DCINT2        0x00000004  // Digital Comparator Interrupt 2
#define ADC_DCRIC_DCINT1        0x00000002  // Digital Comparator Interrupt 1
#define ADC_DCRIC_DCINT0        0x00000001  // Digital Comparator Interrupt 0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL0 register.
//
//*****************************************************************************
#define ADC_DCCTL0_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL0_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL0_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL0_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL0_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL0_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL0_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL0_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL0_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL0_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL0_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL0_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL0_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL0_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL0_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL0_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL0_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL0_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL0_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL0_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL1 register.
//
//*****************************************************************************
#define ADC_DCCTL1_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL1_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL1_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL1_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL1_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL1_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL1_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL1_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL1_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL1_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL1_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL1_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL1_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL1_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL1_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL1_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL1_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL1_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL1_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL1_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL2 register.
//
//*****************************************************************************
#define ADC_DCCTL2_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL2_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL2_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL2_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL2_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL2_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL2_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL2_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL2_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL2_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL2_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL2_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL2_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL2_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL2_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL2_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL2_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL2_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL2_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL2_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL3 register.
//
//*****************************************************************************
#define ADC_DCCTL3_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL3_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL3_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL3_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL3_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL3_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL3_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL3_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL3_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL3_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL3_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL3_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL3_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL3_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL3_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL3_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL3_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL3_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL3_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL3_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL4 register.
//
//*****************************************************************************
#define ADC_DCCTL4_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL4_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL4_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL4_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL4_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL4_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL4_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL4_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL4_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL4_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL4_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL4_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL4_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL4_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL4_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL4_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL4_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL4_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL4_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL4_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL5 register.
//
//*****************************************************************************
#define ADC_DCCTL5_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL5_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL5_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL5_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL5_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL5_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL5_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL5_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL5_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL5_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL5_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL5_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL5_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL5_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL5_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL5_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL5_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL5_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL5_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL5_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL6 register.
//
//*****************************************************************************
#define ADC_DCCTL6_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL6_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL6_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL6_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL6_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL6_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL6_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL6_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL6_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL6_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL6_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL6_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL6_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL6_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL6_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL6_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL6_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL6_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL6_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL6_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL7 register.
//
//*****************************************************************************
#define ADC_DCCTL7_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL7_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL7_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL7_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL7_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL7_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL7_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL7_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL7_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL7_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL7_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL7_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL7_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL7_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL7_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL7_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL7_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL7_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL7_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL7_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP0 register.
//
//*****************************************************************************
#define ADC_DCCMP0_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP0_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP0_COMP1_S      16
#define ADC_DCCMP0_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP1 register.
//
//*****************************************************************************
#define ADC_DCCMP1_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP1_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP1_COMP1_S      16
#define ADC_DCCMP1_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP2 register.
//
//*****************************************************************************
#define ADC_DCCMP2_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP2_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP2_COMP1_S      16
#define ADC_DCCMP2_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP3 register.
//
//*****************************************************************************
#define ADC_DCCMP3_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP3_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP3_COMP1_S      16
#define ADC_DCCMP3_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP4 register.
//
//*****************************************************************************
#define ADC_DCCMP4_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP4_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP4_COMP1_S      16
#define ADC_DCCMP4_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP5 register.
//
//*****************************************************************************
#define ADC_DCCMP5_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP5_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP5_COMP1_S      16
#define ADC_DCCMP5_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP6 register.
//
//*****************************************************************************
#define ADC_DCCMP6_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP6_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP6_COMP1_S      16
#define ADC_DCCMP6_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP7 register.
//
//*****************************************************************************
#define ADC_DCCMP7_COMP1_M      0x03FF0000  // Compare 1
#define ADC_DCCMP7_COMP0_M      0x000003FF  // Compare 0
#define ADC_DCCMP7_COMP1_S      16
#define ADC_DCCMP7_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the the interpretation of the data in the
// SSFIFOx when the ADC TMLB is enabled.
//
//*****************************************************************************
#define ADC_SSFIFO_TMLB_CNT_M   0x000003C0  // Continuous Sample Counter
#define ADC_SSFIFO_TMLB_CONT    0x00000020  // Continuation Sample Indicator
#define ADC_SSFIFO_TMLB_DIFF    0x00000010  // Differential Sample Indicator
#define ADC_SSFIFO_TMLB_TS      0x00000008  // Temp Sensor Sample Indicator
#define ADC_SSFIFO_TMLB_MUX_M   0x00000007  // Analog Input Indicator
#define ADC_SSFIFO_TMLB_CNT_S   6           // Sample counter shift
#define ADC_SSFIFO_TMLB_MUX_S   0           // Input channel number shift

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACMIS register.
//
//*****************************************************************************
#define COMP_ACMIS_IN2          0x00000004  // Comparator 2 Masked Interrupt
                                            // Status
#define COMP_ACMIS_IN1          0x00000002  // Comparator 1 Masked Interrupt
                                            // Status
#define COMP_ACMIS_IN0          0x00000001  // Comparator 0 Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACRIS register.
//
//*****************************************************************************
#define COMP_ACRIS_IN2          0x00000004  // Comparator 2 Interrupt Status
#define COMP_ACRIS_IN1          0x00000002  // Comparator 1 Interrupt Status
#define COMP_ACRIS_IN0          0x00000001  // Comparator 0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACINTEN register.
//
//*****************************************************************************
#define COMP_ACINTEN_IN2        0x00000004  // Comparator 2 Interrupt Enable
#define COMP_ACINTEN_IN1        0x00000002  // Comparator 1 Interrupt Enable
#define COMP_ACINTEN_IN0        0x00000001  // Comparator 0 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACREFCTL
// register.
//
//*****************************************************************************
#define COMP_ACREFCTL_EN        0x00000200  // Resistor Ladder Enable
#define COMP_ACREFCTL_RNG       0x00000100  // Resistor Ladder Range
#define COMP_ACREFCTL_VREF_M    0x0000000F  // Resistor Ladder Voltage Ref
#define COMP_ACREFCTL_VREF_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT0 register.
//
//*****************************************************************************
#define COMP_ACSTAT0_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL0 register.
//
//*****************************************************************************
#define COMP_ACCTL0_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL0_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL0_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL0_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL0_ASRCP_REF   0x00000400  // Internal voltage reference
                                            // (VIREF)
#define COMP_ACCTL0_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL0_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL0_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL0_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL0_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL0_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL0_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL0_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL0_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL0_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL0_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL0_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL0_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT1 register.
//
//*****************************************************************************
#define COMP_ACSTAT1_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL1 register.
//
//*****************************************************************************
#define COMP_ACCTL1_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL1_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL1_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL1_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL1_ASRCP_REF   0x00000400  // Internal voltage reference
                                            // (VIREF)
#define COMP_ACCTL1_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL1_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL1_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL1_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL1_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL1_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL1_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL1_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL1_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL1_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL1_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL1_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL1_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT2 register.
//
//*****************************************************************************
#define COMP_ACSTAT2_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL2 register.
//
//*****************************************************************************
#define COMP_ACCTL2_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL2_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL2_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL2_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL2_ASRCP_REF   0x00000400  // Internal voltage reference
                                            // (VIREF)
#define COMP_ACCTL2_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL2_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL2_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL2_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL2_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL2_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL2_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL2_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL2_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL2_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL2_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL2_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL2_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_CTL register.
//
//*****************************************************************************
#define CAN_CTL_TEST            0x00000080  // Test Mode Enable
#define CAN_CTL_CCE             0x00000040  // Configuration Change Enable
#define CAN_CTL_DAR             0x00000020  // Disable Automatic-Retransmission
#define CAN_CTL_EIE             0x00000008  // Error Interrupt Enable
#define CAN_CTL_SIE             0x00000004  // Status Interrupt Enable
#define CAN_CTL_IE              0x00000002  // CAN Interrupt Enable
#define CAN_CTL_INIT            0x00000001  // Initialization

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_STS register.
//
//*****************************************************************************
#define CAN_STS_BOFF            0x00000080  // Bus-Off Status
#define CAN_STS_EWARN           0x00000040  // Warning Status
#define CAN_STS_EPASS           0x00000020  // Error Passive
#define CAN_STS_RXOK            0x00000010  // Received a Message Successfully
#define CAN_STS_TXOK            0x00000008  // Transmitted a Message
                                            // Successfully
#define CAN_STS_LEC_M           0x00000007  // Last Error Code
#define CAN_STS_LEC_NONE        0x00000000  // No Error
#define CAN_STS_LEC_STUFF       0x00000001  // Stuff Error
#define CAN_STS_LEC_FORM        0x00000002  // Format Error
#define CAN_STS_LEC_ACK         0x00000003  // ACK Error
#define CAN_STS_LEC_BIT1        0x00000004  // Bit 1 Error
#define CAN_STS_LEC_BIT0        0x00000005  // Bit 0 Error
#define CAN_STS_LEC_CRC         0x00000006  // CRC Error
#define CAN_STS_LEC_NOEVENT     0x00000007  // No Event

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_ERR register.
//
//*****************************************************************************
#define CAN_ERR_RP              0x00008000  // Received Error Passive
#define CAN_ERR_REC_M           0x00007F00  // Receive Error Counter
#define CAN_ERR_TEC_M           0x000000FF  // Transmit Error Counter
#define CAN_ERR_REC_S           8
#define CAN_ERR_TEC_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BIT register.
//
//*****************************************************************************
#define CAN_BIT_TSEG2_M         0x00007000  // Time Segment after Sample Point
#define CAN_BIT_TSEG1_M         0x00000F00  // Time Segment Before Sample Point
#define CAN_BIT_SJW_M           0x000000C0  // (Re)Synchronization Jump Width
#define CAN_BIT_BRP_M           0x0000003F  // Baud Rate Prescaler
#define CAN_BIT_TSEG2_S         12
#define CAN_BIT_TSEG1_S         8
#define CAN_BIT_SJW_S           6
#define CAN_BIT_BRP_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_INT register.
//
//*****************************************************************************
#define CAN_INT_INTID_M         0x0000FFFF  // Interrupt Identifier
#define CAN_INT_INTID_NONE      0x00000000  // No interrupt pending
#define CAN_INT_INTID_STATUS    0x00008000  // Status Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TST register.
//
//*****************************************************************************
#define CAN_TST_RX              0x00000080  // Receive Observation
#define CAN_TST_TX_M            0x00000060  // Transmit Control
#define CAN_TST_TX_CANCTL       0x00000000  // CAN Module Control
#define CAN_TST_TX_SAMPLE       0x00000020  // Sample Point
#define CAN_TST_TX_DOMINANT     0x00000040  // Driven Low
#define CAN_TST_TX_RECESSIVE    0x00000060  // Driven High
#define CAN_TST_LBACK           0x00000010  // Loopback Mode
#define CAN_TST_SILENT          0x00000008  // Silent Mode
#define CAN_TST_BASIC           0x00000004  // Basic Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BRPE register.
//
//*****************************************************************************
#define CAN_BRPE_BRPE_M         0x0000000F  // Baud Rate Prescaler Extension
#define CAN_BRPE_BRPE_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CRQ register.
//
//*****************************************************************************
#define CAN_IF1CRQ_BUSY         0x00008000  // Busy Flag
#define CAN_IF1CRQ_MNUM_M       0x0000003F  // Message Number
#define CAN_IF1CRQ_MNUM_RSVD    0x00000000  // 0 is not a valid message number;
                                            // it is interpreted as 0x20, or
                                            // object 32
#define CAN_IF1CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CMSK register.
//
//*****************************************************************************
#define CAN_IF1CMSK_WRNRD       0x00000080  // Write, Not Read
#define CAN_IF1CMSK_MASK        0x00000040  // Access Mask Bits
#define CAN_IF1CMSK_ARB         0x00000020  // Access Arbitration Bits
#define CAN_IF1CMSK_CONTROL     0x00000010  // Access Control Bits
#define CAN_IF1CMSK_CLRINTPND   0x00000008  // Clear Interrupt Pending Bit
#define CAN_IF1CMSK_NEWDAT      0x00000004  // Access New Data
#define CAN_IF1CMSK_TXRQST      0x00000004  // Access Transmission Request
#define CAN_IF1CMSK_DATAA       0x00000002  // Access Data Byte 0 to 3
#define CAN_IF1CMSK_DATAB       0x00000001  // Access Data Byte 4 to 7

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK1 register.
//
//*****************************************************************************
#define CAN_IF1MSK1_IDMSK_M     0x0000FFFF  // Identifier Mask
#define CAN_IF1MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK2 register.
//
//*****************************************************************************
#define CAN_IF1MSK2_MXTD        0x00008000  // Mask Extended Identifier
#define CAN_IF1MSK2_MDIR        0x00004000  // Mask Message Direction
#define CAN_IF1MSK2_IDMSK_M     0x00001FFF  // Identifier Mask
#define CAN_IF1MSK2_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB1 register.
//
//*****************************************************************************
#define CAN_IF1ARB1_ID_M        0x0000FFFF  // Message Identifier
#define CAN_IF1ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB2 register.
//
//*****************************************************************************
#define CAN_IF1ARB2_MSGVAL      0x00008000  // Message Valid
#define CAN_IF1ARB2_XTD         0x00004000  // Extended Identifier
#define CAN_IF1ARB2_DIR         0x00002000  // Message Direction
#define CAN_IF1ARB2_ID_M        0x00001FFF  // Message Identifier
#define CAN_IF1ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MCTL register.
//
//*****************************************************************************
#define CAN_IF1MCTL_NEWDAT      0x00008000  // New Data
#define CAN_IF1MCTL_MSGLST      0x00004000  // Message Lost
#define CAN_IF1MCTL_INTPND      0x00002000  // Interrupt Pending
#define CAN_IF1MCTL_UMASK       0x00001000  // Use Acceptance Mask
#define CAN_IF1MCTL_TXIE        0x00000800  // Transmit Interrupt Enable
#define CAN_IF1MCTL_RXIE        0x00000400  // Receive Interrupt Enable
#define CAN_IF1MCTL_RMTEN       0x00000200  // Remote Enable
#define CAN_IF1MCTL_TXRQST      0x00000100  // Transmit Request
#define CAN_IF1MCTL_EOB         0x00000080  // End of Buffer
#define CAN_IF1MCTL_DLC_M       0x0000000F  // Data Length Code
#define CAN_IF1MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA1 register.
//
//*****************************************************************************
#define CAN_IF1DA1_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA2 register.
//
//*****************************************************************************
#define CAN_IF1DA2_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB1 register.
//
//*****************************************************************************
#define CAN_IF1DB1_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB2 register.
//
//*****************************************************************************
#define CAN_IF1DB2_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CRQ register.
//
//*****************************************************************************
#define CAN_IF2CRQ_BUSY         0x00008000  // Busy Flag
#define CAN_IF2CRQ_MNUM_M       0x0000003F  // Message Number
#define CAN_IF2CRQ_MNUM_RSVD    0x00000000  // 0 is not a valid message number;
                                            // it is interpreted as 0x20, or
                                            // object 32
#define CAN_IF2CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CMSK register.
//
//*****************************************************************************
#define CAN_IF2CMSK_WRNRD       0x00000080  // Write, Not Read
#define CAN_IF2CMSK_MASK        0x00000040  // Access Mask Bits
#define CAN_IF2CMSK_ARB         0x00000020  // Access Arbitration Bits
#define CAN_IF2CMSK_CONTROL     0x00000010  // Access Control Bits
#define CAN_IF2CMSK_CLRINTPND   0x00000008  // Clear Interrupt Pending Bit
#define CAN_IF2CMSK_NEWDAT      0x00000004  // Access New Data
#define CAN_IF2CMSK_TXRQST      0x00000004  // Access Transmission Request
#define CAN_IF2CMSK_DATAA       0x00000002  // Access Data Byte 0 to 3
#define CAN_IF2CMSK_DATAB       0x00000001  // Access Data Byte 4 to 7

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK1 register.
//
//*****************************************************************************
#define CAN_IF2MSK1_IDMSK_M     0x0000FFFF  // Identifier Mask
#define CAN_IF2MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK2 register.
//
//*****************************************************************************
#define CAN_IF2MSK2_MXTD        0x00008000  // Mask Extended Identifier
#define CAN_IF2MSK2_MDIR        0x00004000  // Mask Message Direction
#define CAN_IF2MSK2_IDMSK_M     0x00001FFF  // Identifier Mask
#define CAN_IF2MSK2_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB1 register.
//
//*****************************************************************************
#define CAN_IF2ARB1_ID_M        0x0000FFFF  // Message Identifier
#define CAN_IF2ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB2 register.
//
//*****************************************************************************
#define CAN_IF2ARB2_MSGVAL      0x00008000  // Message Valid
#define CAN_IF2ARB2_XTD         0x00004000  // Extended Identifier
#define CAN_IF2ARB2_DIR         0x00002000  // Message Direction
#define CAN_IF2ARB2_ID_M        0x00001FFF  // Message Identifier
#define CAN_IF2ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MCTL register.
//
//*****************************************************************************
#define CAN_IF2MCTL_NEWDAT      0x00008000  // New Data
#define CAN_IF2MCTL_MSGLST      0x00004000  // Message Lost
#define CAN_IF2MCTL_INTPND      0x00002000  // Interrupt Pending
#define CAN_IF2MCTL_UMASK       0x00001000  // Use Acceptance Mask
#define CAN_IF2MCTL_TXIE        0x00000800  // Transmit Interrupt Enable
#define CAN_IF2MCTL_RXIE        0x00000400  // Receive Interrupt Enable
#define CAN_IF2MCTL_RMTEN       0x00000200  // Remote Enable
#define CAN_IF2MCTL_TXRQST      0x00000100  // Transmit Request
#define CAN_IF2MCTL_EOB         0x00000080  // End of Buffer
#define CAN_IF2MCTL_DLC_M       0x0000000F  // Data Length Code
#define CAN_IF2MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA1 register.
//
//*****************************************************************************
#define CAN_IF2DA1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA2 register.
//
//*****************************************************************************
#define CAN_IF2DA2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB1 register.
//
//*****************************************************************************
#define CAN_IF2DB1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB2 register.
//
//*****************************************************************************
#define CAN_IF2DB2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ1 register.
//
//*****************************************************************************
#define CAN_TXRQ1_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ1_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ2 register.
//
//*****************************************************************************
#define CAN_TXRQ2_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ2_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA1 register.
//
//*****************************************************************************
#define CAN_NWDA1_NEWDAT_M      0x0000FFFF  // New Data Bits
#define CAN_NWDA1_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA2 register.
//
//*****************************************************************************
#define CAN_NWDA2_NEWDAT_M      0x0000FFFF  // New Data Bits
#define CAN_NWDA2_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1INT register.
//
//*****************************************************************************
#define CAN_MSG1INT_INTPND_M    0x0000FFFF  // Interrupt Pending Bits
#define CAN_MSG1INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2INT register.
//
//*****************************************************************************
#define CAN_MSG2INT_INTPND_M    0x0000FFFF  // Interrupt Pending Bits
#define CAN_MSG2INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1VAL register.
//
//*****************************************************************************
#define CAN_MSG1VAL_MSGVAL_M    0x0000FFFF  // Message Valid Bits
#define CAN_MSG1VAL_MSGVAL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2VAL register.
//
//*****************************************************************************
#define CAN_MSG2VAL_MSGVAL_M    0x0000FFFF  // Message Valid Bits
#define CAN_MSG2VAL_MSGVAL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_RIS register.
//
//*****************************************************************************
#define MAC_RIS_PHYINT          0x00000040  // PHY Interrupt
#define MAC_RIS_MDINT           0x00000020  // MII Transaction Complete
#define MAC_RIS_RXER            0x00000010  // Receive Error
#define MAC_RIS_FOV             0x00000008  // FIFO Overrun
#define MAC_RIS_TXEMP           0x00000004  // Transmit FIFO Empty
#define MAC_RIS_TXER            0x00000002  // Transmit Error
#define MAC_RIS_RXINT           0x00000001  // Packet Received

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IM register.
//
//*****************************************************************************
#define MAC_IM_PHYINTM          0x00000040  // Mask PHY Interrupt
#define MAC_IM_MDINTM           0x00000020  // Mask MII Transaction Complete
#define MAC_IM_RXERM            0x00000010  // Mask Receive Error
#define MAC_IM_FOVM             0x00000008  // Mask FIFO Overrun
#define MAC_IM_TXEMPM           0x00000004  // Mask Transmit FIFO Empty
#define MAC_IM_TXERM            0x00000002  // Mask Transmit Error
#define MAC_IM_RXINTM           0x00000001  // Mask Packet Received

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_RCTL register.
//
//*****************************************************************************
#define MAC_RCTL_RSTFIFO        0x00000010  // Clear Receive FIFO
#define MAC_RCTL_BADCRC         0x00000008  // Enable Reject Bad CRC
#define MAC_RCTL_PRMS           0x00000004  // Enable Promiscuous Mode
#define MAC_RCTL_AMUL           0x00000002  // Enable Multicast Frames
#define MAC_RCTL_RXEN           0x00000001  // Enable Receiver

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_TCTL register.
//
//*****************************************************************************
#define MAC_TCTL_DUPLEX         0x00000010  // Enable Duplex Mode
#define MAC_TCTL_CRC            0x00000004  // Enable CRC Generation
#define MAC_TCTL_PADEN          0x00000002  // Enable Packet Padding
#define MAC_TCTL_TXEN           0x00000001  // Enable Transmitter

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_DATA register.
//
//*****************************************************************************
#define MAC_DATA_TXDATA_M       0xFFFFFFFF  // Transmit FIFO Data
#define MAC_DATA_RXDATA_M       0xFFFFFFFF  // Receive FIFO Data
#define MAC_DATA_RXDATA_S       0
#define MAC_DATA_TXDATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IA0 register.
//
//*****************************************************************************
#define MAC_IA0_MACOCT4_M       0xFF000000  // MAC Address Octet 4
#define MAC_IA0_MACOCT3_M       0x00FF0000  // MAC Address Octet 3
#define MAC_IA0_MACOCT2_M       0x0000FF00  // MAC Address Octet 2
#define MAC_IA0_MACOCT1_M       0x000000FF  // MAC Address Octet 1
#define MAC_IA0_MACOCT4_S       24
#define MAC_IA0_MACOCT3_S       16
#define MAC_IA0_MACOCT2_S       8
#define MAC_IA0_MACOCT1_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_IA1 register.
//
//*****************************************************************************
#define MAC_IA1_MACOCT6_M       0x0000FF00  // MAC Address Octet 6
#define MAC_IA1_MACOCT5_M       0x000000FF  // MAC Address Octet 5
#define MAC_IA1_MACOCT6_S       8
#define MAC_IA1_MACOCT5_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_THR register.
//
//*****************************************************************************
#define MAC_THR_THRESH_M        0x0000003F  // Threshold Value
#define MAC_THR_THRESH_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MCTL register.
//
//*****************************************************************************
#define MAC_MCTL_REGADR_M       0x000000F8  // MII Register Address
#define MAC_MCTL_WRITE          0x00000002  // MII Register Transaction Type
#define MAC_MCTL_START          0x00000001  // MII Register Transaction Enable
#define MAC_MCTL_REGADR_S       3

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MDV register.
//
//*****************************************************************************
#define MAC_MDV_DIV_M           0x000000FF  // Clock Divider
#define MAC_MDV_DIV_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MTXD register.
//
//*****************************************************************************
#define MAC_MTXD_MDTX_M         0x0000FFFF  // MII Register Transmit Data
#define MAC_MTXD_MDTX_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MRXD register.
//
//*****************************************************************************
#define MAC_MRXD_MDRX_M         0x0000FFFF  // MII Register Receive Data
#define MAC_MRXD_MDRX_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_NP register.
//
//*****************************************************************************
#define MAC_NP_NPR_M            0x0000003F  // Number of Packets in Receive
                                            // FIFO
#define MAC_NP_NPR_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_TR register.
//
//*****************************************************************************
#define MAC_TR_NEWTX            0x00000001  // New Transmission

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_LED register.
//
//*****************************************************************************
#define MAC_LED_LED1_M          0x00000F00  // LED1 Source
#define MAC_LED_LED1_LINK       0x00000000  // Link OK
#define MAC_LED_LED1_RXTX       0x00000100  // RX or TX Activity (Default LED1)
#define MAC_LED_LED1_100        0x00000500  // 100BASE-TX mode
#define MAC_LED_LED1_10         0x00000600  // 10BASE-T mode
#define MAC_LED_LED1_DUPLEX     0x00000700  // Full-Duplex
#define MAC_LED_LED1_LINKACT    0x00000800  // Link OK & Blink=RX or TX
                                            // Activity
#define MAC_LED_LED0_M          0x0000000F  // LED0 Source
#define MAC_LED_LED0_LINK       0x00000000  // Link OK (Default LED0)
#define MAC_LED_LED0_RXTX       0x00000001  // RX or TX Activity
#define MAC_LED_LED0_100        0x00000005  // 100BASE-TX mode
#define MAC_LED_LED0_10         0x00000006  // 10BASE-T mode
#define MAC_LED_LED0_DUPLEX     0x00000007  // Full-Duplex
#define MAC_LED_LED0_LINKACT    0x00000008  // Link OK & Blink=RX or TX
                                            // Activity

//*****************************************************************************
//
// The following are defines for the bit fields in the MAC_O_MDIX register.
//
//*****************************************************************************
#define MAC_MDIX_EN             0x00000001  // MDI/MDI-X Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR0 register.
//
//*****************************************************************************
#define PHY_MR0_RESET           0x00008000  // Reset Registers
#define PHY_MR0_LOOPBK          0x00004000  // Loopback Mode
#define PHY_MR0_SPEEDSL         0x00002000  // Speed Select
#define PHY_MR0_ANEGEN          0x00001000  // Auto-Negotiation Enable
#define PHY_MR0_PWRDN           0x00000800  // Power Down
#define PHY_MR0_ISO             0x00000400  // Isolate
#define PHY_MR0_RANEG           0x00000200  // Restart Auto-Negotiation
#define PHY_MR0_DUPLEX          0x00000100  // Set Duplex Mode
#define PHY_MR0_COLT            0x00000080  // Collision Test

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR1 register.
//
//*****************************************************************************
#define PHY_MR1_100X_F          0x00004000  // 100BASE-TX Full-Duplex Mode
#define PHY_MR1_100X_H          0x00002000  // 100BASE-TX Half-Duplex Mode
#define PHY_MR1_10T_F           0x00001000  // 10BASE-T Full-Duplex Mode
#define PHY_MR1_10T_H           0x00000800  // 10BASE-T Half-Duplex Mode
#define PHY_MR1_ANEGC           0x00000020  // Auto-Negotiation Complete
#define PHY_MR1_RFAULT          0x00000010  // Remote Fault
#define PHY_MR1_ANEGA           0x00000008  // Auto-Negotiation
#define PHY_MR1_LINK            0x00000004  // Link Made
#define PHY_MR1_JAB             0x00000002  // Jabber Condition
#define PHY_MR1_EXTD            0x00000001  // Extended Capabilities

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR2 register.
//
//*****************************************************************************
#define PHY_MR2_OUI_M           0x0000FFFF  // Organizationally Unique
                                            // Identifier[21:6]
#define PHY_MR2_OUI_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR3 register.
//
//*****************************************************************************
#define PHY_MR3_OUI_M           0x0000FC00  // Organizationally Unique
                                            // Identifier[5:0]
#define PHY_MR3_MN_M            0x000003F0  // Model Number
#define PHY_MR3_RN_M            0x0000000F  // Revision Number
#define PHY_MR3_OUI_S           10
#define PHY_MR3_MN_S            4
#define PHY_MR3_RN_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR4 register.
//
//*****************************************************************************
#define PHY_MR4_NP              0x00008000  // Next Page
#define PHY_MR4_RF              0x00002000  // Remote Fault
#define PHY_MR4_A3              0x00000100  // Technology Ability Field [3]
#define PHY_MR4_A2              0x00000080  // Technology Ability Field [2]
#define PHY_MR4_A1              0x00000040  // Technology Ability Field [1]
#define PHY_MR4_A0              0x00000020  // Technology Ability Field [0]
#define PHY_MR4_S_M             0x0000001F  // Selector Field
#define PHY_MR4_S_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR5 register.
//
//*****************************************************************************
#define PHY_MR5_NP              0x00008000  // Next Page
#define PHY_MR5_ACK             0x00004000  // Acknowledge
#define PHY_MR5_RF              0x00002000  // Remote Fault
#define PHY_MR5_A_M             0x00001FE0  // Technology Ability Field
#define PHY_MR5_S_M             0x0000001F  // Selector Field
#define PHY_MR5_S_8023          0x00000001  // IEEE Std 802.3
#define PHY_MR5_S_8029          0x00000002  // IEEE Std 802.9 ISLAN-16T
#define PHY_MR5_S_8025          0x00000003  // IEEE Std 802.5
#define PHY_MR5_S_1394          0x00000004  // IEEE Std 1394
#define PHY_MR5_A_S             5

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR6 register.
//
//*****************************************************************************
#define PHY_MR6_PDF             0x00000010  // Parallel Detection Fault
#define PHY_MR6_LPNPA           0x00000008  // Link Partner is Next Page Able
#define PHY_MR6_PRX             0x00000002  // New Page Received
#define PHY_MR6_LPANEGA         0x00000001  // Link Partner is Auto-Negotiation
                                            // Able

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR16 register.
//
//*****************************************************************************
#define PHY_MR16_SR_M           0x000003C0  // Silicon Revision Identifier
#define PHY_MR16_SR_S           6

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR17 register.
//
//*****************************************************************************
#define PHY_MR17_FASTRIP        0x00004000  // 10-BASE-T Fast Mode Enable
#define PHY_MR17_EDPD           0x00002000  // Enable Energy Detect Power Down
#define PHY_MR17_LSQE           0x00000800  // Low Squelch Enable
#define PHY_MR17_FASTEST        0x00000100  // Auto-Negotiation Test Mode
#define PHY_MR17_FGLS           0x00000004  // Force Good Link Status
#define PHY_MR17_ENON           0x00000002  // Energy On

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR27 register.
//
//*****************************************************************************
#define PHY_MR27_XPOL           0x00000010  // Polarity State of 10 BASE-T

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR29 register.
//
//*****************************************************************************
#define PHY_MR29_EONIS          0x00000080  // ENERGYON Interrupt
#define PHY_MR29_ANCOMPIS       0x00000040  // Auto-Negotiation Complete
                                            // Interrupt
#define PHY_MR29_RFLTIS         0x00000020  // Remote Fault Interrupt
#define PHY_MR29_LDIS           0x00000010  // Link Down Interrupt
#define PHY_MR29_LPACKIS        0x00000008  // Auto-Negotiation LP Acknowledge
#define PHY_MR29_PDFIS          0x00000004  // Parallel Detection Fault
#define PHY_MR29_PRXIS          0x00000002  // Auto Negotiation Page Received

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR30 register.
//
//*****************************************************************************
#define PHY_MR30_EONIM          0x00000080  // ENERGYON Interrupt Enabled
#define PHY_MR30_ANCOMPIM       0x00000040  // Auto-Negotiation Complete
                                            // Interrupt Enabled
#define PHY_MR30_RFLTIM         0x00000020  // Remote Fault Interrupt Enabled
#define PHY_MR30_LDIM           0x00000010  // Link Down Interrupt Enabled
#define PHY_MR30_LPACKIM        0x00000008  // Auto-Negotiation LP Acknowledge
                                            // Enabled
#define PHY_MR30_PDFIM          0x00000004  // Parallel Detection Fault Enabled
#define PHY_MR30_PRXIM          0x00000002  // Auto Negotiation Page Received
                                            // Enabled

//*****************************************************************************
//
// The following are defines for the bit fields in the PHY_MR31 register.
//
//*****************************************************************************
#define PHY_MR31_AUTODONE       0x00001000  // Auto Negotiation Done
#define PHY_MR31_SPEED_M        0x0000001C  // HCD Speed Value
#define PHY_MR31_SPEED_10HD     0x00000004  // 10BASE-T half duplex
#define PHY_MR31_SPEED_100HD    0x00000008  // 100BASE-T half duplex
#define PHY_MR31_SPEED_10FD     0x00000014  // 10BASE-T full duplex
#define PHY_MR31_SPEED_100FD    0x00000018  // 100BASE-T full duplex
#define PHY_MR31_SCRDIS         0x00000001  // Scramble Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FADDR register.
//
//*****************************************************************************
#define USB_FADDR_M             0x0000007F  // Function Address
#define USB_FADDR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_POWER register.
//
//*****************************************************************************
#define USB_POWER_ISOUP         0x00000080  // Isochronous Update
#define USB_POWER_SOFTCONN      0x00000040  // Soft Connect/Disconnect
#define USB_POWER_RESET         0x00000008  // RESET Signaling
#define USB_POWER_RESUME        0x00000004  // RESUME Signaling
#define USB_POWER_SUSPEND       0x00000002  // SUSPEND Mode
#define USB_POWER_PWRDNPHY      0x00000001  // Power Down PHY

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXIS register.
//
//*****************************************************************************
#define USB_TXIS_EP15           0x00008000  // TX Endpoint 15 Interrupt
#define USB_TXIS_EP14           0x00004000  // TX Endpoint 14 Interrupt
#define USB_TXIS_EP13           0x00002000  // TX Endpoint 13 Interrupt
#define USB_TXIS_EP12           0x00001000  // TX Endpoint 12 Interrupt
#define USB_TXIS_EP11           0x00000800  // TX Endpoint 11 Interrupt
#define USB_TXIS_EP10           0x00000400  // TX Endpoint 10 Interrupt
#define USB_TXIS_EP9            0x00000200  // TX Endpoint 9 Interrupt
#define USB_TXIS_EP8            0x00000100  // TX Endpoint 8 Interrupt
#define USB_TXIS_EP7            0x00000080  // TX Endpoint 7 Interrupt
#define USB_TXIS_EP6            0x00000040  // TX Endpoint 6 Interrupt
#define USB_TXIS_EP5            0x00000020  // TX Endpoint 5 Interrupt
#define USB_TXIS_EP4            0x00000010  // TX Endpoint 4 Interrupt
#define USB_TXIS_EP3            0x00000008  // TX Endpoint 3 Interrupt
#define USB_TXIS_EP2            0x00000004  // TX Endpoint 2 Interrupt
#define USB_TXIS_EP1            0x00000002  // TX Endpoint 1 Interrupt
#define USB_TXIS_EP0            0x00000001  // TX and RX Endpoint 0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXIS register.
//
//*****************************************************************************
#define USB_RXIS_EP15           0x00008000  // RX Endpoint 15 Interrupt
#define USB_RXIS_EP14           0x00004000  // RX Endpoint 14 Interrupt
#define USB_RXIS_EP13           0x00002000  // RX Endpoint 13 Interrupt
#define USB_RXIS_EP12           0x00001000  // RX Endpoint 12 Interrupt
#define USB_RXIS_EP11           0x00000800  // RX Endpoint 11 Interrupt
#define USB_RXIS_EP10           0x00000400  // RX Endpoint 10 Interrupt
#define USB_RXIS_EP9            0x00000200  // RX Endpoint 9 Interrupt
#define USB_RXIS_EP8            0x00000100  // RX Endpoint 8 Interrupt
#define USB_RXIS_EP7            0x00000080  // RX Endpoint 7 Interrupt
#define USB_RXIS_EP6            0x00000040  // RX Endpoint 6 Interrupt
#define USB_RXIS_EP5            0x00000020  // RX Endpoint 5 Interrupt
#define USB_RXIS_EP4            0x00000010  // RX Endpoint 4 Interrupt
#define USB_RXIS_EP3            0x00000008  // RX Endpoint 3 Interrupt
#define USB_RXIS_EP2            0x00000004  // RX Endpoint 2 Interrupt
#define USB_RXIS_EP1            0x00000002  // RX Endpoint 1 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXIE register.
//
//*****************************************************************************
#define USB_TXIE_EP15           0x00008000  // TX Endpoint 15 Interrupt Enable
#define USB_TXIE_EP14           0x00004000  // TX Endpoint 14 Interrupt Enable
#define USB_TXIE_EP13           0x00002000  // TX Endpoint 13 Interrupt Enable
#define USB_TXIE_EP12           0x00001000  // TX Endpoint 12 Interrupt Enable
#define USB_TXIE_EP11           0x00000800  // TX Endpoint 11 Interrupt Enable
#define USB_TXIE_EP10           0x00000400  // TX Endpoint 10 Interrupt Enable
#define USB_TXIE_EP9            0x00000200  // TX Endpoint 9 Interrupt Enable
#define USB_TXIE_EP8            0x00000100  // TX Endpoint 8 Interrupt Enable
#define USB_TXIE_EP7            0x00000080  // TX Endpoint 7 Interrupt Enable
#define USB_TXIE_EP6            0x00000040  // TX Endpoint 6 Interrupt Enable
#define USB_TXIE_EP5            0x00000020  // TX Endpoint 5 Interrupt Enable
#define USB_TXIE_EP4            0x00000010  // TX Endpoint 4 Interrupt Enable
#define USB_TXIE_EP3            0x00000008  // TX Endpoint 3 Interrupt Enable
#define USB_TXIE_EP2            0x00000004  // TX Endpoint 2 Interrupt Enable
#define USB_TXIE_EP1            0x00000002  // TX Endpoint 1 Interrupt Enable
#define USB_TXIE_EP0            0x00000001  // TX and RX Endpoint 0 Interrupt
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXIE register.
//
//*****************************************************************************
#define USB_RXIE_EP15           0x00008000  // RX Endpoint 15 Interrupt Enable
#define USB_RXIE_EP14           0x00004000  // RX Endpoint 14 Interrupt Enable
#define USB_RXIE_EP13           0x00002000  // RX Endpoint 13 Interrupt Enable
#define USB_RXIE_EP12           0x00001000  // RX Endpoint 12 Interrupt Enable
#define USB_RXIE_EP11           0x00000800  // RX Endpoint 11 Interrupt Enable
#define USB_RXIE_EP10           0x00000400  // RX Endpoint 10 Interrupt Enable
#define USB_RXIE_EP9            0x00000200  // RX Endpoint 9 Interrupt Enable
#define USB_RXIE_EP8            0x00000100  // RX Endpoint 8 Interrupt Enable
#define USB_RXIE_EP7            0x00000080  // RX Endpoint 7 Interrupt Enable
#define USB_RXIE_EP6            0x00000040  // RX Endpoint 6 Interrupt Enable
#define USB_RXIE_EP5            0x00000020  // RX Endpoint 5 Interrupt Enable
#define USB_RXIE_EP4            0x00000010  // RX Endpoint 4 Interrupt Enable
#define USB_RXIE_EP3            0x00000008  // RX Endpoint 3 Interrupt Enable
#define USB_RXIE_EP2            0x00000004  // RX Endpoint 2 Interrupt Enable
#define USB_RXIE_EP1            0x00000002  // RX Endpoint 1 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IS register.
//
//*****************************************************************************
#define USB_IS_VBUSERR          0x00000080  // VBUS Error
#define USB_IS_SESREQ           0x00000040  // SESSION REQUEST
#define USB_IS_DISCON           0x00000020  // Session Disconnect
#define USB_IS_CONN             0x00000010  // Session Connect
#define USB_IS_SOF              0x00000008  // Start of Frame
#define USB_IS_BABBLE           0x00000004  // Babble Detected
#define USB_IS_RESET            0x00000004  // RESET Signaling Detected
#define USB_IS_RESUME           0x00000002  // RESUME Signaling Detected
#define USB_IS_SUSPEND          0x00000001  // SUSPEND Signaling Detected

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IE register.
//
//*****************************************************************************
#define USB_IE_VBUSERR          0x00000080  // Enable VBUS Error Interrupt
#define USB_IE_SESREQ           0x00000040  // Enable Session Request
#define USB_IE_DISCON           0x00000020  // Enable Disconnect Interrupt
#define USB_IE_CONN             0x00000010  // Enable Connect Interrupt
#define USB_IE_SOF              0x00000008  // Enable Start-of-Frame Interrupt
#define USB_IE_BABBLE           0x00000004  // Enable Babble Interrupt
#define USB_IE_RESET            0x00000004  // Enable RESET Interrupt
#define USB_IE_RESUME           0x00000002  // Enable RESUME Interrupt
#define USB_IE_SUSPND           0x00000001  // Enable SUSPEND Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FRAME register.
//
//*****************************************************************************
#define USB_FRAME_M             0x000007FF  // Frame Number
#define USB_FRAME_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPIDX register.
//
//*****************************************************************************
#define USB_EPIDX_EPIDX_M       0x0000000F  // Endpoint Index
#define USB_EPIDX_EPIDX_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TEST register.
//
//*****************************************************************************
#define USB_TEST_FORCEH         0x00000080  // Force Host Mode
#define USB_TEST_FIFOACC        0x00000040  // FIFO Access
#define USB_TEST_FORCEFS        0x00000020  // Force Full-Speed Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO0 register.
//
//*****************************************************************************
#define USB_FIFO0_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO0_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO1 register.
//
//*****************************************************************************
#define USB_FIFO1_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO1_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO2 register.
//
//*****************************************************************************
#define USB_FIFO2_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO2_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO3 register.
//
//*****************************************************************************
#define USB_FIFO3_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO3_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO4 register.
//
//*****************************************************************************
#define USB_FIFO4_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO4_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO5 register.
//
//*****************************************************************************
#define USB_FIFO5_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO5_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO6 register.
//
//*****************************************************************************
#define USB_FIFO6_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO6_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO7 register.
//
//*****************************************************************************
#define USB_FIFO7_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO7_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO8 register.
//
//*****************************************************************************
#define USB_FIFO8_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO8_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO9 register.
//
//*****************************************************************************
#define USB_FIFO9_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO9_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO10 register.
//
//*****************************************************************************
#define USB_FIFO10_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO10_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO11 register.
//
//*****************************************************************************
#define USB_FIFO11_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO11_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO12 register.
//
//*****************************************************************************
#define USB_FIFO12_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO12_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO13 register.
//
//*****************************************************************************
#define USB_FIFO13_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO13_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO14 register.
//
//*****************************************************************************
#define USB_FIFO14_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO14_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO15 register.
//
//*****************************************************************************
#define USB_FIFO15_EPDATA_M     0xFFFFFFFF  // Endpoint Data
#define USB_FIFO15_EPDATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DEVCTL register.
//
//*****************************************************************************
#define USB_DEVCTL_DEV          0x00000080  // Device Mode
#define USB_DEVCTL_FSDEV        0x00000040  // Full-Speed Device Detected
#define USB_DEVCTL_LSDEV        0x00000020  // Low-Speed Device Detected
#define USB_DEVCTL_VBUS_M       0x00000018  // VBUS Level
#define USB_DEVCTL_VBUS_NONE    0x00000000  // Below SessionEnd
#define USB_DEVCTL_VBUS_SEND    0x00000008  // Above SessionEnd, below AValid
#define USB_DEVCTL_VBUS_AVALID  0x00000010  // Above AValid, below VBUSValid
#define USB_DEVCTL_VBUS_VALID   0x00000018  // Above VBUSValid
#define USB_DEVCTL_HOST         0x00000004  // Host Mode
#define USB_DEVCTL_HOSTREQ      0x00000002  // Host Request
#define USB_DEVCTL_SESSION      0x00000001  // Session Start/End

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFIFOSZ register.
//
//*****************************************************************************
#define USB_TXFIFOSZ_DPB        0x00000010  // Double Packet Buffer Support
#define USB_TXFIFOSZ_SIZE_M     0x0000000F  // Max Packet Size
#define USB_TXFIFOSZ_SIZE_8     0x00000000  // 8
#define USB_TXFIFOSZ_SIZE_16    0x00000001  // 16
#define USB_TXFIFOSZ_SIZE_32    0x00000002  // 32
#define USB_TXFIFOSZ_SIZE_64    0x00000003  // 64
#define USB_TXFIFOSZ_SIZE_128   0x00000004  // 128
#define USB_TXFIFOSZ_SIZE_256   0x00000005  // 256
#define USB_TXFIFOSZ_SIZE_512   0x00000006  // 512
#define USB_TXFIFOSZ_SIZE_1024  0x00000007  // 1024
#define USB_TXFIFOSZ_SIZE_2048  0x00000008  // 2048

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFIFOSZ register.
//
//*****************************************************************************
#define USB_RXFIFOSZ_DPB        0x00000010  // Double Packet Buffer Support
#define USB_RXFIFOSZ_SIZE_M     0x0000000F  // Max Packet Size
#define USB_RXFIFOSZ_SIZE_8     0x00000000  // 8
#define USB_RXFIFOSZ_SIZE_16    0x00000001  // 16
#define USB_RXFIFOSZ_SIZE_32    0x00000002  // 32
#define USB_RXFIFOSZ_SIZE_64    0x00000003  // 64
#define USB_RXFIFOSZ_SIZE_128   0x00000004  // 128
#define USB_RXFIFOSZ_SIZE_256   0x00000005  // 256
#define USB_RXFIFOSZ_SIZE_512   0x00000006  // 512
#define USB_RXFIFOSZ_SIZE_1024  0x00000007  // 1024
#define USB_RXFIFOSZ_SIZE_2048  0x00000008  // 2048

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFIFOADD
// register.
//
//*****************************************************************************
#define USB_TXFIFOADD_ADDR_M    0x000001FF  // Transmit/Receive Start Address
#define USB_TXFIFOADD_ADDR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFIFOADD
// register.
//
//*****************************************************************************
#define USB_RXFIFOADD_ADDR_M    0x000001FF  // Transmit/Receive Start Address
#define USB_RXFIFOADD_ADDR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CONTIM register.
//
//*****************************************************************************
#define USB_CONTIM_WTCON_M      0x000000F0  // Connect Wait
#define USB_CONTIM_WTID_M       0x0000000F  // Wait ID
#define USB_CONTIM_WTCON_S      4
#define USB_CONTIM_WTID_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VPLEN register.
//
//*****************************************************************************
#define USB_VPLEN_VPLEN_M       0x000000FF  // VBUS Pulse Length
#define USB_VPLEN_VPLEN_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FSEOF register.
//
//*****************************************************************************
#define USB_FSEOF_FSEOFG_M      0x000000FF  // Full-Speed End-of-Frame Gap
#define USB_FSEOF_FSEOFG_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LSEOF register.
//
//*****************************************************************************
#define USB_LSEOF_LSEOFG_M      0x000000FF  // Low-Speed End-of-Frame Gap
#define USB_LSEOF_LSEOFG_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR0
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR0_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR0_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR0
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR0_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR0_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR0_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT0
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT0_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT0_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR1
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR1_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR1_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR1
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR1_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR1_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR1_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT1
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT1_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT1_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR1
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR1_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR1_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR1
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR1_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR1_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR1_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT1
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT1_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT1_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR2
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR2_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR2_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR2
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR2_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR2_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR2_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT2
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT2_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT2_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR2
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR2_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR2_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR2
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR2_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR2_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR2_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT2
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT2_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT2_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR3
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR3_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR3_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR3
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR3_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR3_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR3_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT3
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT3_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT3_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR3
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR3_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR3_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR3
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR3_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR3_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR3_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT3
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT3_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT3_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR4
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR4_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR4_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR4
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR4_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR4_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR4_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT4
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT4_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT4_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR4
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR4_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR4_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR4
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR4_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR4_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR4_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT4
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT4_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT4_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR5
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR5_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR5_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR5
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR5_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR5_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR5_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT5
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT5_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT5_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR5
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR5_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR5_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR5
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR5_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR5_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR5_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT5
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT5_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT5_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR6
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR6_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR6_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR6
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR6_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR6_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR6_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT6
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT6_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT6_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR6
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR6_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR6_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR6
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR6_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR6_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR6_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT6
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT6_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT6_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR7
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR7_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR7_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR7
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR7_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR7_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR7_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT7
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT7_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT7_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR7
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR7_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR7_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR7
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR7_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR7_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR7_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT7
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT7_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT7_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR8
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR8_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR8_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR8
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR8_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR8_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR8_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT8
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT8_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT8_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR8
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR8_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR8_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR8
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR8_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR8_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR8_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT8
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT8_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT8_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR9
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR9_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR9_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR9
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR9_MULTTRAN 0x00000080  // Multiple Translators
#define USB_TXHUBADDR9_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR9_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT9
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT9_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT9_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR9
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR9_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR9_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR9
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR9_MULTTRAN 0x00000080  // Multiple Translators
#define USB_RXHUBADDR9_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR9_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT9
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT9_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT9_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR10
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR10_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR10_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR10
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR10_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR10_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR10_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT10
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT10_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT10_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR10
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR10_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR10_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR10
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR10_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR10_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR10_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT10
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT10_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT10_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR11
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR11_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR11_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR11
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR11_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR11_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR11_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT11
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT11_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT11_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR11
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR11_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR11_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR11
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR11_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR11_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR11_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT11
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT11_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT11_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR12
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR12_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR12_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR12
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR12_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR12_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR12_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT12
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT12_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT12_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR12
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR12_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR12_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR12
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR12_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR12_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR12_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT12
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT12_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT12_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR13
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR13_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR13_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR13
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR13_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR13_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR13_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT13
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT13_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT13_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR13
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR13_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR13_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR13
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR13_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR13_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR13_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT13
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT13_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT13_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR14
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR14_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR14_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR14
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR14_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR14_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR14_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT14
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT14_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT14_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR14
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR14_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR14_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR14
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR14_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR14_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR14_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT14
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT14_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT14_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR15
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR15_ADDR_M 0x0000007F  // Device Address
#define USB_TXFUNCADDR15_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR15
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR15_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_TXHUBADDR15_ADDR_M  0x0000007F  // Hub Address
#define USB_TXHUBADDR15_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT15
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT15_PORT_M  0x0000007F  // Hub Port
#define USB_TXHUBPORT15_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR15
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR15_ADDR_M 0x0000007F  // Device Address
#define USB_RXFUNCADDR15_ADDR_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR15
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR15_MULTTRAN \
                                0x00000080  // Multiple Translators
#define USB_RXHUBADDR15_ADDR_M  0x0000007F  // Hub Address
#define USB_RXHUBADDR15_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT15
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT15_PORT_M  0x0000007F  // Hub Port
#define USB_RXHUBPORT15_PORT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CSRL0 register.
//
//*****************************************************************************
#define USB_CSRL0_NAKTO         0x00000080  // NAK Timeout
#define USB_CSRL0_SETENDC       0x00000080  // Setup End Clear
#define USB_CSRL0_STATUS        0x00000040  // STATUS Packet
#define USB_CSRL0_RXRDYC        0x00000040  // RXRDY Clear
#define USB_CSRL0_REQPKT        0x00000020  // Request Packet
#define USB_CSRL0_STALL         0x00000020  // Send Stall
#define USB_CSRL0_SETEND        0x00000010  // Setup End
#define USB_CSRL0_ERROR         0x00000010  // Error
#define USB_CSRL0_DATAEND       0x00000008  // Data End
#define USB_CSRL0_SETUP         0x00000008  // Setup Packet
#define USB_CSRL0_STALLED       0x00000004  // Endpoint Stalled
#define USB_CSRL0_TXRDY         0x00000002  // Transmit Packet Ready
#define USB_CSRL0_RXRDY         0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CSRH0 register.
//
//*****************************************************************************
#define USB_CSRH0_DTWE          0x00000004  // Data Toggle Write Enable
#define USB_CSRH0_DT            0x00000002  // Data Toggle
#define USB_CSRH0_FLUSH         0x00000001  // Flush FIFO

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_COUNT0 register.
//
//*****************************************************************************
#define USB_COUNT0_COUNT_M      0x0000007F  // FIFO Count
#define USB_COUNT0_COUNT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TYPE0 register.
//
//*****************************************************************************
#define USB_TYPE0_SPEED_M       0x000000C0  // Operating Speed
#define USB_TYPE0_SPEED_FULL    0x00000080  // Full
#define USB_TYPE0_SPEED_LOW     0x000000C0  // Low

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_NAKLMT register.
//
//*****************************************************************************
#define USB_NAKLMT_NAKLMT_M     0x0000001F  // EP0 NAK Limit
#define USB_NAKLMT_NAKLMT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP1 register.
//
//*****************************************************************************
#define USB_TXMAXP1_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP1_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL1 register.
//
//*****************************************************************************
#define USB_TXCSRL1_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL1_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL1_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL1_STALL       0x00000010  // Send STALL
#define USB_TXCSRL1_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL1_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL1_ERROR       0x00000004  // Error
#define USB_TXCSRL1_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL1_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL1_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH1 register.
//
//*****************************************************************************
#define USB_TXCSRH1_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH1_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH1_MODE        0x00000020  // Mode
#define USB_TXCSRH1_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH1_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH1_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH1_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH1_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP1 register.
//
//*****************************************************************************
#define USB_RXMAXP1_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP1_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL1 register.
//
//*****************************************************************************
#define USB_RXCSRL1_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL1_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL1_STALL       0x00000020  // Send STALL
#define USB_RXCSRL1_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL1_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL1_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL1_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL1_OVER        0x00000004  // Overrun
#define USB_RXCSRL1_ERROR       0x00000004  // Error
#define USB_RXCSRL1_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL1_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH1 register.
//
//*****************************************************************************
#define USB_RXCSRH1_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH1_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH1_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH1_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH1_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH1_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH1_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH1_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH1_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT1 register.
//
//*****************************************************************************
#define USB_RXCOUNT1_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT1_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE1 register.
//
//*****************************************************************************
#define USB_TXTYPE1_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE1_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE1_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE1_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE1_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE1_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE1_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE1_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE1_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE1_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE1_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL1
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL1_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL1_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL1_TXPOLL_S \
                                0
#define USB_TXINTERVAL1_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE1 register.
//
//*****************************************************************************
#define USB_RXTYPE1_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE1_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE1_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE1_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE1_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE1_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE1_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE1_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE1_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE1_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE1_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL1
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL1_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL1_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL1_TXPOLL_S \
                                0
#define USB_RXINTERVAL1_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP2 register.
//
//*****************************************************************************
#define USB_TXMAXP2_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP2_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL2 register.
//
//*****************************************************************************
#define USB_TXCSRL2_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL2_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL2_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL2_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL2_STALL       0x00000010  // Send STALL
#define USB_TXCSRL2_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL2_ERROR       0x00000004  // Error
#define USB_TXCSRL2_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL2_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL2_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH2 register.
//
//*****************************************************************************
#define USB_TXCSRH2_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH2_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH2_MODE        0x00000020  // Mode
#define USB_TXCSRH2_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH2_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH2_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH2_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH2_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP2 register.
//
//*****************************************************************************
#define USB_RXMAXP2_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP2_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL2 register.
//
//*****************************************************************************
#define USB_RXCSRL2_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL2_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL2_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL2_STALL       0x00000020  // Send STALL
#define USB_RXCSRL2_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL2_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL2_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL2_ERROR       0x00000004  // Error
#define USB_RXCSRL2_OVER        0x00000004  // Overrun
#define USB_RXCSRL2_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL2_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH2 register.
//
//*****************************************************************************
#define USB_RXCSRH2_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH2_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH2_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH2_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH2_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH2_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH2_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH2_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH2_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT2 register.
//
//*****************************************************************************
#define USB_RXCOUNT2_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT2_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE2 register.
//
//*****************************************************************************
#define USB_TXTYPE2_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE2_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE2_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE2_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE2_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE2_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE2_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE2_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE2_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE2_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE2_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL2
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL2_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL2_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL2_NAKLMT_S \
                                0
#define USB_TXINTERVAL2_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE2 register.
//
//*****************************************************************************
#define USB_RXTYPE2_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE2_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE2_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE2_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE2_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE2_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE2_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE2_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE2_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE2_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE2_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL2
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL2_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL2_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL2_TXPOLL_S \
                                0
#define USB_RXINTERVAL2_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP3 register.
//
//*****************************************************************************
#define USB_TXMAXP3_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP3_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL3 register.
//
//*****************************************************************************
#define USB_TXCSRL3_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL3_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL3_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL3_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL3_STALL       0x00000010  // Send STALL
#define USB_TXCSRL3_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL3_ERROR       0x00000004  // Error
#define USB_TXCSRL3_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL3_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL3_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH3 register.
//
//*****************************************************************************
#define USB_TXCSRH3_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH3_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH3_MODE        0x00000020  // Mode
#define USB_TXCSRH3_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH3_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH3_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH3_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH3_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP3 register.
//
//*****************************************************************************
#define USB_RXMAXP3_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP3_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL3 register.
//
//*****************************************************************************
#define USB_RXCSRL3_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL3_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL3_STALL       0x00000020  // Send STALL
#define USB_RXCSRL3_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL3_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL3_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL3_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL3_ERROR       0x00000004  // Error
#define USB_RXCSRL3_OVER        0x00000004  // Overrun
#define USB_RXCSRL3_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL3_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH3 register.
//
//*****************************************************************************
#define USB_RXCSRH3_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH3_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH3_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH3_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH3_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH3_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH3_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH3_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH3_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT3 register.
//
//*****************************************************************************
#define USB_RXCOUNT3_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT3_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE3 register.
//
//*****************************************************************************
#define USB_TXTYPE3_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE3_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE3_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE3_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE3_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE3_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE3_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE3_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE3_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE3_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE3_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL3
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL3_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL3_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL3_TXPOLL_S \
                                0
#define USB_TXINTERVAL3_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE3 register.
//
//*****************************************************************************
#define USB_RXTYPE3_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE3_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE3_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE3_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE3_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE3_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE3_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE3_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE3_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE3_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE3_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL3
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL3_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL3_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL3_TXPOLL_S \
                                0
#define USB_RXINTERVAL3_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP4 register.
//
//*****************************************************************************
#define USB_TXMAXP4_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP4_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL4 register.
//
//*****************************************************************************
#define USB_TXCSRL4_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL4_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL4_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL4_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL4_STALL       0x00000010  // Send STALL
#define USB_TXCSRL4_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL4_ERROR       0x00000004  // Error
#define USB_TXCSRL4_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL4_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL4_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH4 register.
//
//*****************************************************************************
#define USB_TXCSRH4_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH4_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH4_MODE        0x00000020  // Mode
#define USB_TXCSRH4_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH4_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH4_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH4_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH4_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP4 register.
//
//*****************************************************************************
#define USB_RXMAXP4_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP4_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL4 register.
//
//*****************************************************************************
#define USB_RXCSRL4_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL4_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL4_STALL       0x00000020  // Send STALL
#define USB_RXCSRL4_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL4_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL4_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL4_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL4_OVER        0x00000004  // Overrun
#define USB_RXCSRL4_ERROR       0x00000004  // Error
#define USB_RXCSRL4_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL4_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH4 register.
//
//*****************************************************************************
#define USB_RXCSRH4_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH4_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH4_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH4_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH4_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH4_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH4_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH4_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH4_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT4 register.
//
//*****************************************************************************
#define USB_RXCOUNT4_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT4_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE4 register.
//
//*****************************************************************************
#define USB_TXTYPE4_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE4_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE4_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE4_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE4_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE4_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE4_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE4_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE4_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE4_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE4_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL4
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL4_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL4_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL4_NAKLMT_S \
                                0
#define USB_TXINTERVAL4_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE4 register.
//
//*****************************************************************************
#define USB_RXTYPE4_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE4_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE4_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE4_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE4_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE4_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE4_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE4_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE4_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE4_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE4_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL4
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL4_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL4_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL4_NAKLMT_S \
                                0
#define USB_RXINTERVAL4_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP5 register.
//
//*****************************************************************************
#define USB_TXMAXP5_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP5_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL5 register.
//
//*****************************************************************************
#define USB_TXCSRL5_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL5_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL5_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL5_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL5_STALL       0x00000010  // Send STALL
#define USB_TXCSRL5_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL5_ERROR       0x00000004  // Error
#define USB_TXCSRL5_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL5_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL5_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH5 register.
//
//*****************************************************************************
#define USB_TXCSRH5_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH5_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH5_MODE        0x00000020  // Mode
#define USB_TXCSRH5_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH5_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH5_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH5_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH5_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP5 register.
//
//*****************************************************************************
#define USB_RXMAXP5_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP5_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL5 register.
//
//*****************************************************************************
#define USB_RXCSRL5_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL5_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL5_STALL       0x00000020  // Send STALL
#define USB_RXCSRL5_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL5_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL5_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL5_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL5_ERROR       0x00000004  // Error
#define USB_RXCSRL5_OVER        0x00000004  // Overrun
#define USB_RXCSRL5_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL5_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH5 register.
//
//*****************************************************************************
#define USB_RXCSRH5_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH5_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH5_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH5_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH5_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH5_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH5_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH5_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH5_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT5 register.
//
//*****************************************************************************
#define USB_RXCOUNT5_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT5_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE5 register.
//
//*****************************************************************************
#define USB_TXTYPE5_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE5_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE5_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE5_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE5_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE5_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE5_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE5_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE5_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE5_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE5_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL5
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL5_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL5_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL5_NAKLMT_S \
                                0
#define USB_TXINTERVAL5_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE5 register.
//
//*****************************************************************************
#define USB_RXTYPE5_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE5_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE5_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE5_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE5_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE5_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE5_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE5_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE5_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE5_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE5_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL5
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL5_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL5_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL5_TXPOLL_S \
                                0
#define USB_RXINTERVAL5_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP6 register.
//
//*****************************************************************************
#define USB_TXMAXP6_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP6_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL6 register.
//
//*****************************************************************************
#define USB_TXCSRL6_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL6_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL6_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL6_STALL       0x00000010  // Send STALL
#define USB_TXCSRL6_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL6_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL6_ERROR       0x00000004  // Error
#define USB_TXCSRL6_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL6_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL6_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH6 register.
//
//*****************************************************************************
#define USB_TXCSRH6_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH6_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH6_MODE        0x00000020  // Mode
#define USB_TXCSRH6_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH6_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH6_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH6_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH6_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP6 register.
//
//*****************************************************************************
#define USB_RXMAXP6_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP6_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL6 register.
//
//*****************************************************************************
#define USB_RXCSRL6_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL6_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL6_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL6_STALL       0x00000020  // Send STALL
#define USB_RXCSRL6_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL6_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL6_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL6_ERROR       0x00000004  // Error
#define USB_RXCSRL6_OVER        0x00000004  // Overrun
#define USB_RXCSRL6_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL6_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH6 register.
//
//*****************************************************************************
#define USB_RXCSRH6_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH6_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH6_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH6_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH6_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH6_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH6_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH6_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH6_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT6 register.
//
//*****************************************************************************
#define USB_RXCOUNT6_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT6_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE6 register.
//
//*****************************************************************************
#define USB_TXTYPE6_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE6_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE6_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE6_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE6_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE6_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE6_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE6_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE6_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE6_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE6_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL6
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL6_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL6_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL6_TXPOLL_S \
                                0
#define USB_TXINTERVAL6_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE6 register.
//
//*****************************************************************************
#define USB_RXTYPE6_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE6_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE6_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE6_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE6_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE6_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE6_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE6_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE6_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE6_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE6_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL6
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL6_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL6_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL6_NAKLMT_S \
                                0
#define USB_RXINTERVAL6_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP7 register.
//
//*****************************************************************************
#define USB_TXMAXP7_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP7_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL7 register.
//
//*****************************************************************************
#define USB_TXCSRL7_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL7_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL7_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL7_STALL       0x00000010  // Send STALL
#define USB_TXCSRL7_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL7_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL7_ERROR       0x00000004  // Error
#define USB_TXCSRL7_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL7_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL7_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH7 register.
//
//*****************************************************************************
#define USB_TXCSRH7_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH7_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH7_MODE        0x00000020  // Mode
#define USB_TXCSRH7_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH7_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH7_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH7_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH7_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP7 register.
//
//*****************************************************************************
#define USB_RXMAXP7_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP7_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL7 register.
//
//*****************************************************************************
#define USB_RXCSRL7_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL7_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL7_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL7_STALL       0x00000020  // Send STALL
#define USB_RXCSRL7_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL7_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL7_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL7_ERROR       0x00000004  // Error
#define USB_RXCSRL7_OVER        0x00000004  // Overrun
#define USB_RXCSRL7_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL7_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH7 register.
//
//*****************************************************************************
#define USB_RXCSRH7_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH7_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH7_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH7_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH7_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH7_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH7_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH7_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH7_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT7 register.
//
//*****************************************************************************
#define USB_RXCOUNT7_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT7_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE7 register.
//
//*****************************************************************************
#define USB_TXTYPE7_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE7_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE7_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE7_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE7_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE7_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE7_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE7_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE7_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE7_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE7_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL7
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL7_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL7_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL7_NAKLMT_S \
                                0
#define USB_TXINTERVAL7_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE7 register.
//
//*****************************************************************************
#define USB_RXTYPE7_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE7_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE7_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE7_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE7_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE7_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE7_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE7_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE7_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE7_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE7_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL7
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL7_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL7_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL7_NAKLMT_S \
                                0
#define USB_RXINTERVAL7_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP8 register.
//
//*****************************************************************************
#define USB_TXMAXP8_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP8_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL8 register.
//
//*****************************************************************************
#define USB_TXCSRL8_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL8_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL8_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL8_STALL       0x00000010  // Send STALL
#define USB_TXCSRL8_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL8_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL8_ERROR       0x00000004  // Error
#define USB_TXCSRL8_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL8_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL8_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH8 register.
//
//*****************************************************************************
#define USB_TXCSRH8_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH8_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH8_MODE        0x00000020  // Mode
#define USB_TXCSRH8_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH8_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH8_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH8_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH8_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP8 register.
//
//*****************************************************************************
#define USB_RXMAXP8_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP8_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL8 register.
//
//*****************************************************************************
#define USB_RXCSRL8_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL8_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL8_STALL       0x00000020  // Send STALL
#define USB_RXCSRL8_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL8_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL8_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL8_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL8_OVER        0x00000004  // Overrun
#define USB_RXCSRL8_ERROR       0x00000004  // Error
#define USB_RXCSRL8_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL8_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH8 register.
//
//*****************************************************************************
#define USB_RXCSRH8_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH8_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH8_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH8_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH8_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH8_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH8_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH8_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH8_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT8 register.
//
//*****************************************************************************
#define USB_RXCOUNT8_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT8_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE8 register.
//
//*****************************************************************************
#define USB_TXTYPE8_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE8_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE8_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE8_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE8_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE8_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE8_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE8_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE8_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE8_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE8_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL8
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL8_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL8_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL8_NAKLMT_S \
                                0
#define USB_TXINTERVAL8_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE8 register.
//
//*****************************************************************************
#define USB_RXTYPE8_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE8_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE8_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE8_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE8_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE8_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE8_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE8_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE8_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE8_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE8_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL8
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL8_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL8_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL8_NAKLMT_S \
                                0
#define USB_RXINTERVAL8_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP9 register.
//
//*****************************************************************************
#define USB_TXMAXP9_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP9_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL9 register.
//
//*****************************************************************************
#define USB_TXCSRL9_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL9_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL9_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL9_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL9_STALL       0x00000010  // Send STALL
#define USB_TXCSRL9_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL9_ERROR       0x00000004  // Error
#define USB_TXCSRL9_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL9_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL9_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH9 register.
//
//*****************************************************************************
#define USB_TXCSRH9_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH9_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH9_MODE        0x00000020  // Mode
#define USB_TXCSRH9_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH9_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH9_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH9_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH9_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP9 register.
//
//*****************************************************************************
#define USB_RXMAXP9_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP9_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL9 register.
//
//*****************************************************************************
#define USB_RXCSRL9_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL9_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL9_STALL       0x00000020  // Send STALL
#define USB_RXCSRL9_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL9_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL9_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL9_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL9_ERROR       0x00000004  // Error
#define USB_RXCSRL9_OVER        0x00000004  // Overrun
#define USB_RXCSRL9_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL9_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH9 register.
//
//*****************************************************************************
#define USB_RXCSRH9_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH9_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH9_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH9_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH9_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH9_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH9_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH9_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH9_DT          0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT9 register.
//
//*****************************************************************************
#define USB_RXCOUNT9_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT9_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE9 register.
//
//*****************************************************************************
#define USB_TXTYPE9_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE9_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE9_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE9_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE9_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE9_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE9_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE9_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE9_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE9_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE9_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL9
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL9_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL9_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL9_TXPOLL_S \
                                0
#define USB_TXINTERVAL9_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE9 register.
//
//*****************************************************************************
#define USB_RXTYPE9_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE9_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE9_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE9_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE9_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE9_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE9_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE9_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE9_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE9_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE9_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL9
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL9_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL9_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL9_NAKLMT_S \
                                0
#define USB_RXINTERVAL9_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP10 register.
//
//*****************************************************************************
#define USB_TXMAXP10_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP10_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL10 register.
//
//*****************************************************************************
#define USB_TXCSRL10_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL10_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL10_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL10_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL10_STALL      0x00000010  // Send STALL
#define USB_TXCSRL10_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL10_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL10_ERROR      0x00000004  // Error
#define USB_TXCSRL10_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL10_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH10 register.
//
//*****************************************************************************
#define USB_TXCSRH10_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH10_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH10_MODE       0x00000020  // Mode
#define USB_TXCSRH10_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH10_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH10_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH10_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH10_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP10 register.
//
//*****************************************************************************
#define USB_RXMAXP10_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP10_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL10 register.
//
//*****************************************************************************
#define USB_RXCSRL10_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL10_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL10_STALL      0x00000020  // Send STALL
#define USB_RXCSRL10_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL10_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL10_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL10_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL10_OVER       0x00000004  // Overrun
#define USB_RXCSRL10_ERROR      0x00000004  // Error
#define USB_RXCSRL10_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL10_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH10 register.
//
//*****************************************************************************
#define USB_RXCSRH10_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH10_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH10_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH10_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH10_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH10_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH10_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH10_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH10_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT10
// register.
//
//*****************************************************************************
#define USB_RXCOUNT10_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT10_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE10 register.
//
//*****************************************************************************
#define USB_TXTYPE10_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE10_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE10_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE10_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE10_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE10_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE10_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE10_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE10_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE10_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE10_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL10
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL10_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL10_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL10_TXPOLL_S \
                                0
#define USB_TXINTERVAL10_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE10 register.
//
//*****************************************************************************
#define USB_RXTYPE10_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE10_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE10_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE10_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE10_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE10_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE10_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE10_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE10_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE10_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE10_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL10
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL10_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL10_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL10_TXPOLL_S \
                                0
#define USB_RXINTERVAL10_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP11 register.
//
//*****************************************************************************
#define USB_TXMAXP11_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP11_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL11 register.
//
//*****************************************************************************
#define USB_TXCSRL11_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL11_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL11_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL11_STALL      0x00000010  // Send STALL
#define USB_TXCSRL11_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL11_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL11_ERROR      0x00000004  // Error
#define USB_TXCSRL11_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL11_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL11_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH11 register.
//
//*****************************************************************************
#define USB_TXCSRH11_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH11_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH11_MODE       0x00000020  // Mode
#define USB_TXCSRH11_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH11_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH11_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH11_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH11_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP11 register.
//
//*****************************************************************************
#define USB_RXMAXP11_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP11_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL11 register.
//
//*****************************************************************************
#define USB_RXCSRL11_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL11_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL11_STALL      0x00000020  // Send STALL
#define USB_RXCSRL11_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL11_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL11_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL11_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL11_OVER       0x00000004  // Overrun
#define USB_RXCSRL11_ERROR      0x00000004  // Error
#define USB_RXCSRL11_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL11_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH11 register.
//
//*****************************************************************************
#define USB_RXCSRH11_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH11_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH11_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH11_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH11_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH11_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH11_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH11_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH11_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT11
// register.
//
//*****************************************************************************
#define USB_RXCOUNT11_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT11_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE11 register.
//
//*****************************************************************************
#define USB_TXTYPE11_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE11_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE11_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE11_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE11_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE11_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE11_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE11_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE11_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE11_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE11_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL11
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL11_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL11_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL11_NAKLMT_S \
                                0
#define USB_TXINTERVAL11_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE11 register.
//
//*****************************************************************************
#define USB_RXTYPE11_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE11_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE11_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE11_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE11_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE11_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE11_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE11_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE11_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE11_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE11_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL11
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL11_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL11_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL11_TXPOLL_S \
                                0
#define USB_RXINTERVAL11_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP12 register.
//
//*****************************************************************************
#define USB_TXMAXP12_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP12_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL12 register.
//
//*****************************************************************************
#define USB_TXCSRL12_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL12_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL12_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL12_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL12_STALL      0x00000010  // Send STALL
#define USB_TXCSRL12_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL12_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL12_ERROR      0x00000004  // Error
#define USB_TXCSRL12_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL12_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH12 register.
//
//*****************************************************************************
#define USB_TXCSRH12_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH12_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH12_MODE       0x00000020  // Mode
#define USB_TXCSRH12_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH12_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH12_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH12_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH12_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP12 register.
//
//*****************************************************************************
#define USB_RXMAXP12_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP12_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL12 register.
//
//*****************************************************************************
#define USB_RXCSRL12_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL12_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL12_STALL      0x00000020  // Send STALL
#define USB_RXCSRL12_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL12_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL12_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL12_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL12_ERROR      0x00000004  // Error
#define USB_RXCSRL12_OVER       0x00000004  // Overrun
#define USB_RXCSRL12_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL12_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH12 register.
//
//*****************************************************************************
#define USB_RXCSRH12_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH12_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH12_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH12_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH12_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH12_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH12_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH12_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH12_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT12
// register.
//
//*****************************************************************************
#define USB_RXCOUNT12_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT12_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE12 register.
//
//*****************************************************************************
#define USB_TXTYPE12_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE12_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE12_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE12_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE12_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE12_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE12_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE12_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE12_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE12_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE12_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL12
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL12_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL12_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL12_TXPOLL_S \
                                0
#define USB_TXINTERVAL12_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE12 register.
//
//*****************************************************************************
#define USB_RXTYPE12_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE12_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE12_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE12_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE12_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE12_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE12_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE12_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE12_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE12_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE12_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL12
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL12_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL12_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL12_NAKLMT_S \
                                0
#define USB_RXINTERVAL12_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP13 register.
//
//*****************************************************************************
#define USB_TXMAXP13_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP13_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL13 register.
//
//*****************************************************************************
#define USB_TXCSRL13_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL13_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL13_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL13_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL13_STALL      0x00000010  // Send STALL
#define USB_TXCSRL13_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL13_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL13_ERROR      0x00000004  // Error
#define USB_TXCSRL13_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL13_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH13 register.
//
//*****************************************************************************
#define USB_TXCSRH13_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH13_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH13_MODE       0x00000020  // Mode
#define USB_TXCSRH13_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH13_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH13_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH13_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH13_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP13 register.
//
//*****************************************************************************
#define USB_RXMAXP13_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP13_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL13 register.
//
//*****************************************************************************
#define USB_RXCSRL13_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL13_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL13_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL13_STALL      0x00000020  // Send STALL
#define USB_RXCSRL13_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL13_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL13_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL13_OVER       0x00000004  // Overrun
#define USB_RXCSRL13_ERROR      0x00000004  // Error
#define USB_RXCSRL13_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL13_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH13 register.
//
//*****************************************************************************
#define USB_RXCSRH13_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH13_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH13_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH13_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH13_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH13_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH13_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH13_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH13_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT13
// register.
//
//*****************************************************************************
#define USB_RXCOUNT13_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT13_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE13 register.
//
//*****************************************************************************
#define USB_TXTYPE13_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE13_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE13_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE13_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE13_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE13_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE13_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE13_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE13_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE13_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE13_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL13
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL13_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL13_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL13_TXPOLL_S \
                                0
#define USB_TXINTERVAL13_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE13 register.
//
//*****************************************************************************
#define USB_RXTYPE13_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE13_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE13_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE13_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE13_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE13_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE13_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE13_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE13_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE13_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE13_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL13
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL13_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL13_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL13_TXPOLL_S \
                                0
#define USB_RXINTERVAL13_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP14 register.
//
//*****************************************************************************
#define USB_TXMAXP14_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP14_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL14 register.
//
//*****************************************************************************
#define USB_TXCSRL14_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL14_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL14_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL14_STALL      0x00000010  // Send STALL
#define USB_TXCSRL14_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL14_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL14_ERROR      0x00000004  // Error
#define USB_TXCSRL14_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL14_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL14_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH14 register.
//
//*****************************************************************************
#define USB_TXCSRH14_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH14_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH14_MODE       0x00000020  // Mode
#define USB_TXCSRH14_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH14_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH14_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH14_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH14_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP14 register.
//
//*****************************************************************************
#define USB_RXMAXP14_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP14_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL14 register.
//
//*****************************************************************************
#define USB_RXCSRL14_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL14_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL14_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL14_STALL      0x00000020  // Send STALL
#define USB_RXCSRL14_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL14_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL14_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL14_OVER       0x00000004  // Overrun
#define USB_RXCSRL14_ERROR      0x00000004  // Error
#define USB_RXCSRL14_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL14_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH14 register.
//
//*****************************************************************************
#define USB_RXCSRH14_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH14_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH14_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH14_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH14_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH14_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH14_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH14_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH14_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT14
// register.
//
//*****************************************************************************
#define USB_RXCOUNT14_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT14_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE14 register.
//
//*****************************************************************************
#define USB_TXTYPE14_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE14_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE14_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE14_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE14_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE14_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE14_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE14_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE14_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE14_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE14_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL14
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL14_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL14_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL14_TXPOLL_S \
                                0
#define USB_TXINTERVAL14_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE14 register.
//
//*****************************************************************************
#define USB_RXTYPE14_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE14_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE14_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE14_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE14_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE14_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE14_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE14_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE14_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE14_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE14_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL14
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL14_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL14_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL14_TXPOLL_S \
                                0
#define USB_RXINTERVAL14_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP15 register.
//
//*****************************************************************************
#define USB_TXMAXP15_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_TXMAXP15_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL15 register.
//
//*****************************************************************************
#define USB_TXCSRL15_NAKTO      0x00000080  // NAK Timeout
#define USB_TXCSRL15_CLRDT      0x00000040  // Clear Data Toggle
#define USB_TXCSRL15_STALLED    0x00000020  // Endpoint Stalled
#define USB_TXCSRL15_SETUP      0x00000010  // Setup Packet
#define USB_TXCSRL15_STALL      0x00000010  // Send STALL
#define USB_TXCSRL15_FLUSH      0x00000008  // Flush FIFO
#define USB_TXCSRL15_UNDRN      0x00000004  // Underrun
#define USB_TXCSRL15_ERROR      0x00000004  // Error
#define USB_TXCSRL15_FIFONE     0x00000002  // FIFO Not Empty
#define USB_TXCSRL15_TXRDY      0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH15 register.
//
//*****************************************************************************
#define USB_TXCSRH15_AUTOSET    0x00000080  // Auto Set
#define USB_TXCSRH15_ISO        0x00000040  // Isochronous Transfers
#define USB_TXCSRH15_MODE       0x00000020  // Mode
#define USB_TXCSRH15_DMAEN      0x00000010  // DMA Request Enable
#define USB_TXCSRH15_FDT        0x00000008  // Force Data Toggle
#define USB_TXCSRH15_DMAMOD     0x00000004  // DMA Request Mode
#define USB_TXCSRH15_DTWE       0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH15_DT         0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP15 register.
//
//*****************************************************************************
#define USB_RXMAXP15_MAXLOAD_M  0x000007FF  // Maximum Payload
#define USB_RXMAXP15_MAXLOAD_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL15 register.
//
//*****************************************************************************
#define USB_RXCSRL15_CLRDT      0x00000080  // Clear Data Toggle
#define USB_RXCSRL15_STALLED    0x00000040  // Endpoint Stalled
#define USB_RXCSRL15_STALL      0x00000020  // Send STALL
#define USB_RXCSRL15_REQPKT     0x00000020  // Request Packet
#define USB_RXCSRL15_FLUSH      0x00000010  // Flush FIFO
#define USB_RXCSRL15_DATAERR    0x00000008  // Data Error
#define USB_RXCSRL15_NAKTO      0x00000008  // NAK Timeout
#define USB_RXCSRL15_ERROR      0x00000004  // Error
#define USB_RXCSRL15_OVER       0x00000004  // Overrun
#define USB_RXCSRL15_FULL       0x00000002  // FIFO Full
#define USB_RXCSRL15_RXRDY      0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH15 register.
//
//*****************************************************************************
#define USB_RXCSRH15_AUTOCL     0x00000080  // Auto Clear
#define USB_RXCSRH15_AUTORQ     0x00000040  // Auto Request
#define USB_RXCSRH15_ISO        0x00000040  // Isochronous Transfers
#define USB_RXCSRH15_DMAEN      0x00000020  // DMA Request Enable
#define USB_RXCSRH15_PIDERR     0x00000010  // PID Error
#define USB_RXCSRH15_DISNYET    0x00000010  // Disable NYET
#define USB_RXCSRH15_DMAMOD     0x00000008  // DMA Request Mode
#define USB_RXCSRH15_DTWE       0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH15_DT         0x00000002  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT15
// register.
//
//*****************************************************************************
#define USB_RXCOUNT15_COUNT_M   0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT15_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE15 register.
//
//*****************************************************************************
#define USB_TXTYPE15_SPEED_M    0x000000C0  // Operating Speed
#define USB_TXTYPE15_SPEED_DFLT 0x00000000  // Default
#define USB_TXTYPE15_SPEED_FULL 0x00000080  // Full
#define USB_TXTYPE15_SPEED_LOW  0x000000C0  // Low
#define USB_TXTYPE15_PROTO_M    0x00000030  // Protocol
#define USB_TXTYPE15_PROTO_CTRL 0x00000000  // Control
#define USB_TXTYPE15_PROTO_ISOC 0x00000010  // Isochronous
#define USB_TXTYPE15_PROTO_BULK 0x00000020  // Bulk
#define USB_TXTYPE15_PROTO_INT  0x00000030  // Interrupt
#define USB_TXTYPE15_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_TXTYPE15_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL15
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL15_TXPOLL_M \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL15_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL15_NAKLMT_S \
                                0
#define USB_TXINTERVAL15_TXPOLL_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE15 register.
//
//*****************************************************************************
#define USB_RXTYPE15_SPEED_M    0x000000C0  // Operating Speed
#define USB_RXTYPE15_SPEED_DFLT 0x00000000  // Default
#define USB_RXTYPE15_SPEED_FULL 0x00000080  // Full
#define USB_RXTYPE15_SPEED_LOW  0x000000C0  // Low
#define USB_RXTYPE15_PROTO_M    0x00000030  // Protocol
#define USB_RXTYPE15_PROTO_CTRL 0x00000000  // Control
#define USB_RXTYPE15_PROTO_ISOC 0x00000010  // Isochronous
#define USB_RXTYPE15_PROTO_BULK 0x00000020  // Bulk
#define USB_RXTYPE15_PROTO_INT  0x00000030  // Interrupt
#define USB_RXTYPE15_TEP_M      0x0000000F  // Target Endpoint Number
#define USB_RXTYPE15_TEP_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL15
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL15_TXPOLL_M \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL15_NAKLMT_M \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL15_TXPOLL_S \
                                0
#define USB_RXINTERVAL15_NAKLMT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT1
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT1_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT1_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT2
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT2_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT2_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT3
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT3_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT3_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT4
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT4_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT4_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT5
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT5_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT5_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT6
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT6_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT6_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT7
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT7_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT7_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT8
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT8_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT8_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT9
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT9_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT9_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT10
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT10_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT10_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT11
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT11_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT11_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT12
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT12_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT12_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT13
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT13_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT13_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT14
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT14_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT14_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT15
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT15_COUNT_M \
                                0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT15_COUNT_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXDPKTBUFDIS
// register.
//
//*****************************************************************************
#define USB_RXDPKTBUFDIS_EP15   0x00008000  // EP15 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP14   0x00004000  // EP14 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP13   0x00002000  // EP13 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP12   0x00001000  // EP12 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP11   0x00000800  // EP11 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP10   0x00000400  // EP10 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP9    0x00000200  // EP9 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP8    0x00000100  // EP8 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP7    0x00000080  // EP7 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP6    0x00000040  // EP6 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP5    0x00000020  // EP5 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP4    0x00000010  // EP4 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP3    0x00000008  // EP3 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP2    0x00000004  // EP2 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP1    0x00000002  // EP1 RX Double-Packet Buffer
                                            // Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXDPKTBUFDIS
// register.
//
//*****************************************************************************
#define USB_TXDPKTBUFDIS_EP15   0x00008000  // EP15 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP14   0x00004000  // EP14 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP13   0x00002000  // EP13 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP12   0x00001000  // EP12 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP11   0x00000800  // EP11 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP10   0x00000400  // EP10 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP9    0x00000200  // EP9 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP8    0x00000100  // EP8 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP7    0x00000080  // EP7 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP6    0x00000040  // EP6 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP5    0x00000020  // EP5 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP4    0x00000010  // EP4 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP3    0x00000008  // EP3 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP2    0x00000004  // EP2 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP1    0x00000002  // EP1 TX Double-Packet Buffer
                                            // Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPC register.
//
//*****************************************************************************
#define USB_EPC_PFLTACT_M       0x00000300  // Power Fault Action
#define USB_EPC_PFLTACT_UNCHG   0x00000000  // Unchanged
#define USB_EPC_PFLTACT_TRIS    0x00000100  // Tristate
#define USB_EPC_PFLTACT_LOW     0x00000200  // Low
#define USB_EPC_PFLTACT_HIGH    0x00000300  // High
#define USB_EPC_PFLTAEN         0x00000040  // Power Fault Action Enable
#define USB_EPC_PFLTSEN_HIGH    0x00000020  // Power Fault Sense
#define USB_EPC_PFLTEN          0x00000010  // Power Fault Input Enable
#define USB_EPC_EPENDE          0x00000004  // EPEN Drive Enable
#define USB_EPC_EPEN_M          0x00000003  // External Power Supply Enable
                                            // Configuration
#define USB_EPC_EPEN_LOW        0x00000000  // Power Enable Active Low
#define USB_EPC_EPEN_HIGH       0x00000001  // Power Enable Active High
#define USB_EPC_EPEN_VBLOW      0x00000002  // Power Enable High if VBUS Low
#define USB_EPC_EPEN_VBHIGH     0x00000003  // Power Enable High if VBUS High

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCRIS register.
//
//*****************************************************************************
#define USB_EPCRIS_PF           0x00000001  // USB Power Fault Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCIM register.
//
//*****************************************************************************
#define USB_EPCIM_PF            0x00000001  // USB Power Fault Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCISC register.
//
//*****************************************************************************
#define USB_EPCISC_PF           0x00000001  // USB Power Fault Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRRIS register.
//
//*****************************************************************************
#define USB_DRRIS_RESUME        0x00000001  // RESUME Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRIM register.
//
//*****************************************************************************
#define USB_DRIM_RESUME         0x00000001  // RESUME Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRISC register.
//
//*****************************************************************************
#define USB_DRISC_RESUME        0x00000001  // RESUME Interrupt Status and
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_GPCS register.
//
//*****************************************************************************
#define USB_GPCS_DEVMODOTG      0x00000002  // Enable Device Mode
#define USB_GPCS_DEVMOD         0x00000001  // Device Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDC register.
//
//*****************************************************************************
#define USB_VDC_VBDEN           0x00000001  // VBUS Droop Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCRIS register.
//
//*****************************************************************************
#define USB_VDCRIS_VD           0x00000001  // VBUS Droop Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCIM register.
//
//*****************************************************************************
#define USB_VDCIM_VD            0x00000001  // VBUS Droop Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCISC register.
//
//*****************************************************************************
#define USB_VDCISC_VD           0x00000001  // VBUS Droop Interrupt Status and
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IDVRIS register.
//
//*****************************************************************************
#define USB_IDVRIS_ID           0x00000001  // ID Valid Detect Raw Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IDVIM register.
//
//*****************************************************************************
#define USB_IDVIM_ID            0x00000001  // ID Valid Detect Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IDVISC register.
//
//*****************************************************************************
#define USB_IDVISC_ID           0x00000001  // ID Valid Detect Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMASEL register.
//
//*****************************************************************************
#define USB_DMASEL_DMACTX_M     0x00F00000  // DMA C TX Select
#define USB_DMASEL_DMACRX_M     0x000F0000  // DMA C RX Select
#define USB_DMASEL_DMABTX_M     0x0000F000  // DMA B TX Select
#define USB_DMASEL_DMABRX_M     0x00000F00  // DMA B RX Select
#define USB_DMASEL_DMAATX_M     0x000000F0  // DMA A TX Select
#define USB_DMASEL_DMAARX_M     0x0000000F  // DMA A RX Select
#define USB_DMASEL_DMABTX_S     12
#define USB_DMASEL_DMABRX_S     8
#define USB_DMASEL_DMAATX_S     4
#define USB_DMASEL_DMAARX_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXFIFO register.
//
//*****************************************************************************
#define I2S_TXFIFO_M            0xFFFFFFFF  // TX Data
#define I2S_TXFIFO_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXFIFOCFG
// register.
//
//*****************************************************************************
#define I2S_TXFIFOCFG_CSS       0x00000002  // Compact Stereo Sample Size
#define I2S_TXFIFOCFG_LRS       0x00000001  // Left-Right Sample Indicator

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXCFG register.
//
//*****************************************************************************
#define I2S_TXCFG_JST           0x20000000  // Justification of Output Data
#define I2S_TXCFG_DLY           0x10000000  // Data Delay
#define I2S_TXCFG_SCP           0x08000000  // SCLK Polarity
#define I2S_TXCFG_LRP           0x04000000  // Left/Right Clock Polarity
#define I2S_TXCFG_WM_M          0x03000000  // Write Mode
#define I2S_TXCFG_WM_DUAL       0x00000000  // Stereo mode
#define I2S_TXCFG_WM_COMPACT    0x01000000  // Compact Stereo mode
#define I2S_TXCFG_WM_MONO       0x02000000  // Mono mode
#define I2S_TXCFG_FMT           0x00800000  // FIFO Empty
#define I2S_TXCFG_MSL           0x00400000  // SCLK Master/Slave
#define I2S_TXCFG_SSZ_M         0x0000FC00  // Sample Size
#define I2S_TXCFG_SDSZ_M        0x000003F0  // System Data Size
#define I2S_TXCFG_SSZ_S         10
#define I2S_TXCFG_SDSZ_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXLIMIT register.
//
//*****************************************************************************
#define I2S_TXLIMIT_LIMIT_M     0x0000001F  // FIFO Limit
#define I2S_TXLIMIT_LIMIT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXISM register.
//
//*****************************************************************************
#define I2S_TXISM_FFI           0x00010000  // Transmit FIFO Service Request
                                            // Interrupt
#define I2S_TXISM_FFM           0x00000001  // FIFO Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXLEV register.
//
//*****************************************************************************
#define I2S_TXLEV_LEVEL_M       0x0000001F  // Number of Audio Samples
#define I2S_TXLEV_LEVEL_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXFIFO register.
//
//*****************************************************************************
#define I2S_RXFIFO_M            0xFFFFFFFF  // RX Data
#define I2S_RXFIFO_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXFIFOCFG
// register.
//
//*****************************************************************************
#define I2S_RXFIFOCFG_FMM       0x00000004  // FIFO Mono Mode
#define I2S_RXFIFOCFG_CSS       0x00000002  // Compact Stereo Sample Size
#define I2S_RXFIFOCFG_LRS       0x00000001  // Left-Right Sample Indicator

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXCFG register.
//
//*****************************************************************************
#define I2S_RXCFG_JST           0x20000000  // Justification of Input Data
#define I2S_RXCFG_DLY           0x10000000  // Data Delay
#define I2S_RXCFG_SCP           0x08000000  // SCLK Polarity
#define I2S_RXCFG_LRP           0x04000000  // Left/Right Clock Polarity
#define I2S_RXCFG_RM            0x01000000  // Read Mode
#define I2S_RXCFG_MSL           0x00400000  // SCLK Master/Slave
#define I2S_RXCFG_SSZ_M         0x0000FC00  // Sample Size
#define I2S_RXCFG_SDSZ_M        0x000003F0  // System Data Size
#define I2S_RXCFG_SSZ_S         10
#define I2S_RXCFG_SDSZ_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXLIMIT register.
//
//*****************************************************************************
#define I2S_RXLIMIT_LIMIT_M     0x0000001F  // FIFO Limit
#define I2S_RXLIMIT_LIMIT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXISM register.
//
//*****************************************************************************
#define I2S_RXISM_FFI           0x00010000  // Receive FIFO Service Request
                                            // Interrupt
#define I2S_RXISM_FFM           0x00000001  // FIFO Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXLEV register.
//
//*****************************************************************************
#define I2S_RXLEV_LEVEL_M       0x0000001F  // Number of Audio Samples
#define I2S_RXLEV_LEVEL_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_CFG register.
//
//*****************************************************************************
#define I2S_CFG_RXSLV           0x00000020  // Use External I2S0RXMCLK
#define I2S_CFG_TXSLV           0x00000010  // Use External I2S0TXMCLK
#define I2S_CFG_RXEN            0x00000002  // Serial Receive Engine Enable
#define I2S_CFG_TXEN            0x00000001  // Serial Transmit Engine Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_IM register.
//
//*****************************************************************************
#define I2S_IM_RXRE             0x00000020  // Receive FIFO Read Error
#define I2S_IM_RXFSR            0x00000010  // Receive FIFO Service Request
#define I2S_IM_TXWE             0x00000002  // Transmit FIFO Write Error
#define I2S_IM_TXFSR            0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RIS register.
//
//*****************************************************************************
#define I2S_RIS_RXRE            0x00000020  // Receive FIFO Read Error
#define I2S_RIS_RXFSR           0x00000010  // Receive FIFO Service Request
#define I2S_RIS_TXWE            0x00000002  // Transmit FIFO Write Error
#define I2S_RIS_TXFSR           0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_MIS register.
//
//*****************************************************************************
#define I2S_MIS_RXRE            0x00000020  // Receive FIFO Read Error
#define I2S_MIS_RXFSR           0x00000010  // Receive FIFO Service Request
#define I2S_MIS_TXWE            0x00000002  // Transmit FIFO Write Error
#define I2S_MIS_TXFSR           0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_IC register.
//
//*****************************************************************************
#define I2S_IC_RXRE             0x00000020  // Receive FIFO Read Error
#define I2S_IC_TXWE             0x00000002  // Transmit FIFO Write Error

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_CFG register.
//
//*****************************************************************************
#define EPI_CFG_BLKEN           0x00000010  // Block Enable
#define EPI_CFG_MODE_M          0x0000000F  // Mode Select
#define EPI_CFG_MODE_NONE       0x00000000  // General Purpose
#define EPI_CFG_MODE_SDRAM      0x00000001  // SDRAM
#define EPI_CFG_MODE_HB8        0x00000002  // 8-Bit Host-Bus (HB8)
#define EPI_CFG_MODE_HB16       0x00000003  // 16-Bit Host-Bus (HB16)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD register.
//
//*****************************************************************************
#define EPI_BAUD_COUNT1_M       0xFFFF0000  // Baud Rate Counter 1
#define EPI_BAUD_COUNT0_M       0x0000FFFF  // Baud Rate Counter 0
#define EPI_BAUD_COUNT1_S       16
#define EPI_BAUD_COUNT0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG register.
//
//*****************************************************************************
#define EPI_HB16CFG_XFFEN       0x00800000  // External FIFO FULL Enable
#define EPI_HB16CFG_XFEEN       0x00400000  // External FIFO EMPTY Enable
#define EPI_HB16CFG_WRHIGH      0x00200000  // WRITE Strobe Polarity
#define EPI_HB16CFG_RDHIGH      0x00100000  // READ Strobe Polarity
#define EPI_HB16CFG_MAXWAIT_M   0x0000FF00  // Maximum Wait
#define EPI_HB16CFG_WRWS_M      0x000000C0  // CS0n Write Wait States
#define EPI_HB16CFG_WRWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_WRWS_1      0x00000040  // 1 wait state
#define EPI_HB16CFG_WRWS_2      0x00000080  // 2 wait states
#define EPI_HB16CFG_WRWS_3      0x000000C0  // 3 wait states
#define EPI_HB16CFG_RDWS_M      0x00000030  // CS0n Read Wait States
#define EPI_HB16CFG_RDWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_RDWS_1      0x00000010  // 1 wait state
#define EPI_HB16CFG_RDWS_2      0x00000020  // 2 wait states
#define EPI_HB16CFG_RDWS_3      0x00000030  // 3 wait states
#define EPI_HB16CFG_BSEL        0x00000004  // Byte Select Configuration
#define EPI_HB16CFG_MODE_M      0x00000003  // Host Bus Sub-Mode
#define EPI_HB16CFG_MODE_ADMUX  0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG_MODE_ADNMUX 0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG_MODE_SRAM   0x00000002  // Continuous Read - D[15:0]
#define EPI_HB16CFG_MODE_XFIFO  0x00000003  // XFIFO - D[15:0]
#define EPI_HB16CFG_MAXWAIT_S   8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG register.
//
//*****************************************************************************
#define EPI_GPCFG_CLKPIN        0x80000000  // Clock Pin
#define EPI_GPCFG_CLKGATE       0x40000000  // Clock Gated
#define EPI_GPCFG_RDYEN         0x10000000  // Ready Enable
#define EPI_GPCFG_FRMPIN        0x08000000  // Framing Pin
#define EPI_GPCFG_FRM50         0x04000000  // 50/50 Frame
#define EPI_GPCFG_FRMCNT_M      0x03C00000  // Frame Count
#define EPI_GPCFG_RW            0x00200000  // Read and Write
#define EPI_GPCFG_WR2CYC        0x00080000  // 2-Cycle Writes
#define EPI_GPCFG_RD2CYC        0x00040000  // 2-Cycle Reads
#define EPI_GPCFG_MAXWAIT_M     0x0000FF00  // Maximum Wait
#define EPI_GPCFG_ASIZE_M       0x00000030  // Address Bus Size
#define EPI_GPCFG_ASIZE_NONE    0x00000000  // No address
#define EPI_GPCFG_ASIZE_4BIT    0x00000010  // Up to 4 bits wide
#define EPI_GPCFG_ASIZE_12BIT   0x00000020  // Up to 12 bits wide. This size
                                            // cannot be used with 24-bit data
#define EPI_GPCFG_ASIZE_20BIT   0x00000030  // Up to 20 bits wide. This size
                                            // cannot be used with data sizes
                                            // other than 8
#define EPI_GPCFG_DSIZE_M       0x00000003  // Size of Data Bus
#define EPI_GPCFG_DSIZE_4BIT    0x00000000  // 8 Bits Wide (EPI0S0 to EPI0S7)
#define EPI_GPCFG_DSIZE_16BIT   0x00000001  // 16 Bits Wide (EPI0S0 to EPI0S15)
#define EPI_GPCFG_DSIZE_24BIT   0x00000002  // 24 Bits Wide (EPI0S0 to EPI0S23)
#define EPI_GPCFG_DSIZE_32BIT   0x00000003  // 32 Bits Wide (EPI0S0 to EPI0S31)
#define EPI_GPCFG_FRMCNT_S      22
#define EPI_GPCFG_MAXWAIT_S     8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_SDRAMCFG register.
//
//*****************************************************************************
#define EPI_SDRAMCFG_FREQ_M     0xC0000000  // Frequency Range
#define EPI_SDRAMCFG_FREQ_NONE  0x00000000  // 0 - 15 MHz
#define EPI_SDRAMCFG_FREQ_15MHZ 0x40000000  // 15 - 30 MHz
#define EPI_SDRAMCFG_FREQ_30MHZ 0x80000000  // 30 - 50 MHz
#define EPI_SDRAMCFG_FREQ_50MHZ 0xC0000000  // 50 - 100 MHz
#define EPI_SDRAMCFG_RFSH_M     0x07FF0000  // Refresh Counter
#define EPI_SDRAMCFG_SLEEP      0x00000200  // Sleep Mode
#define EPI_SDRAMCFG_SIZE_M     0x00000003  // Size of SDRAM
#define EPI_SDRAMCFG_SIZE_8MB   0x00000000  // 64 megabits (8MB)
#define EPI_SDRAMCFG_SIZE_16MB  0x00000001  // 128 megabits (16MB)
#define EPI_SDRAMCFG_SIZE_32MB  0x00000002  // 256 megabits (32MB)
#define EPI_SDRAMCFG_SIZE_64MB  0x00000003  // 512 megabits (64MB)
#define EPI_SDRAMCFG_RFSH_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG register.
//
//*****************************************************************************
#define EPI_HB8CFG_XFFEN        0x00800000  // External FIFO FULL Enable
#define EPI_HB8CFG_XFEEN        0x00400000  // External FIFO EMPTY Enable
#define EPI_HB8CFG_WRHIGH       0x00200000  // CS0n WRITE Strobe Polarity
#define EPI_HB8CFG_RDHIGH       0x00100000  // CS0n READ Strobe Polarity
#define EPI_HB8CFG_MAXWAIT_M    0x0000FF00  // Maximum Wait
#define EPI_HB8CFG_WRWS_M       0x000000C0  // Write Wait States
#define EPI_HB8CFG_WRWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_WRWS_1       0x00000040  // 1 wait state
#define EPI_HB8CFG_WRWS_2       0x00000080  // 2 wait states
#define EPI_HB8CFG_WRWS_3       0x000000C0  // 3 wait states
#define EPI_HB8CFG_RDWS_M       0x00000030  // Read Wait States
#define EPI_HB8CFG_RDWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_RDWS_1       0x00000010  // 1 wait state
#define EPI_HB8CFG_RDWS_2       0x00000020  // 2 wait states
#define EPI_HB8CFG_RDWS_3       0x00000030  // 3 wait states
#define EPI_HB8CFG_MODE_M       0x00000003  // Host Bus Sub-Mode
#define EPI_HB8CFG_MODE_MUX     0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG_MODE_NMUX    0x00000001  // ADNONMUX - D[7:0]
#define EPI_HB8CFG_MODE_SRAM    0x00000002  // Continuous Read - D[7:0]
#define EPI_HB8CFG_MODE_FIFO    0x00000003  // XFIFO - D[7:0]
#define EPI_HB8CFG_MAXWAIT_S    8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG2 register.
//
//*****************************************************************************
#define EPI_HB8CFG2_WORD        0x80000000  // Word Access Mode
#define EPI_HB8CFG2_CSBAUD      0x04000000  // Chip Select Baud Rate
#define EPI_HB8CFG2_CSCFG_M     0x03000000  // Chip Select Configuration
#define EPI_HB8CFG2_CSCFG_ALE   0x00000000  // ALE Configuration
#define EPI_HB8CFG2_CSCFG_CS    0x01000000  // CSn Configuration
#define EPI_HB8CFG2_CSCFG_DCS   0x02000000  // Dual CSn Configuration
#define EPI_HB8CFG2_CSCFG_ADCS  0x03000000  // ALE with Dual CSn Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG2 register.
//
//*****************************************************************************
#define EPI_HB16CFG2_WORD       0x80000000  // Word Access Mode
#define EPI_HB16CFG2_CSBAUD     0x04000000  // Chip Select Baud Rate
#define EPI_HB16CFG2_CSCFG_M    0x03000000  // Chip Select Configuration
#define EPI_HB16CFG2_CSCFG_ALE  0x00000000  // ALE Configuration
#define EPI_HB16CFG2_CSCFG_CS   0x01000000  // CSn Configuration
#define EPI_HB16CFG2_CSCFG_DCS  0x02000000  // Dual CSn Configuration
#define EPI_HB16CFG2_CSCFG_ADCS 0x03000000  // ALE with Dual CSn Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG2 register.
//
//*****************************************************************************
#define EPI_GPCFG2_WORD         0x80000000  // Word Access Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_ADDRMAP register.
//
//*****************************************************************************
#define EPI_ADDRMAP_EPSZ_M      0x000000C0  // External Peripheral Size
#define EPI_ADDRMAP_EPSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_EPSZ_64KB   0x00000040  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_EPSZ_16MB   0x00000080  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_EPSZ_256MB  0x000000C0  // 256 MB; lower address range:
                                            // 0x000.0000 to 0xFFF.FFFF
#define EPI_ADDRMAP_EPADR_M     0x00000030  // External Peripheral Address
#define EPI_ADDRMAP_EPADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_EPADR_A000  0x00000010  // At 0xA000.0000
#define EPI_ADDRMAP_EPADR_C000  0x00000020  // At 0xC000.0000
#define EPI_ADDRMAP_ERSZ_M      0x0000000C  // External RAM Size
#define EPI_ADDRMAP_ERSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_ERSZ_64KB   0x00000004  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_ERSZ_16MB   0x00000008  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_ERSZ_256MB  0x0000000C  // 256 MB; lower address range:
                                            // 0x000.0000 to 0xFFF.FFFF
#define EPI_ADDRMAP_ERADR_M     0x00000003  // External RAM Address
#define EPI_ADDRMAP_ERADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_ERADR_6000  0x00000001  // At 0x6000.0000
#define EPI_ADDRMAP_ERADR_8000  0x00000002  // At 0x8000.0000

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE0 register.
//
//*****************************************************************************
#define EPI_RSIZE0_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE0_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE0_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE0_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR0 register.
//
//*****************************************************************************
#define EPI_RADDR0_ADDR_M       0x1FFFFFFF  // Current Address
#define EPI_RADDR0_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD0 register.
//
//*****************************************************************************
#define EPI_RPSTD0_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD0_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE1 register.
//
//*****************************************************************************
#define EPI_RSIZE1_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE1_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE1_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE1_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR1 register.
//
//*****************************************************************************
#define EPI_RADDR1_ADDR_M       0x1FFFFFFF  // Current Address
#define EPI_RADDR1_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD1 register.
//
//*****************************************************************************
#define EPI_RPSTD1_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD1_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_STAT register.
//
//*****************************************************************************
#define EPI_STAT_CELOW          0x00000200  // Clock Enable Low
#define EPI_STAT_XFFULL         0x00000100  // External FIFO Full
#define EPI_STAT_XFEMPTY        0x00000080  // External FIFO Empty
#define EPI_STAT_INITSEQ        0x00000040  // Initialization Sequence
#define EPI_STAT_WBUSY          0x00000020  // Write Busy
#define EPI_STAT_NBRBUSY        0x00000010  // Non-Blocking Read Busy
#define EPI_STAT_ACTIVE         0x00000001  // Register Active

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RFIFOCNT register.
//
//*****************************************************************************
#define EPI_RFIFOCNT_COUNT_M    0x00000007  // FIFO Count
#define EPI_RFIFOCNT_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO register.
//
//*****************************************************************************
#define EPI_READFIFO_DATA_M     0xFFFFFFFF  // Reads Data
#define EPI_READFIFO_DATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO1
// register.
//
//*****************************************************************************
#define EPI_READFIFO1_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO1_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO2
// register.
//
//*****************************************************************************
#define EPI_READFIFO2_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO2_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO3
// register.
//
//*****************************************************************************
#define EPI_READFIFO3_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO3_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO4
// register.
//
//*****************************************************************************
#define EPI_READFIFO4_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO4_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO5
// register.
//
//*****************************************************************************
#define EPI_READFIFO5_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO5_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO6
// register.
//
//*****************************************************************************
#define EPI_READFIFO6_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO6_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO7
// register.
//
//*****************************************************************************
#define EPI_READFIFO7_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO7_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_FIFOLVL register.
//
//*****************************************************************************
#define EPI_FIFOLVL_WFERR       0x00020000  // Write Full Error
#define EPI_FIFOLVL_RSERR       0x00010000  // Read Stall Error
#define EPI_FIFOLVL_WRFIFO_M    0x00000070  // Write FIFO
#define EPI_FIFOLVL_WRFIFO_EMPT 0x00000000  // Trigger when there are 1 to 4
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_4  0x00000020  // Trigger when there are 1 to 3
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_2  0x00000030  // Trigger when there are 1 to 2
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_3_4  0x00000040  // Trigger when there is 1 space
                                            // available in the WFIFO
#define EPI_FIFOLVL_RDFIFO_M    0x00000007  // Read FIFO
#define EPI_FIFOLVL_RDFIFO_EMPT 0x00000000  // Empty
#define EPI_FIFOLVL_RDFIFO_1_8  0x00000001  // Trigger when there are 1 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_4  0x00000002  // Trigger when there are 2 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_2  0x00000003  // Trigger when there are 4 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_3_4  0x00000004  // Trigger when there are 6 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_7_8  0x00000005  // Trigger when there are 7 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_FULL 0x00000006  // Trigger when there are 8 entries
                                            // in the NBRFIFO

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_WFIFOCNT register.
//
//*****************************************************************************
#define EPI_WFIFOCNT_WTAV_M     0x00000007  // Available Write Transactions
#define EPI_WFIFOCNT_WTAV_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_IM register.
//
//*****************************************************************************
#define EPI_IM_WRIM             0x00000004  // Write Interrupt Mask
#define EPI_IM_RDIM             0x00000002  // Read Interrupt Mask
#define EPI_IM_ERRIM            0x00000001  // Error Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RIS register.
//
//*****************************************************************************
#define EPI_RIS_WRRIS           0x00000004  // Write Raw Interrupt Status
#define EPI_RIS_RDRIS           0x00000002  // Read Raw Interrupt Status
#define EPI_RIS_ERRRIS          0x00000001  // Error Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_MIS register.
//
//*****************************************************************************
#define EPI_MIS_WRMIS           0x00000004  // Write Masked Interrupt Status
#define EPI_MIS_RDMIS           0x00000002  // Read Masked Interrupt Status
#define EPI_MIS_ERRMIS          0x00000001  // Error Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_EISC register.
//
//*****************************************************************************
#define EPI_EISC_WTFULL         0x00000004  // Write FIFO Full Error
#define EPI_EISC_RSTALL         0x00000002  // Read Stalled Error
#define EPI_EISC_TOUT           0x00000001  // Timeout Error

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCC register.
//
//*****************************************************************************
#define HIB_RTCC_M              0xFFFFFFFF  // RTC Counter
#define HIB_RTCC_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCM0 register.
//
//*****************************************************************************
#define HIB_RTCM0_M             0xFFFFFFFF  // RTC Match 0
#define HIB_RTCM0_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCM1 register.
//
//*****************************************************************************
#define HIB_RTCM1_M             0xFFFFFFFF  // RTC Match 1
#define HIB_RTCM1_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCLD register.
//
//*****************************************************************************
#define HIB_RTCLD_M             0xFFFFFFFF  // RTC Load
#define HIB_RTCLD_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CTL register.
//
//*****************************************************************************
#define HIB_CTL_WRC             0x80000000  // Write Complete/Capable
#define HIB_CTL_VDD3ON          0x00000100  // VDD Powered
#define HIB_CTL_VABORT          0x00000080  // Power Cut Abort Enable
#define HIB_CTL_CLK32EN         0x00000040  // Clocking Enable
#define HIB_CTL_LOWBATEN        0x00000020  // Low Battery Monitoring Enable
#define HIB_CTL_PINWEN          0x00000010  // External WAKE Pin Enable
#define HIB_CTL_RTCWEN          0x00000008  // RTC Wake-up Enable
#define HIB_CTL_CLKSEL          0x00000004  // Hibernation Module Clock Select
#define HIB_CTL_HIBREQ          0x00000002  // Hibernation Request
#define HIB_CTL_RTCEN           0x00000001  // RTC Timer Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IM register.
//
//*****************************************************************************
#define HIB_IM_EXTW             0x00000008  // External Wake-Up Interrupt Mask
#define HIB_IM_LOWBAT           0x00000004  // Low Battery Voltage Interrupt
                                            // Mask
#define HIB_IM_RTCALT1          0x00000002  // RTC Alert 1 Interrupt Mask
#define HIB_IM_RTCALT0          0x00000001  // RTC Alert 0 Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RIS register.
//
//*****************************************************************************
#define HIB_RIS_EXTW            0x00000008  // External Wake-Up Raw Interrupt
                                            // Status
#define HIB_RIS_LOWBAT          0x00000004  // Low Battery Voltage Raw
                                            // Interrupt Status
#define HIB_RIS_RTCALT1         0x00000002  // RTC Alert 1 Raw Interrupt Status
#define HIB_RIS_RTCALT0         0x00000001  // RTC Alert 0 Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_MIS register.
//
//*****************************************************************************
#define HIB_MIS_EXTW            0x00000008  // External Wake-Up Masked
                                            // Interrupt Status
#define HIB_MIS_LOWBAT          0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Status
#define HIB_MIS_RTCALT1         0x00000002  // RTC Alert 1 Masked Interrupt
                                            // Status
#define HIB_MIS_RTCALT0         0x00000001  // RTC Alert 0 Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IC register.
//
//*****************************************************************************
#define HIB_IC_EXTW             0x00000008  // External Wake-Up Masked
                                            // Interrupt Clear
#define HIB_IC_LOWBAT           0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Clear
#define HIB_IC_RTCALT1          0x00000002  // RTC Alert1 Masked Interrupt
                                            // Clear
#define HIB_IC_RTCALT0          0x00000001  // RTC Alert0 Masked Interrupt
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCT register.
//
//*****************************************************************************
#define HIB_RTCT_TRIM_M         0x0000FFFF  // RTC Trim Value
#define HIB_RTCT_TRIM_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_DATA register.
//
//*****************************************************************************
#define HIB_DATA_RTD_M          0xFFFFFFFF  // Hibernation Module NV Data
#define HIB_DATA_RTD_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMA register.
//
//*****************************************************************************
#define FLASH_FMA_OFFSET_M      0x0001FFFF  // Address Offset
#define FLASH_FMA_OFFSET_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMD register.
//
//*****************************************************************************
#define FLASH_FMD_DATA_M        0xFFFFFFFF  // Data Value
#define FLASH_FMD_DATA_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMC register.
//
//*****************************************************************************
#define FLASH_FMC_WRKEY         0xA4420000  // FLASH write key
#define FLASH_FMC_COMT          0x00000008  // Commit Register Value
#define FLASH_FMC_MERASE        0x00000004  // Mass Erase Flash Memory
#define FLASH_FMC_ERASE         0x00000002  // Erase a Page of Flash Memory
#define FLASH_FMC_WRITE         0x00000001  // Write a Word into Flash Memory

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCRIS register.
//
//*****************************************************************************
#define FLASH_FCRIS_PRIS        0x00000002  // Programming Raw Interrupt Status
#define FLASH_FCRIS_ARIS        0x00000001  // Access Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCIM register.
//
//*****************************************************************************
#define FLASH_FCIM_PMASK        0x00000002  // Programming Interrupt Mask
#define FLASH_FCIM_AMASK        0x00000001  // Access Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCMISC register.
//
//*****************************************************************************
#define FLASH_FCMISC_PMISC      0x00000002  // Programming Masked Interrupt
                                            // Status and Clear
#define FLASH_FCMISC_AMISC      0x00000001  // Access Masked Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMC2 register.
//
//*****************************************************************************
#define FLASH_FMC2_WRKEY        0xA4420000  // FLASH write key
#define FLASH_FMC2_WRBUF        0x00000001  // Buffered Flash Memory Write

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FWBVAL register.
//
//*****************************************************************************
#define FLASH_FWBVAL_FWB_M      0xFFFFFFFF  // Flash Memory Write Buffer

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCTL register.
//
//*****************************************************************************
#define FLASH_FCTL_USDACK       0x00000002  // User Shut Down Acknowledge
#define FLASH_FCTL_USDREQ       0x00000001  // User Shut Down Request

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FWBN register.
//
//*****************************************************************************
#define FLASH_FWBN_DATA_M       0xFFFFFFFF  // Data

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_BOOTCFG register.
//
//*****************************************************************************
#define FLASH_BOOTCFG_NW        0x80000000  // Not Written
#define FLASH_BOOTCFG_PORT_M    0x0000E000  // Boot GPIO Port
#define FLASH_BOOTCFG_PORT_A    0x00000000  // Port A
#define FLASH_BOOTCFG_PORT_B    0x00002000  // Port B
#define FLASH_BOOTCFG_PORT_C    0x00004000  // Port C
#define FLASH_BOOTCFG_PORT_D    0x00006000  // Port D
#define FLASH_BOOTCFG_PORT_E    0x00008000  // Port E
#define FLASH_BOOTCFG_PORT_F    0x0000A000  // Port F
#define FLASH_BOOTCFG_PORT_G    0x0000C000  // Port G
#define FLASH_BOOTCFG_PORT_H    0x0000E000  // Port H
#define FLASH_BOOTCFG_PIN_M     0x00001C00  // Boot GPIO Pin
#define FLASH_BOOTCFG_PIN_0     0x00000000  // Pin 0
#define FLASH_BOOTCFG_PIN_1     0x00000400  // Pin 1
#define FLASH_BOOTCFG_PIN_2     0x00000800  // Pin 2
#define FLASH_BOOTCFG_PIN_3     0x00000C00  // Pin 3
#define FLASH_BOOTCFG_PIN_4     0x00001000  // Pin 4
#define FLASH_BOOTCFG_PIN_5     0x00001400  // Pin 5
#define FLASH_BOOTCFG_PIN_6     0x00001800  // Pin 6
#define FLASH_BOOTCFG_PIN_7     0x00001C00  // Pin 7
#define FLASH_BOOTCFG_POL       0x00000200  // Boot GPIO Polarity
#define FLASH_BOOTCFG_EN        0x00000100  // Boot GPIO Enable
#define FLASH_BOOTCFG_DBG1      0x00000002  // Debug Control 1
#define FLASH_BOOTCFG_DBG0      0x00000001  // Debug Control 0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_RMCTL register.
//
//*****************************************************************************
#define FLASH_RMCTL_BA          0x00000001  // Boot Alias

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_RMVER register.
//
//*****************************************************************************
#define FLASH_RMVER_CONT_M      0xFF000000  // ROM Contents
#define FLASH_RMVER_CONT_LM_AES 0x02000000  // Stellaris Boot Loader &
                                            // DriverLib with AES
#define FLASH_RMVER_VER_M       0x0000FF00  // ROM Version
#define FLASH_RMVER_REV_M       0x000000FF  // ROM Revision
#define FLASH_RMVER_VER_S       8
#define FLASH_RMVER_REV_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERDBG register.
//
//*****************************************************************************
#define FLASH_USERDBG_NW        0x80000000  // User Debug Not Written
#define FLASH_USERDBG_DATA_M    0x7FFFFFFC  // User Data
#define FLASH_USERDBG_DBG1      0x00000002  // Debug Control 1
#define FLASH_USERDBG_DBG0      0x00000001  // Debug Control 0
#define FLASH_USERDBG_DATA_S    2

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG0 register.
//
//*****************************************************************************
#define FLASH_USERREG0_NW       0x80000000  // Not Written
#define FLASH_USERREG0_DATA_M   0x7FFFFFFF  // User Data
#define FLASH_USERREG0_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG1 register.
//
//*****************************************************************************
#define FLASH_USERREG1_NW       0x80000000  // Not Written
#define FLASH_USERREG1_DATA_M   0x7FFFFFFF  // User Data
#define FLASH_USERREG1_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG2 register.
//
//*****************************************************************************
#define FLASH_USERREG2_NW       0x80000000  // Not Written
#define FLASH_USERREG2_DATA_M   0x7FFFFFFF  // User Data
#define FLASH_USERREG2_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG3 register.
//
//*****************************************************************************
#define FLASH_USERREG3_NW       0x80000000  // Not Written
#define FLASH_USERREG3_DATA_M   0x7FFFFFFF  // User Data
#define FLASH_USERREG3_DATA_S   0

//*****************************************************************************
//
// The following are defines for the erase size of the FLASH block that is
// erased by an erase operation, and the protect size is the size of the FLASH
// block that is protected by each protection register.
//
//*****************************************************************************
#define FLASH_PROTECT_SIZE      0x00000800
#define FLASH_ERASE_SIZE        0x00000400

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID0 register.
//
//*****************************************************************************
#define SYSCTL_DID0_VER_M       0x70000000  // DID0 Version
#define SYSCTL_DID0_VER_1       0x10000000  // Second version of the DID0
                                            // register format
#define SYSCTL_DID0_CLASS_M     0x00FF0000  // Device Class
#define SYSCTL_DID0_CLASS_TEMPEST \
                                0x00040000  // Stellaris(R) Tempest-class
                                            // microcontrollers
#define SYSCTL_DID0_MAJ_M       0x0000FF00  // Major Revision
#define SYSCTL_DID0_MAJ_REVA    0x00000000  // Revision A (initial device)
#define SYSCTL_DID0_MAJ_REVB    0x00000100  // Revision B (first base layer
                                            // revision)
#define SYSCTL_DID0_MAJ_REVC    0x00000200  // Revision C (second base layer
                                            // revision)
#define SYSCTL_DID0_MIN_M       0x000000FF  // Minor Revision
#define SYSCTL_DID0_MIN_0       0x00000000  // Initial device, or a major
                                            // revision update
#define SYSCTL_DID0_MIN_1       0x00000001  // First metal layer change
#define SYSCTL_DID0_MIN_2       0x00000002  // Second metal layer change

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID1 register.
//
//*****************************************************************************
#define SYSCTL_DID1_VER_M       0xF0000000  // DID1 Version
#define SYSCTL_DID1_VER_1       0x10000000  // Second version of the DID1
                                            // register format
#define SYSCTL_DID1_FAM_M       0x0F000000  // Family
#define SYSCTL_DID1_FAM_STELLARIS \
                                0x00000000  // Stellaris family of
                                            // microcontollers, that is, all
                                            // devices with external part
                                            // numbers starting with LM3S
#define SYSCTL_DID1_PRTNO_M     0x00FF0000  // Part Number
#define SYSCTL_DID1_PRTNO_9790  0x00670000  // LM3S9790
#define SYSCTL_DID1_PINCNT_M    0x0000E000  // Package Pin Count
#define SYSCTL_DID1_PINCNT_100  0x00004000  // 100-pin package
#define SYSCTL_DID1_TEMP_M      0x000000E0  // Temperature Range
#define SYSCTL_DID1_TEMP_C      0x00000000  // Commercial temperature range (0C
                                            // to 70C)
#define SYSCTL_DID1_TEMP_I      0x00000020  // Industrial temperature range
                                            // (-40C to 85C)
#define SYSCTL_DID1_TEMP_E      0x00000040  // Extended temperature range (-40C
                                            // to 105C)
#define SYSCTL_DID1_PKG_M       0x00000018  // Package Type
#define SYSCTL_DID1_PKG_SOIC    0x00000000  // SOIC package
#define SYSCTL_DID1_PKG_QFP     0x00000008  // LQFP package
#define SYSCTL_DID1_PKG_BGA     0x00000010  // BGA package
#define SYSCTL_DID1_ROHS        0x00000004  // RoHS-Compliance
#define SYSCTL_DID1_QUAL_M      0x00000003  // Qualification Status
#define SYSCTL_DID1_QUAL_ES     0x00000000  // Engineering Sample (unqualified)
#define SYSCTL_DID1_QUAL_PP     0x00000001  // Pilot Production (unqualified)
#define SYSCTL_DID1_QUAL_FQ     0x00000002  // Fully Qualified

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC0 register.
//
//*****************************************************************************
#define SYSCTL_DC0_SRAMSZ_M     0xFFFF0000  // SRAM Size
#define SYSCTL_DC0_SRAMSZ_64KB  0x00FF0000  // 64 KB of SRAM
#define SYSCTL_DC0_FLASHSZ_M    0x0000FFFF  // Flash Size
#define SYSCTL_DC0_FLASHSZ_128K 0x0000003F  // 128 KB of Flash
#define SYSCTL_DC0_SRAMSZ_S     16          // SRAM size shift
#define SYSCTL_DC0_FLASHSZ_S    0           // Flash size shift

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC1 register.
//
//*****************************************************************************
#define SYSCTL_DC1_WDT1         0x10000000  // Watchdog Timer1 Present
#define SYSCTL_DC1_CAN1         0x02000000  // CAN Module 1 Present
#define SYSCTL_DC1_CAN0         0x01000000  // CAN Module 0 Present
#define SYSCTL_DC1_ADC1         0x00020000  // ADC Module 1 Present
#define SYSCTL_DC1_ADC0         0x00010000  // ADC Module 0 Present
#define SYSCTL_DC1_MINSYSDIV_M  0x0000F000  // System Clock Divider
#define SYSCTL_DC1_MINSYSDIV_100 \
                                0x00001000  // Divide VCO (400MHZ) by 5 minimum
#define SYSCTL_DC1_MINSYSDIV_66 0x00002000  // Divide VCO (400MHZ) by 2*2 + 2 =
                                            // 6 minimum
#define SYSCTL_DC1_MINSYSDIV_50 0x00003000  // Specifies a 50-MHz CPU clock
                                            // with a PLL divider of 4
#define SYSCTL_DC1_MINSYSDIV_25 0x00007000  // Specifies a 25-MHz clock with a
                                            // PLL divider of 8
#define SYSCTL_DC1_MINSYSDIV_20 0x00009000  // Specifies a 20-MHz clock with a
                                            // PLL divider of 10
#define SYSCTL_DC1_ADC1SPD_M    0x00000C00  // Max ADC1 Speed
#define SYSCTL_DC1_ADC1SPD_1M   0x00000C00  // 1M samples/second
#define SYSCTL_DC1_ADC0SPD_M    0x00000300  // Max ADC0 Speed
#define SYSCTL_DC1_ADC0SPD_1M   0x00000300  // 1M samples/second
#define SYSCTL_DC1_MPU          0x00000080  // MPU Present
#define SYSCTL_DC1_HIB          0x00000040  // Hibernation Module Present
#define SYSCTL_DC1_TEMP         0x00000020  // Temp Sensor Present
#define SYSCTL_DC1_PLL          0x00000010  // PLL Present
#define SYSCTL_DC1_WDT0         0x00000008  // Watchdog Timer 0 Present
#define SYSCTL_DC1_SWO          0x00000004  // SWO Trace Port Present
#define SYSCTL_DC1_SWD          0x00000002  // SWD Present
#define SYSCTL_DC1_JTAG         0x00000001  // JTAG Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC2 register.
//
//*****************************************************************************
#define SYSCTL_DC2_EPI0         0x40000000  // EPI Module 0 Present
#define SYSCTL_DC2_I2S0         0x10000000  // I2S Module 0 Present
#define SYSCTL_DC2_COMP2        0x04000000  // Analog Comparator 2 Present
#define SYSCTL_DC2_COMP1        0x02000000  // Analog Comparator 1 Present
#define SYSCTL_DC2_COMP0        0x01000000  // Analog Comparator 0 Present
#define SYSCTL_DC2_TIMER3       0x00080000  // Timer Module 3 Present
#define SYSCTL_DC2_TIMER2       0x00040000  // Timer Module 2 Present
#define SYSCTL_DC2_TIMER1       0x00020000  // Timer Module 1 Present
#define SYSCTL_DC2_TIMER0       0x00010000  // Timer Module 0 Present
#define SYSCTL_DC2_I2C1         0x00004000  // I2C Module 1 Present
#define SYSCTL_DC2_I2C0         0x00001000  // I2C Module 0 Present
#define SYSCTL_DC2_SSI1         0x00000020  // SSI Module 1 Present
#define SYSCTL_DC2_SSI0         0x00000010  // SSI Module 0 Present
#define SYSCTL_DC2_UART2        0x00000004  // UART Module 2 Present
#define SYSCTL_DC2_UART1        0x00000002  // UART Module 1 Present
#define SYSCTL_DC2_UART0        0x00000001  // UART Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC3 register.
//
//*****************************************************************************
#define SYSCTL_DC3_32KHZ        0x80000000  // 32KHz Input Clock Available
#define SYSCTL_DC3_CCP5         0x20000000  // CCP5 Pin Present
#define SYSCTL_DC3_CCP4         0x10000000  // CCP4 Pin Present
#define SYSCTL_DC3_CCP3         0x08000000  // CCP3 Pin Present
#define SYSCTL_DC3_CCP2         0x04000000  // CCP2 Pin Present
#define SYSCTL_DC3_CCP1         0x02000000  // CCP1 Pin Present
#define SYSCTL_DC3_CCP0         0x01000000  // CCP0 Pin Present
#define SYSCTL_DC3_ADC0AIN7     0x00800000  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC3_ADC0AIN6     0x00400000  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC3_ADC0AIN5     0x00200000  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC3_ADC0AIN4     0x00100000  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC3_ADC0AIN3     0x00080000  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC3_ADC0AIN2     0x00040000  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC3_ADC0AIN1     0x00020000  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC3_ADC0AIN0     0x00010000  // ADC Module 0 AIN0 Pin Present
#define SYSCTL_DC3_C2O          0x00004000  // C2o Pin Present
#define SYSCTL_DC3_C2PLUS       0x00002000  // C2+ Pin Present
#define SYSCTL_DC3_C2MINUS      0x00001000  // C2- Pin Present
#define SYSCTL_DC3_C1O          0x00000800  // C1o Pin Present
#define SYSCTL_DC3_C1PLUS       0x00000400  // C1+ Pin Present
#define SYSCTL_DC3_C1MINUS      0x00000200  // C1- Pin Present
#define SYSCTL_DC3_C0O          0x00000100  // C0o Pin Present
#define SYSCTL_DC3_C0PLUS       0x00000080  // C0+ Pin Present
#define SYSCTL_DC3_C0MINUS      0x00000040  // C0- Pin Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC4 register.
//
//*****************************************************************************
#define SYSCTL_DC4_EPHY0        0x40000000  // Ethernet PHY Layer 0 Present
#define SYSCTL_DC4_EMAC0        0x10000000  // Ethernet MAC Layer 0 Present
#define SYSCTL_DC4_PICAL        0x00040000  // PIOSC Calibrate
#define SYSCTL_DC4_CCP7         0x00008000  // CCP7 Pin Present
#define SYSCTL_DC4_CCP6         0x00004000  // CCP6 Pin Present
#define SYSCTL_DC4_UDMA         0x00002000  // Micro-DMA Module Present
#define SYSCTL_DC4_ROM          0x00001000  // Internal Code ROM Present
#define SYSCTL_DC4_GPIOJ        0x00000100  // GPIO Port J Present
#define SYSCTL_DC4_GPIOH        0x00000080  // GPIO Port H Present
#define SYSCTL_DC4_GPIOG        0x00000040  // GPIO Port G Present
#define SYSCTL_DC4_GPIOF        0x00000020  // GPIO Port F Present
#define SYSCTL_DC4_GPIOE        0x00000010  // GPIO Port E Present
#define SYSCTL_DC4_GPIOD        0x00000008  // GPIO Port D Present
#define SYSCTL_DC4_GPIOC        0x00000004  // GPIO Port C Present
#define SYSCTL_DC4_GPIOB        0x00000002  // GPIO Port B Present
#define SYSCTL_DC4_GPIOA        0x00000001  // GPIO Port A Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC6 register.
//
//*****************************************************************************
#define SYSCTL_DC6_USB0PHY      0x00000010  // USB Module 0 PHY Present
#define SYSCTL_DC6_USB0_M       0x00000003  // USB Module 0 Present
#define SYSCTL_DC6_USB0_OTG     0x00000003  // USB0 is OTG

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC7 register.
//
//*****************************************************************************
#define SYSCTL_DC7_DMACH30      0x40000000  // SW
#define SYSCTL_DC7_DMACH29      0x20000000  // I2S0_TX / CAN1_TX
#define SYSCTL_DC7_DMACH28      0x10000000  // I2S0_RX / CAN1_RX
#define SYSCTL_DC7_DMACH27      0x08000000  // CAN1_TX / ADC1_SS3
#define SYSCTL_DC7_DMACH26      0x04000000  // CAN1_RX / ADC1_SS2
#define SYSCTL_DC7_DMACH25      0x02000000  // SSI1_TX / ADC1_SS1
#define SYSCTL_DC7_DMACH24      0x01000000  // SSI1_RX / ADC1_SS0
#define SYSCTL_DC7_DMACH23      0x00800000  // UART1_TX / CAN2_TX
#define SYSCTL_DC7_DMACH22      0x00400000  // UART1_RX / CAN2_RX
#define SYSCTL_DC7_DMACH21      0x00200000  // Timer1B / EPI0_WFIFO
#define SYSCTL_DC7_DMACH20      0x00100000  // Timer1A / EPI0_NBRFIFO
#define SYSCTL_DC7_DMACH19      0x00080000  // Timer0B / Timer1B
#define SYSCTL_DC7_DMACH18      0x00040000  // Timer0A / Timer1A
#define SYSCTL_DC7_DMACH17      0x00020000  // ADC0_SS3
#define SYSCTL_DC7_DMACH16      0x00010000  // ADC0_SS2
#define SYSCTL_DC7_DMACH15      0x00008000  // ADC0_SS1 / Timer2B
#define SYSCTL_DC7_DMACH14      0x00004000  // ADC0_SS0 / Timer2A
#define SYSCTL_DC7_DMACH13      0x00002000  // CAN0_TX / UART2_TX
#define SYSCTL_DC7_DMACH12      0x00001000  // CAN0_RX / UART2_RX
#define SYSCTL_DC7_DMACH11      0x00000800  // SSI0_TX / SSI1_TX
#define SYSCTL_DC7_DMACH10      0x00000400  // SSI0_RX / SSI1_RX
#define SYSCTL_DC7_DMACH9       0x00000200  // UART0_TX / UART1_TX
#define SYSCTL_DC7_DMACH8       0x00000100  // UART0_RX / UART1_RX
#define SYSCTL_DC7_DMACH7       0x00000080  // ETH_TX / Timer2B
#define SYSCTL_DC7_DMACH6       0x00000040  // ETH_RX / Timer2A
#define SYSCTL_DC7_DMACH5       0x00000020  // USB_EP3_TX / Timer2B
#define SYSCTL_DC7_DMACH4       0x00000010  // USB_EP3_RX / Timer2A
#define SYSCTL_DC7_DMACH3       0x00000008  // USB_EP2_TX / Timer3B
#define SYSCTL_DC7_DMACH2       0x00000004  // USB_EP2_RX / Timer3A
#define SYSCTL_DC7_DMACH1       0x00000002  // USB_EP1_TX / UART2_TX
#define SYSCTL_DC7_DMACH0       0x00000001  // USB_EP1_RX / UART2_RX

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC8 register.
//
//*****************************************************************************
#define SYSCTL_DC8_ADC1AIN15    0x80000000  // ADC Module 1 AIN15 Pin Present
#define SYSCTL_DC8_ADC1AIN14    0x40000000  // ADC Module 1 AIN14 Pin Present
#define SYSCTL_DC8_ADC1AIN13    0x20000000  // ADC Module 1 AIN13 Pin Present
#define SYSCTL_DC8_ADC1AIN12    0x10000000  // ADC Module 1 AIN12 Pin Present
#define SYSCTL_DC8_ADC1AIN11    0x08000000  // ADC Module 1 AIN11 Pin Present
#define SYSCTL_DC8_ADC1AIN10    0x04000000  // ADC Module 1 AIN10 Pin Present
#define SYSCTL_DC8_ADC1AIN9     0x02000000  // ADC Module 1 AIN9 Pin Present
#define SYSCTL_DC8_ADC1AIN8     0x01000000  // ADC Module 1 AIN8 Pin Present
#define SYSCTL_DC8_ADC1AIN7     0x00800000  // ADC Module 1 AIN7 Pin Present
#define SYSCTL_DC8_ADC1AIN6     0x00400000  // ADC Module 1 AIN6 Pin Present
#define SYSCTL_DC8_ADC1AIN5     0x00200000  // ADC Module 1 AIN5 Pin Present
#define SYSCTL_DC8_ADC1AIN4     0x00100000  // ADC Module 1 AIN4 Pin Present
#define SYSCTL_DC8_ADC1AIN3     0x00080000  // ADC Module 1 AIN3 Pin Present
#define SYSCTL_DC8_ADC1AIN2     0x00040000  // ADC Module 1 AIN2 Pin Present
#define SYSCTL_DC8_ADC1AIN1     0x00020000  // ADC Module 1 AIN1 Pin Present
#define SYSCTL_DC8_ADC1AIN0     0x00010000  // ADC Module 1 AIN0 Pin Present
#define SYSCTL_DC8_ADC0AIN15    0x00008000  // ADC Module 0 AIN15 Pin Present
#define SYSCTL_DC8_ADC0AIN14    0x00004000  // ADC Module 0 AIN14 Pin Present
#define SYSCTL_DC8_ADC0AIN13    0x00002000  // ADC Module 0 AIN13 Pin Present
#define SYSCTL_DC8_ADC0AIN12    0x00001000  // ADC Module 0 AIN12 Pin Present
#define SYSCTL_DC8_ADC0AIN11    0x00000800  // ADC Module 0 AIN11 Pin Present
#define SYSCTL_DC8_ADC0AIN10    0x00000400  // ADC Module 0 AIN10 Pin Present
#define SYSCTL_DC8_ADC0AIN9     0x00000200  // ADC Module 0 AIN9 Pin Present
#define SYSCTL_DC8_ADC0AIN8     0x00000100  // ADC Module 0 AIN8 Pin Present
#define SYSCTL_DC8_ADC0AIN7     0x00000080  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC8_ADC0AIN6     0x00000040  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC8_ADC0AIN5     0x00000020  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC8_ADC0AIN4     0x00000010  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC8_ADC0AIN3     0x00000008  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC8_ADC0AIN2     0x00000004  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC8_ADC0AIN1     0x00000002  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC8_ADC0AIN0     0x00000001  // ADC Module 0 AIN0 Pin Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PBORCTL register.
//
//*****************************************************************************
#define SYSCTL_PBORCTL_BORIOR   0x00000002  // BOR Interrupt or Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR0 register.
//
//*****************************************************************************
#define SYSCTL_SRCR0_WDT1       0x10000000  // WDT1 Reset Control
#define SYSCTL_SRCR0_CAN1       0x02000000  // CAN1 Reset Control
#define SYSCTL_SRCR0_CAN0       0x01000000  // CAN0 Reset Control
#define SYSCTL_SRCR0_ADC1       0x00020000  // ADC1 Reset Control
#define SYSCTL_SRCR0_ADC0       0x00010000  // ADC0 Reset Control
#define SYSCTL_SRCR0_HIB        0x00000040  // HIB Reset Control
#define SYSCTL_SRCR0_WDT0       0x00000008  // WDT0 Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR1 register.
//
//*****************************************************************************
#define SYSCTL_SRCR1_EPI0       0x40000000  // EPI0 Reset Control
#define SYSCTL_SRCR1_I2S0       0x10000000  // I2S0 Reset Control
#define SYSCTL_SRCR1_COMP2      0x04000000  // Analog Comp 2 Reset Control
#define SYSCTL_SRCR1_COMP1      0x02000000  // Analog Comp 1 Reset Control
#define SYSCTL_SRCR1_COMP0      0x01000000  // Analog Comp 0 Reset Control
#define SYSCTL_SRCR1_TIMER3     0x00080000  // Timer 3 Reset Control
#define SYSCTL_SRCR1_TIMER2     0x00040000  // Timer 2 Reset Control
#define SYSCTL_SRCR1_TIMER1     0x00020000  // Timer 1 Reset Control
#define SYSCTL_SRCR1_TIMER0     0x00010000  // Timer 0 Reset Control
#define SYSCTL_SRCR1_I2C1       0x00004000  // I2C1 Reset Control
#define SYSCTL_SRCR1_I2C0       0x00001000  // I2C0 Reset Control
#define SYSCTL_SRCR1_SSI1       0x00000020  // SSI1 Reset Control
#define SYSCTL_SRCR1_SSI0       0x00000010  // SSI0 Reset Control
#define SYSCTL_SRCR1_UART2      0x00000004  // UART2 Reset Control
#define SYSCTL_SRCR1_UART1      0x00000002  // UART1 Reset Control
#define SYSCTL_SRCR1_UART0      0x00000001  // UART0 Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR2 register.
//
//*****************************************************************************
#define SYSCTL_SRCR2_EPHY0      0x40000000  // PHY0 Reset Control
#define SYSCTL_SRCR2_EMAC0      0x10000000  // MAC0 Reset Control
#define SYSCTL_SRCR2_USB0       0x00010000  // USB0 Reset Control
#define SYSCTL_SRCR2_UDMA       0x00002000  // Micro-DMA Reset Control
#define SYSCTL_SRCR2_GPIOJ      0x00000100  // Port J Reset Control
#define SYSCTL_SRCR2_GPIOH      0x00000080  // Port H Reset Control
#define SYSCTL_SRCR2_GPIOG      0x00000040  // Port G Reset Control
#define SYSCTL_SRCR2_GPIOF      0x00000020  // Port F Reset Control
#define SYSCTL_SRCR2_GPIOE      0x00000010  // Port E Reset Control
#define SYSCTL_SRCR2_GPIOD      0x00000008  // Port D Reset Control
#define SYSCTL_SRCR2_GPIOC      0x00000004  // Port C Reset Control
#define SYSCTL_SRCR2_GPIOB      0x00000002  // Port B Reset Control
#define SYSCTL_SRCR2_GPIOA      0x00000001  // Port A Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RIS register.
//
//*****************************************************************************
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  // MOSC Power Up Raw Interrupt
                                            // Status
#define SYSCTL_RIS_USBPLLLRIS   0x00000080  // USB PLL Lock Raw Interrupt
                                            // Status
#define SYSCTL_RIS_PLLLRIS      0x00000040  // PLL Lock Raw Interrupt Status
#define SYSCTL_RIS_BORRIS       0x00000002  // Brown-Out Reset Raw Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_IMC register.
//
//*****************************************************************************
#define SYSCTL_IMC_MOSCPUPIM    0x00000100  // MOSC Power Up Interrupt Mask
#define SYSCTL_IMC_USBPLLLIM    0x00000080  // USB PLL Lock Interrupt Mask
#define SYSCTL_IMC_PLLLIM       0x00000040  // PLL Lock Interrupt Mask
#define SYSCTL_IMC_BORIM        0x00000002  // Brown-Out Reset Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MISC register.
//
//*****************************************************************************
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  // MOSC Power Up Masked Interrupt
                                            // Status
#define SYSCTL_MISC_USBPLLLMIS  0x00000080  // USB PLL Lock Masked Interrupt
                                            // Status
#define SYSCTL_MISC_PLLLMIS     0x00000040  // PLL Lock Masked Interrupt Status
#define SYSCTL_MISC_BORMIS      0x00000002  // BOR Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RESC register.
//
//*****************************************************************************
#define SYSCTL_RESC_MOSCFAIL    0x00010000  // MOSC Failure Reset
#define SYSCTL_RESC_WDT1        0x00000020  // Watchdog Timer 1 Reset
#define SYSCTL_RESC_SW          0x00000010  // Software Reset
#define SYSCTL_RESC_WDT0        0x00000008  // Watchdog Timer 0 Reset
#define SYSCTL_RESC_BOR         0x00000004  // Brown-Out Reset
#define SYSCTL_RESC_POR         0x00000002  // Power-On Reset
#define SYSCTL_RESC_EXT         0x00000001  // External Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCC register.
//
//*****************************************************************************
#define SYSCTL_RCC_ACG          0x08000000  // Auto Clock Gating
#define SYSCTL_RCC_SYSDIV_M     0x07800000  // System Clock Divisor
#define SYSCTL_RCC_SYSDIV_2     0x00800000  // System clock /2
#define SYSCTL_RCC_SYSDIV_3     0x01000000  // System clock /3
#define SYSCTL_RCC_SYSDIV_4     0x01800000  // System clock /4
#define SYSCTL_RCC_SYSDIV_5     0x02000000  // System clock /5
#define SYSCTL_RCC_SYSDIV_6     0x02800000  // System clock /6
#define SYSCTL_RCC_SYSDIV_7     0x03000000  // System clock /7
#define SYSCTL_RCC_SYSDIV_8     0x03800000  // System clock /8
#define SYSCTL_RCC_SYSDIV_9     0x04000000  // System clock /9
#define SYSCTL_RCC_SYSDIV_10    0x04800000  // System clock /10
#define SYSCTL_RCC_SYSDIV_11    0x05000000  // System clock /11
#define SYSCTL_RCC_SYSDIV_12    0x05800000  // System clock /12
#define SYSCTL_RCC_SYSDIV_13    0x06000000  // System clock /13
#define SYSCTL_RCC_SYSDIV_14    0x06800000  // System clock /14
#define SYSCTL_RCC_SYSDIV_15    0x07000000  // System clock /15
#define SYSCTL_RCC_SYSDIV_16    0x07800000  // System clock /16
#define SYSCTL_RCC_USESYSDIV    0x00400000  // Enable System Clock Divider
#define SYSCTL_RCC_PWRDN        0x00002000  // PLL Power Down
#define SYSCTL_RCC_BYPASS       0x00000800  // PLL Bypass
#define SYSCTL_RCC_XTAL_M       0x000007C0  // Crystal Value
#define SYSCTL_RCC_XTAL_1MHZ    0x00000000  // 1 MHz
#define SYSCTL_RCC_XTAL_1_84MHZ 0x00000040  // 1.8432 MHz
#define SYSCTL_RCC_XTAL_2MHZ    0x00000080  // 2 MHz
#define SYSCTL_RCC_XTAL_2_45MHZ 0x000000C0  // 2.4576 MHz
#define SYSCTL_RCC_XTAL_3_57MHZ 0x00000100  // 3.579545 MHz
#define SYSCTL_RCC_XTAL_3_68MHZ 0x00000140  // 3.6864 MHz
#define SYSCTL_RCC_XTAL_4MHZ    0x00000180  // 4 MHz
#define SYSCTL_RCC_XTAL_4_09MHZ 0x000001C0  // 4.096 MHz
#define SYSCTL_RCC_XTAL_4_91MHZ 0x00000200  // 4.9152 MHz
#define SYSCTL_RCC_XTAL_5MHZ    0x00000240  // 5 MHz
#define SYSCTL_RCC_XTAL_5_12MHZ 0x00000280  // 5.12 MHz
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  // 6 MHz
#define SYSCTL_RCC_XTAL_6_14MHZ 0x00000300  // 6.144 MHz
#define SYSCTL_RCC_XTAL_7_37MHZ 0x00000340  // 7.3728 MHz
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  // 8 MHz
#define SYSCTL_RCC_XTAL_8_19MHZ 0x000003C0  // 8.192 MHz
#define SYSCTL_RCC_XTAL_10MHZ   0x00000400  // 10 MHz
#define SYSCTL_RCC_XTAL_12MHZ   0x00000440  // 12 MHz
#define SYSCTL_RCC_XTAL_12_2MHZ 0x00000480  // 12.288 MHz
#define SYSCTL_RCC_XTAL_13_5MHZ 0x000004C0  // 13.56 MHz
#define SYSCTL_RCC_XTAL_14_3MHZ 0x00000500  // 14.31818 MHz
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  // 16 MHz
#define SYSCTL_RCC_XTAL_16_3MHZ 0x00000580  // 16.384 MHz
#define SYSCTL_RCC_OSCSRC_M     0x00000030  // Oscillator Source
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  // MOSC
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  // IOSC
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  // IOSC/4
#define SYSCTL_RCC_OSCSRC_30    0x00000030  // 30 kHz
#define SYSCTL_RCC_IOSCDIS      0x00000002  // Internal Oscillator Disable
#define SYSCTL_RCC_MOSCDIS      0x00000001  // Main Oscillator Disable
#define SYSCTL_RCC_SYSDIV_S     23

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLCFG register.
//
//*****************************************************************************
#define SYSCTL_PLLCFG_F_M       0x00003FE0  // PLL F Value
#define SYSCTL_PLLCFG_R_M       0x0000001F  // PLL R Value
#define SYSCTL_PLLCFG_F_S       5
#define SYSCTL_PLLCFG_R_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_GPIOHBCTL
// register.
//
//*****************************************************************************
#define SYSCTL_GPIOHBCTL_PORTJ  0x00000100  // Port J Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTH  0x00000080  // Port H Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTG  0x00000040  // Port G Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTF  0x00000020  // Port F Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTE  0x00000010  // Port E Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTD  0x00000008  // Port D Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTC  0x00000004  // Port C Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTB  0x00000002  // Port B Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTA  0x00000001  // Port A Advanced High-Performance
                                            // Bus

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCC2 register.
//
//*****************************************************************************
#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
                                            // MHz
#define SYSCTL_RCC2_SYSDIV2_M   0x1F800000  // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2_2   0x00800000  // System clock /2
#define SYSCTL_RCC2_SYSDIV2_3   0x01000000  // System clock /3
#define SYSCTL_RCC2_SYSDIV2_4   0x01800000  // System clock /4
#define SYSCTL_RCC2_SYSDIV2_5   0x02000000  // System clock /5
#define SYSCTL_RCC2_SYSDIV2_6   0x02800000  // System clock /6
#define SYSCTL_RCC2_SYSDIV2_7   0x03000000  // System clock /7
#define SYSCTL_RCC2_SYSDIV2_8   0x03800000  // System clock /8
#define SYSCTL_RCC2_SYSDIV2_9   0x04000000  // System clock /9
#define SYSCTL_RCC2_SYSDIV2_10  0x04800000  // System clock /10
#define SYSCTL_RCC2_SYSDIV2_11  0x05000000  // System clock /11
#define SYSCTL_RCC2_SYSDIV2_12  0x05800000  // System clock /12
#define SYSCTL_RCC2_SYSDIV2_13  0x06000000  // System clock /13
#define SYSCTL_RCC2_SYSDIV2_14  0x06800000  // System clock /14
#define SYSCTL_RCC2_SYSDIV2_15  0x07000000  // System clock /15
#define SYSCTL_RCC2_SYSDIV2_16  0x07800000  // System clock /16
#define SYSCTL_RCC2_SYSDIV2_17  0x08000000  // System clock /17
#define SYSCTL_RCC2_SYSDIV2_18  0x08800000  // System clock /18
#define SYSCTL_RCC2_SYSDIV2_19  0x09000000  // System clock /19
#define SYSCTL_RCC2_SYSDIV2_20  0x09800000  // System clock /20
#define SYSCTL_RCC2_SYSDIV2_21  0x0A000000  // System clock /21
#define SYSCTL_RCC2_SYSDIV2_22  0x0A800000  // System clock /22
#define SYSCTL_RCC2_SYSDIV2_23  0x0B000000  // System clock /23
#define SYSCTL_RCC2_SYSDIV2_24  0x0B800000  // System clock /24
#define SYSCTL_RCC2_SYSDIV2_25  0x0C000000  // System clock /25
#define SYSCTL_RCC2_SYSDIV2_26  0x0C800000  // System clock /26
#define SYSCTL_RCC2_SYSDIV2_27  0x0D000000  // System clock /27
#define SYSCTL_RCC2_SYSDIV2_28  0x0D800000  // System clock /28
#define SYSCTL_RCC2_SYSDIV2_29  0x0E000000  // System clock /29
#define SYSCTL_RCC2_SYSDIV2_30  0x0E800000  // System clock /30
#define SYSCTL_RCC2_SYSDIV2_31  0x0F000000  // System clock /31
#define SYSCTL_RCC2_SYSDIV2_32  0x0F800000  // System clock /32
#define SYSCTL_RCC2_SYSDIV2_33  0x10000000  // System clock /33
#define SYSCTL_RCC2_SYSDIV2_34  0x10800000  // System clock /34
#define SYSCTL_RCC2_SYSDIV2_35  0x11000000  // System clock /35
#define SYSCTL_RCC2_SYSDIV2_36  0x11800000  // System clock /36
#define SYSCTL_RCC2_SYSDIV2_37  0x12000000  // System clock /37
#define SYSCTL_RCC2_SYSDIV2_38  0x12800000  // System clock /38
#define SYSCTL_RCC2_SYSDIV2_39  0x13000000  // System clock /39
#define SYSCTL_RCC2_SYSDIV2_40  0x13800000  // System clock /40
#define SYSCTL_RCC2_SYSDIV2_41  0x14000000  // System clock /41
#define SYSCTL_RCC2_SYSDIV2_42  0x14800000  // System clock /42
#define SYSCTL_RCC2_SYSDIV2_43  0x15000000  // System clock /43
#define SYSCTL_RCC2_SYSDIV2_44  0x15800000  // System clock /44
#define SYSCTL_RCC2_SYSDIV2_45  0x16000000  // System clock /45
#define SYSCTL_RCC2_SYSDIV2_46  0x16800000  // System clock /46
#define SYSCTL_RCC2_SYSDIV2_47  0x17000000  // System clock /47
#define SYSCTL_RCC2_SYSDIV2_48  0x17800000  // System clock /48
#define SYSCTL_RCC2_SYSDIV2_49  0x18000000  // System clock /49
#define SYSCTL_RCC2_SYSDIV2_50  0x18800000  // System clock /50
#define SYSCTL_RCC2_SYSDIV2_51  0x19000000  // System clock /51
#define SYSCTL_RCC2_SYSDIV2_52  0x19800000  // System clock /52
#define SYSCTL_RCC2_SYSDIV2_53  0x1A000000  // System clock /53
#define SYSCTL_RCC2_SYSDIV2_54  0x1A800000  // System clock /54
#define SYSCTL_RCC2_SYSDIV2_55  0x1B000000  // System clock /55
#define SYSCTL_RCC2_SYSDIV2_56  0x1B800000  // System clock /56
#define SYSCTL_RCC2_SYSDIV2_57  0x1C000000  // System clock /57
#define SYSCTL_RCC2_SYSDIV2_58  0x1C800000  // System clock /58
#define SYSCTL_RCC2_SYSDIV2_59  0x1D000000  // System clock /59
#define SYSCTL_RCC2_SYSDIV2_60  0x1D800000  // System clock /60
#define SYSCTL_RCC2_SYSDIV2_61  0x1E000000  // System clock /61
#define SYSCTL_RCC2_SYSDIV2_62  0x1E800000  // System clock /62
#define SYSCTL_RCC2_SYSDIV2_63  0x1F000000  // System clock /63
#define SYSCTL_RCC2_SYSDIV2_64  0x1F800000  // System clock /64
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_USBPWRDN    0x00004000  // Power-Down USB PLL
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC
#define SYSCTL_RCC2_OSCSRC2_IO  0x00000010  // PIOSC
#define SYSCTL_RCC2_OSCSRC2_IO4 0x00000020  // PIOSC/4
#define SYSCTL_RCC2_OSCSRC2_30  0x00000030  // 30 kHz
#define SYSCTL_RCC2_OSCSRC2_419 0x00000060  // 4.194304 MHz
#define SYSCTL_RCC2_OSCSRC2_32  0x00000070  // 32.768 kHz
#define SYSCTL_RCC2_SYSDIV2_S   23

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MOSCCTL register.
//
//*****************************************************************************
#define SYSCTL_MOSCCTL_CVAL     0x00000001  // Clock Validation for MOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC0 register.
//
//*****************************************************************************
#define SYSCTL_RCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_RCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_RCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_RCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_RCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_RCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_RCGC0_ADC1SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC1SPD_250K \
                                0x00000400  // 250K samples/second
#define SYSCTL_RCGC0_ADC1SPD_500K \
                                0x00000800  // 500K samples/second
#define SYSCTL_RCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_RCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_RCGC0_ADC0SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC0SPD_250K \
                                0x00000100  // 250K samples/second
#define SYSCTL_RCGC0_ADC0SPD_500K \
                                0x00000200  // 500K samples/second
#define SYSCTL_RCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_RCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_RCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC1 register.
//
//*****************************************************************************
#define SYSCTL_RCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_RCGC1_I2S0       0x10000000  // I2S0 Clock Gating
#define SYSCTL_RCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_RCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_RCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_RCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_RCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_RCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_RCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_RCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_RCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_RCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_RCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_RCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_RCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_RCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC2 register.
//
//*****************************************************************************
#define SYSCTL_RCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_RCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
#define SYSCTL_RCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_RCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_RCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_RCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_RCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_RCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC0 register.
//
//*****************************************************************************
#define SYSCTL_SCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_SCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_SCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_SCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_SCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_SCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_SCGC0_ADC1SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_SCGC0_ADC1SPD_250K \
                                0x00000400  // 250K samples/second
#define SYSCTL_SCGC0_ADC1SPD_500K \
                                0x00000800  // 500K samples/second
#define SYSCTL_SCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_SCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_SCGC0_ADC0SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_SCGC0_ADC0SPD_250K \
                                0x00000100  // 250K samples/second
#define SYSCTL_SCGC0_ADC0SPD_500K \
                                0x00000200  // 500K samples/second
#define SYSCTL_SCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_SCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_SCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC1 register.
//
//*****************************************************************************
#define SYSCTL_SCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_SCGC1_I2S0       0x10000000  // I2S0 Clock Gating
#define SYSCTL_SCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_SCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_SCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_SCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_SCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_SCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_SCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_SCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_SCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_SCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_SCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_SCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_SCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_SCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC2 register.
//
//*****************************************************************************
#define SYSCTL_SCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_SCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
#define SYSCTL_SCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_SCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_SCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_SCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_SCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_SCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_SCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_SCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_SCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_SCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_SCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC0 register.
//
//*****************************************************************************
#define SYSCTL_DCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_DCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_DCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_DCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_DCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_DCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_DCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC1 register.
//
//*****************************************************************************
#define SYSCTL_DCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_DCGC1_I2S0       0x10000000  // I2S0 Clock Gating
#define SYSCTL_DCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_DCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_DCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_DCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_DCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_DCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_DCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_DCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_DCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_DCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_DCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_DCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_DCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_DCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC2 register.
//
//*****************************************************************************
#define SYSCTL_DCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_DCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
#define SYSCTL_DCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_DCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_DCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_DCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_DCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_DCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_DCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_DCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_DCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_DCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_DCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DSLPCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_DSLPCLKCFG_D_M   0x1F800000  // Divider Field Override
#define SYSCTL_DSLPCLKCFG_D_1   0x00000000  // System clock /1
#define SYSCTL_DSLPCLKCFG_D_2   0x00800000  // System clock /2
#define SYSCTL_DSLPCLKCFG_D_3   0x01000000  // System clock /3
#define SYSCTL_DSLPCLKCFG_D_4   0x01800000  // System clock /4
#define SYSCTL_DSLPCLKCFG_D_5   0x02000000  // System clock /5
#define SYSCTL_DSLPCLKCFG_D_6   0x02800000  // System clock /6
#define SYSCTL_DSLPCLKCFG_D_7   0x03000000  // System clock /7
#define SYSCTL_DSLPCLKCFG_D_8   0x03800000  // System clock /8
#define SYSCTL_DSLPCLKCFG_D_9   0x04000000  // System clock /9
#define SYSCTL_DSLPCLKCFG_D_10  0x04800000  // System clock /10
#define SYSCTL_DSLPCLKCFG_D_11  0x05000000  // System clock /11
#define SYSCTL_DSLPCLKCFG_D_12  0x05800000  // System clock /12
#define SYSCTL_DSLPCLKCFG_D_13  0x06000000  // System clock /13
#define SYSCTL_DSLPCLKCFG_D_14  0x06800000  // System clock /14
#define SYSCTL_DSLPCLKCFG_D_15  0x07000000  // System clock /15
#define SYSCTL_DSLPCLKCFG_D_16  0x07800000  // System clock /16
#define SYSCTL_DSLPCLKCFG_D_17  0x08000000  // System clock /17
#define SYSCTL_DSLPCLKCFG_D_18  0x08800000  // System clock /18
#define SYSCTL_DSLPCLKCFG_D_19  0x09000000  // System clock /19
#define SYSCTL_DSLPCLKCFG_D_20  0x09800000  // System clock /20
#define SYSCTL_DSLPCLKCFG_D_21  0x0A000000  // System clock /21
#define SYSCTL_DSLPCLKCFG_D_22  0x0A800000  // System clock /22
#define SYSCTL_DSLPCLKCFG_D_23  0x0B000000  // System clock /23
#define SYSCTL_DSLPCLKCFG_D_24  0x0B800000  // System clock /24
#define SYSCTL_DSLPCLKCFG_D_25  0x0C000000  // System clock /25
#define SYSCTL_DSLPCLKCFG_D_26  0x0C800000  // System clock /26
#define SYSCTL_DSLPCLKCFG_D_27  0x0D000000  // System clock /27
#define SYSCTL_DSLPCLKCFG_D_28  0x0D800000  // System clock /28
#define SYSCTL_DSLPCLKCFG_D_29  0x0E000000  // System clock /29
#define SYSCTL_DSLPCLKCFG_D_30  0x0E800000  // System clock /30
#define SYSCTL_DSLPCLKCFG_D_31  0x0F000000  // System clock /31
#define SYSCTL_DSLPCLKCFG_D_32  0x0F800000  // System clock /32
#define SYSCTL_DSLPCLKCFG_D_33  0x10000000  // System clock /33
#define SYSCTL_DSLPCLKCFG_D_34  0x10800000  // System clock /34
#define SYSCTL_DSLPCLKCFG_D_35  0x11000000  // System clock /35
#define SYSCTL_DSLPCLKCFG_D_36  0x11800000  // System clock /36
#define SYSCTL_DSLPCLKCFG_D_37  0x12000000  // System clock /37
#define SYSCTL_DSLPCLKCFG_D_38  0x12800000  // System clock /38
#define SYSCTL_DSLPCLKCFG_D_39  0x13000000  // System clock /39
#define SYSCTL_DSLPCLKCFG_D_40  0x13800000  // System clock /40
#define SYSCTL_DSLPCLKCFG_D_41  0x14000000  // System clock /41
#define SYSCTL_DSLPCLKCFG_D_42  0x14800000  // System clock /42
#define SYSCTL_DSLPCLKCFG_D_43  0x15000000  // System clock /43
#define SYSCTL_DSLPCLKCFG_D_44  0x15800000  // System clock /44
#define SYSCTL_DSLPCLKCFG_D_45  0x16000000  // System clock /45
#define SYSCTL_DSLPCLKCFG_D_46  0x16800000  // System clock /46
#define SYSCTL_DSLPCLKCFG_D_47  0x17000000  // System clock /47
#define SYSCTL_DSLPCLKCFG_D_48  0x17800000  // System clock /48
#define SYSCTL_DSLPCLKCFG_D_49  0x18000000  // System clock /49
#define SYSCTL_DSLPCLKCFG_D_50  0x18800000  // System clock /50
#define SYSCTL_DSLPCLKCFG_D_51  0x19000000  // System clock /51
#define SYSCTL_DSLPCLKCFG_D_52  0x19800000  // System clock /52
#define SYSCTL_DSLPCLKCFG_D_53  0x1A000000  // System clock /53
#define SYSCTL_DSLPCLKCFG_D_54  0x1A800000  // System clock /54
#define SYSCTL_DSLPCLKCFG_D_55  0x1B000000  // System clock /55
#define SYSCTL_DSLPCLKCFG_D_56  0x1B800000  // System clock /56
#define SYSCTL_DSLPCLKCFG_D_57  0x1C000000  // System clock /57
#define SYSCTL_DSLPCLKCFG_D_58  0x1C800000  // System clock /58
#define SYSCTL_DSLPCLKCFG_D_59  0x1D000000  // System clock /59
#define SYSCTL_DSLPCLKCFG_D_60  0x1D800000  // System clock /60
#define SYSCTL_DSLPCLKCFG_D_61  0x1E000000  // System clock /61
#define SYSCTL_DSLPCLKCFG_D_62  0x1E800000  // System clock /62
#define SYSCTL_DSLPCLKCFG_D_63  0x1F000000  // System clock /63
#define SYSCTL_DSLPCLKCFG_D_64  0x1F800000  // System clock /64
#define SYSCTL_DSLPCLKCFG_O_M   0x00000070  // Clock Source
#define SYSCTL_DSLPCLKCFG_O_IGN 0x00000000  // MOSC
#define SYSCTL_DSLPCLKCFG_O_IO  0x00000010  // PIOSC
#define SYSCTL_DSLPCLKCFG_O_30  0x00000030  // 30 kHz
#define SYSCTL_DSLPCLKCFG_O_32  0x00000070  // 32.768 kHz

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PIOSCCAL
// register.
//
//*****************************************************************************
#define SYSCTL_PIOSCCAL_UTEN    0x80000000  // Use User Trim Value
#define SYSCTL_PIOSCCAL_CAL     0x00000200  // Start Calibration
#define SYSCTL_PIOSCCAL_UPDATE  0x00000100  // Update Trim
#define SYSCTL_PIOSCCAL_UT_M    0x0000007F  // User Trim Value
#define SYSCTL_PIOSCCAL_UT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PIOSCSTAT
// register.
//
//*****************************************************************************
#define SYSCTL_PIOSCSTAT_DT_M   0x007F0000  // Default Trim Value
#define SYSCTL_PIOSCSTAT_CR_M   0x00000300  // Calibration Result
#define SYSCTL_PIOSCSTAT_CRNONE 0x00000000  // Calibration has not been
                                            // attempted
#define SYSCTL_PIOSCSTAT_CRPASS 0x00000100  // The last calibration operation
                                            // completed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CRFAIL 0x00000200  // The last calibration operation
                                            // failed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CT_M   0x0000007F  // Calibration Trim Value
#define SYSCTL_PIOSCSTAT_DT_S   16
#define SYSCTL_PIOSCSTAT_CT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_I2SMCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_I2SMCLKCFG_RXEN  0x80000000  // RX Clock Enable
#define SYSCTL_I2SMCLKCFG_RXI_M 0x3FF00000  // RX Clock Integer Input
#define SYSCTL_I2SMCLKCFG_RXF_M 0x000F0000  // RX Clock Fractional Input
#define SYSCTL_I2SMCLKCFG_TXEN  0x00008000  // TX Clock Enable
#define SYSCTL_I2SMCLKCFG_TXI_M 0x00003FF0  // TX Clock Integer Input
#define SYSCTL_I2SMCLKCFG_TXF_M 0x0000000F  // TX Clock Fractional Input
#define SYSCTL_I2SMCLKCFG_RXI_S 20
#define SYSCTL_I2SMCLKCFG_RXF_S 16
#define SYSCTL_I2SMCLKCFG_TXI_S 4
#define SYSCTL_I2SMCLKCFG_TXF_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC9 register.
//
//*****************************************************************************
#define SYSCTL_DC9_ADC1DC7      0x00800000  // ADC1 DC7 Present
#define SYSCTL_DC9_ADC1DC6      0x00400000  // ADC1 DC6 Present
#define SYSCTL_DC9_ADC1DC5      0x00200000  // ADC1 DC5 Present
#define SYSCTL_DC9_ADC1DC4      0x00100000  // ADC1 DC4 Present
#define SYSCTL_DC9_ADC1DC3      0x00080000  // ADC1 DC3 Present
#define SYSCTL_DC9_ADC1DC2      0x00040000  // ADC1 DC2 Present
#define SYSCTL_DC9_ADC1DC1      0x00020000  // ADC1 DC1 Present
#define SYSCTL_DC9_ADC1DC0      0x00010000  // ADC1 DC0 Present
#define SYSCTL_DC9_ADC0DC7      0x00000080  // ADC0 DC7 Present
#define SYSCTL_DC9_ADC0DC6      0x00000040  // ADC0 DC6 Present
#define SYSCTL_DC9_ADC0DC5      0x00000020  // ADC0 DC5 Present
#define SYSCTL_DC9_ADC0DC4      0x00000010  // ADC0 DC4 Present
#define SYSCTL_DC9_ADC0DC3      0x00000008  // ADC0 DC3 Present
#define SYSCTL_DC9_ADC0DC2      0x00000004  // ADC0 DC2 Present
#define SYSCTL_DC9_ADC0DC1      0x00000002  // ADC0 DC1 Present
#define SYSCTL_DC9_ADC0DC0      0x00000001  // ADC0 DC0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_NVMSTAT register.
//
//*****************************************************************************
#define SYSCTL_NVMSTAT_FWB      0x00000001  // 32 Word Flash Write Buffer
                                            // Active

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_STAT register.
//
//*****************************************************************************
#define UDMA_STAT_DMACHANS_M    0x001F0000  // Available uDMA Channels Minus 1
#define UDMA_STAT_STATE_M       0x000000F0  // Control State Machine Status
#define UDMA_STAT_STATE_IDLE    0x00000000  // Idle
#define UDMA_STAT_STATE_RD_CTRL 0x00000010  // Reading channel controller data
#define UDMA_STAT_STATE_RD_SRCENDP \
                                0x00000020  // Reading source end pointer
#define UDMA_STAT_STATE_RD_DSTENDP \
                                0x00000030  // Reading destination end pointer
#define UDMA_STAT_STATE_RD_SRCDAT \
                                0x00000040  // Reading source data
#define UDMA_STAT_STATE_WR_DSTDAT \
                                0x00000050  // Writing destination data
#define UDMA_STAT_STATE_WAIT    0x00000060  // Waiting for uDMA request to
                                            // clear
#define UDMA_STAT_STATE_WR_CTRL 0x00000070  // Writing channel controller data
#define UDMA_STAT_STATE_STALL   0x00000080  // Stalled
#define UDMA_STAT_STATE_DONE    0x00000090  // Done
#define UDMA_STAT_STATE_UNDEF   0x000000A0  // Undefined
#define UDMA_STAT_MASTEN        0x00000001  // Master Enable Status
#define UDMA_STAT_DMACHANS_S    16

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CFG register.
//
//*****************************************************************************
#define UDMA_CFG_MASTEN         0x00000001  // Controller Master Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CTLBASE register.
//
//*****************************************************************************
#define UDMA_CTLBASE_ADDR_M     0xFFFFFC00  // Channel Control Base Address
#define UDMA_CTLBASE_ADDR_S     10

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTBASE register.
//
//*****************************************************************************
#define UDMA_ALTBASE_ADDR_M     0xFFFFFFFF  // Alternate Channel Address
                                            // Pointer
#define UDMA_ALTBASE_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_WAITSTAT register.
//
//*****************************************************************************
#define UDMA_WAITSTAT_WAITREQ_M 0xFFFFFFFF  // Channel [n] Wait Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_SWREQ register.
//
//*****************************************************************************
#define UDMA_SWREQ_M            0xFFFFFFFF  // Channel [n] Software Request

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTSET
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTSET_SET_M  0xFFFFFFFF  // Channel [n] Useburst Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTCLR
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTCLR_CLR_M  0xFFFFFFFF  // Channel [n] Useburst Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKSET
// register.
//
//*****************************************************************************
#define UDMA_REQMASKSET_SET_M   0xFFFFFFFF  // Channel [n] Request Mask Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKCLR
// register.
//
//*****************************************************************************
#define UDMA_REQMASKCLR_CLR_M   0xFFFFFFFF  // Channel [n] Request Mask Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENASET register.
//
//*****************************************************************************
#define UDMA_ENASET_SET_M       0xFFFFFFFF  // Channel [n] Enable Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENACLR register.
//
//*****************************************************************************
#define UDMA_ENACLR_CLR_M       0xFFFFFFFF  // Clear Channel [n] Enable Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTSET register.
//
//*****************************************************************************
#define UDMA_ALTSET_SET_M       0xFFFFFFFF  // Channel [n] Alternate Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTCLR register.
//
//*****************************************************************************
#define UDMA_ALTCLR_CLR_M       0xFFFFFFFF  // Channel [n] Alternate Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOSET register.
//
//*****************************************************************************
#define UDMA_PRIOSET_SET_M      0xFFFFFFFF  // Channel [n] Priority Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOCLR register.
//
//*****************************************************************************
#define UDMA_PRIOCLR_CLR_M      0xFFFFFFFF  // Channel [n] Priority Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ERRCLR register.
//
//*****************************************************************************
#define UDMA_ERRCLR_ERRCLR      0x00000001  // uDMA Bus Error Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHALT register.
//
//*****************************************************************************
#define UDMA_CHALT_M            0xFFFFFFFF  // Channel [n] Alternate Assignment
                                            // Select

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_SRCENDP register.
//
//*****************************************************************************
#define UDMA_SRCENDP_ADDR_M     0xFFFFFFFF  // Source Address End Pointer
#define UDMA_SRCENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_DSTENDP register.
//
//*****************************************************************************
#define UDMA_DSTENDP_ADDR_M     0xFFFFFFFF  // Destination Address End Pointer
#define UDMA_DSTENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_CHCTL register.
//
//*****************************************************************************
#define UDMA_CHCTL_DSTINC_M     0xC0000000  // Destination Address Increment
#define UDMA_CHCTL_DSTINC_8     0x00000000  // Byte
#define UDMA_CHCTL_DSTINC_16    0x40000000  // Half-word
#define UDMA_CHCTL_DSTINC_32    0x80000000  // Word
#define UDMA_CHCTL_DSTINC_NONE  0xC0000000  // No increment
#define UDMA_CHCTL_DSTSIZE_M    0x30000000  // Destination Data Size
#define UDMA_CHCTL_DSTSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_DSTSIZE_16   0x10000000  // Half-word
#define UDMA_CHCTL_DSTSIZE_32   0x20000000  // Word
#define UDMA_CHCTL_SRCINC_M     0x0C000000  // Source Address Increment
#define UDMA_CHCTL_SRCINC_8     0x00000000  // Byte
#define UDMA_CHCTL_SRCINC_16    0x04000000  // Half-word
#define UDMA_CHCTL_SRCINC_32    0x08000000  // Word
#define UDMA_CHCTL_SRCINC_NONE  0x0C000000  // No increment
#define UDMA_CHCTL_SRCSIZE_M    0x03000000  // Source Data Size
#define UDMA_CHCTL_SRCSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_SRCSIZE_16   0x01000000  // Half-word
#define UDMA_CHCTL_SRCSIZE_32   0x02000000  // Word
#define UDMA_CHCTL_ARBSIZE_M    0x0003C000  // Arbitration Size
#define UDMA_CHCTL_ARBSIZE_1    0x00000000  // 1 Transfer
#define UDMA_CHCTL_ARBSIZE_2    0x00004000  // 2 Transfers
#define UDMA_CHCTL_ARBSIZE_4    0x00008000  // 4 Transfers
#define UDMA_CHCTL_ARBSIZE_8    0x0000C000  // 8 Transfers
#define UDMA_CHCTL_ARBSIZE_16   0x00010000  // 16 Transfers
#define UDMA_CHCTL_ARBSIZE_32   0x00014000  // 32 Transfers
#define UDMA_CHCTL_ARBSIZE_64   0x00018000  // 64 Transfers
#define UDMA_CHCTL_ARBSIZE_128  0x0001C000  // 128 Transfers
#define UDMA_CHCTL_ARBSIZE_256  0x00020000  // 256 Transfers
#define UDMA_CHCTL_ARBSIZE_512  0x00024000  // 512 Transfers
#define UDMA_CHCTL_ARBSIZE_1024 0x00028000  // 1024 Transfers
#define UDMA_CHCTL_XFERSIZE_M   0x00003FF0  // Transfer Size (minus 1)
#define UDMA_CHCTL_NXTUSEBURST  0x00000008  // Next Useburst
#define UDMA_CHCTL_XFERMODE_M   0x00000007  // uDMA Transfer Mode
#define UDMA_CHCTL_XFERMODE_STOP \
                                0x00000000  // Stop
#define UDMA_CHCTL_XFERMODE_BASIC \
                                0x00000001  // Basic
#define UDMA_CHCTL_XFERMODE_AUTO \
                                0x00000002  // Auto-Request
#define UDMA_CHCTL_XFERMODE_PINGPONG \
                                0x00000003  // Ping-Pong
#define UDMA_CHCTL_XFERMODE_MEM_SG \
                                0x00000004  // Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_MEM_SGA \
                                0x00000005  // Alternate Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SG \
                                0x00000006  // Peripheral Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SGA \
                                0x00000007  // Alternate Peripheral
                                            // Scatter-Gather
#define UDMA_CHCTL_XFERSIZE_S   4

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_INT_TYPE register.
//
//*****************************************************************************
#define NVIC_INT_TYPE_LINES_M   0x0000001F  // Number of interrupt lines (x32)
#define NVIC_INT_TYPE_LINES_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CTRL register.
//
//*****************************************************************************
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_RELOAD register.
//
//*****************************************************************************
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value
#define NVIC_ST_RELOAD_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CURRENT
// register.
//
//*****************************************************************************
#define NVIC_ST_CURRENT_M       0x00FFFFFF  // Counter current value
#define NVIC_ST_CURRENT_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CAL register.
//
//*****************************************************************************
#define NVIC_ST_CAL_NOREF       0x80000000  // No reference clock
#define NVIC_ST_CAL_SKEW        0x40000000  // Clock skew
#define NVIC_ST_CAL_ONEMS_M     0x00FFFFFF  // 1ms reference value
#define NVIC_ST_CAL_ONEMS_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN0 register.
//
//*****************************************************************************
#define NVIC_EN0_INT31          0x80000000  // Interrupt 31 enable
#define NVIC_EN0_INT30          0x40000000  // Interrupt 30 enable
#define NVIC_EN0_INT29          0x20000000  // Interrupt 29 enable
#define NVIC_EN0_INT28          0x10000000  // Interrupt 28 enable
#define NVIC_EN0_INT27          0x08000000  // Interrupt 27 enable
#define NVIC_EN0_INT26          0x04000000  // Interrupt 26 enable
#define NVIC_EN0_INT25          0x02000000  // Interrupt 25 enable
#define NVIC_EN0_INT24          0x01000000  // Interrupt 24 enable
#define NVIC_EN0_INT23          0x00800000  // Interrupt 23 enable
#define NVIC_EN0_INT22          0x00400000  // Interrupt 22 enable
#define NVIC_EN0_INT21          0x00200000  // Interrupt 21 enable
#define NVIC_EN0_INT20          0x00100000  // Interrupt 20 enable
#define NVIC_EN0_INT19          0x00080000  // Interrupt 19 enable
#define NVIC_EN0_INT18          0x00040000  // Interrupt 18 enable
#define NVIC_EN0_INT17          0x00020000  // Interrupt 17 enable
#define NVIC_EN0_INT16          0x00010000  // Interrupt 16 enable
#define NVIC_EN0_INT15          0x00008000  // Interrupt 15 enable
#define NVIC_EN0_INT14          0x00004000  // Interrupt 14 enable
#define NVIC_EN0_INT13          0x00002000  // Interrupt 13 enable
#define NVIC_EN0_INT12          0x00001000  // Interrupt 12 enable
#define NVIC_EN0_INT11          0x00000800  // Interrupt 11 enable
#define NVIC_EN0_INT10          0x00000400  // Interrupt 10 enable
#define NVIC_EN0_INT9           0x00000200  // Interrupt 9 enable
#define NVIC_EN0_INT8           0x00000100  // Interrupt 8 enable
#define NVIC_EN0_INT7           0x00000080  // Interrupt 7 enable
#define NVIC_EN0_INT6           0x00000040  // Interrupt 6 enable
#define NVIC_EN0_INT5           0x00000020  // Interrupt 5 enable
#define NVIC_EN0_INT4           0x00000010  // Interrupt 4 enable
#define NVIC_EN0_INT3           0x00000008  // Interrupt 3 enable
#define NVIC_EN0_INT2           0x00000004  // Interrupt 2 enable
#define NVIC_EN0_INT1           0x00000002  // Interrupt 1 enable
#define NVIC_EN0_INT0           0x00000001  // Interrupt 0 enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN1 register.
//
//*****************************************************************************
#define NVIC_EN1_INT59          0x08000000  // Interrupt 59 enable
#define NVIC_EN1_INT58          0x04000000  // Interrupt 58 enable
#define NVIC_EN1_INT57          0x02000000  // Interrupt 57 enable
#define NVIC_EN1_INT56          0x01000000  // Interrupt 56 enable
#define NVIC_EN1_INT55          0x00800000  // Interrupt 55 enable
#define NVIC_EN1_INT54          0x00400000  // Interrupt 54 enable
#define NVIC_EN1_INT53          0x00200000  // Interrupt 53 enable
#define NVIC_EN1_INT52          0x00100000  // Interrupt 52 enable
#define NVIC_EN1_INT51          0x00080000  // Interrupt 51 enable
#define NVIC_EN1_INT50          0x00040000  // Interrupt 50 enable
#define NVIC_EN1_INT49          0x00020000  // Interrupt 49 enable
#define NVIC_EN1_INT48          0x00010000  // Interrupt 48 enable
#define NVIC_EN1_INT47          0x00008000  // Interrupt 47 enable
#define NVIC_EN1_INT46          0x00004000  // Interrupt 46 enable
#define NVIC_EN1_INT45          0x00002000  // Interrupt 45 enable
#define NVIC_EN1_INT44          0x00001000  // Interrupt 44 enable
#define NVIC_EN1_INT43          0x00000800  // Interrupt 43 enable
#define NVIC_EN1_INT42          0x00000400  // Interrupt 42 enable
#define NVIC_EN1_INT41          0x00000200  // Interrupt 41 enable
#define NVIC_EN1_INT40          0x00000100  // Interrupt 40 enable
#define NVIC_EN1_INT39          0x00000080  // Interrupt 39 enable
#define NVIC_EN1_INT38          0x00000040  // Interrupt 38 enable
#define NVIC_EN1_INT37          0x00000020  // Interrupt 37 enable
#define NVIC_EN1_INT36          0x00000010  // Interrupt 36 enable
#define NVIC_EN1_INT35          0x00000008  // Interrupt 35 enable
#define NVIC_EN1_INT34          0x00000004  // Interrupt 34 enable
#define NVIC_EN1_INT33          0x00000002  // Interrupt 33 enable
#define NVIC_EN1_INT32          0x00000001  // Interrupt 32 enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS0 register.
//
//*****************************************************************************
#define NVIC_DIS0_INT31         0x80000000  // Interrupt 31 disable
#define NVIC_DIS0_INT30         0x40000000  // Interrupt 30 disable
#define NVIC_DIS0_INT29         0x20000000  // Interrupt 29 disable
#define NVIC_DIS0_INT28         0x10000000  // Interrupt 28 disable
#define NVIC_DIS0_INT27         0x08000000  // Interrupt 27 disable
#define NVIC_DIS0_INT26         0x04000000  // Interrupt 26 disable
#define NVIC_DIS0_INT25         0x02000000  // Interrupt 25 disable
#define NVIC_DIS0_INT24         0x01000000  // Interrupt 24 disable
#define NVIC_DIS0_INT23         0x00800000  // Interrupt 23 disable
#define NVIC_DIS0_INT22         0x00400000  // Interrupt 22 disable
#define NVIC_DIS0_INT21         0x00200000  // Interrupt 21 disable
#define NVIC_DIS0_INT20         0x00100000  // Interrupt 20 disable
#define NVIC_DIS0_INT19         0x00080000  // Interrupt 19 disable
#define NVIC_DIS0_INT18         0x00040000  // Interrupt 18 disable
#define NVIC_DIS0_INT17         0x00020000  // Interrupt 17 disable
#define NVIC_DIS0_INT16         0x00010000  // Interrupt 16 disable
#define NVIC_DIS0_INT15         0x00008000  // Interrupt 15 disable
#define NVIC_DIS0_INT14         0x00004000  // Interrupt 14 disable
#define NVIC_DIS0_INT13         0x00002000  // Interrupt 13 disable
#define NVIC_DIS0_INT12         0x00001000  // Interrupt 12 disable
#define NVIC_DIS0_INT11         0x00000800  // Interrupt 11 disable
#define NVIC_DIS0_INT10         0x00000400  // Interrupt 10 disable
#define NVIC_DIS0_INT9          0x00000200  // Interrupt 9 disable
#define NVIC_DIS0_INT8          0x00000100  // Interrupt 8 disable
#define NVIC_DIS0_INT7          0x00000080  // Interrupt 7 disable
#define NVIC_DIS0_INT6          0x00000040  // Interrupt 6 disable
#define NVIC_DIS0_INT5          0x00000020  // Interrupt 5 disable
#define NVIC_DIS0_INT4          0x00000010  // Interrupt 4 disable
#define NVIC_DIS0_INT3          0x00000008  // Interrupt 3 disable
#define NVIC_DIS0_INT2          0x00000004  // Interrupt 2 disable
#define NVIC_DIS0_INT1          0x00000002  // Interrupt 1 disable
#define NVIC_DIS0_INT0          0x00000001  // Interrupt 0 disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS1 register.
//
//*****************************************************************************
#define NVIC_DIS1_INT59         0x08000000  // Interrupt 59 disable
#define NVIC_DIS1_INT58         0x04000000  // Interrupt 58 disable
#define NVIC_DIS1_INT57         0x02000000  // Interrupt 57 disable
#define NVIC_DIS1_INT56         0x01000000  // Interrupt 56 disable
#define NVIC_DIS1_INT55         0x00800000  // Interrupt 55 disable
#define NVIC_DIS1_INT54         0x00400000  // Interrupt 54 disable
#define NVIC_DIS1_INT53         0x00200000  // Interrupt 53 disable
#define NVIC_DIS1_INT52         0x00100000  // Interrupt 52 disable
#define NVIC_DIS1_INT51         0x00080000  // Interrupt 51 disable
#define NVIC_DIS1_INT50         0x00040000  // Interrupt 50 disable
#define NVIC_DIS1_INT49         0x00020000  // Interrupt 49 disable
#define NVIC_DIS1_INT48         0x00010000  // Interrupt 48 disable
#define NVIC_DIS1_INT47         0x00008000  // Interrupt 47 disable
#define NVIC_DIS1_INT46         0x00004000  // Interrupt 46 disable
#define NVIC_DIS1_INT45         0x00002000  // Interrupt 45 disable
#define NVIC_DIS1_INT44         0x00001000  // Interrupt 44 disable
#define NVIC_DIS1_INT43         0x00000800  // Interrupt 43 disable
#define NVIC_DIS1_INT42         0x00000400  // Interrupt 42 disable
#define NVIC_DIS1_INT41         0x00000200  // Interrupt 41 disable
#define NVIC_DIS1_INT40         0x00000100  // Interrupt 40 disable
#define NVIC_DIS1_INT39         0x00000080  // Interrupt 39 disable
#define NVIC_DIS1_INT38         0x00000040  // Interrupt 38 disable
#define NVIC_DIS1_INT37         0x00000020  // Interrupt 37 disable
#define NVIC_DIS1_INT36         0x00000010  // Interrupt 36 disable
#define NVIC_DIS1_INT35         0x00000008  // Interrupt 35 disable
#define NVIC_DIS1_INT34         0x00000004  // Interrupt 34 disable
#define NVIC_DIS1_INT33         0x00000002  // Interrupt 33 disable
#define NVIC_DIS1_INT32         0x00000001  // Interrupt 32 disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND0 register.
//
//*****************************************************************************
#define NVIC_PEND0_INT31        0x80000000  // Interrupt 31 pend
#define NVIC_PEND0_INT30        0x40000000  // Interrupt 30 pend
#define NVIC_PEND0_INT29        0x20000000  // Interrupt 29 pend
#define NVIC_PEND0_INT28        0x10000000  // Interrupt 28 pend
#define NVIC_PEND0_INT27        0x08000000  // Interrupt 27 pend
#define NVIC_PEND0_INT26        0x04000000  // Interrupt 26 pend
#define NVIC_PEND0_INT25        0x02000000  // Interrupt 25 pend
#define NVIC_PEND0_INT24        0x01000000  // Interrupt 24 pend
#define NVIC_PEND0_INT23        0x00800000  // Interrupt 23 pend
#define NVIC_PEND0_INT22        0x00400000  // Interrupt 22 pend
#define NVIC_PEND0_INT21        0x00200000  // Interrupt 21 pend
#define NVIC_PEND0_INT20        0x00100000  // Interrupt 20 pend
#define NVIC_PEND0_INT19        0x00080000  // Interrupt 19 pend
#define NVIC_PEND0_INT18        0x00040000  // Interrupt 18 pend
#define NVIC_PEND0_INT17        0x00020000  // Interrupt 17 pend
#define NVIC_PEND0_INT16        0x00010000  // Interrupt 16 pend
#define NVIC_PEND0_INT15        0x00008000  // Interrupt 15 pend
#define NVIC_PEND0_INT14        0x00004000  // Interrupt 14 pend
#define NVIC_PEND0_INT13        0x00002000  // Interrupt 13 pend
#define NVIC_PEND0_INT12        0x00001000  // Interrupt 12 pend
#define NVIC_PEND0_INT11        0x00000800  // Interrupt 11 pend
#define NVIC_PEND0_INT10        0x00000400  // Interrupt 10 pend
#define NVIC_PEND0_INT9         0x00000200  // Interrupt 9 pend
#define NVIC_PEND0_INT8         0x00000100  // Interrupt 8 pend
#define NVIC_PEND0_INT7         0x00000080  // Interrupt 7 pend
#define NVIC_PEND0_INT6         0x00000040  // Interrupt 6 pend
#define NVIC_PEND0_INT5         0x00000020  // Interrupt 5 pend
#define NVIC_PEND0_INT4         0x00000010  // Interrupt 4 pend
#define NVIC_PEND0_INT3         0x00000008  // Interrupt 3 pend
#define NVIC_PEND0_INT2         0x00000004  // Interrupt 2 pend
#define NVIC_PEND0_INT1         0x00000002  // Interrupt 1 pend
#define NVIC_PEND0_INT0         0x00000001  // Interrupt 0 pend

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND1 register.
//
//*****************************************************************************
#define NVIC_PEND1_INT59        0x08000000  // Interrupt 59 pend
#define NVIC_PEND1_INT58        0x04000000  // Interrupt 58 pend
#define NVIC_PEND1_INT57        0x02000000  // Interrupt 57 pend
#define NVIC_PEND1_INT56        0x01000000  // Interrupt 56 pend
#define NVIC_PEND1_INT55        0x00800000  // Interrupt 55 pend
#define NVIC_PEND1_INT54        0x00400000  // Interrupt 54 pend
#define NVIC_PEND1_INT53        0x00200000  // Interrupt 53 pend
#define NVIC_PEND1_INT52        0x00100000  // Interrupt 52 pend
#define NVIC_PEND1_INT51        0x00080000  // Interrupt 51 pend
#define NVIC_PEND1_INT50        0x00040000  // Interrupt 50 pend
#define NVIC_PEND1_INT49        0x00020000  // Interrupt 49 pend
#define NVIC_PEND1_INT48        0x00010000  // Interrupt 48 pend
#define NVIC_PEND1_INT47        0x00008000  // Interrupt 47 pend
#define NVIC_PEND1_INT46        0x00004000  // Interrupt 46 pend
#define NVIC_PEND1_INT45        0x00002000  // Interrupt 45 pend
#define NVIC_PEND1_INT44        0x00001000  // Interrupt 44 pend
#define NVIC_PEND1_INT43        0x00000800  // Interrupt 43 pend
#define NVIC_PEND1_INT42        0x00000400  // Interrupt 42 pend
#define NVIC_PEND1_INT41        0x00000200  // Interrupt 41 pend
#define NVIC_PEND1_INT40        0x00000100  // Interrupt 40 pend
#define NVIC_PEND1_INT39        0x00000080  // Interrupt 39 pend
#define NVIC_PEND1_INT38        0x00000040  // Interrupt 38 pend
#define NVIC_PEND1_INT37        0x00000020  // Interrupt 37 pend
#define NVIC_PEND1_INT36        0x00000010  // Interrupt 36 pend
#define NVIC_PEND1_INT35        0x00000008  // Interrupt 35 pend
#define NVIC_PEND1_INT34        0x00000004  // Interrupt 34 pend
#define NVIC_PEND1_INT33        0x00000002  // Interrupt 33 pend
#define NVIC_PEND1_INT32        0x00000001  // Interrupt 32 pend

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND0 register.
//
//*****************************************************************************
#define NVIC_UNPEND0_INT31      0x80000000  // Interrupt 31 unpend
#define NVIC_UNPEND0_INT30      0x40000000  // Interrupt 30 unpend
#define NVIC_UNPEND0_INT29      0x20000000  // Interrupt 29 unpend
#define NVIC_UNPEND0_INT28      0x10000000  // Interrupt 28 unpend
#define NVIC_UNPEND0_INT27      0x08000000  // Interrupt 27 unpend
#define NVIC_UNPEND0_INT26      0x04000000  // Interrupt 26 unpend
#define NVIC_UNPEND0_INT25      0x02000000  // Interrupt 25 unpend
#define NVIC_UNPEND0_INT24      0x01000000  // Interrupt 24 unpend
#define NVIC_UNPEND0_INT23      0x00800000  // Interrupt 23 unpend
#define NVIC_UNPEND0_INT22      0x00400000  // Interrupt 22 unpend
#define NVIC_UNPEND0_INT21      0x00200000  // Interrupt 21 unpend
#define NVIC_UNPEND0_INT20      0x00100000  // Interrupt 20 unpend
#define NVIC_UNPEND0_INT19      0x00080000  // Interrupt 19 unpend
#define NVIC_UNPEND0_INT18      0x00040000  // Interrupt 18 unpend
#define NVIC_UNPEND0_INT17      0x00020000  // Interrupt 17 unpend
#define NVIC_UNPEND0_INT16      0x00010000  // Interrupt 16 unpend
#define NVIC_UNPEND0_INT15      0x00008000  // Interrupt 15 unpend
#define NVIC_UNPEND0_INT14      0x00004000  // Interrupt 14 unpend
#define NVIC_UNPEND0_INT13      0x00002000  // Interrupt 13 unpend
#define NVIC_UNPEND0_INT12      0x00001000  // Interrupt 12 unpend
#define NVIC_UNPEND0_INT11      0x00000800  // Interrupt 11 unpend
#define NVIC_UNPEND0_INT10      0x00000400  // Interrupt 10 unpend
#define NVIC_UNPEND0_INT9       0x00000200  // Interrupt 9 unpend
#define NVIC_UNPEND0_INT8       0x00000100  // Interrupt 8 unpend
#define NVIC_UNPEND0_INT7       0x00000080  // Interrupt 7 unpend
#define NVIC_UNPEND0_INT6       0x00000040  // Interrupt 6 unpend
#define NVIC_UNPEND0_INT5       0x00000020  // Interrupt 5 unpend
#define NVIC_UNPEND0_INT4       0x00000010  // Interrupt 4 unpend
#define NVIC_UNPEND0_INT3       0x00000008  // Interrupt 3 unpend
#define NVIC_UNPEND0_INT2       0x00000004  // Interrupt 2 unpend
#define NVIC_UNPEND0_INT1       0x00000002  // Interrupt 1 unpend
#define NVIC_UNPEND0_INT0       0x00000001  // Interrupt 0 unpend

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND1 register.
//
//*****************************************************************************
#define NVIC_UNPEND1_INT59      0x08000000  // Interrupt 59 unpend
#define NVIC_UNPEND1_INT58      0x04000000  // Interrupt 58 unpend
#define NVIC_UNPEND1_INT57      0x02000000  // Interrupt 57 unpend
#define NVIC_UNPEND1_INT56      0x01000000  // Interrupt 56 unpend
#define NVIC_UNPEND1_INT55      0x00800000  // Interrupt 55 unpend
#define NVIC_UNPEND1_INT54      0x00400000  // Interrupt 54 unpend
#define NVIC_UNPEND1_INT53      0x00200000  // Interrupt 53 unpend
#define NVIC_UNPEND1_INT52      0x00100000  // Interrupt 52 unpend
#define NVIC_UNPEND1_INT51      0x00080000  // Interrupt 51 unpend
#define NVIC_UNPEND1_INT50      0x00040000  // Interrupt 50 unpend
#define NVIC_UNPEND1_INT49      0x00020000  // Interrupt 49 unpend
#define NVIC_UNPEND1_INT48      0x00010000  // Interrupt 48 unpend
#define NVIC_UNPEND1_INT47      0x00008000  // Interrupt 47 unpend
#define NVIC_UNPEND1_INT46      0x00004000  // Interrupt 46 unpend
#define NVIC_UNPEND1_INT45      0x00002000  // Interrupt 45 unpend
#define NVIC_UNPEND1_INT44      0x00001000  // Interrupt 44 unpend
#define NVIC_UNPEND1_INT43      0x00000800  // Interrupt 43 unpend
#define NVIC_UNPEND1_INT42      0x00000400  // Interrupt 42 unpend
#define NVIC_UNPEND1_INT41      0x00000200  // Interrupt 41 unpend
#define NVIC_UNPEND1_INT40      0x00000100  // Interrupt 40 unpend
#define NVIC_UNPEND1_INT39      0x00000080  // Interrupt 39 unpend
#define NVIC_UNPEND1_INT38      0x00000040  // Interrupt 38 unpend
#define NVIC_UNPEND1_INT37      0x00000020  // Interrupt 37 unpend
#define NVIC_UNPEND1_INT36      0x00000010  // Interrupt 36 unpend
#define NVIC_UNPEND1_INT35      0x00000008  // Interrupt 35 unpend
#define NVIC_UNPEND1_INT34      0x00000004  // Interrupt 34 unpend
#define NVIC_UNPEND1_INT33      0x00000002  // Interrupt 33 unpend
#define NVIC_UNPEND1_INT32      0x00000001  // Interrupt 32 unpend

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE0 register.
//
//*****************************************************************************
#define NVIC_ACTIVE0_INT31      0x80000000  // Interrupt 31 active
#define NVIC_ACTIVE0_INT30      0x40000000  // Interrupt 30 active
#define NVIC_ACTIVE0_INT29      0x20000000  // Interrupt 29 active
#define NVIC_ACTIVE0_INT28      0x10000000  // Interrupt 28 active
#define NVIC_ACTIVE0_INT27      0x08000000  // Interrupt 27 active
#define NVIC_ACTIVE0_INT26      0x04000000  // Interrupt 26 active
#define NVIC_ACTIVE0_INT25      0x02000000  // Interrupt 25 active
#define NVIC_ACTIVE0_INT24      0x01000000  // Interrupt 24 active
#define NVIC_ACTIVE0_INT23      0x00800000  // Interrupt 23 active
#define NVIC_ACTIVE0_INT22      0x00400000  // Interrupt 22 active
#define NVIC_ACTIVE0_INT21      0x00200000  // Interrupt 21 active
#define NVIC_ACTIVE0_INT20      0x00100000  // Interrupt 20 active
#define NVIC_ACTIVE0_INT19      0x00080000  // Interrupt 19 active
#define NVIC_ACTIVE0_INT18      0x00040000  // Interrupt 18 active
#define NVIC_ACTIVE0_INT17      0x00020000  // Interrupt 17 active
#define NVIC_ACTIVE0_INT16      0x00010000  // Interrupt 16 active
#define NVIC_ACTIVE0_INT15      0x00008000  // Interrupt 15 active
#define NVIC_ACTIVE0_INT14      0x00004000  // Interrupt 14 active
#define NVIC_ACTIVE0_INT13      0x00002000  // Interrupt 13 active
#define NVIC_ACTIVE0_INT12      0x00001000  // Interrupt 12 active
#define NVIC_ACTIVE0_INT11      0x00000800  // Interrupt 11 active
#define NVIC_ACTIVE0_INT10      0x00000400  // Interrupt 10 active
#define NVIC_ACTIVE0_INT9       0x00000200  // Interrupt 9 active
#define NVIC_ACTIVE0_INT8       0x00000100  // Interrupt 8 active
#define NVIC_ACTIVE0_INT7       0x00000080  // Interrupt 7 active
#define NVIC_ACTIVE0_INT6       0x00000040  // Interrupt 6 active
#define NVIC_ACTIVE0_INT5       0x00000020  // Interrupt 5 active
#define NVIC_ACTIVE0_INT4       0x00000010  // Interrupt 4 active
#define NVIC_ACTIVE0_INT3       0x00000008  // Interrupt 3 active
#define NVIC_ACTIVE0_INT2       0x00000004  // Interrupt 2 active
#define NVIC_ACTIVE0_INT1       0x00000002  // Interrupt 1 active
#define NVIC_ACTIVE0_INT0       0x00000001  // Interrupt 0 active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE1 register.
//
//*****************************************************************************
#define NVIC_ACTIVE1_INT59      0x08000000  // Interrupt 59 active
#define NVIC_ACTIVE1_INT58      0x04000000  // Interrupt 58 active
#define NVIC_ACTIVE1_INT57      0x02000000  // Interrupt 57 active
#define NVIC_ACTIVE1_INT56      0x01000000  // Interrupt 56 active
#define NVIC_ACTIVE1_INT55      0x00800000  // Interrupt 55 active
#define NVIC_ACTIVE1_INT54      0x00400000  // Interrupt 54 active
#define NVIC_ACTIVE1_INT53      0x00200000  // Interrupt 53 active
#define NVIC_ACTIVE1_INT52      0x00100000  // Interrupt 52 active
#define NVIC_ACTIVE1_INT51      0x00080000  // Interrupt 51 active
#define NVIC_ACTIVE1_INT50      0x00040000  // Interrupt 50 active
#define NVIC_ACTIVE1_INT49      0x00020000  // Interrupt 49 active
#define NVIC_ACTIVE1_INT48      0x00010000  // Interrupt 48 active
#define NVIC_ACTIVE1_INT47      0x00008000  // Interrupt 47 active
#define NVIC_ACTIVE1_INT46      0x00004000  // Interrupt 46 active
#define NVIC_ACTIVE1_INT45      0x00002000  // Interrupt 45 active
#define NVIC_ACTIVE1_INT44      0x00001000  // Interrupt 44 active
#define NVIC_ACTIVE1_INT43      0x00000800  // Interrupt 43 active
#define NVIC_ACTIVE1_INT42      0x00000400  // Interrupt 42 active
#define NVIC_ACTIVE1_INT41      0x00000200  // Interrupt 41 active
#define NVIC_ACTIVE1_INT40      0x00000100  // Interrupt 40 active
#define NVIC_ACTIVE1_INT39      0x00000080  // Interrupt 39 active
#define NVIC_ACTIVE1_INT38      0x00000040  // Interrupt 38 active
#define NVIC_ACTIVE1_INT37      0x00000020  // Interrupt 37 active
#define NVIC_ACTIVE1_INT36      0x00000010  // Interrupt 36 active
#define NVIC_ACTIVE1_INT35      0x00000008  // Interrupt 35 active
#define NVIC_ACTIVE1_INT34      0x00000004  // Interrupt 34 active
#define NVIC_ACTIVE1_INT33      0x00000002  // Interrupt 33 active
#define NVIC_ACTIVE1_INT32      0x00000001  // Interrupt 32 active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI0 register.
//
//*****************************************************************************
#define NVIC_PRI0_INT3_M        0xFF000000  // Interrupt 3 priority mask
#define NVIC_PRI0_INT2_M        0x00FF0000  // Interrupt 2 priority mask
#define NVIC_PRI0_INT1_M        0x0000FF00  // Interrupt 1 priority mask
#define NVIC_PRI0_INT0_M        0x000000FF  // Interrupt 0 priority mask
#define NVIC_PRI0_INT3_S        24
#define NVIC_PRI0_INT2_S        16
#define NVIC_PRI0_INT1_S        8
#define NVIC_PRI0_INT0_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI1 register.
//
//*****************************************************************************
#define NVIC_PRI1_INT7_M        0xFF000000  // Interrupt 7 priority mask
#define NVIC_PRI1_INT6_M        0x00FF0000  // Interrupt 6 priority mask
#define NVIC_PRI1_INT5_M        0x0000FF00  // Interrupt 5 priority mask
#define NVIC_PRI1_INT4_M        0x000000FF  // Interrupt 4 priority mask
#define NVIC_PRI1_INT7_S        24
#define NVIC_PRI1_INT6_S        16
#define NVIC_PRI1_INT5_S        8
#define NVIC_PRI1_INT4_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI2 register.
//
//*****************************************************************************
#define NVIC_PRI2_INT11_M       0xFF000000  // Interrupt 11 priority mask
#define NVIC_PRI2_INT10_M       0x00FF0000  // Interrupt 10 priority mask
#define NVIC_PRI2_INT9_M        0x0000FF00  // Interrupt 9 priority mask
#define NVIC_PRI2_INT8_M        0x000000FF  // Interrupt 8 priority mask
#define NVIC_PRI2_INT11_S       24
#define NVIC_PRI2_INT10_S       16
#define NVIC_PRI2_INT9_S        8
#define NVIC_PRI2_INT8_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI3 register.
//
//*****************************************************************************
#define NVIC_PRI3_INT15_M       0xFF000000  // Interrupt 15 priority mask
#define NVIC_PRI3_INT14_M       0x00FF0000  // Interrupt 14 priority mask
#define NVIC_PRI3_INT13_M       0x0000FF00  // Interrupt 13 priority mask
#define NVIC_PRI3_INT12_M       0x000000FF  // Interrupt 12 priority mask
#define NVIC_PRI3_INT15_S       24
#define NVIC_PRI3_INT14_S       16
#define NVIC_PRI3_INT13_S       8
#define NVIC_PRI3_INT12_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI4 register.
//
//*****************************************************************************
#define NVIC_PRI4_INT19_M       0xFF000000  // Interrupt 19 priority mask
#define NVIC_PRI4_INT18_M       0x00FF0000  // Interrupt 18 priority mask
#define NVIC_PRI4_INT17_M       0x0000FF00  // Interrupt 17 priority mask
#define NVIC_PRI4_INT16_M       0x000000FF  // Interrupt 16 priority mask
#define NVIC_PRI4_INT19_S       24
#define NVIC_PRI4_INT18_S       16
#define NVIC_PRI4_INT17_S       8
#define NVIC_PRI4_INT16_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI5 register.
//
//*****************************************************************************
#define NVIC_PRI5_INT23_M       0xFF000000  // Interrupt 23 priority mask
#define NVIC_PRI5_INT22_M       0x00FF0000  // Interrupt 22 priority mask
#define NVIC_PRI5_INT21_M       0x0000FF00  // Interrupt 21 priority mask
#define NVIC_PRI5_INT20_M       0x000000FF  // Interrupt 20 priority mask
#define NVIC_PRI5_INT23_S       24
#define NVIC_PRI5_INT22_S       16
#define NVIC_PRI5_INT21_S       8
#define NVIC_PRI5_INT20_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI6 register.
//
//*****************************************************************************
#define NVIC_PRI6_INT27_M       0xFF000000  // Interrupt 27 priority mask
#define NVIC_PRI6_INT26_M       0x00FF0000  // Interrupt 26 priority mask
#define NVIC_PRI6_INT25_M       0x0000FF00  // Interrupt 25 priority mask
#define NVIC_PRI6_INT24_M       0x000000FF  // Interrupt 24 priority mask
#define NVIC_PRI6_INT27_S       24
#define NVIC_PRI6_INT26_S       16
#define NVIC_PRI6_INT25_S       8
#define NVIC_PRI6_INT24_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI7 register.
//
//*****************************************************************************
#define NVIC_PRI7_INT31_M       0xFF000000  // Interrupt 31 priority mask
#define NVIC_PRI7_INT30_M       0x00FF0000  // Interrupt 30 priority mask
#define NVIC_PRI7_INT29_M       0x0000FF00  // Interrupt 29 priority mask
#define NVIC_PRI7_INT28_M       0x000000FF  // Interrupt 28 priority mask
#define NVIC_PRI7_INT31_S       24
#define NVIC_PRI7_INT30_S       16
#define NVIC_PRI7_INT29_S       8
#define NVIC_PRI7_INT28_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI8 register.
//
//*****************************************************************************
#define NVIC_PRI8_INT35_M       0xFF000000  // Interrupt 35 priority mask
#define NVIC_PRI8_INT34_M       0x00FF0000  // Interrupt 34 priority mask
#define NVIC_PRI8_INT33_M       0x0000FF00  // Interrupt 33 priority mask
#define NVIC_PRI8_INT32_M       0x000000FF  // Interrupt 32 priority mask
#define NVIC_PRI8_INT35_S       24
#define NVIC_PRI8_INT34_S       16
#define NVIC_PRI8_INT33_S       8
#define NVIC_PRI8_INT32_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI9 register.
//
//*****************************************************************************
#define NVIC_PRI9_INT39_M       0xFF000000  // Interrupt 39 priority mask
#define NVIC_PRI9_INT38_M       0x00FF0000  // Interrupt 38 priority mask
#define NVIC_PRI9_INT37_M       0x0000FF00  // Interrupt 37 priority mask
#define NVIC_PRI9_INT36_M       0x000000FF  // Interrupt 36 priority mask
#define NVIC_PRI9_INT39_S       24
#define NVIC_PRI9_INT38_S       16
#define NVIC_PRI9_INT37_S       8
#define NVIC_PRI9_INT36_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI10 register.
//
//*****************************************************************************
#define NVIC_PRI10_INT43_M      0xFF000000  // Interrupt 43 priority mask
#define NVIC_PRI10_INT42_M      0x00FF0000  // Interrupt 42 priority mask
#define NVIC_PRI10_INT41_M      0x0000FF00  // Interrupt 41 priority mask
#define NVIC_PRI10_INT40_M      0x000000FF  // Interrupt 40 priority mask
#define NVIC_PRI10_INT43_S      24
#define NVIC_PRI10_INT42_S      16
#define NVIC_PRI10_INT41_S      8
#define NVIC_PRI10_INT40_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CPUID register.
//
//*****************************************************************************
#define NVIC_CPUID_IMP_M        0xFF000000  // Implementer
#define NVIC_CPUID_VAR_M        0x00F00000  // Variant
#define NVIC_CPUID_PARTNO_M     0x0000FFF0  // Processor part number
#define NVIC_CPUID_REV_M        0x0000000F  // Revision

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_INT_CTRL register.
//
//*****************************************************************************
#define NVIC_INT_CTRL_NMI_SET   0x80000000  // Pend a NMI
#define NVIC_INT_CTRL_PEND_SV   0x10000000  // Pend a PendSV
#define NVIC_INT_CTRL_UNPEND_SV 0x08000000  // Unpend a PendSV
#define NVIC_INT_CTRL_PENDSTSET 0x04000000  // Set pending SysTick interrupt
#define NVIC_INT_CTRL_PENDSTCLR 0x02000000  // Clear pending SysTick interrupt
#define NVIC_INT_CTRL_ISR_PRE   0x00800000  // Debug interrupt handling
#define NVIC_INT_CTRL_ISR_PEND  0x00400000  // Debug interrupt pending
#define NVIC_INT_CTRL_VEC_PEN_M 0x003FF000  // Highest pending exception
#define NVIC_INT_CTRL_RET_BASE  0x00000800  // Return to base
#define NVIC_INT_CTRL_VEC_ACT_M 0x000003FF  // Current active exception
#define NVIC_INT_CTRL_VEC_PEN_S 12
#define NVIC_INT_CTRL_VEC_ACT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_VTABLE register.
//
//*****************************************************************************
#define NVIC_VTABLE_BASE        0x20000000  // Vector table base
#define NVIC_VTABLE_OFFSET_M    0x1FFFFF00  // Vector table offset
#define NVIC_VTABLE_OFFSET_S    8

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_APINT register.
//
//*****************************************************************************
#define NVIC_APINT_VECTKEY_M    0xFFFF0000  // Vector key mask
#define NVIC_APINT_VECTKEY      0x05FA0000  // Vector key
#define NVIC_APINT_ENDIANESS    0x00008000  // Data endianess
#define NVIC_APINT_PRIGROUP_M   0x00000700  // Priority group
#define NVIC_APINT_PRIGROUP_0_8 0x00000700  // Priority group 0.8 split
#define NVIC_APINT_PRIGROUP_1_7 0x00000600  // Priority group 1.7 split
#define NVIC_APINT_PRIGROUP_2_6 0x00000500  // Priority group 2.6 split
#define NVIC_APINT_PRIGROUP_3_5 0x00000400  // Priority group 3.5 split
#define NVIC_APINT_PRIGROUP_4_4 0x00000300  // Priority group 4.4 split
#define NVIC_APINT_PRIGROUP_5_3 0x00000200  // Priority group 5.3 split
#define NVIC_APINT_PRIGROUP_6_2 0x00000100  // Priority group 6.2 split
#define NVIC_APINT_SYSRESETREQ  0x00000004  // System reset request
#define NVIC_APINT_VECT_CLR_ACT 0x00000002  // Clear active NMI/fault info
#define NVIC_APINT_VECT_RESET   0x00000001  // System reset
#define NVIC_APINT_PRIGROUP_7_1 0x00000000  // Priority group 7.1 split

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_CTRL register.
//
//*****************************************************************************
#define NVIC_SYS_CTRL_SEVONPEND 0x00000010  // Wakeup on pend
#define NVIC_SYS_CTRL_SLEEPDEEP 0x00000004  // Deep sleep enable
#define NVIC_SYS_CTRL_SLEEPEXIT 0x00000002  // Sleep on ISR exit

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CFG_CTRL register.
//
//*****************************************************************************
#define NVIC_CFG_CTRL_BFHFNMIGN 0x00000100  // Ignore bus fault in NMI/fault
#define NVIC_CFG_CTRL_DIV0      0x00000010  // Trap on divide by 0
#define NVIC_CFG_CTRL_UNALIGNED 0x00000008  // Trap on unaligned access
#define NVIC_CFG_CTRL_DEEP_PEND 0x00000004  // Allow deep interrupt trigger
#define NVIC_CFG_CTRL_MAIN_PEND 0x00000002  // Allow main interrupt trigger
#define NVIC_CFG_CTRL_BASE_THR  0x00000001  // Thread state control

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI1 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI1_RES_M     0xFF000000  // Priority of reserved handler
#define NVIC_SYS_PRI1_USAGE_M   0x00FF0000  // Priority of usage fault handler
#define NVIC_SYS_PRI1_BUS_M     0x0000FF00  // Priority of bus fault handler
#define NVIC_SYS_PRI1_MEM_M     0x000000FF  // Priority of mem manage handler
#define NVIC_SYS_PRI1_USAGE_S   16
#define NVIC_SYS_PRI1_BUS_S     8
#define NVIC_SYS_PRI1_MEM_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI2 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI2_SVC_M     0xFF000000  // Priority of SVCall handler
#define NVIC_SYS_PRI2_RES_M     0x00FFFFFF  // Priority of reserved handlers
#define NVIC_SYS_PRI2_SVC_S     24

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI3 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI3_TICK_M    0xFF000000  // Priority of Sys Tick handler
#define NVIC_SYS_PRI3_PENDSV_M  0x00FF0000  // Priority of PendSV handler
#define NVIC_SYS_PRI3_RES_M     0x0000FF00  // Priority of reserved handler
#define NVIC_SYS_PRI3_DEBUG_M   0x000000FF  // Priority of debug handler
#define NVIC_SYS_PRI3_TICK_S    24
#define NVIC_SYS_PRI3_PENDSV_S  16
#define NVIC_SYS_PRI3_DEBUG_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_HND_CTRL
// register.
//
//*****************************************************************************
#define NVIC_SYS_HND_CTRL_USAGE 0x00040000  // Usage fault enable
#define NVIC_SYS_HND_CTRL_BUS   0x00020000  // Bus fault enable
#define NVIC_SYS_HND_CTRL_MEM   0x00010000  // Mem manage fault enable
#define NVIC_SYS_HND_CTRL_SVC   0x00008000  // SVCall is pended
#define NVIC_SYS_HND_CTRL_BUSP  0x00004000  // Bus fault is pended
#define NVIC_SYS_HND_CTRL_TICK  0x00000800  // Sys tick is active
#define NVIC_SYS_HND_CTRL_PNDSV 0x00000400  // PendSV is active
#define NVIC_SYS_HND_CTRL_MON   0x00000100  // Monitor is active
#define NVIC_SYS_HND_CTRL_SVCA  0x00000080  // SVCall is active
#define NVIC_SYS_HND_CTRL_USGA  0x00000008  // Usage fault is active
#define NVIC_SYS_HND_CTRL_BUSA  0x00000002  // Bus fault is active
#define NVIC_SYS_HND_CTRL_MEMA  0x00000001  // Mem manage is active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_FAULT_STAT_DIV0    0x02000000  // Divide by zero fault
#define NVIC_FAULT_STAT_UNALIGN 0x01000000  // Unaligned access fault
#define NVIC_FAULT_STAT_NOCP    0x00080000  // No coprocessor fault
#define NVIC_FAULT_STAT_INVPC   0x00040000  // Invalid PC fault
#define NVIC_FAULT_STAT_INVSTAT 0x00020000  // Invalid state fault
#define NVIC_FAULT_STAT_UNDEF   0x00010000  // Undefined instruction fault
#define NVIC_FAULT_STAT_BFARV   0x00008000  // BFAR is valid
#define NVIC_FAULT_STAT_BSTKE   0x00001000  // Stack bus fault
#define NVIC_FAULT_STAT_BUSTKE  0x00000800  // Unstack bus fault
#define NVIC_FAULT_STAT_IMPRE   0x00000400  // Imprecise data bus error
#define NVIC_FAULT_STAT_PRECISE 0x00000200  // Precise data bus error
#define NVIC_FAULT_STAT_IBUS    0x00000100  // Instruction bus fault
#define NVIC_FAULT_STAT_MMARV   0x00000080  // MMAR is valid
#define NVIC_FAULT_STAT_MSTKE   0x00000010  // Stack access violation
#define NVIC_FAULT_STAT_MUSTKE  0x00000008  // Unstack access violation
#define NVIC_FAULT_STAT_DERR    0x00000002  // Data access violation
#define NVIC_FAULT_STAT_IERR    0x00000001  // Instruction access violation

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_HFAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_HFAULT_STAT_DBG    0x80000000  // Debug event
#define NVIC_HFAULT_STAT_FORCED 0x40000000  // Cannot execute fault handler
#define NVIC_HFAULT_STAT_VECT   0x00000002  // Vector table read fault

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DEBUG_STAT
// register.
//
//*****************************************************************************
#define NVIC_DEBUG_STAT_EXTRNL  0x00000010  // EDBGRQ asserted
#define NVIC_DEBUG_STAT_VCATCH  0x00000008  // Vector catch
#define NVIC_DEBUG_STAT_DWTTRAP 0x00000004  // DWT match
#define NVIC_DEBUG_STAT_BKPT    0x00000002  // Breakpoint instruction
#define NVIC_DEBUG_STAT_HALTED  0x00000001  // Halt request

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MM_ADDR register.
//
//*****************************************************************************
#define NVIC_MM_ADDR_M          0xFFFFFFFF  // Data fault address
#define NVIC_MM_ADDR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_ADDR
// register.
//
//*****************************************************************************
#define NVIC_FAULT_ADDR_M       0xFFFFFFFF  // Data bus fault address
#define NVIC_FAULT_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_TYPE register.
//
//*****************************************************************************
#define NVIC_MPU_TYPE_IREGION_M 0x00FF0000  // Number of I regions
#define NVIC_MPU_TYPE_DREGION_M 0x0000FF00  // Number of D regions
#define NVIC_MPU_TYPE_SEPARATE  0x00000001  // Separate or unified MPU
#define NVIC_MPU_TYPE_IREGION_S 16
#define NVIC_MPU_TYPE_DREGION_S 8

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_CTRL register.
//
//*****************************************************************************
#define NVIC_MPU_CTRL_PRIVDEFEN 0x00000004  // MPU default region in priv mode
#define NVIC_MPU_CTRL_HFNMIENA  0x00000002  // MPU enabled during faults
#define NVIC_MPU_CTRL_ENABLE    0x00000001  // MPU enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_NUMBER
// register.
//
//*****************************************************************************
#define NVIC_MPU_NUMBER_M       0x000000FF  // MPU region to access
#define NVIC_MPU_NUMBER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE register.
//
//*****************************************************************************
#define NVIC_MPU_BASE_ADDR_M    0xFFFFFFE0  // Base address mask
#define NVIC_MPU_BASE_VALID     0x00000010  // Region number valid
#define NVIC_MPU_BASE_REGION_M  0x0000000F  // Region number
#define NVIC_MPU_BASE_ADDR_S    8
#define NVIC_MPU_BASE_REGION_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR_M         0xFFFF0000  // Attributes
#define NVIC_MPU_ATTR_AP_NO_NO  0x00000000  // prv: no access, usr: no access
#define NVIC_MPU_ATTR_BUFFRABLE 0x00010000  // Bufferable
#define NVIC_MPU_ATTR_CACHEABLE 0x00020000  // Cacheable
#define NVIC_MPU_ATTR_SHAREABLE 0x00040000  // Shareable
#define NVIC_MPU_ATTR_TEX_M     0x00380000  // Type extension mask
#define NVIC_MPU_ATTR_AP_RW_NO  0x01000000  // prv: rw, usr: none
#define NVIC_MPU_ATTR_AP_RW_RO  0x02000000  // prv: rw, usr: read-only
#define NVIC_MPU_ATTR_AP_RW_RW  0x03000000  // prv: rw, usr: rw
#define NVIC_MPU_ATTR_AP_RO_NO  0x05000000  // prv: ro, usr: none
#define NVIC_MPU_ATTR_AP_RO_RO  0x06000000  // prv: ro, usr: ro
#define NVIC_MPU_ATTR_AP_M      0x07000000  // Access permissions mask
#define NVIC_MPU_ATTR_XN        0x10000000  // Execute disable
#define NVIC_MPU_ATTR_SRD_M     0x0000FF00  // Sub-region disable mask
#define NVIC_MPU_ATTR_SRD_0     0x00000100  // Sub-region 0 disable
#define NVIC_MPU_ATTR_SRD_1     0x00000200  // Sub-region 1 disable
#define NVIC_MPU_ATTR_SRD_2     0x00000400  // Sub-region 2 disable
#define NVIC_MPU_ATTR_SRD_3     0x00000800  // Sub-region 3 disable
#define NVIC_MPU_ATTR_SRD_4     0x00001000  // Sub-region 4 disable
#define NVIC_MPU_ATTR_SRD_5     0x00002000  // Sub-region 5 disable
#define NVIC_MPU_ATTR_SRD_6     0x00004000  // Sub-region 6 disable
#define NVIC_MPU_ATTR_SRD_7     0x00008000  // Sub-region 7 disable
#define NVIC_MPU_ATTR_SIZE_M    0x0000003E  // Region size mask
#define NVIC_MPU_ATTR_SIZE_32B  0x00000008  // Region size 32 bytes
#define NVIC_MPU_ATTR_SIZE_64B  0x0000000A  // Region size 64 bytes
#define NVIC_MPU_ATTR_SIZE_128B 0x0000000C  // Region size 128 bytes
#define NVIC_MPU_ATTR_SIZE_256B 0x0000000E  // Region size 256 bytes
#define NVIC_MPU_ATTR_SIZE_512B 0x00000010  // Region size 512 bytes
#define NVIC_MPU_ATTR_SIZE_1K   0x00000012  // Region size 1 Kbytes
#define NVIC_MPU_ATTR_SIZE_2K   0x00000014  // Region size 2 Kbytes
#define NVIC_MPU_ATTR_SIZE_4K   0x00000016  // Region size 4 Kbytes
#define NVIC_MPU_ATTR_SIZE_8K   0x00000018  // Region size 8 Kbytes
#define NVIC_MPU_ATTR_SIZE_16K  0x0000001A  // Region size 16 Kbytes
#define NVIC_MPU_ATTR_SIZE_32K  0x0000001C  // Region size 32 Kbytes
#define NVIC_MPU_ATTR_SIZE_64K  0x0000001E  // Region size 64 Kbytes
#define NVIC_MPU_ATTR_SIZE_128K 0x00000020  // Region size 128 Kbytes
#define NVIC_MPU_ATTR_SIZE_256K 0x00000022  // Region size 256 Kbytes
#define NVIC_MPU_ATTR_SIZE_512K 0x00000024  // Region size 512 Kbytes
#define NVIC_MPU_ATTR_SIZE_1M   0x00000026  // Region size 1 Mbytes
#define NVIC_MPU_ATTR_SIZE_2M   0x00000028  // Region size 2 Mbytes
#define NVIC_MPU_ATTR_SIZE_4M   0x0000002A  // Region size 4 Mbytes
#define NVIC_MPU_ATTR_SIZE_8M   0x0000002C  // Region size 8 Mbytes
#define NVIC_MPU_ATTR_SIZE_16M  0x0000002E  // Region size 16 Mbytes
#define NVIC_MPU_ATTR_SIZE_32M  0x00000030  // Region size 32 Mbytes
#define NVIC_MPU_ATTR_SIZE_64M  0x00000032  // Region size 64 Mbytes
#define NVIC_MPU_ATTR_SIZE_128M 0x00000034  // Region size 128 Mbytes
#define NVIC_MPU_ATTR_SIZE_256M 0x00000036  // Region size 256 Mbytes
#define NVIC_MPU_ATTR_SIZE_512M 0x00000038  // Region size 512 Mbytes
#define NVIC_MPU_ATTR_SIZE_1G   0x0000003A  // Region size 1 Gbytes
#define NVIC_MPU_ATTR_SIZE_2G   0x0000003C  // Region size 2 Gbytes
#define NVIC_MPU_ATTR_SIZE_4G   0x0000003E  // Region size 4 Gbytes
#define NVIC_MPU_ATTR_ENABLE    0x00000001  // Region enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_CTRL register.
//
//*****************************************************************************
#define NVIC_DBG_CTRL_DBGKEY_M  0xFFFF0000  // Debug key mask
#define NVIC_DBG_CTRL_DBGKEY    0xA05F0000  // Debug key
#define NVIC_DBG_CTRL_S_RESET_ST \
                                0x02000000  // Core has reset since last read
#define NVIC_DBG_CTRL_S_RETIRE_ST \
                                0x01000000  // Core has executed insruction
                                            // since last read
#define NVIC_DBG_CTRL_S_LOCKUP  0x00080000  // Core is locked up
#define NVIC_DBG_CTRL_S_SLEEP   0x00040000  // Core is sleeping
#define NVIC_DBG_CTRL_S_HALT    0x00020000  // Core status on halt
#define NVIC_DBG_CTRL_S_REGRDY  0x00010000  // Register read/write available
#define NVIC_DBG_CTRL_C_SNAPSTALL \
                                0x00000020  // Breaks a stalled load/store
#define NVIC_DBG_CTRL_C_MASKINT 0x00000008  // Mask interrupts when stepping
#define NVIC_DBG_CTRL_C_STEP    0x00000004  // Step the core
#define NVIC_DBG_CTRL_C_HALT    0x00000002  // Halt the core
#define NVIC_DBG_CTRL_C_DEBUGEN 0x00000001  // Enable debug

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_XFER register.
//
//*****************************************************************************
#define NVIC_DBG_XFER_REG_WNR   0x00010000  // Write or not read
#define NVIC_DBG_XFER_REG_SEL_M 0x0000001F  // Register
#define NVIC_DBG_XFER_REG_CFBP  0x00000014  // Control/Fault/BasePri/PriMask
#define NVIC_DBG_XFER_REG_DSP   0x00000013  // Deep SP
#define NVIC_DBG_XFER_REG_PSP   0x00000012  // Process SP
#define NVIC_DBG_XFER_REG_MSP   0x00000011  // Main SP
#define NVIC_DBG_XFER_REG_FLAGS 0x00000010  // xPSR/Flags register
#define NVIC_DBG_XFER_REG_R15   0x0000000F  // Register R15
#define NVIC_DBG_XFER_REG_R14   0x0000000E  // Register R14
#define NVIC_DBG_XFER_REG_R13   0x0000000D  // Register R13
#define NVIC_DBG_XFER_REG_R12   0x0000000C  // Register R12
#define NVIC_DBG_XFER_REG_R11   0x0000000B  // Register R11
#define NVIC_DBG_XFER_REG_R10   0x0000000A  // Register R10
#define NVIC_DBG_XFER_REG_R9    0x00000009  // Register R9
#define NVIC_DBG_XFER_REG_R8    0x00000008  // Register R8
#define NVIC_DBG_XFER_REG_R7    0x00000007  // Register R7
#define NVIC_DBG_XFER_REG_R6    0x00000006  // Register R6
#define NVIC_DBG_XFER_REG_R5    0x00000005  // Register R5
#define NVIC_DBG_XFER_REG_R4    0x00000004  // Register R4
#define NVIC_DBG_XFER_REG_R3    0x00000003  // Register R3
#define NVIC_DBG_XFER_REG_R2    0x00000002  // Register R2
#define NVIC_DBG_XFER_REG_R1    0x00000001  // Register R1
#define NVIC_DBG_XFER_REG_R0    0x00000000  // Register R0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_DATA register.
//
//*****************************************************************************
#define NVIC_DBG_DATA_M         0xFFFFFFFF  // Data temporary cache
#define NVIC_DBG_DATA_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_INT register.
//
//*****************************************************************************
#define NVIC_DBG_INT_HARDERR    0x00000400  // Debug trap on hard fault
#define NVIC_DBG_INT_INTERR     0x00000200  // Debug trap on interrupt errors
#define NVIC_DBG_INT_BUSERR     0x00000100  // Debug trap on bus error
#define NVIC_DBG_INT_STATERR    0x00000080  // Debug trap on usage fault state
#define NVIC_DBG_INT_CHKERR     0x00000040  // Debug trap on usage fault check
#define NVIC_DBG_INT_NOCPERR    0x00000020  // Debug trap on coprocessor error
#define NVIC_DBG_INT_MMERR      0x00000010  // Debug trap on mem manage fault
#define NVIC_DBG_INT_RESET      0x00000008  // Core reset status
#define NVIC_DBG_INT_RSTPENDCLR 0x00000004  // Clear pending core reset
#define NVIC_DBG_INT_RSTPENDING 0x00000002  // Core reset is pending
#define NVIC_DBG_INT_RSTVCATCH  0x00000001  // Reset vector catch

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SW_TRIG register.
//
//*****************************************************************************
#define NVIC_SW_TRIG_INTID_M    0x000003FF  // Interrupt to trigger
#define NVIC_SW_TRIG_INTID_S    0

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// Deprecated defines for the bit fields in the USB_O_RXFIFOADD register.
//
//*****************************************************************************
#define USB_RXFIFOADD_ADDR_0    0x00000000  // 0
#define USB_RXFIFOADD_ADDR_8    0x00000001  // 8
#define USB_RXFIFOADD_ADDR_16   0x00000002  // 16
#define USB_RXFIFOADD_ADDR_32   0x00000003  // 32
#define USB_RXFIFOADD_ADDR_64   0x00000004  // 64
#define USB_RXFIFOADD_ADDR_128  0x00000005  // 128
#define USB_RXFIFOADD_ADDR_256  0x00000006  // 256
#define USB_RXFIFOADD_ADDR_512  0x00000007  // 512
#define USB_RXFIFOADD_ADDR_1024 0x00000008  // 1024
#define USB_RXFIFOADD_ADDR_2048 0x00000009  // 2048

//*****************************************************************************
//
// Deprecated defines for the bit fields in the USB_O_TXFIFOADD register.
//
//*****************************************************************************
#define USB_TXFIFOADD_ADDR_0    0x00000000  // 0
#define USB_TXFIFOADD_ADDR_8    0x00000001  // 8
#define USB_TXFIFOADD_ADDR_16   0x00000002  // 16
#define USB_TXFIFOADD_ADDR_32   0x00000003  // 32
#define USB_TXFIFOADD_ADDR_64   0x00000004  // 64
#define USB_TXFIFOADD_ADDR_128  0x00000005  // 128
#define USB_TXFIFOADD_ADDR_256  0x00000006  // 256
#define USB_TXFIFOADD_ADDR_512  0x00000007  // 512
#define USB_TXFIFOADD_ADDR_1024 0x00000008  // 1024
#define USB_TXFIFOADD_ADDR_2048 0x00000009  // 2048

//*****************************************************************************
//
// Deprecated defines for the bit fields in the EPI_O_HB8CFG2 register.
//
//*****************************************************************************
#define EPI_HB8CFG2_CSCFG       0x01000000  // CSn Configuration

//*****************************************************************************
//
// Deprecated defines for the bit fields in the EPI_O_BAUD register.
//
//*****************************************************************************
#define EPI_BAUD_COUNT_M        0x0000FFFF  // Baud Rate Counter
#define EPI_BAUD_COUNT_S        0

//*****************************************************************************
//
// Deprecated defines for the bit fields in the FLASH_FMC register.
//
//*****************************************************************************
#define FLASH_FMC_WRKEY_M       0xFFFF0000  // Flash Memory Write Key
#define FLASH_FMC_WRKEY_S       16

//*****************************************************************************
//
// Deprecated defines for the bit fields in the SYSCTL_RCC2 register.
//
//*****************************************************************************
#define SYSCTL_RCC2_FRACT       0x00400000  // Fractional divide
#define SYSCTL_RCC2_USEFRACT    0x40000000  // Use fractional divider

//*****************************************************************************
//
// Deprecated defines for the bit fields in the SYSCTL_DID1 register.
//
//*****************************************************************************
#define SYSCTL_DID1_PKG_28SOIC  0x00000000  // SOIC package
#define SYSCTL_DID1_PKG_48QFP   0x00000008  // QFP package

//*****************************************************************************
//
// Deprecated defines for the NVIC register addresses.
//
//*****************************************************************************
#define NVIC_MPU_R              (*((volatile unsigned long *)0xE000ED9C))

#endif

#endif // __LM3S9790_H__