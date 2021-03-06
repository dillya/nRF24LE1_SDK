////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_pin_configure.c
//
// Copyright Aleksandr Svalov (Alarus), 2014
//
// The author provides no guarantees, warantees, or promises, implied or
// otherwise.  By using this software you agree to indemnify the author
// of any damages incurred by using it.
//
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
////////////////////////////////////////////////////////////////////////////////////

#include "owi.h"


////////////////////////////////////////////////////////////////////////////////////
//
// void owi_pin_configure(gpio_pin_id_t owi_pin_id)
//
// Description:
//  Configures the OWI pin
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin to be configured
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////////
void owi_pin_configure(gpio_pin_id_t owi_pin_id)
{
	gpio_pin_configure(owi_pin_id, GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT | GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_CLEAR | GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_NORMAL_DRIVE_STRENGTH);
	gpio_pin_configure(owi_pin_id, GPIO_PIN_CONFIG_OPTION_DIR_INPUT | GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_PULL_UP_RESISTOR);
	// The first rising edge can be interpreted by a slave as the end of a reset pulse.
	// Delay for the required reset recovery time (H) to be sure that the real reset is interpreted correctly.
	delay_us(OWI_DELAY_H);
}
