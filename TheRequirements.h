#ifndef TheRequirements_H
#define TheRequirements_H
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h> 
//Sad wee can't do WTFPL
 //https://github.com/we-make-software/TheRequirements?tab=License-1-ov-file
 //Damm!! you GPL!!
#define Layer0Setup(description,version,build) \
    MODULE_DESCRIPTION(description "\version: " #version "\build:" #build); \
    MODULE_LICENSE("GPL"); \
    MODULE_AUTHOR("We-Make-Software.Com"); \
    static int __init SetupInitProject(void) { \
        Layer0Start(); \
        printk(KERN_INFO "%s: Start\nVersion: %s\nBuild: %s\nTimestamp: %llu\n", description, #version, #build, ktime_get_real_seconds()); \
        return 0; \
    } \
    static void __exit SetupExitProject(void) { \
        Layer0End(); \
        printk(KERN_INFO "%s: End\nVersion: %s\nBuild: %s\nTimestamp: %llu\n", description, #version, #build, ktime_get_real_seconds()); \
    } \
    module_init(SetupInitProject); \
    module_exit(SetupExitProject);
#endif