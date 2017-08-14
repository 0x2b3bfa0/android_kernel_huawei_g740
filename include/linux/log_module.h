/*
 * log_module.h
 *
 * provide interface to other module to enable/disable log system.
 *
 */

#ifndef __LOG_MODULE_H
#define __LOG_MODULE_H

#include <linux/list.h>

typedef int (*debug_mask_config)(void * value);

typedef int (*dynamic_debug_config)(void * value);

 /* log level
  * 1, follow the kernel log level
  * 2, add reg and key level to do some special log
  * 3, NONE means no log output
  */
typedef enum _device_log_level{
    HW_DEVICE_DEBUG_LEVEL_NONE = 0, 
    HW_DEVICE_DEBUG_LEVEL_EMERG = 1, 
    HW_DEVICE_DEBUG_LEVEL_ALERT = 2,  
    HW_DEVICE_DEBUG_LEVEL_CRIT = 3,  
    HW_DEVICE_DEBUG_LEVEL_ERR = 4,    
    HW_DEVICE_DEBUG_LEVEL_WARNING = 5,
    HW_DEVICE_DEBUG_LEVEL_NOTICE = 6,
    HW_DEVICE_DEBUG_LEVEL_INFO = 7,
    HW_DEVICE_DEBUG_LEVEL_DEBUG = 8,
    HW_DEVICE_DEBUG_LEVEL_REG = 9,
    HW_DEVICE_DEBUG_LEVEL_KEY = 10,  /* seldom use,depends on useage */
    HW_DEVICE_DEBUG_LEVEL_ALL,
}device_log_level;

/* module category */
typedef enum _module_category{
    HW_DEVICE_MODULE_INVALID,
    HW_DEVICE_MODULE_LCD,
    HW_DEVICE_MODULE_CAMERA,
    HW_DEVICE_MODULE_TP,
    HW_DEVICE_MODULE_SENSOR,
    HW_DEVICE_MODULE_LED,
    HW_DEVICE_MODULE_KEYPAD,
    HW_DEVICE_MODULE_BT,
    HW_DEVICE_MODULE_WIFI,
    HW_DEVICE_MODULE_NFC,
    HW_DEVICE_MODULE_ALL
} module_category;

#define MAX_MODULE_NAME_LEN 32

struct hw_device_debug{
    struct list_head list;
    device_log_level  log_level;
    char device_name[MAX_MODULE_NAME_LEN]; /* driver don't provide space to save name */
    module_category category;    /* module category */
    long id_num;    /* to diff from dynamic module which has same device_name */
    debug_mask_config debug_mask_config;
    dynamic_debug_config dynamic_debug_config;
};

#define LOG_MODULE_PRIVATE_BASE 0x8888
#define LOG_M_SET_DEVICE_LOG   _IOW(LOG_MODULE_PRIVATE_BASE, 1, struct hw_device_debug *)
#define LOG_M_GET_MODULE_NUM    _IOR(LOG_MODULE_PRIVATE_BASE, 2, int)
#define LOG_M_GET_MODULE    _IOWR(LOG_MODULE_PRIVATE_BASE, 3,  struct hw_device_debug *)

#endif

