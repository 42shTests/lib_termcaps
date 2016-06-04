#ifndef CAPS_H
# define CAPS_H

# include "types.h"
# include <unistd.h>
# include "logger.h"

# define CAPS__TERMTYPE getenv("TERM")
//# define CAPS__TERMTYPE "ansi"

/*
** caps print
*/
int				caps__print (const char *s, size_t line_count);

/*
** caps print cap
*/
typedef enum		e_caps_cap
{
	CAPS__RIGHT,
	CAPS__LEFT,
	CAPS__UP,
	CAPS__DOWN,
	CAPS__DELETE,
	CAPS__CLEAR_TO_END_OF_LINE,
	CAPS__CLEAR_TO_END_OF_SCREEN,
	CAPS__CARRIAGE_RETURN,
	CAPS__ENDLINE,
	CAPS__BACKSPACE
}					t_caps_cap;

void				caps__print_cap(const t_caps_cap value, int lines);

/*
** caps delete line
*/
void	caps__delete_line(const size_t line_offset);

/*
** caps cursor to offset
*/
void	caps__cursor_to_offset(const size_t to_offset, const size_t current_offset);

/*
** caps get cursor x y
*/
bool	caps__cursor_getxy(int *x, int *y);

/*
** caps put cursor
*/
bool	caps__cursor_setxy(int x, int y);

/*
** caps win: return the count of column or line
*/
# define WIN_COLUMNS					"co"
# define WIN_LINE					"li"

size_t				caps__win (const char *cmd);

/*
** caps tcapcodes
*/
# define KEYPAD_UPPER_LEFT_KEY				"K1"
# define KEYPAD_CENTER_KEY				"K2"
# define KEYPAD_UPPER_RIGHT_KEY				"K3"
# define KEYPAD_BOTTOM_LEFT_KEY				"K4"
# define KEYPAD_BOTTOM_RIGHT_KEY			"K5"
# define FUNCTION_KEY_0					"k0"
# define FUNCTION_KEY_1					"k1"
# define FUNCTION_KEY_2					"k2"
# define FUNCTION_KEY_3					"k3"
# define FUNCTION_KEY_4					"k4"
# define FUNCTION_KEY_5					"k5"
# define FUNCTION_KEY_6					"k6"
# define FUNCTION_KEY_7					"k7"
# define FUNCTION_KEY_8					"k8"
# define FUNCTION_KEY_9					"k9"
# define FUNCTION_KEY_10				"k:"
# define CURSOR_HOME_KEY				"kh"
# define CURSOR_HOME_DOWN_KEY				"kH"
# define CURSOR_LEFT_KEY				"kl"
# define CURSOR_RIGHT_KEY				"kr"
# define CURSOR_UP_KEY					"ku"
# define CURSOR_DOWN_KEY				"kd"
# define PREVIOUS_PAGE_KEY				"kP"
# define NEXT_PAGE_KEY					"kN"
# define BACKSPACE_KEY					"kb"
# define DELETE_UNDER_CURSOR_KEY			"kD"
# define INSERT_MODE_KEY				"kI"
# define EXIT_INSERT_MODE_KEY				"kM"
# define KEYPAD_ON_KEY					"ks"
# define KEYPAD_OFF_KEY					"ke"
# define CLEAR_ALL_TABS_KEY				"ka"
# define CLEAR_THIS_TAB_KEY				"kt"
# define CLEAR_SCREEN_KEY				"kC"
# define CLEAR_TO_END_OF_SCREEN_KEY			"kS"
# define CLEAR_TO_END_OF_LINE_KEY			"kE"
# define INSERT_LINE_KEY				"kA"
# define DELETE_LINE_KEY				"kL"
# define SET_TAB_HERE_KEY				"kT"
# define BACK_TAB_KEY					"kB"
# define SHIFTED_CURSOR_LEFT_KEY			"#4"
# define SHIFTED_CURSOR_RIGHT_KEY			"%i"
# define SCROLLING_FORWARD_KEY				"kF"
# define SCROLLING_BACKWARD_KEY				"kR"
# define BEGIN_KEY					"@1"
# define END_KEY					"@7"
# define MARK_KEY					"%2"
# define SELECT_KEY					"*6"
# define COPY_KEY					"@5"
# define ENTER_KEY					"@8"
# define EXIT_KEY					"@9"
# define SUSPEND_KEY					"&7"
# define RESUME_KEY					"&5"
# define RESTART_KEY					"&4"
# define REFRESH_KEY					"&2"
# define REDO_KEY					"%0"
# define CANCEL_KEY					"@2"

/*
** caps init func: initialize function from tcapcode
*/
bool				caps__init_func (const char *in_tcapcode, int (*in_func)());

/*
** caps meta keycodes
*/

# define CAPS__KEYCODE_CTRL_SPACE			("\x00")
# define CAPS__KEYCODE_CTRL_A				("\x01")
# define CAPS__KEYCODE_CTRL_B				("\x02")
# define CAPS__KEYCODE_CTRL_C				("\x03")
# define CAPS__KEYCODE_CTRL_D				("\x04")
# define CAPS__KEYCODE_CTRL_E				("\x05")
# define CAPS__KEYCODE_CTRL_F				("\x06")
# define CAPS__KEYCODE_CTRL_G				("\x07")
# define CAPS__KEYCODE_CTRL_H				("\x08")
# define CAPS__KEYCODE_CTRL_I				("\x09")
# define CAPS__KEYCODE_CTRL_J				("\x0a")
# define CAPS__KEYCODE_CTRL_K				("\x0b")
# define CAPS__KEYCODE_CTRL_L				("\x0c")
# define CAPS__KEYCODE_CTRL_M				("\x0d")
# define CAPS__KEYCODE_CTRL_N				("\x0e")
# define CAPS__KEYCODE_CTRL_O				("\x0f")
# define CAPS__KEYCODE_CTRL_P				("\x10")
# define CAPS__KEYCODE_CTRL_Q				("\x11")
# define CAPS__KEYCODE_CTRL_R				("\x12")
# define CAPS__KEYCODE_CTRL_S				("\x13")
# define CAPS__KEYCODE_CTRL_T				("\x14")
# define CAPS__KEYCODE_CTRL_U				("\x15")
# define CAPS__KEYCODE_CTRL_V				("\x16")
# define CAPS__KEYCODE_CTRL_W				("\x17")
# define CAPS__KEYCODE_CTRL_X				("\x18")
# define CAPS__KEYCODE_CTRL_Y				("\x19")
# define CAPS__KEYCODE_CTRL_Z				("\x1a")
# define CAPS__KEYCODE_CTRL_CURSOR_LEFT			("\x1b\x5b\x31\x3b\x35\x44")
# define CAPS__KEYCODE_CTRL_CURSOR_RIGHT		("\x1b\x5b\x31\x3b\x35\x43")
# define CAPS__KEYCODE_CTRL_CURSOR_UP			("\x1b\x5b\x31\x3b\x35\x41")
# define CAPS__KEYCODE_CTRL_CURSOR_DOWN			("\x1b\x5b\x31\x3b\x35\x42")
# define CAPS__KEYCODE_BACKSPACE			("\x7f")
# define CAPS__KEYCODE_ESCAPE				("\x1b")

/*
** caps init func: initialize function from keycode
*/
bool				caps__init_func_by_keycode (const char *keycode, int (*in_func)());

/*
** caps keycode dump
*/
char				*caps__keycode_dump (const size_t keycode_size, const char *keycode);

/*
** caps keycode cmp
*/
int				caps__keycode_cmp (const t_buffer keycode1, const t_buffer keycode2);

/*
** caps keycode find
*/
bool			caps__keycode_find (const size_t keycode_size, const char *keycode);

/*
** caps execute function
*/
bool				caps__exec_func (const size_t keycode_size, const char *keycode, void *in_context);

/*
** caps initialize / finalize
*/
bool				caps__initialize (void);
bool				caps__finalize (void);

#endif
