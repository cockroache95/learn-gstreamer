
export GSTREAMER_ROOT=$(shell pwd;)
export BUILD_ROOT:=${GSTREAMER_ROOT}/build
export BIN_ROOT:=${GSTREAMER_ROOT}/bin

include ${GSTREAMER_ROOT}/Makefile.inc

.PHONY: all clean helloworld

all: info helloworld
	
helloworld:
	@echo "=================================================================================="
	@echo "[NTD] Build helloworld"
	make -C ${GSTREAMER_ROOT}/helloworld \
		-f ${GSTREAMER_ROOT}/helloworld/Makefile -j ${NUM_OF_CORES}

clean: clean_helloworld
	@rm -rf ${BUILD_ROOT}
	@echo "=================================================================================="
	@echo "[NTD] Clean all object files & binaries"
clean_helloworld:
	@echo "=================================================================================="
	@echo "[NTD] Clean helloworld"
	make -C ${GSTREAMER_ROOT}/helloworld \
		-f ${GSTREAMER_ROOT}/helloworld/Makefile clean

info:
	@echo "=================================================================================="
	@echo "[NTD] Checking the compile enviroment"
	@echo "[NTD] SYSROOT      : "$(SYSROOT)
	@echo "[NTD] TARGET_DEVICE: "$(TARGET_DEVICE)
	@echo "[NTD] VSM_NVR_ROOT : "$(VSM_NVR_ROOT)
	@echo "[NTD] CFLAGS       : "$(CFLAGS)
	@echo "[NTD] LDFLAGS      : "$(LDFLAGS)
	@echo "=================================================================================="	
	@mkdir -p ${BUILD_ROOT} ${BIN_ROOT}