
/*  ev3_dc.c was generated by yup.py (yupp) 0.7b7
    out of ev3_dc.yu-c at 2015-02-01 14:52
 *//**
 *  \file  ev3_dc.c (ev3_dc.yu-c)
 *  \brief  EV3 DC Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_DC_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_dc.h"

#define PATH_PREF_LEN  25
#define _ID_SPOT  "///"

#define PATH_COMMAND  "/sys/class/dc-motor/motor" _ID_SPOT "command"
#define PATH_COMMANDS  "/sys/class/dc-motor/motor" _ID_SPOT "commands"
#define PATH_DRIVER_NAME  "/sys/class/dc-motor/motor" _ID_SPOT "driver_name"
#define PATH_DUTY_CYCLE  "/sys/class/dc-motor/motor" _ID_SPOT "duty_cycle"
#define PATH_DUTY_CYCLE_SP  "/sys/class/dc-motor/motor" _ID_SPOT "duty_cycle_sp"
#define PATH_POLARITY  "/sys/class/dc-motor/motor" _ID_SPOT "polarity"
#define PATH_PORT_NAME  "/sys/class/dc-motor/motor" _ID_SPOT "port_name"
#define PATH_RAMP_DOWN_MS  "/sys/class/dc-motor/motor" _ID_SPOT "ramp_down_ms"
#define PATH_RAMP_UP_MS  "/sys/class/dc-motor/motor" _ID_SPOT "ramp_up_ms"

size_t get_dc_command( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_dc_command( uint8_t sn, char *value )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_dc_commands( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_COMMANDS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_dc_driver_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_DRIVER_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_dc_duty_cycle( uint8_t sn, int *buf )
{
	char s[] = PATH_DUTY_CYCLE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t get_dc_duty_cycle_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_DUTY_CYCLE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_dc_duty_cycle_sp( uint8_t sn, int value )
{
	char s[] = PATH_DUTY_CYCLE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_dc_polarity( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_POLARITY;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_dc_polarity( uint8_t sn, char *value )
{
	char s[] = PATH_POLARITY;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_dc_port_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_PORT_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_dc_ramp_down_ms( uint8_t sn, dword *buf )
{
	char s[] = PATH_RAMP_DOWN_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t set_dc_ramp_down_ms( uint8_t sn, dword value )
{
	char s[] = PATH_RAMP_DOWN_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_dword( s, value );
}

size_t get_dc_ramp_up_ms( uint8_t sn, dword *buf )
{
	char s[] = PATH_RAMP_UP_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t set_dc_ramp_up_ms( uint8_t sn, dword value )
{
	char s[] = PATH_RAMP_UP_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_dword( s, value );
}

const char *ev3_dc_type( uint8_t type_inx )
{
	switch ( type_inx ) {
	case RCX_MOTOR:
		return "rcx-motor";

	}
	return ( STR_unknown_ );
}

uint8_t get_dc_type_inx( uint8_t sn )
{
	char buf[ 64 ];

	if ( !get_dc_driver_name( sn, buf, sizeof( buf ))) return ( DC_TYPE__NONE_ );

	if ( strcmp( buf, "rcx-motor" ) == 0 ) return RCX_MOTOR;

	return ( DC_TYPE__COUNT_ );
}

uint8_t get_dc_port_inx( uint8_t sn, uint8_t *extport )
{
	char buf[ 32 ];

	if ( !get_dc_port_name( sn, buf, sizeof( buf ))) return ( EV3_PORT__NONE_ );

	return ( ev3_port_inx( buf, extport ));
}

EV3_DC *ev3_dc_desc( uint8_t sn )
{
	if ( sn >= DC_DESC__LIMIT_) sn = DC_DESC__LIMIT_ - 1;
	return ( ev3_dc + sn );
}

uint8_t ev3_dc_desc_type_inx( uint8_t sn )
{
	return ( ev3_dc_desc( sn )->type_inx );
}

uint8_t ev3_dc_desc_port( uint8_t sn )
{
	return ( ev3_dc_desc( sn )->port );
}

uint8_t ev3_dc_desc_extport( uint8_t sn )
{
	return ( ev3_dc_desc( sn )->extport );
}

bool ev3_search_dc( uint8_t type_inx, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < DC_DESC__LIMIT_) {
		if ( ev3_dc[ _sn ].type_inx == type_inx ) {
			*sn = _sn;
			return ( true );
		}
		++_sn;
	}
	*sn = DC__NONE_;
	return ( false );
}

bool ev3_search_dc_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < DC_DESC__LIMIT_) {
		if ( ev3_dc[ _sn ].port == port ) {

			if ( extport ) {
				if ( ev3_dc[ _sn ].extport == extport ) {
						*sn = _sn;
						return ( true );
					}
			}
			else {
				*sn = _sn;
				return ( true );
			}
		}
		++_sn;
	}
	*sn = DC__NONE_;
	return ( false );
}

int ev3_dc_init( void )
{
	char list[ 256 ];
	char *p;
	uint32_t sn;
	int cnt = 0;

	memset( ev3_dc, 0, sizeof( ev3_dc ));

	if ( !ev3_listdir( "/sys/class/dc-motor", list, sizeof( list ))) return ( -1 );

	p = strtok( list, " " );
	while ( p ) {
		if (( ev3_string_suffix( "motor", &p, &sn ) == 1 ) && ( sn < DC_DESC__LIMIT_)) {

			ev3_dc[ sn ].type_inx = get_dc_type_inx( sn );
			ev3_dc[ sn ].port = get_dc_port_inx( sn, &ev3_dc[ sn ].extport );
			++cnt;
		}
		p = strtok( NULL, " " );
	}
	return ( cnt );
}

