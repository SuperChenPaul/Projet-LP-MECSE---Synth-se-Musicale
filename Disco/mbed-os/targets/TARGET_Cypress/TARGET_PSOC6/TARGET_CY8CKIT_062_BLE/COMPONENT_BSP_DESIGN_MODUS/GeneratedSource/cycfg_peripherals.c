/*******************************************************************************
* File Name: cycfg_peripherals.c
*
* Description:
* Peripheral Hardware Block configuration
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#include "cycfg_peripherals.h"

#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_BLE_obj = 
	{
		.type = CYHAL_RSC_BLESS,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
cy_stc_csd_context_t cy_csd_0_context = 
{
	.lockKey = CY_CSD_NONE_KEY,
};
const cy_stc_scb_ezi2c_config_t CYBSP_CSD_COMM_config = 
{
	.numberOfAddresses = CY_SCB_EZI2C_ONE_ADDRESS,
	.slaveAddress1 = 8U,
	.slaveAddress2 = 0U,
	.subAddressSize = CY_SCB_EZI2C_SUB_ADDR16_BITS,
	.enableWakeFromSleep = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_CSD_COMM_obj = 
	{
		.type = CYHAL_RSC_SCB,
		.block_num = 3U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_smif_config_t CYBSP_QSPI_config = 
{
	.mode = (uint32_t)CY_SMIF_NORMAL,
	.deselectDelay = CYBSP_QSPI_DESELECT_DELAY,
	.rxClockSel = (uint32_t)CY_SMIF_SEL_INV_INTERNAL_CLK,
	.blockEvent = (uint32_t)CY_SMIF_BUS_ERROR,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_QSPI_obj = 
	{
		.type = CYHAL_RSC_SMIF,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_mcwdt_config_t CYBSP_MCWDT0_config = 
{
	.c0Match = 32768U,
	.c1Match = 32768U,
	.c0Mode = CY_MCWDT_MODE_NONE,
	.c1Mode = CY_MCWDT_MODE_NONE,
	.c2ToggleBit = 16U,
	.c2Mode = CY_MCWDT_MODE_NONE,
	.c0ClearOnMatch = false,
	.c1ClearOnMatch = false,
	.c0c1Cascade = true,
	.c1c2Cascade = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_MCWDT0_obj = 
	{
		.type = CYHAL_RSC_LPTIMER,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_rtc_config_t CYBSP_RTC_config = 
{
	.sec = 0U,
	.min = 0U,
	.hour = 12U,
	.amPm = CY_RTC_AM,
	.hrFormat = CY_RTC_24_HOURS,
	.dayOfWeek = CY_RTC_SUNDAY,
	.date = 1U,
	.month = CY_RTC_JANUARY,
	.year = 0U,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_RTC_obj = 
	{
		.type = CYHAL_RSC_RTC,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
		cyhal_hwmgr_reserve(&CYBSP_BLE_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_CSD_CLOCK, CY_SYSCLK_DIV_8_BIT, 0U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB3_CLOCK, CY_SYSCLK_DIV_8_BIT, 1U);
#if defined (CY_USING_HAL)
		cyhal_hwmgr_reserve(&CYBSP_CSD_COMM_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
		cyhal_hwmgr_reserve(&CYBSP_QSPI_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
		cyhal_hwmgr_reserve(&CYBSP_MCWDT0_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
		cyhal_hwmgr_reserve(&CYBSP_RTC_obj);
#endif //defined (CY_USING_HAL)
}
