#include <mod_foo.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Mykhailo Panchenko <panchenko.mike@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static int __init foo_module_init(void)
{
    return 0;
}

static void __exit foo_module_exit(void)
{
    /* Do nothing here right now */
}

void hello_print(void) {
    pr_emerg("[%s] Hello, world!\n", module_name(THIS_MODULE));
}

EXPORT_SYMBOL(hello_print);

module_init(foo_module_init);
module_exit(foo_module_exit);
