#include <mod_foo.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <asm-generic/bug.h>
#include <linux/slab.h>

MODULE_AUTHOR("Mykhailo Panchenko <panchenko.mike@gmail.com>");
MODULE_DESCRIPTION("mod_foo2 in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint iter = 1;

MODULE_PARM_DESC(iter, "How many iteration of printing hello_print()");
module_param(iter, uint, S_IRUSR);

static int __init foo_module_init(void)
{
    uint i;

    WARN(iter == 0, "Warning iter param is setted to \"0\"");
    BUG_ON(iter > 10);

    if (iter == 5) {
	return -EINVAL;
    }

    if (iter == 2) {
	__module_get(THIS_MODULE);
    }

    for (i = 0; i < iter; i++) {
	hello_print();
    }
    return 0;
}

static void print_goodbye(void)
{
    pr_emerg("[%s] Good bye!\n", module_name(THIS_MODULE));
}

static void __exit foo_module_exit(void)
{
    print_goodbye();
    /* Do nothing here right now */
}

module_init(foo_module_init);
module_exit(foo_module_exit);
