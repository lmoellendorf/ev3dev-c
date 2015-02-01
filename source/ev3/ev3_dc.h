
/*  ev3_dc.h was generated by yup.py (yupp) 0.7b7
    out of ev3_dc.yu-h at 2015-02-01 14:51
 *//**
 *  \file  ev3_dc.h (ev3_dc.yu-h)
 *  \brief  EV3 DC Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_DC_H
#define EV3_DC_H

#ifdef  EV3_DC_IMPLEMENT
#define EV3_DC_EXT
#define EV3_DC_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_DC_EXT extern
#define EV3_DC_EXT_INIT( dec, init ) \
	extern dec
#endif

#ifndef COMMA
#define COMMA   ,
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \defgroup ev3_dc DC Motors
 *  \brief Access to EV3 DC Motors.
 *  \see http://www.ev3dev.org/docs/motors/
 *  \see http://www.ev3dev.org/docs/drivers/dc-motor-class/
 *  \{
 */

#define DC_DIR  "/sys/class/dc-motor"  /**< Directory of DC motors. */

/**
 *  \brief Structure of a DC motor descriptor.
 */
typedef struct {
	uint8_t type_inx;  /**< DC motor type. */
	uint8_t port;  /**< DC motor EV3 port. */
	uint8_t extport;  /**< DC motor extended port. */

} EV3_DC;

#define DC_DESC__LIMIT_  64  /**< Limit of DC motor descriptors. */

#define DC__NONE_  DC_DESC__LIMIT_  /**< DC motor is not found. */

/**
 *  \brief Vector of DC motor descriptors (filled by \ref ev3_dc_init).
 */
EV3_DC_EXT EV3_DC ev3_dc[ DC_DESC__LIMIT_ ];

/**
 *  \brief Types of DC motors.
 */
enum {
	DC_TYPE__NONE_ = 0,

	RCX_MOTOR,

	DC_TYPE__COUNT_
};

/**
 *  \brief Get "command" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_command( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "command" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_command( uint8_t sn, char *value );

/**
 *  \brief Get "commands" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_commands( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "driver_name" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "duty_cycle" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_duty_cycle( uint8_t sn, int *buf );

/**
 *  \brief Get "duty_cycle_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_duty_cycle_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "duty_cycle_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_duty_cycle_sp( uint8_t sn, int value );

/**
 *  \brief Get "polarity" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "polarity" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_polarity( uint8_t sn, char *value );

/**
 *  \brief Get "port_name" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_port_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "ramp_down_ms" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_ramp_down_ms( uint8_t sn, dword *buf );

/**
 *  \brief Set "ramp_down_ms" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_ramp_down_ms( uint8_t sn, dword value );

/**
 *  \brief Get "ramp_up_ms" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_ramp_up_ms( uint8_t sn, dword *buf );

/**
 *  \brief Set "ramp_up_ms" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_ramp_up_ms( uint8_t sn, dword value );

/**
 *  \brief Get name of the specified DC motor type.
 *  \param type_inx The DC motor type.
 *  \return Requested value.
 */
EV3_DC_EXT const char *ev3_dc_type( uint8_t type_inx );

/**
 *  \brief Get index of the DC motor type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t get_dc_type_inx( uint8_t sn );

/**
 *  \brief Get indexes of the EV3 port and the extended port of the DC motor.
 *  \param sn Sequence number.
 *  \param extport Buffer for the extended port index.
 *  \return EV3 port index.
 */
EV3_DC_EXT uint8_t get_dc_port_inx( uint8_t sn, uint8_t *extport );

/**
 *  \brief Get descriptor of the DC motor.
 *  \param sn Sequence number.
 *  \return Pointer to the DC motor descriptor.
 */
EV3_DC_EXT EV3_DC *ev3_dc_desc( uint8_t sn );

/**
 *  \brief Get type from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t ev3_dc_desc_type_inx( uint8_t sn );
/**
 *  \brief Get EV3 port from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t ev3_dc_desc_port( uint8_t sn );
/**
 *  \brief Get extended port from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t ev3_dc_desc_extport( uint8_t sn );

/**
 *  \brief Search of a sequence number of the specified DC motor type.
 *  \param type_inx The DC motor type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the DC motor is found.
 */
EV3_DC_EXT bool ev3_search_dc( uint8_t type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the DC motor by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.

 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the DC motor is found.
 */
EV3_DC_EXT bool ev3_search_dc_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Detect connected DC motors.
 *  \return The number of found DC motors or -1 in case of an error.
 */
EV3_DC_EXT int ev3_dc_init( void );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

