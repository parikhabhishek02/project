/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


#define IOCON_PIO_DIGITAL_EN 0x80u    /*!<@brief Enables digital function */
#define IOCON_PIO_FUNC1 0x01u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_INPFILT_OFF 0x0100u /*!<@brief Input filter disabled */
#define IOCON_PIO_INV_DI 0x00u        /*!<@brief Input function is not inverted */
#define IOCON_PIO_MODE_INACT 0x00u    /*!<@brief No addition pin function */
#define IOCON_PIO_OPENDRAIN_DI 0x00u  /*!<@brief Open drain is disabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u /*!<@brief Standard mode, output slew rate control is enabled */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_DIGITAL_EN 0x80u    /*!<@brief Enables digital function */
#define IOCON_PIO_FUNC1 0x01u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_I2CDRIVE_LOW 0x00u  /*!<@brief Low drive: 4 mA */
#define IOCON_PIO_I2CFILTER_EN 0x00u  /*!<@brief I2C 50 ns glitch filter enabled */
#define IOCON_PIO_I2CSLEW_I2C 0x00u   /*!<@brief I2C mode */
#define IOCON_PIO_INPFILT_OFF 0x0100u /*!<@brief Input filter disabled */
#define IOCON_PIO_INV_DI 0x00u        /*!<@brief Input function is not inverted */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void I2C4_InitPins(void); /* Function assigned for the Cortex-M0P */

#define PIO025_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO025_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO026_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO026_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void I2C4_DeinitPins(void); /* Function assigned for the Cortex-M0P */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
