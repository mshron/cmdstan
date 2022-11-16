#ifndef CMDSTAN_ARGUMENTS_ARG_LAPLACE_JACOBIAN_HPP
#define CMDSTAN_ARGUMENTS_ARG_LAPLACE_JACOBIAN_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_laplace_jacobian : public bool_argument {
 public:
  arg_laplace_jacobian() : bool_argument() {
    _name = "jacobian";
    _description = "Set to true (1) to include change-of-variables adjustment"
                   "for constraining parameter transforms";
    _validity = "[0, 1]";
    _default = "1";
    _default_value = true;
    _constrained = false;
    _good_value = 1;
    _value = _default_value;
  }
};

}  // namespace cmdstan
#endif
