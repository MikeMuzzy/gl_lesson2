ifneq ($(KERNELRELEASE),)

# kbuild part of makefile
obj-m := mod_foo1.o
obj-m += mod_foo2.o

mod_foo1-y := src/mod_foo1.o
mod_foo2-y := src/mod_foo2.o

ccflags-y := -I$(src)/include

else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
