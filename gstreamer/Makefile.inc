##############################################################################
#Define the compile enviroment
##############################################################################

#TARGET_DEVICE:=aarch64
TARGET_DEVICE:=$(shell uname -m)

ifeq ($(TARGET_DEVICE),aarch64)
    CROSS_COMPILE:=aarch64-linux-gnu-
    SYSROOT:=/media/danv5/DATA/dannv5/CROSS_COMPILE/toolchain/jetson/sysroot_nvr_g2_104
    TARGET_SIZE:=64
    DEFINES+=-DPLATFORM_TEGRA
endif

CC:=${CROSS_COMPILE}gcc
CXX:=${CROSS_COMPILE}g++
AR:=${CROSS_COMPILE}ar
LD:=${CROSS_COMPILE}ld

##############################################################################
#Defining compiler flags
##############################################################################
NUM_OF_CORES:=10
LFLAGS:=--sysroot=$(SYSROOT) -Wall -g --std=c++11 -fPIC
LFLAGS_C:=--sysroot=$(SYSROOT) -Wall -g -fPIC

INC_PATH:=-I$(SYSROOT)/usr/include/${TARGET_DEVICE}-linux-gnu
INC_PATH+=-I$(SYSROOT)/usr/include/

###############################################################
#                    GSTREAMER FLAGS                          #
GSTREAMER_INC:= -I$(SYSROOT)/usr/include/gstreamer-1.0 -I$(SYSROOT)/usr/lib/${TARGET_DEVICE}-linux-gnu/gstreamer-1.0/include 
GSTREAMER_INC+= -I$(SYSROOT)/usr/include/glib-2.0 -I$(SYSROOT)/usr/lib/${TARGET_DEVICE}-linux-gnu/glib-2.0/include
GSTREAMER_LIBS:= -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0
###############################################################


DEFINES+=-UTEST

#CFLAGS:=$(LFLAGS) 
CFLAGS+=$(INC_PATH) ${GSTREAMER_INC}
CFLAGS+=$(DEFINES) 

LDFLAGS:=$(LFLAGS) -L$(SYSROOT)/usr/lib/${TARGET_DEVICE}-linux-gnu ${GSTREAMER_LIBS}
