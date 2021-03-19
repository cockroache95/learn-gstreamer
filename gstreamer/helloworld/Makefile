include ${GSTREAMER_ROOT}/Makefile.inc

BUILD_DIR_HELLOWORLD:=${BUILD_ROOT}/helloworld/

SRCS_CPP:=$(wildcard *.cpp)
OBJS_CPP := $(patsubst %.cpp, $(BUILD_DIR_HELLOWORLD)%.cpp.o, $(SRCS_CPP))

SRCS_C:=$(wildcard *.c)
OBJS_C := $(patsubst %.c, $(BUILD_DIR_HELLOWORLD)%.c.o, $(SRCS_C))

APP:=${BIN_ROOT}/helloworld
.PHONY: all clean check
all: check ${APP}
	

$(APP): $(OBJS_CPP) $(OBJS_C) Makefile $(GSTREAMER_ROOT)/Makefile.inc
	$(CXX) -o $(APP) $(OBJS_C) $(OBJS_CPP) $(LDFLAGS)

${BUILD_DIR_HELLOWORLD}%.cpp.o: %.cpp $(INCS) Makefile $(GSTREAMER_ROOT)/Makefile.inc
	$(CXX) $< -c -o $@ $(LFLAGS) $(CFLAGS)
${BUILD_DIR_HELLOWORLD}%.c.o: %.c $(INCS) Makefile $(GSTREAMER_ROOT)/Makefile.inc
	$(CC) $< -c -o $@ $(LFLAGS_C) $(CFLAGS)

clean: check
	@echo "[HLW] Clean HelloWorld APP"
	@rm -rf $(BUILD_DIR_HELLOWORLD)

check:
	@echo "========= HELLOWORLD APP INFO =========="
	@mkdir -p ${BUILD_DIR_HELLOWORLD}
	@echo "[HLW] Source: " ${SRCS_CPP} ${SRCS_C}
	@echo "[HLW] Build dir: " ${BUILD_DIR_HELLOWORLD}
	@echo "[HLW] Target app: " ${APP}
	@echo "============ ============== ============"