#ifndef TheRequirements_H
#define TheRequirements_H
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
 //Sad wee can't do WTFPL
#define Layer0Setup(description,layer) \
    MODULE_DESCRIPTION(description); \
    MODULE_LICENSE("GPL"); \
    MODULE_AUTHOR("We-Make-Software.Com"); \
    static int __init SetupInitProject(void) { \
        Layer0Start(); \
        printk(KERN_INFO "%s: Start\nTimestamp: %llu\n", description, ktime_get_real_seconds()); \
        return 0; \
    } \
    static void __exit SetupExitProject(void) { \
        Layer0End(); \
        printk(KERN_INFO "%s: End\nTimestamp: %llu\n", description, ktime_get_real_seconds()); \
    } \
    module_init(SetupInitProject); \
    module_exit(SetupExitProject);
#endif