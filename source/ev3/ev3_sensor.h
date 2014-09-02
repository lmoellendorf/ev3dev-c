
/*  ev3_sensor.h was generated by yup.py (yupp) 0.7b4
    out of ev3_sensor.yu-h at 2014-09-02 18:23
 *//**
 *  \file  ev3_sensor.h (ev3_sensor.yu-h)
 *  \brief  ev3dev sensors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  The MIT License
 */

#ifndef EV3_SENSOR_H
#define EV3_SENSOR_H

#ifdef  EV3_SENSOR_IMPLEMENT
#define EV3_SENSOR_EXT
#define EV3_SENSOR_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_SENSOR_EXT extern
#define EV3_SENSOR_EXT_INIT( dec, init ) \
	extern dec
#endif

#ifndef COMMA
#define COMMA   ,
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \addtogroup ev3dev
 *  \{
 */

enum {
	IN1,
	IN2,
	IN3,
	IN4,

	IN__COUNT_
};

EV3_SENSOR_EXT struct {
	bool     detected;
	uint32_t id;
	uint32_t type_id;

} ev3_sensor[ IN__COUNT_ ];

enum {
	EV3_TOUCH = 16,
	EV3_COLOR = 29,
	EV3_ULTRASONIC = 30,
	EV3_GYRO = 32,
	EV3_INFRARED = 33,

};

EV3_SENSOR_EXT size_t get_sensor_bin_data( uint8_t id, byte *buf, size_t sz );
EV3_SENSOR_EXT size_t set_sensor_bin_data( uint8_t id, byte *value, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_bin_data_format( uint8_t id, char *buf, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_dp( uint8_t id, dword *buf );

EV3_SENSOR_EXT size_t get_sensor_fw_version( uint8_t id, char *buf, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_i2c_addr( uint8_t id, int *buf );

EV3_SENSOR_EXT size_t get_sensor_mode( uint8_t id, char *buf, size_t sz );
EV3_SENSOR_EXT size_t set_sensor_mode( uint8_t id, char *value );

EV3_SENSOR_EXT size_t get_sensor_modes( uint8_t id, char *buf, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_num_values( uint8_t id, dword *buf );

EV3_SENSOR_EXT size_t get_sensor_poll_ms( uint8_t id, dword *buf );
EV3_SENSOR_EXT size_t set_sensor_poll_ms( uint8_t id, dword value );

EV3_SENSOR_EXT size_t get_sensor_port_name( uint8_t id, char *buf, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_units( uint8_t id, char *buf, size_t sz );

EV3_SENSOR_EXT size_t get_sensor_type_id( uint8_t id, dword *buf );

EV3_SENSOR_EXT size_t get_sensor_value0( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value1( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value2( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value3( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value4( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value5( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value6( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value7( uint8_t id, float *buf );

EV3_SENSOR_EXT size_t get_sensor_value( uint8_t ind, uint8_t id, int *buf );

EV3_SENSOR_EXT char *get_sensor_type_id_string( uint8_t type_id );

EV3_SENSOR_EXT int search_sensor_port( uint8_t type_id );

EV3_SENSOR_EXT int ev3_sensor_init( void );

/** \} */

#ifdef __cplusplus
}
#endif

#endif
