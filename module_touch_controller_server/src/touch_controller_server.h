#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

#include "touch_controller_impl.h"

#define DELAY 100000000		// corresponds to 1 sec for 100MHz timer


enum commands {
	NEXT_TOUCH_CMD = 1,
	LAST_TOUCH_CMD = 2,
	LAST_TOUCH_TIMED_CMD = 3
};

typedef enum{FALSE,TRUE} t_status;


/** \brief The touch controller server function.
 *
 * \param c_server The channel connecting the client API and the server.
 * \param ports The structure containing the touch controller port details.
 */
void touch_controller_server(chanend c_server, touchController_ports &ports);

/** \brief The function that processes the pen-down interrupt generated by touching the screen.
 * 
 * \param ports The structure containing the touch controller port details.
 * \param presentTimeSec The current time in seconds relative to the call of touch controller server function.
 * \param touched The flag that records the touch status.
 * \param x The X coordinate value.
 * \param y The Y coordinate value.
 * \param touchTime The time of touch in seconds relative to the call of touch controller server function.
 */
select process_interrupt(touchController_ports &ports, unsigned presentTimeSec, t_status &touched, unsigned &x, unsigned &y, unsigned &touchTime);

/** \brief The function to get the last touch coordinates from the touch controller server function. 
 * \param c_ts The channel connecting this client API and the server.
 * \param x The X coordinate value.
 * \param y The Y coordinate value.
 */
t_status touch_server_get_last_coord(chanend c_ts, unsigned &x, unsigned &y);

/** \brief The function to get the next touch coordinates from the touch controller server function.
 * \param c_ts The channel connecting this client API and the server.
 * \param x The X coordinate value.
 * \param y The Y coordinate value.
 */
void touch_server_get_next_coord(chanend c_ts, unsigned &x, unsigned &y);

/** \brief The function to get the last touch coordinates from the touch controller server function. The time elapsed from the last touch event is also computed.
 * \param c_ts The channel connecting this client API and the server.
 * \param t The time elapsed from the last touch event in seconds.
 * \param x The X coordinate value.
 * \param y The Y coordinate value.
 */
t_status touch_server_get_last_coord_timed(chanend c_ts, unsigned &t, unsigned &x, unsigned &y);

/** \brief The function to scale coordinate values (from the touch point coordinates to the LCD pixel coordinates)
 *
 * \param x The X coordinate value
 * \param y The Y coordinate value
 */
void scale_coords(unsigned &x, unsigned &y);


#endif /* TOUCHSCREEN_H_ */