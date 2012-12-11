// this code is stolen from boost
//
#include <algorithm>
#include <typeinfo>

class any {
 public:
  any() : content(0) {
  }

  ~any() {
    delete content;
  }

  template <typename ValueType>
  any(const ValueType& value) :
      content (new holder<ValueType>(value)) {
  }

  any(const any& other) :
      content(other.content ? other.content->clone() : 0) {
  }

 public:
  any& swap(any& rhs) {
    std::swap(content, rhs.content);
    return *this;
  }

  const std::type_info & type() const {
    return content ? content->type() : typeid(void);
  }

  template <typename ValueType>
  any& operator=(const ValueType& rhs) {
    any(rhs).swap(*this);
    return *this;
  }

 public:
  bool empty() const {
    return !content;
  }

 public:
  class placeholder {
   public:
    virtual ~placeholder() {
    }

   public:
    virtual const std::type_info& type() const = 0;
    virtual placeholder* clone() const = 0;
  };

  template <typename ValueType>
  class holder : public placeholder {
   public:
    holder(const ValueType& value) :
        held(value) {
    }
   public:
    virtual const std::type_info& type() const {
      return typeid(ValueType);
    }

    virtual placeholder* clone() const {
      return new holder(held);
    }
   public:
    ValueType held;

   private:
    holder& operator=(const holder&);
  };

  placeholder* content;
};

template <typename ValueType>
ValueType* any_cast(any* operand) {
  return operand && operand->type() == typeid(ValueType) ?
      &static_cast<any::holder<ValueType>*>(operand->content)->held :0;
}

template <typename ValueType>
inline const ValueType* any_cast(const any* operand) {
  return any_cast<ValueType>(const_cast<any*>(operand));
}

