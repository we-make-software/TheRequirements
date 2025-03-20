#ifndef TheRequirements_H
#define TheRequirements_H
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
//Sad wee can't do WTFPL
//https://github.com/we-make-software/TheRequirements?tab=License-1-ov-file
//Damm!! you GPL!!Show me!!
#define Layer0Setup(description,version,build) \
    MODULE_DESCRIPTION(description "\version: " #version "\build:" #build); \
    MODULE_LICENSE("GPL"); \
    MODULE_AUTHOR("We-Make-Software.Com"); \
    static int __init SetupInitProject(void) { \
        Layer0Start(); \
        return 0; \
    } \
    static void __exit SetupExitProject(void) { \
        Layer0End(); \
    } \
    module_init(SetupInitProject); \
    module_exit(SetupExitProject);
#endif