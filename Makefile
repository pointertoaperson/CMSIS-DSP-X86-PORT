##Makefile for x86 port of CMSIS-DSP LIBRARY####
## CHANGE THE COMPILER FLAG AS PER YOUR ARCHITECTURE

CMSIS_DIR := CMSIS

# Collect all .c files recursively under CMSIS/Source and main.c
SRC_ALL := main.c $(shell find $(CMSIS_DIR)/Source -name '*.c')

# Files to exclude from compilation
EXCLUDE := \
	CMSIS/Source/BasicMathFunctions/BasicMathFunctions.c\
	CMSIS/Source/BasicMathFunctions/BasicMathFunctionsf16.c \
	CMSIS/Source/QuaternionMathFunctions/QuaternionMathFunctions.c \
  $(CMSIS_DIR)/Source/MatrixFunctions/_arm_mat_mult_neon.c \
  $(CMSIS_DIR)/Source/TransformFunctions/TransformFunctions.c \
  CMSIS/Source/StatisticsFunctions/StatisticsFunctions.c \
  CMSIS/Source/StatisticsFunctions/StatisticsFunctionsf16.c \
  CMSIS/Source/BayesFunctions/BayesFunctions.c \
  CMSIS/Source/BayesFunctions/BayesFunctionsf16.c \
  CMSIS/Source/CommonTables/CommonTables.c \
  CMSIS/Source/CommonTables/CommonTablesf16.c \
  CMSIS/Source/ComplexMathFunctions/ComplexMathFunctions.c \
  CMSIS/Source/ComplexMathFunctions/ComplexMathFunctionsf16.c \
  CMSIS/Source/ControllerFunctions/ControllerFunctions.c \
  CMSIS/Source/DistanceFunctions/DistanceFunctions.c \
  CMSIS/Source/FastMathFunctions/FastMathFunctions.c \
  CMSIS/Source/FastMathFunctions/FastMathFunctionsf16.c \
  CMSIS/Source/FilteringFunctions/FilteringFunctions.c \
  CMSIS/Source/FilteringFunctions/FilteringFunctionsf16.c \
  CMSIS/Source/InterpolationFunctions/InterpolationFunctions.c \
  CMSIS/Source/InterpolationFunctions/InterpolationFunctionsf16.c \
  CMSIS/Source/MatrixFunctions/MatrixFunctions.c \
  CMSIS/Source/MatrixFunctions/MatrixFunctionsf16.c \
  CMSIS/Source/SupportFunctions/SupportFunctions.c \
  CMSIS/Source/SupportFunctions/SupportFunctionsf16.c \
  CMSIS/Source/SVMFunctions/SVMFunctions.c \
  CMSIS/Source/SVMFunctions/SVMFunctionsf16.c \
  CMSIS/Source/TransformFunctions/TransformFunctions.c \
  CMSIS/Source/TransformFunctions/TransformFunctionsf16.c \
  CMSIS/Source/WindowFunctions/WindowFunctions.c 










# Filter out excluded files
SRC := $(filter-out $(EXCLUDE), $(SRC_ALL))

INC := -I$(CMSIS_DIR)/Include 

CFLAGS := -Wall -O2 $(INC) -include stdint.h -D__ALIGNED\(x\)= -DARM_DSP_TABLE_ATTRIBUTE= -DARM_MATH_CM3

TARGET := dsp_test

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "Compiling files:"
	@echo $^
	$(CC) $(CFLAGS) $^ -lm -o $@

clean:
	rm -f $(TARGET)
