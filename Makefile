# 项目路径
SRC_DIR := src
BUILD_DIR := build

# 子模块
MODULE := runoob_cpp

# 编译器
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall

# 源文件和目标文件
SRCS := $(wildcard $(SRC_DIR)/$(MODULE)/*.cpp)
BINS := $(patsubst $(SRC_DIR)/$(MODULE)/%.cpp,$(BUILD_DIR)/$(MODULE)/%,$(SRCS))

# 默认目标
all: $(BINS)

# 编译规则
$(BUILD_DIR)/$(MODULE)/%: $(SRC_DIR)/$(MODULE)/%.cpp
	@mkdir -p $(BUILD_DIR)/$(MODULE)
	$(CXX) $(CXXFLAGS) $< -o $@

# 单独构建
%:
	@$(MAKE) $(BUILD_DIR)/$(MODULE)/$@

# 清理
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
