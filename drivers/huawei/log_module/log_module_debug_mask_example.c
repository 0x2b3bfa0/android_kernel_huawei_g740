/*
 * log_module_debug_mask_example.c
 * just example code
 *
 */

#include <linux/log_module.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

/* this module don't contain native module log system, we just control the debug mask */

static int log_module_example_debug_mask;
module_param(log_module_example_debug_mask, int, S_IRUGO | S_IWUSR | S_IWGRP);

int log_module_example_debug_mask_config(void * value)
{
    printk("mask altered from [%d]\n", log_module_example_debug_mask);
    log_module_example_debug_mask = (int)*(int*)value;

    return log_module_example_debug_mask;
}

static struct hw_device_debug new_module_example ={
    .device_name = "debug_mask_example",
    .category = HW_DEVICE_MODULE_LCD, /* LCD is one example */
    .debug_mask_config = log_module_example_debug_mask_config,
    .log_level = HW_DEVICE_DEBUG_LEVEL_NONE,
};

extern int register_log_module(struct hw_device_debug * new_module);
extern void unregister_log_module(struct hw_device_debug *new_module);

static int __init hw_debug_log_init_module_example(void)
{
    log_module_example_debug_mask = HW_DEVICE_DEBUG_LEVEL_NONE;
    register_log_module(&new_module_example);
    return 0;
}

static void __exit hw_debug_log_exit_module_example(void)
{
    unregister_log_module(&new_module_example);
}

module_init(hw_debug_log_init_module_example);
module_exit(hw_debug_log_exit_module_example);

MODULE_DESCRIPTION("Huawei log control module example");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Guo Yun <yun.guo@huawei.com>");
MODULE_VERSION("1.0");

