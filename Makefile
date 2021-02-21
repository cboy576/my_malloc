##
## EPITECH PROJECT, 2021
## malloc
## File description:
## Makefile automatically generated using Epine!
##

NAME = libmy_malloc.so

all: $(NAME)
.PHONY: all

__NAME__SRCS := $(shell find -path './src/*.c')
__NAME__OBJS := $(filter %.c,$(__NAME__SRCS))
__NAME__OBJS := $(__NAME__OBJS:.c=.o)
__NAME__DEPS := $(__NAME__OBJS:.o=.d)
$(NAME) $(__NAME__OBJS):
$(NAME): CPPFLAGS :=
$(NAME): CPPFLAGS += -MD -MP
$(NAME): CPPFLAGS += -I./include
$(NAME): CFLAGS :=
$(NAME): CFLAGS += -fPIC
$(NAME): CFLAGS += -Wall
$(NAME): CFLAGS += -Wextra
$(NAME): CFLAGS += $(if DEBUG,-g3)
$(NAME): LDLIBS :=
$(NAME): LDFLAGS :=
$(NAME): LDFLAGS += -shared
$(NAME): LDFLAGS += -L.
$(NAME): LDFLAGS += -Wl,-rpath .
$(NAME): $(__NAME__OBJS)
	@echo [shared] $@
	@$(CC) -o $@ $(__NAME__OBJS) $(LDFLAGS) $(LDLIBS)
-include $(__NAME__DEPS)

unit_tests_SRCS := $(shell find -path './tests/*.c')
unit_tests_OBJS := $(filter %.c,$(unit_tests_SRCS))
unit_tests_OBJS := $(unit_tests_OBJS:.c=.o)
unit_tests_DEPS := $(unit_tests_OBJS:.o=.d)
unit_tests $(unit_tests_OBJS): $(NAME)
unit_tests: CPPFLAGS :=
unit_tests: CPPFLAGS += -MD -MP
unit_tests: CPPFLAGS += -I./include
unit_tests: CFLAGS :=
unit_tests: CFLAGS += -Wall
unit_tests: CFLAGS += -Wextra
unit_tests: CFLAGS += $(if DEBUG,-g3)
unit_tests: LDLIBS :=
unit_tests: LDLIBS += -l:$(NAME)
unit_tests: LDFLAGS :=
unit_tests: LDFLAGS += -L.
unit_tests: LDFLAGS += -Wl,-rpath .
unit_tests: $(unit_tests_OBJS)
	@echo [binary] $@
	@$(CC) -o $@ $(unit_tests_OBJS) $(LDFLAGS) $(LDLIBS)
-include $(unit_tests_DEPS)

%.o: %.c
	@echo [C] $@
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
%.o: %.cpp
	@echo [C++] $@
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

tests_run: ./unit_tests
	./unit_tests $(ARGS)
.PHONY: tests_run

clean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
.PHONY: clean

fclean: clean
	$(RM) $(NAME) unit_tests
	$(RM) ./unit_tests
.PHONY: fclean

re: fclean all
.PHONY: re
