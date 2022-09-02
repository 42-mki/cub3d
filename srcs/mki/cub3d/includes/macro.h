/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:16:45 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 16:14:48 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*
**	get_next_line BUFFER_SIZE
*/

# define BUFFER_SIZE			100

/*
**	X11 Event
*/

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

/*
**	Apple's key code
*/

# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_ESC				53
# define ARROW_L				123
# define ARROW_R				124

/*
**	Color Value
*/

# define RED					0xFF0000
# define GREEN					0x00FF00
# define BLUE					0x0000FF
# define WHITE					0xFFFFFF

/*
**	Setting
*/

# define MOVE_SPEED				0.5
# define ROTATE_SPEED			5
# define TEX_WIDTH				64
# define TEX_HEIGHT				64
# define RIGHT					0
# define LEFT					1
# define UP						2
# define DOWN					3

#endif
