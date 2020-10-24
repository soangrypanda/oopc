#include "typecheck.h"

struct class_check_s {
    char blank;
};

struct class_check_s class_check = { 0 };

struct class_check_s *passed = &class_check;
