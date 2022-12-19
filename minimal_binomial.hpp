
// Code generated by stanc v2.30.0-104-g5240321e
// modified my mqbs
#include <stan/model/model_header.hpp>
#include <unordered_map>
#include <iostream>
#include <functional>
#include <variant>
#include <utility>
#include <algorithm>
#include <deque>
#include <memory>
#include <stan/callbacks/interrupt.hpp>
#include <stan/callbacks/logger.hpp>
#include <stan/callbacks/stream_logger.hpp>
#include <stan/callbacks/unique_stream_writer.hpp>
#include <stan/callbacks/stream_writer.hpp>
#include <stan/callbacks/writer.hpp>
#include <stan/services/sample/hmc_static_unit_e.hpp>
#include <stan/services/sample/hmc_static_unit_e_adapt.hpp>

namespace bernoulli_model_namespace {

using stan::model::model_base_crtp;
using namespace stan::math;


stan::math::profile_map profiles__;
static constexpr std::array<const char*, 7> locations_array__ = 
{" (found before start of program)",
 " (in 'examples/bernoulli/bernoulli.stan', line 6, column 2 to column 30)",
 " (in 'examples/bernoulli/bernoulli.stan', line 9, column 2 to column 20)",
 " (in 'examples/bernoulli/bernoulli.stan', line 10, column 2 to column 23)",
 " (in 'examples/bernoulli/bernoulli.stan', line 2, column 2 to column 17)",
 " (in 'examples/bernoulli/bernoulli.stan', line 3, column 8 to column 9)",
 " (in 'examples/bernoulli/bernoulli.stan', line 3, column 2 to column 34)"};

using log_prob_function_ = std::function<
            stan::math::var_value<double>(
                   std::vector<stan::math::var_value<double>>, 
                   std::vector<int>,  
                   std::unordered_map<const char*, std::vector<double>>,
                   std::ostream*)>;

class bernoulli_model final : public model_base_crtp<bernoulli_model> {

 private:
  std::unordered_map<const char*, std::vector<double> > data;
  log_prob_function_ fcn;
 
 public:
  ~bernoulli_model() { }

  inline std::string model_name() const final { return "bernoulli_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.30.0-104-g5240321e", "stancflags = "};
  }
  
  bernoulli_model(stan::io::var_context& context__,
                  log_prob_function_ &fcn,
                  std::unordered_map<const char *, std::vector<double> > data,
                  unsigned int random_seed__ = 0,
                  std::ostream* pstream__ = nullptr): fcn(fcn), data(data), model_base_crtp(0) {
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static constexpr const char* function__ = "bernoulli_model_namespace::bernoulli_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    int pos__ = std::numeric_limits<int>::min();
    pos__ = 1;
   // TODO fix data loading
    /*context__.validate_dims("data initialization","N","int",
         std::vector<size_t>{});
    N = std::numeric_limits<int>::min();
    
    
    N = context__.vals_i("N")[(1 - 1)];
    stan::math::check_greater_or_equal(function__, "N", N, 0);
    stan::math::validate_non_negative_index("y", "N", N);
    context__.validate_dims("data initialization","y","int",
         std::vector<size_t>{static_cast<size_t>(N)});
    y = std::vector<int>(N, std::numeric_limits<int>::min());
    
    y = context__.vals_i("y");
    stan::math::check_greater_or_equal(function__, "y", y, 0);
    stan::math::check_less_or_equal(function__, "y", y, 1);*/
    num_params_r__ = 1;
    
  }

  stan::math::var_value<double> deref(double x) const {
      return stan::math::var_value<double>(x);
  }

  stan::math::var_value<double> deref(stan::math::var x) const {
      return x;
  }

  template <bool propto__, bool jacobian__ , typename VecR, typename VecI, 
  stan::require_vector_like_t<VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline stan::scalar_type_t<VecR> log_prob_impl_2(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
      std::vector<stan::math::var_value<double>> var_array;
      for (auto &item : params_r__) {
          var_array.push_back(deref(item));
      }
      auto result = fcn(var_array, params_i__, data, pstream__);
      return result.val();
      //return static_cast<stan::scalar_type_t<VecR>>(result);
  }

  template <bool propto__, bool jacobian__ , typename VecR, typename VecI, 
  stan::require_vector_like_t<VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "bernoulli_model_namespace::log_prob";
    (void) function__;  // suppress unused var warning
    
    try {
      local_scalar_t__ theta = DUMMY_VAR__;
      current_statement__ = 1;
      theta = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 1, lp__);
      {
        current_statement__ = 2;
        lp_accum__.add(stan::math::beta_lpdf<propto__>(theta, 1, 1));
        current_statement__ = 3;
        lp_accum__.add(stan::math::bernoulli_lpmf<propto__>(data.at("y"), theta));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, 
  stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, 
  stan::require_vector_vt<std::is_floating_point, VecVar>* = nullptr> 
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    static constexpr bool propto__ = true;
    (void) propto__;
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    int current_statement__ = 0; 
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    constexpr bool jacobian__ = false;
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "bernoulli_model_namespace::write_array";
    (void) function__;  // suppress unused var warning
    
    try {
      double theta = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 1;
      theta = in__.template read_constrain_lub<local_scalar_t__, jacobian__>(
                0, 1, lp__);
      out__.write(theta);
      if (stan::math::logical_negation((stan::math::primitive_value(
            emit_transformed_parameters__) || stan::math::primitive_value(
            emit_generated_quantities__)))) {
        return ;
      } 
      if (stan::math::logical_negation(emit_generated_quantities__)) {
        return ;
      } 
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, 
  stan::require_vector_t<VecVar>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline void transform_inits_impl(VecVar& params_r__, VecI& params_i__,
                                   VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      local_scalar_t__ theta = DUMMY_VAR__;
      theta = in__.read<local_scalar_t__>();
      out__.write_free_lub(0, 1, theta);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__ = std::vector<std::string>{"theta"};
    
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    
    dimss__ = std::vector<std::vector<size_t>>{std::vector<size_t>{}};
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "theta");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "theta");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"theta\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"}]");
    
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"theta\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"}]");
    
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 1;
      const size_t num_transformed = emit_transformed_parameters * 0;
      const size_t num_gen_quantities = emit_generated_quantities * 0;
      const size_t num_to_write = num_params__ + num_transformed +
        num_gen_quantities;
      std::vector<int> params_i;
      vars = Eigen::Matrix<double, Eigen::Dynamic, 1>::Constant(num_to_write,
        std::numeric_limits<double>::quiet_NaN());
      write_array_impl(base_rng, params_r, params_i, vars,
        emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 1;
      const size_t num_transformed = emit_transformed_parameters * 0;
      const size_t num_gen_quantities = emit_generated_quantities * 0;
      const size_t num_to_write = num_params__ + num_transformed +
        num_gen_quantities;
      vars = std::vector<double>(num_to_write,
        std::numeric_limits<double>::quiet_NaN());
      write_array_impl(base_rng, params_r, params_i, vars,
        emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    double strip_var(double x) const {
        return x;
    }

    double strip_var(const stan::math::var_value<double>& x) const {
        return x.val();
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      std::vector<int> params_i;
      std::vector<double> vec{};
      for (auto i=0; i<params_r.size(); i++) {
          double d = strip_var(params_r(i,0));
          vec.push_back(d);
      }
      return log_prob_impl_2<propto__, jacobian__>(vec, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl_2<propto__, jacobian__>(params_r, params_i, pstream);
    }


    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits(context, params_i, params_r_vec, pstream);
      params_r = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        params_r_vec.data(), params_r_vec.size());
    }

  inline void transform_inits(const stan::io::var_context& context,
                              std::vector<int>& params_i,
                              std::vector<double>& vars,
                              std::ostream* pstream__ = nullptr) const {
     constexpr std::array<const char*, 1> names__{"theta"};
     const std::array<Eigen::Index, 1> constrain_param_sizes__{1};
     const auto num_constrained_params__ = std::accumulate(
     constrain_param_sizes__.begin(), constrain_param_sizes__.end(), 0);
    
     std::vector<double> params_r_flat__(num_constrained_params__);
     Eigen::Index size_iter__ = 0;
     Eigen::Index flat_iter__ = 0;
     for (auto&& param_name__ : names__) {
       const auto param_vec__ = context.vals_r(param_name__);
       for (Eigen::Index i = 0; i < constrain_param_sizes__[size_iter__]; ++i) {
         params_r_flat__[flat_iter__] = param_vec__[i];
         ++flat_iter__;
       }
       ++size_iter__;
     }
     vars.resize(num_params_r__);
     transform_inits_impl(params_r_flat__, params_i, vars, pstream__);
    } // transform_inits() 
    
};
}
#ifndef USING_R

// Boilerplate
bernoulli_model_namespace::bernoulli_model& new_model(
        stan::io::var_context& data_context,
        bernoulli_model_namespace::log_prob_function_ &fcn,
        std::unordered_map<const char*, std::vector<double>> &data,
        unsigned int seed,
        std::ostream* msg_stream) {
    bernoulli_model_namespace::bernoulli_model* m = new bernoulli_model_namespace::bernoulli_model(data_context, fcn, data, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return bernoulli_model_namespace::profiles__;
}

#endif

using shared_context_ptr = std::shared_ptr<stan::io::var_context>;

/**
 * Given the name of a file, return a shared pointer holding the data contents.
 * @param file A system file to read from.
 */
inline shared_context_ptr get_var_context(const std::string file) {
  std::fstream stream("foo", std::fstream::in);
  stan::io::dump var_context(stream);
  return std::make_shared<stan::io::dump>(var_context);
}

using context_vector = std::vector<shared_context_ptr>;
/**
 * Make a vector of shared pointers to contexts.
 * @param file The name of the file. For multi-chain we will attempt to find
 *  {file_name}_1{file_ending} and if that fails try to use the named file as
 *  the data for each chain.
 * @param num_chains The number of chains to run.
 * @return An std vector of shared pointers to var contexts
 */
context_vector get_vec_var_context(const std::string &file, size_t num_chains) {
  if (num_chains == 1) {
    return context_vector(1, get_var_context(file));
  }
  auto make_context = [](auto &&file, auto &&stream,
                         auto &&file_ending) -> shared_context_ptr {
      std::stringstream msg;
      msg << "file ending of " << file_ending << " is not supported by cmdstan";
      throw std::invalid_argument(msg.str());
      using stan::io::dump;
      return std::make_shared<dump>(dump(stream));
  };
  // use default for all chain inits
  if (file == "") {
    using stan::io::dump;
    std::fstream stream(file.c_str(), std::fstream::in);
    return context_vector(num_chains, std::make_shared<dump>(dump(stream)));
  } else {
    size_t file_marker_pos = file.find_last_of(".");
    if (file_marker_pos > file.size()) {
      std::stringstream msg;
      msg << "Found: \"" << file
          << "\" but user specied files must end in .json or .R";
      throw std::invalid_argument(msg.str());
    }
    std::string file_name = file.substr(0, file_marker_pos);
    std::string file_ending = file.substr(file_marker_pos, file.size());
    if (file_ending != ".json" && file_ending != ".R") {
      std::stringstream msg;
      msg << "file ending of " << file_ending << " is not supported by cmdstan";
      throw std::invalid_argument(msg.str());
    }
    std::string file_1
        = std::string(file_name + "_" + std::to_string(1) + file_ending);
    std::fstream stream_1(file_1.c_str(), std::fstream::in);
    // Check if file_1 exists, if so then we'll assume num_chains of these
    // exist.
    if (stream_1.rdstate() & std::ifstream::failbit) {
      // if that fails we will try to find a base file
      std::fstream stream(file.c_str(), std::fstream::in);
      if (stream.rdstate() & std::ifstream::failbit) {
        std::string file_name_err
            = std::string("\"" + file_1 + "\" and base file \"" + file + "\"");
        std::stringstream msg;
        msg << "Searching for  \"" << file_name_err << std::endl;
        msg << "Can't open either of specified files," << file_name_err
            << std::endl;
        throw std::invalid_argument(msg.str());
      } else {
        return context_vector(num_chains,
                              make_context(file, stream, file_ending));
      }
    } else {
      // If we found file_1 then we'll assume file_{1...N} exists
      context_vector ret;
      ret.reserve(num_chains);
      ret.push_back(make_context(file_1, stream_1, file_ending));
      for (size_t i = 1; i < num_chains; ++i) {
        std::string file_i
            = std::string(file_name + "_" + std::to_string(i) + file_ending);
        std::fstream stream_i(file_1.c_str(), std::fstream::in);
        // If any stream fails at this point something went wrong with file
        // names.
        if (stream_i.rdstate() & std::ifstream::failbit) {
          std::string file_name_err = std::string(
              "\"" + file_1 + "\" but cannot open \"" + file_i + "\"");
          std::stringstream msg;
          msg << "Found " << file_name_err << std::endl;
          throw std::invalid_argument(msg.str());
        }
        ret.push_back(make_context(file_i, stream_i, file_ending));
      }
      return ret;
    }
  }
  // This should not happen
  using stan::io::dump;
  std::fstream stream(file.c_str(), std::fstream::in);
  return context_vector(num_chains, std::make_shared<dump>(dump(stream)));
}

namespace stan_interpreter {

/*enum class token_type {not_parsed, empty, eof, distribution, name, var, real, 
                 integer, data, args, expr, datablock, tilde,
                 parametersblock, modelblock, stmts, stmt};*/


enum class token_type {L, R, atom, literal_num, eof, root, empty};

class token {
    friend std::ostream& operator<<(std::ostream&, token const&);
    private:
        token_type t;
        std::string str_value;
        double dbl_value;
        int line;
        int pos;
    public:
        token(token_type t, 
              std::string str_value, 
              double dbl_value,
              int line, 
              int pos) :
            t{t}, str_value{str_value}, dbl_value{dbl_value},
            line{line}, pos{pos} {};
        token(token_type t) : t{t} {};
        token() {
            t = token_type::empty;
       }
        token_type get_type() {
            return t;
        }
        std::string get_str_value() {
            return str_value;
        }
        double get_dbl_value() {
            return dbl_value;
        }
        std::string to_string() const {
            switch (t) {
                case token_type::L: 
                    return "LEFT";
                case token_type::R:
                    return "RIGHT";
                case token_type::atom:
                    return "ATOM(" + str_value + ")";
                case token_type::literal_num:
                    return "LIT_NUM(" + std::to_string(dbl_value) + ")";
                case token_type::root:
                    return "ROOT";
                case token_type::eof:
                    return "EOF";
                case token_type::empty:
                    return "EMPTY";
                default:
                    return "NotImplemented";
            }
        }
};

class scanner {
    private:
        int line = 0;
        bool filled = false;
    public:
        std::deque<token> tokens {};
        scanner() {}
        bool isdigit(char ch) {
            return  (ch >= 48 && ch <= 57) || ch == 46;
        }
        bool is_filled() {
            return filled;
        }
        bool consume(token_type t) {
            token temp;
            peek(temp);
            if (tokens.size() == 0 || temp.get_type() != t) {
                return false;
            } else {
                tokens.pop_front();
                return true;
            }
        }
        bool peek(token &out) {
            if (tokens.size() == 0) {
                return false;
            } else {
                out = tokens.front();
                return true;
            }

        }
        void read_line(std::string s) {
            filled = true;
            int pos = 0;
            char ch = s[pos];
            while(ch) {
                if (ch == '(') {
                    tokens.push_back(token(token_type::L, "", 0, line, pos));
                    pos++;
                    ch = s[pos];
                } else if (ch == ')') {
                    tokens.push_back(token(token_type::R, "", 0, line, pos));
                    pos++;
                    ch = s[pos];
                } else if (isdigit(ch)) {
                    std::string temp;
                    int span = 0;
                    while(isdigit(ch)) {
                        temp += ch;
                        span++;
                        ch = s[pos+span];
                    }
                    tokens.push_back(token(token_type::literal_num, "",
                                     stof(temp), line, pos));
                    pos += span;
                } else if (ch==' ' || ch ==0) {
                    pos++;
                    ch = s[pos];
                } else {
                    std::string temp;
                    int span = 0;
                    while(ch!=' ' && ch!=0 && ch!=')') {
                        temp += ch;
                        span++;
                        ch = s[pos+span];
                    }
                    tokens.push_back(token(token_type::atom,
                                     temp, 0, line, pos));
                    pos += span;
                }
            }
            line++;
        }
};


std::ostream &operator<<(std::ostream &os, token const &tok) {
    return os << tok.to_string();
}

class AST {
    protected:
        std::vector<std::unique_ptr<AST>> nodes;
        int depth = 0;
    public:
        virtual ~AST() = default;
        virtual std::string to_string() = 0 ;
        auto operator[](int i) const {
            return nodes[i].get();
        }
        int size() {
            return nodes.size();
        }
        int get_depth() {
            return depth;
        }
        std::string pprint_string() {
            std::string out = to_string();
            for (auto &c : nodes) {
                for (int i = 0; i<=get_depth(); i++) {
                    out += " ";
                }
                out += c->to_string() + "\n";
            }
            return out;

        }
};

auto find_nodes(AST &a) {};

class Expr : public AST {
    public:
        ~Expr() {};
};

class RealNumeral : public Expr {
    private:
        double num;
    public:
        RealNumeral(double num) : num{num} {};
        ~RealNumeral() {};
        std::string to_string() {
            return std::to_string(num);
        }
};

class parser {
    public:
        auto parse(scanner &scan, int d = 0) {
            if (!scan.is_filled()) {
                throw "Scanner needs to be filled before we can make AST";
            }
            token tok;
            if (!scan.peek(tok)) {
                throw "Error, pulling from past scanner end";
            }
            switch (tok.get_type()) {
                case token_type::literal_num:
                    scan.consume(token_type::literal_num);
                    return std::make_unique<RealNumeral>(tok.get_dbl_value());
                default:
                    throw "Not implemented";
                }
        }
            
};

/*class action {

};

class add : public action {
    
};

class tree_walk {
    private:
        std::unordered_map<string, &action> actions;
        ast my_ast;
        std::unordered_map<std::string, std::vector<stan::math::var_value<double>> &var_values;
    public:
        tree_walk(std::unordered_map<string, &action> actions,
                  ast my_ast,
                  std::unordered_map<std::string, std::vector<stan::math::var_value<double>> &var_values) : 
            actions{actions}, my_ast{my_ast}, var_values{var_values} {};
};

class model {
    tree_walk data;
    tree_walk parameters;
    tree_walk model;
    std::unordered_map<std::string, std::vector<stan::math::var_value<double>> var_values;
};*/


class log_prob_generator {
    using T = stan::math::var_value<double>;
    private:
        std::vector<token> stack {};
    public:
        log_prob_generator() {};
        T operator()(
                std::vector<stan::math::var_value<double>> params_r__, 
                std::vector<int> params_i__, 
                std::unordered_map<const char*, std::vector<double>> data, 
                std::ostream* pstream__) {
            T lp__(0.0);
            stan::math::accumulator<T> lp_accum__;
            stan::io::deserializer<T> in__(params_r__, params_i__);
            T  DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
            T theta = DUMMY_VAR__;
            theta = in__.template read_constrain_lub<T, true>(0, 1, lp__);
            lp_accum__.add(stan::math::beta_lpdf<true>(theta, 1, 1));
            lp_accum__.add(stan::math::bernoulli_lpmf<true>(data.at("y"), theta));
            lp_accum__.add(lp__);
            return lp_accum__.sum();
        }

};

}

int main(int argc, char **argv) {
    stan_interpreter::scanner s;
    std::string input;
    std::ifstream file(argv[1]);
    while (getline(file, input)) {
        s.read_line(input);
    }
    for (auto &el : s.tokens) {
        std::cout<<el<<" ";
    }
    std::cout<<"\n";
    stan_interpreter::parser p;
    auto test = p.parse(s);
    std::cout<<"Parsed:\n"<<test->pprint_string();
}

void run_model() {
    bernoulli_model_namespace::log_prob_function_ fcn = stan_interpreter::log_prob_generator();

    std::unordered_map<const char*, std::vector<double>> data;

    data["N"] = std::vector<double>{10};
    data["y"] = std::vector<double>{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    std::shared_ptr<stan::io::var_context> var_context = get_var_context("examples/bernoulli/bernoulli.data.json");
    bernoulli_model_namespace::bernoulli_model &model = new_model(*var_context, fcn, data, 0, &std::cout);

    std::string init = "foo";
    // https://mc-stan.org/docs/2_23/reference-manual/hmc-algorithm-parameters.html
    int num_chains = 1;
    std::vector<std::shared_ptr<stan::io::var_context>> init_contexts = get_vec_var_context(init, num_chains);
    unsigned int random_seed = 0;
    unsigned int chain = 0;
    double init_radius = 2.0;
    int id = 0;
    int num_warmup = 1000;
    int num_samples = 1000; 
    int num_thin = 1;
    bool save_warmup = false;
    int refresh = 1000;
    double stepsize = 0.1;
    double stepsize_jitter = 0.1;
    double int_time = 0;
    double delta = 0.8;
    double gamma = 0.05;
    double kappa = 0.75;
    double t0 = 10;
    stan::callbacks::stream_writer info(std::cout);
    stan::callbacks::stream_writer err(std::cerr);
    stan::callbacks::stream_logger logger(std::cout, std::cout, std::cout,
                                        std::cerr, std::cerr);
    stan::callbacks::writer init_writer;
    stan::callbacks::interrupt interrupt;
    stan::callbacks::stream_writer sample_writer(std::cerr); // print out results to stderr for now
    stan::callbacks::writer diagnostic_writer;
    auto return_code = stan::services::sample::hmc_static_unit_e(
            model, *(init_contexts[0]), random_seed, id, init_radius,
            num_warmup, num_samples, num_thin, save_warmup, refresh, stepsize,
            stepsize_jitter, int_time, interrupt, logger, init_writer,
            sample_writer, diagnostic_writer);
}
