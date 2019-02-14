CXX = g++

#TBR
#TARGET_EXEC ?= quantize

# with ?= the variable is set only if it’s not already set
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src/general ./src/segment ./src/weight ./src/schemata ./src/table ./src/parsers ./src/input ./src/scoremodel ./src/output ./lib/midifile
INCLUDE_DIRS ?= /usr/local/include ./include ./lib/midifile

# we assume only .cpp source files
# source do not contain the main (target) files
#SRCS := $(shell find $(SRC_DIRS) -name '*.cpp') ./src/targets/quant/test_rearchi.cpp 
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
#OBJS := $(addsuffix .o, $(BUILD_DIR)/$(notdir $(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# includes
INC_DIRS := $(shell find $(SRC_DIRS) -type d) $(INCLUDE_DIRS) $(SRC_DIRS) 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

#targets
TARGET_QUANT_OBJ ?= $(BUILD_DIR)/src/targets/quant/squant.o
TARGET_EQUIV_OBJ ?= $(BUILD_DIR)/src/targets/equiv/equiv.o
TARGET_SCHEMA_OBJ ?= $(BUILD_DIR)/src/targets/schema/schemas.o
TARGET_MIDI_OBJ ?= $(BUILD_DIR)/src/targets/midi/midiutil.o
TARGET_MEI_OBJ ?= $(BUILD_DIR)/src/targets/mei/meiutil.o

TARGET_FLAG  = -D PLATFORM_DARWIN=1 -D PLATFORM_LINUX=2 -D PLATFORM_FREEBSD=3 -D PLATFORM_CYGWIN=4
TARGET_FLAG += -D TARGET_QUANT=1 -D TARGET_EQUIV=2 -D TARGET_SCHEMA=3 -D TARGET_MIDI=4 -D TARGET_MEI=5
TARGET_FLAG += -D QP_PLATFORM=PLATFORM_LINUX 

$(info $$SRC_DIRS is [${SRC_DIRS}])
$(info $$SRCS is [${SRCS}])
$(info $$OBJS is [${OBJS}])

#CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=gnu++11  #used for cygwin on windows
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++11 
#CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=gnu++11 -std=c++11
#-Wc++11-extensions

#linker flags
LDFLAGS ?= -lmei
#LDFLAGS ?= -pthread -lmei


#$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
#	mkdir -p $(BUILD_DIR)
#	$(CXX) $(OBJS) -o $@ $(LDFLAGS)


quant: TARGET_FLAG += -D QP_TARGET=TARGET_QUANT
quant: $(OBJS) $(TARGET_QUANT_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(TARGET_QUANT_OBJ) -o $@ $(LDFLAGS)

equiv: TARGET_FLAG += -D QP_TARGET=TARGET_EQUIV
equiv: $(OBJS) $(TARGET_EQUIV_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(TARGET_EQUIV_OBJ) -o $@ $(LDFLAGS)

schema: TARGET_FLAG += -D QP_TARGET=TARGET_SCHEMA
schema: $(OBJS) $(TARGET_SCHEMA_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(TARGET_SCHEMA_OBJ) -o $@ $(LDFLAGS)

midi: TARGET_FLAG += -D QP_TARGET=TARGET_MIDI
midi: $(OBJS) $(TARGET_MIDI_OBJ) 	
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(TARGET_MIDI_OBJ) -o $@ $(LDFLAGS)


mei: TARGET_FLAG += -D QP_TARGET=TARGET_MEI
mei: $(OBJS) $(TARGET_MEI_OBJ) 	
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(TARGET_MEI_OBJ) -o $@ $(LDFLAGS)

# c++ source
$(BUILD_DIR)/%.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TARGET_FLAG) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR) $(OBJS) $(DEPS)
	$(RM) $(TARGET_QUANT_OBJ) $(TARGET_EQUIV_OBJ) $(TARGET_SCHEMA_OBJ) $(TARGET_MIDI_OBJ) $(TARGET_MEI_OBJ)

-include $(DEPS)

MKDIR_P ?= mkdir -p
