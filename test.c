/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 main.c												:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/03/31 16:58:07 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/05/09 16:01:35 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "caps.h"
#include "types.h"


#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <termcap.h>

# define KEY_ESC		0x1b
# define KEY_BS			0x7f
# define KEY_ENTER		0x0b

# define INPUT_BUFFER_SIZE_MAX	7

static bool minishell__read_input(int fd)
{
	size_t			input_buffer_size;
	char			input_buffer[INPUT_BUFFER_SIZE_MAX];

	if (!isatty(fd))
	{
		log_fatal("isatty() failed fd %d", fd);
		return 0;
	}

	while (1)
	{
		input_buffer_size = read(fd, input_buffer, sizeof (input_buffer));
		input_buffer[input_buffer_size] = 0;

		log_debug("key: (size: %zu) %s\r", input_buffer_size, caps__keycode_dump(input_buffer_size, input_buffer));

		if (input_buffer[0] == KEY_ESC || input_buffer[0] == KEY_BS ||
			(input_buffer_size == 1 && input_buffer[0] < 27))
			caps__keycode_find(input_buffer_size, input_buffer);
		else
		{
			/* save command line */
		}

		if (input_buffer[0] == 'q')
			break ;
	}

	return (TRUE);
}

static bool minishell__termios_raw(int fd)
{
	struct termios			termios_old;
	struct termios			termios_new;

	if (!isatty(fd))
	{
		log_fatal("We're not reading on a tty fd %d", fd);
		return 0;
	}

	/* get the current termios structure */
	if (tcgetattr(0, &termios_old) != 0)
	{
		log_fatal("tcgetattr() failed fd_old %d", fd);
		return 0;
	}

	termios_new = termios_old;

	/* POSIX raw */
	termios_new.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
							 | INLCR | IGNCR | ICRNL | IXON);
	termios_new.c_oflag &= ~OPOST;
	termios_new.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	termios_new.c_cflag &= ~(CSIZE | PARENB);
	termios_new.c_cflag |= CS8;

	/* set terminal in raw mode */
	if (tcsetattr(fd, TCSAFLUSH, &termios_new) != 0)
	{
		log_fatal("tcsetattr() failed to initialize %s", "");
		return 0;
	}

	if (!minishell__read_input(fd))
	{
		log_error("minishell__read_input() failed %s", "");

		/* set terminal back to normal */
		if (tcsetattr(fd, TCSADRAIN, &termios_old) != 0)
			log_error("tcsetattr() failed t finalize %s", "");

		return (FALSE);
	}

	/* set terminal back to normal */
	if (tcsetattr(fd, TCSADRAIN, &termios_old) != 0)
	{
		log_fatal("tcsetattr() failed t finalize %s", "");
		return 0;
	}

	return (TRUE);
}

# define TTY_DEVICE "/dev/tty"

static bool minishell__device_open(void)
{
	int		fd;

	/* open a tty */
	fd = open(TTY_DEVICE, O_RDONLY);
	if (fd == -1)
	{
		log_fatal("open() failed on %s", TTY_DEVICE);
		return 0;
	}

	log_debug("our program read and write on %s fd %d", TTY_DEVICE, fd);

	if (!minishell__termios_raw(fd))
	{
		log_error("minishell__termios_init() failed %s", "");

		if (close(fd))
			log_error("close() failed on %s", TTY_DEVICE);
		return (FALSE);
	}

	if (close(fd))
	{
		log_fatal("close() failed on %s", TTY_DEVICE);
		return 0;
	}

	return (TRUE);
}

#define ASSERT(expr) if (!expr) {log_fatal("(%s) failed", #expr); return 0;}

static bool minishell__initialize_key_map(void)
{
	return (TRUE);
}

int main()
{
	if (!caps__initialize(1))
	{
		log_error("caps_initialize() failed %s", "");
		return (1);
	}

	if (!minishell__initialize_key_map())
	{
		log_error("minishell__initialize_key_map() failed %s", "");
		return (1);
	}

	if (!minishell__device_open())
	{
		log_error("minishell__raw_mode() failed %s", "");
		return (1);
	}

	if (!caps__finalize())
	{
		log_error("caps_finalize() failed %s", "");
		return (1);
	}

	return (0);
}
