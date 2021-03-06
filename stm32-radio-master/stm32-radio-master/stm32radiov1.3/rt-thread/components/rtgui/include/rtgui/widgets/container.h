/*
 * File      : container.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-10-16     Bernard      first version
 */
#ifndef __RTGUI_CONTAINER_H__
#define __RTGUI_CONTAINER_H__

#include <rtgui/widgets/widget.h>

/** Gets the type of a container */
#define RTGUI_CONTAINER_TYPE       (rtgui_container_type_get())
/** Casts the object to a rtgui_container */
#define RTGUI_CONTAINER(obj)       (RTGUI_OBJECT_CAST((obj), RTGUI_CONTAINER_TYPE, rtgui_container_t))
/** Checks if the object is a rtgui_container */
#define RTGUI_IS_CONTAINER(obj)    (RTGUI_OBJECT_CHECK_TYPE((obj), RTGUI_CONTAINER_TYPE))

struct rtgui_container
{
	/* inherit from widget */
	struct rtgui_widget parent;

	struct rtgui_widget* focused;
	rtgui_list_t children;
};
typedef struct rtgui_container rtgui_container_t;

rtgui_type_t *rtgui_container_type_get(void);

void rtgui_container_add_child(rtgui_container_t *container, rtgui_widget_t* child);
void rtgui_container_remove_child(rtgui_container_t *container, rtgui_widget_t* child);
void rtgui_container_destroy_children(rtgui_container_t *container);
rtgui_widget_t* rtgui_container_get_first_child(rtgui_container_t* container);

rt_bool_t rtgui_container_event_handler(rtgui_widget_t* widget, rtgui_event_t* event);

rt_bool_t rtgui_container_dispatch_event(rtgui_container_t *container, rtgui_event_t* event);
rt_bool_t rtgui_container_dispatch_mouse_event(rtgui_container_t *container, struct rtgui_event_mouse* event);

#endif
